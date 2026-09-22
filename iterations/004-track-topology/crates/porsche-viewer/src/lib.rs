pub mod arcade;
pub mod car_mesh;
mod renderer;
pub use renderer::{Camera, Renderer, instance, request_gpu, summarize};

#[cfg(target_arch = "wasm32")]
mod browser;

#[cfg(not(target_arch = "wasm32"))]
pub mod native;
