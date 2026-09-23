//! Vehicle physics simulation engine for NFS 5 Porsche Unleashed.
//!
//! Features:
//! - 6 DOF rigid body dynamics with quaternion integration
//! - Powertrain engine with 21-point torque curves interpolated on 500-RPM grid
//! - 4-wheel independent suspension with bump/rebound damping and anti-roll bars
//! - Friction ellipse tire slip model with Coulomb friction budget and `.sim` grip multipliers
//! - Road surface heightfield queries via `surface::RoadSurface`

pub mod powertrain;
pub mod rigid_body;
pub mod suspension;
pub mod tire;
pub mod vehicle;

pub use powertrain::Powertrain;
pub use rigid_body::RigidBody;
pub use suspension::{SuspensionSystem, SuspensionWheel, WHEEL_FL, WHEEL_FR, WHEEL_RL, WHEEL_RR};
pub use tire::Tire;
pub use vehicle::{VehicleControls, VehicleSimulation, VehicleTelemetry};
