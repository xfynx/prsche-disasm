#![allow(clippy::items_after_test_module)]

use std::{
    collections::BTreeMap,
    fs,
    io::BufWriter,
    num::NonZeroU32,
    path::{Path, PathBuf},
    sync::Arc,
};

use nfs_assets::{AssetFiles, Scene, load_car, load_track};
use winit::{
    application::ApplicationHandler,
    dpi::PhysicalSize,
    event::{ElementState, MouseButton, MouseScrollDelta, WindowEvent},
    event_loop::{ActiveEventLoop, EventLoop},
    keyboard::{KeyCode, PhysicalKey},
    window::{Window, WindowId},
};

use crate::{Renderer, instance, request_gpu, summarize};

pub fn run_cli(args: impl IntoIterator<Item = String>) -> Result<(), String> {
    let mut command = None;
    let mut game_dir = None;
    let mut car = None;
    let mut track = None;
    let mut screenshot = None;
    let mut yaw = None;
    let mut pitch = None;
    let mut distance = None;
    let mut center_x = None;
    let mut center_y = None;
    let mut center_z = None;
    let mut paint_index = 0;
    let mut width = 1280;
    let mut height = 720;

    let mut iter = args.into_iter();
    while let Some(arg) = iter.next() {
        match arg.as_str() {
            "inspect" | "view" => command = Some(arg),
            "--game-dir" => game_dir = Some(PathBuf::from(next_value(&mut iter, "--game-dir")?)),
            "--car" => car = Some(next_value(&mut iter, "--car")?),
            "--track" => track = Some(next_value(&mut iter, "--track")?),
            "--screenshot" => {
                screenshot = Some(PathBuf::from(next_value(&mut iter, "--screenshot")?))
            }
            "--yaw" => yaw = Some(parse_f32(&mut iter, "--yaw")?),
            "--pitch" => pitch = Some(parse_f32(&mut iter, "--pitch")?),
            "--distance" => distance = Some(parse_f32(&mut iter, "--distance")?),
            "--center-x" => center_x = Some(parse_f32(&mut iter, "--center-x")?),
            "--center-y" => center_y = Some(parse_f32(&mut iter, "--center-y")?),
            "--center-z" => center_z = Some(parse_f32(&mut iter, "--center-z")?),
            "--paint-index" => {
                paint_index = next_value(&mut iter, "--paint-index")?
                    .parse::<u32>()
                    .map_err(|_| "--paint-index requires an integer 0..5")?;
                if paint_index > 5 {
                    return Err("--paint-index must be 0..5".into());
                }
            }
            "--width" => width = parse_u32(&mut iter, "--width")?,
            "--height" => height = parse_u32(&mut iter, "--height")?,
            "--help" | "-h" => {
                println!("{}", usage());
                return Ok(());
            }
            other => return Err(format!("Unknown argument: {other}\n\n{}", usage())),
        }
    }

    let command = command.ok_or_else(usage)?;
    if car.is_some() && track.is_some() {
        return Err("Cannot specify both --car and --track".into());
    }
    if paint_index != 0 && (command != "view" || screenshot.is_none() || track.is_some()) {
        return Err("--paint-index requires car view --screenshot".into());
    }
    let game_dir = game_dir.ok_or_else(|| format!("Missing --game-dir\n\n{}", usage()))?;
    let (scene, title) = match (car, track) {
        (Some(c), None) => {
            let files = read_game_files(&game_dir, &c)?;
            (load_car(&files, &c)?, c)
        }
        (None, Some(t)) => {
            let files = read_track_files(&game_dir, &t)?;
            (load_track(&files, &t)?, format!("Track {t}"))
        }
        (None, None) => {
            let default_car = String::from("356a");
            let files = read_game_files(&game_dir, &default_car)?;
            (load_car(&files, &default_car)?, default_car)
        }
        _ => unreachable!(),
    };

    match command.as_str() {
        "inspect" => {
            println!("{}", summarize(&scene));
            Ok(())
        }
        "view" => {
            if let Some(path) = screenshot {
                let center = match (center_x, center_y, center_z) {
                    (Some(x), Some(y), Some(z)) => Some([x, y, z]),
                    _ => None,
                };
                pollster::block_on(render_screenshot(
                    &scene,
                    width,
                    height,
                    yaw,
                    pitch,
                    distance,
                    center,
                    paint_index,
                    &path,
                ))
            } else {
                let center = match (center_x, center_y, center_z) {
                    (Some(x), Some(y), Some(z)) => Some([x, y, z]),
                    _ => None,
                };
                run_window(scene, &title, yaw, pitch, distance, center)
            }
        }
        _ => unreachable!(),
    }
}

