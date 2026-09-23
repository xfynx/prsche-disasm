use bytemuck::{Pod, Zeroable};
use glam::{Mat4, Vec3};
use nfs_assets::{AlphaMode, Scene};
use std::collections::BTreeMap;
use wgpu::util::DeviceExt;

pub fn summarize(scene: &Scene) -> String {
    let vertices: usize = scene.meshes.iter().map(|m| m.vertices.len()).sum();
    let triangles: usize = scene.meshes.iter().map(|m| m.indices.len() / 3).sum();
    format!(
        "{} parts · {vertices} vertices · {triangles} triangles · {} textures · {} materials\nBounds: {:?}\n{}",
        scene.meshes.len(),
        scene.textures.len(),
        scene.materials.len(),
        scene.bounds,
        scene.diagnostics.join("\n")
    )
}

pub fn instance() -> wgpu::Instance {
    let backends = if cfg!(target_arch = "wasm32") {
        wgpu::Backends::BROWSER_WEBGPU
    } else if cfg!(target_os = "macos") {
        wgpu::Backends::METAL
    } else {
        wgpu::Backends::VULKAN
    };
    let mut descriptor = wgpu::InstanceDescriptor::new_without_display_handle();
    descriptor.backends = backends;
    wgpu::Instance::new(descriptor)
}

