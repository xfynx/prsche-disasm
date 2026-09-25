//! Track course, checkpoint gates, lap verification, and wrong-way detection.

use nfs_formats::SplinePoint;

/// A checkpoint gate spanning the track width.
#[derive(Debug, Clone, PartialEq)]
pub struct CheckpointGate {
    pub index: usize,
    pub center: [f32; 3],
    pub forward: [f32; 3],
    pub right: [f32; 3],
    pub half_width: f32,
    pub distance_along_course: f32,
}

impl CheckpointGate {
    /// Tests if a vehicle moving from `p_prev` to `p_curr` crossed this gate forward.
    /// Returns:
    /// - `Some(true)` if crossed forward within bounds
    /// - `Some(false)` if crossed in the reverse direction
    /// - `None` if no crossing occurred
    pub fn test_crossing(&self, p_prev: [f32; 3], p_curr: [f32; 3]) -> Option<bool> {
        let v_prev = [
            p_prev[0] - self.center[0],
            p_prev[1] - self.center[1],
            p_prev[2] - self.center[2],
        ];
        let v_curr = [
            p_curr[0] - self.center[0],
            p_curr[1] - self.center[1],
            p_curr[2] - self.center[2],
        ];

        // Height check (avoid triggers from bridges above/below)
        if v_curr[1].abs() > 6.0 && v_prev[1].abs() > 6.0 {
            return None;
        }

        // Distance along forward normal
        let d_prev =
            v_prev[0] * self.forward[0] + v_prev[1] * self.forward[1] + v_prev[2] * self.forward[2];
        let d_curr =
            v_curr[0] * self.forward[0] + v_curr[1] * self.forward[1] + v_curr[2] * self.forward[2];

        // Check if sign flipped across the gate plane
        let crossed_forward = d_prev <= 0.0 && d_curr > 0.0;
        let crossed_reverse = d_prev >= 0.0 && d_curr < 0.0;

        if !crossed_forward && !crossed_reverse {
            return None;
        }

        // Lateral check: estimate lateral offset at crossing plane
        let t = if (d_curr - d_prev).abs() > 1e-5 {
            (-d_prev) / (d_curr - d_prev)
        } else {
            0.5
        };
        let p_cross = [
            p_prev[0] + t * (p_curr[0] - p_prev[0]),
            p_prev[1] + t * (p_curr[1] - p_prev[1]),
            p_prev[2] + t * (p_curr[2] - p_prev[2]),
        ];
        let lat_offset = (p_cross[0] - self.center[0]) * self.right[0]
            + (p_cross[1] - self.center[1]) * self.right[1]
            + (p_cross[2] - self.center[2]) * self.right[2];

        if lat_offset.abs() <= self.half_width + 8.0 {
            Some(crossed_forward)
        } else {
            None
        }
    }
}

/// A waypoint along the course centerline.
#[derive(Debug, Clone, PartialEq)]
pub struct CourseWaypoint {
    pub position: [f32; 3],
    pub forward: [f32; 3],
    pub distance_along_course: f32,
    pub curvature: f32,
    pub target_speed: f32,
}

/// Course geometry, racing line, checkpoints, and lap verification.
#[derive(Debug, Clone, PartialEq)]
pub struct TrackCourse {
    pub waypoints: Vec<CourseWaypoint>,
    pub checkpoints: Vec<CheckpointGate>,
    pub total_length: f32,
    pub is_circuit: bool,
}

