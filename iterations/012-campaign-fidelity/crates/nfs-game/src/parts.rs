//! Parts, tuning upgrades and vehicle performance modifiers.

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum PartCategory {
    Engine,
    Exhaust,
    Brakes,
    Springs,
    Shocks,
    SwayBars,
    Gearbox,
    Tires,
    WeightReduction,
    Other,
}

impl std::str::FromStr for PartCategory {
    type Err = std::convert::Infallible;

    fn from_str(name: &str) -> Result<Self, Self::Err> {
        Ok(Self::from_name(name))
    }
}

impl PartCategory {
    pub fn from_name(name: &str) -> Self {
        let lower = name.to_lowercase();
        if lower.contains("engine")
            || lower.contains("carb")
            || lower.contains("intake")
            || lower.contains("injector")
            || lower.contains("chip")
        {
            PartCategory::Engine
        } else if lower.contains("exhaust") {
            PartCategory::Exhaust
        } else if lower.contains("brake") {
            PartCategory::Brakes
        } else if lower.contains("spring") {
            PartCategory::Springs
        } else if lower.contains("shock") {
            PartCategory::Shocks
        } else if lower.contains("sway") {
            PartCategory::SwayBars
        } else if lower.contains("gear") || lower.contains("shift") || lower.contains("flywheel") {
            PartCategory::Gearbox
        } else if lower.contains("tire") || lower.contains("rim") {
            PartCategory::Tires
        } else if lower.contains("body")
            || lower.contains("door")
            || lower.contains("hood")
            || lower.contains("roof")
            || lower.contains("spoiler")
        {
            PartCategory::WeightReduction
        } else {
            PartCategory::Other
        }
    }

    pub fn display_name(&self) -> &'static str {
        match self {
            PartCategory::Engine => "Двигатель (Engine)",
            PartCategory::Exhaust => "Выхлоп (Exhaust)",
            PartCategory::Brakes => "Тормоза (Brakes)",
            PartCategory::Springs => "Пружины (Springs)",
            PartCategory::Shocks => "Амортизаторы (Shocks)",
            PartCategory::SwayBars => "Стабилизаторы (Sway Bars)",
            PartCategory::Gearbox => "Трансмиссия (Gearbox)",
            PartCategory::Tires => "Шины (Tires)",
            PartCategory::WeightReduction => "Кузов / Облегчение",
            PartCategory::Other => "Прочее",
        }
    }
}

/// An installed part on an owned vehicle.
#[derive(Debug, Clone, PartialEq)]
pub struct InstalledPart {
    pub part_id: u32,
    pub name: String,
    pub category: PartCategory,
    pub condition: f32, // 0.0 (broken) .. 1.0 (mint)
    pub price: u32,
    pub modifier_value: f32,
}

impl InstalledPart {
    pub fn new(
        part_id: u32,
        name: &str,
        category: PartCategory,
        price: u32,
        modifier_value: f32,
    ) -> Self {
        Self {
            part_id,
            name: name.to_string(),
            category,
            condition: 1.0,
            price,
            modifier_value,
        }
    }

    /// Calculate repair cost to restore condition back to 1.0.
    pub fn repair_cost(&self) -> u32 {
        if self.condition >= 0.99 {
            return 0;
        }
        let wear = (1.0 - self.condition).clamp(0.0, 1.0);
        ((self.price as f32) * wear * 0.75).round() as u32
    }

    /// Repair part to 100% condition.
    pub fn repair(&mut self) {
        self.condition = 1.0;
    }

    /// Degrade part after racing distance (e.g. per km).
    pub fn apply_wear(&mut self, distance_km: f32) {
        let wear_rate = match self.category {
            PartCategory::Tires => 0.005,
            PartCategory::Brakes => 0.003,
            PartCategory::Engine => 0.001,
            _ => 0.0005,
        };
        self.condition = (self.condition - distance_km * wear_rate).clamp(0.1, 1.0);
    }
}

/// Aggregated performance multipliers applied to physical simulation.
#[derive(Debug, Clone, PartialEq)]
pub struct PerformanceModifiers {
    pub power_multiplier: f32,
    pub brake_multiplier: f32,
    pub suspension_stiffness_multiplier: f32,
    pub damping_multiplier: f32,
    pub roll_stiffness_multiplier: f32,
    pub tire_grip_multiplier: f32,
    pub mass_multiplier: f32,
}

