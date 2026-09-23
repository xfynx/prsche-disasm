#![allow(clippy::all)]
//! Numeric geometry audit independent of GPU visibility and camera placement.
use nfs_assets::{load_car, AssetFiles, Mesh, Scene, Texture};
use std::{env, fs, path::Path};

#[derive(Clone, Copy)]
struct RayHit {
    triangle: usize,
    t: f32,
    uv: [f32; 2],
}

struct PartMetadata {
    fill_mode: u16,
    trans_info: u16,
    material: u16,
}

fn sub(a: [f32; 3], b: [f32; 3]) -> [f32; 3] {
    [a[0] - b[0], a[1] - b[1], a[2] - b[2]]
}
fn dot(a: [f32; 3], b: [f32; 3]) -> f32 {
    a.into_iter().zip(b).map(|(a, b)| a * b).sum()
}
fn cross(a: [f32; 3], b: [f32; 3]) -> [f32; 3] {
    [
        a[1] * b[2] - a[2] * b[1],
        a[2] * b[0] - a[0] * b[2],
        a[0] * b[1] - a[1] * b[0],
    ]
}
fn length(v: [f32; 3]) -> f32 {
    dot(v, v).sqrt()
}

fn mesh_center(mesh: &Mesh) -> Result<[f32; 3], String> {
    let first = mesh
        .vertices
        .first()
        .ok_or_else(|| format!("{} has no vertices", mesh.name))?;
    let mut bounds = [first.position, first.position];
    for vertex in &mesh.vertices[1..] {
        for axis in 0..3 {
            bounds[0][axis] = bounds[0][axis].min(vertex.position[axis]);
            bounds[1][axis] = bounds[1][axis].max(vertex.position[axis]);
        }
    }
    Ok(std::array::from_fn(|axis| {
        (bounds[0][axis] + bounds[1][axis]) * 0.5
    }))
}

fn nearest_ray_hit(
    mesh: &Mesh,
    eye: [f32; 3],
    direction: [f32; 3],
) -> Result<Option<RayHit>, String> {
    if mesh.indices.len() % 3 != 0 {
        return Err(format!("{} has incomplete triangle indices", mesh.name));
    }
    let mut nearest = None;
    for (triangle, indices) in mesh.indices.chunks_exact(3).enumerate() {
        let vertices = indices
            .iter()
            .copied()
            .map(|index| {
                mesh.vertices
                    .get(index as usize)
                    .ok_or_else(|| format!("{} index {index} out of bounds", mesh.name))
            })
            .into_iter()
            .collect::<Result<Vec<_>, _>>()?;
        let edge1 = sub(vertices[1].position, vertices[0].position);
        let edge2 = sub(vertices[2].position, vertices[0].position);
        let p = cross(direction, edge2);
        let determinant = dot(edge1, p);
        if determinant.abs() < 1e-7 {
            continue;
        }
        let inv = determinant.recip();
        let q = sub(eye, vertices[0].position);
        let u = dot(q, p) * inv;
        if !(0.0..=1.0).contains(&u) {
            continue;
        }
        let v = dot(direction, cross(q, edge1)) * inv;
        if v < 0.0 || u + v > 1.0 {
            continue;
        }
        let t = dot(edge2, cross(q, edge1)) * inv;
        if t <= 1e-7 || nearest.is_some_and(|hit: RayHit| t >= hit.t) {
            continue;
        }
        let w = 1.0 - u - v;
        nearest = Some(RayHit {
            triangle,
            t,
            uv: std::array::from_fn(|axis| {
                w * vertices[0].uv[axis] + u * vertices[1].uv[axis] + v * vertices[2].uv[axis]
            }),
        });
    }
    Ok(nearest)
}