impl TrackCourse {
    /// Builds a course from 2D `.lsp` spline points with optional surface height sampling.
    pub fn from_spline_points(
        points: &[SplinePoint],
        is_circuit: bool,
        elevation_fn: impl Fn(f32, f32) -> f32,
    ) -> Result<Self, String> {
        if points.len() < 3 {
            return Err("spline path must have at least 3 points".into());
        }

        let n = points.len();
        let mut raw_positions = Vec::with_capacity(n);

        // Convert .lsp (x, z) to scene coordinates [x, y, -z]
        for p in points {
            let x = p.x;
            let z = -p.z;
            let y = elevation_fn(x, z);
            raw_positions.push([x, y, z]);
        }

        let mut waypoints = Vec::with_capacity(n);
        let mut cumulative_dist = 0.0f32;

        for i in 0..n {
            let p_curr = raw_positions[i];
            let p_next = if i + 1 < n {
                raw_positions[i + 1]
            } else if is_circuit {
                raw_positions[0]
            } else {
                raw_positions[i]
            };

            let p_prev = if i > 0 {
                raw_positions[i - 1]
            } else if is_circuit {
                raw_positions[n - 1]
            } else {
                raw_positions[0]
            };

            // Tangent forward direction
            let dx = p_next[0] - p_curr[0];
            let dy = p_next[1] - p_curr[1];
            let dz = p_next[2] - p_curr[2];
            let seg_len = (dx * dx + dy * dy + dz * dz).sqrt();

            let (fwd_x, fwd_y, fwd_z) = if seg_len > 1e-4 {
                (dx / seg_len, dy / seg_len, dz / seg_len)
            } else {
                (0.0, 0.0, -1.0)
            };

            // Estimate local road curvature (angle change / segment length)
            let v1 = [p_curr[0] - p_prev[0], p_curr[2] - p_prev[2]];
            let v2 = [p_next[0] - p_curr[0], p_next[2] - p_curr[2]];
            let l1 = (v1[0] * v1[0] + v1[1] * v1[1]).sqrt().max(1e-3);
            let l2 = (v2[0] * v2[0] + v2[1] * v2[1]).sqrt().max(1e-3);
            let dot = (v1[0] * v2[0] + v1[1] * v2[1]) / (l1 * l2);
            let angle_change = dot.clamp(-1.0, 1.0).acos();
            let curvature = angle_change / ((l1 + l2) * 0.5);

            // Suggested speed: v = sqrt(a_lat / curvature), clamped between 15 m/s (54 km/h) and 70 m/s (252 km/h)
            let a_lat_budget = 8.5; // m/s^2
            let target_speed = if curvature > 0.001 {
                (a_lat_budget / curvature).sqrt().clamp(15.0, 70.0)
            } else {
                70.0
            };

            waypoints.push(CourseWaypoint {
                position: p_curr,
                forward: [fwd_x, fwd_y, fwd_z],
                distance_along_course: cumulative_dist,
                curvature,
                target_speed,
            });

            cumulative_dist += seg_len;
        }

        let total_length = cumulative_dist;

        // Generate checkpoints: Start/Finish at 0, plus evenly spaced intermediate gates
        let checkpoint_count = if is_circuit {
            (n / 25).clamp(4, 12)
        } else {
            (n / 25).clamp(4, 16)
        };

        let mut checkpoints = Vec::with_capacity(checkpoint_count);
        let stride = n / checkpoint_count;

        for (gate_idx, cp_i) in (0..n).step_by(stride).take(checkpoint_count).enumerate() {
            let wp = &waypoints[cp_i];
            // Right-hand horizontal vector: forward cross [0, 1, 0]
            let rx = -wp.forward[2];
            let ry = 0.0;
            let rz = wp.forward[0];
            let r_len = (rx * rx + rz * rz).sqrt().max(1e-4);

            checkpoints.push(CheckpointGate {
                index: gate_idx,
                center: wp.position,
                forward: wp.forward,
                right: [rx / r_len, ry, rz / r_len],
                half_width: 14.0, // typical 2-lane road half width with shoulders
                distance_along_course: wp.distance_along_course,
            });
        }

        Ok(Self {
            waypoints,
            checkpoints,
            total_length,
            is_circuit,
        })
    }

    /// Finds the closest waypoint index and distance to that waypoint.
    pub fn find_closest_waypoint(&self, pos: [f32; 3]) -> (usize, f32) {
        let mut min_dist_sq = f32::INFINITY;
        let mut closest_idx = 0;

        for (i, wp) in self.waypoints.iter().enumerate() {
            let dx = pos[0] - wp.position[0];
            let dy = pos[1] - wp.position[1];
            let dz = pos[2] - wp.position[2];
            let dist_sq = dx * dx + dy * dy + dz * dz;
            if dist_sq < min_dist_sq {
                min_dist_sq = dist_sq;
                closest_idx = i;
            }
        }

        (closest_idx, min_dist_sq.sqrt())
    }

