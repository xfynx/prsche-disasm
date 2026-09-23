//! Road barrier and track boundary collision resolution.

use crate::TopologyEdge;

/// Configuration for vehicle-to-barrier collisions.
#[derive(Debug, Clone, PartialEq)]
pub struct BarrierCollisionConfig {
    pub vehicle_radius: f32,
    pub height_tolerance: f32,
    pub restitution: f32,
    pub wall_friction: f32,
}

impl Default for BarrierCollisionConfig {
    fn default() -> Self {
        Self {
            vehicle_radius: 1.25,
            height_tolerance: 1.6,
            restitution: 0.32,
            wall_friction: 0.28,
        }
    }
}

/// Result of a barrier collision test.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct BarrierHit {
    pub contact_point: [f32; 3],
    pub normal: [f32; 3],
    pub penetration: f32,
    pub edge_flags: u8,
}

/// Resolves collisions against track boundary edges.
pub struct BarrierCollider;

impl BarrierCollider {
    /// Detects contact against a list of topology edges.
    pub fn detect_contact(
        pos: [f32; 3],
        edges: &[TopologyEdge],
        config: &BarrierCollisionConfig,
    ) -> Option<BarrierHit> {
        let px = pos[0];
        let py = pos[1];
        let pz = pos[2];

        let mut closest_hit: Option<BarrierHit> = None;
        let mut min_dist_sq = config.vehicle_radius * config.vehicle_radius;

        for edge in edges {
            let x1 = edge.p1[0];
            let z1 = edge.p1[2];
            let x2 = edge.p2[0];
            let z2 = edge.p2[2];

            let dx = x2 - x1;
            let dz = z2 - z1;
            let len_sq = dx * dx + dz * dz;
            if len_sq < 1e-4 {
                continue;
            }

            let t = (((px - x1) * dx + (pz - z1) * dz) / len_sq).clamp(0.0, 1.0);
            let closest_x = x1 + t * dx;
            let closest_z = z1 + t * dz;
            let closest_y = edge.p1[1] + t * (edge.p2[1] - edge.p1[1]);

            // Vertical tolerance check (layering on bridges/tunnels)
            if (py - closest_y).abs() > config.height_tolerance {
                continue;
            }

            let dist_x = px - closest_x;
            let dist_z = pz - closest_z;
            let dist_sq = dist_x * dist_x + dist_z * dist_z;

            if dist_sq < min_dist_sq && dist_sq > 1e-7 {
                min_dist_sq = dist_sq;
                let dist = dist_sq.sqrt();
                let penetration = config.vehicle_radius - dist;
                let nx = dist_x / dist;
                let nz = dist_z / dist;

                closest_hit = Some(BarrierHit {
                    contact_point: [closest_x, closest_y, closest_z],
                    normal: [nx, 0.0, nz],
                    penetration,
                    edge_flags: edge.flags,
                });
            }
        }

        closest_hit
    }

    /// Resolves barrier collision for a 3D position and velocity vector.
    /// Modifies `pos` and `vel` in place and returns `true` if a collision occurred.
    pub fn resolve_collision(
        pos: &mut [f32; 3],
        vel: &mut [f32; 3],
        edges: &[TopologyEdge],
        config: &BarrierCollisionConfig,
    ) -> bool {
        if let Some(hit) = Self::detect_contact(*pos, edges, config) {
            // Push out along normal
            pos[0] += hit.normal[0] * hit.penetration;
            pos[2] += hit.normal[2] * hit.penetration;

            // Velocity response
            let vn = vel[0] * hit.normal[0] + vel[2] * hit.normal[2];
            if vn < 0.0 {
                // Decompose into normal and tangential components
                let vt_x = vel[0] - vn * hit.normal[0];
                let vt_z = vel[2] - vn * hit.normal[2];

                // Bounce normal with restitution
                let new_vn = -config.restitution * vn;

                // Scrub tangential velocity with wall friction
                let friction_factor = (1.0 - config.wall_friction).max(0.1);
                vel[0] = vt_x * friction_factor + new_vn * hit.normal[0];
                vel[2] = vt_z * friction_factor + new_vn * hit.normal[2];
            }

            true
        } else {
            false
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_barrier_detection_and_resolution() {
        let edge = TopologyEdge {
            flags: 0x10, // barrier flag
            p1: [-10.0, 0.0, 0.0],
            p2: [10.0, 0.0, 0.0],
        };

        let config = BarrierCollisionConfig::default();

        // Vehicle heading into barrier from +Z towards -Z
        let mut pos = [0.0, 0.0, 0.8]; // radius is 1.25m, so penetration = 0.45m
        let mut vel = [0.0, 0.0, -10.0];

        let hit = BarrierCollider::detect_contact(pos, std::slice::from_ref(&edge), &config);
        assert!(hit.is_some());
        let h = hit.unwrap();
        assert!((h.penetration - 0.45).abs() < 1e-3);
        assert!((h.normal[2] - 1.0).abs() < 1e-3); // Normal points toward +Z

        // Resolve
        let collided = BarrierCollider::resolve_collision(&mut pos, &mut vel, &[edge], &config);
        assert!(collided);
        assert!(pos[2] >= 1.25 - 1e-4); // Pushed out beyond radius
        assert!(vel[2] > 0.0); // Bounced back with positive velocity
        assert!(vel[2] < 10.0); // Lost energy via restitution
    }

    #[test]
    fn test_barrier_height_tolerance_separation() {
        let edge = TopologyEdge {
            flags: 0,
            p1: [-10.0, 10.0, 0.0], // elevated bridge at Y = 10
            p2: [10.0, 10.0, 0.0],
        };

        let config = BarrierCollisionConfig::default();

        // Vehicle on lower road at Y = 0
        let pos = [0.0, 0.0, 0.5];
        let hit = BarrierCollider::detect_contact(pos, &[edge], &config);
        assert!(hit.is_none(), "Must not collide with bridge overhead");
    }
}
