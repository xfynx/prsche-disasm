//! Race state machine, timing, and session control.

/// Phases of a race session.
#[derive(Debug, Clone, PartialEq)]
pub enum RacePhase {
    /// Loading assets and setting up grid.
    Loading,
    /// Pre-race countdown (e.g. 3, 2, 1, GO!).
    Countdown {
        remaining_secs: f32,
        initial_secs: f32,
    },
    /// Active racing with free player and AI vehicle control.
    Racing { elapsed_secs: f32 },
    /// Session is temporarily paused.
    Paused { previous_phase: Box<RacePhase> },
    /// Player crossed finish line on final lap; vehicle decelerates/coasts.
    Finished {
        total_time_secs: f32,
        cooldown_secs: f32,
    },
    /// Final results screen with standings and times.
    Results,
}

/// Visual or audio cue during countdown.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum CountdownCue {
    Three,
    Two,
    One,
    Go,
}

impl RacePhase {
    /// Returns true if the car can be actively controlled by user inputs.
    pub fn allows_driving_input(&self) -> bool {
        matches!(self, RacePhase::Racing { .. } | RacePhase::Finished { .. })
    }

    /// Returns true if active race time is ticking.
    pub fn is_racing(&self) -> bool {
        matches!(self, RacePhase::Racing { .. })
    }

    /// Returns true if the race is paused.
    pub fn is_paused(&self) -> bool {
        matches!(self, RacePhase::Paused { .. })
    }

    /// Returns true if the race has concluded (Finished or Results).
    pub fn is_finished(&self) -> bool {
        matches!(self, RacePhase::Finished { .. } | RacePhase::Results)
    }

    /// Returns the current countdown cue if within countdown phase.
    pub fn countdown_cue(&self) -> Option<CountdownCue> {
        match self {
            RacePhase::Countdown { remaining_secs, .. } => {
                if *remaining_secs > 2.0 {
                    Some(CountdownCue::Three)
                } else if *remaining_secs > 1.0 {
                    Some(CountdownCue::Two)
                } else if *remaining_secs > 0.0 {
                    Some(CountdownCue::One)
                } else {
                    Some(CountdownCue::Go)
                }
            }
            _ => None,
        }
    }
}

/// Tracks lap progression, lap times, splits, and best lap.
#[derive(Debug, Clone, PartialEq)]
pub struct LapTracker {
    /// Current lap index (1-based, e.g. 1..=total_laps).
    pub current_lap: u32,
    /// Total number of laps required to complete the race (1 for sprints).
    pub total_laps: u32,
    /// Elapsed time on the current lap in seconds.
    pub current_lap_time: f32,
    /// History of completed lap times in seconds.
    pub completed_laps: Vec<f32>,
    /// Best recorded lap time across the session.
    pub best_lap_time: Option<f32>,
    /// Sector split times for the current lap.
    pub current_sector_splits: Vec<f32>,
    /// All sector splits across completed laps.
    pub history_sector_splits: Vec<Vec<f32>>,
}

impl LapTracker {
    /// Creates a new lap tracker.
    pub fn new(total_laps: u32) -> Self {
        Self {
            current_lap: 1,
            total_laps: total_laps.max(1),
            current_lap_time: 0.0,
            completed_laps: Vec::new(),
            best_lap_time: None,
            current_sector_splits: Vec::new(),
            history_sector_splits: Vec::new(),
        }
    }

    /// Accumulates time into the current lap.
    pub fn step(&mut self, dt: f32) {
        if dt > 0.0 {
            self.current_lap_time += dt;
        }
    }

    /// Records a sector split time.
    pub fn record_sector_split(&mut self) -> f32 {
        let split = self.current_lap_time;
        self.current_sector_splits.push(split);
        split
    }

    /// Completes the current lap and advances to the next.
    /// Returns `true` if the race is now completed (all laps finished).
    pub fn complete_lap(&mut self) -> bool {
        let lap_time = self.current_lap_time;
        self.completed_laps.push(lap_time);

        match self.best_lap_time {
            Some(best) if lap_time < best => self.best_lap_time = Some(lap_time),
            None => self.best_lap_time = Some(lap_time),
            _ => {}
        }

        self.history_sector_splits
            .push(std::mem::take(&mut self.current_sector_splits));
        self.current_lap_time = 0.0;

        if self.current_lap >= self.total_laps {
            true
        } else {
            self.current_lap += 1;
            false
        }
    }

