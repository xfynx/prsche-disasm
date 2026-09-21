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

pub struct Camera {
    pub yaw: f32,
    pub pitch: f32,
    pub distance: f32,
    pub center: Vec3,
    pub radius: f32,
}

impl Camera {
    pub fn new(bounds: [[f32; 3]; 2]) -> Self {
        let min = Vec3::from(bounds[0]);
        let max = Vec3::from(bounds[1]);
        let radius = ((max - min).length() * 0.5).max(0.1);
        let mut camera = Self {
            center: (max + min) * 0.5,
            radius,
            yaw: 0.0,
            pitch: 0.0,
            distance: 0.0,
        };
        camera.reset();
        camera
    }
    pub fn reset(&mut self) {
        self.yaw = 0.75;
        self.pitch = 0.27;
        self.distance = self.radius * 2.8;
    }
    pub fn orbit(&mut self, x: f32, y: f32) {
        self.yaw -= x * 0.006;
        self.pitch = (self.pitch + y * 0.006).clamp(-1.45, 1.45);
    }
    pub fn zoom(&mut self, delta: f32) {
        self.distance =
            (self.distance * (delta * 0.001).exp()).clamp(self.radius * 1.1, self.radius * 16.0);
    }
    fn eye(&self) -> Vec3 {
        self.center
            + self.distance
                * Vec3::new(
                    self.yaw.sin() * self.pitch.cos(),
                    self.pitch.sin(),
                    self.yaw.cos() * self.pitch.cos(),
                )
    }
    fn uniform(&self, width: u32, height: u32) -> CameraUniform {
        let projection = Mat4::perspective_rh(
            45.0_f32.to_radians(),
            width as f32 / height.max(1) as f32,
            self.radius * 0.01,
            self.radius * 100.0,
        );
        let eye = self.eye();
        CameraUniform {
            matrix: (projection * Mat4::look_at_rh(eye, self.center, Vec3::Y)).to_cols_array_2d(),
            eye: [eye.x, eye.y, eye.z, 1.0],
        }
    }
}

#[repr(C)]
#[derive(Clone, Copy, Pod, Zeroable)]
struct CameraUniform {
    matrix: [[f32; 4]; 4],
    eye: [f32; 4],
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
    materials: Vec<GpuMaterial>,
    paint_color: usize,
    depth: wgpu::TextureView,
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
        for material in &scene.materials {
            let blend = material.alpha_mode == AlphaMode::Blend;
            let double_sided = material.double_sided;
            let key = (blend, double_sided, material.depth_bias);
            if pipelines.contains_key(&key) {
                continue;
            }
            pipelines.insert(key, device.create_render_pipeline(&wgpu::RenderPipelineDescriptor {
                label: Some("car"), layout: Some(&layout),
                vertex: wgpu::VertexState { module: &shader, entry_point: Some("vs_main"), compilation_options: Default::default(), buffers: &[Some(wgpu::VertexBufferLayout { array_stride: std::mem::size_of::<GpuVertex>() as u64, step_mode: wgpu::VertexStepMode::Vertex, attributes: &wgpu::vertex_attr_array![0 => Float32x3, 1 => Float32x3, 2 => Float32x2] })] },
                fragment: Some(wgpu::FragmentState { module: &shader, entry_point: Some("fs_main"), compilation_options: Default::default(), targets: &[Some(wgpu::ColorTargetState { format, blend: if blend { Some(wgpu::BlendState::ALPHA_BLENDING) } else { None }, write_mask: wgpu::ColorWrites::ALL })] }),
                primitive: wgpu::PrimitiveState { cull_mode: if double_sided { None } else { Some(wgpu::Face::Back) }, ..Default::default() },
                depth_stencil: Some(wgpu::DepthStencilState { format: wgpu::TextureFormat::Depth32Float, depth_write_enabled: Some(!blend), depth_compare: Some(wgpu::CompareFunction::LessEqual), stencil: Default::default(), bias: wgpu::DepthBiasState { constant: material.depth_bias, ..Default::default() } }),
                multisample: Default::default(), multiview_mask: None, cache: None,
            }));
        }
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
            materials,
            paint_color: 0,
            depth,
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
        self.queue.write_buffer(
            &self.camera_buffer,
            0,
            bytemuck::bytes_of(&self.camera.uniform(self.width, self.height)),
        );
        let mut encoder = self.device.create_command_encoder(&Default::default());
        {
            let mut pass = encoder.begin_render_pass(&wgpu::RenderPassDescriptor {
                label: Some("car"),
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
            pass.set_bind_group(0, &self.camera_group, &[]);
            let mut order: Vec<usize> = (0..self.meshes.len()).collect();
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
