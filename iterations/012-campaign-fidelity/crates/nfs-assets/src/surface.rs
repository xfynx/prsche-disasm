//! CPU-only support-surface queries for static `RD*` track articles.
//!
//! `RD*` is selected from the CRP article `Name` as a geometric road-surface
//! hypothesis. The format parser proves the article and its triangles exist;
//! it does not prove NFS5 used this set for collision or tyre physics.

use std::collections::BTreeMap;

use crate::Mesh;

const CELL_SIZE: f32 = 16.0;
const MAX_ABS_COORDINATE: f32 = 1_000_000.0;
const MAX_CELLS_PER_TRIANGLE: i64 = 4096;
const MIN_UP_NORMAL: f32 = 0.01;
// Query coordinates are f32. Permit eight ULPs at the local coordinate scale,
// measured as XZ distance from each projected edge rather than a barycentric ratio.
const EDGE_ULPS: f64 = 8.0;

/// Original CRP identity retained when a triangle is copied before material batching.
#[derive(Debug, Clone, PartialEq, Eq, Hash)]
pub struct RoadTriangleIdentity {
    pub article_name: String,
    pub article_index: usize,
    pub mesh_name: String,
    pub primitive_index: u16,
    pub triangle_index: usize,
}

/// One candidate support triangle in scene coordinates `[x, y, -z]`.
#[derive(Debug, Clone)]
pub struct RoadTriangle {
    pub identity: RoadTriangleIdentity,
    pub positions: [[f32; 3]; 3],
}

/// A valid support contact. `identity` can be used by an audit UI or log.
#[derive(Debug, Clone)]
pub struct SurfaceHit {
    pub height: f32,
    pub normal: [f32; 3],
    pub identity: RoadTriangleIdentity,
}

/// Counts accepted geometry and every input class deliberately rejected by the index.
#[derive(Debug, Clone, Copy, Default, PartialEq, Eq)]
pub struct RoadSurfaceReport {
    pub accepted: usize,
    pub rejected_degenerate: usize,
    pub rejected_vertical: usize,
    pub rejected_non_finite: usize,
    pub rejected_out_of_bounds: usize,
    pub rejected_giant: usize,
}

#[derive(Debug, Clone)]
struct IndexedTriangle {
    source: RoadTriangle,
    normal: [f32; 3],
}

/// A bounded XZ spatial grid for the static `RD*` geometry hypothesis.
#[derive(Debug, Clone, Default)]
pub struct RoadSurface {
    triangles: Vec<IndexedTriangle>,
    grid: BTreeMap<(i32, i32), Vec<usize>>,
    report: RoadSurfaceReport,
}

impl RoadSurface {
    /// Builds a grid while rejecting malformed and impractically large triangles.
    pub fn from_triangles(triangles: impl IntoIterator<Item = RoadTriangle>) -> Self {
        let mut surface = Self::default();
        for triangle in triangles {
            surface.insert(triangle);
        }
        surface
    }

    pub fn report(&self) -> RoadSurfaceReport {
        self.report
    }

    pub fn triangle_count(&self) -> usize {
        self.triangles.len()
    }