    /// Calculates distance along the course for a world position.
    pub fn distance_along_course(&self, pos: [f32; 3]) -> f32 {
        if self.waypoints.is_empty() {
            return 0.0;
        }

        let (idx, _) = self.find_closest_waypoint(pos);
        let wp = &self.waypoints[idx];

        // Project displacement from waypoint onto track forward tangent
        let dx = pos[0] - wp.position[0];
        let dy = pos[1] - wp.position[1];
        let dz = pos[2] - wp.position[2];
        let proj = dx * wp.forward[0] + dy * wp.forward[1] + dz * wp.forward[2];

        (wp.distance_along_course + proj).clamp(0.0, self.total_length)
    }

    /// Returns true if the vehicle's heading is opposed to the track forward tangent.
    pub fn is_wrong_way(&self, pos: [f32; 3], vehicle_forward: [f32; 3]) -> bool {
        if self.waypoints.is_empty() {
            return false;
        }

        let (idx, _) = self.find_closest_waypoint(pos);
        let track_fwd = self.waypoints[idx].forward;

        let dot = vehicle_forward[0] * track_fwd[0]
            + vehicle_forward[1] * track_fwd[1]
            + vehicle_forward[2] * track_fwd[2];

        // Heading angle > 115 degrees from course tangent
        dot < -0.42
    }
}

/// Tracks sequential checkpoint progression for a vehicle to prevent lap skipping.
#[derive(Debug, Clone, PartialEq)]
pub struct CourseProgressTracker {
    pub next_checkpoint: usize,
    pub checkpoints_visited_this_lap: usize,
    pub is_wrong_way: bool,
    pub wrong_way_timer: f32,
    pub last_pos: [f32; 3],
}

impl CourseProgressTracker {
    /// Creates a tracker waiting for the first gate (or start/finish line).
    pub fn new(initial_pos: [f32; 3]) -> Self {
        Self {
            next_checkpoint: 1, // Start by heading towards checkpoint 1
            checkpoints_visited_this_lap: 0,
            is_wrong_way: false,
            wrong_way_timer: 0.0,
            last_pos: initial_pos,
        }
    }

