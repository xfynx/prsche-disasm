use std::collections::BTreeMap;

use nfs_formats::{bytes, f32le, parse_fsh, parse_track_crp, u16le, u32le, Entry};

use super::*;

fn find<'a>(files: &'a AssetFiles, name: &str) -> Result<&'a [u8], String> {
    let name = name.to_ascii_lowercase();
    let suffix = format!("/{name}");
    let matches: Vec<_> = files
        .iter()
        .filter(|(k, _)| {
            let k = k.replace('\\', "/").to_ascii_lowercase();
            k == name || k.ends_with(&suffix)
        })
        .collect();

    if matches.is_empty() {
        return Err(format!("missing resource {name}"));
    }
    if matches.len() == 1 {
        return Ok(matches[0].1);
    }
    let preferred: Vec<_> = matches
        .iter()
        .filter(|(k, _)| {
            let k = k.to_ascii_lowercase();
            (k.contains("/track/") || k.contains("\\track\\")) && !k.contains("sky")
        })
        .copied()
        .collect();
    if preferred.len() == 1 {
        return Ok(preferred[0].1);
    }
    Err(format!("ambiguous resource {name}"))
}

fn c_string(data: &[u8]) -> String {
    String::from_utf8_lossy(data.split(|byte| *byte == 0).next().unwrap_or(&[])).into_owned()
}

fn normalize(v: [f32; 3]) -> [f32; 3] {
    let len = v.iter().map(|x| x * x).sum::<f32>().sqrt();
    if len > 1e-8 {
        v.map(|x| x / len)
    } else {
        [0.; 3]
    }
}

fn triangle_normal(triangle: [[f32; 3]; 3]) -> [f32; 3] {
    let a: [f32; 3] = std::array::from_fn(|i| triangle[1][i] - triangle[0][i]);
    let b: [f32; 3] = std::array::from_fn(|i| triangle[2][i] - triangle[0][i]);
    normalize([
        a[1] * b[2] - a[2] * b[1],
        a[2] * b[0] - a[0] * b[2],
        a[0] * b[1] - a[1] * b[0],
    ])
}

pub fn to_scene_coordinates(v: [f32; 3]) -> [f32; 3] {
    [v[0], v[1], -v[2]]
}