    /// Returns the most recently completed lap time, if any.
    pub fn last_completed_lap_time(&self) -> Option<f32> {
        self.completed_laps.last().copied()
    }

    /// Returns true if all required laps have been completed.
    pub fn is_race_complete(&self) -> bool {
        self.completed_laps.len() >= self.total_laps as usize
    }

    /// Formats a time in seconds to "MM:SS.ff".
    pub fn format_time(seconds: f32) -> String {
        if seconds < 0.0 {
            return "--:--.--".to_string();
        }
        let total_centis = (seconds * 100.0).round() as u64;
        let centis = total_centis % 100;
        let total_secs = total_centis / 100;
        let secs = total_secs % 60;
        let mins = total_secs / 60;
        format!("{:02}:{:02}.{:02}", mins, secs, centis)
    }
}

/// Participant entry in the race session.
#[derive(Debug, Clone, PartialEq)]
pub struct RaceParticipant {
    pub id: usize,
    pub name: String,
    pub is_player: bool,
    pub car_model: String,
    pub current_position: usize,
    pub distance_along_track: f32,
    pub laps_completed: u32,
    pub total_time_secs: Option<f32>,
    pub best_lap_secs: Option<f32>,
}

/// Orchestrates an entire race session, state transitions, and standings.
#[derive(Debug, Clone)]
pub struct RaceSession {
    pub track_id: String,
    pub phase: RacePhase,
    pub lap_tracker: LapTracker,
    pub participants: Vec<RaceParticipant>,
    pub is_point_to_point: bool,
    pub total_race_time: f32,
}

impl RaceSession {
    /// Creates a new race session with default 3 laps and a 3.0s countdown.
    pub fn new(track_id: impl Into<String>, total_laps: u32, is_point_to_point: bool) -> Self {
        Self {
            track_id: track_id.into(),
            phase: RacePhase::Countdown {
                remaining_secs: 3.0,
                initial_secs: 3.0,
            },
            lap_tracker: LapTracker::new(total_laps),
            participants: Vec::new(),
            is_point_to_point,
            total_race_time: 0.0,
        }
    }

    /// Adds a participant to the session.
    pub fn add_participant(
        &mut self,
        id: usize,
        name: impl Into<String>,
        is_player: bool,
        car_model: impl Into<String>,
    ) {
        let position = self.participants.len() + 1;
        self.participants.push(RaceParticipant {
            id,
            name: name.into(),
            is_player,
            car_model: car_model.into(),
            current_position: position,
            distance_along_track: 0.0,
            laps_completed: 0,
            total_time_secs: None,
            best_lap_secs: None,
        });
    }

    /// Advances the race session by `dt` seconds.
    pub fn step(&mut self, dt: f32) {
        match &mut self.phase {
            RacePhase::Countdown { remaining_secs, .. } => {
                *remaining_secs -= dt;
                // Once countdown passes 0, transition to Racing
                if *remaining_secs <= 0.0 {
                    self.phase = RacePhase::Racing { elapsed_secs: 0.0 };
                }
            }
            RacePhase::Racing { elapsed_secs } => {
                *elapsed_secs += dt;
                self.total_race_time += dt;
                self.lap_tracker.step(dt);
            }
            RacePhase::Finished {
                cooldown_secs,
                total_time_secs,
            } => {
                *cooldown_secs -= dt;
                if *cooldown_secs <= 0.0 {
                    let total = *total_time_secs;
                    self.phase = RacePhase::Results;
                    // Record final player time if not set
                    if let Some(player) = self.participants.iter_mut().find(|p| p.is_player) {
                        if player.total_time_secs.is_none() {
                            player.total_time_secs = Some(total);
                            player.best_lap_secs = self.lap_tracker.best_lap_time;
                        }
                    }
                }
            }
            RacePhase::Paused { .. } | RacePhase::Loading | RacePhase::Results => {}
        }
    }

