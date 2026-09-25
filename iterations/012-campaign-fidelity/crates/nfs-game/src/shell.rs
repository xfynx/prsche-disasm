//! Game shell screen state machine, career navigation, and idempotent reward logic.

use crate::actions::UiAction;
use crate::events::{
    get_evolution_first_event, get_factory_driver_first_event, CareerMode, EventDefinition,
    EventGoal,
};
use crate::profile::PlayerProfile;

/// All distinct screens in the game shell.
#[derive(Debug, Clone, PartialEq)]
pub enum Screen {
    MainMenu {
        selected_index: usize,
    },
    ProfileSelect {
        selected_index: usize,
    },
    CreateProfile {
        input_name: String,
    },
    ModeSelect {
        selected_index: usize,
    },
    Garage {
        selected_car_index: usize,
        message: Option<String>,
    },
    EventBriefing {
        event: EventDefinition,
    },
    Loading {
        event: EventDefinition,
        request_id: u64,
    },
    Racing {
        event: EventDefinition,
        paused: bool,
    },
    Results {
        event: EventDefinition,
        result: EventResult,
        reward_applied: bool,
    },
}

/// Outcome of a finished event.
#[derive(Debug, Clone, PartialEq)]
pub struct EventResult {
    pub passed: bool,
    pub player_time: f32,
    pub position: usize,
    pub prize_awarded: u32,
    pub summary_message: String,
}

/// The core GameShell state machine.
#[derive(Debug, Clone)]
pub struct GameShell {
    pub screen: Screen,
    pub profile: Option<PlayerProfile>,
    pub request_counter: u64,
}

impl Default for GameShell {
    fn default() -> Self {
        Self::new()
    }
}

impl GameShell {
    pub fn new() -> Self {
        Self {
            screen: Screen::MainMenu { selected_index: 0 },
            profile: None,
            request_counter: 0,
        }
    }

    pub fn with_profile(profile: PlayerProfile) -> Self {
        Self {
            screen: Screen::MainMenu { selected_index: 0 },
            profile: Some(profile),
            request_counter: 0,
        }
    }