fn sampled_rgba(texture: &Texture, uv: [f32; 2]) -> Result<[f32; 4], String> {
    if !uv.into_iter().all(f32::is_finite)
        || texture.width == 0
        || texture.height == 0
        || texture.rgba.len() != (texture.width * texture.height * 4) as usize
    {
        return Err(format!("{}: invalid texture sample", texture.name));
    }
    // Source: renderer.rs uses repeat + linear filtering and car.wgsl samples
    // the atlas with textureSample. This mirrors raw sampler RGBA, not lighting.
    let coordinate = |uv: f32, size: u32| {
        let texel = uv.rem_euclid(1.0) * size as f32 - 0.5;
        (texel.floor() as i32, texel.fract())
    };
    let (x, fx) = coordinate(uv[0], texture.width);
    let (y, fy) = coordinate(uv[1], texture.height);
    let texel = |x: i32, y: i32| -> [f32; 4] {
        let x = x.rem_euclid(texture.width as i32) as usize;
        let y = y.rem_euclid(texture.height as i32) as usize;
        let offset = (y * texture.width as usize + x) * 4;
        std::array::from_fn(|channel| texture.rgba[offset + channel] as f32 / 255.0)
    };
    let corners: [[f32; 4]; 4] = [
        texel(x, y),
        texel(x + 1, y),
        texel(x, y + 1),
        texel(x + 1, y + 1),
    ];
    Ok(std::array::from_fn(|channel| {
        let top = corners[0][channel] + (corners[1][channel] - corners[0][channel]) * fx;
        let bottom = corners[2][channel] + (corners[3][channel] - corners[2][channel]) * fx;
        top + (bottom - top) * fy
    }))
}

fn entry_name(data: &[u8]) -> String {
    String::from_utf8_lossy(data.split(|byte| *byte == 0).next().unwrap_or(&[]))
        .trim()
        .to_string()
}

fn read_u16(data: &[u8], offset: usize) -> Result<u16, String> {
    Ok(u16::from_le_bytes(
        data.get(offset..offset + 2)
            .ok_or("truncated tPartInfo")?
            .try_into()
            .map_err(|_| "invalid tPartInfo")?,
    ))
}

fn read_i32(data: &[u8], offset: usize) -> Result<i32, String> {
    Ok(i32::from_le_bytes(
        data.get(offset..offset + 4)
            .ok_or("truncated tPartInfo")?
            .try_into()
            .map_err(|_| "invalid tPartInfo")?,
    ))
}

fn read_u32(data: &[u8], offset: usize) -> Result<u32, String> {
    Ok(u32::from_le_bytes(
        data.get(offset..offset + 4)
            .ok_or("truncated material")?
            .try_into()
            .map_err(|_| "invalid material")?,
    ))
}

fn parse_mesh_name(mesh_name: &str) -> Result<(usize, u16), String> {
    let (article_name, part) = mesh_name
        .rsplit_once('/')
        .ok_or_else(|| format!("invalid mesh name {mesh_name}"))?;
    let (_, article) = article_name
        .rsplit_once('#')
        .ok_or_else(|| format!("invalid mesh name {mesh_name}"))?;
    Ok((
        article
            .parse::<usize>()
            .map_err(|_| format!("invalid article index {mesh_name}"))?,
        part.parse::<u16>()
            .map_err(|_| format!("invalid part index {mesh_name}"))?,
    ))
}

fn part_metadata(crp: &nfs_formats::Crp, mesh_name: &str) -> Result<PartMetadata, String> {
    let (article_index, part) = parse_mesh_name(mesh_name)?;
    let article = crp
        .articles
        .get(article_index)
        .ok_or_else(|| format!("article missing for {mesh_name}"))?;
    let pr = article
        .children
        .iter()
        .find(|entry| entry.tag == "pr" && entry.index & 0x0fff == part)
        .ok_or_else(|| format!("part missing for {mesh_name}"))?;
    Ok(PartMetadata {
        fill_mode: read_u16(&pr.data, 0)?,
        trans_info: read_u16(&pr.data, 2)?,
        material: read_u16(&pr.data, 4)?,
    })
}

fn byte_differences(left: &[u8], right: &[u8]) -> Vec<String> {
    let mut ranges = Vec::new();
    let mut index = 0;
    while index < left.len().min(right.len()) {
        if left[index] == right[index] {
            index += 1;
            continue;
        }
        let start = index;
        while index < left.len().min(right.len()) && left[index] != right[index] {
            index += 1;
        }
        let left = left[start..index]
            .iter()
            .map(|byte| format!("{byte:02x}"))
            .collect::<String>();
        let right = right[start..index]
            .iter()
            .map(|byte| format!("{byte:02x}"))
            .collect::<String>();
        ranges.push(format!("0x{start:03x}: {left}->{right}"));
    }
    if left.len() != right.len() {
        ranges.push(format!("length {}->{}", left.len(), right.len()));
    }
    ranges
}

