//! Reconstructed chassis contacts against finite road triangles.
//! These bounds and coefficients are an adapter, not recovered NFS5 collision data.

use glam::{Quat, Vec3};

use super::rigid_body::RigidBody;
use crate::surface::RoadSurface;

const SKIN: f32 = 0.002;
const MAX_RECOVERY: f32 = 0.12;
const FRICTION: f32 = 0.55;

/// Box in body coordinates. The selected model can replace the fallback bounds.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct ChassisBounds {
    pub min: Vec3,
    pub max: Vec3,
}

impl ChassisBounds {
    pub fn from_model(bounds: [[f32; 3]; 2]) -> Result<Self, String> {
        let min = Vec3::from_array(bounds[0]);
        let max = Vec3::from_array(bounds[1]);
        let extent = max - min;
        if !min.is_finite()
            || !max.is_finite()
            || extent.min_element() <= 0.05
            || extent.x > 3.5
            || extent.y > 3.0
            || extent.z > 7.0
        {
            return Err("Invalid finite body-local chassis bounds".into());
        }
        Ok(Self { min, max })
    }

    pub(super) fn reconstructed(width: f32, length: f32) -> Self {
        Self {
            min: Vec3::new(-width * 0.46, -0.23, -length * 0.47),
            max: Vec3::new(width * 0.46, 1.05, length * 0.47),
        }
    }

    fn corners(self) -> [Vec3; 8] {
        let (lo, hi) = (self.min, self.max);
        [
            Vec3::new(lo.x, lo.y, lo.z),
            Vec3::new(hi.x, lo.y, lo.z),
            Vec3::new(lo.x, lo.y, hi.z),
            Vec3::new(hi.x, lo.y, hi.z),
            Vec3::new(lo.x, hi.y, lo.z),
            Vec3::new(hi.x, hi.y, lo.z),
            Vec3::new(lo.x, hi.y, hi.z),
            Vec3::new(hi.x, hi.y, hi.z),
        ]
    }
}

fn effective_mass(body: &RigidBody, r: Vec3, direction: Vec3) -> f32 {
    let torque_body = body.orientation.inverse() * r.cross(direction);
    let angular_world = body.orientation * (body.inv_inertia * torque_body);
    body.inv_mass + direction.dot(angular_world.cross(r))
}

fn apply_impulse(body: &mut RigidBody, r: Vec3, impulse: Vec3) {
    body.linear_velocity += impulse * body.inv_mass;
    body.angular_velocity += body.inv_inertia * (body.orientation.inverse() * r.cross(impulse));
}

