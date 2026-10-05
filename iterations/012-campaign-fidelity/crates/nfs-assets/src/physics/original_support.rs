//! Bounded polygon support query from `Porsche.exe` SHA256
//! `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
//!
//! Source: indexed constructors `0x4853c0` (quad), `0x485c50` (triangle),
//! containment callbacks `0x485780` / `0x486090`, and supplied-leaf selection
//! `0x47329f..0x47332c`; checked against original x86 in
//! `runs/013-original-support-query/support-replay.json`. The resource loader,
//! spatial traversal, and selection of the leaf are outside this API.

#[derive(Clone, Debug, PartialEq)]
pub enum SupportVertices {
    Triangle([[f32; 3]; 3]),
    Quad([[f32; 3]; 4]),
}

#[derive(Clone, Debug, PartialEq)]
pub struct SupportPolygon {
    pub vertices: SupportVertices,
    /// Original polygon flags at object+0xa; selection checks its low nibble.
    pub flags_word_a: u16,
    /// Value returned by the polygon's center callback (vtable slot +4),
    /// computed here once for the supplied-leaf query. This is not a field
    /// at object+4, which holds the polygon type byte.
    pub center: [f32; 3],
    /// Original orientation byte at object+8.
    pub winding_8: bool,
}

fn cross_bits(a: [f32; 3], b: [f32; 3], point: [f32; 3]) -> i32 {
    // The callback stores the x87 cross value as f32, then compares its
    // signed integer bit pattern. In particular, -0.0 and +0.0 differ.
    let cross = ((a[0] as f64 - b[0] as f64) * (point[2] as f64 - b[2] as f64)
        - (point[0] as f64 - b[0] as f64) * (a[2] as f64 - b[2] as f64)) as f32;
    cross.to_bits() as i32
}

fn edges_agree(vertices: &[[f32; 3]], point: [f32; 3], winding: bool) -> bool {
    (0..vertices.len()).all(|i| {
        let signed_bits = cross_bits(vertices[i], vertices[(i + 1) % vertices.len()], point);
        if winding {
            signed_bits <= 0
        } else {
            signed_bits >= 0
        }
    })
}

impl SupportPolygon {
    pub fn new(vertices: SupportVertices, flags_word_a: u16) -> Self {
        let (points, factor): (&[[f32; 3]], f32) = match &vertices {
            SupportVertices::Triangle(points) => (points, f32::from_bits(0x3eaaaaab)),
            SupportVertices::Quad(points) => (points, 0.25),
        };
        let mut center = [0.0; 3];
        for axis in 0..3 {
            // The original triangle callback adds 0+1+2. The quad callback
            // adds 2+1+0+3 before multiplying by its factor.
            let sum = match &vertices {
                SupportVertices::Triangle(_) => {
                    points[0][axis] as f64 + points[1][axis] as f64 + points[2][axis] as f64
                }
                SupportVertices::Quad(_) => {
                    points[2][axis] as f64
                        + points[1][axis] as f64
                        + points[0][axis] as f64
                        + points[3][axis] as f64
                }
            };
            center[axis] = (sum * factor as f64) as f32;
        }
        let winding_8 = edges_agree(points, center, true);
        Self {
            vertices,
            flags_word_a,
            center,
            winding_8,
        }
    }

    pub fn contains_xz(&self, point: [f32; 3]) -> bool {
        let points: &[[f32; 3]] = match &self.vertices {
            SupportVertices::Triangle(points) => points,
            SupportVertices::Quad(points) => points,
        };
        edges_agree(points, point, self.winding_8)
    }
}

/// One already enumerated record in the supplied spatial leaf.
pub struct SupportLeafRecord<'a> {
    pub record_type: u8,
    pub polygon: &'a SupportPolygon,
}

/// Return the index of the first nearest eligible type-1 polygon in this
/// already supplied leaf. Strict `<` preserves the original first tie.
pub fn select_support_polygon(records: &[SupportLeafRecord<'_>], point: [f32; 3]) -> Option<usize> {
    let mut best_distance = f32::from_bits(0x7e967699);
    let mut selected = None;
    for (index, record) in records.iter().enumerate() {
        if record.record_type != 1
            || record.polygon.flags_word_a & 0xf == 0
            || !record.polygon.contains_xz(point)
        {
            continue;
        }
        // The comparison uses the live x87 difference against a stored f32
        // best distance. f64 approximates the 80-bit x87 accumulator; the
        // winning distance is then stored as f32.
        let distance = (record.polygon.center[1] as f64 - point[1] as f64).abs();
        if distance < best_distance as f64 {
            best_distance = distance as f32;
            selected = Some(index);
        }
    }
    selected
}
