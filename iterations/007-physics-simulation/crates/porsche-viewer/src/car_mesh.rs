//! Procedural stylized Porsche sports car mesh generator.
//! Provides an authentic, streamlined Porsche silhouette (low nose, teardrop cabin, fastback tail)
//! that is guaranteed to render with wheels on road surface (Y=0).

use glam::Vec3;

#[derive(Clone, Copy)]
pub struct VertexData {
    pub pos: [f32; 3],
    pub normal: [f32; 3],
    pub uv: [f32; 2],
}

pub struct PartMesh {
    pub material: usize,
    pub vertices: Vec<VertexData>,
    pub indices: Vec<u32>,
}

pub struct CarGeometry {
    pub parts: Vec<PartMesh>,
}

pub const MAT_BODY: usize = 0;
pub const MAT_GLASS: usize = 1;
pub const MAT_BLACK: usize = 2;
pub const MAT_RIMS: usize = 3;
pub const MAT_LIGHTS_FRONT: usize = 4;
pub const MAT_LIGHTS_REAR: usize = 5;

pub const CAR_COLORS: [[f32; 4]; 6] = [
    [0.84, 0.10, 0.08, 1.0], // 0: Guards Red (classic Porsche)
    [0.10, 0.18, 0.35, 1.0], // 1: Midnight Blue
    [0.78, 0.80, 0.82, 1.0], // 2: GT Silver Metallic
    [0.12, 0.35, 0.18, 1.0], // 3: Irish Green
    [0.92, 0.72, 0.08, 1.0], // 4: Speed Yellow
    [0.12, 0.12, 0.14, 1.0], // 5: Basalt Black
];

