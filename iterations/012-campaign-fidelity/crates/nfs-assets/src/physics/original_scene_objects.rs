//! Bounded mixed-scene objects from Porsche.exe SHA256
//! ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
//! EDG: 0x487e80 -> 0x485100; callbacks 0x4852b0/0x485340/0x4852f0.
//! Special spatial bounds: 0x486340, callbacks 0x486490/0x486560.
//! 0x488590 generates additional shared-boundary edges from the temporary
//! polygon tree. It does not take raw EDG as its input.

use nfs_formats::{parse_edg, Result};

#[derive(Clone, Debug, PartialEq)]
pub struct EdgeObject {
    /// Raw EDG byte +0, copied to object word +8 by 0x487f0d and 0x4851e8.
    pub word: u16,
    pub endpoints: [[f32; 3]; 2],
    /// Index of the 28-byte resource record in the direct file load path.
    pub source_index: usize,
}

impl EdgeObject {
    /// 0x485100 constructor. When either XZ span exceeds the original 100
    /// constant, replace A by B and offset B.x by the original literal 1.
    /// Raw resource endpoints cannot be used as constructed object endpoints.
    pub fn from_source(word: u16, mut endpoints: [[f32; 3]; 2], source_index: usize) -> Self {
        let x_span = endpoints[0][0].max(endpoints[1][0]) as f64
            - endpoints[0][0].min(endpoints[1][0]) as f64;
        let z_span = endpoints[0][2].max(endpoints[1][2]) as f64
            - endpoints[0][2].min(endpoints[1][2]) as f64;
        if x_span > 100.0 || z_span > 100.0 {
            endpoints[0] = endpoints[1];
            endpoints[1][0] = (endpoints[1][0] as f64 + 1.0) as f32;
        }
        Self {
            word,
            endpoints,
            source_index,
        }
    }
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum SpecialKind {
    Cylinder,
    Box,
}

#[derive(Clone, Debug, PartialEq)]
pub struct SpecialObject {
    pub kind: SpecialKind,
    /// Bounds assembled by 0x486340 from eight caller-supplied transformed
    /// vertices. The transform producer at 0x475241..0x4752be is separate.
    pub lower: [f32; 3],
    pub upper: [f32; 3],
}

#[derive(Clone, Debug, PartialEq)]
pub enum SceneObject {
    Edge(EdgeObject),
    Special(SpecialObject),
}

impl SceneObject {
    /// The original vtable +4 center callback, storing each component to f32.
    pub fn center(&self) -> [f32; 3] {
        match self {
            Self::Edge(edge) => std::array::from_fn(|axis| {
                ((edge.endpoints[1][axis] as f64 + edge.endpoints[0][axis] as f64) * 0.5) as f32
            }),
            Self::Special(shape) => std::array::from_fn(|axis| {
                ((shape.lower[axis] as f64 + shape.upper[axis] as f64) * 0.5) as f32
            }),
        }
    }

    /// Original vtable +8 writes X/Z only; Y retains caller's value.
    pub fn bounds(&self, mut lower: [f32; 3], mut upper: [f32; 3]) -> ([f32; 3], [f32; 3]) {
        match self {
            Self::Edge(edge) => {
                for axis in [0, 2] {
                    lower[axis] = edge.endpoints[0][axis].min(edge.endpoints[1][axis]);
                    upper[axis] = edge.endpoints[0][axis].max(edge.endpoints[1][axis]);
                }
            }
            Self::Special(shape) => {
                for axis in [0, 2] {
                    lower[axis] = shape.lower[axis];
                    upper[axis] = shape.upper[axis];
                }
            }
        }
        (lower, upper)
    }

    pub fn is_finite(&self) -> bool {
        let points: &[[f32; 3]] = match self {
            Self::Edge(edge) => &edge.endpoints,
            Self::Special(shape) => std::array::from_ref(&shape.lower),
        };
        points.iter().flatten().all(|value| value.is_finite())
            && match self {
                Self::Edge(_) => true,
                Self::Special(shape) => shape.upper.iter().all(|value| value.is_finite()),
            }
    }
}

/// Direct EDG file records in source order, with the original constructor.
/// Successful 0x487e80 skips temporary-tree generation at 0x4880ed. Missing
/// EDG instead takes 0x488590 generation; that fallback is not implemented here.
pub fn load_raw_edg_objects(bytes: &[u8]) -> Result<Vec<SceneObject>> {
    let edges = parse_edg(bytes)?;
    Ok(edges
        .segments
        .into_iter()
        .enumerate()
        .map(|(source_index, segment)| {
            SceneObject::Edge(EdgeObject::from_source(
                u16::from(segment.flags),
                [segment.p1, segment.p2],
                source_index,
            ))
        })
        .collect())
}

/// 0x486340 bounds over the eight vertices supplied to 0x486690/0x486c20.
pub fn special_from_transformed_vertices(
    kind: SpecialKind,
    vertices: [[f32; 3]; 8],
) -> Result<SceneObject> {
    if vertices.iter().flatten().any(|value| !value.is_finite()) {
        return Err("nonfinite special geometry outside proven callback contract".into());
    }
    let lower = std::array::from_fn(|axis| {
        vertices
            .iter()
            .map(|vertex| vertex[axis])
            .reduce(f32::min)
            .unwrap()
    });
    let upper = std::array::from_fn(|axis| {
        vertices
            .iter()
            .map(|vertex| vertex[axis])
            .reduce(f32::max)
            .unwrap()
    });
    Ok(SceneObject::Special(SpecialObject { kind, lower, upper }))
}

/// 0x489cc0 segment intersection in XZ, used by EDG slot +0x10. The
/// source stores query directions, denominator and first parameter as f32;
/// edge directions remain in x87 registers. Endpoint equality is inclusive.
pub fn edge_intersects_segment(edge: &EdgeObject, query: [[f32; 3]; 2]) -> bool {
    let a = query[0];
    let b = query[1];
    let c = edge.endpoints[0];
    let d = edge.endpoints[1];
    let qx = (b[0] as f64 - a[0] as f64) as f32;
    let qz = (b[2] as f64 - a[2] as f64) as f32;
    // The second segment's directions remain in x87 registers; only query
    // directions are stored to f32 at 0x489cdb and 0x489ce5.
    let ex = d[0] as f64 - c[0] as f64;
    let ez = d[2] as f64 - c[2] as f64;
    let unrounded_denominator = qx as f64 * ez - ex * qz as f64;
    let denominator = unrounded_denominator as f32;
    if unrounded_denominator == 0.0 {
        return false;
    }
    let az = (a[2] as f64 - c[2] as f64) as f32;
    let ax = (a[0] as f64 - c[0] as f64) as f32;
    let t = ((az as f64 * ex - ax as f64 * ez) / denominator as f64) as f32;
    if !(0.0..=1.0).contains(&t) {
        return false;
    }
    let u = (az as f64 * qx as f64 - ax as f64 * qz as f64) / denominator as f64;
    (0.0..=1.0).contains(&u)
}
