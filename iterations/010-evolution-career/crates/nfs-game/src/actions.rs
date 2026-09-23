//! Common input actions for both UI navigation and driving across web and native platforms.

/// UI navigation action for menus and shells.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum UiAction {
    Up,
    Down,
    Left,
    Right,
    Confirm,
    Back,
    Pause,
}

/// Continuous driving inputs.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct DriveInput {
    pub steer: f32,
    pub throttle: f32,
    pub brake: f32,
    pub handbrake: bool,
    pub reset: bool,
}

impl Default for DriveInput {
    fn default() -> Self {
        Self {
            steer: 0.0,
            throttle: 0.0,
            brake: 0.0,
            handbrake: false,
            reset: false,
        }
    }
}
