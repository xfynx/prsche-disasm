//! Ordered SCN trigger traversal. The geometry is sourced; mission semantics
//! are a reconstruction pending executable evidence.

use crate::ScenarioGate;

#[derive(Debug, Clone)]
pub struct ScenarioProgress {
    gates: Vec<ScenarioGate>,
    next: usize,
    last_position: [f32; 3],
    complete: bool,
}

impl ScenarioProgress {
    /// Reject incomplete or out-of-order source routes, including any route
    /// without an explicit End trigger.
    pub fn new(gates: Vec<ScenarioGate>, start: [f32; 3]) -> Option<Self> {
        let valid = gates.last().is_some_and(|gate| gate.is_end)
            && gates.iter().enumerate().all(|(i, gate)| {
                gate.sequence == i as u32 + 1 && (gate.is_end == (i + 1 == gates.len()))
            });
        valid.then_some(Self {
            gates,
            next: 0,
            last_position: start,
            complete: false,
        })
    }

    pub fn reset(&mut self, start: [f32; 3]) {
        self.next = 0;
        self.last_position = start;
        self.complete = false;
    }

    pub fn observe(&mut self, position: [f32; 3]) {
        if let Some(gate) = self.gates.get(self.next) {
            if enters_gate(*gate, self.last_position, position) {
                self.next += 1;
                self.complete = gate.is_end && self.next == self.gates.len();
            }
        }
        self.last_position = position;
    }

    pub fn complete(&self) -> bool {
        self.complete
    }
    pub fn passed_gates(&self) -> usize {
        self.next
    }
}

fn enters_gate(gate: ScenarioGate, previous: [f32; 3], current: [f32; 3]) -> bool {
    let motion = [current[0] - previous[0], current[2] - previous[2]];
    if motion[0] * gate.forward[0] + motion[1] * gate.forward[2] <= 0.0 {
        return false;
    }
    let a = gate.segment[0];
    let b = gate.segment[1];
    let length = (b[0] - a[0]).hypot(b[2] - a[2]);
    if length <= f32::EPSILON {
        return false;
    }
    let axis = [(b[0] - a[0]) / length, (b[2] - a[2]) / length];
    let normal = [-axis[1], axis[0]];
    let local = |p: [f32; 3]| {
        let d = [p[0] - a[0], p[2] - a[2]];
        [
            d[0] * axis[0] + d[1] * axis[1],
            d[0] * normal[0] + d[1] * normal[1],
        ]
    };
    let p = local(previous);
    let q = local(current);
    let half_width = gate.width * 0.5;
    if (0.0..=length).contains(&p[0]) && p[1].abs() <= half_width {
        return false;
    }
    // Clip the movement segment to the source footprint so a thin trigger
    // cannot be skipped between simulation samples.
    let mut low = 0.0_f32;
    let mut high = 1.0_f32;
    for (start, delta, min, max) in [
        (p[0], q[0] - p[0], 0.0, length),
        (p[1], q[1] - p[1], -half_width, half_width),
    ] {
        if delta.abs() < f32::EPSILON {
            if start < min || start > max {
                return false;
            }
        } else {
            let t0 = (min - start) / delta;
            let t1 = (max - start) / delta;
            low = low.max(t0.min(t1));
            high = high.min(t0.max(t1));
            if low > high {
                return false;
            }
        }
    }
    true
}

#[cfg(test)]
mod tests {
    use super::*;

    fn gate(sequence: u32, z: f32, is_end: bool) -> ScenarioGate {
        ScenarioGate {
            sequence,
            center: [0.0, 0.0, z],
            segment: [[-2.0, 0.0, z], [2.0, 0.0, z]],
            width: 1.0,
            forward: [0.0, 0.0, 1.0],
            is_end,
        }
    }

    #[test]
    fn ordered_entry_end_and_reset() {
        let mut progress = ScenarioProgress::new(
            vec![gate(1, 10.0, false), gate(2, 20.0, true)],
            [0.0, 0.0, 0.0],
        )
        .unwrap();
        progress.observe([0.0, 0.0, 21.0]);
        assert_eq!(progress.passed_gates(), 1);
        assert!(!progress.complete()); // Crossing End in the same sweep is insufficient.
        progress.reset([0.0, 0.0, 0.0]);
        progress.observe([0.0, 0.0, 11.0]);
        progress.observe([0.0, 0.0, 21.0]);
        assert!(progress.complete());
        progress.reset([0.0, 0.0, 21.0]);
        assert!(!progress.complete());
        progress.observe([0.0, 0.0, 9.0]);
        assert_eq!(progress.passed_gates(), 0); // Wrong direction.
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
        progress.observe([2.1, 0.0, 20.0]);
        assert!(!progress.complete());
    }

    #[test]
    fn early_end_does_not_advance_missing_waypoint() {
        let mut progress = ScenarioProgress::new(
            vec![gate(1, 10.0, false), gate(2, 20.0, true)],
            [0.0, 0.0, 15.0],
        )
        .unwrap();
        progress.observe([0.0, 0.0, 21.0]);
        assert_eq!(progress.passed_gates(), 0);
        assert!(!progress.complete());
    }
}