    /// Process a UI navigation action on the current screen.
    pub fn handle_action(&mut self, action: UiAction) {
        match &mut self.screen {
            Screen::MainMenu { selected_index } => match action {
                UiAction::Up => {
                    if *selected_index > 0 {
                        *selected_index -= 1;
                    }
                }
                UiAction::Down => {
                    if *selected_index < 3 {
                        *selected_index += 1;
                    }
                }
                UiAction::Confirm => match *selected_index {
                    0 => {
                        // Play Career / Mode Select
                        if self.profile.is_none() {
                            self.screen = Screen::ProfileSelect { selected_index: 0 };
                        } else {
                            self.screen = Screen::ModeSelect { selected_index: 0 };
                        }
                    }
                    1 => {
                        // Profile Select
                        self.screen = Screen::ProfileSelect { selected_index: 0 };
                    }
                    2 => {
                        // Quick Race / Garage
                        if let Some(p) = &self.profile {
                            if !p.garage.is_empty() {
                                self.screen = Screen::Garage {
                                    selected_car_index: p.selected_car_index,
                                    message: None,
                                };
                            } else {
                                self.screen = Screen::ModeSelect { selected_index: 2 };
                            }
                        } else {
                            self.screen = Screen::ProfileSelect { selected_index: 0 };
                        }
                    }
                    _ => {}
                },
                _ => {}
            },

            Screen::ProfileSelect { selected_index } => match action {
                UiAction::Up => {
                    if *selected_index > 0 {
                        *selected_index -= 1;
                    }
                }
                UiAction::Down => {
                    if *selected_index < 1 {
                        *selected_index += 1;
                    }
                }
                UiAction::Confirm => {
                    if *selected_index == 0 {
                        // Create New Profile
                        self.screen = Screen::CreateProfile {
                            input_name: "Pilot".to_string(),
                        };
                    } else if self.profile.is_some() {
                        self.screen = Screen::ModeSelect { selected_index: 0 };
                    }
                }
                UiAction::Back => {
                    self.screen = Screen::MainMenu { selected_index: 0 };
                }
                _ => {}
            },

            Screen::CreateProfile { input_name } => match action {
                UiAction::Confirm => {
                    let mut new_p = PlayerProfile::new(input_name);
                    let _ = new_p.buy_initial_356(); // Auto-buy initial 356 for smooth career entry
                    self.profile = Some(new_p);
                    self.screen = Screen::ModeSelect { selected_index: 0 };
                }
                UiAction::Back => {
                    self.screen = Screen::ProfileSelect { selected_index: 0 };
                }
                _ => {}
            },

            Screen::ModeSelect { selected_index } => match action {
                UiAction::Up => {
                    if *selected_index > 0 {
                        *selected_index -= 1;
                    }
                }
                UiAction::Down => {
                    if *selected_index < 2 {
                        *selected_index += 1;
                    }
                }
                UiAction::Confirm => match *selected_index {
                    0 => {
                        // Evolution Career: check car in garage
                        if let Some(p) = &self.profile {
                            if p.garage.is_empty() {
                                self.screen = Screen::Garage {
                                    selected_car_index: 0,
                                    message: Some(
                                        "Please purchase a 356 before entering Evolution!"
                                            .to_string(),
                                    ),
                                };
                                return;
                            }
                            let car = &p.garage[p.selected_car_index];
                            let event = get_evolution_first_event(&car.model_name, &car.sim_name);
                            self.screen = Screen::EventBriefing { event };
                        }
                    }
                    1 => {
                        // Factory Driver: 0M01 Applying Test with Boxster
                        let event = get_factory_driver_first_event();
                        self.screen = Screen::EventBriefing { event };
                    }
                    2 => {
                        // Quick Race
                        let event = get_evolution_first_event("356_1", "356coupe11");
                        self.screen = Screen::EventBriefing { event };
                    }
                    _ => {}
                },
                UiAction::Back => {
                    self.screen = Screen::MainMenu { selected_index: 0 };
                }
                _ => {}
            },

            Screen::Garage {
                selected_car_index,
                message: _,
            } => match action {
                UiAction::Left => {
                    if let Some(p) = &self.profile {
                        if !p.garage.is_empty() && *selected_car_index > 0 {
                            *selected_car_index -= 1;
                        }
                    }
                }
                UiAction::Right => {
                    if let Some(p) = &self.profile {
                        if !p.garage.is_empty() && *selected_car_index + 1 < p.garage.len() {
                            *selected_car_index += 1;
                        }
                    }
                }
                UiAction::Confirm => {
                    if let Some(p) = &mut self.profile {
                        if p.garage.is_empty() && p.credits >= 11_000 {
                            let _ = p.buy_initial_356();
                        } else if !p.garage.is_empty() {
                            p.selected_car_index = *selected_car_index;
                            let car = &p.garage[p.selected_car_index];
                            let event = get_evolution_first_event(&car.model_name, &car.sim_name);
                            self.screen = Screen::EventBriefing { event };
                        }
                    }
                }
                UiAction::Back => {
                    self.screen = Screen::ModeSelect { selected_index: 0 };
                }
                _ => {}
            },

            Screen::EventBriefing { event } => match action {
                UiAction::Confirm => {
                    self.request_counter += 1;
                    let req_id = self.request_counter;
                    self.screen = Screen::Loading {
                        event: event.clone(),
                        request_id: req_id,
                    };
                }
                UiAction::Back => {
                    self.screen = Screen::ModeSelect { selected_index: 0 };
                }
                _ => {}
            },

            Screen::Loading {
                event,
                request_id: _,
            } => {
                if action == UiAction::Back {
                    // Cancel async loading: invalidate request ID
                    self.request_counter += 1;
                    self.screen = Screen::EventBriefing {
                        event: event.clone(),
                    };
                }
            }

            Screen::Racing { event: _, paused } => {
                if action == UiAction::Pause {
                    *paused = !*paused;
                }
            }

            Screen::Results {
                event,
                result: _,
                reward_applied: _,
            } => match action {
                UiAction::Confirm => {
                    // Continue back to career / mode select
                    self.screen = Screen::ModeSelect { selected_index: 0 };
                }
                UiAction::Back => {
                    // Retry event
                    self.screen = Screen::EventBriefing {
                        event: event.clone(),
                    };
                }
                _ => {}
            },
        }
    }