    /// Accepted source triangles for a read-only audit. The iterator exposes no grid internals.
    pub fn triangles(
        &self,
    ) -> impl Iterator<Item = (&RoadTriangleIdentity, &[[f32; 3]; 3], [f32; 3])> + '_ {
        self.triangles.iter().map(|triangle| {
            (
                &triangle.source.identity,
                &triangle.source.positions,
                triangle.normal,
            )
        })
    }

    /// Returns the nearest permitted support to `reference_y`, rather than the
    /// globally highest deck. `max_step_up` and `max_drop` are non-negative distances.
    pub fn query(
        &self,
        x: f32,
        z: f32,
        reference_y: f32,
        max_step_up: f32,
        max_drop: f32,
    ) -> Option<SurfaceHit> {
        if ![x, z, reference_y, max_step_up, max_drop]
            .iter()
            .all(|value| value.is_finite())
            || max_step_up < 0.0
            || max_drop < 0.0
        {
            return None;
        }
        let cell = cell_for(x, z)?;
        let mut best: Option<(f32, &IndexedTriangle, f32)> = None;
        for &index in self.grid.get(&cell)? {
            let triangle = &self.triangles[index];
            let Some(height) = height_at(&triangle.source.positions, x, z) else {
                continue;
            };
            if height > reference_y + max_step_up || height < reference_y - max_drop {
                continue;
            }
            let distance = (height - reference_y).abs();
            if match best.as_ref() {
                Some((best_distance, _, _)) => distance < *best_distance,
                None => true,
            } {
                best = Some((distance, triangle, height));
            }
        }
        best.map(|(_, triangle, height)| SurfaceHit {
            height,
            normal: triangle.normal,
            identity: triangle.source.identity.clone(),
        })
    }

    fn insert(&mut self, triangle: RoadTriangle) {
        if triangle
            .positions
            .iter()
            .flatten()
            .any(|value| !value.is_finite())
        {
            self.report.rejected_non_finite += 1;
            return;
        }
        if triangle
            .positions
            .iter()
            .flatten()
            .any(|value| value.abs() > MAX_ABS_COORDINATE)
        {
            self.report.rejected_out_of_bounds += 1;
            return;
        }
        let normal = triangle_normal(triangle.positions);
        let length_sq = dot(normal, normal);
        if length_sq <= 1e-12 {
            self.report.rejected_degenerate += 1;
            return;
        }
        let mut normal = normal.map(|value| value / length_sq.sqrt());
        if normal[1].abs() < MIN_UP_NORMAL {
            self.report.rejected_vertical += 1;
            return;
        }
        if normal[1] < 0.0 {
            normal = normal.map(|value| -value);
        }
        let min_x = triangle
            .positions
            .iter()
            .map(|point| point[0])
            .fold(f32::INFINITY, f32::min);
        let max_x = triangle
            .positions
            .iter()
            .map(|point| point[0])
            .fold(f32::NEG_INFINITY, f32::max);
        let min_z = triangle
            .positions
            .iter()
            .map(|point| point[2])
            .fold(f32::INFINITY, f32::min);
        let max_z = triangle
            .positions
            .iter()
            .map(|point| point[2])
            .fold(f32::NEG_INFINITY, f32::max);
        let Some((min_cell_x, min_cell_z)) = cell_for(min_x, min_z) else {
            self.report.rejected_out_of_bounds += 1;
            return;
        };
        let Some((max_cell_x, max_cell_z)) = cell_for(max_x, max_z) else {
            self.report.rejected_out_of_bounds += 1;
            return;
        };
        let cells = i64::from(max_cell_x - min_cell_x + 1) * i64::from(max_cell_z - min_cell_z + 1);
        if cells > MAX_CELLS_PER_TRIANGLE {
            self.report.rejected_giant += 1;
            return;
        }
        let index = self.triangles.len();
        self.triangles.push(IndexedTriangle {
            source: triangle,
            normal,
        });
        for cell_x in min_cell_x..=max_cell_x {
            for cell_z in min_cell_z..=max_cell_z {
                self.grid.entry((cell_x, cell_z)).or_default().push(index);
            }
        }
        self.report.accepted += 1;
    }
}

pub(crate) fn triangles_from_mesh(
    article_name: &str,
    article_index: usize,
    primitive_index: u16,
    mesh: &Mesh,
) -> Vec<RoadTriangle> {
    mesh.indices
        .as_chunks::<3>()
        .0
        .iter()
        .enumerate()
        .filter_map(|(triangle_index, indices)| {
            let positions = (*indices).map(|index| {
                mesh.vertices
                    .get(index as usize)
                    .map(|vertex| vertex.position)
            });
            Some(RoadTriangle {
                identity: RoadTriangleIdentity {
                    article_name: article_name.into(),
                    article_index,
                    mesh_name: mesh.name.clone(),
                    primitive_index,
                    triangle_index,
                },
                positions: [positions[0]?, positions[1]?, positions[2]?],
            })
        })
        .collect()
}

