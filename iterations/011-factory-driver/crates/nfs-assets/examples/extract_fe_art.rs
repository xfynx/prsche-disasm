use std::fs;
use std::path::Path;

fn write_bmp(path: &Path, width: u32, height: u32, rgba: &[u8]) -> std::io::Result<()> {
    let mut out = Vec::with_capacity(54 + (width * height * 4) as usize);
    out.extend_from_slice(b"BM");
    let file_size = 54 + width * height * 4;
    out.extend_from_slice(&file_size.to_le_bytes());
    out.extend_from_slice(&[0, 0, 0, 0]);
    out.extend_from_slice(&54u32.to_le_bytes());
    out.extend_from_slice(&40u32.to_le_bytes());
    out.extend_from_slice(&(width as i32).to_le_bytes());
    out.extend_from_slice(&(-(height as i32)).to_le_bytes()); // top-down
    out.extend_from_slice(&1u16.to_le_bytes());
    out.extend_from_slice(&32u16.to_le_bytes());
    out.extend_from_slice(&0u32.to_le_bytes());
    out.extend_from_slice(&(width * height * 4).to_le_bytes());
    out.extend_from_slice(&2835u32.to_le_bytes());
    out.extend_from_slice(&2835u32.to_le_bytes());
    out.extend_from_slice(&0u32.to_le_bytes());
    out.extend_from_slice(&0u32.to_le_bytes());
    for chunk in rgba.as_chunks::<4>().0 {
        out.push(chunk[2]);
        out.push(chunk[1]);
        out.push(chunk[0]);
        out.push(chunk[3]);
    }
    fs::write(path, out)
}

fn main() {
    let game_dir = if Path::new("local/game/FEData").exists() {
        Path::new("local/game/FEData").to_path_buf()
    } else {
        Path::new("../../local/game/FEData").to_path_buf()
    };
    let out_dir = if Path::new("iterations/011-factory-driver/web/assets").exists() {
        Path::new("iterations/011-factory-driver/web/assets").to_path_buf()
    } else {
        Path::new("web/assets").to_path_buf()
    };
    fs::create_dir_all(&out_dir).unwrap();

    let art_files = [
        ("Art/porsche.fsh", "porsche"),
        ("Art/FactoryPeople.fsh", "people"),
        ("Art/careertabs.fsh", "careertabs"),
        ("Art/tabs.fsh", "tabs"),
        ("Art/hud.fsh", "hud"),
        ("Art/Finallogos1.fsh", "logos"),
        ("Art/racebutton.fsh", "racebutton"),
        ("Art/BackButton.fsh", "backbutton"),
        ("Art/DarkOval.fsh", "darkoval"),
    ];

    for (rel_path, prefix) in &art_files {
        let full_path = game_dir.join(rel_path);
        if let Ok(bytes) = fs::read(&full_path) {
            if let Ok(images) = nfs_formats::parse_fsh(&bytes) {
                println!("{}: extracted {} images", rel_path, images.len());
                for img in &images {
                    let filename = format!("{}_{}.bmp", prefix, img.name);
                    let target = out_dir.join(&filename);
                    if let Err(e) = write_bmp(&target, img.width, img.height, &img.rgba) {
                        eprintln!("Failed to write {}: {}", target.display(), e);
                    }
                }
            } else {
                eprintln!("{}: failed to parse FSH", rel_path);
            }
        } else {
            eprintln!("{}: not found", full_path.display());
        }
    }

    // Also extract Factory mission diagrams (0M01.fsh through 3M12.fsh)
    let factory_dir = game_dir.join("Factory");
    if let Ok(entries) = fs::read_dir(&factory_dir) {
        for entry in entries.flatten() {
            let path = entry.path();
            if path
                .extension()
                .is_some_and(|ext| ext.eq_ignore_ascii_case("fsh"))
            {
                let stem = path.file_stem().unwrap().to_str().unwrap().to_lowercase();
                if let Ok(bytes) = fs::read(&path) {
                    if let Ok(images) = nfs_formats::parse_fsh(&bytes) {
                        if let Some(first) = images.first() {
                            let target = out_dir.join(format!("map_{}.bmp", stem));
                            let _ = write_bmp(&target, first.width, first.height, &first.rgba);
                        }
                    }
                }
            }
        }
    }

    println!("Extraction complete! Files saved to {}", out_dir.display());
}