    /// Pauses the race session if currently in Countdown, Racing, or Finished.
    pub fn pause(&mut self) {
        if matches!(
            self.phase,
            RacePhase::Countdown { .. } | RacePhase::Racing { .. } | RacePhase::Finished { .. }
        ) {
            let current = std::mem::replace(&mut self.phase, RacePhase::Loading);
            self.phase = RacePhase::Paused {
                previous_phase: Box::new(current),
            };
        }
    }

    /// Resumes the race session from pause.
    pub fn resume(&mut self) {
        if let RacePhase::Paused { previous_phase } = &mut self.phase {
            self.phase = *std::mem::replace(previous_phase, Box::new(RacePhase::Loading));
        }
    }

    /// Toggles pause state.
    pub fn toggle_pause(&mut self) {
        if self.phase.is_paused() {
            self.resume();
        } else {
            self.pause();
        }
    }

    /// Restarts the race session from the countdown phase.
    pub fn restart(&mut self, countdown_secs: f32) {
        let total_laps = self.lap_tracker.total_laps;
        self.lap_tracker = LapTracker::new(total_laps);
        self.total_race_time = 0.0;
        self.phase = RacePhase::Countdown {
            remaining_secs: countdown_secs,
            initial_secs: countdown_secs,
        };
        for (i, p) in self.participants.iter_mut().enumerate() {
            p.current_position = i + 1;
            p.distance_along_track = 0.0;
            p.laps_completed = 0;
            p.total_time_secs = None;
            p.best_lap_secs = None;
        }
    }

    /// Triggers crossing the start/finish line for the player.
    /// Returns true if this crossing completed the race.
    pub fn on_player_lap_completed(&mut self) -> bool {
        if !self.phase.is_racing() {
            return false;
        }

        let race_completed = self.lap_tracker.complete_lap();
        if let Some(player) = self.participants.iter_mut().find(|p| p.is_player) {
            player.laps_completed += 1;
            player.best_lap_secs = self.lap_tracker.best_lap_time;
        }

        if race_completed {
            let total = self.total_race_time;
            self.phase = RacePhase::Finished {
                total_time_secs: total,
                cooldown_secs: 3.5, // 3.5 seconds post-race coast before results
            };
            if let Some(player) = self.participants.iter_mut().find(|p| p.is_player) {
                player.total_time_secs = Some(total);
            }
            true
        } else {
            false
        }
    }

    /// Updates live race positions based on completed laps and distance along the track.
    pub fn update_standings(&mut self) {
        // Sort participants by laps_completed (descending), then distance_along_track (descending)
        self.participants.sort_by(|a, b| {
            b.laps_completed.cmp(&a.laps_completed).then_with(|| {
                b.distance_along_track
                    .partial_cmp(&a.distance_along_track)
                    .unwrap_or(std::cmp::Ordering::Equal)
            })
        });

        for (idx, p) in self.participants.iter_mut().enumerate() {
            p.current_position = idx + 1;
        }
    }