fn usage() -> String {
    "Usage:\n  porsche-viewer inspect --game-dir <path> (--car <name> | --track <name>)\n  porsche-viewer view --game-dir <path> (--car <name> | --track <name>) [--screenshot out.png] [--paint-index 0..5 (car screenshot only)] [--yaw radians] [--pitch radians] [--width px] [--height px]".into()
}

fn next_value(iter: &mut impl Iterator<Item = String>, name: &str) -> Result<String, String> {
    iter.next()
        .ok_or_else(|| format!("{name} requires a value"))
}

#[cfg(test)]
mod gpu_diagnostics {
    use super::*;

    #[test]
    #[ignore = "requires a Vulkan adapter; no game resources"]
    fn paint_mask_gpu() {
        use nfs_assets::{AlphaMode, Material, Mesh, Texture, Vertex};
        let vertices = [
            ([-1., -1., 0.], [0., 1.]),
            ([1., -1., 0.], [1., 1.]),
            ([1., 1., 0.], [1., 0.]),
            ([-1., 1., 0.], [0., 0.]),
        ]
        .map(|(position, uv)| Vertex {
            position,
            normal: [0., 0., 1.],
            uv,
        })
        .to_vec();
        let scene = Scene {
            meshes: vec![Mesh {
                name: "paint regression".into(),
                vertices,
                indices: vec![0, 1, 2, 0, 2, 3],
                material: 0,
            }],
            textures: vec![Texture {
                name: "lamp / paint / cutout".into(),
                width: 12,
                height: 1,
                rgba: (0..12)
                    .flat_map(|x| {
                        [
                            220,
                            220,
                            220,
                            if x < 4 {
                                255
                            } else if x < 8 {
                                204
                            } else {
                                0
                            },
                        ]
                    })
                    .collect(),
            }],
            materials: vec![Material {
                name: "exterior".into(),
                texture: Some(0),
                base_color: [1.; 4],
                paintable: true,
                alpha_mode: AlphaMode::Mask,
                alpha_cutoff: 0.,
                double_sided: true,
                depth_bias: 0,
            }],
            bounds: [[-1., -1., 0.], [1., 1., 0.]],
            diagnostics: vec![],
            ..Default::default()
        };
        let white = pollster::block_on(render_pixels(
            &scene,
            256,
            256,
            Some(0.),
            Some(0.),
            None,
            None,
            0,
        ))
        .unwrap();
        let red = pollster::block_on(render_pixels(
            &scene,
            256,
            256,
            Some(0.),
            Some(0.),
            None,
            None,
            1,
        ))
        .unwrap();
        let pixel = |data: &[u8], x: usize, y: usize| -> [u8; 4] {
            data[(y * 256 + x) * 4..(y * 256 + x + 1) * 4]
                .try_into()
                .unwrap()
        };
        assert_eq!(
            pixel(&white, 75, 128),
            pixel(&red, 75, 128),
            "lamp must not change"
        );
        assert_ne!(
            pixel(&white, 75, 128),
            pixel(&white, 0, 0),
            "lamp must be visible"
        );
        assert!(
            pixel(&red, 128, 128)[1] < pixel(&white, 128, 128)[1],
            "body must change"
        );
        assert_eq!(
            pixel(&red, 180, 128),
            pixel(&red, 0, 0),
            "alpha zero must cut out"
        );
        assert_eq!(
            pixel(&red, 128, 128)[3],
            255,
            "paint alpha must not become opacity"
        );
    }

