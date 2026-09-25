//! Dealership (new and used car market) and Parts shop.

use crate::parts::{InstalledPart, PartCategory};
use crate::tournament::TournamentEra;

/// Information about a car offered for sale in the market.
#[derive(Debug, Clone, PartialEq)]
pub struct MarketCar {
    pub id: String,
    pub model_name: String,
    pub sim_name: String,
    pub display_name: String,
    pub year: u32,
    pub era: TournamentEra,
    pub is_used: bool,
    pub mileage_km: u32,
    pub base_price: u32,
    pub price: u32,
    pub overall_condition: f32, // 0.0 to 1.0
    pub initial_parts: Vec<InstalledPart>,
}

impl MarketCar {
    /// Calculate current market value of an owned car given mileage and parts condition.
    pub fn calculate_resale_value(base_price: u32, mileage_km: u32, avg_condition: f32) -> u32 {
        let mileage_factor = (1.0 - (mileage_km as f32 / 200_000.0).clamp(0.0, 0.4)).max(0.6);
        let condition_factor = 0.35 + 0.65 * avg_condition.clamp(0.1, 1.0);
        ((base_price as f32) * mileage_factor * condition_factor).round() as u32
    }
}

/// Catalog of cars available across the three Evolution eras.
pub fn get_dealership_catalog() -> Vec<MarketCar> {
    vec![
        // Classic Era (1950 - 1969)
        MarketCar {
            id: "356_ferdinand".into(),
            model_name: "356_1".into(),
            sim_name: "356coupe11".into(),
            display_name: "'50 356 Ferdinand".into(),
            year: 1950,
            era: TournamentEra::Classic,
            is_used: false,
            mileage_km: 0,
            base_price: 11000,
            price: 11000,
            overall_condition: 1.0,
            initial_parts: vec![],
        },
        MarketCar {
            id: "356a_coupe".into(),
            model_name: "356a".into(),
            sim_name: "356acoupe16".into(),
            display_name: "'56 356 A 1600 Coupe".into(),
            year: 1956,
            era: TournamentEra::Classic,
            is_used: false,
            mileage_km: 0,
            base_price: 14500,
            price: 14500,
            overall_condition: 1.0,
            initial_parts: vec![],
        },
        MarketCar {
            id: "356b_carrera".into(),
            model_name: "356b".into(),
            sim_name: "356bcarrera2".into(),
            display_name: "'60 356 B 2000 GS Carrera 2".into(),
            year: 1960,
            era: TournamentEra::Classic,
            is_used: false,
            mileage_km: 0,
            base_price: 21000,
            price: 21000,
            overall_condition: 1.0,
            initial_parts: vec![],
        },
        MarketCar {
            id: "550_spyder".into(),
            model_name: "550".into(),
            sim_name: "550aspyder".into(),
            display_name: "'56 550 A Spyder".into(),
            year: 1956,
            era: TournamentEra::Classic,
            is_used: false,
            mileage_km: 0,
            base_price: 32000,
            price: 32000,
            overall_condition: 1.0,
            initial_parts: vec![],
        },
        MarketCar {
            id: "901_coupe".into(),
            model_name: "901".into(),
            sim_name: "911coupe".into(),
            display_name: "'64 911 Coupe (901)".into(),
            year: 1964,
            era: TournamentEra::Classic,
            is_used: false,
            mileage_km: 0,
            base_price: 26000,
            price: 26000,
            overall_condition: 1.0,
            initial_parts: vec![],
        },
        // Golden Era (1970 - 1988)
        MarketCar {
            id: "914_4".into(),
            model_name: "914".into(),
            sim_name: "914_4".into(),
            display_name: "'70 914/4".into(),
            year: 1970,
            era: TournamentEra::Golden,
            is_used: false,
            mileage_km: 0,
            base_price: 18000,
            price: 18000,
            overall_condition: 1.0,
            initial_parts: vec![],
        },
        MarketCar {
            id: "930_turbo".into(),
            model_name: "930".into(),
            sim_name: "911turbo33".into(),
            display_name: "'78 911 Turbo 3.3 (930)".into(),
            year: 1978,
            era: TournamentEra::Golden,
            is_used: false,
            mileage_km: 0,
            base_price: 48000,
            price: 48000,
            overall_condition: 1.0,
            initial_parts: vec![],
        },
        MarketCar {
            id: "944_coupe".into(),
            model_name: "944".into(),
            sim_name: "944".into(),
            display_name: "'82 944".into(),
            year: 1982,
            era: TournamentEra::Golden,
            is_used: false,
            mileage_km: 0,
            base_price: 34000,
            price: 34000,
            overall_condition: 1.0,
            initial_parts: vec![],
        },
        MarketCar {
            id: "928_gt".into(),
            model_name: "928".into(),
            sim_name: "928".into(),
            display_name: "'78 928".into(),
            year: 1978,
            era: TournamentEra::Golden,
            is_used: false,
            mileage_km: 0,
            base_price: 52000,
            price: 52000,
            overall_condition: 1.0,
            initial_parts: vec![],
        },
        // Modern Era (1989 - 2000)
        MarketCar {
            id: "964_carrera".into(),
            model_name: "964".into(),
            sim_name: "964carrera2".into(),
            display_name: "'89 911 Carrera 2 (964)".into(),
            year: 1989,
            era: TournamentEra::Modern,
            is_used: false,
            mileage_km: 0,
            base_price: 65000,
            price: 65000,
            overall_condition: 1.0,
            initial_parts: vec![],
        },
        MarketCar {
            id: "993_carrera".into(),
            model_name: "993".into(),
            sim_name: "993carrera".into(),
            display_name: "'95 911 Carrera (993)".into(),
            year: 1995,
            era: TournamentEra::Modern,
            is_used: false,
            mileage_km: 0,
            base_price: 78000,
            price: 78000,
            overall_condition: 1.0,
            initial_parts: vec![],
        },
        MarketCar {
            id: "boxster_986".into(),
            model_name: "boxster".into(),
            sim_name: "boxster".into(),
            display_name: "'97 Boxster (986)".into(),
            year: 1997,
            era: TournamentEra::Modern,
            is_used: false,
            mileage_km: 0,
            base_price: 55000,
            price: 55000,
            overall_condition: 1.0,
            initial_parts: vec![],
        },
        MarketCar {
            id: "996_carrera".into(),
            model_name: "996".into(),
            sim_name: "996carrera".into(),
            display_name: "'98 911 Carrera (996)".into(),
            year: 1998,
            era: TournamentEra::Modern,
            is_used: false,
            mileage_km: 0,
            base_price: 88000,
            price: 88000,
            overall_condition: 1.0,
            initial_parts: vec![],
        },
        MarketCar {
            id: "gt3_996".into(),
            model_name: "gt3".into(),
            sim_name: "996gt3".into(),
            display_name: "'99 911 GT3 (996)".into(),
            year: 1999,
            era: TournamentEra::Modern,
            is_used: false,
            mileage_km: 0,
            base_price: 125000,
            price: 125000,
            overall_condition: 1.0,
            initial_parts: vec![],
        },
    ]
}