fn cell_for(x: f32, z: f32) -> Option<(i32, i32)> {
    if !x.is_finite()
        || !z.is_finite()
        || x.abs() > MAX_ABS_COORDINATE
        || z.abs() > MAX_ABS_COORDINATE
    {
        return None;
    }
    Some((
        (x / CELL_SIZE).floor() as i32,
        (z / CELL_SIZE).floor() as i32,
    ))
}

fn triangle_normal(points: [[f32; 3]; 3]) -> [f32; 3] {
    let a = subtract(points[1], points[0]);
    let b = subtract(points[2], points[0]);
    cross(a, b)
}

fn height_at(points: &[[f32; 3]; 3], x: f32, z: f32) -> Option<f32> {
    let a = points[0].map(f64::from);
    let b = points[1].map(f64::from);
    let c = points[2].map(f64::from);
    let x = f64::from(x);
    let z = f64::from(z);
    let denominator = (b[2] - c[2]) * (a[0] - c[0]) + (c[0] - b[0]) * (a[2] - c[2]);
    if denominator.abs() <= f64::EPSILON {
        return None;
    }
    let u = ((b[2] - c[2]) * (x - c[0]) + (c[0] - b[0]) * (z - c[2])) / denominator;
    let v = ((c[2] - a[2]) * (x - c[0]) + (a[0] - c[0]) * (z - c[2])) / denominator;
    let w = 1.0 - u - v;
    let coordinate_scale = a
        .into_iter()
        .chain(b)
        .chain(c)
        .chain([x, z])
        .map(f64::abs)
        .fold(1.0, f64::max);
    let edge_tolerance = EDGE_ULPS * f64::from(f32::EPSILON) * coordinate_scale;
    let denominator = denominator.abs();
    let u_tolerance = edge_tolerance * distance_xz(b, c) / denominator;
    let v_tolerance = edge_tolerance * distance_xz(c, a) / denominator;
    let w_tolerance = edge_tolerance * distance_xz(a, b) / denominator;
    if u < -u_tolerance || v < -v_tolerance || w < -w_tolerance {
        return None;
    }
    Some((u * a[1] + v * b[1] + w * c[1]) as f32)
}

fn distance_xz(a: [f64; 3], b: [f64; 3]) -> f64 {
    (a[0] - b[0]).hypot(a[2] - b[2])
}

fn subtract(a: [f32; 3], b: [f32; 3]) -> [f32; 3] {
    [a[0] - b[0], a[1] - b[1], a[2] - b[2]]
}

fn cross(a: [f32; 3], b: [f32; 3]) -> [f32; 3] {
    [
        a[1] * b[2] - a[2] * b[1],
        a[2] * b[0] - a[0] * b[2],
        a[0] * b[1] - a[1] * b[0],
    ]
}

fn dot(a: [f32; 3], b: [f32; 3]) -> f32 {
    a.into_iter().zip(b).map(|(a, b)| a * b).sum()
}

#[cfg(test)]
mod tests {
    use super::*;

    fn triangle(name: &str, points: [[f32; 3]; 3]) -> RoadTriangle {
        RoadTriangle {
            identity: RoadTriangleIdentity {
                article_name: name.into(),
                article_index: 7,
                mesh_name: format!("{name}#7/0"),
                primitive_index: 0,
                triangle_index: 3,
            },
            positions: points,
        }
    }

    #[test]
    fn returns_incline_height_upward_normal_and_identity() {
        let surface = RoadSurface::from_triangles([triangle(
            "RD0001",
            [[0.0, 0.0, 0.0], [8.0, 4.0, 0.0], [0.0, 0.0, 8.0]],
        )]);
        let hit = surface.query(2.0, 2.0, 0.8, 1.0, 1.0).unwrap();
        assert!((hit.height - 1.0).abs() < 1e-5);
        assert!(hit.normal[1] > 0.89);
        assert_eq!(hit.identity.article_name, "RD0001");
    }