impl Default for PerformanceModifiers {
    fn default() -> Self {
        Self {
            power_multiplier: 1.0,
            brake_multiplier: 1.0,
            suspension_stiffness_multiplier: 1.0,
            damping_multiplier: 1.0,
            roll_stiffness_multiplier: 1.0,
            tire_grip_multiplier: 1.0,
            mass_multiplier: 1.0,
        }
    }
}

impl PerformanceModifiers {
    /// Compute net modifiers from list of installed parts.
    pub fn from_installed_parts(parts: &[InstalledPart]) -> Self {
        let mut mods = Self::default();
        for p in parts {
            let eff = p.condition.clamp(0.2, 1.0);
            match p.category {
                PartCategory::Engine => {
                    if p.modifier_value > 1.0 && p.modifier_value <= 3.0 {
                        mods.power_multiplier *= 1.0 + (p.modifier_value - 1.0) * eff;
                    } else if p.modifier_value > 50.0 {
                        let bonus = ((p.modifier_value - 60.0) / 120.0).clamp(0.0, 0.5);
                        mods.power_multiplier *= 1.0 + bonus * eff;
                    }
                }
                PartCategory::Exhaust => {
                    mods.power_multiplier *= 1.0 + 0.06 * eff;
                }
                PartCategory::Brakes => {
                    let bonus = if p.modifier_value > 1.0 {
                        p.modifier_value - 1.0
                    } else {
                        0.25
                    };
                    mods.brake_multiplier *= 1.0 + bonus * eff;
                }
                PartCategory::Springs => {
                    let bonus = if p.modifier_value > 1.0 {
                        p.modifier_value - 1.0
                    } else {
                        0.3
                    };
                    mods.suspension_stiffness_multiplier *= 1.0 + bonus * eff;
                }
                PartCategory::Shocks => {
                    let bonus = if p.modifier_value > 1.0 {
                        p.modifier_value - 1.0
                    } else {
                        0.4
                    };
                    mods.damping_multiplier *= 1.0 + bonus * eff;
                }
                PartCategory::SwayBars => {
                    let bonus = if p.modifier_value > 1.0 {
                        p.modifier_value - 1.0
                    } else {
                        0.25
                    };
                    mods.roll_stiffness_multiplier *= 1.0 + bonus * eff;
                }
                PartCategory::Tires => {
                    mods.tire_grip_multiplier *= 1.0 + 0.15 * eff;
                }
                PartCategory::WeightReduction => {
                    mods.mass_multiplier *= 1.0 - 0.05 * eff;
                }
                _ => {}
            }
        }
        mods
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_performance_modifiers_accumulate() {
        let parts = vec![
            InstalledPart::new(1, "Sports Exhaust", PartCategory::Exhaust, 350, 1.0),
            InstalledPart::new(2, "Race Brakes", PartCategory::Brakes, 450, 1.5),
            InstalledPart::new(3, "Sport Tires", PartCategory::Tires, 300, 1.0),
            InstalledPart::new(
                4,
                "Fiberglass Hood",
                PartCategory::WeightReduction,
                500,
                1.0,
            ),
        ];

        let mods = PerformanceModifiers::from_installed_parts(&parts);
        assert!(mods.power_multiplier > 1.05);
        assert!(mods.brake_multiplier > 1.4);
        assert!(mods.tire_grip_multiplier > 1.1);
        assert!(mods.mass_multiplier < 0.96);
    }

    #[test]
    fn test_repair_and_wear() {
        let mut part = InstalledPart::new(10, "Brake Pads", PartCategory::Brakes, 200, 1.0);
        assert_eq!(part.repair_cost(), 0);

        part.apply_wear(100.0); // 100 km * 0.003 = 0.3 wear -> condition 0.7
        assert!(part.condition < 0.75);
        assert!(part.repair_cost() > 30);

        part.repair();
        assert_eq!(part.condition, 1.0);
        assert_eq!(part.repair_cost(), 0);
    }
}