    /// Returns the player's current standings position (e.g. 1 for 1st place).
    pub fn player_position(&self) -> usize {
        self.participants
            .iter()
            .find(|p| p.is_player)
            .map(|p| p.current_position)
            .unwrap_or(1)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_lap_tracker_progression() {
        let mut tracker = LapTracker::new(3);
        assert_eq!(tracker.current_lap, 1);
        assert_eq!(tracker.total_laps, 3);
        assert!(!tracker.is_race_complete());

        // Step 10 seconds on lap 1
        tracker.step(10.0);
        assert_eq!(tracker.current_lap_time, 10.0);

        // Record a split
        let split = tracker.record_sector_split();
        assert_eq!(split, 10.0);

        // Step 5 more seconds
        tracker.step(5.0);
        let finished = tracker.complete_lap();
        assert!(!finished);
        assert_eq!(tracker.current_lap, 2);
        assert_eq!(tracker.completed_laps, vec![15.0]);
        assert_eq!(tracker.best_lap_time, Some(15.0));
        assert_eq!(tracker.current_lap_time, 0.0);

        // Lap 2: 12 seconds (faster)
        tracker.step(12.0);
        let finished2 = tracker.complete_lap();
        assert!(!finished2);
        assert_eq!(tracker.current_lap, 3);
        assert_eq!(tracker.best_lap_time, Some(12.0));

        // Lap 3: 14 seconds (final lap)
        tracker.step(14.0);
        let finished3 = tracker.complete_lap();
        assert!(finished3);
        assert!(tracker.is_race_complete());
        assert_eq!(tracker.completed_laps.len(), 3);
        assert_eq!(tracker.best_lap_time, Some(12.0));
    }

    #[test]
    fn test_countdown_and_race_phases() {
        let mut session = RaceSession::new("skidpad", 2, false);
        session.add_participant(0, "Player", true, "356a");
        session.add_participant(1, "AI 1", false, "boxster");

        assert!(matches!(session.phase, RacePhase::Countdown { .. }));
        assert_eq!(session.phase.countdown_cue(), Some(CountdownCue::Three));

        // Step 1.2s -> Countdown at 1.8s (Cue: Two)
        session.step(1.2);
        assert_eq!(session.phase.countdown_cue(), Some(CountdownCue::Two));

        // Step 1.0s -> Countdown at 0.8s (Cue: One)
        session.step(1.0);
        assert_eq!(session.phase.countdown_cue(), Some(CountdownCue::One));

        // Step 1.0s -> Goes past 0 -> Racing phase
        session.step(1.0);
        assert!(session.phase.is_racing());
        assert!(session.phase.allows_driving_input());

        // Step 20s of racing
        session.step(20.0);
        assert_eq!(session.total_race_time, 20.0);
        assert_eq!(session.lap_tracker.current_lap, 1);

        // Pause and resume
        session.pause();
        assert!(session.phase.is_paused());
        assert!(!session.phase.is_racing());

        session.step(5.0); // Should not advance race time while paused
        assert_eq!(session.total_race_time, 20.0);

        session.resume();
        assert!(session.phase.is_racing());

        // Complete Lap 1
        let finished_lap1 = session.on_player_lap_completed();
        assert!(!finished_lap1);
        assert_eq!(session.lap_tracker.current_lap, 2);

        // Complete Lap 2 -> Race finished
        let finished_lap2 = session.on_player_lap_completed();
        assert!(finished_lap2);
        assert!(matches!(session.phase, RacePhase::Finished { .. }));

        // Cooldown expires -> Results
        session.step(4.0);
        assert_eq!(session.phase, RacePhase::Results);
        assert!(session.phase.is_finished());
    }

    #[test]
    fn test_standings_order() {
        let mut session = RaceSession::new("autobahn", 3, false);
        session.add_participant(0, "Player", true, "356a");
        session.add_participant(1, "Rival 1", false, "boxster");
        session.add_participant(2, "Rival 2", false, "gt3");

        // Set distances
        session.participants[0].laps_completed = 1;
        session.participants[0].distance_along_track = 150.0;

        session.participants[1].laps_completed = 1;
        session.participants[1].distance_along_track = 300.0;

        session.participants[2].laps_completed = 0;
        session.participants[2].distance_along_track = 500.0;

        session.update_standings();

        // Rival 1: 1 lap, 300m -> P1
        // Player:  1 lap, 150m -> P2
        // Rival 2: 0 laps, 500m -> P3
        assert_eq!(session.participants[0].name, "Rival 1");
        assert_eq!(session.participants[0].current_position, 1);
        assert_eq!(session.participants[1].name, "Player");
        assert_eq!(session.participants[1].current_position, 2);
        assert_eq!(session.participants[2].name, "Rival 2");
        assert_eq!(session.participants[2].current_position, 3);
        assert_eq!(session.player_position(), 2);
    }

    #[test]
    fn test_format_time() {
        assert_eq!(LapTracker::format_time(0.0), "00:00.00");
        assert_eq!(LapTracker::format_time(65.432), "01:05.43");
        assert_eq!(LapTracker::format_time(125.0), "02:05.00");
        assert_eq!(LapTracker::format_time(-1.0), "--:--.--");
    }
}
