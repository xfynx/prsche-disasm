//! Recovered shape-1 trigger predicate and ordered scenario progression.
//! Full mission result rules and vehicle bounds/origin equivalence remain under audit.

use crate::ScenarioGate;
use glam::Vec3;

/// Explicit inputs to the EXE predicate, independent of the physics backend.
#[derive(Debug, Clone, Copy)]
pub struct TriggerVehicle {
    pub position: Vec3,
    pub forward: Vec3,
    pub right: Vec3,
    pub up: Vec3,
    pub half_extents: Vec3,
    pub velocity: Vec3,
    /// Original resource flag +0x518; only set when that flag is known.
    pub expanded: bool,
}

impl TriggerVehicle {
    /// 0x499946..0x499a4d. These are current chassis diagonals, not a motion sweep.
    pub fn diagonals(&self) -> [[Vec3; 2]; 2] {
        let center = self.position - self.up * self.half_extents.y;
        let length = self.forward * (0.7 * self.half_extents.z);
        let width = self.right * (0.9 * self.half_extents.x);
        let mut pairs = [
            [center + length - width, center - length + width],
            [center + length + width, center - length - width],
        ];
        if self.expanded {
            for [a, b] in &mut pairs {
                // Preserve the original sequential in-place add/sub operations.
                *b += *b - *a;
                *a += *a - *b;
            }
        }
        pairs
    }
}

/// Original selector matches FourCC and source X/Z, not the instance index.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct PropTarget {
    pub fourcc: u32,
    pub position: [f32; 3],
}

#[derive(Debug, Clone)]
pub struct ScenarioProp {
    pub target: PropTarget,
    pub triggerable: bool,
}

/// EXE 0x483070: normalize and raise all triggerable instances.
pub fn hide_triggerable_props(props: &mut [ScenarioProp]) {
    for prop in props.iter_mut().filter(|p| p.triggerable) {
        let y = &mut prop.target.position[1];
        if *y > 8000.0 {
            *y -= 10000.0;
        }
        if *y <= 8000.0 {
            *y += 10000.0;
        }
    }
}

/// EXE 0x482f70: hide the group, then lower all exact X/Z/tag matches.
pub fn select_triggerable_prop(props: &mut [ScenarioProp], target: PropTarget) {
    hide_triggerable_props(props);
    for prop in props.iter_mut().filter(|p| p.triggerable) {
        if prop.target.fourcc == target.fourcc
            && prop.target.position[0] == target.position[0]
            && prop.target.position[2] == target.position[2]
            && prop.target.position[1] > 8000.0
        {
            prop.target.position[1] -= 10000.0;
        }
    }
}

#[derive(Debug, Clone)]
pub struct ScenarioProgress {
    gates: Vec<ScenarioGate>,
    next: usize,
    complete: bool,
}

impl ScenarioProgress {
    /// Reject incomplete or out-of-order source routes, including any route
    /// without an explicit End trigger.
    pub fn new(gates: Vec<ScenarioGate>, _start: [f32; 3]) -> Option<Self> {
        let valid = gates.last().is_some_and(|gate| gate.is_end)
            && gates.iter().enumerate().all(|(i, gate)| {
                gate.shape == 1
                    && gate.sequence == i as u32 + 1
                    && (gate.is_end == (i + 1 == gates.len()))
            });
        valid.then_some(Self {
            gates,
            next: 0,
            complete: false,
        })
    }

    pub fn reset(&mut self, _start: [f32; 3]) {
        self.next = 0;
        self.complete = false;
    }

    pub fn observe(&mut self, vehicle: &TriggerVehicle) {
        if let Some(gate) = self.gates.get(self.next) {
            if trigger_matches(*gate, vehicle) {
                self.next += 1;
                self.complete = gate.is_end && self.next == self.gates.len();
            }
        }
    }

    pub fn complete(&self) -> bool {
        self.complete
    }
    pub fn passed_gates(&self) -> usize {
        self.next
    }
    pub fn last_linked_prop(&self) -> Option<PropTarget> {
        self.next
            .checked_sub(1)
            .and_then(|i| self.gates[i].linked_prop)
    }
}

fn segment_intersects(a: Vec3, b: Vec3, c: Vec3, d: Vec3) -> bool {
    let cross = |u: Vec3, v: Vec3| u.x * v.z - u.z * v.x;
    let ab = b - a;
    let cd = d - c;
    let denominator = cross(ab, cd);
    if denominator == 0.0 {
        return false;
    }
    let t = cross(c - a, cd) / denominator;
    let u = cross(c - a, ab) / denominator;
    (0.0..=1.0).contains(&t) && (0.0..=1.0).contains(&u)
}