    /// Notify that asynchronous asset loading completed.
    /// Safely ignores outdated requests if the user cancelled loading.
    pub fn on_loading_completed(&mut self, req_id: u64) -> bool {
        if let Screen::Loading { event, request_id } = &self.screen {
            if *request_id == req_id {
                self.screen = Screen::Racing {
                    event: event.clone(),
                    paused: false,
                };
                return true;
            }
        }
        false
    }

    /// Complete race session and transition to Results screen.
    pub fn finish_race(&mut self, player_time: f32, position: usize) {
        if let Screen::Racing { event, .. } = &self.screen {
            let passed = match &event.goal {
                EventGoal::RacePosition { min_position } => position <= *min_position,
                EventGoal::TimeLimit { max_seconds } => player_time <= *max_seconds,
            };

            let prize = if passed { event.first_prize } else { 0 };
            let msg = if passed {
                event.pass_message.clone()
            } else {
                event.fail_message.clone()
            };

            let result = EventResult {
                passed,
                player_time,
                position,
                prize_awarded: prize,
                summary_message: msg,
            };

            let mut shell_result = Screen::Results {
                event: event.clone(),
                result,
                reward_applied: false,
            };

            std::mem::swap(&mut self.screen, &mut shell_result);
            self.apply_result_idempotent();
        }
    }