pub fn load(files: &AssetFiles, track: &str) -> Result<Scene, String> {
    if track.is_empty()
        || !track
            .bytes()
            .all(|b| b.is_ascii_alphanumeric() || b == b'_')
    {
        return Err("track identifier must be alphanumeric".into());
    }
    let crp_data = find(files, &format!("{track}.crp"))?;
    let crp = parse_track_crp(crp_data).map_err(|e| format!("{track}.crp: {e}"))?;

    let fsh_name = crp
        .misc
        .iter()
        .find(|e| e.tag == "sn" && e.index == 0)
        .map(|e| c_string(&e.data))
        .filter(|s| !s.is_empty())
        .unwrap_or_else(|| format!("{track}.fsh"));

    let fsh_data = find(files, &fsh_name)?;
    let images = parse_fsh(fsh_data).map_err(|e| format!("{fsh_name}: {e}"))?;

    let mut scene = Scene {
        meshes: Vec::new(),
        textures: Vec::new(),
        materials: Vec::new(),
        bounds: [[f32::INFINITY; 3], [f32::NEG_INFINITY; 3]],
        diagnostics: vec![format!(
            "Track {track}: {} articles, {} misc entries, {} decoded bytes; {} textures from {fsh_name}",
            crp.articles.len(),
            crp.misc.len(),
            crp.decoded_size,
            images.len(),
        )],
    };

    let mut tex_map = BTreeMap::new();
    for image in images {
        let idx = scene.textures.len();
        let name_key = image.name.to_ascii_lowercase();
        scene.textures.push(Texture {
            name: image.name,
            width: image.width,
            height: image.height,
            rgba: image.rgba,
        });
        tex_map.insert(name_key, idx);
    }

    let mut matmap = BTreeMap::new();
    let mut material_entries: Vec<_> = crp.misc.iter().filter(|e| e.tag == "mt").collect();
    material_entries.sort_by_key(|e| e.index);

    for e in material_entries {
        let render_method = if e.data.len() >= 32 {
            c_string(bytes(&e.data, 16, 16).map_err(|err| format!("mt{}: {err}", e.index))?)
        } else {
            String::from("Opaque")
        };

        let tex_name = if e.data.len() >= 0x2c {
            let name_bytes =
                bytes(&e.data, 0x28, 4).map_err(|err| format!("mt{}: {err}", e.index))?;
            c_string(name_bytes).trim().to_ascii_lowercase()
        } else {
            String::new()
        };

        let texture = tex_map.get(&tex_name).copied();
        let alpha_mode = if render_method == "Opaque" {
            AlphaMode::Opaque
        } else if let Some(t_idx) = texture {
            let has_transparency = scene.textures[t_idx]
                .rgba
                .as_chunks::<4>()
                .0
                .iter()
                .any(|p| p[3] < 255);
            if has_transparency {
                AlphaMode::Mask
            } else {
                AlphaMode::Opaque
            }
        } else {
            AlphaMode::Opaque
        };

        let double_sided = render_method != "Opaque";
        let depth_bias = if e.data.len() >= 0x118 {
            u32le(&e.data, 0x114).unwrap_or(0) as i32
        } else {
            0
        };

        matmap.insert(e.index, scene.materials.len());
        scene.materials.push(Material {
            name: format!("mt{}:{render_method}", e.index),
            texture,
            base_color: [1.0; 4],
            paintable: false,
            alpha_mode,
            alpha_cutoff: 0.5,
            double_sided,
            depth_bias,
        });
    }

    let mut total_tris = 0;
    for (ai, a) in crp.articles.iter().enumerate() {
        let article_name = a
            .children
            .iter()
            .find(|c| c.tag == "Name" && c.index == 0)
            .map(|c| c_string(&c.data))
            .unwrap_or_else(|| format!("article{ai}"));

        // Articles with Base flag 0x8000 are dynamic/instanced library props (e.g. smackable cones,
        // vehicles, spectator figures placed by .scn files), not static track world geometry.
        let is_library_prop = a
            .children
            .iter()
            .find(|c| c.tag == "Base" && c.index == 0)
            .and_then(|base| u32le(&base.data, 0).ok())
            .map(|b0| b0 & 0x8000 != 0)
            .unwrap_or(false);
        if is_library_prop {
            continue;
        }

        let Some(vt) = a.children.iter().find(|c| c.tag == "vt" && c.index == 0) else {
            continue;
        };
        let uv = a.children.iter().find(|c| c.tag == "uv" && c.index == 0);
        let tr = a.children.iter().find(|c| c.tag == "tr" && c.index == 0);

        if vt.data.len() % 16 != 0 {
            return Err(format!("{article_name}: unaligned vertices in vt:0"));
        }
        let n_verts = vt.data.len() / 16;

        let matrix = if let Some(t) = tr {
            if t.data.len() >= 64 {
                let mut m = [0.0f32; 16];
                for (k, val) in m.iter_mut().enumerate() {
                    *val = f32le(&t.data, k * 4).map_err(|err| format!("{article_name}: {err}"))?;
                }
                Some(m)
            } else {
                None
            }
        } else {
            None
        };

        let mut raw_positions = Vec::with_capacity(n_verts);
        for i in 0..n_verts {
            let x = f32le(&vt.data, i * 16)?;
            let y = f32le(&vt.data, i * 16 + 4)?;
            let z = f32le(&vt.data, i * 16 + 8)?;
            let (tx, ty, tz) = if let Some(m) = matrix {
                (
                    x * m[0] + y * m[4] + z * m[8] + m[12],
                    x * m[1] + y * m[5] + z * m[9] + m[13],
                    x * m[2] + y * m[6] + z * m[10] + m[14],
                )
            } else {
                (x, y, z)
            };
            raw_positions.push(to_scene_coordinates([tx, ty, tz]));
        }

        for pr in a
            .children
            .iter()
            .filter(|c| c.tag == "pr" && (c.index >> 12) == 0)
        {
            let m = parse_mesh(
                pr,
                &raw_positions,
                uv,
                &matmap,
                format!("{article_name}#{ai}/{}", pr.index),
            )?;
            if !m.indices.is_empty() {
                total_tris += m.indices.len() / 3;
                for v in &m.vertices {
                    for k in 0..3 {
                        scene.bounds[0][k] = scene.bounds[0][k].min(v.position[k]);
                        scene.bounds[1][k] = scene.bounds[1][k].max(v.position[k]);
                    }
                }
                scene.meshes.push(m);
            }
        }
    }

    if scene.meshes.is_empty() {
        return Err("no drawable meshes in track".into());
    }

    scene.diagnostics.push(format!(
        "Loaded {} meshes, {} triangles, bounds min=[{:.2}, {:.2}, {:.2}] max=[{:.2}, {:.2}, {:.2}]",
        scene.meshes.len(),
        total_tris,
        scene.bounds[0][0], scene.bounds[0][1], scene.bounds[0][2],
        scene.bounds[1][0], scene.bounds[1][1], scene.bounds[1][2],
    ));

    Ok(scene)
}