/// EXE 0x4704e0/0x4706c0, shape 1. Other shapes are not reconstructed here.
pub fn trigger_matches(gate: ScenarioGate, vehicle: &TriggerVehicle) -> bool {
    if gate.shape != 1 {
        return false;
    }
    let pairs = vehicle.diagonals();
    let [a, b] = gate.segment.map(Vec3::from);
    if pairs[0]
        .iter()
        .any(|p| !(a.y - 3.5..=a.y + 3.5).contains(&p.y))
    {
        return false;
    }
    if !pairs.iter().any(|[c, d]| segment_intersects(*c, *d, a, b)) {
        return false;
    }
    let heading = Vec3::from(gate.forward);
    if heading != Vec3::ZERO && heading.dot(vehicle.forward) <= 0.5 {
        return false;
    }
    let movement = Vec3::from(gate.velocity_direction);
    let velocity_direction = vehicle.velocity.try_normalize().unwrap_or(Vec3::Y);
    if movement != Vec3::ZERO && movement.dot(velocity_direction) <= 0.5 {
        return false;
    }
    // 0x49bea9..0x49bf02, also 0x4a0316..0x4a0354: max + min/4.
    let vx = vehicle.velocity.x.abs();
    let vz = vehicle.velocity.z.abs();
    let speed = vx.max(vz) + 0.25 * vx.min(vz);
    speed + 0.1 > gate.speed_range[0] && gate.speed_range[1] + 0.1 > speed
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn original_prop_selection_matches_tag_xz_and_preserves_unflagged() {
        let arrow = PropTarget {
            fourcc: u32::from_le_bytes(*b"ARW1"),
            position: [1.0, 4.0, 3.0],
        };
        let other = PropTarget {
            position: [2.0, 0.0, 3.0],
            ..arrow
        };
        let cone = PropTarget {
            fourcc: u32::from_le_bytes(*b"CONE"),
            ..arrow
        };
        let mut props = vec![
            ScenarioProp {
                target: arrow,
                triggerable: true,
            },
            ScenarioProp {
                target: PropTarget {
                    position: [1.0, 5.0, 3.0],
                    ..arrow
                },
                triggerable: true,
            },
            ScenarioProp {
                target: other,
                triggerable: true,
            },
            ScenarioProp {
                target: cone,
                triggerable: false,
            },
        ];
        hide_triggerable_props(&mut props);
        hide_triggerable_props(&mut props);
        assert_eq!(
            props
                .iter()
                .map(|p| p.target.position[1])
                .collect::<Vec<_>>(),
            [10004.0, 10005.0, 10000.0, 4.0]
        );
        select_triggerable_prop(&mut props, arrow);
        assert_eq!(
            props
                .iter()
                .map(|p| p.target.position[1])
                .collect::<Vec<_>>(),
            [4.0, 5.0, 10000.0, 4.0]
        );
        select_triggerable_prop(&mut props, other);
        assert_eq!(
            props
                .iter()
                .map(|p| p.target.position[1])
                .collect::<Vec<_>>(),
            [10004.0, 10005.0, 0.0, 4.0]
        );
        select_triggerable_prop(&mut props, PropTarget { fourcc: 0, ..arrow });
        assert_eq!(
            props
                .iter()
                .map(|p| p.target.position[1])
                .collect::<Vec<_>>(),
            [10004.0, 10005.0, 10000.0, 4.0]
        );
    }

    fn gate(sequence: u32, z: f32, is_end: bool) -> ScenarioGate {
        ScenarioGate {
            sequence,
            center: [0.0, 0.0, z],
            segment: [[-2.0, 0.0, z], [2.0, 0.0, z]],
            width: 1.0,
            forward: [0.0; 3],
            velocity_direction: [0.0; 3],
            shape: 1,
            speed_range: [0.0, 200.0],
            is_end,
            linked_prop: None,
        }
    }

    #[test]
    fn ordered_entry_end_and_reset() {
        let mut progress = ScenarioProgress::new(
            vec![gate(1, 10.0, false), gate(2, 20.0, true)],
            [0.0, 0.0, 0.0],
        )
        .unwrap();
        progress.observe(&vehicle(0.0, 21.0));
        assert_eq!(progress.passed_gates(), 0); // No historical point sweep.
        assert!(!progress.complete());
        progress.reset([0.0, 0.0, 0.0]);
        progress.observe(&vehicle(0.0, 10.0));
        progress.observe(&vehicle(0.0, 20.0));
        assert!(progress.complete());
        progress.reset([0.0, 0.0, 21.0]);
        assert!(!progress.complete());
        let mut reverse = vehicle(0.0, 10.0);
        reverse.forward = -Vec3::Z;
        reverse.velocity = -Vec3::Z;
        progress.observe(&reverse);
        assert_eq!(progress.passed_gates(), 1); // Zero source vectors allow either direction.
    }

    #[test]
    fn rejects_missing_end_or_sequence() {
        assert!(ScenarioProgress::new(vec![gate(1, 10.0, false)], [0.0; 3]).is_none());
        assert!(ScenarioProgress::new(vec![gate(2, 10.0, true)], [0.0; 3]).is_none());
    }

    #[test]
    fn exact_footprint_rejects_side_miss() {
        let mut progress =
            ScenarioProgress::new(vec![gate(1, 10.0, true)], [2.1, 0.0, 0.0]).unwrap();
        progress.observe(&vehicle(4.0, 10.0));
        assert!(!progress.complete());
    }

    #[test]
    fn early_end_does_not_advance_missing_waypoint() {
        let mut progress = ScenarioProgress::new(
            vec![gate(1, 10.0, false), gate(2, 20.0, true)],
            [0.0, 0.0, 15.0],
        )
        .unwrap();
        progress.observe(&vehicle(0.0, 20.0));
        assert_eq!(progress.passed_gates(), 0);
        assert!(!progress.complete());
    }

    fn vehicle(x: f32, z: f32) -> TriggerVehicle {
        TriggerVehicle {
            position: Vec3::new(x, 0.5, z),
            forward: Vec3::Z,
            right: Vec3::X,
            up: Vec3::Y,
            half_extents: Vec3::new(1.0, 0.5, 2.0),
            velocity: Vec3::ZERO,
            expanded: false,
        }
    }

    #[test]
    fn body_diagonals_allow_stationary_overlap_but_not_swept_center_or_width() {
        let mut g = gate(1, 10.0, true);
        assert!(trigger_matches(g, &vehicle(0.0, 10.0)));
        assert!(trigger_matches(g, &vehicle(2.5, 11.0))); // Diagonal overlaps despite center outside.
        g.width = 1000.0; // p2 is not a shape-1 rectangle width.
        assert!(!trigger_matches(g, &vehicle(0.0, 12.0)));
        let mut above = vehicle(0.0, 10.0);
        above.position.y += 3.5;
        assert!(trigger_matches(g, &above));
        above.position.y += 0.01;
        assert!(!trigger_matches(g, &above));
    }

    #[test]
    fn source_direction_thresholds_and_horizontal_speed_metric() {
        let mut g = gate(1, 10.0, true);
        let mut v = vehicle(0.0, 10.0);
        g.forward = [0.0, 0.0, 0.5];
        assert!(!trigger_matches(g, &v)); // Strict dot > .5, no source-vector normalization.
        g.forward[2] = 0.51;
        assert!(trigger_matches(g, &v));
        g.velocity_direction = [0.0, 1.0, 0.0];
        assert!(trigger_matches(g, &v)); // Stationary fallback is +Y.
        g.velocity_direction = [0.0; 3];
        v.velocity = Vec3::new(4.0, 100.0, -8.0); // max+min/4=9, ignore vertical speed.
        g.speed_range = [8.95, 9.0];
        assert!(trigger_matches(g, &v));
        g.speed_range = [9.11, 200.0];
        assert!(!trigger_matches(g, &v));
    }

    #[test]
    fn source_segment_endpoints_collinearity_and_expansion() {
        assert!(segment_intersects(
            Vec3::ZERO,
            Vec3::Z,
            Vec3::Z,
            Vec3::Z + Vec3::X
        ));
        assert!(!segment_intersects(
            Vec3::ZERO,
            Vec3::Z,
            Vec3::Z * 0.5,
            Vec3::Z * 2.0
        ));
        let mut v = vehicle(0.0, 0.0);
        let old = v.diagonals();
        v.expanded = true;
        for (pair, [a, b]) in v.diagonals().iter().zip(old) {
            assert!((pair[0] - (3.0 * a - 2.0 * b)).length() < 1e-5);
            assert!((pair[1] - (2.0 * b - a)).length() < 1e-5);
        }
    }
}
