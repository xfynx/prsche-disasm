//! Career event definitions for Evolution and Factory Driver.

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum CareerMode {
    Evolution,
    FactoryDriver,
    QuickRace,
}

#[derive(Debug, Clone, PartialEq)]
pub enum EventGoal {
    /// Win race or reach top positions.
    RacePosition { min_position: usize },
    /// Finish within a given time limit in seconds.
    TimeLimit { max_seconds: f32 },
}

#[derive(Debug, Clone, PartialEq)]
pub struct EventDefinition {
    pub id: String,
    pub mode: CareerMode,
    pub title: String,
    pub description: String,
    pub track_id: u32,
    pub track_name: String,
    pub car_model: String,
    pub car_sim: String,
    pub laps: u32,
    pub opponents_count: usize,
    pub entry_fee: u32,
    pub first_prize: u32,
    pub goal: EventGoal,
    pub pass_message: String,
    pub fail_message: String,
}

/// Create the confirmed first event of the Evolution career:
/// Classic Tournament 1: 356 Challenge (Stage 1, Canyon).
pub fn get_evolution_first_event(car_model: &str, car_sim: &str) -> EventDefinition {
    EventDefinition {
        id: "evo_classic_t01_s01".to_string(),
        mode: CareerMode::Evolution,
        title: "356 Challenge - Race 1".to_string(),
        description: "Classic Era Tournament 1: A challenge for the new driver across Côte d'Azur Canyon in the classic 356.".to_string(),
        track_id: 14,
        track_name: "canyon".to_string(),
        car_model: if car_model.is_empty() { "356_1".to_string() } else { car_model.to_string() },
        car_sim: if car_sim.is_empty() { "356coupe11".to_string() } else { car_sim.to_string() },
        laps: 2,
        opponents_count: 3,
        entry_fee: 750,
        first_prize: 4500,
        goal: EventGoal::RacePosition { min_position: 1 },
        pass_message: "Victory in 356 Challenge! Prize of 4,500 credits awarded.".to_string(),
        fail_message: "You did not take first place. Entry fee lost. Try again!".to_string(),
    }
}

/// Create the confirmed introductory event of Factory Driver:
/// 0M01: "Applying Test" (Skidpad, Boxster, 32.0 second limit).
pub fn get_factory_driver_first_event() -> EventDefinition {
    EventDefinition {
        id: "0M01".to_string(),
        mode: CareerMode::FactoryDriver,
        title: "0M01: Applying Test".to_string(),
        description: "Take the Porsche Boxster out to the Weissach Skid Pad and navigate the course within thirty-two seconds to join the test team.".to_string(),
        track_id: 13,
        track_name: "skidpad".to_string(),
        car_model: "boxster".to_string(),
        car_sim: "boxster".to_string(),
        laps: 1,
        opponents_count: 0,
        entry_fee: 0,
        first_prize: 0, // Factory Driver rewards rank progression, not direct cash
        goal: EventGoal::TimeLimit { max_seconds: 32.0 },
        pass_message: "Hey there, welcome to the team! I'm Rolf and I'm the Test Driving Supervisor for the Porsche Test Team. You're off to a great start.".to_string(),
        fail_message: "I'm sorry, my young friend, but you just don't have the skills we require. Come and see me again when you've got a bit more experience.".to_string(),
    }
}