    #[test]
    #[ignore = "requires a Vulkan adapter; no game resources"]
    fn coplanar_material_bias_gpu() {
        use nfs_assets::{AlphaMode, Material, Mesh, Texture, Vertex};
        let vertices = [
            ([-1., -1., 0.], [0., 1.]),
            ([1., -1., 0.], [1., 1.]),
            ([1., 1., 0.], [1., 0.]),
            ([-1., 1., 0.], [0., 0.]),
        ]
        .map(|(position, uv)| Vertex {
            position,
            normal: [0., 0., 1.],
            uv,
        })
        .to_vec();
        let mesh = |material| Mesh {
            name: "coplanar".into(),
            vertices: vertices.clone(),
            indices: vec![0, 1, 2, 0, 2, 3],
            material,
        };
        let scene = Scene {
            // Deliberately put the detail first: article order must not win.
            meshes: vec![mesh(1), mesh(0)],
            textures: vec![
                Texture {
                    name: "paint".into(),
                    width: 1,
                    height: 1,
                    rgba: vec![220, 220, 220, 204],
                },
                Texture {
                    name: "lamp".into(),
                    width: 1,
                    height: 1,
                    rgba: vec![220, 220, 220, 255],
                },
            ],
            materials: (0..2)
                .map(|i| Material {
                    name: format!("mt{i}"),
                    texture: Some(i),
                    base_color: [1.; 4],
                    paintable: true,
                    alpha_mode: AlphaMode::Mask,
                    alpha_cutoff: 0.,
                    double_sided: true,
                    depth_bias: if i == 1 { -3 } else { 0 },
                })
                .collect(),
            bounds: [[-1., -1., 0.], [1., 1., 0.]],
            diagnostics: vec![],
            ..Default::default()
        };
        let actual = pollster::block_on(render_pixels(
            &scene,
            64,
            64,
            Some(0.),
            Some(0.),
            None,
            None,
            1,
        ))
        .unwrap();
        let mut lamp = scene.clone();
        lamp.meshes.retain(|mesh| mesh.material == 1);
        let expected = pollster::block_on(render_pixels(
            &lamp,
            64,
            64,
            Some(0.),
            Some(0.),
            None,
            None,
            1,
        ))
        .unwrap();
        assert_eq!(
            actual, expected,
            "detail must cover coplanar body despite article order"
        );
    }

    #[test]
    #[ignore = "requires local game and Vulkan; writes layer diagnostics under local/builds"]
    fn headlight_layers() {
        let root = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../../..");
        let scene = load_car(
            &read_game_files(&root.join("local/game"), "356b").unwrap(),
            "356b",
        )
        .unwrap();
        let output = root.join("local/builds/001-car-viewer/validation/layers");
        fs::create_dir_all(&output).unwrap();
        for (label, include_body) in [
            ("lights", false),
            ("lights-body", true),
            ("all-material-order", true),
        ] {
            let mut layer = scene.clone();
            if label == "all-material-order" {
                layer.meshes.sort_by_key(|mesh| mesh.material);
            } else {
                layer.meshes.retain(|mesh| {
                    mesh.name.starts_with("Light1#")
                        || (include_body && mesh.name.starts_with("Body#"))
                });
            }
            pollster::block_on(render_screenshot(
                &layer,
                960,
                600,
                None,
                None,
                None,
                None,
                1,
                &output.join(format!("{label}.png")),
            ))
            .unwrap();
        }
    }
}

fn parse_f32(iter: &mut impl Iterator<Item = String>, name: &str) -> Result<f32, String> {
    next_value(iter, name)?
        .parse()
        .map_err(|_| format!("{name} requires a number"))
}

fn parse_u32(iter: &mut impl Iterator<Item = String>, name: &str) -> Result<u32, String> {
    let value: u32 = next_value(iter, name)?
        .parse()
        .map_err(|_| format!("{name} requires a positive integer"))?;
    NonZeroU32::new(value)
        .map(NonZeroU32::get)
        .ok_or_else(|| format!("{name} must be greater than zero"))
}

fn read_game_files(root: &Path, car: &str) -> Result<AssetFiles, String> {
    if !root.is_dir() {
        return Err(format!("Game directory not found: {}", root.display()));
    }
    let mut files = BTreeMap::new();
    read_dir_recursive(root, root, car, &mut files)?;
    Ok(files)
}

fn read_dir_recursive(
    root: &Path,
    dir: &Path,
    car: &str,
    files: &mut AssetFiles,
) -> Result<(), String> {
    for entry in fs::read_dir(dir).map_err(|e| format!("{}: {e}", dir.display()))? {
        let entry = entry.map_err(|e| format!("{}: {e}", dir.display()))?;
        let path = entry.path();
        let kind = entry
            .file_type()
            .map_err(|e| format!("{}: {e}", path.display()))?;
        if kind.is_dir() {
            read_dir_recursive(root, &path, car, files)?;
        } else if kind.is_file() {
            let extension = path
                .extension()
                .and_then(|extension| extension.to_str())
                .map(str::to_ascii_lowercase);
            let stem = path
                .file_stem()
                .and_then(|stem| stem.to_str())
                .unwrap_or_default();
            let selected = extension.as_deref() == Some("fsh")
                || (matches!(extension.as_deref(), Some("crp") | Some("tpg"))
                    && stem.eq_ignore_ascii_case(car));
            if !selected {
                continue;
            }
            let key = path
                .strip_prefix(root)
                .unwrap_or(&path)
                .to_string_lossy()
                .replace('\\', "/")
                .to_ascii_lowercase();
            let data = fs::read(&path).map_err(|e| format!("{}: {e}", path.display()))?;
            files.insert(key, data);
        }
    }
    Ok(())
}