/// Resolve the current swept corner contacts. The previous pose limits which
/// deck is reachable; `Some(surface)` misses never become an implicit y=0 plane.
pub(super) fn resolve_chassis_ground(
    body: &mut RigidBody,
    bounds: ChassisBounds,
    surface: Option<&RoadSurface>,
    previous_position: Vec3,
    previous_orientation: Quat,
    dt: f32,
) {
    if dt <= 0.0 || !dt.is_finite() {
        return;
    }
    for corner in bounds.corners() {
        let previous = previous_position + previous_orientation * corner;
        let current = body.to_world_pos(corner);
        let allowed_up = (previous.y - current.y).max(0.0) + MAX_RECOVERY;
        let (height, normal) = match surface {
            Some(surface) => {
                let Some(hit) = surface.query(current.x, current.z, current.y, allowed_up, SKIN)
                else {
                    continue;
                };
                (hit.height, Vec3::from_array(hit.normal))
            }
            // `None` is the explicit flat-road calibration fixture used by the
            // suspension and CPU tests. A present but empty surface stays empty.
            None if current.y <= SKIN && -current.y <= allowed_up => (0.0, Vec3::Y),
            None => continue,
        };
        let depth = height - current.y;
        if depth < -SKIN {
            continue;
        }
        // A one-sided road deck is reachable only from above or from a bounded
        // overlap carried into this substep. This excludes a distant upper deck.
        if previous.y + MAX_RECOVERY < height {
            continue;
        }
        let r = current - body.world_com();
        let normal_speed = body.point_velocity(current).dot(normal);
        let denominator = effective_mass(body, r, normal);
        if denominator <= 0.0 {
            continue;
        }
        // Impulses stop closing speed. Position correction below is separate,
        // so an impact does not turn penetration depth into launch velocity.
        let impulse_n = (-normal_speed).max(0.0) / denominator;
        if impulse_n > 0.0 {
            apply_impulse(body, r, normal * impulse_n);
            let tangent =
                body.point_velocity(current) - normal * body.point_velocity(current).dot(normal);
            let tangent_speed = tangent.length();
            if tangent_speed > 1e-5 {
                let direction = tangent / tangent_speed;
                let denominator_t = effective_mass(body, r, direction);
                if denominator_t > 0.0 {
                    let impulse_t = (tangent_speed / denominator_t).min(FRICTION * impulse_n);
                    apply_impulse(body, r, -direction * impulse_t);
                }
            }
        }
        // Resolve this reachable corner completely. Partial correction can
        // leave it below the next substep's permitted recovery depth, losing
        // contact permanently after a fast roof impact. On a slope, vertical
        // depth times normal.y is the signed distance to the triangle plane.
        if depth > 0.0 {
            body.position += normal * depth * normal.y;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::surface::{RoadTriangle, RoadTriangleIdentity};

    fn road(y: f32, half: f32) -> RoadSurface {
        let p = [
            [-half, y, -half],
            [half, y, -half],
            [half, y, half],
            [-half, y, half],
        ];
        RoadSurface::from_triangles([[0, 1, 2], [0, 2, 3]].into_iter().enumerate().map(
            |(i, triangle)| RoadTriangle {
                identity: RoadTriangleIdentity {
                    article_name: "test".into(),
                    article_index: 0,
                    mesh_name: "road".into(),
                    primitive_index: 0,
                    triangle_index: i,
                },
                positions: triangle.map(|j| p[j]),
            },
        ))
    }

    fn body() -> RigidBody {
        RigidBody::new(1000.0, 1.8, 1.3, 4.2, Vec3::ZERO)
    }
    fn bounds() -> ChassisBounds {
        ChassisBounds::reconstructed(1.8, 4.2)
    }

    #[test]
    fn inverted_roof_comes_to_rest_on_finite_road() {
        let surface = road(0.0, 10.0);
        let mut b = body();
        b.position.y = 1.4;
        b.orientation = Quat::from_rotation_z(std::f32::consts::PI);
        for _ in 0..720 {
            let old_position = b.position;
            let old_orientation = b.orientation;
            b.integrate(1.0 / 240.0, Vec3::new(0.0, -9.80665, 0.0));
            resolve_chassis_ground(
                &mut b,
                bounds(),
                Some(&surface),
                old_position,
                old_orientation,
                1.0 / 240.0,
            );
        }
        assert!(
            b.position.y > 1.0,
            "roof passed through road: {}",
            b.position.y
        );
        assert!(b.position.y < 1.3, "roof did not settle: {}", b.position.y);
        assert!(
            b.linear_velocity.y.abs() < 0.3,
            "roof vertical velocity: {:?}",
            b.linear_velocity
        );
    }

    #[test]
    fn rolled_side_stays_above_the_road() {
        let surface = road(0.0, 10.0);
        let mut b = body();
        b.position.y = 1.3;
        b.orientation = Quat::from_rotation_z(std::f32::consts::FRAC_PI_2);
        for _ in 0..720 {
            let old_position = b.position;
            let old_orientation = b.orientation;
            b.integrate(1.0 / 240.0, Vec3::new(0.0, -9.80665, 0.0));
            resolve_chassis_ground(
                &mut b,
                bounds(),
                Some(&surface),
                old_position,
                old_orientation,
                1.0 / 240.0,
            );
        }
        let lowest_corner = bounds()
            .corners()
            .into_iter()
            .map(|point| b.to_world_pos(point).y)
            .fold(f32::INFINITY, f32::min);
        assert!(lowest_corner > -0.05, "rolled body sank: {lowest_corner}");
        assert!(
            b.linear_velocity.y.abs() < 0.3,
            "side vertical velocity: {:?}",
            b.linear_velocity
        );
    }

    #[test]
    fn fast_rotating_roof_impact_keeps_all_corners_above_road() {
        let surface = road(0.0, 20.0);
        let mut b = body();
        b.position.y = 2.0;
        b.orientation = Quat::from_rotation_z(std::f32::consts::PI - 0.2);
        b.linear_velocity.y = -20.0;
        b.angular_velocity.z = 1.5;
        for step in 0..720 {
            let old_position = b.position;
            let old_orientation = b.orientation;
            b.integrate(1.0 / 240.0, Vec3::new(0.0, -9.80665, 0.0));
            resolve_chassis_ground(
                &mut b,
                bounds(),
                Some(&surface),
                old_position,
                old_orientation,
                1.0 / 240.0,
            );
            let lowest = bounds()
                .corners()
                .into_iter()
                .map(|point| b.to_world_pos(point).y)
                .fold(f32::INFINITY, f32::min);
            assert!(lowest > -0.15, "roof tunneled at step {step}: {lowest}");
        }
        assert!(
            b.linear_velocity.y.abs() < 0.5,
            "impact vertical velocity: {:?}",
            b.linear_velocity
        );
    }

    #[test]
    fn finite_edge_and_lower_deck_do_not_catch_airborne_body() {
        let surface = road(-2.0, 2.0);
        let mut b = body();
        b.position = Vec3::new(5.0, 0.1, 0.0);
        b.linear_velocity.y = -3.0;
        let old = b.position;
        b.integrate(1.0 / 240.0, Vec3::new(0.0, -9.80665, 0.0));
        let orientation = b.orientation;
        resolve_chassis_ground(
            &mut b,
            bounds(),
            Some(&surface),
            old,
            orientation,
            1.0 / 240.0,
        );
        assert!(b.linear_velocity.y < -3.0);
        b.position.x = 0.0;
        b.position.y = 0.0;
        let old = b.position;
        let orientation = b.orientation;
        resolve_chassis_ground(
            &mut b,
            bounds(),
            Some(&surface),
            old,
            orientation,
            1.0 / 240.0,
        );
        assert_eq!(
            b.position, old,
            "lower deck pulled chassis through bridge gap"
        );

        let upper_deck = road(2.0, 2.0);
        b.linear_velocity.y = -1.0;
        resolve_chassis_ground(
            &mut b,
            bounds(),
            Some(&upper_deck),
            old,
            orientation,
            1.0 / 240.0,
        );
        assert_eq!(b.position, old, "upper deck caught the roof from below");
    }
}