fn ray_render_metadata(root: &Path, car: &str, body: &str, light: &str) -> Result<(), String> {
    let crp = nfs_formats::parse_crp(
        &fs::read(root.join(format!("{car}.crp"))).map_err(|error| error.to_string())?,
    )?;
    let body = part_metadata(&crp, body)?;
    let light = part_metadata(&crp, light)?;
    println!(
        "ray metadata Body pr FillMode={} TransInfo=0x{:x} material=mt{}",
        body.fill_mode, body.trans_info, body.material
    );
    println!(
        "ray metadata Light1 pr FillMode={} TransInfo=0x{:x} material=mt{}",
        light.fill_mode, light.trans_info, light.material
    );
    let material = |index| {
        crp.misc
            .iter()
            .find(|entry| entry.tag == "mt" && entry.index == index)
            .ok_or_else(|| format!("mt{index} missing"))
    };
    let body_mt = material(body.material)?;
    let light_mt = material(light.material)?;
    if body_mt.data.len() < 0x138 || light_mt.data.len() < 0x138 {
        return Err("truncated material metadata".into());
    }
    // Source: Material.h/Material.cpp name the render method (+0x10), TPG
    // index (+0x28), and cull bytes (+0x0c/+0x110). Other byte differences
    // are reported without assigning runtime semantics or render priority.
    println!(
        "ray metadata mt{} render={} tpage={} cull=[0x0c={:#04x},0x110={:#04x}]",
        body.material,
        entry_name(&body_mt.data[0x10..0x20]),
        read_u32(&body_mt.data, 0x28)?,
        body_mt.data[0x0c],
        body_mt.data[0x110],
    );
    println!(
        "ray metadata mt{} render={} tpage={} cull=[0x0c={:#04x},0x110={:#04x}]",
        light.material,
        entry_name(&light_mt.data[0x10..0x20]),
        read_u32(&light_mt.data, 0x28)?,
        light_mt.data[0x0c],
        light_mt.data[0x110],
    );
    println!(
        "ray metadata mt{}-mt{} rawDiff={:?}",
        body.material,
        light.material,
        byte_differences(&body_mt.data, &light_mt.data)
    );
    Ok(())
}

fn ray_part_info(root: &Path, car: &str, mesh_name: &str) -> Result<(), String> {
    let (article, part) = parse_mesh_name(mesh_name)?;
    let crp = nfs_formats::parse_crp(
        &fs::read(root.join(format!("{car}.crp"))).map_err(|error| error.to_string())?,
    )?;
    let article = crp
        .articles
        .get(article)
        .ok_or_else(|| format!("article missing for {mesh_name}"))?;
    let pr = article
        .children
        .iter()
        .find(|entry| entry.tag == "pr" && entry.index & 0x0fff == part)
        .ok_or_else(|| format!("part missing for {mesh_name}"))?;
    let info_count = read_i32(&pr.data, 40)?;
    if !(0..=1024).contains(&info_count) {
        return Err(format!(
            "{mesh_name}: unreasonable tPartInfo count {info_count}"
        ));
    }
    println!(
        "ray source {mesh_name} article={} prLevel={} infoCount={info_count}",
        entry_name(&article.find("Name", 0).ok_or("article has no Name")?.data),
        pr.index >> 12,
    );
    // Source: local/references/LibOpenNFS/lib/CrpLib/Common.h tPartInfo layout.
    // The original runtime meaning of RMOffs is unverified; report it verbatim.
    for index in 0..info_count as usize {
        let offset = 48 + index * 16;
        let id = read_u16(&pr.data, offset + 10)?;
        if id > 2 {
            continue;
        }
        let level = read_u16(&pr.data, offset + 12)?;
        let row = read_u16(&pr.data, offset + 14)?;
        let tag = ["vt", "nm", "uv"][id as usize];
        let entry_levels = article
            .children
            .iter()
            .filter(|entry| entry.tag == tag)
            .map(|entry| entry.index & 0x000f)
            .collect::<Vec<_>>();
        println!(
            "ray source channel {tag} tPartInfo.Level={level} RMOffs={} Offset={} IndexRowRef={row} entryLevels={entry_levels:?}",
            read_i32(&pr.data, offset)?,
            read_i32(&pr.data, offset + 4)?,
        );
    }
    Ok(())
}