fn read_track_files(root: &Path, track: &str) -> Result<AssetFiles, String> {
    if !root.is_dir() {
        return Err(format!("Game directory not found: {}", root.display()));
    }
    let mut files = BTreeMap::new();
    read_track_dir_recursive(root, root, track, &mut files)?;
    Ok(files)
}

fn read_track_dir_recursive(
    root: &Path,
    dir: &Path,
    track: &str,
    files: &mut AssetFiles,
) -> Result<(), String> {
    for entry in fs::read_dir(dir).map_err(|e| format!("{}: {e}", dir.display()))? {
        let entry = entry.map_err(|e| format!("{}: {e}", dir.display()))?;
        let path = entry.path();
        let kind = entry
            .file_type()
            .map_err(|e| format!("{}: {e}", path.display()))?;
        if kind.is_dir() {
            // Include Sky/ directory for sky textures
            read_track_dir_recursive(root, &path, track, files)?;
        } else if kind.is_file() {
            let extension = path
                .extension()
                .and_then(|extension| extension.to_str())
                .map(str::to_ascii_lowercase);
            let stem = path
                .file_stem()
                .and_then(|stem| stem.to_str())
                .unwrap_or_default();

            // Check if file is inside a Sky/ directory
            let in_sky_dir = path
                .parent()
                .and_then(|p| p.file_name())
                .and_then(|n| n.to_str())
                .map(|n| n.eq_ignore_ascii_case("sky"))
                .unwrap_or(false);

            let selected = if in_sky_dir {
                // Inside Sky/: load .fsh files matching track name
                extension.as_deref() == Some("fsh") && stem.eq_ignore_ascii_case(track)
            } else if extension.as_deref() == Some("scn") {
                // .scn files use <track>_st<N>.scn naming — match by prefix
                stem.to_ascii_lowercase()
                    .starts_with(&track.to_ascii_lowercase())
            } else {
                // Original: crp, fsh, env, edg, map, jnc with exact stem match
                matches!(
                    extension.as_deref(),
                    Some("crp")
                        | Some("fsh")
                        | Some("env")
                        | Some("edg")
                        | Some("map")
                        | Some("jnc")
                ) && stem.eq_ignore_ascii_case(track)
            };
            if !selected {
                continue;
            }
            let key = path
                .strip_prefix(root)
                .unwrap_or(&path)
                .to_string_lossy()
                .replace('\\', "/")
                .to_ascii_lowercase();
            let data = fs::read(&path).map_err(|e| format!("{}: {e}", path.display()))?;
            files.insert(key, data);
        }
    }
    Ok(())
}

fn run_window(
    scene: Scene,
    title: &str,
    yaw: Option<f32>,
    pitch: Option<f32>,
    distance: Option<f32>,
    center: Option<[f32; 3]>,
) -> Result<(), String> {
    let event_loop = EventLoop::new().map_err(|e| format!("Event loop unavailable: {e}"))?;
    let mut app = App::new(scene, title, yaw, pitch, distance, center);
    event_loop
        .run_app(&mut app)
        .map_err(|e| format!("Window loop failed: {e}"))
}

struct App {
    scene: Option<Scene>,
    title: String,
    window: Option<Arc<Window>>,
    surface: Option<wgpu::Surface<'static>>,
    config: Option<wgpu::SurfaceConfiguration>,
    renderer: Option<Renderer>,
    dragging_orbit: bool,
    dragging_pan: bool,
    cursor: Option<(f64, f64)>,
    shift_pressed: bool,
    initial_yaw: Option<f32>,
    initial_pitch: Option<f32>,
    initial_distance: Option<f32>,
    initial_center: Option<[f32; 3]>,
}

impl App {
    fn new(
        scene: Scene,
        title: &str,
        yaw: Option<f32>,
        pitch: Option<f32>,
        distance: Option<f32>,
        center: Option<[f32; 3]>,
    ) -> Self {
        Self {
            scene: Some(scene),
            title: title.to_string(),
            window: None,
            surface: None,
            config: None,
            renderer: None,
            dragging_orbit: false,
            dragging_pan: false,
            cursor: None,
            shift_pressed: false,
            initial_yaw: yaw,
            initial_pitch: pitch,
            initial_distance: distance,
            initial_center: center,
        }
    }

