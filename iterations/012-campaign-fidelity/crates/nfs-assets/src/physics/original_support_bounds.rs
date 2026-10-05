//! Type-1 support callbacks and node/object overlap from unmodified Porsche.exe.
//!
//! SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
//! Source and differential replay: research/original-collision/support-bounds.md.
//! Finite type-1 triangles/quads only; no resource assembly or tree insertion.

/// Original vtable +4 (`0x4855c0` quad, `0x485e40` triangle).
/// The source evaluates intermediates in x87 precision, then stores each f32.
pub fn center(vertices: &[[f32; 3]]) -> [f32; 3] {
    assert!(vertices.len() == 3 || vertices.len() == 4);
    let factor = if vertices.len() == 3 {
        (1.0_f32 / 3.0_f32) as f64
    } else {
        0.25_f64
    };
    std::array::from_fn(|axis| {
        let mut sum = vertices[1][axis] as f64 + vertices[0][axis] as f64;
        sum += vertices[2][axis] as f64;
        if vertices.len() == 4 {
            sum += vertices[3][axis] as f64;
        }
        (sum * factor) as f32
    })
}

/// Original vtable +8 (`0x485630` quad, `0x485ea0` triangle).
/// Both callbacks write X/Z only: caller-provided Y values remain intact.
pub fn bounds(
    vertices: &[[f32; 3]],
    mut lower: [f32; 3],
    mut upper: [f32; 3],
) -> ([f32; 3], [f32; 3]) {
    assert!(vertices.len() == 3 || vertices.len() == 4);
    for axis in [0, 2] {
        lower[axis] = vertices.iter().map(|v| v[axis]).reduce(f32::min).unwrap();
        upper[axis] = vertices.iter().map(|v| v[axis]).reduce(f32::max).unwrap();
    }
    (lower, upper)
}

/// Packed node from original_spatial, with its original level-width table.
/// Returns the bounded result of `0x484320` for finite type-1 support vertices.
pub fn node_overlap(
    packed: u32,
    widths: &[f32; 16],
    half_extent: f32,
    vertices: &[[f32; 3]],
) -> bool {
    let width = widths[(packed >> 28) as usize] as f64;
    let x = (packed & 0x3fff) as f64;
    let z = ((packed >> 14) & 0x3fff) as f64;
    let cell_x = (x * width - half_extent as f64) as f32;
    let cell_z = (z * width - half_extent as f64) as f32;
    let right = (cell_x as f64 + width) as f32;
    let far = (cell_z as f64 + width) as f32;
    let midpoint = center(vertices);
    if midpoint[0] >= cell_x && midpoint[0] <= right && midpoint[2] >= cell_z && midpoint[2] <= far
    {
        return true;
    }
    let (lower, upper) = bounds(vertices, [0.0; 3], [0.0; 3]);
    lower[0] < right && lower[2] < far && upper[0] >= cell_x && upper[2] >= cell_z
}
