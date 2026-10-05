//! Bounded owner-side type-1 support lookup in Porsche.exe.
//! SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
//! 0x474060 owns the polygon cache; 0x473240 owns the node cache. Plane
//! callbacks are 0x474320, quad 0x485b50 and triangle 0x485f90.

use super::original_support::{SupportPolygon, SupportVertices};
use super::original_support_tree::SupportTree;
use nfs_formats::Result;

#[derive(Clone, Copy, Debug, PartialEq)]
pub struct SupportPlaneHit {
    pub polygon: usize,
    /// Polygon slot +0x18, index zero; first source vertex in original axes.
    pub point: [f32; 3],
    /// The owner's cached +0x0c normal after 0x474320.
    pub normal: [f32; 3],
    pub height: f32,
}

#[derive(Clone, Debug, Default, PartialEq)]
pub struct OriginalSupportOwner {
    /// Original owner+0x28. This is distinct from the spatial node cache.
    pub polygon: Option<usize>,
    /// Original owner+0x2c.
    pub node: Option<usize>,
}

fn subtract(a: [f32; 3], b: [f32; 3]) -> [f32; 3] {
    std::array::from_fn(|i| (a[i] as f64 - b[i] as f64) as f32)
}

fn normal(polygon: &SupportPolygon) -> [f32; 3] {
    let (a, b) = match &polygon.vertices {
        SupportVertices::Triangle(v) => (subtract(v[1], v[0]), subtract(v[0], v[2])),
        SupportVertices::Quad(v) => {
            // 0x485b50 averages opposite edge differences, storing each f32.
            let a = std::array::from_fn(|i| {
                (((v[2][i] as f64 - v[3][i] as f64) + (v[1][i] as f64 - v[0][i] as f64)) * 0.5)
                    as f32
            });
            let b = std::array::from_fn(|i| {
                (((v[0][i] as f64 - v[3][i] as f64) + (v[1][i] as f64 - v[2][i] as f64)) * 0.5)
                    as f32
            });
            (a, b)
        }
    };
    let (a, b) = if polygon.winding_8 { (a, b) } else { (b, a) };
    let mut cross = [
        (a[1] as f64 * b[2] as f64 - a[2] as f64 * b[1] as f64) as f32,
        (a[2] as f64 * b[0] as f64 - a[0] as f64 * b[2] as f64) as f32,
        (a[0] as f64 * b[1] as f64 - a[1] as f64 * b[0] as f64) as f32,
    ];
    let length = ((cross[0] as f64 * cross[0] as f64)
        + (cross[1] as f64 * cross[1] as f64)
        + (cross[2] as f64 * cross[2] as f64))
        .sqrt();
    if length >= 0.01 {
        for component in &mut cross {
            *component = (*component as f64 / length) as f32;
        }
        if cross[1] < f32::from_bits(0x3f7ff972) {
            return cross;
        }
    }
    cross[1] = f32::from_bits(0x3f7ff972);
    cross
}

impl OriginalSupportOwner {
    /// `reuse=true` is the 0x474060 caller flag: retain a cached polygon when
    /// its XZ containment callback accepts this point. Otherwise run 0x473240.
    /// A zero/nonfinite normal Y cannot supply a finite height in the bounded
    /// portable API; the original caller divides by that value without a guard.
    pub fn select(
        &mut self,
        tree: &SupportTree,
        polygons: &[SupportPolygon],
        point: [f32; 3],
        reuse: bool,
    ) -> Result<Option<SupportPlaneHit>> {
        if point.iter().any(|value| !value.is_finite()) {
            return Err("nonfinite support owner query outside proven contract".into());
        }
        if self.polygon.is_some_and(|index| index >= polygons.len()) {
            return Err("cached polygon outside support arena".into());
        }
        let retained = if reuse {
            self.polygon
                .and_then(|index| polygons.get(index).map(|p| (index, p)))
                .filter(|(_, polygon)| polygon.contains_xz(point))
                .map(|(index, _)| index)
        } else {
            None
        };
        let index = if let Some(index) = retained {
            Some(index)
        } else {
            let (index, node) = tree.query(polygons, point, self.node)?;
            self.node = Some(node);
            self.polygon = index;
            index
        };
        let Some(index) = index else { return Ok(None) };
        let polygon = polygons
            .get(index)
            .ok_or("cached polygon outside support arena")?;
        let base = match &polygon.vertices {
            SupportVertices::Triangle(v) => v[0],
            SupportVertices::Quad(v) => v[0],
        };
        let normal = normal(polygon);
        if !normal[1].is_finite() || normal[1] == 0.0 {
            return Ok(None);
        }
        let height = (base[1] as f64
            - ((point[0] as f64 - base[0] as f64) * normal[0] as f64
                + (point[2] as f64 - base[2] as f64) * normal[2] as f64)
                / normal[1] as f64) as f32;
        if !height.is_finite() {
            return Ok(None);
        }
        Ok(Some(SupportPlaneHit {
            polygon: index,
            point: base,
            normal,
            height,
        }))
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn stacked_support_and_cached_polygon() {
        let vertices =
            |y| SupportVertices::Triangle([[0.0, y, 0.0], [0.0, y, 10.0], [10.0, y, 0.0]]);
        let polygons = vec![
            SupportPolygon::new(vertices(0.0), 1),
            SupportPolygon::new(vertices(10.0), 1),
        ];
        let mut tree = SupportTree::original_scene();
        tree.insert(&polygons, 0).unwrap();
        tree.insert(&polygons, 1).unwrap();
        let mut owner = OriginalSupportOwner::default();
        let first = owner
            .select(&tree, &polygons, [1.0, 1.0, 1.0], true)
            .unwrap()
            .unwrap();
        assert_eq!(first.polygon, 0);
        assert_eq!(first.height, 0.0);
        let retained = owner
            .select(&tree, &polygons, [1.0, 9.0, 1.0], true)
            .unwrap()
            .unwrap();
        assert_eq!(retained.polygon, 0);
        let fresh = owner
            .select(&tree, &polygons, [1.0, 9.0, 1.0], false)
            .unwrap()
            .unwrap();
        assert_eq!(fresh.polygon, 1);
        assert_eq!(fresh.height, 10.0);
    }
}