    fn initialize(&mut self, event_loop: &ActiveEventLoop) -> Result<(), String> {
        let window = Arc::new(
            event_loop
                .create_window(
                    Window::default_attributes()
                        .with_title(&self.title)
                        .with_inner_size(PhysicalSize::new(1280, 720)),
                )
                .map_err(|e| format!("Window unavailable: {e}"))?,
        );
        let size = window.inner_size();
        let instance = instance();
        let surface = instance
            .create_surface(window.clone())
            .map_err(|e| format!("Surface unavailable: {e}"))?;
        let (adapter, device, queue) = pollster::block_on(request_gpu(&instance, Some(&surface)))?;
        let caps = surface.get_capabilities(&adapter);
        let format = caps
            .formats
            .iter()
            .copied()
            .find(wgpu::TextureFormat::is_srgb)
            .or_else(|| caps.formats.first().copied())
            .ok_or("Surface has no color formats")?;
        let present_mode = caps
            .present_modes
            .iter()
            .copied()
            .find(|mode| *mode == wgpu::PresentMode::Fifo)
            .unwrap_or(caps.present_modes[0]);
        let alpha_mode = caps.alpha_modes[0];
        let config = wgpu::SurfaceConfiguration {
            usage: wgpu::TextureUsages::RENDER_ATTACHMENT,
            format,
            color_space: wgpu::SurfaceColorSpace::Auto,
            width: size.width.max(1),
            height: size.height.max(1),
            present_mode,
            alpha_mode,
            view_formats: vec![],
            desired_maximum_frame_latency: 2,
        };
        surface.configure(&device, &config);
        let mut renderer = Renderer::new(
            device,
            queue,
            format,
            config.width,
            config.height,
            self.scene.as_ref().ok_or("Scene missing")?,
        )?;
        if let Some(yaw) = self.initial_yaw {
            renderer.camera.yaw = yaw;
        }
        if let Some(pitch) = self.initial_pitch {
            renderer.camera.pitch = pitch.clamp(-1.45, 1.45);
        }
        if let Some(distance) = self.initial_distance {
            renderer.camera.distance = distance;
            renderer.camera.initial_distance = distance;
        }
        if let Some(center) = self.initial_center {
            renderer.camera.center = glam::Vec3::from(center);
            renderer.camera.initial_center = renderer.camera.center;
        }

        self.window = Some(window);
        self.surface = Some(surface);
        self.config = Some(config);
        self.renderer = Some(renderer);
        Ok(())
    }

    fn resize(&mut self, size: PhysicalSize<u32>) {
        if size.width == 0 || size.height == 0 {
            if let Some(renderer) = &mut self.renderer {
                renderer.resize(0, 0);
            }
            return;
        }
        let (Some(surface), Some(config), Some(renderer)) =
            (&self.surface, &mut self.config, &mut self.renderer)
        else {
            return;
        };
        config.width = size.width;
        config.height = size.height;
        surface.configure(&renderer.device, config);
        renderer.resize(size.width, size.height);
    }

    fn draw(&mut self) -> Result<(), String> {
        let (Some(surface), Some(renderer)) = (&self.surface, &mut self.renderer) else {
            return Ok(());
        };
        let frame = match surface.get_current_texture() {
            wgpu::CurrentSurfaceTexture::Success(frame)
            | wgpu::CurrentSurfaceTexture::Suboptimal(frame) => frame,
            wgpu::CurrentSurfaceTexture::Lost | wgpu::CurrentSurfaceTexture::Outdated => {
                if let (Some(config), Some(renderer)) = (&self.config, &self.renderer) {
                    surface.configure(&renderer.device, config);
                }
                return Ok(());
            }
            wgpu::CurrentSurfaceTexture::Timeout | wgpu::CurrentSurfaceTexture::Occluded => {
                return Ok(());
            }
            wgpu::CurrentSurfaceTexture::Validation => {
                return Err("Surface frame validation failed".into());
            }
        };
        let view = frame.texture.create_view(&Default::default());
        renderer.render(&view);
        renderer.queue.present(frame);
        Ok(())
    }
}

impl ApplicationHandler for App {
    fn resumed(&mut self, event_loop: &ActiveEventLoop) {
        if self.window.is_none() {
            let res = self.initialize(event_loop);
            if let Err(error) = res {
                eprintln!("{error}");
                event_loop.exit();
            }
        }
    }