/// Generate used car listings for market with wear and discounted prices.
pub fn generate_used_car_market(era: TournamentEra) -> Vec<MarketCar> {
    let mut catalog = get_dealership_catalog();
    catalog.retain(|c| c.era <= era);

    let mut used = Vec::new();
    for (i, c) in catalog.into_iter().enumerate() {
        let mileage = 25_000 + ((i as u32 * 17_421) % 65_000);
        let condition = 0.55 + ((i as f32 * 0.13) % 0.35);
        let price = MarketCar::calculate_resale_value(c.base_price, mileage, condition);
        used.push(MarketCar {
            id: format!("used_{}", c.id),
            model_name: c.model_name,
            sim_name: c.sim_name,
            display_name: format!("{} [Б/У, {} км]", c.display_name, mileage),
            year: c.year,
            era: c.era,
            is_used: true,
            mileage_km: mileage,
            base_price: c.base_price,
            price,
            overall_condition: condition,
            initial_parts: vec![
                InstalledPart {
                    part_id: 27,
                    name: "Тормозная система".into(),
                    category: PartCategory::Brakes,
                    condition,
                    price: 250,
                    modifier_value: 1.0,
                },
                InstalledPart {
                    part_id: 42,
                    name: "Амортизаторы и подвеска".into(),
                    category: PartCategory::Shocks,
                    condition,
                    price: 200,
                    modifier_value: 1.0,
                },
            ],
        });
    }
    used
}

