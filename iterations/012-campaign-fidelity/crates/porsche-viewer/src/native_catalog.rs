use std::{
    collections::BTreeSet,
    env, fs,
    path::{Path, PathBuf},
};

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum NativeTargetKind {
    Car,
    Track,
}

#[derive(Debug, Clone)]
pub struct NativeTarget {
    pub kind: NativeTargetKind,
    pub name: String,
}

#[derive(Debug, Clone)]
pub struct NativeCatalog {
    pub game_dir: PathBuf,
    cars: Vec<String>,
    tracks: Vec<String>,
    kind: NativeTargetKind,
    car_index: usize,
    track_index: usize,
}

impl NativeCatalog {
    pub fn discover_default() -> Result<Self, String> {
        let game_dir = default_game_dir().ok_or_else(|| {
            "No default local/game directory found; use view --game-dir".to_string()
        })?;
        Self::from_game_dir(game_dir)
    }

    pub fn from_game_dir(game_dir: PathBuf) -> Result<Self, String> {
        if !game_dir.is_dir() {
            return Err(format!("Game directory not found: {}", game_dir.display()));
        }
        let mut cars_crp = BTreeSet::new();
        let mut cars_tpg = BTreeSet::new();
        let mut tracks_crp = BTreeSet::new();
        let mut tracks_edges = BTreeSet::new();
        scan_dir(
            &game_dir,
            &mut cars_crp,
            &mut cars_tpg,
            &mut tracks_crp,
            &mut tracks_edges,
        )?;

        let cars = cars_crp
            .intersection(&cars_tpg)
            .cloned()
            .collect::<Vec<_>>();
        let tracks = tracks_crp
            .intersection(&tracks_edges)
            .cloned()
            .collect::<Vec<_>>();
        if cars.is_empty() {
            return Err(format!(
                "No car CRP/TPG pairs found in {}",
                game_dir.display()
            ));
        }
        if tracks.is_empty() {
            return Err(format!(
                "No track CRP/EDG pairs found in {}",
                game_dir.display()
            ));
        }

        Ok(Self {
            game_dir,
            car_index: index_or_zero(&cars, "356a"),
            track_index: index_or_zero(&tracks, "skidpad"),
            cars,
            tracks,
            kind: NativeTargetKind::Track,
        })
    }

    pub fn selected(&self) -> NativeTarget {
        NativeTarget {
            kind: self.kind,
            name: self.current_names()[self.current_index()].clone(),
        }
    }

    pub fn switch_kind(&mut self) {
        self.kind = match self.kind {
            NativeTargetKind::Car => NativeTargetKind::Track,
            NativeTargetKind::Track => NativeTargetKind::Car,
        };
    }

    pub fn advance(&mut self, delta: isize) {
        let len = self.current_len();
        if len == 0 {
            return;
        }
        let index = self.current_index();
        let next = (index as isize + delta).rem_euclid(len as isize) as usize;
        match self.kind {
            NativeTargetKind::Car => self.car_index = next,
            NativeTargetKind::Track => self.track_index = next,
        }
    }

    pub fn select_track_by_name(&mut self, track_name: &str) -> bool {
        if let Some(pos) = self.tracks.iter().position(|t| t == track_name) {
            self.kind = NativeTargetKind::Track;
            self.track_index = pos;
            true
        } else {
            false
        }
    }

    pub fn current_kind_label(&self) -> &'static str {
        match self.kind {
            NativeTargetKind::Car => "Car",
            NativeTargetKind::Track => "Track",
        }
    }

    pub fn current_index(&self) -> usize {
        match self.kind {
            NativeTargetKind::Car => self.car_index,
            NativeTargetKind::Track => self.track_index,
        }
    }

    pub fn current_len(&self) -> usize {
        self.current_names().len()
    }

    fn current_names(&self) -> &[String] {
        match self.kind {
            NativeTargetKind::Car => &self.cars,
            NativeTargetKind::Track => &self.tracks,
        }
    }
}

fn default_game_dir() -> Option<PathBuf> {
    let mut candidates = Vec::new();
    if let Ok(current) = env::current_dir() {
        add_local_game_candidates(&current, &mut candidates);
    }
    add_local_game_candidates(Path::new(env!("CARGO_MANIFEST_DIR")), &mut candidates);

    let mut seen = BTreeSet::new();
    candidates.into_iter().find(|path| {
        let key = path.to_string_lossy().to_ascii_lowercase();
        seen.insert(key) && path.is_dir()
    })
}

fn add_local_game_candidates(base: &Path, candidates: &mut Vec<PathBuf>) {
    for ancestor in base.ancestors() {
        candidates.push(ancestor.join("local").join("game"));
    }
}

fn scan_dir(
    dir: &Path,
    cars_crp: &mut BTreeSet<String>,
    cars_tpg: &mut BTreeSet<String>,
    tracks_crp: &mut BTreeSet<String>,
    tracks_edges: &mut BTreeSet<String>,
) -> Result<(), String> {
    for entry in fs::read_dir(dir).map_err(|e| format!("{}: {e}", dir.display()))? {
        let entry = entry.map_err(|e| format!("{}: {e}", dir.display()))?;
        let path = entry.path();
        let kind = entry
            .file_type()
            .map_err(|e| format!("{}: {e}", path.display()))?;
        if kind.is_dir() {
            scan_dir(&path, cars_crp, cars_tpg, tracks_crp, tracks_edges)?;
            continue;
        }
        if !kind.is_file() {
            continue;
        }
        let Some(stem) = path.file_stem().and_then(|stem| stem.to_str()) else {
            continue;
        };
        let Some(extension) = path.extension().and_then(|ext| ext.to_str()) else {
            continue;
        };
        let name = stem.to_ascii_lowercase();
        let extension = extension.to_ascii_lowercase();
        if path_has_component(&path, "carmodel") {
            match extension.as_str() {
                "crp" => {
                    cars_crp.insert(name);
                }
                "tpg" => {
                    cars_tpg.insert(name);
                }
                _ => {}
            }
        } else if path_has_component(&path, "track") {
            match extension.as_str() {
                "crp" => {
                    tracks_crp.insert(name);
                }
                "edg" => {
                    tracks_edges.insert(name);
                }
                _ => {}
            }
        }
    }
    Ok(())
}

fn path_has_component(path: &Path, name: &str) -> bool {
    path.components().any(|component| {
        component
            .as_os_str()
            .to_str()
            .is_some_and(|component| component.eq_ignore_ascii_case(name))
    })
}

fn index_or_zero(items: &[String], preferred: &str) -> usize {
    items
        .iter()
        .position(|item| item.eq_ignore_ascii_case(preferred))
        .unwrap_or(0)
}