pub fn generate_procedural_car() -> CarGeometry {
    let mut body = PartMesh {
        material: MAT_BODY,
        vertices: Vec::new(),
        indices: Vec::new(),
    };
    let mut glass = PartMesh {
        material: MAT_GLASS,
        vertices: Vec::new(),
        indices: Vec::new(),
    };
    let mut black = PartMesh {
        material: MAT_BLACK,
        vertices: Vec::new(),
        indices: Vec::new(),
    };
    let mut rims = PartMesh {
        material: MAT_RIMS,
        vertices: Vec::new(),
        indices: Vec::new(),
    };
    let mut front_lights = PartMesh {
        material: MAT_LIGHTS_FRONT,
        vertices: Vec::new(),
        indices: Vec::new(),
    };
    let mut rear_lights = PartMesh {
        material: MAT_LIGHTS_REAR,
        vertices: Vec::new(),
        indices: Vec::new(),
    };

    // Helper to add a quad
    let add_quad = |mesh: &mut PartMesh, p0: [f32; 3], p1: [f32; 3], p2: [f32; 3], p3: [f32; 3]| {
        let v0 = Vec3::from(p0);
        let v1 = Vec3::from(p1);
        let v2 = Vec3::from(p2);
        let normal = (v1 - v0).cross(v2 - v0).normalize_or_zero().to_array();
        let base_idx = mesh.vertices.len() as u32;
        mesh.vertices.push(VertexData {
            pos: p0,
            normal,
            uv: [0.0, 0.0],
        });
        mesh.vertices.push(VertexData {
            pos: p1,
            normal,
            uv: [1.0, 0.0],
        });
        mesh.vertices.push(VertexData {
            pos: p2,
            normal,
            uv: [1.0, 1.0],
        });
        mesh.vertices.push(VertexData {
            pos: p3,
            normal,
            uv: [0.0, 1.0],
        });
        mesh.indices.extend_from_slice(&[
            base_idx,
            base_idx + 1,
            base_idx + 2,
            base_idx,
            base_idx + 2,
            base_idx + 3,
        ]);
    };

    // Helper to add a 3D box
    let add_box = |mesh: &mut PartMesh, min: [f32; 3], max: [f32; 3]| {
        let [x0, y0, z0] = min;
        let [x1, y1, z1] = max;
        // Top (+Y)
        add_quad(mesh, [x0, y1, z1], [x1, y1, z1], [x1, y1, z0], [x0, y1, z0]);
        // Bottom (-Y)
        add_quad(mesh, [x0, y0, z0], [x1, y0, z0], [x1, y0, z1], [x0, y0, z1]);
        // Front (-Z)
        add_quad(mesh, [x0, y0, z0], [x0, y1, z0], [x1, y1, z0], [x1, y0, z0]);
        // Back (+Z)
        add_quad(mesh, [x1, y0, z1], [x1, y1, z1], [x0, y1, z1], [x0, y0, z1]);
        // Left (-X)
        add_quad(mesh, [x0, y0, z1], [x0, y1, z1], [x0, y1, z0], [x0, y0, z0]);
        // Right (+X)
        add_quad(mesh, [x1, y0, z0], [x1, y1, z0], [x1, y1, z1], [x1, y0, z1]);
    };

    // 1. Lower chassis / underbody plate (Black)
    add_box(&mut black, [-0.80, 0.15, -2.00], [0.80, 0.32, 2.05]);

    // 2. Front bumper & lower nose (Body)
    add_box(&mut body, [-0.82, 0.25, -2.15], [0.82, 0.52, -1.85]);
    // Front splitter / air intake (Black)
    add_box(&mut black, [-0.60, 0.22, -2.17], [0.60, 0.35, -2.10]);

    // 3. Front hood (sloping down to nose)
    add_quad(
        &mut body,
        [-0.78, 0.72, -0.60],
        [0.78, 0.72, -0.60],
        [0.75, 0.52, -1.90],
        [-0.75, 0.52, -1.90],
    );

    // Front left & right fender curves
    add_quad(
        &mut body,
        [-0.84, 0.30, -1.90],
        [-0.75, 0.52, -1.90],
        [-0.78, 0.72, -0.60],
        [-0.86, 0.50, -0.60],
    );
    add_quad(
        &mut body,
        [0.75, 0.52, -1.90],
        [0.84, 0.30, -1.90],
        [0.86, 0.50, -0.60],
        [0.78, 0.72, -0.60],
    );

    // 4. Cockpit / Greenhouse (Glass & Roof)
    // Windshield (sloping from hood to roof)
    add_quad(
        &mut glass,
        [-0.72, 0.74, -0.58],
        [0.72, 0.74, -0.58],
        [0.62, 1.24, -0.10],
        [-0.62, 1.24, -0.10],
    );
    // Roof (Body)
    add_quad(
        &mut body,
        [-0.62, 1.24, -0.10],
        [0.62, 1.24, -0.10],
        [0.60, 1.22, 0.55],
        [-0.60, 1.22, 0.55],
    );
    // Fastback rear window (Glass)
    add_quad(
        &mut glass,
        [-0.60, 1.22, 0.55],
        [0.60, 1.22, 0.55],
        [0.68, 0.80, 1.45],
        [-0.68, 0.80, 1.45],
    );
    // Side windows Left & Right (Glass)
    add_quad(
        &mut glass,
        [-0.63, 1.23, -0.08],
        [-0.73, 0.73, -0.55],
        [-0.74, 0.73, 0.58],
        [-0.61, 1.21, 0.52],
    );
    add_quad(
        &mut glass,
        [0.73, 0.73, -0.55],
        [0.63, 1.23, -0.08],
        [0.61, 1.21, 0.52],
        [0.74, 0.73, 0.58],
    );

    // 5. Doors & Side Pods (Body)
    add_box(&mut body, [-0.85, 0.30, -0.60], [-0.74, 0.72, 0.60]);
    add_box(&mut body, [0.74, 0.30, -0.60], [0.85, 0.72, 0.60]);

    // 6. Rear Engine Deck & Tail (Body)
    add_quad(
        &mut body,
        [-0.76, 0.78, 1.40],
        [0.76, 0.78, 1.40],
        [0.72, 0.68, 2.10],
        [-0.72, 0.68, 2.10],
    );
    // Rear bumper & ducktail spoiler
    add_box(&mut body, [-0.82, 0.30, 1.95], [0.82, 0.70, 2.15]);
    add_box(&mut body, [-0.74, 0.68, 2.05], [0.74, 0.74, 2.18]); // small spoiler lip
    // Rear diffuser / exhaust cutout (Black)
    add_box(&mut black, [-0.55, 0.20, 2.10], [0.55, 0.32, 2.16]);

    // Rear engine lid grille vents (Black)
    add_box(&mut black, [-0.35, 0.785, 1.55], [0.35, 0.795, 1.85]);

    // 7. Headlights (round front lenses on front fenders)
    add_box(
        &mut front_lights,
        [-0.68, 0.52, -2.05],
        [-0.50, 0.65, -1.95],
    );
    add_box(&mut front_lights, [0.50, 0.52, -2.05], [0.68, 0.65, -1.95]);

    // 8. Taillights (vibrant red horizontal light strip across rear deck)
    add_box(&mut rear_lights, [-0.76, 0.58, 2.15], [0.76, 0.66, 2.18]);

    // 9. Wheels & Rims (4 wheels)
    // Wheel centers:
    let wheels = [
        [-0.78, 0.32, -1.25, -1.0], // Front Left
        [0.78, 0.32, -1.25, 1.0],   // Front Right
        [-0.80, 0.32, 1.20, -1.0],  // Rear Left
        [0.80, 0.32, 1.20, 1.0],    // Rear Right
    ];

    let segments = 16;
    let radius = 0.32_f32;
    let width = 0.22_f32;

    for &[cx, cy, cz, side] in &wheels {
        let x_inner = cx - side * width * 0.5;
        let x_outer = cx + side * width * 0.5;

        // Tire cylinder (Black)
        let tire_base = black.vertices.len() as u32;
        for i in 0..=segments {
            let theta = (i as f32 / segments as f32) * std::f32::consts::TAU;
            let dy = theta.cos() * radius;
            let dz = theta.sin() * radius;
            let normal = [0.0, theta.cos(), theta.sin()];
            black.vertices.push(VertexData {
                pos: [x_inner, cy + dy, cz + dz],
                normal,
                uv: [0.0, 0.0],
            });
            black.vertices.push(VertexData {
                pos: [x_outer, cy + dy, cz + dz],
                normal,
                uv: [1.0, 0.0],
            });
        }
        for i in 0..segments {
            let i0 = tire_base + i * 2;
            let i1 = i0 + 1;
            let i2 = i0 + 2;
            let i3 = i0 + 3;
            if side > 0.0 {
                black.indices.extend_from_slice(&[i0, i2, i1, i1, i2, i3]);
            } else {
                black.indices.extend_from_slice(&[i0, i1, i2, i1, i3, i2]);
            }
        }

        // Rim outer disc (Silver)
        let rim_radius = radius * 0.72;
        let rim_center = [x_outer + side * 0.005, cy, cz];
        let rim_base = rims.vertices.len() as u32;
        rims.vertices.push(VertexData {
            pos: rim_center,
            normal: [side, 0.0, 0.0],
            uv: [0.5, 0.5],
        });
        for i in 0..=segments {
            let theta = (i as f32 / segments as f32) * std::f32::consts::TAU;
            let dy = theta.cos() * rim_radius;
            let dz = theta.sin() * rim_radius;
            rims.vertices.push(VertexData {
                pos: [rim_center[0], cy + dy, cz + dz],
                normal: [side, 0.0, 0.0],
                uv: [0.5 + theta.cos() * 0.5, 0.5 + theta.sin() * 0.5],
            });
        }
        for i in 1..=segments {
            if side > 0.0 {
                rims.indices
                    .extend_from_slice(&[rim_base, rim_base + i, rim_base + i + 1]);
            } else {
                rims.indices
                    .extend_from_slice(&[rim_base, rim_base + i + 1, rim_base + i]);
            }
        }
    }

    CarGeometry {
        parts: vec![body, glass, black, rims, front_lights, rear_lights],
    }
}