    /// Updates tracker with current position and vehicle forward vector.
    /// Returns:
    /// - `Some(true)` if a valid lap was just completed at the Start/Finish line
    /// - `Some(false)` if an intermediate checkpoint was crossed
    /// - `None` if no checkpoint was crossed
    pub fn update(
        &mut self,
        curr_pos: [f32; 3],
        vehicle_forward: [f32; 3],
        course: &TrackCourse,
        dt: f32,
    ) -> Option<bool> {
        if course.checkpoints.is_empty() {
            self.last_pos = curr_pos;
            return None;
        }

        let wrong_way_now = course.is_wrong_way(curr_pos, vehicle_forward);
        if wrong_way_now {
            self.wrong_way_timer += dt;
            if self.wrong_way_timer > 0.8 {
                self.is_wrong_way = true;
            }
        } else {
            self.wrong_way_timer = (self.wrong_way_timer - dt * 2.0).max(0.0);
            if self.wrong_way_timer <= 0.0 {
                self.is_wrong_way = false;
            }
        }

        let target_cp_idx = self.next_checkpoint;
        let gate = &course.checkpoints[target_cp_idx];

        let crossing = gate.test_crossing(self.last_pos, curr_pos);
        self.last_pos = curr_pos;

        if let Some(true) = crossing {
            // Forward crossing of expected checkpoint
            self.checkpoints_visited_this_lap += 1;
            let total_cp = course.checkpoints.len();

            if target_cp_idx == 0 {
                // Crossed Start/Finish line: verify that majority of checkpoints were visited
                if self.checkpoints_visited_this_lap >= total_cp.saturating_sub(1) {
                    self.checkpoints_visited_this_lap = 0;
                    self.next_checkpoint = 1;
                    return Some(true); // Lap completed!
                }
            } else {
                self.next_checkpoint = (target_cp_idx + 1) % total_cp;
                return Some(false); // Intermediate checkpoint crossed
            }
        }

        None
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_gate_crossing_detection() {
        let gate = CheckpointGate {
            index: 0,
            center: [0.0, 0.0, 0.0],
            forward: [0.0, 0.0, -1.0], // Driving in -Z direction
            right: [1.0, 0.0, 0.0],
            half_width: 10.0,
            distance_along_course: 0.0,
        };

        // Forward crossing: from +Z to -Z
        let p_prev = [0.0, 0.0, 2.0];
        let p_curr = [0.0, 0.0, -2.0];
        assert_eq!(gate.test_crossing(p_prev, p_curr), Some(true));

        // Reverse crossing: from -Z to +Z
        assert_eq!(gate.test_crossing(p_curr, p_prev), Some(false));

        // Out of lateral bounds (x = 25m while half_width = 10m)
        let p_wide_prev = [25.0, 0.0, 2.0];
        let p_wide_curr = [25.0, 0.0, -2.0];
        assert_eq!(gate.test_crossing(p_wide_prev, p_wide_curr), None);

        // Height mismatch (y = 15m, e.g. elevated bridge)
        let p_high_prev = [0.0, 15.0, 2.0];
        let p_high_curr = [0.0, 15.0, -2.0];
        assert_eq!(gate.test_crossing(p_high_prev, p_high_curr), None);
    }

    #[test]
    fn test_circular_course_creation_and_lap_completion() {
        // Construct a circular ring of 40 points
        let radius = 100.0f32;
        let mut spline_pts = Vec::new();
        for i in 0..40 {
            let angle = (i as f32 / 40.0) * std::f32::consts::TAU;
            let x = radius * angle.cos();
            let z = radius * angle.sin();
            spline_pts.push(SplinePoint { x, z });
        }

        let course = TrackCourse::from_spline_points(&spline_pts, true, |_, _| 0.0).unwrap();
        assert!(course.is_circuit);
        assert!(course.total_length > 600.0);
        assert!(!course.checkpoints.is_empty());

        let mut tracker = CourseProgressTracker::new(course.checkpoints[0].center);

        // Step through each checkpoint in sequence
        let total_cp = course.checkpoints.len();
        for step_idx in 1..total_cp {
            let gate = &course.checkpoints[step_idx];
            let p_before = [
                gate.center[0] - gate.forward[0] * 1.0,
                gate.center[1],
                gate.center[2] - gate.forward[2] * 1.0,
            ];
            let p_after = [
                gate.center[0] + gate.forward[0] * 1.0,
                gate.center[1],
                gate.center[2] + gate.forward[2] * 1.0,
            ];

            tracker.last_pos = p_before;
            let res = tracker.update(p_after, gate.forward, &course, 0.1);
            assert_eq!(
                res,
                Some(false),
                "Checkpoint {step_idx} should trigger intermediate crossing"
            );
        }

        // Now cross Start/Finish line (gate 0)
        let gate0 = &course.checkpoints[0];
        let p0_before = [
            gate0.center[0] - gate0.forward[0] * 1.0,
            gate0.center[1],
            gate0.center[2] - gate0.forward[2] * 1.0,
        ];
        let p0_after = [
            gate0.center[0] + gate0.forward[0] * 1.0,
            gate0.center[1],
            gate0.center[2] + gate0.forward[2] * 1.0,
        ];

        tracker.last_pos = p0_before;
        let lap_res = tracker.update(p0_after, gate0.forward, &course, 0.1);
        assert_eq!(
            lap_res,
            Some(true),
            "Gate 0 crossing must trigger lap completion"
        );
    }

    #[test]
    fn test_wrong_way_detection() {
        let mut spline_pts = Vec::new();
        // Straight line heading in -Z (forward = [0, 0, -1])
        for z in [0.0, 10.0, 20.0, 30.0] {
            spline_pts.push(SplinePoint { x: 0.0, z });
        }

        let course = TrackCourse::from_spline_points(&spline_pts, false, |_, _| 0.0).unwrap();

        // Moving forward in -Z direction -> Not wrong way
        let fwd = [0.0, 0.0, -1.0];
        assert!(!course.is_wrong_way([0.0, 0.0, -15.0], fwd));

        // Moving backward in +Z direction -> Wrong way
        let bwd = [0.0, 0.0, 1.0];
        assert!(course.is_wrong_way([0.0, 0.0, -15.0], bwd));
    }
}