/// Catalog item available in the Parts Shop.
#[derive(Debug, Clone, PartialEq)]
pub struct ShopPart {
    pub part_id: u32,
    pub name: String,
    pub compatible_car_model: String,
    pub category: PartCategory,
    pub price: u32,
    pub modifier_value: f32,
    pub description: String,
}

/// Catalog of standard tuning parts for purchase.
pub fn get_standard_parts_shop() -> Vec<ShopPart> {
    vec![
        // 356 Parts
        ShopPart {
            part_id: 13,
            name: "1100 Engine Upgrade".into(),
            compatible_car_model: "356".into(),
            category: PartCategory::Engine,
            price: 900,
            modifier_value: 1.10,
            description: "Увеличение мощности двигателя на 10%.".into(),
        },
        ShopPart {
            part_id: 14,
            name: "1300 Engine Upgrade".into(),
            compatible_car_model: "356".into(),
            category: PartCategory::Engine,
            price: 1000,
            modifier_value: 1.20,
            description: "Увеличение мощности двигателя на 20%.".into(),
        },
        ShopPart {
            part_id: 16,
            name: "1500 S Engine Upgrade".into(),
            compatible_car_model: "356".into(),
            category: PartCategory::Engine,
            price: 1450,
            modifier_value: 1.35,
            description: "Спортивный двигатель 1500 S: +35% к мощности.".into(),
        },
        ShopPart {
            part_id: 27,
            name: "Standard Brake Package".into(),
            compatible_car_model: "356".into(),
            category: PartCategory::Brakes,
            price: 183,
            modifier_value: 1.0,
            description: "Стандартные заводские тормоза.".into(),
        },
        ShopPart {
            part_id: 37,
            name: "Sport Brake Package".into(),
            compatible_car_model: "356".into(),
            category: PartCategory::Brakes,
            price: 244,
            modifier_value: 1.35,
            description: "Усиленные тормозные колодки и барабаны: +35% торможения.".into(),
        },
        ShopPart {
            part_id: 43,
            name: "Sport Lowering Springs".into(),
            compatible_car_model: "356".into(),
            category: PartCategory::Springs,
            price: 170,
            modifier_value: 1.30,
            description: "Спортивные укороченные пружины подвески: -5мм клиренс.".into(),
        },
        ShopPart {
            part_id: 46,
            name: "Sport Shocks".into(),
            compatible_car_model: "356".into(),
            category: PartCategory::Shocks,
            price: 207,
            modifier_value: 1.40,
            description: "Газонаполненные спортивные амортизаторы.".into(),
        },
        ShopPart {
            part_id: 47,
            name: "Anti-Roll Sway Bars".into(),
            compatible_car_model: "356".into(),
            category: PartCategory::SwayBars,
            price: 98,
            modifier_value: 1.20,
            description: "Стабилизаторы поперечной устойчивости против кренов.".into(),
        },
        ShopPart {
            part_id: 50,
            name: "Competition Exhaust".into(),
            compatible_car_model: "356".into(),
            category: PartCategory::Exhaust,
            price: 320,
            modifier_value: 1.08,
            description: "Прямоточный гоночный выхлоп.".into(),
        },
        ShopPart {
            part_id: 51,
            name: "Race Tires (Semi-Slicks)".into(),
            compatible_car_model: "356".into(),
            category: PartCategory::Tires,
            price: 450,
            modifier_value: 1.20,
            description: "Гоночные шины повышенного сцепления: +20% к боковому удержанию.".into(),
        },
    ]
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_dealership_and_resale_formula() {
        let catalog = get_dealership_catalog();
        assert!(catalog.len() >= 14);

        // 356 Ferdinand base price is 11,000
        let res_new = MarketCar::calculate_resale_value(11000, 0, 1.0);
        assert_eq!(res_new, 11000);

        // With 50,000 km and 0.70 condition, resale value drops
        let res_used = MarketCar::calculate_resale_value(11000, 50_000, 0.70);
        assert!(res_used < 11000);
        assert!(res_used > 5000);
    }

    #[test]
    fn test_used_car_generation() {
        let used = generate_used_car_market(TournamentEra::Classic);
        assert!(!used.is_empty());
        for c in &used {
            assert!(c.is_used);
            assert!(c.mileage_km > 0);
            assert!(c.price < c.base_price);
            assert_eq!(c.era, TournamentEra::Classic);
        }
    }
}