    /// Idempotently apply results and rewards to profile progress and economy.
    pub fn apply_result_idempotent(&mut self) -> bool {
        if let Screen::Results {
            event,
            result,
            reward_applied,
        } = &mut self.screen
        {
            if *reward_applied {
                return false; // Already applied, prevent duplicate rewards
            }

            if let Some(prof) = &mut self.profile {
                if result.passed {
                    match event.mode {
                        CareerMode::Evolution => {
                            prof.credits += result.prize_awarded;
                            if !prof.evolution.completed_tournaments.contains(&0) {
                                prof.evolution.completed_tournaments.push(0);
                            }
                            prof.evolution.total_prize_money += result.prize_awarded;
                        }
                        CareerMode::FactoryDriver => {
                            if !prof.factory_driver.completed_missions.contains(&event.id) {
                                prof.factory_driver
                                    .completed_missions
                                    .push(event.id.clone());
                            }
                            prof.factory_driver.current_mission_code = "1m01".to_string();
                            prof.factory_driver.driver_rank = "Junior Test Driver".to_string();
                            prof.factory_driver
                                .best_times
                                .insert(event.id.clone(), result.player_time);
                        }
                        CareerMode::QuickRace => {}
                    }
                }
            }

            *reward_applied = true;
            return true;
        }
        false
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_initial_menu_navigation() {
        let mut shell = GameShell::new();
        assert_eq!(shell.screen, Screen::MainMenu { selected_index: 0 });

        shell.handle_action(UiAction::Down);
        assert_eq!(shell.screen, Screen::MainMenu { selected_index: 1 });

        shell.handle_action(UiAction::Up);
        assert_eq!(shell.screen, Screen::MainMenu { selected_index: 0 });
    }

    #[test]
    fn test_profile_creation_and_auto_car() {
        let mut shell = GameShell::new();
        shell.handle_action(UiAction::Confirm); // Opens ProfileSelect
        assert_eq!(shell.screen, Screen::ProfileSelect { selected_index: 0 });

        shell.handle_action(UiAction::Confirm); // Opens CreateProfile
        match &shell.screen {
            Screen::CreateProfile { input_name } => assert_eq!(input_name, "Pilot"),
            _ => panic!("Expected CreateProfile screen"),
        }

        shell.handle_action(UiAction::Confirm); // Confirms and enters ModeSelect
        assert!(shell.profile.is_some());
        let prof = shell.profile.as_ref().unwrap();
        assert_eq!(prof.name, "Pilot");
        assert_eq!(prof.garage.len(), 1);
        assert_eq!(prof.credits, 0); // Bought initial 356 Ferdinand for 11,000
    }

    #[test]
    fn test_evolution_event_lifecycle_and_idempotency() {
        let mut prof = PlayerProfile::new("EvoRacer");
        prof.buy_initial_356().unwrap();
        assert_eq!(prof.credits, 0);

        let mut shell = GameShell::with_profile(prof);
        shell.screen = Screen::ModeSelect { selected_index: 0 };
        shell.handle_action(UiAction::Confirm); // Opens EventBriefing for 356 Challenge

        match &shell.screen {
            Screen::EventBriefing { event } => assert_eq!(event.id, "evo_classic_t01_s01"),
            _ => panic!("Expected EventBriefing"),
        }

        shell.handle_action(UiAction::Confirm); // Starts Loading
        let req_id = shell.request_counter;

        let loaded = shell.on_loading_completed(req_id);
        assert!(loaded);
        assert!(matches!(shell.screen, Screen::Racing { .. }));

        // Finish race in 1st place!
        shell.finish_race(120.5, 1);

        // Check Results
        match &shell.screen {
            Screen::Results {
                result,
                reward_applied,
                ..
            } => {
                assert!(result.passed);
                assert_eq!(result.prize_awarded, 4500);
                assert!(*reward_applied);
            }
            _ => panic!("Expected Results screen"),
        }

        // Profile should now have 4500 credits and completed tournament 0
        let p = shell.profile.as_ref().unwrap();
        assert_eq!(p.credits, 4500);
        assert_eq!(p.evolution.completed_tournaments, vec![0]);

        // Attempting to reapply result should be a no-op (idempotent)
        let second_apply = shell.apply_result_idempotent();
        assert!(!second_apply);
        assert_eq!(shell.profile.as_ref().unwrap().credits, 4500);
    }

    #[test]
    fn test_factory_driver_pass_and_fail() {
        // Test Fail (over 32s)
        let prof = PlayerProfile::new("TestRolf");
        let mut shell = GameShell::with_profile(prof);
        shell.screen = Screen::ModeSelect { selected_index: 1 };
        shell.handle_action(UiAction::Confirm); // 0M01 briefing
        shell.handle_action(UiAction::Confirm); // Loading
        let req_id = shell.request_counter;
        shell.on_loading_completed(req_id);

        // Over 32s -> Fail
        shell.finish_race(34.2, 1);
        match &shell.screen {
            Screen::Results { result, .. } => {
                assert!(!result.passed);
                assert_eq!(result.prize_awarded, 0);
            }
            _ => panic!("Expected Results"),
        }
        let p = shell.profile.as_ref().unwrap();
        assert_eq!(p.factory_driver.driver_rank, "Applicant");
        assert_eq!(p.factory_driver.current_mission_code, "0M01");

        // Test Pass (under 32s)
        shell.screen = Screen::ModeSelect { selected_index: 1 };
        shell.handle_action(UiAction::Confirm);
        shell.handle_action(UiAction::Confirm);
        let req_id = shell.request_counter;
        shell.on_loading_completed(req_id);

        // Under 32s -> Pass
        shell.finish_race(29.8, 1);
        match &shell.screen {
            Screen::Results { result, .. } => {
                assert!(result.passed);
            }
            _ => panic!("Expected Results"),
        }
        let p = shell.profile.as_ref().unwrap();
        assert_eq!(p.factory_driver.driver_rank, "Junior Test Driver");
        assert_eq!(p.factory_driver.current_mission_code, "1m01");
        assert_eq!(p.factory_driver.completed_missions, vec!["0M01"]);
    }

    #[test]
    fn test_cancelled_loading_ignores_old_request() {
        let mut shell = GameShell::new();
        shell.profile = Some(PlayerProfile::new("Canceller"));
        shell.screen = Screen::ModeSelect { selected_index: 1 };
        shell.handle_action(UiAction::Confirm); // Briefing
        shell.handle_action(UiAction::Confirm); // Loading with req_id 1
        let old_req_id = shell.request_counter;

        // User hits Back during loading
        shell.handle_action(UiAction::Back);
        assert!(matches!(shell.screen, Screen::EventBriefing { .. }));

        // Old callback arrives
        let completed = shell.on_loading_completed(old_req_id);
        assert!(!completed);
        assert!(matches!(shell.screen, Screen::EventBriefing { .. })); // Stays in briefing!
    }
}
