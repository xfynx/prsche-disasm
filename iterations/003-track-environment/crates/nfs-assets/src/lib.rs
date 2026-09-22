//! GPU-independent scene contract shared by native and browser frontends.
use std::collections::BTreeMap;

#[derive(Debug, Clone)]
pub struct Vertex {
    pub position: [f32; 3],
    pub normal: [f32; 3],
    pub uv: [f32; 2],
}

#[derive(Debug, Clone)]
pub struct Mesh {
    pub name: String,
    pub vertices: Vec<Vertex>,
    pub indices: Vec<u32>,
    pub material: usize,
}

#[derive(Debug, Clone)]
pub struct Texture {
    pub name: String,
    pub width: u32,
    pub height: u32,
    pub rgba: Vec<u8>,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum AlphaMode {
    Opaque,
    Mask,
    Blend,
}

#[derive(Debug, Clone)]
pub struct Material {
    pub name: String,
    pub texture: Option<usize>,
    pub base_color: [f32; 4],
    pub paintable: bool,
    pub alpha_mode: AlphaMode,
    pub alpha_cutoff: f32,
    pub double_sided: bool,
    /// Signed material depth offset; separates coplanar detail surfaces.
    pub depth_bias: i32,
}

/// A library prop template extracted from the track CRP (articles with `Base & 0x8000`).
#[derive(Debug, Clone)]
pub struct PropArticle {
    /// 4-byte FourCC identifier from `Base:0` at offset 0x44 (e.g. `CONE`, `ARW1`, `SAW1`).
    pub fourcc: u32,
    /// Range of mesh indices in `Scene::meshes` belonging to this prop.
    pub mesh_range: std::ops::Range<usize>,
}

/// A placed prop instance from a `.scn` scenario file.
#[derive(Debug, Clone)]
pub struct PropInstance {
    /// Index into `Scene::prop_articles`.
    pub article_index: usize,
    /// World position in scene coordinates (already transformed to `[x, y, -z]`).
    pub position: [f32; 3],
    /// 3×3 orientation matrix (row-major) from the `.scn` file.
    pub rotation: [[f32; 3]; 3],
}

/// Sky panorama texture loaded from `Sky/<track>.fsh`.
#[derive(Debug, Clone)]
pub struct SkyTexture {
    pub width: u32,
    pub height: u32,
    pub rgba: Vec<u8>,
}

#[derive(Debug, Clone)]
pub struct Scene {
    pub meshes: Vec<Mesh>,
    pub textures: Vec<Texture>,
    pub materials: Vec<Material>,
    pub bounds: [[f32; 3]; 2],
    pub diagnostics: Vec<String>,
    /// Library prop templates (mesh geometry centered at origin).
    pub prop_articles: Vec<PropArticle>,
    /// Placed prop instances from `.scn` scenario files.
    pub prop_instances: Vec<PropInstance>,
    /// Sky horizon panorama texture, if available.
    pub sky_texture: Option<SkyTexture>,
}

impl Default for Scene {
    fn default() -> Self {
        Self {
            meshes: Vec::new(),
            textures: Vec::new(),
            materials: Vec::new(),
            bounds: [[f32::INFINITY; 3], [f32::NEG_INFINITY; 3]],
            diagnostics: Vec::new(),
            prop_articles: Vec::new(),
            prop_instances: Vec::new(),
            sky_texture: None,
        }
    }
}

/// Keys are case-insensitive slash-separated paths or bare resource filenames.
pub type AssetFiles = BTreeMap<String, Vec<u8>>;

/// Load a car from user-selected bytes. Native and WASM call the same implementation.
pub fn load_car(files: &AssetFiles, car: &str) -> Result<Scene, String> {
    loader::load(files, car).map_err(|e| format!("{car}: {e}"))
}

/// Load a track from user-selected bytes. Native and WASM call the same implementation.
pub fn load_track(files: &AssetFiles, track: &str) -> Result<Scene, String> {
    track_loader::load(files, track).map_err(|e| format!("{track}: {e}"))
}

mod loader;
pub mod track_loader;
