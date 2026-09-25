//! Read-only audit of the static `RD*` support-surface hypothesis.
//!
//! Usage: `cargo run -p nfs-assets --example audit_surface -- <GameData/Track> [track ...]`
//! With no track arguments, audits every direct `*.crp` / `*.fsh` pair in the directory.

use std::{env, fs, path::Path};

use nfs_assets::{load_track, AssetFiles, RoadSurface};

const MAX_SAMPLES_PER_TRACK: usize = 100_000;
const HEIGHT_TOLERANCE: f32 = 0.01;

fn collect_tracks(root: &Path, requested: &[String]) -> Result<Vec<String>, String> {
    if !requested.is_empty() {
        return Ok(requested
            .iter()
            .map(|track| track.to_ascii_lowercase())
            .collect());
    }
    let mut tracks = fs::read_dir(root)
        .map_err(|error| format!("{}: {error}", root.display()))?
        .filter_map(|entry| entry.ok())
        .filter_map(|entry| {
            let path = entry.path();
            let extension = path.extension()?.to_str()?;
            (extension.eq_ignore_ascii_case("crp"))
                .then(|| path.file_stem()?.to_str().map(str::to_owned))?
        })
        .filter(|track| root.join(format!("{track}.fsh")).is_file())
        .collect::<Vec<_>>();
    tracks.sort_by_key(|track| track.to_ascii_lowercase());
    if tracks.is_empty() {
        return Err("no direct CRP/FSH track pairs found".into());
    }
    Ok(tracks)
}

fn load_pair(root: &Path, track: &str) -> Result<AssetFiles, String> {
    let mut files = AssetFiles::new();
    for extension in ["crp", "fsh"] {
        let path = root.join(format!("{track}.{extension}"));
        files.insert(
            format!("{track}.{extension}"),
            fs::read(&path).map_err(|error| format!("{}: {error}", path.display()))?,
        );
    }
    Ok(files)
}

fn centroid(points: &[[f32; 3]; 3]) -> [f32; 3] {
    std::array::from_fn(|axis| (points[0][axis] + points[1][axis] + points[2][axis]) / 3.0)
}

fn audit(track: &str, surface: &RoadSurface) -> Result<(), String> {
    if surface.triangle_count() == 0 {
        return Err(format!("{track}: no accepted static RD* support triangles"));
    }
    let mut sampled = 0usize;
    let mut max_height_error = 0.0f32;
    for (identity, points, _) in surface.triangles().take(MAX_SAMPLES_PER_TRACK) {
        let point = centroid(points);
        let hit = surface
            .query(
                point[0],
                point[2],
                point[1],
                HEIGHT_TOLERANCE,
                HEIGHT_TOLERANCE,
            )
            .ok_or_else(|| {
                format!(
                    "{track}: centroid miss {}#{} primitive={} triangle={} point={point:?} vertices={points:?}",
                    identity.article_name,
                    identity.article_index,
                    identity.primitive_index,
                    identity.triangle_index
                )
            })?;
        let error = (hit.height - point[1]).abs();
        if error > HEIGHT_TOLERANCE {
            return Err(format!(
                "{track}: height error {error:.6} at {}#{} primitive={} triangle={}",
                identity.article_name,
                identity.article_index,
                identity.primitive_index,
                identity.triangle_index
            ));
        }
        max_height_error = max_height_error.max(error);
        sampled += 1;
    }
    let omitted = surface.triangle_count().saturating_sub(sampled);
    println!(
        "{track}: accepted={} sampled={} omitted={} max-height-error={max_height_error:.7} rejects={:?}",
        surface.triangle_count(),
        sampled,
        omitted,
        surface.report(),
    );
    Ok(())
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let args = env::args().skip(1).collect::<Vec<_>>();
    let root = Path::new(args.first().ok_or("expected GameData/Track directory")?);
    let tracks = collect_tracks(root, &args[1..])?;
    for track in tracks {
        let files = load_pair(root, &track)?;
        let scene = load_track(&files, &track)?;
        let surface = scene
            .road_surface
            .as_ref()
            .ok_or_else(|| format!("{track}: loader returned no road surface"))?;
        audit(&track, surface)?;
    }
    Ok(())
}