    #[test]
    fn accepts_triangle_edges_and_misses_outside() {
        let surface = RoadSurface::from_triangles([triangle(
            "RD_EDGE",
            [[0.0, 0.0, 0.0], [8.0, 0.0, 0.0], [0.0, 0.0, 8.0]],
        )]);
        assert!(surface.query(4.0, 0.0, 0.0, 0.0, 0.0).is_some());
        assert!(surface.query(6.0, 6.0, 0.0, 1.0, 1.0).is_none());
    }

    #[test]
    fn queries_a_real_world_thin_triangle_at_its_f32_centroid() {
        // monaco3 CRP audit: RD0144C (1 PRIMARY)#408, primitive 0, triangle 3.
        // The projected triangle is thin enough that f32 centroid rounding changes its
        // raw barycentric coordinates substantially; the point is still micrometres
        // from the projected edge at this coordinate scale.
        let points = [
            [-72.82958, -7.735953, 64.55752],
            [-72.45224, -7.582618, 60.22616],
            [-72.9732, -7.794313, 66.20606],
        ];
        let point: [f32; 3] =
            std::array::from_fn(|axis| (points[0][axis] + points[1][axis] + points[2][axis]) / 3.0);
        let surface = RoadSurface::from_triangles([triangle("RD0144C (1 PRIMARY)", points)]);
        let hit = surface
            .query(point[0], point[2], point[1], 0.01, 0.01)
            .unwrap();
        assert!((hit.height - point[1]).abs() <= 0.01);
    }

    #[test]
    fn chooses_nearest_allowed_stacked_deck() {
        let lower = triangle(
            "RD_LOW",
            [[0.0, 0.0, 0.0], [8.0, 0.0, 0.0], [0.0, 0.0, 8.0]],
        );
        let upper = triangle(
            "RD_HIGH",
            [[0.0, 10.0, 0.0], [8.0, 10.0, 0.0], [0.0, 10.0, 8.0]],
        );
        let surface = RoadSurface::from_triangles([lower, upper]);
        assert_eq!(
            surface
                .query(1.0, 1.0, 1.0, 2.0, 2.0)
                .unwrap()
                .identity
                .article_name,
            "RD_LOW"
        );
        assert_eq!(
            surface
                .query(1.0, 1.0, 9.0, 2.0, 2.0)
                .unwrap()
                .identity
                .article_name,
            "RD_HIGH"
        );
        assert!(surface.query(1.0, 1.0, 5.0, 1.0, 1.0).is_none());
    }

    #[test]
    fn rejects_invalid_vertical_and_unbounded_triangles() {
        let degenerate = triangle("RD_DEG", [[0.0, 0.0, 0.0]; 3]);
        let vertical = triangle(
            "RD_WALL",
            [[0.0, 0.0, 0.0], [0.0, 4.0, 0.0], [0.0, 0.0, 4.0]],
        );
        let non_finite = triangle(
            "RD_NAN",
            [[f32::NAN, 0.0, 0.0], [1.0, 0.0, 0.0], [0.0, 0.0, 1.0]],
        );
        let giant = triangle(
            "RD_GIANT",
            [
                [-900_000.0, 0.0, -900_000.0],
                [900_000.0, 0.0, -900_000.0],
                [-900_000.0, 0.0, 900_000.0],
            ],
        );
        let surface = RoadSurface::from_triangles([degenerate, vertical, non_finite, giant]);
        assert_eq!(surface.triangle_count(), 0);
        assert_eq!(
            surface.report(),
            RoadSurfaceReport {
                accepted: 0,
                rejected_degenerate: 1,
                rejected_vertical: 1,
                rejected_non_finite: 1,
                rejected_out_of_bounds: 0,
                rejected_giant: 1,
            }
        );
    }

    #[test]
    fn invalid_query_input_is_a_miss() {
        let surface = RoadSurface::default();
        assert!(surface.query(f32::NAN, 0.0, 0.0, 1.0, 1.0).is_none());
        assert!(surface.query(0.0, 0.0, 0.0, -1.0, 1.0).is_none());
    }
}
