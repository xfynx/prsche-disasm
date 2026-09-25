use std::collections::HashSet;
use std::error::Error;
use std::fs::{self, File};
use std::io::BufWriter;
use std::path::{Path, PathBuf};

type ExtractResult<T> = Result<T, Box<dyn Error>>;

fn workspace_root() -> ExtractResult<PathBuf> {
    let manifest = Path::new(env!("CARGO_MANIFEST_DIR"));
    let root = manifest
        .parent()
        .and_then(Path::parent)
        .and_then(Path::parent)
        .and_then(Path::parent)
        .ok_or("could not locate workspace root from CARGO_MANIFEST_DIR")?;
    Ok(root.canonicalize()?)
}

fn validate_paths(game_arg: &Path, out_arg: &Path) -> ExtractResult<(PathBuf, PathBuf)> {
    let root = workspace_root()?;
    let expected_game = root.join("local/game").canonicalize()?;
    let game = game_arg.canonicalize()?;
    if game != expected_game {
        return Err(format!(
            "game path must resolve to {}; refusing to read another location",
            expected_game.display()
        )
        .into());
    }

    let expected_out = root.join("local/derived/fe-ui");
    // A fresh checkout has no derived cache yet. Create only its known parent,
    // after checking that local itself is still inside this workspace.
    if !root.join("local/derived").exists() {
        if root.join("local").canonicalize()? != root.join("local") {
            return Err("workspace local directory must not be a symlink".into());
        }
        fs::create_dir(root.join("local/derived"))?;
    }
    let out_parent = out_arg
        .parent()
        .ok_or("output path must name the workspace local/derived/fe-ui directory")?;
    let out_name = out_arg
        .file_name()
        .ok_or("output path must name the workspace local/derived/fe-ui directory")?;
    let canonical_out = out_parent.canonicalize()?.join(out_name);
    if canonical_out != expected_out {
        return Err(format!(
            "output path must resolve to {}; refusing to write elsewhere",
            expected_out.display()
        )
        .into());
    }
    if out_arg.exists() && out_arg.canonicalize()? != expected_out {
        return Err("output directory must not be a symlink".into());
    }
    Ok((game, expected_out))
}

fn safe_stem(stem: &str) -> bool {
    !stem.is_empty()
        && stem.bytes().all(|byte| {
            byte.is_ascii_lowercase() || byte.is_ascii_digit() || byte == b'_' || byte == b'-'
        })
}

fn add_archive(
    game_dir: &Path,
    relative_path: &str,
    prefix: &str,
    files: &mut Vec<(String, nfs_formats::Image)>,
) -> ExtractResult<()> {
    let path = game_dir.join("FEData").join(relative_path);
    let bytes = fs::read(&path).map_err(|error| format!("{}: {error}", path.display()))?;
    let images = nfs_formats::parse_fsh(&bytes)
        .map_err(|error| format!("{}: failed to parse FSH: {error}", path.display()))?;
    if images.is_empty() {
        return Err(format!("{}: FSH contains no images", path.display()).into());
    }
    for image in images {
        if !safe_stem(&image.name) {
            return Err(format!("{}: unsafe image name {:?}", path.display(), image.name).into());
        }
        let filename = format!("{prefix}_{}.png", image.name);
        // HUD contains repeated four-character IDs. Preserve the existing UI
        // naming convention (last source entry wins), but report that choice.
        if let Some(index) = files.iter().position(|(name, _)| name == &filename) {
            eprintln!(
                "{}: repeated {}, using last source entry",
                path.display(),
                image.name
            );
            files.remove(index);
        }
        files.push((filename, image));
    }
    Ok(())
}

fn extract_all(game_dir: &Path) -> ExtractResult<Vec<(String, nfs_formats::Image)>> {
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
    let mut files = Vec::new();
    for (path, prefix) in art_files {
        add_archive(game_dir, path, prefix, &mut files)?;
    }

    let factory_dir = game_dir.join("FEData/Factory");
    let mut mission_archives = fs::read_dir(&factory_dir)
        .map_err(|error| format!("{}: {error}", factory_dir.display()))?
        .map(|entry| entry.map(|entry| entry.path()))
        .collect::<Result<Vec<_>, _>>()?;
    mission_archives.retain(|path| {
        path.extension()
            .is_some_and(|extension| extension.eq_ignore_ascii_case("fsh"))
    });
    mission_archives.sort();
    for path in mission_archives {
        let stem = path
            .file_stem()
            .and_then(|stem| stem.to_str())
            .ok_or_else(|| format!("{}: invalid filename", path.display()))?
            .to_ascii_lowercase();
        if !safe_stem(&stem) {
            return Err(format!("{}: unsafe archive name", path.display()).into());
        }
        let bytes = fs::read(&path).map_err(|error| format!("{}: {error}", path.display()))?;
        let images = nfs_formats::parse_fsh(&bytes)
            .map_err(|error| format!("{}: failed to parse FSH: {error}", path.display()))?;
        let image = images
            .into_iter()
            .next()
            .ok_or_else(|| format!("{}: FSH contains no images", path.display()))?;
        files.push((format!("map_{stem}.png"), image));
    }

    let mut names = HashSet::new();
    for (name, _) in &files {
        if !names.insert(name.clone()) {
            return Err(format!("multiple archives produce output file {name}").into());
        }
    }
    Ok(files)
}

fn write_png(path: &Path, image: &nfs_formats::Image) -> ExtractResult<()> {
    let expected_len = (image.width as usize)
        .checked_mul(image.height as usize)
        .and_then(|pixels| pixels.checked_mul(4))
        .ok_or_else(|| format!("{}: image dimensions overflow", path.display()))?;
    if image.width == 0 || image.height == 0 || image.rgba.len() != expected_len {
        return Err(format!("{}: invalid RGBA image dimensions/data", path.display()).into());
    }

    let file = BufWriter::new(File::create(path)?);
    let mut encoder = png::Encoder::new(file, image.width, image.height);
    encoder.set_color(png::ColorType::Rgba);
    encoder.set_depth(png::BitDepth::Eight);
    let mut writer = encoder.write_header()?;
    writer.write_image_data(&image.rgba)?;
    Ok(())
}

fn run() -> ExtractResult<()> {
    let args = std::env::args_os().skip(1).collect::<Vec<_>>();
    if args.len() != 2 {
        return Err(
            "usage: extract_fe_art <workspace/local/game> <workspace/local/derived/fe-ui>".into(),
        );
    }
    let (game_dir, out_dir) = validate_paths(Path::new(&args[0]), Path::new(&args[1]))?;
    let files = extract_all(&game_dir)?;

    fs::create_dir_all(&out_dir)?;
    for (name, _) in &files {
        let target = out_dir.join(name);
        if let Ok(metadata) = fs::symlink_metadata(&target) {
            if metadata.file_type().is_symlink() || !metadata.is_file() {
                return Err(format!(
                    "refusing to overwrite non-regular output path {}",
                    target.display()
                )
                .into());
            }
        }
    }
    for (name, image) in &files {
        let target = out_dir.join(name);
        write_png(&target, image)
            .map_err(|error| format!("failed to write {}: {error}", target.display()))?;
    }
    println!(
        "Extracted {} PNG files to {}",
        files.len(),
        out_dir.display()
    );
    Ok(())
}

fn main() {
    if let Err(error) = run() {
        eprintln!("FE UI extraction failed: {error}");
        std::process::exit(1);
    }
}