    fn window_event(&mut self, event_loop: &ActiveEventLoop, _: WindowId, event: WindowEvent) {
        match event {
            WindowEvent::CloseRequested => event_loop.exit(),
            WindowEvent::Resized(size) => self.resize(size),
            WindowEvent::ScaleFactorChanged { .. } => {
                if let Some(window) = &self.window {
                    self.resize(window.inner_size());
                }
            }
            WindowEvent::RedrawRequested => {
                if let Err(error) = self.draw() {
                    eprintln!("{error}");
                    event_loop.exit();
                }
            }
            WindowEvent::ModifiersChanged(modifiers) => {
                self.shift_pressed = modifiers.state().shift_key();
            }
            WindowEvent::MouseInput { state, button, .. } => {
                let pressed = state == ElementState::Pressed;
                match button {
                    MouseButton::Left => {
                        if self.shift_pressed {
                            self.dragging_pan = pressed;
                            self.dragging_orbit = false;
                        } else {
                            self.dragging_orbit = pressed;
                            self.dragging_pan = false;
                        }
                    }
                    MouseButton::Right | MouseButton::Middle => {
                        self.dragging_pan = pressed;
                        self.dragging_orbit = false;
                    }
                    _ => {}
                }
                if !self.dragging_orbit && !self.dragging_pan {
                    self.cursor = None;
                }
            }
            WindowEvent::CursorLeft { .. } => {
                if !self.dragging_orbit && !self.dragging_pan {
                    self.cursor = None;
                }
            }
            WindowEvent::CursorMoved { position, .. } => {
                if let (Some((x, y)), Some(renderer)) = (self.cursor, &mut self.renderer) {
                    let dx = (position.x - x) as f32;
                    let dy = (position.y - y) as f32;
                    if self.dragging_orbit {
                        renderer.camera.orbit(dx, dy);
                        if let Some(window) = &self.window {
                            window.request_redraw();
                        }
                    } else if self.dragging_pan {
                        renderer.camera.pan(dx, dy);
                        if let Some(window) = &self.window {
                            window.request_redraw();
                        }
                    }
                }
                self.cursor = Some((position.x, position.y));
            }
            WindowEvent::MouseWheel { delta, .. } => {
                if let Some(renderer) = &mut self.renderer {
                    let amount = match delta {
                        MouseScrollDelta::LineDelta(_, y) => -y * 120.0,
                        MouseScrollDelta::PixelDelta(pos) => -pos.y as f32,
                    };
                    renderer.camera.zoom(amount);
                }
                if let Some(window) = &self.window {
                    window.request_redraw();
                }
            }
            WindowEvent::KeyboardInput { event, .. } if event.state == ElementState::Pressed => {
                let speed_mult = if self.shift_pressed { 3.0 } else { 1.0 };
                match event.physical_key {
                    PhysicalKey::Code(KeyCode::KeyR) => {
                        if let Some(renderer) = &mut self.renderer {
                            if renderer.is_drive_mode() && renderer.has_car() {
                                renderer.reset_car();
                            } else {
                                renderer.camera.reset();
                            }
                        }
                        if let Some(window) = &self.window {
                            window.request_redraw();
                        }
                    }
                    PhysicalKey::Code(KeyCode::KeyC) => {
                        if let Some(renderer) = &mut self.renderer {
                            if renderer.is_drive_mode() && renderer.has_car() {
                                let view = renderer.cycle_car_view();
                                println!("Car view mode: {:?}", view);
                            } else {
                                renderer.cycle_paint_color();
                            }
                        }
                        if let Some(window) = &self.window {
                            window.request_redraw();
                        }
                    }
                    PhysicalKey::Code(KeyCode::KeyP) => {
                        if let Some(renderer) = &mut self.renderer {
                            if renderer.has_car() {
                                renderer.cycle_car_paint();
                            } else {
                                renderer.cycle_paint_color();
                            }
                        }
                        if let Some(window) = &self.window {
                            window.request_redraw();
                        }
                    }
                    PhysicalKey::Code(KeyCode::Space) => {
                        if let Some(renderer) = &mut self.renderer
                            && renderer.is_drive_mode()
                            && renderer.has_car()
                        {
                            renderer.update_car(0.04, 0.0, 0.0, true);
                        }
                        if let Some(window) = &self.window {
                            window.request_redraw();
                        }
                    }
                    PhysicalKey::Code(KeyCode::KeyT) => {
                        if let Some(renderer) = &mut self.renderer {
                            let on = renderer.toggle_topology();
                            println!("Topology overlay: {}", if on { "on" } else { "off" });
                        }
                        if let Some(window) = &self.window {
                            window.request_redraw();
                        }
                    }
                    PhysicalKey::Code(KeyCode::KeyF) => {
                        if let Some(renderer) = &mut self.renderer {
                            let drive = renderer.toggle_camera_mode();
                            println!(
                                "Mode: {}",
                                if drive {
                                    if renderer.has_car() {
                                        "Arcade Car Drive"
                                    } else {
                                        "Drive (fly-through)"
                                    }
                                } else {
                                    "Orbit"
                                }
                            );
                        }
                        if let Some(window) = &self.window {
                            window.request_redraw();
                        }
                    }
                    PhysicalKey::Code(KeyCode::KeyW) | PhysicalKey::Code(KeyCode::ArrowUp) => {
                        if let Some(renderer) = &mut self.renderer {
                            if renderer.is_drive_mode() && renderer.has_car() {
                                renderer.update_car(0.04, speed_mult, 0.0, false);
                            } else {
                                renderer.move_ground(speed_mult, 0.0);
                            }
                        }
                        if let (Some(window), Some(renderer)) = (&self.window, &self.renderer) {
                            if renderer.is_drive_mode() && renderer.has_car() {
                                let speed = renderer.get_car_speed_kmh();
                                let gear = renderer.get_car_gear();
                                let g_str = if gear < 0 {
                                    "R".into()
                                } else if gear == 0 {
                                    "N".into()
                                } else {
                                    format!("{gear}")
                                };
                                window.set_title(&format!(
                                    "{} | {:.0} км/ч [{}]",
                                    self.title, speed, g_str
                                ));
                            }
                            window.request_redraw();
                        }
                    }
                    PhysicalKey::Code(KeyCode::KeyS) | PhysicalKey::Code(KeyCode::ArrowDown) => {
                        if let Some(renderer) = &mut self.renderer {
                            if renderer.is_drive_mode() && renderer.has_car() {
                                renderer.update_car(0.04, -speed_mult, 0.0, false);
                            } else {
                                renderer.move_ground(-speed_mult, 0.0);
                            }
                        }
                        if let (Some(window), Some(renderer)) = (&self.window, &self.renderer) {
                            if renderer.is_drive_mode() && renderer.has_car() {
                                let speed = renderer.get_car_speed_kmh();
                                let gear = renderer.get_car_gear();
                                let g_str = if gear < 0 {
                                    "R".into()
                                } else if gear == 0 {
                                    "N".into()
                                } else {
                                    format!("{gear}")
                                };
                                window.set_title(&format!(
                                    "{} | {:.0} км/ч [{}]",
                                    self.title, speed, g_str
                                ));
                            }
                            window.request_redraw();
                        }
                    }
                    PhysicalKey::Code(KeyCode::KeyA) | PhysicalKey::Code(KeyCode::ArrowLeft) => {
                        if let Some(renderer) = &mut self.renderer {
                            if renderer.is_drive_mode() && renderer.has_car() {
                                renderer.update_car(0.04, 0.0, -1.0, false);
                            } else {
                                renderer.move_ground(0.0, -speed_mult);
                            }
                        }
                        if let Some(window) = &self.window {
                            window.request_redraw();
                        }
                    }
                    PhysicalKey::Code(KeyCode::KeyD) | PhysicalKey::Code(KeyCode::ArrowRight) => {
                        if let Some(renderer) = &mut self.renderer {
                            if renderer.is_drive_mode() && renderer.has_car() {
                                renderer.update_car(0.04, 0.0, 1.0, false);
                            } else {
                                renderer.move_ground(0.0, speed_mult);
                            }
                        }
                        if let Some(window) = &self.window {
                            window.request_redraw();
                        }
                    }
                    PhysicalKey::Code(KeyCode::KeyQ)
                    | PhysicalKey::Code(KeyCode::Minus)
                    | PhysicalKey::Code(KeyCode::NumpadSubtract) => {
                        if let Some(renderer) = &mut self.renderer {
                            renderer.camera.zoom(120.0 * speed_mult);
                        }
                        if let Some(window) = &self.window {
                            window.request_redraw();
                        }
                    }
                    PhysicalKey::Code(KeyCode::KeyE)
                    | PhysicalKey::Code(KeyCode::Equal)
                    | PhysicalKey::Code(KeyCode::NumpadAdd) => {
                        if let Some(renderer) = &mut self.renderer {
                            renderer.camera.zoom(-120.0 * speed_mult);
                        }
                        if let Some(window) = &self.window {
                            window.request_redraw();
                        }
                    }
                    _ => {}
                }
            }
            _ => {}
        }
    }

