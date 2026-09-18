use std::collections::BTreeMap;

use js_sys::{Array, Uint8Array};
use nfs_assets::{AssetFiles, Scene, load_car};
use wasm_bindgen::prelude::*;
use web_sys::HtmlCanvasElement;

use crate::{Renderer, instance, request_gpu, summarize};

#[wasm_bindgen(start)]
pub fn install_panic_hook() {
    console_error_panic_hook::set_once();
}

#[wasm_bindgen]
pub struct BrowserViewer {
    surface: wgpu::Surface<'static>,
    config: wgpu::SurfaceConfiguration,
    device: wgpu::Device,
    queue: wgpu::Queue,
    renderer: Option<Renderer>,
}

#[wasm_bindgen]
pub async fn create_viewer(canvas: HtmlCanvasElement) -> Result<BrowserViewer, JsValue> {
    if !has_webgpu() {
        return Err(JsValue::from_str(
            "WebGPU недоступен. Откройте страницу в браузере с поддержкой WebGPU.",
        ));
    }
    let width = canvas.client_width().max(1) as u32;
    let height = canvas.client_height().max(1) as u32;
    canvas.set_width(width);
    canvas.set_height(height);

    let instance = instance();
    let surface = instance
        .create_surface(wgpu::SurfaceTarget::Canvas(canvas))
        .map_err(|e| JsValue::from_str(&format!("Не удалось создать поверхность WebGPU: {e}")))?;
    let (adapter, device, queue) = request_gpu(&instance, Some(&surface))
        .await
        .map_err(|e| JsValue::from_str(&format!("Не удалось открыть WebGPU: {e}")))?;
    let caps = surface.get_capabilities(&adapter);
    let format = caps
        .formats
        .iter()
        .copied()
        .find(wgpu::TextureFormat::is_srgb)
        .or_else(|| caps.formats.first().copied())
        .ok_or_else(|| JsValue::from_str("WebGPU не вернул формат canvas"))?;
    let config = wgpu::SurfaceConfiguration {
        usage: wgpu::TextureUsages::RENDER_ATTACHMENT,
        format,
        color_space: wgpu::SurfaceColorSpace::Auto,
        width,
        height,
        present_mode: wgpu::PresentMode::Fifo,
        alpha_mode: caps.alpha_modes[0],
        view_formats: vec![],
        desired_maximum_frame_latency: 2,
    };
    surface.configure(&device, &config);

    Ok(BrowserViewer {
        surface,
        config,
        device,
        queue,
        renderer: None,
    })
}

#[wasm_bindgen]
impl BrowserViewer {
    pub fn load(&mut self, names: Array, bytes: Array, car: String) -> Result<String, JsValue> {
        let scene = files_from_js(names, bytes)
            .and_then(|files| load_car(&files, &car))
            .map_err(|e| JsValue::from_str(&e))?;
        self.set_scene(scene)
    }

    pub fn resize(&mut self, width: u32, height: u32) {
        let width = width.max(1);
        let height = height.max(1);
        self.config.width = width;
        self.config.height = height;
        self.surface.configure(&self.device, &self.config);
        if let Some(renderer) = &mut self.renderer {
            renderer.resize(width, height);
        }
    }

    pub fn orbit(&mut self, dx: f32, dy: f32) {
        if let Some(renderer) = &mut self.renderer {
            renderer.camera.orbit(dx, dy);
        }
    }

    pub fn zoom(&mut self, delta: f32) {
        if let Some(renderer) = &mut self.renderer {
            renderer.camera.zoom(delta);
        }
    }

    pub fn reset_camera(&mut self) {
        if let Some(renderer) = &mut self.renderer {
            renderer.camera.reset();
        }
    }

    pub fn cycle_paint_color(&mut self) {
        if let Some(renderer) = &mut self.renderer {
            renderer.cycle_paint_color();
        }
    }

    pub fn render(&mut self) -> Result<(), JsValue> {
        let Some(renderer) = &mut self.renderer else {
            return Ok(());
        };
        let frame = match self.surface.get_current_texture() {
            wgpu::CurrentSurfaceTexture::Success(frame)
            | wgpu::CurrentSurfaceTexture::Suboptimal(frame) => frame,
            wgpu::CurrentSurfaceTexture::Lost | wgpu::CurrentSurfaceTexture::Outdated => {
                self.surface.configure(&renderer.device, &self.config);
                return Ok(());
            }
            wgpu::CurrentSurfaceTexture::Timeout | wgpu::CurrentSurfaceTexture::Occluded => {
                return Ok(());
            }
            wgpu::CurrentSurfaceTexture::Validation => {
                return Err(JsValue::from_str("Ошибка проверки поверхности WebGPU"));
            }
        };
        let view = frame.texture.create_view(&Default::default());
        renderer.render(&view);
        self.queue.present(frame);
        Ok(())
    }
}

impl BrowserViewer {
    fn set_scene(&mut self, scene: Scene) -> Result<String, JsValue> {
        let summary = summarize(&scene);
        let renderer = Renderer::new(
            self.device.clone(),
            self.queue.clone(),
            self.config.format,
            self.config.width,
            self.config.height,
            &scene,
        )
        .map_err(|e| JsValue::from_str(&e))?;
        self.renderer = Some(renderer);
        Ok(summary)
    }
}

fn files_from_js(names: Array, bytes: Array) -> Result<AssetFiles, String> {
    if names.length() != bytes.length() {
        return Err("internal file list mismatch".into());
    }
    let mut files = BTreeMap::new();
    for index in 0..names.length() {
        let name = names
            .get(index)
            .as_string()
            .ok_or("file name is not a string")?
            .replace('\\', "/")
            .to_ascii_lowercase();
        let data = Uint8Array::new(&bytes.get(index)).to_vec();
        files.insert(name, data);
    }
    Ok(files)
}

fn has_webgpu() -> bool {
    js_sys::Reflect::has(&js_sys::global(), &JsValue::from_str("GPU")).unwrap_or(false)
        || web_sys::window()
            .and_then(|window| js_sys::Reflect::get(&window, &JsValue::from_str("navigator")).ok())
            .and_then(|navigator| js_sys::Reflect::get(&navigator, &JsValue::from_str("gpu")).ok())
            .is_some()
}