pub async fn request_gpu(
    instance: &wgpu::Instance,
    surface: Option<&wgpu::Surface<'_>>,
) -> Result<(wgpu::Adapter, wgpu::Device, wgpu::Queue), String> {
    let adapter = instance
        .request_adapter(&wgpu::RequestAdapterOptions {
            power_preference: wgpu::PowerPreference::HighPerformance,
            compatible_surface: surface,
            force_fallback_adapter: false,
            apply_limit_buckets: false,
        })
        .await
        .map_err(|e| format!("Graphics adapter unavailable: {e}"))?;
    let (device, queue) = adapter
        .request_device(&wgpu::DeviceDescriptor {
            label: Some("Porsche viewer"),
            ..Default::default()
        })
        .await
        .map_err(|e| format!("Graphics device unavailable: {e}"))?;
    Ok((adapter, device, queue))
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum CameraMode {
    Orbit,
    Drive,
}

pub struct Camera {
    pub mode: CameraMode,
    pub yaw: f32,
    pub pitch: f32,
    pub distance: f32,
    pub center: Vec3,
    pub initial_center: Vec3,
    pub initial_distance: f32,
    pub radius: f32,
    pub drive_pos: Vec3,
    pub drive_target: Vec3,
    pub drive_height: f32,
    pub drive_fov: f32,
}

impl Camera {
    pub fn new(bounds: [[f32; 3]; 2]) -> Self {
        let min = Vec3::from(bounds[0]);
        let max = Vec3::from(bounds[1]);
        let radius = ((max - min).length() * 0.5).max(0.1);
        let center = (max + min) * 0.5;
        let distance = radius * 2.8;
        let mut camera = Self {
            mode: CameraMode::Orbit,
            center,
            initial_center: center,
            initial_distance: distance,
            radius,
            yaw: 0.0,
            pitch: 0.0,
            distance: 0.0,
            drive_pos: center,
            drive_target: center + Vec3::new(0.0, 0.0, -10.0),
            drive_height: 1.6,
            drive_fov: 58.0,
        };
        camera.reset();
        camera
    }
    pub fn reset(&mut self) {
        self.mode = CameraMode::Orbit;
        self.center = self.initial_center;
        self.yaw = 0.75;
        self.pitch = 0.27;
        self.distance = self.initial_distance;
        self.drive_pos = self.initial_center;
        self.drive_target = self.initial_center + Vec3::new(0.0, 0.0, -10.0);
        self.drive_height = 1.6;
        self.drive_fov = 58.0;
    }
    pub fn orbit(&mut self, x: f32, y: f32) {
        match self.mode {
            CameraMode::Orbit => {
                self.yaw -= x * 0.006;
                self.pitch = (self.pitch + y * 0.006).clamp(-1.45, 1.45);
            }
            CameraMode::Drive => {
                self.yaw -= x * 0.004;
                self.pitch = (self.pitch - y * 0.004).clamp(-1.35, 1.35);
            }
        }
    }
    pub fn pan(&mut self, x: f32, y: f32) {
        match self.mode {
            CameraMode::Orbit => {
                let eye = self.eye();
                let forward = (self.center - eye).normalize_or_zero();
                let right = forward.cross(Vec3::Y).normalize_or_zero();
                let up = right.cross(forward).normalize_or_zero();
                let speed = (self.distance * 0.0015).max(0.01);
                self.center += (-right * x + up * y) * speed;
            }
            CameraMode::Drive => {
                let forward_h =
                    Vec3::new(-self.yaw.sin(), 0.0, -self.yaw.cos()).normalize_or_zero();
                let right_h = forward_h.cross(Vec3::Y).normalize_or_zero();
                self.drive_pos += -right_h * x * 0.05 + forward_h * y * 0.05;
            }
        }
    }
    pub fn move_ground(&mut self, forward_amount: f32, right_amount: f32) {
        match self.mode {
            CameraMode::Orbit => {
                let eye = self.eye();
                let forward = (self.center - eye).normalize_or_zero();
                let mut forward_h = Vec3::new(forward.x, 0.0, forward.z).normalize_or_zero();
                if forward_h.length_squared() < 0.001 {
                    forward_h = Vec3::new(-self.yaw.sin(), 0.0, -self.yaw.cos());
                }
                let right_h = forward_h.cross(Vec3::Y).normalize_or_zero();
                let speed = (self.distance * 0.05).clamp(0.5, 50.0);
                self.center += (forward_h * forward_amount + right_h * right_amount) * speed;
            }
            CameraMode::Drive => {
                let forward_h =
                    Vec3::new(-self.yaw.sin(), 0.0, -self.yaw.cos()).normalize_or_zero();
                let right_h = forward_h.cross(Vec3::Y).normalize_or_zero();
                let speed = 25.0;
                self.drive_pos += (forward_h * forward_amount + right_h * right_amount) * speed;
            }
        }
    }
    pub fn zoom(&mut self, delta: f32) {
        match self.mode {
            CameraMode::Orbit => {
                let min_distance = (self.radius * 0.001).clamp(0.2, 1.0);
                let max_distance = (self.radius * 20.0).max(5000.0);
                self.distance =
                    (self.distance * (delta * 0.001).exp()).clamp(min_distance, max_distance);
            }
            CameraMode::Drive => {
                self.drive_height = (self.drive_height + delta * 0.005).clamp(0.5, 30.0);
            }
        }
    }
    pub fn eye(&self) -> Vec3 {
        match self.mode {
            CameraMode::Orbit => {
                self.center
                    + self.distance
                        * Vec3::new(
                            self.yaw.sin() * self.pitch.cos(),
                            self.pitch.sin(),
                            self.yaw.cos() * self.pitch.cos(),
                        )
            }
            CameraMode::Drive => self.drive_pos,
        }
    }
    pub fn target(&self) -> Vec3 {
        match self.mode {
            CameraMode::Orbit => self.center,
            CameraMode::Drive => self.drive_target,
        }
    }
    fn view_projection(&self, width: u32, height: u32) -> Mat4 {
        let (fov, near, far) = match self.mode {
            CameraMode::Orbit => (
                45.0_f32.to_radians(),
                (self.distance * 0.05).clamp(0.05, 1.0),
                (self.radius * 20.0).max(10_000.0),
            ),
            CameraMode::Drive => (
                self.drive_fov.to_radians(),
                0.1_f32,
                (self.radius * 20.0).max(10_000.0),
            ),
        };
        let projection = Mat4::perspective_rh(fov, width as f32 / height.max(1) as f32, near, far);
        let eye = self.eye();
        let target = self.target();
        projection * Mat4::look_at_rh(eye, target, Vec3::Y)
    }
    fn uniform(&self, width: u32, height: u32) -> CameraUniform {
        let eye = self.eye();
        CameraUniform {
            matrix: self.view_projection(width, height).to_cols_array_2d(),
            eye: [eye.x, eye.y, eye.z, 1.0],
            model: Mat4::IDENTITY.to_cols_array_2d(),
        }
    }
}

#[repr(C)]
#[derive(Clone, Copy, Pod, Zeroable)]
struct CameraUniform {
    matrix: [[f32; 4]; 4],
    eye: [f32; 4],
    model: [[f32; 4]; 4],
}
#[repr(C)]
#[derive(Clone, Copy, Pod, Zeroable)]
struct GpuVertex {
    position: [f32; 3],
    normal: [f32; 3],
    uv: [f32; 2],
}
struct GpuMesh {
    vertex: wgpu::Buffer,
    index: wgpu::Buffer,
    count: u32,
    material: usize,
    center: Vec3,
}
struct GpuMaterial {
    group: wgpu::BindGroup,
    color_buffer: wgpu::Buffer,
    paintable: bool,
    alpha_mode: AlphaMode,
    alpha_cutoff: f32,
    double_sided: bool,
    depth_bias: i32,
}

/// A prop instance draw call: model matrix + range of mesh indices to draw.
struct PropDraw {
    model: Mat4,
    mesh_range: std::ops::Range<usize>,
}

/// Sky dome rendering state.
struct SkyState {
    pipeline: wgpu::RenderPipeline,
    vertex_buffer: wgpu::Buffer,
    index_buffer: wgpu::Buffer,
    index_count: u32,
    camera_buffer: wgpu::Buffer,
    camera_group: wgpu::BindGroup,
    texture_group: wgpu::BindGroup,
}

#[repr(C)]
#[derive(Clone, Copy, Pod, Zeroable)]
struct LineVertex {
    position: [f32; 3],
    color: [f32; 4],
}

pub struct TopologyRenderer {
    pipeline: wgpu::RenderPipeline,
    vertex_buffer: wgpu::Buffer,
    pub vertex_count: u32,
}

struct CarRenderState {
    meshes: Vec<GpuMesh>,
    materials: Vec<GpuMaterial>,
}

pub struct Renderer {
    pub device: wgpu::Device,
    pub queue: wgpu::Queue,
    pub camera: Camera,
    pub width: u32,
    pub height: u32,
    camera_buffer: wgpu::Buffer,
    camera_group: wgpu::BindGroup,
    pipelines: BTreeMap<(bool, bool, i32), wgpu::RenderPipeline>,
    meshes: Vec<GpuMesh>,
    static_mesh_count: usize,
    materials: Vec<GpuMaterial>,
    paint_color: usize,
    depth: wgpu::TextureView,
    prop_draws: Vec<PropDraw>,
    sky: Option<SkyState>,
    pub topology: Option<TopologyRenderer>,
    pub show_topology: bool,
    pub road_edges: Vec<nfs_assets::TopologyEdge>,
    pub road_surface: Option<nfs_assets::RoadSurface>,
    pub car: Option<crate::arcade::ArcadeCar>,
    pub sim_car: Option<nfs_assets::physics::VehicleSimulation>,
    pub sim_telemetry: Option<nfs_assets::physics::VehicleTelemetry>,
    pub sim_mode: bool,
    car_render: Option<CarRenderState>,
}

impl Renderer {
    pub fn new(
        device: wgpu::Device,
        queue: wgpu::Queue,
        format: wgpu::TextureFormat,
        width: u32,
        height: u32,
        scene: &Scene,
    ) -> Result<Self, String> {
        if scene.meshes.is_empty() || scene.materials.is_empty() {
            return Err("Scene has no geometry or materials".into());
        }
        let camera = Camera::new(scene.bounds);
        let camera_buffer = device.create_buffer_init(&wgpu::util::BufferInitDescriptor {
            label: Some("camera"),
            contents: bytemuck::bytes_of(&camera.uniform(width, height)),
            usage: wgpu::BufferUsages::UNIFORM | wgpu::BufferUsages::COPY_DST,
        });
        let camera_layout = device.create_bind_group_layout(&wgpu::BindGroupLayoutDescriptor {
            label: Some("camera"),
            entries: &[wgpu::BindGroupLayoutEntry {
                binding: 0,
                visibility: wgpu::ShaderStages::VERTEX_FRAGMENT,
                ty: wgpu::BindingType::Buffer {
                    ty: wgpu::BufferBindingType::Uniform,
                    has_dynamic_offset: false,
                    min_binding_size: None,
                },
                count: None,
            }],
        });
        let camera_group = device.create_bind_group(&wgpu::BindGroupDescriptor {
            label: Some("camera"),
            layout: &camera_layout,
            entries: &[wgpu::BindGroupEntry {
                binding: 0,
                resource: camera_buffer.as_entire_binding(),
            }],
        });
        let material_layout = device.create_bind_group_layout(&wgpu::BindGroupLayoutDescriptor {
            label: Some("material"),
            entries: &[
                wgpu::BindGroupLayoutEntry {
                    binding: 0,
                    visibility: wgpu::ShaderStages::FRAGMENT,
                    ty: wgpu::BindingType::Texture {
                        sample_type: wgpu::TextureSampleType::Float { filterable: true },
                        view_dimension: wgpu::TextureViewDimension::D2,
                        multisampled: false,
                    },
                    count: None,
                },
                wgpu::BindGroupLayoutEntry {
                    binding: 1,
                    visibility: wgpu::ShaderStages::FRAGMENT,
                    ty: wgpu::BindingType::Sampler(wgpu::SamplerBindingType::Filtering),
                    count: None,
                },
                wgpu::BindGroupLayoutEntry {
                    binding: 2,
                    visibility: wgpu::ShaderStages::FRAGMENT,
                    ty: wgpu::BindingType::Buffer {
                        ty: wgpu::BufferBindingType::Uniform,
                        has_dynamic_offset: false,
                        min_binding_size: None,
                    },
                    count: None,
                },
            ],
        });
        let sampler = device.create_sampler(&wgpu::SamplerDescriptor {
            label: Some("texture sampler"),
            address_mode_u: wgpu::AddressMode::Repeat,
            address_mode_v: wgpu::AddressMode::Repeat,
            mag_filter: wgpu::FilterMode::Linear,
            min_filter: wgpu::FilterMode::Linear,
            ..Default::default()
        });
        let mut texture_views = Vec::new();
        for texture in &scene.textures {
            if texture.width == 0
                || texture.height == 0
                || texture.width > device.limits().max_texture_dimension_2d
                || texture.height > device.limits().max_texture_dimension_2d
                || u64::from(texture.width) * u64::from(texture.height) * 4
                    != texture.rgba.len() as u64
            {
                return Err(format!("Invalid texture dimensions/data: {}", texture.name));
            }
            texture_views.push(upload_texture(
                &device,
                &queue,
                texture.width,
                texture.height,
                &texture.rgba,
            ));
        }
        let white = upload_texture(&device, &queue, 1, 1, &[255; 4]);
        let mut materials = Vec::new();
        for material in &scene.materials {
            let view = match material.texture {
                Some(i) => texture_views
                    .get(i)
                    .ok_or("Invalid material texture index")?,
                None => &white,
            };
            let material_uniform = [
                material.base_color[0],
                material.base_color[1],
                material.base_color[2],
                material.base_color[3],
                alpha_mode_code(material.alpha_mode),
                material.alpha_cutoff,
                if material.paintable { 1.0 } else { 0.0 },
                0.0,
            ];
            let color = device.create_buffer_init(&wgpu::util::BufferInitDescriptor {
                label: Some(&material.name),
                contents: bytemuck::cast_slice(&material_uniform),
                usage: wgpu::BufferUsages::UNIFORM | wgpu::BufferUsages::COPY_DST,
            });
            let group = device.create_bind_group(&wgpu::BindGroupDescriptor {
                label: Some(&material.name),
                layout: &material_layout,
                entries: &[
                    wgpu::BindGroupEntry {
                        binding: 0,
                        resource: wgpu::BindingResource::TextureView(view),
                    },
                    wgpu::BindGroupEntry {
                        binding: 1,
                        resource: wgpu::BindingResource::Sampler(&sampler),
                    },
                    wgpu::BindGroupEntry {
                        binding: 2,
                        resource: color.as_entire_binding(),
                    },
                ],
            });
            materials.push(GpuMaterial {
                group,
                color_buffer: color,
                paintable: material.paintable,
                alpha_mode: material.alpha_mode,
                alpha_cutoff: material.alpha_cutoff,
                double_sided: material.double_sided,
                depth_bias: material.depth_bias,
            });
        }
        let shader = device.create_shader_module(wgpu::ShaderModuleDescriptor {
            label: Some("car shader"),
            source: wgpu::ShaderSource::Wgsl(include_str!("car.wgsl").into()),
        });
        let layout = device.create_pipeline_layout(&wgpu::PipelineLayoutDescriptor {
            label: Some("car"),
            bind_group_layouts: &[Some(&camera_layout), Some(&material_layout)],
            immediate_size: 0,
        });
        let mut pipelines = BTreeMap::new();
        let make_pipeline = |blend: bool, double_sided: bool, depth_bias: i32| {
            device.create_render_pipeline(&wgpu::RenderPipelineDescriptor {
                label: Some("car"), layout: Some(&layout),
                vertex: wgpu::VertexState { module: &shader, entry_point: Some("vs_main"), compilation_options: Default::default(), buffers: &[Some(wgpu::VertexBufferLayout { array_stride: std::mem::size_of::<GpuVertex>() as u64, step_mode: wgpu::VertexStepMode::Vertex, attributes: &wgpu::vertex_attr_array![0 => Float32x3, 1 => Float32x3, 2 => Float32x2] })] },
                fragment: Some(wgpu::FragmentState { module: &shader, entry_point: Some("fs_main"), compilation_options: Default::default(), targets: &[Some(wgpu::ColorTargetState { format, blend: if blend { Some(wgpu::BlendState::ALPHA_BLENDING) } else { None }, write_mask: wgpu::ColorWrites::ALL })] }),
                primitive: wgpu::PrimitiveState { cull_mode: if double_sided { None } else { Some(wgpu::Face::Back) }, ..Default::default() },
                depth_stencil: Some(wgpu::DepthStencilState { format: wgpu::TextureFormat::Depth32Float, depth_write_enabled: Some(!blend), depth_compare: Some(wgpu::CompareFunction::LessEqual), stencil: Default::default(), bias: wgpu::DepthBiasState { constant: depth_bias, ..Default::default() } }),
                multisample: Default::default(), multiview_mask: None, cache: None,
            })
        };
        for material in &scene.materials {
            let blend = material.alpha_mode == AlphaMode::Blend;
            let double_sided = material.double_sided;
            let key = (blend, double_sided, material.depth_bias);
            pipelines
                .entry(key)
                .or_insert_with(|| make_pipeline(blend, double_sided, material.depth_bias));
        }
        pipelines
            .entry((false, false, 0))
            .or_insert_with(|| make_pipeline(false, false, 0));
        pipelines
            .entry((true, false, 0))
            .or_insert_with(|| make_pipeline(true, false, 0));
        let mut meshes = Vec::new();
        for mesh in &scene.meshes {
            if mesh.vertices.is_empty() || mesh.indices.is_empty() {
                continue;
            }
            if mesh.material >= materials.len()
                || mesh
                    .indices
                    .iter()
                    .any(|&i| i as usize >= mesh.vertices.len())
            {
                return Err(format!("Invalid mesh indices: {}", mesh.name));
            }
            let vertices: Vec<GpuVertex> = mesh
                .vertices
                .iter()
                .map(|v| GpuVertex {
                    position: v.position,
                    normal: v.normal,
                    uv: v.uv,
                })
                .collect();
            let center = mesh
                .vertices
                .iter()
                .map(|v| Vec3::from(v.position))
                .sum::<Vec3>()
                / mesh.vertices.len() as f32;
            meshes.push(GpuMesh {
                vertex: device.create_buffer_init(&wgpu::util::BufferInitDescriptor {
                    label: Some(&mesh.name),
                    contents: bytemuck::cast_slice(&vertices),
                    usage: wgpu::BufferUsages::VERTEX,
                }),
                index: device.create_buffer_init(&wgpu::util::BufferInitDescriptor {
                    label: Some(&mesh.name),
                    contents: bytemuck::cast_slice(&mesh.indices),
                    usage: wgpu::BufferUsages::INDEX,
                }),
                count: mesh.indices.len() as u32,
                material: mesh.material,
                center,
            });
        }
        let static_mesh_count = scene
            .prop_articles
            .first()
            .map(|p| p.mesh_range.start)
            .unwrap_or(scene.meshes.len());

        // Build prop instance draw calls
        let prop_draws: Vec<PropDraw> = scene
            .prop_instances
            .iter()
            .map(|inst| {
                let r = &inst.rotation;
                // Build 4x4 model matrix from 3x3 rotation + translation.
                // The .scn rotation is row-major; scene coordinates negate Z.
                let model = Mat4::from_cols_array(&[
                    r[0][0],
                    r[1][0],
                    -r[2][0],
                    0.0,
                    r[0][1],
                    r[1][1],
                    -r[2][1],
                    0.0,
                    -r[0][2],
                    -r[1][2],
                    r[2][2],
                    0.0,
                    inst.position[0],
                    inst.position[1],
                    inst.position[2],
                    1.0,
                ]);
                PropDraw {
                    model,
                    mesh_range: scene.prop_articles[inst.article_index].mesh_range.clone(),
                }
            })
            .collect();

        // Build sky dome
        let sky = scene.sky_texture.as_ref().map(|sky_tex| {
            create_sky_state(
                &device,
                &queue,
                format,
                &camera,
                width,
                height,
                sky_tex.width,
                sky_tex.height,
                &sky_tex.rgba,
            )
        });

        // Build topology line overlay
        let mut topology_renderer = None;
        if let Some(top) = &scene.topology {
            let mut line_vertices = Vec::new();
            for line in &top.boundary_lines {
                if line.points.len() >= 2 {
                    for i in 0..line.points.len() - 1 {
                        line_vertices.push(LineVertex {
                            position: line.points[i],
                            color: line.color,
                        });
                        line_vertices.push(LineVertex {
                            position: line.points[i + 1],
                            color: line.color,
                        });
                    }
                }
            }
            if !line_vertices.is_empty() {
                let vertex_buffer = device.create_buffer_init(&wgpu::util::BufferInitDescriptor {
                    label: Some("topology line vertices"),
                    contents: bytemuck::cast_slice(&line_vertices),
                    usage: wgpu::BufferUsages::VERTEX,
                });
                let line_shader = device.create_shader_module(wgpu::ShaderModuleDescriptor {
                    label: Some("topology line shader"),
                    source: wgpu::ShaderSource::Wgsl(
                        r#"
struct Camera {
    matrix: mat4x4<f32>,
    eye: vec4<f32>,
    model: mat4x4<f32>,
};
@group(0) @binding(0) var<uniform> camera: Camera;

struct VertexInput {
    @location(0) position: vec3<f32>,
    @location(1) color: vec4<f32>,
};

struct VertexOutput {
    @builtin(position) clip_position: vec4<f32>,
    @location(0) color: vec4<f32>,
};

@vertex
fn vs_main(in: VertexInput) -> VertexOutput {
    var out: VertexOutput;
    var world_pos = camera.model * vec4<f32>(in.position, 1.0);
    var clip_pos = camera.matrix * world_pos;
    clip_pos.z = clip_pos.z - 0.0004 * clip_pos.w;
    out.clip_position = clip_pos;
    out.color = in.color;
    return out;
}

@fragment
fn fs_main(in: VertexOutput) -> @location(0) vec4<f32> {
    return in.color;
}
"#
                        .into(),
                    ),
                });
                let line_layout = device.create_pipeline_layout(&wgpu::PipelineLayoutDescriptor {
                    label: Some("topology line layout"),
                    bind_group_layouts: &[Some(&camera_layout)],
                    immediate_size: 0,
                });
                let pipeline = device.create_render_pipeline(&wgpu::RenderPipelineDescriptor {
                    label: Some("topology line pipeline"),
                    layout: Some(&line_layout),
                    vertex: wgpu::VertexState {
                        module: &line_shader,
                        entry_point: Some("vs_main"),
                        compilation_options: Default::default(),
                        buffers: &[Some(wgpu::VertexBufferLayout {
                            array_stride: std::mem::size_of::<LineVertex>() as u64,
                            step_mode: wgpu::VertexStepMode::Vertex,
                            attributes: &wgpu::vertex_attr_array![0 => Float32x3, 1 => Float32x4],
                        })],
                    },
                    fragment: Some(wgpu::FragmentState {
                        module: &line_shader,
                        entry_point: Some("fs_main"),
                        compilation_options: Default::default(),
                        targets: &[Some(wgpu::ColorTargetState {
                            format,
                            blend: Some(wgpu::BlendState::ALPHA_BLENDING),
                            write_mask: wgpu::ColorWrites::ALL,
                        })],
                    }),
                    primitive: wgpu::PrimitiveState {
                        topology: wgpu::PrimitiveTopology::LineList,
                        ..Default::default()
                    },
                    depth_stencil: Some(wgpu::DepthStencilState {
                        format: wgpu::TextureFormat::Depth32Float,
                        depth_write_enabled: Some(false),
                        depth_compare: Some(wgpu::CompareFunction::LessEqual),
                        stencil: Default::default(),
                        bias: Default::default(),
                    }),
                    multisample: Default::default(),
                    multiview_mask: None,
                    cache: None,
                });
                topology_renderer = Some(TopologyRenderer {
                    pipeline,
                    vertex_buffer,
                    vertex_count: line_vertices.len() as u32,
                });
            }
        }

        // Arcade & 6 DOF Simulation car spawn and procedural GPU geometry (for track scenes)
        let mut car = None;
        let mut sim_car = None;
        let mut car_render = None;
        let road_edges: Vec<nfs_assets::TopologyEdge> = scene
            .topology
            .as_ref()
            .map(|t| t.edges.clone())
            .unwrap_or_default();

        if !road_edges.is_empty() {
            let mut spawn_pos = camera.center;
            let mut spawn_yaw = 0.0_f32;

            if let Some(first_edge) = road_edges.first() {
                let p1 = Vec3::from(first_edge.p1);
                let p2 = Vec3::from(first_edge.p2);
                let mid = (p1 + p2) * 0.5;
                let dir = (p2 - p1).normalize_or_zero();
                let perp = Vec3::new(-dir.z, 0.0, dir.x).normalize_or_zero();
                let to_center = camera.center - mid;
                let inward = if perp.dot(to_center) >= 0.0 {
                    perp
                } else {
                    -perp
                };
                spawn_pos = mid + inward * 6.5;
                spawn_pos.y = p1.y;
                if dir.length_squared() > 0.01 {
                    spawn_yaw = (-dir.x).atan2(-dir.z);
                }
            }

            let mut arcade_car = crate::arcade::ArcadeCar::new(spawn_pos, spawn_yaw);
            arcade_car.reset_to_road(&road_edges);
            if let Some(hit) = scene.road_surface.as_ref().and_then(|surface| {
                surface.query(
                    arcade_car.pos.x,
                    arcade_car.pos.z,
                    arcade_car.pos.y,
                    2.0,
                    4.0,
                )
            }) {
                arcade_car.pos.y = hit.height;
            }
            car = Some(arcade_car);

            // Realistic 6 DOF Vehicle Simulation specification
            let sim_spec = nfs_formats::sim::SimCar {
                name: "1997 Boxster 2.5L".to_string(),
                mass_kg: 1252.0,
                wheelbase_m: 2.415,
                gear_count: 5,
                drive_flags: 2,
                reverse_gear: -3.44,
                forward_gears: vec![3.50, 2.12, 1.43, 1.03, 0.79],
                final_drive: 3.89,
                redline_rpm: 6700.0,
                idle_or_step_rpm: 800.0,
                torque_curve: [
                    98.0, 102.0, 130.0, 138.0, 157.0, 157.0, 169.0, 169.0, 173.0, 181.0, 181.0,
                    173.0, 146.0, 110.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                ],
                brake_bias: 0.62,
                drag_coeff: 0.31,
                swaybar_stiffness: 12000.0,
                suspension_stiffness: 28.0,
                front_track_m: 1.465,
                rear_track_m: 1.500,
                damping_compression: 2.5,
                damping_rebound: 3.2,
                tire_grip: 0.90,
                cg_offset_m: [0.0, 0.35, -0.1],
                raw: [0u8; 328],
            };
            let mut vehicle_sim = nfs_assets::physics::VehicleSimulation::from_sim(&sim_spec);
            vehicle_sim.reset(spawn_pos, spawn_yaw);
            sim_car = Some(vehicle_sim);

            let geom = crate::car_mesh::generate_procedural_car();
            let mut car_materials = Vec::new();
            for part in &geom.parts {
                let color_idx = part.material;
                let base_color = match color_idx {
                    crate::car_mesh::MAT_BODY => crate::car_mesh::CAR_COLORS[0],
                    crate::car_mesh::MAT_GLASS => [0.10, 0.14, 0.20, 0.90],
                    crate::car_mesh::MAT_BLACK => [0.08, 0.08, 0.09, 1.0],
                    crate::car_mesh::MAT_RIMS => [0.82, 0.84, 0.86, 1.0],
                    crate::car_mesh::MAT_LIGHTS_FRONT => [1.0, 0.98, 0.85, 1.0],
                    crate::car_mesh::MAT_LIGHTS_REAR => [0.95, 0.06, 0.06, 1.0],
                    _ => [0.8, 0.8, 0.8, 1.0],
                };
                let alpha_mode = if color_idx == crate::car_mesh::MAT_GLASS {
                    AlphaMode::Blend
                } else {
                    AlphaMode::Opaque
                };
                let material_uniform = [
                    base_color[0],
                    base_color[1],
                    base_color[2],
                    base_color[3],
                    alpha_mode_code(alpha_mode),
                    0.0,
                    0.0,
                    0.0,
                ];
                let color_buf = device.create_buffer_init(&wgpu::util::BufferInitDescriptor {
                    label: Some("procedural car color"),
                    contents: bytemuck::cast_slice(&material_uniform),
                    usage: wgpu::BufferUsages::UNIFORM | wgpu::BufferUsages::COPY_DST,
                });
                let group = device.create_bind_group(&wgpu::BindGroupDescriptor {
                    label: Some("procedural car material"),
                    layout: &material_layout,
                    entries: &[
                        wgpu::BindGroupEntry {
                            binding: 0,
                            resource: wgpu::BindingResource::TextureView(&white),
                        },
                        wgpu::BindGroupEntry {
                            binding: 1,
                            resource: wgpu::BindingResource::Sampler(&sampler),
                        },
                        wgpu::BindGroupEntry {
                            binding: 2,
                            resource: color_buf.as_entire_binding(),
                        },
                    ],
                });
                car_materials.push(GpuMaterial {
                    group,
                    color_buffer: color_buf,
                    paintable: color_idx == crate::car_mesh::MAT_BODY,
                    alpha_mode,
                    alpha_cutoff: 0.0,
                    double_sided: false,
                    depth_bias: 0,
                });
            }

            let mut car_meshes = Vec::new();
            for (idx, part) in geom.parts.iter().enumerate() {
                let vertices: Vec<GpuVertex> = part
                    .vertices
                    .iter()
                    .map(|v| GpuVertex {
                        position: v.pos,
                        normal: v.normal,
                        uv: v.uv,
                    })
                    .collect();
                let center = vertices
                    .iter()
                    .map(|v| Vec3::from(v.position))
                    .sum::<Vec3>()
                    / vertices.len() as f32;
                car_meshes.push(GpuMesh {
                    vertex: device.create_buffer_init(&wgpu::util::BufferInitDescriptor {
                        label: Some("procedural car vertex"),
                        contents: bytemuck::cast_slice(&vertices),
                        usage: wgpu::BufferUsages::VERTEX,
                    }),
                    index: device.create_buffer_init(&wgpu::util::BufferInitDescriptor {
                        label: Some("procedural car index"),
                        contents: bytemuck::cast_slice(&part.indices),
                        usage: wgpu::BufferUsages::INDEX,
                    }),
                    count: part.indices.len() as u32,
                    material: idx,
                    center,
                });
            }
            car_render = Some(CarRenderState {
                meshes: car_meshes,
                materials: car_materials,
            });
        }

        let depth = depth_view(&device, width, height);
        Ok(Self {
            device,
            queue,
            camera,
            width,
            height,
            camera_buffer,
            camera_group,
            pipelines,
            meshes,
            static_mesh_count,
            materials,
            paint_color: 0,
            depth,
            prop_draws,
            sky,
            topology: topology_renderer,
            show_topology: false,
            road_surface: scene.road_surface.clone(),
            road_edges,
            car,
            sim_car,
            sim_telemetry: None,
            sim_mode: true,
            car_render,
        })
    }
    pub fn resize(&mut self, width: u32, height: u32) {
        self.width = width;
        self.height = height;
        if width > 0 && height > 0 {
            self.depth = depth_view(&self.device, width, height);
        }
    }
    pub fn cycle_paint_color(&mut self) {
        const COLORS: [[f32; 4]; 6] = [
            [1.0, 1.0, 1.0, 1.0],
            [0.72, 0.05, 0.04, 1.0],
            [0.03, 0.16, 0.72, 1.0],
            [0.04, 0.48, 0.16, 1.0],
            [0.82, 0.72, 0.05, 1.0],
            [0.08, 0.08, 0.09, 1.0],
        ];
        self.paint_color = (self.paint_color + 1) % COLORS.len();
        for material in &self.materials {
            if material.paintable {
                self.queue.write_buffer(
                    &material.color_buffer,
                    0,
                    bytemuck::cast_slice(&[
                        COLORS[self.paint_color][0],
                        COLORS[self.paint_color][1],
                        COLORS[self.paint_color][2],
                        COLORS[self.paint_color][3],
                        alpha_mode_code(material.alpha_mode),
                        material.alpha_cutoff,
                        1.0,
                        0.0,
                    ]),
                );
            }
        }
    }
    pub fn render(&mut self, target: &wgpu::TextureView) {
        if self.width == 0 || self.height == 0 {
            return;
        }
        // Update camera uniform with identity model matrix
        self.queue.write_buffer(
            &self.camera_buffer,
            0,
            bytemuck::bytes_of(&self.camera.uniform(self.width, self.height)),
        );

        // Update sky camera if present
        if let Some(sky) = &self.sky {
            let eye = self.camera.eye();
            let view_no_translate = Mat4::look_at_rh(eye, self.camera.center, Vec3::Y);
            let rotation_only = Mat4::from_cols(
                view_no_translate.col(0),
                view_no_translate.col(1),
                view_no_translate.col(2),
                glam::Vec4::new(0.0, 0.0, 0.0, 1.0),
            );
            let near = (self.camera.distance * 0.05).clamp(0.05, 1.0);
            let far = (self.camera.radius * 20.0).max(10_000.0);
            let projection = Mat4::perspective_rh(
                45.0_f32.to_radians(),
                self.width as f32 / self.height.max(1) as f32,
                near,
                far,
            );
            let sky_vp = projection * rotation_only;
            let sky_uniform = SkyUniform {
                view_projection: sky_vp.to_cols_array_2d(),
            };
            self.queue
                .write_buffer(&sky.camera_buffer, 0, bytemuck::bytes_of(&sky_uniform));
        }

        let mut encoder = self.device.create_command_encoder(&Default::default());
        {
            let mut pass = encoder.begin_render_pass(&wgpu::RenderPassDescriptor {
                label: Some("main"),
                color_attachments: &[Some(wgpu::RenderPassColorAttachment {
                    view: target,
                    depth_slice: None,
                    resolve_target: None,
                    ops: wgpu::Operations {
                        load: wgpu::LoadOp::Clear(wgpu::Color {
                            r: 0.022,
                            g: 0.030,
                            b: 0.044,
                            a: 1.0,
                        }),
                        store: wgpu::StoreOp::Store,
                    },
                })],
                depth_stencil_attachment: Some(wgpu::RenderPassDepthStencilAttachment {
                    view: &self.depth,
                    depth_ops: Some(wgpu::Operations {
                        load: wgpu::LoadOp::Clear(1.0),
                        store: wgpu::StoreOp::Store,
                    }),
                    stencil_ops: None,
                }),
                ..Default::default()
            });

            // 1. Draw sky dome first (depth at far plane, always behind geometry)
            if let Some(sky) = &self.sky {
                pass.set_pipeline(&sky.pipeline);
                pass.set_bind_group(0, &sky.camera_group, &[]);
                pass.set_bind_group(1, &sky.texture_group, &[]);
                pass.set_vertex_buffer(0, sky.vertex_buffer.slice(..));
                pass.set_index_buffer(sky.index_buffer.slice(..), wgpu::IndexFormat::Uint16);
                pass.draw_indexed(0..sky.index_count, 0, 0..1);
            }

            // 2. Draw static geometry (identity model matrix)
            pass.set_bind_group(0, &self.camera_group, &[]);
            let mut order: Vec<usize> = (0..self.static_mesh_count).collect();
            let eye = self.camera.eye();
            order.sort_by(|&a, &b| {
                let a = &self.meshes[a];
                let b = &self.meshes[b];
                let ta = self.materials[a.material].alpha_mode == AlphaMode::Blend;
                let tb = self.materials[b.material].alpha_mode == AlphaMode::Blend;
                ta.cmp(&tb).then_with(|| {
                    if ta {
                        b.center
                            .distance_squared(eye)
                            .total_cmp(&a.center.distance_squared(eye))
                    } else {
                        std::cmp::Ordering::Equal
                    }
                })
            });
            for index in order {
                let mesh = &self.meshes[index];
                let material = &self.materials[mesh.material];
                pass.set_pipeline(
                    &self.pipelines[&(
                        material.alpha_mode == AlphaMode::Blend,
                        material.double_sided,
                        material.depth_bias,
                    )],
                );
                pass.set_bind_group(1, &material.group, &[]);
                pass.set_vertex_buffer(0, mesh.vertex.slice(..));
                pass.set_index_buffer(mesh.index.slice(..), wgpu::IndexFormat::Uint32);
                pass.draw_indexed(0..mesh.count, 0, 0..1);
            }
        }
        self.queue.submit([encoder.finish()]);

        // 3. Draw prop instances (one encoder per instance to update model matrix)
        if !self.prop_draws.is_empty() {
            for prop_draw in &self.prop_draws {
                let mut uniform = self.camera.uniform(self.width, self.height);
                uniform.model = prop_draw.model.to_cols_array_2d();
                self.queue
                    .write_buffer(&self.camera_buffer, 0, bytemuck::bytes_of(&uniform));
                let mut encoder = self.device.create_command_encoder(&Default::default());
                {
                    let mut pass = encoder.begin_render_pass(&wgpu::RenderPassDescriptor {
                        label: Some("prop"),
                        color_attachments: &[Some(wgpu::RenderPassColorAttachment {
                            view: target,
                            depth_slice: None,
                            resolve_target: None,
                            ops: wgpu::Operations {
                                load: wgpu::LoadOp::Load,
                                store: wgpu::StoreOp::Store,
                            },
                        })],
                        depth_stencil_attachment: Some(wgpu::RenderPassDepthStencilAttachment {
                            view: &self.depth,
                            depth_ops: Some(wgpu::Operations {
                                load: wgpu::LoadOp::Load,
                                store: wgpu::StoreOp::Store,
                            }),
                            stencil_ops: None,
                        }),
                        ..Default::default()
                    });
                    pass.set_bind_group(0, &self.camera_group, &[]);
                    for mesh_idx in prop_draw.mesh_range.clone() {
                        if mesh_idx >= self.meshes.len() {
                            continue;
                        }
                        let mesh = &self.meshes[mesh_idx];
                        let material = &self.materials[mesh.material];
                        pass.set_pipeline(
                            &self.pipelines[&(
                                material.alpha_mode == AlphaMode::Blend,
                                material.double_sided,
                                material.depth_bias,
                            )],
                        );
                        pass.set_bind_group(1, &material.group, &[]);
                        pass.set_vertex_buffer(0, mesh.vertex.slice(..));
                        pass.set_index_buffer(mesh.index.slice(..), wgpu::IndexFormat::Uint32);
                        pass.draw_indexed(0..mesh.count, 0, 0..1);
                    }
                }
                self.queue.submit([encoder.finish()]);
            }
            // Restore identity model for next frame
            self.queue.write_buffer(
                &self.camera_buffer,
                0,
                bytemuck::bytes_of(&self.camera.uniform(self.width, self.height)),
            );
        }

        // 3.5. Draw car on track (if present)
        if let (Some(car), Some(car_render)) = (&self.car, &self.car_render) {
            let model_matrix = match (&self.sim_car, self.sim_mode) {
                (Some(sim), true) => sim.body.transform_matrix(),
                _ => car.model_matrix(),
            };
            let mut uniform = self.camera.uniform(self.width, self.height);
            uniform.model = model_matrix.to_cols_array_2d();
            self.queue
                .write_buffer(&self.camera_buffer, 0, bytemuck::bytes_of(&uniform));

            let mut encoder = self.device.create_command_encoder(&Default::default());
            {
                let mut pass = encoder.begin_render_pass(&wgpu::RenderPassDescriptor {
                    label: Some("arcade car"),
                    color_attachments: &[Some(wgpu::RenderPassColorAttachment {
                        view: target,
                        depth_slice: None,
                        resolve_target: None,
                        ops: wgpu::Operations {
                            load: wgpu::LoadOp::Load,
                            store: wgpu::StoreOp::Store,
                        },
                    })],
                    depth_stencil_attachment: Some(wgpu::RenderPassDepthStencilAttachment {
                        view: &self.depth,
                        depth_ops: Some(wgpu::Operations {
                            load: wgpu::LoadOp::Load,
                            store: wgpu::StoreOp::Store,
                        }),
                        stencil_ops: None,
                    }),
                    ..Default::default()
                });
                pass.set_bind_group(0, &self.camera_group, &[]);
                for mesh in &car_render.meshes {
                    if mesh.material >= car_render.materials.len() {
                        continue;
                    }
                    let material = &car_render.materials[mesh.material];
                    let pipeline_key = (
                        material.alpha_mode == AlphaMode::Blend,
                        material.double_sided,
                        material.depth_bias,
                    );
                    if let Some(pipeline) = self.pipelines.get(&pipeline_key) {
                        pass.set_pipeline(pipeline);
                        pass.set_bind_group(1, &material.group, &[]);
                        pass.set_vertex_buffer(0, mesh.vertex.slice(..));
                        pass.set_index_buffer(mesh.index.slice(..), wgpu::IndexFormat::Uint32);
                        pass.draw_indexed(0..mesh.count, 0, 0..1);
                    }
                }
            }
            self.queue.submit([encoder.finish()]);

            // Restore identity model for remaining passes
            self.queue.write_buffer(
                &self.camera_buffer,
                0,
                bytemuck::bytes_of(&self.camera.uniform(self.width, self.height)),
            );
        }

        // 4. Draw topology lines (if enabled and present)
        if let Some(top) = self
            .topology
            .as_ref()
            .filter(|t| self.show_topology && t.vertex_count > 0)
        {
            let mut encoder = self.device.create_command_encoder(&Default::default());
            {
                let mut pass = encoder.begin_render_pass(&wgpu::RenderPassDescriptor {
                    label: Some("topology lines"),
                    color_attachments: &[Some(wgpu::RenderPassColorAttachment {
                        view: target,
                        depth_slice: None,
                        resolve_target: None,
                        ops: wgpu::Operations {
                            load: wgpu::LoadOp::Load,
                            store: wgpu::StoreOp::Store,
                        },
                    })],
                    depth_stencil_attachment: Some(wgpu::RenderPassDepthStencilAttachment {
                        view: &self.depth,
                        depth_ops: Some(wgpu::Operations {
                            load: wgpu::LoadOp::Load,
                            store: wgpu::StoreOp::Store,
                        }),
                        stencil_ops: None,
                    }),
                    ..Default::default()
                });
                pass.set_pipeline(&top.pipeline);
                pass.set_bind_group(0, &self.camera_group, &[]);
                pass.set_vertex_buffer(0, top.vertex_buffer.slice(..));
                pass.draw(0..top.vertex_count, 0..1);
            }
            self.queue.submit([encoder.finish()]);
        }
    }

    pub fn set_show_topology(&mut self, show: bool) {
        self.show_topology = show;
    }

    pub fn toggle_topology(&mut self) -> bool {
        self.show_topology = !self.show_topology;
        self.show_topology
    }

    pub fn sample_road_elevation(&self, x: f32, z: f32) -> Option<f32> {
        sample_road_elevation_from_edges(&self.road_edges, x, z)
    }

    pub fn move_ground(&mut self, forward_amount: f32, right_amount: f32) {
        if self.camera.mode == CameraMode::Drive && self.car.is_some() {
            self.update_car(0.016, forward_amount * 0.05, right_amount * 0.05, false);
            return;
        }
        self.camera.move_ground(forward_amount, right_amount);
        if let Some(road_y) = (self.camera.mode == CameraMode::Drive)
            .then(|| self.sample_road_elevation(self.camera.drive_pos.x, self.camera.drive_pos.z))
            .flatten()
        {
            let target_y = road_y + self.camera.drive_height;
            self.camera.drive_pos.y += (target_y - self.camera.drive_pos.y) * 0.35;
        }
    }

    pub fn toggle_camera_mode(&mut self) -> bool {
        match self.camera.mode {
            CameraMode::Orbit => {
                self.camera.mode = CameraMode::Drive;
                if let Some(car) = &mut self.car {
                    if car.pos.length_squared() < 0.01 {
                        car.reset_to_road(&self.road_edges);
                    }
                    self.camera.drive_pos = car.camera_eye;
                    self.camera.drive_target = car.camera_target;
                    self.camera.drive_fov = 58.0;
                } else {
                    let mut start_pos = self.camera.center;
                    if let Some(road_y) = self.sample_road_elevation(start_pos.x, start_pos.z) {
                        start_pos.y = road_y + self.camera.drive_height;
                    } else if let Some(first_edge) = self.road_edges.first() {
                        start_pos = Vec3::new(
                            first_edge.p1[0],
                            first_edge.p1[1] + self.camera.drive_height,
                            first_edge.p1[2],
                        );
                        let dir = (Vec3::from(first_edge.p2) - Vec3::from(first_edge.p1))
                            .normalize_or_zero();
                        if dir.length_squared() > 0.01 {
                            self.camera.yaw = (-dir.x).atan2(-dir.z);
                        }
                    }
                    self.camera.drive_pos = start_pos;
                    self.camera.drive_target = start_pos + Vec3::new(0.0, 0.0, -10.0);
                }
                self.camera.pitch = 0.0;
                true
            }
            CameraMode::Drive => {
                self.camera.mode = CameraMode::Orbit;
                if let Some(car) = &self.car {
                    self.camera.center = car.pos;
                } else {
                    let forward = Vec3::new(-self.camera.yaw.sin(), 0.0, -self.camera.yaw.cos());
                    self.camera.center = self.camera.drive_pos + forward * 20.0;
                }
                self.camera.distance = 40.0;
                self.camera.pitch = 0.35;
                false
            }
        }
    }

    pub fn is_drive_mode(&self) -> bool {
        self.camera.mode == CameraMode::Drive
    }

    pub fn update_car(&mut self, dt: f32, throttle: f32, steer: f32, handbrake: bool) {
        let edges = &self.road_edges;

        if let (true, Some(sim)) = (self.sim_mode, &mut self.sim_car) {
            let controls = nfs_assets::physics::VehicleControls {
                throttle: throttle.max(0.0),
                brake: (-throttle).max(0.0),
                steer,
                handbrake,
                manual_gear: None,
                auto_gear: true,
            };
            let tel = sim.step(self.road_surface.as_ref(), &controls, dt);
            if self.camera.mode == CameraMode::Drive {
                let forward = sim.body.forward();
                let eye = sim.body.position + Vec3::new(0.0, 2.0, 0.0) - forward * 5.8;
                let target = sim.body.position + Vec3::new(0.0, 0.9, 0.0) + forward * 1.5;
                self.camera.drive_pos = eye;
                self.camera.drive_target = target;
                self.camera.drive_fov = 58.0 + (tel.speed_mps / 50.0).clamp(0.0, 1.0) * 10.0;
            }
            self.sim_telemetry = Some(tel);
            return;
        }

        if let Some(car) = &mut self.car {
            let reference_y = car.pos.y;
            let surface = self.road_surface.as_ref();
            car.update(dt, throttle, steer, handbrake, edges, |x, z| {
                match surface {
                    // Prototype support window, not recovered physics. On a miss,
                    // do not snap to another deck through the old edge estimate.
                    Some(surface) => surface
                        .query(x, z, reference_y, 2.0, 4.0)
                        .map(|hit| hit.height),
                    None => sample_road_elevation_from_edges(edges, x, z),
                }
            });
            if self.camera.mode == CameraMode::Drive {
                self.camera.drive_pos = car.camera_eye;
                self.camera.drive_target = car.camera_target;
                self.camera.drive_fov = match car.view_mode {
                    crate::arcade::DriveViewMode::Chase => {
                        58.0 + (car.speed.abs() / 50.0).clamp(0.0, 1.0) * 10.0
                    }
                    crate::arcade::DriveViewMode::Bumper => {
                        68.0 + (car.speed.abs() / 50.0).clamp(0.0, 1.0) * 12.0
                    }
                    crate::arcade::DriveViewMode::Free => 55.0,
                };
            }
        }
    }

    pub fn reset_car(&mut self) {
        if let Some(car) = &mut self.car {
            car.reset_to_road(&self.road_edges);
            if let Some(hit) = self
                .road_surface
                .as_ref()
                .and_then(|surface| surface.query(car.pos.x, car.pos.z, car.pos.y, 2.0, 4.0))
            {
                car.pos.y = hit.height;
            }
            if let Some(sim) = &mut self.sim_car {
                sim.reset(car.pos, car.yaw);
            }
            if self.camera.mode == CameraMode::Drive {
                self.camera.drive_pos = car.camera_eye;
                self.camera.drive_target = car.camera_target;
            }
        }
    }

    pub fn cycle_car_view(&mut self) -> crate::arcade::DriveViewMode {
        if let Some(car) = &mut self.car {
            let mode = car.cycle_view_mode();
            if self.camera.mode == CameraMode::Drive {
                self.camera.drive_pos = car.camera_eye;
                self.camera.drive_target = car.camera_target;
            }
            mode
        } else {
            crate::arcade::DriveViewMode::Chase
        }
    }

    pub fn cycle_car_paint(&mut self) -> usize {
        if let (Some(car), Some(car_render)) = (&mut self.car, &mut self.car_render) {
            let color_idx = car.cycle_paint();
            let color = crate::car_mesh::CAR_COLORS[color_idx];
            let material_uniform = [
                color[0],
                color[1],
                color[2],
                color[3],
                alpha_mode_code(AlphaMode::Opaque),
                0.0,
                0.0,
                0.0,
            ];
            self.queue.write_buffer(
                &car_render.materials[crate::car_mesh::MAT_BODY].color_buffer,
                0,
                bytemuck::cast_slice(&material_uniform),
            );
            color_idx
        } else {
            0
        }
    }

    pub fn get_car_speed_kmh(&self) -> f32 {
        if let (true, Some(tel)) = (self.sim_mode, &self.sim_telemetry) {
            return tel.speed_kmh;
        }
        self.car.as_ref().map(|c| c.speed_kmh()).unwrap_or(0.0)
    }

    pub fn get_car_gear(&self) -> i32 {
        if let (true, Some(tel)) = (self.sim_mode, &self.sim_telemetry) {
            return tel.current_gear;
        }
        self.car.as_ref().map(|c| c.gear).unwrap_or(0)
    }

    pub fn get_car_rpm(&self) -> f32 {
        if let (true, Some(tel)) = (self.sim_mode, &self.sim_telemetry) {
            return (tel.engine_rpm / 7000.0).clamp(0.0, 1.0);
        }
        self.car.as_ref().map(|c| c.rpm).unwrap_or(0.0)
    }

    pub fn toggle_sim_mode(&mut self) -> bool {
        self.sim_mode = !self.sim_mode;
        self.sim_mode
    }

    pub fn is_sim_mode(&self) -> bool {
        self.sim_mode
    }

    pub fn has_car(&self) -> bool {
        self.car.is_some()
    }
}

pub fn sample_road_elevation_from_edges(
    road_edges: &[nfs_assets::TopologyEdge],
    x: f32,
    z: f32,
) -> Option<f32> {
    if road_edges.is_empty() {
        return None;
    }
    let mut best_dist_sq = 1e9_f32;
    let mut best_y = 0.0_f32;

    for edge in road_edges {
        let x1 = edge.p1[0];
        let z1 = edge.p1[2];
        let x2 = edge.p2[0];
        let z2 = edge.p2[2];

        if (x - x1).abs() > 45.0 && (x - x2).abs() > 45.0 {
            continue;
        }
        if (z - z1).abs() > 45.0 && (z - z2).abs() > 45.0 {
            continue;
        }

        let dx = x2 - x1;
        let dz = z2 - z1;
        let seg_len_sq = dx * dx + dz * dz;
        let t = if seg_len_sq < 1e-6 {
            0.0
        } else {
            (((x - x1) * dx + (z - z1) * dz) / seg_len_sq).clamp(0.0, 1.0)
        };

        let proj_x = x1 + t * dx;
        let proj_z = z1 + t * dz;
        let dist_sq = (x - proj_x) * (x - proj_x) + (z - proj_z) * (z - proj_z);
        if dist_sq < best_dist_sq {
            best_dist_sq = dist_sq;
            let y1 = edge.p1[1];
            let y2 = edge.p2[1];
            best_y = y1 + t * (y2 - y1);
        }
    }

    if best_dist_sq < 625.0 {
        return Some(best_y);
    }

    if best_dist_sq > 1e8 {
        for edge in road_edges {
            let x1 = edge.p1[0];
            let z1 = edge.p1[2];
            let x2 = edge.p2[0];
            let z2 = edge.p2[2];

            let dx = x2 - x1;
            let dz = z2 - z1;
            let seg_len_sq = dx * dx + dz * dz;
            let t = if seg_len_sq < 1e-6 {
                0.0
            } else {
                (((x - x1) * dx + (z - z1) * dz) / seg_len_sq).clamp(0.0, 1.0)
            };

            let proj_x = x1 + t * dx;
            let proj_z = z1 + t * dz;
            let dist_sq = (x - proj_x) * (x - proj_x) + (z - proj_z) * (z - proj_z);
            if dist_sq < best_dist_sq {
                best_dist_sq = dist_sq;
                let y1 = edge.p1[1];
                let y2 = edge.p2[1];
                best_y = y1 + t * (y2 - y1);
            }
        }
    }

    if best_dist_sq < 6400.0 {
        Some(best_y)
    } else {
        None
    }
}

fn alpha_mode_code(mode: AlphaMode) -> f32 {
    match mode {
        AlphaMode::Opaque => 0.0,
        AlphaMode::Mask => 1.0,
        AlphaMode::Blend => 2.0,
    }
}

fn upload_texture(
    device: &wgpu::Device,
    queue: &wgpu::Queue,
    width: u32,
    height: u32,
    rgba: &[u8],
) -> wgpu::TextureView {
    let size = wgpu::Extent3d {
        width,
        height,
        depth_or_array_layers: 1,
    };
    let texture = device.create_texture(&wgpu::TextureDescriptor {
        label: Some("car texture"),
        size,
        mip_level_count: 1,
        sample_count: 1,
        dimension: wgpu::TextureDimension::D2,
        format: wgpu::TextureFormat::Rgba8UnormSrgb,
        usage: wgpu::TextureUsages::TEXTURE_BINDING | wgpu::TextureUsages::COPY_DST,
        view_formats: &[],
    });
    queue.write_texture(
        wgpu::TexelCopyTextureInfo {
            texture: &texture,
            mip_level: 0,
            origin: wgpu::Origin3d::ZERO,
            aspect: wgpu::TextureAspect::All,
        },
        rgba,
        wgpu::TexelCopyBufferLayout {
            offset: 0,
            bytes_per_row: Some(4 * width),
            rows_per_image: Some(height),
        },
        size,
    );
    texture.create_view(&Default::default())
}

fn depth_view(device: &wgpu::Device, width: u32, height: u32) -> wgpu::TextureView {
    device
        .create_texture(&wgpu::TextureDescriptor {
            label: Some("depth"),
            size: wgpu::Extent3d {
                width: width.max(1),
                height: height.max(1),
                depth_or_array_layers: 1,
            },
            mip_level_count: 1,
            sample_count: 1,
            dimension: wgpu::TextureDimension::D2,
            format: wgpu::TextureFormat::Depth32Float,
            usage: wgpu::TextureUsages::RENDER_ATTACHMENT,
            view_formats: &[],
        })
        .create_view(&Default::default())
}

// --- Sky dome ---

#[repr(C)]
#[derive(Clone, Copy, Pod, Zeroable)]
struct SkyUniform {
    view_projection: [[f32; 4]; 4],
}

#[repr(C)]
#[derive(Clone, Copy, Pod, Zeroable)]
struct SkyVertex {
    position: [f32; 3],
}

fn generate_sky_sphere() -> (Vec<SkyVertex>, Vec<u16>) {
    let stacks = 16u16;
    let slices = 32u16;
    let radius = 1.0f32;
    let mut vertices = Vec::new();
    let mut indices = Vec::new();

    for i in 0..=stacks {
        let phi = std::f32::consts::PI * i as f32 / stacks as f32;
        for j in 0..=slices {
            let theta = 2.0 * std::f32::consts::PI * j as f32 / slices as f32;
            let x = radius * phi.sin() * theta.cos();
            let y = radius * phi.cos();
            let z = radius * phi.sin() * theta.sin();
            vertices.push(SkyVertex {
                position: [x, y, z],
            });
        }
    }

    for i in 0..stacks {
        for j in 0..slices {
            let first = i * (slices + 1) + j;
            let second = first + slices + 1;
            // Inverted winding (CW) so faces point inward
            indices.extend_from_slice(&[first, second, first + 1]);
            indices.extend_from_slice(&[first + 1, second, second + 1]);
        }
    }
    (vertices, indices)
}

#[allow(clippy::too_many_arguments)]
fn create_sky_state(
    device: &wgpu::Device,
    queue: &wgpu::Queue,
    format: wgpu::TextureFormat,
    camera: &Camera,
    width: u32,
    height: u32,
    tex_width: u32,
    tex_height: u32,
    tex_rgba: &[u8],
) -> SkyState {
    let sky_shader = device.create_shader_module(wgpu::ShaderModuleDescriptor {
        label: Some("sky shader"),
        source: wgpu::ShaderSource::Wgsl(include_str!("sky.wgsl").into()),
    });

    let sky_camera_layout = device.create_bind_group_layout(&wgpu::BindGroupLayoutDescriptor {
        label: Some("sky camera"),
        entries: &[wgpu::BindGroupLayoutEntry {
            binding: 0,
            visibility: wgpu::ShaderStages::VERTEX,
            ty: wgpu::BindingType::Buffer {
                ty: wgpu::BufferBindingType::Uniform,
                has_dynamic_offset: false,
                min_binding_size: None,
            },
            count: None,
        }],
    });

    let sky_texture_layout = device.create_bind_group_layout(&wgpu::BindGroupLayoutDescriptor {
        label: Some("sky texture"),
        entries: &[
            wgpu::BindGroupLayoutEntry {
                binding: 0,
                visibility: wgpu::ShaderStages::FRAGMENT,
                ty: wgpu::BindingType::Texture {
                    sample_type: wgpu::TextureSampleType::Float { filterable: true },
                    view_dimension: wgpu::TextureViewDimension::D2,
                    multisampled: false,
                },
                count: None,
            },
            wgpu::BindGroupLayoutEntry {
                binding: 1,
                visibility: wgpu::ShaderStages::FRAGMENT,
                ty: wgpu::BindingType::Sampler(wgpu::SamplerBindingType::Filtering),
                count: None,
            },
        ],
    });

    let sky_pipeline_layout = device.create_pipeline_layout(&wgpu::PipelineLayoutDescriptor {
        label: Some("sky"),
        bind_group_layouts: &[Some(&sky_camera_layout), Some(&sky_texture_layout)],
        immediate_size: 0,
    });

    let pipeline = device.create_render_pipeline(&wgpu::RenderPipelineDescriptor {
        label: Some("sky"),
        layout: Some(&sky_pipeline_layout),
        vertex: wgpu::VertexState {
            module: &sky_shader,
            entry_point: Some("vs_main"),
            compilation_options: Default::default(),
            buffers: &[Some(wgpu::VertexBufferLayout {
                array_stride: std::mem::size_of::<SkyVertex>() as u64,
                step_mode: wgpu::VertexStepMode::Vertex,
                attributes: &wgpu::vertex_attr_array![0 => Float32x3],
            })],
        },
        fragment: Some(wgpu::FragmentState {
            module: &sky_shader,
            entry_point: Some("fs_main"),
            compilation_options: Default::default(),
            targets: &[Some(wgpu::ColorTargetState {
                format,
                blend: None,
                write_mask: wgpu::ColorWrites::ALL,
            })],
        }),
        primitive: wgpu::PrimitiveState {
            cull_mode: None,
            ..Default::default()
        },
        depth_stencil: Some(wgpu::DepthStencilState {
            format: wgpu::TextureFormat::Depth32Float,
            depth_write_enabled: Some(false),
            depth_compare: Some(wgpu::CompareFunction::LessEqual),
            stencil: Default::default(),
            bias: Default::default(),
        }),
        multisample: Default::default(),
        multiview_mask: None,
        cache: None,
    });

    let vp = camera.view_projection(width, height);
    let sky_uniform = SkyUniform {
        view_projection: vp.to_cols_array_2d(),
    };
    let camera_buffer = device.create_buffer_init(&wgpu::util::BufferInitDescriptor {
        label: Some("sky camera"),
        contents: bytemuck::bytes_of(&sky_uniform),
        usage: wgpu::BufferUsages::UNIFORM | wgpu::BufferUsages::COPY_DST,
    });
    let camera_group = device.create_bind_group(&wgpu::BindGroupDescriptor {
        label: Some("sky camera"),
        layout: &sky_camera_layout,
        entries: &[wgpu::BindGroupEntry {
            binding: 0,
            resource: camera_buffer.as_entire_binding(),
        }],
    });

    let sky_tex_view = upload_texture(device, queue, tex_width, tex_height, tex_rgba);
    let sky_sampler = device.create_sampler(&wgpu::SamplerDescriptor {
        label: Some("sky sampler"),
        address_mode_u: wgpu::AddressMode::Repeat,
        address_mode_v: wgpu::AddressMode::ClampToEdge,
        mag_filter: wgpu::FilterMode::Linear,
        min_filter: wgpu::FilterMode::Linear,
        ..Default::default()
    });
    let texture_group = device.create_bind_group(&wgpu::BindGroupDescriptor {
        label: Some("sky texture"),
        layout: &sky_texture_layout,
        entries: &[
            wgpu::BindGroupEntry {
                binding: 0,
                resource: wgpu::BindingResource::TextureView(&sky_tex_view),
            },
            wgpu::BindGroupEntry {
                binding: 1,
                resource: wgpu::BindingResource::Sampler(&sky_sampler),
            },
        ],
    });

    let (sphere_vertices, sphere_indices) = generate_sky_sphere();
    let vertex_buffer = device.create_buffer_init(&wgpu::util::BufferInitDescriptor {
        label: Some("sky vertices"),
        contents: bytemuck::cast_slice(&sphere_vertices),
        usage: wgpu::BufferUsages::VERTEX,
    });
    let index_buffer = device.create_buffer_init(&wgpu::util::BufferInitDescriptor {
        label: Some("sky indices"),
        contents: bytemuck::cast_slice(&sphere_indices),
        usage: wgpu::BufferUsages::INDEX,
    });
    let index_count = sphere_indices.len() as u32;

    SkyState {
        pipeline,
        vertex_buffer,
        index_buffer,
        index_count,
        camera_buffer,
        camera_group,
        texture_group,
    }
}