    fn about_to_wait(&mut self, _: &ActiveEventLoop) {
        if let Some(window) = &self.window {
            window.request_redraw();
        }
    }
}

#[allow(clippy::too_many_arguments)]
async fn render_screenshot(
    scene: &Scene,
    width: u32,
    height: u32,
    yaw: Option<f32>,
    pitch: Option<f32>,
    distance: Option<f32>,
    center: Option<[f32; 3]>,
    paint_index: u32,
    output: &Path,
) -> Result<(), String> {
    let pixels = render_pixels(
        scene,
        width,
        height,
        yaw,
        pitch,
        distance,
        center,
        paint_index,
    )
    .await?;
    let file = fs::File::create(output).map_err(|e| format!("{}: {e}", output.display()))?;
    let writer = BufWriter::new(file);
    let mut encoder = png::Encoder::new(writer, width, height);
    encoder.set_color(png::ColorType::Rgba);
    encoder.set_depth(png::BitDepth::Eight);
    encoder
        .write_header()
        .map_err(|e| format!("PNG header failed: {e}"))?
        .write_image_data(&pixels)
        .map_err(|e| format!("PNG write failed: {e}"))?;
    Ok(())
}

#[allow(clippy::too_many_arguments)]
async fn render_pixels(
    scene: &Scene,
    width: u32,
    height: u32,
    yaw: Option<f32>,
    pitch: Option<f32>,
    distance: Option<f32>,
    center: Option<[f32; 3]>,
    paint_index: u32,
) -> Result<Vec<u8>, String> {
    let instance = instance();
    let (_, device, queue) = request_gpu(&instance, None).await?;
    let format = wgpu::TextureFormat::Rgba8UnormSrgb;
    let mut renderer = Renderer::new(device, queue, format, width, height, scene)?;
    for _ in 0..paint_index {
        renderer.cycle_paint_color();
    }
    if let Some(yaw) = yaw {
        renderer.camera.yaw = yaw;
    }
    if let Some(pitch) = pitch {
        renderer.camera.pitch = pitch.clamp(-1.45, 1.45);
    }
    if let Some(distance) = distance {
        renderer.camera.distance = distance;
    }
    if let Some(center) = center {
        renderer.camera.center = glam::Vec3::from(center);
        renderer.camera.radius = distance.unwrap_or(50.0);
    }

    let target = renderer.device.create_texture(&wgpu::TextureDescriptor {
        label: Some("headless screenshot"),
        size: wgpu::Extent3d {
            width,
            height,
            depth_or_array_layers: 1,
        },
        mip_level_count: 1,
        sample_count: 1,
        dimension: wgpu::TextureDimension::D2,
        format,
        usage: wgpu::TextureUsages::RENDER_ATTACHMENT | wgpu::TextureUsages::COPY_SRC,
        view_formats: &[],
    });
    let target_view = target.create_view(&Default::default());
    renderer.render(&target_view);

    let bytes_per_pixel = 4u32;
    let unpadded_bytes_per_row = width * bytes_per_pixel;
    let align = wgpu::COPY_BYTES_PER_ROW_ALIGNMENT;
    let padded_bytes_per_row = unpadded_bytes_per_row.div_ceil(align) * align;
    let buffer_size = u64::from(padded_bytes_per_row) * u64::from(height);
    let buffer = renderer.device.create_buffer(&wgpu::BufferDescriptor {
        label: Some("screenshot readback"),
        size: buffer_size,
        usage: wgpu::BufferUsages::COPY_DST | wgpu::BufferUsages::MAP_READ,
        mapped_at_creation: false,
    });
    let mut encoder = renderer.device.create_command_encoder(&Default::default());
    encoder.copy_texture_to_buffer(
        wgpu::TexelCopyTextureInfo {
            texture: &target,
            mip_level: 0,
            origin: wgpu::Origin3d::ZERO,
            aspect: wgpu::TextureAspect::All,
        },
        wgpu::TexelCopyBufferInfo {
            buffer: &buffer,
            layout: wgpu::TexelCopyBufferLayout {
                offset: 0,
                bytes_per_row: Some(padded_bytes_per_row),
                rows_per_image: Some(height),
            },
        },
        wgpu::Extent3d {
            width,
            height,
            depth_or_array_layers: 1,
        },
    );
    renderer.queue.submit([encoder.finish()]);

    let slice = buffer.slice(..);
    let (sender, receiver) = std::sync::mpsc::channel();
    slice.map_async(wgpu::MapMode::Read, move |result| {
        let _ = sender.send(result);
    });
    renderer
        .device
        .poll(wgpu::PollType::wait_indefinitely())
        .map_err(|e| format!("GPU readback poll failed: {e}"))?;
    receiver
        .recv()
        .map_err(|e| format!("GPU readback failed: {e}"))?
        .map_err(|e| format!("GPU readback map failed: {e}"))?;

    let mapped = slice
        .get_mapped_range()
        .map_err(|e| format!("GPU readback map range failed: {e}"))?;
    let mut pixels = vec![0; (width * height * bytes_per_pixel) as usize];
    for row in 0..height as usize {
        let src = row * padded_bytes_per_row as usize;
        let dst = row * unpadded_bytes_per_row as usize;
        pixels[dst..dst + unpadded_bytes_per_row as usize]
            .copy_from_slice(&mapped[src..src + unpadded_bytes_per_row as usize]);
    }
    drop(mapped);
    buffer.unmap();

    Ok(pixels)
}