fn ray_audit(scene: &Scene, root: &Path, car: &str) -> Result<(), String> {
    let light = scene
        .meshes
        .iter()
        .find(|mesh| mesh.name == "Light1#19/0")
        .ok_or("Light1#19/0 is absent")?;
    let target = mesh_center(light)?;
    let center: [f32; 3] =
        std::array::from_fn(|axis| (scene.bounds[0][axis] + scene.bounds[1][axis]) * 0.5);
    let radius = length(sub(scene.bounds[1], scene.bounds[0])) * 0.5;
    // Diagnostic camera convention supplied with this audit; the target is the
    // Light1 AABB centre. A matching t proves coincident depth on this ray only.
    let eye = std::array::from_fn(|axis| {
        center[axis]
            + radius
                * 2.8
                * [
                    0.75f32.sin() * 0.27f32.cos(),
                    0.27f32.sin(),
                    0.75f32.cos() * 0.27f32.cos(),
                ][axis]
    });
    let direction = sub(target, eye);
    let direction = std::array::from_fn(|axis| direction[axis] / length(direction));
    println!("ray Light1#19/0 eye={eye:?} target={target:?} radius={radius:.7}");
    let mut depths = [None; 2];
    let mut source_meshes = [None, None];
    for (group, (label, matches)) in [("Body", true), ("Light1", false)].into_iter().enumerate() {
        let candidates = scene.meshes.iter().filter(|mesh| {
            if matches {
                mesh.name.starts_with("Body#")
            } else {
                mesh.name == "Light1#19/0"
            }
        });
        let hits = candidates
            .map(|mesh| Ok((mesh, nearest_ray_hit(mesh, eye, direction)?)))
            .collect::<Result<Vec<_>, String>>()?;
        let hit = hits
            .into_iter()
            .filter_map(|(mesh, hit)| hit.map(|hit| (mesh, hit)))
            .min_by(|(_, a), (_, b)| a.t.total_cmp(&b.t));
        match hit {
            Some((mesh, hit)) => {
                depths[group] = Some(hit.t);
                source_meshes[group] = Some(mesh.name.as_str());
                let material = scene
                    .materials
                    .get(mesh.material)
                    .ok_or_else(|| format!("{} material out of bounds", mesh.name))?;
                let rgba = match material.texture {
                    Some(page) => sampled_rgba(
                        scene.textures.get(page).ok_or_else(|| {
                            format!("{} texture page out of bounds", material.name)
                        })?,
                        hit.uv,
                    )?,
                    None => [1.0; 4],
                };
                println!(
                    "ray {label} mesh={} tri={} t={:.9} uv={:?} sampledRGBA={rgba:?} {}",
                    mesh.name, hit.triangle, hit.t, hit.uv, material.name
                );
            }
            None => println!("ray {label}: no intersection"),
        }
    }
    if let [Some(body), Some(light)] = depths {
        println!("ray depth Body-Light={:.9}", body - light);
    }
    if let [Some(body), Some(light)] = source_meshes {
        ray_render_metadata(root, car, body, light)?;
    }
    for mesh_name in source_meshes.into_iter().flatten() {
        ray_part_info(root, car, mesh_name)?;
    }
    Ok(())
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let args: Vec<_> = env::args().collect();
    let root = Path::new(
        args.get(1)
            .ok_or("expected CarModel directory and car id")?,
    );
    let car = args.get(2).ok_or("expected car id")?;
    let mut files = AssetFiles::new();
    for entry in fs::read_dir(root)? {
        let path = entry?.path();
        let name = path.file_name().unwrap().to_string_lossy().to_lowercase();
        if name == format!("{car}.crp") || name == format!("{car}.tpg") || name.ends_with(".fsh") {
            files.insert(name, fs::read(path)?);
        }
    }
    let scene = load_car(&files, car)?;
    if let Some(output) = args
        .iter()
        .skip(3)
        .find(|arg| arg.as_str() != "--ray-light1")
    {
        fs::create_dir_all(output)?;
        for texture in &scene.textures {
            let size = 54 + texture.width * texture.height * 4;
            let mut bmp = vec![0u8; 54];
            bmp[..2].copy_from_slice(b"BM");
            bmp[2..6].copy_from_slice(&size.to_le_bytes());
            bmp[10..14].copy_from_slice(&54u32.to_le_bytes());
            bmp[14..18].copy_from_slice(&40u32.to_le_bytes());
            bmp[18..22].copy_from_slice(&texture.width.to_le_bytes());
            bmp[22..26].copy_from_slice(&(-(texture.height as i32)).to_le_bytes());
            bmp[26..28].copy_from_slice(&1u16.to_le_bytes());
            bmp[28..30].copy_from_slice(&32u16.to_le_bytes());
            for p in texture.rgba.chunks_exact(4) {
                bmp.extend_from_slice(&[p[2], p[1], p[0], 255]);
            }
            fs::write(
                Path::new(output).join(format!("{}.bmp", texture.name)),
                &bmp,
            )?;
            for (dst, pixel) in bmp[54..]
                .chunks_exact_mut(4)
                .zip(texture.rgba.chunks_exact(4))
            {
                dst[..3].fill(pixel[3]);
            }
            fs::write(
                Path::new(output).join(format!("{}-alpha.bmp", texture.name)),
                bmp,
            )?;
        }
    }
    if args.iter().skip(3).any(|arg| arg == "--ray-light1") {
        ray_audit(&scene, root, car)?;
    }
    println!("{car} bounds={:?}", scene.bounds);
    for material in &scene.materials {
        if let Some(page) = material.texture {
            let mut alpha = [0usize; 3];
            for pixel in scene.textures[page].rgba.chunks_exact(4) {
                alpha[match pixel[3] {
                    0 => 0,
                    255 => 2,
                    _ => 1,
                }] += 1;
            }
            println!(
                "{} page={page} mode={:?} alpha[zero,partial,full]={alpha:?}",
                material.name, material.alpha_mode
            );
        }
    }
    let mut total = [0usize; 3];
    for mesh in &scene.meshes {
        let mut counts = [0usize; 3];
        let mut bounds = [[f32::INFINITY; 3], [f32::NEG_INFINITY; 3]];
        let mut uv_bounds = [[f32::INFINITY; 2], [f32::NEG_INFINITY; 2]];
        for v in &mesh.vertices {
            for k in 0..3 {
                bounds[0][k] = bounds[0][k].min(v.position[k]);
                bounds[1][k] = bounds[1][k].max(v.position[k]);
            }
            for k in 0..2 {
                uv_bounds[0][k] = uv_bounds[0][k].min(v.uv[k]);
                uv_bounds[1][k] = uv_bounds[1][k].max(v.uv[k]);
            }
        }
        for t in mesh.indices.chunks_exact(3) {
            let v = [t[0], t[1], t[2]].map(|i| &mesh.vertices[i as usize]);
            let a: [f32; 3] = std::array::from_fn(|k| v[1].position[k] - v[0].position[k]);
            let b: [f32; 3] = std::array::from_fn(|k| v[2].position[k] - v[0].position[k]);
            let c = [
                a[1] * b[2] - a[2] * b[1],
                a[2] * b[0] - a[0] * b[2],
                a[0] * b[1] - a[1] * b[0],
            ];
            let dot: f32 = (0..3)
                .map(|k| c[k] * v.iter().map(|v| v.normal[k]).sum::<f32>())
                .sum();
            counts[if dot.abs() < 1e-9 {
                2
            } else if dot > 0.0 {
                0
            } else {
                1
            }] += 1;
        }
        for k in 0..3 {
            total[k] += counts[k];
        }
        println!(
            "{} {} facing={counts:?} bounds={bounds:?} uv={uv_bounds:?}",
            mesh.name, scene.materials[mesh.material].name
        );
    }
    println!("TOTAL facing [aligned, opposed, degenerate]={total:?}");
    Ok(())
}