fn parse_mesh(
    pr: &Entry,
    positions: &[[f32; 3]],
    uv: Option<&Entry>,
    materials: &BTreeMap<u16, usize>,
    name: String,
) -> Result<Mesh, String> {
    let d = &pr.data;
    if d.len() < 48 {
        return Err("pr entry data too short".into());
    }
    let prim_type = u32le(d, 0)? & 0xffff;
    let mat_id = u16le(d, 4)?;
    let material = *materials
        .get(&mat_id)
        .ok_or_else(|| format!("missing referenced material {mat_id}"))?;
    let ni = u32le(d, 40)? as usize;
    let nd = u32le(d, 44)? as usize;
    if ni > 64 || nd > 16 {
        return Err("unreasonable part rows in pr".into());
    }
    let ib = 48 + ni * 16;
    let data_offset = ib + nd * 8;
    let raw = bytes(
        d,
        data_offset,
        nd.checked_mul(pr.count).ok_or("index size overflow")?,
    )?;

    let mut index_rows = Vec::new();
    for row in 0..nd {
        let offset = u32le(d, ib + row * 8 + 4)? as usize;
        bytes(raw, offset, pr.count)?;
        index_rows.push(offset);
    }

    let mut channels = BTreeMap::new();
    for i in 0..ni {
        let o = 48 + i * 16;
        let kind = u16le(d, o + 10)?;
        if kind <= 2 {
            let adjust = u32le(d, o + 4)? as usize;
            let row = u16le(d, o + 14)?;
            let offset = if row == u16::MAX {
                None
            } else {
                Some(
                    *index_rows
                        .get(row as usize)
                        .ok_or("index row reference out of bounds")?,
                )
            };
            let stride = if kind == 2 { 8 } else { 16 };
            if !adjust.is_multiple_of(stride) {
                return Err("unaligned index base".into());
            }
            channels.insert(kind, (offset, adjust / stride));
        }
    }

    let (vo, va) = *channels.get(&0).ok_or("missing vertex index stream")?;
    let mut vertices = Vec::with_capacity(pr.count);
    let mut raw_v_indices = Vec::with_capacity(pr.count);

    for i in 0..pr.count {
        let ix = vo.map_or(i, |off| raw[off + i] as usize) + va;
        let position = *positions
            .get(ix)
            .ok_or_else(|| format!("vertex index {ix} out of bounds ({})", positions.len()))?;

        let mut tex = [0.0; 2];
        if let (Some(u), Some(&(off, adj))) = (uv, channels.get(&2)) {
            let u_ix = off.map_or(i, |off| raw[off + i] as usize) + adj;
            if u.data.len() >= (u_ix + 1) * 8 {
                tex[0] = f32le(&u.data, u_ix * 8)?;
                tex[1] = f32le(&u.data, u_ix * 8 + 4)?;
            }
        }

        raw_v_indices.push(ix);
        vertices.push(Vertex {
            position,
            normal: [0.0, 0.0, 0.0],
            uv: tex,
        });
    }

    let mut indices = Vec::new();
    match prim_type {
        3 => {
            if !pr.count.is_multiple_of(3) {
                return Err("triangle index count not divisible by three".into());
            }
            indices.reserve(pr.count);
            for i in 0..pr.count as u32 {
                indices.push(i);
            }
        }
        4 => {
            if !pr.count.is_multiple_of(4) {
                return Err("quad index count not divisible by four".into());
            }
            let n_quads = pr.count / 4;
            indices.reserve(n_quads * 6);
            for q in 0..n_quads as u32 {
                let base = q * 4;
                indices.extend([base, base + 1, base + 2, base, base + 2, base + 3]);
            }
        }
        1 => {
            if pr.count >= 3 {
                for i in 0..pr.count - 2 {
                    let (a, b, c) = if i % 2 == 0 {
                        (i, i + 1, i + 2)
                    } else {
                        (i + 1, i, i + 2)
                    };
                    let va = raw_v_indices[a];
                    let vb = raw_v_indices[b];
                    let vc = raw_v_indices[c];
                    if va != vb && vb != vc && va != vc {
                        indices.extend([a as u32, b as u32, c as u32]);
                    }
                }
            }
        }
        other => return Err(format!("unsupported primitive type {other:#x}")),
    }

    // Accumulate normals across triangles
    for tri in indices.as_chunks::<3>().0 {
        let i0 = tri[0] as usize;
        let i1 = tri[1] as usize;
        let i2 = tri[2] as usize;
        let n = triangle_normal([
            vertices[i0].position,
            vertices[i1].position,
            vertices[i2].position,
        ]);
        for &idx in &[i0, i1, i2] {
            vertices[idx].normal[0] += n[0];
            vertices[idx].normal[1] += n[1];
            vertices[idx].normal[2] += n[2];
        }
    }
    for v in &mut vertices {
        let norm = normalize(v.normal);
        v.normal = if norm == [0.0; 3] {
            [0.0, 1.0, 0.0]
        } else {
            norm
        };
    }

    Ok(Mesh {
        name,
        vertices,
        indices,
        material,
    })
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn local_skidpad_loads_to_valid_scene() {
        let root = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("../../../../local/game/GameData/Track");
        let crp_path = root.join("skidpad.crp");
        let fsh_path = root.join("skidpad.fsh");
        if !crp_path.exists() || !fsh_path.exists() {
            return;
        }

        let mut files = AssetFiles::new();
        files.insert("skidpad.crp".into(), std::fs::read(&crp_path).unwrap());
        files.insert("skidpad.fsh".into(), std::fs::read(&fsh_path).unwrap());

        let scene = load(&files, "skidpad").unwrap();
        assert_eq!(scene.meshes.len(), 385);
        assert_eq!(scene.textures.len(), 98);
        assert_eq!(scene.materials.len(), 107);
        assert!(scene.bounds[0][0] < -200.0);
        assert!(scene.bounds[1][0] > 200.0);

        // Check for road meshes
        assert!(scene.meshes.iter().any(|m| m.name.starts_with("RD0040C")));
        assert!(scene.meshes.iter().any(|m| m.name.starts_with("RD0048C")));

        // Check for environmental objects
        assert!(scene
            .meshes
            .iter()
            .any(|m| m.name.starts_with("TIREWALL01")));
    }

    #[test]
    fn missing_track_file_reported() {
        let files = AssetFiles::new();
        let err = load(&files, "skidpad").unwrap_err();
        assert!(err.contains("missing resource skidpad.crp"));
    }
}
