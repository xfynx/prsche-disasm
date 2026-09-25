//! Player profile, garage, career progression, and robust persistence.

use crate::economy::MarketCar;
use crate::parts::{InstalledPart, PartCategory, PerformanceModifiers};
use std::collections::BTreeMap;
use std::fs;
use std::path::Path;

/// Minimal, zero-dependency JSON value for deterministic serialization.
#[derive(Debug, Clone, PartialEq)]
pub enum JsonValue {
    Null,
    Bool(bool),
    Number(f64),
    String(String),
    Array(Vec<JsonValue>),
    Object(BTreeMap<String, JsonValue>),
}

impl JsonValue {
    pub fn as_str(&self) -> Option<&str> {
        match self {
            JsonValue::String(s) => Some(s),
            _ => None,
        }
    }

    pub fn as_u32(&self) -> Option<u32> {
        match self {
            JsonValue::Number(n) => Some(*n as u32),
            _ => None,
        }
    }

    pub fn as_f32(&self) -> Option<f32> {
        match self {
            JsonValue::Number(n) => Some(*n as f32),
            _ => None,
        }
    }

    pub fn as_usize(&self) -> Option<usize> {
        match self {
            JsonValue::Number(n) => Some(*n as usize),
            _ => None,
        }
    }

    pub fn as_array(&self) -> Option<&[JsonValue]> {
        match self {
            JsonValue::Array(a) => Some(a.as_slice()),
            _ => None,
        }
    }

    pub fn get(&self, key: &str) -> Option<&JsonValue> {
        match self {
            JsonValue::Object(m) => m.get(key),
            _ => None,
        }
    }

    pub fn serialize(&self) -> String {
        match self {
            JsonValue::Null => "null".to_string(),
            JsonValue::Bool(b) => {
                if *b {
                    "true".to_string()
                } else {
                    "false".to_string()
                }
            }
            JsonValue::Number(n) => {
                if n.fract() == 0.0 {
                    format!("{:.0}", n)
                } else {
                    format!("{:.4}", n)
                }
            }
            JsonValue::String(s) => {
                let mut out = String::with_capacity(s.len() + 2);
                out.push('"');
                for c in s.chars() {
                    match c {
                        '"' => out.push_str("\\\""),
                        '\\' => out.push_str("\\\\"),
                        '\n' => out.push_str("\\n"),
                        '\r' => out.push_str("\\r"),
                        '\t' => out.push_str("\\t"),
                        _ => out.push(c),
                    }
                }
                out.push('"');
                out
            }
            JsonValue::Array(arr) => {
                let items: Vec<String> = arr.iter().map(|item| item.serialize()).collect();
                format!("[{}]", items.join(","))
            }
            JsonValue::Object(obj) => {
                let pairs: Vec<String> = obj
                    .iter()
                    .map(|(k, v)| format!("\"{}\":{}", k, v.serialize()))
                    .collect();
                format!("{{{}}}", pairs.join(","))
            }
        }
    }
}

/// Parse JSON string into JsonValue.
pub fn parse_json(input: &str) -> Result<JsonValue, String> {
    let chars: Vec<char> = input.chars().collect();
    let mut pos = 0;
    skip_whitespace(&chars, &mut pos);
    let val = parse_value(&chars, &mut pos)?;
    skip_whitespace(&chars, &mut pos);
    if pos < chars.len() {
        return Err(format!("trailing characters at position {pos}"));
    }
    Ok(val)
}

fn skip_whitespace(chars: &[char], pos: &mut usize) {
    while *pos < chars.len() && chars[*pos].is_whitespace() {
        *pos += 1;
    }
}

fn parse_value(chars: &[char], pos: &mut usize) -> Result<JsonValue, String> {
    skip_whitespace(chars, pos);
    if *pos >= chars.len() {
        return Err("unexpected end of input".to_string());
    }

    match chars[*pos] {
        '{' => parse_object(chars, pos),
        '[' => parse_array(chars, pos),
        '"' => parse_string(chars, pos).map(JsonValue::String),
        't' | 'f' => parse_bool(chars, pos),
        'n' => parse_null(chars, pos),
        '-' | '0'..='9' => parse_number(chars, pos),
        c => Err(format!("unexpected character '{c}' at position {pos}")),
    }
}

fn parse_object(chars: &[char], pos: &mut usize) -> Result<JsonValue, String> {
    *pos += 1; // skip '{'
    let mut map = BTreeMap::new();
    loop {
        skip_whitespace(chars, pos);
        if *pos >= chars.len() {
            return Err("unclosed object".to_string());
        }
        if chars[*pos] == '}' {
            *pos += 1;
            break;
        }

        let key = parse_string(chars, pos)?;
        skip_whitespace(chars, pos);
        if *pos >= chars.len() || chars[*pos] != ':' {
            return Err(format!("expected ':' after key '{key}'"));
        }
        *pos += 1; // skip ':'

        let val = parse_value(chars, pos)?;
        map.insert(key, val);

        skip_whitespace(chars, pos);
        if *pos < chars.len() && chars[*pos] == ',' {
            *pos += 1;
        } else if *pos < chars.len() && chars[*pos] == '}' {
            *pos += 1;
            break;
        } else {
            return Err("expected ',' or '}' in object".to_string());
        }
    }
    Ok(JsonValue::Object(map))
}

fn parse_array(chars: &[char], pos: &mut usize) -> Result<JsonValue, String> {
    *pos += 1; // skip '['
    let mut arr = Vec::new();
    loop {
        skip_whitespace(chars, pos);
        if *pos >= chars.len() {
            return Err("unclosed array".to_string());
        }
        if chars[*pos] == ']' {
            *pos += 1;
            break;
        }

        let val = parse_value(chars, pos)?;
        arr.push(val);

        skip_whitespace(chars, pos);
        if *pos < chars.len() && chars[*pos] == ',' {
            *pos += 1;
        } else if *pos < chars.len() && chars[*pos] == ']' {
            *pos += 1;
            break;
        } else {
            return Err("expected ',' or ']' in array".to_string());
        }
    }
    Ok(JsonValue::Array(arr))
}

fn parse_string(chars: &[char], pos: &mut usize) -> Result<String, String> {
    if *pos >= chars.len() || chars[*pos] != '"' {
        return Err("expected '\"'".to_string());
    }
    *pos += 1; // skip '"'
    let mut s = String::new();
    while *pos < chars.len() {
        let c = chars[*pos];
        *pos += 1;
        match c {
            '"' => return Ok(s),
            '\\' => {
                if *pos >= chars.len() {
                    return Err("unterminated escape sequence".to_string());
                }
                let esc = chars[*pos];
                *pos += 1;
                match esc {
                    '"' => s.push('"'),
                    '\\' => s.push('\\'),
                    '/' => s.push('/'),
                    'b' => s.push('\x08'),
                    'f' => s.push('\x0c'),
                    'n' => s.push('\n'),
                    'r' => s.push('\r'),
                    't' => s.push('\t'),
                    _ => s.push(esc),
                }
            }
            _ => s.push(c),
        }
    }
    Err("unterminated string".to_string())
}

fn parse_bool(chars: &[char], pos: &mut usize) -> Result<JsonValue, String> {
    if chars[*pos..].starts_with(&['t', 'r', 'u', 'e']) {
        *pos += 4;
        Ok(JsonValue::Bool(true))
    } else if chars[*pos..].starts_with(&['f', 'a', 'l', 's', 'e']) {
        *pos += 5;
        Ok(JsonValue::Bool(false))
    } else {
        Err("invalid boolean literal".to_string())
    }
}

fn parse_null(chars: &[char], pos: &mut usize) -> Result<JsonValue, String> {
    if chars[*pos..].starts_with(&['n', 'u', 'l', 'l']) {
        *pos += 4;
        Ok(JsonValue::Null)
    } else {
        Err("invalid null literal".to_string())
    }
}

fn parse_number(chars: &[char], pos: &mut usize) -> Result<JsonValue, String> {
    let start = *pos;
    if *pos < chars.len() && chars[*pos] == '-' {
        *pos += 1;
    }
    while *pos < chars.len()
        && (chars[*pos].is_ascii_digit()
            || chars[*pos] == '.'
            || chars[*pos] == 'e'
            || chars[*pos] == 'E'
            || chars[*pos] == '+'
            || chars[*pos] == '-')
    {
        *pos += 1;
    }
    let s: String = chars[start..*pos].iter().collect();
    match s.parse::<f64>() {
        Ok(n) => Ok(JsonValue::Number(n)),
        Err(_) => Err(format!("invalid number: {s}")),
    }
}

fn installed_part_to_json(part: &InstalledPart) -> JsonValue {
    let mut map = BTreeMap::new();
    map.insert(
        "part_id".to_string(),
        JsonValue::Number(part.part_id as f64),
    );
    map.insert("name".to_string(), JsonValue::String(part.name.clone()));
    map.insert(
        "category".to_string(),
        JsonValue::String(format!("{:?}", part.category)),
    );
    map.insert(
        "condition".to_string(),
        JsonValue::Number(part.condition as f64),
    );
    map.insert("price".to_string(), JsonValue::Number(part.price as f64));
    map.insert(
        "modifier_value".to_string(),
        JsonValue::Number(part.modifier_value as f64),
    );
    JsonValue::Object(map)
}

fn installed_part_from_json(val: &JsonValue) -> Result<InstalledPart, String> {
    let part_id = val.get("part_id").and_then(|v| v.as_u32()).unwrap_or(0);
    let name = val
        .get("name")
        .and_then(|v| v.as_str())
        .unwrap_or("Part")
        .to_string();
    let cat_str = val
        .get("category")
        .and_then(|v| v.as_str())
        .unwrap_or("Other");
    let category = match cat_str {
        "Engine" => PartCategory::Engine,
        "Exhaust" => PartCategory::Exhaust,
        "Brakes" => PartCategory::Brakes,
        "Springs" => PartCategory::Springs,
        "Shocks" => PartCategory::Shocks,
        "SwayBars" => PartCategory::SwayBars,
        "Gearbox" => PartCategory::Gearbox,
        "Tires" => PartCategory::Tires,
        "WeightReduction" => PartCategory::WeightReduction,
        _ => PartCategory::Other,
    };
    let condition = val.get("condition").and_then(|v| v.as_f32()).unwrap_or(1.0);
    let price = val.get("price").and_then(|v| v.as_u32()).unwrap_or(0);
    let modifier_value = val
        .get("modifier_value")
        .and_then(|v| v.as_f32())
        .unwrap_or(1.0);

    Ok(InstalledPart {
        part_id,
        name,
        category,
        condition,
        price,
        modifier_value,
    })
}

/// Car owned by player in garage.
#[derive(Debug, Clone, PartialEq)]
pub struct OwnedCar {
    pub id: String,
    pub catalog_id: u32,
    pub display_name: String,
    pub model_name: String,
    pub sim_name: String,
    pub color_index: usize,
    pub mileage_km: f32,
    pub base_price: u32,
    pub condition: f32, // 0.0 (total wreck) .. 1.0 (mint)
    pub installed_parts: Vec<InstalledPart>,
}

impl OwnedCar {
    pub fn to_json(&self) -> JsonValue {
        let mut map = BTreeMap::new();
        map.insert("id".to_string(), JsonValue::String(self.id.clone()));
        map.insert(
            "catalog_id".to_string(),
            JsonValue::Number(self.catalog_id as f64),
        );
        map.insert(
            "display_name".to_string(),
            JsonValue::String(self.display_name.clone()),
        );
        map.insert(
            "model_name".to_string(),
            JsonValue::String(self.model_name.clone()),
        );
        map.insert(
            "sim_name".to_string(),
            JsonValue::String(self.sim_name.clone()),
        );
        map.insert(
            "color_index".to_string(),
            JsonValue::Number(self.color_index as f64),
        );
        map.insert(
            "mileage_km".to_string(),
            JsonValue::Number(self.mileage_km as f64),
        );
        map.insert(
            "base_price".to_string(),
            JsonValue::Number(self.base_price as f64),
        );
        map.insert(
            "condition".to_string(),
            JsonValue::Number(self.condition as f64),
        );
        map.insert(
            "installed_parts".to_string(),
            JsonValue::Array(
                self.installed_parts
                    .iter()
                    .map(installed_part_to_json)
                    .collect(),
            ),
        );
        JsonValue::Object(map)
    }

    pub fn from_json(val: &JsonValue) -> Result<Self, String> {
        let id = val
            .get("id")
            .and_then(|v| v.as_str())
            .unwrap_or("car_0")
            .to_string();
        let catalog_id = val.get("catalog_id").and_then(|v| v.as_u32()).unwrap_or(0);
        let display_name = val
            .get("display_name")
            .and_then(|v| v.as_str())
            .unwrap_or("Porsche")
            .to_string();
        let model_name = val
            .get("model_name")
            .and_then(|v| v.as_str())
            .unwrap_or("356_1")
            .to_string();
        let sim_name = val
            .get("sim_name")
            .and_then(|v| v.as_str())
            .unwrap_or("356coupe11")
            .to_string();
        let color_index = val
            .get("color_index")
            .and_then(|v| v.as_usize())
            .unwrap_or(0);
        let mileage_km = val
            .get("mileage_km")
            .and_then(|v| v.as_f32())
            .unwrap_or(0.0);
        let base_price = val
            .get("base_price")
            .and_then(|v| v.as_u32())
            .unwrap_or(11_000);
        let condition = val.get("condition").and_then(|v| v.as_f32()).unwrap_or(1.0);

        let mut installed_parts = Vec::new();
        if let Some(arr) = val.get("installed_parts").and_then(|v| v.as_array()) {
            for p_val in arr {
                installed_parts.push(installed_part_from_json(p_val)?);
            }
        }

        Ok(Self {
            id,
            catalog_id,
            display_name,
            model_name,
            sim_name,
            color_index,
            mileage_km,
            base_price,
            condition,
            installed_parts,
        })
    }

    /// Calculate resale value using mileage and parts condition.
    pub fn calculate_resale_value(&self) -> u32 {
        let parts_condition = if self.installed_parts.is_empty() {
            self.condition
        } else {
            let sum: f32 = self.installed_parts.iter().map(|p| p.condition).sum();
            (self.condition + (sum / self.installed_parts.len() as f32)) * 0.5
        };
        MarketCar::calculate_resale_value(
            self.base_price,
            self.mileage_km.round() as u32,
            parts_condition,
        )
    }

    /// Calculate total repair cost for body + parts.
    pub fn repair_cost(&self) -> u32 {
        let body_wear = (1.0 - self.condition).clamp(0.0, 1.0);
        let body_cost = ((self.base_price as f32) * body_wear * 0.4).round() as u32;
        let parts_cost: u32 = self.installed_parts.iter().map(|p| p.repair_cost()).sum();
        body_cost + parts_cost
    }

    /// Fully repair vehicle body and all installed parts.
    pub fn repair(&mut self) {
        self.condition = 1.0;
        for part in &mut self.installed_parts {
            part.repair();
        }
    }

    /// Apply race wear (distance in km and collision impact damage in 0.0..1.0).
    pub fn apply_wear(&mut self, distance_km: f32, collision_damage: f32) {
        self.mileage_km += distance_km;
        self.condition = (self.condition - collision_damage - distance_km * 0.001).clamp(0.05, 1.0);
        for part in &mut self.installed_parts {
            part.apply_wear(distance_km);
            if collision_damage > 0.05 {
                part.condition = (part.condition - collision_damage * 0.5).clamp(0.05, 1.0);
            }
        }
    }

    /// Compute aggregated performance multipliers from installed tuning parts.
    pub fn performance_modifiers(&self) -> PerformanceModifiers {
        PerformanceModifiers::from_installed_parts(&self.installed_parts)
    }
}

/// Evolution career progression state.
#[derive(Debug, Clone, PartialEq)]
pub struct EvolutionState {
    pub unlocked_tournaments: Vec<u32>,
    pub completed_tournaments: Vec<u32>,
    pub current_stage: u32,
    pub total_prize_money: u32,
}

impl Default for EvolutionState {
    fn default() -> Self {
        Self {
            unlocked_tournaments: vec![0], // Classic Tournament 1: 356 Challenge unlocked
            completed_tournaments: Vec::new(),
            current_stage: 0,
            total_prize_money: 0,
        }
    }
}

impl EvolutionState {
    pub fn to_json(&self) -> JsonValue {
        let mut map = BTreeMap::new();
        map.insert(
            "unlocked_tournaments".to_string(),
            JsonValue::Array(
                self.unlocked_tournaments
                    .iter()
                    .map(|&t| JsonValue::Number(t as f64))
                    .collect(),
            ),
        );
        map.insert(
            "completed_tournaments".to_string(),
            JsonValue::Array(
                self.completed_tournaments
                    .iter()
                    .map(|&t| JsonValue::Number(t as f64))
                    .collect(),
            ),
        );
        map.insert(
            "current_stage".to_string(),
            JsonValue::Number(self.current_stage as f64),
        );
        map.insert(
            "total_prize_money".to_string(),
            JsonValue::Number(self.total_prize_money as f64),
        );
        JsonValue::Object(map)
    }

    pub fn from_json(val: &JsonValue) -> Self {
        let mut state = Self::default();
        if let Some(unlocked) = val.get("unlocked_tournaments").and_then(|v| v.as_array()) {
            state.unlocked_tournaments = unlocked.iter().filter_map(|x| x.as_u32()).collect();
        }
        if let Some(completed) = val.get("completed_tournaments").and_then(|v| v.as_array()) {
            state.completed_tournaments = completed.iter().filter_map(|x| x.as_u32()).collect();
        }
        if let Some(stage) = val.get("current_stage").and_then(|v| v.as_u32()) {
            state.current_stage = stage;
        }
        if let Some(prizes) = val.get("total_prize_money").and_then(|v| v.as_u32()) {
            state.total_prize_money = prizes;
        }
        state
    }
}

/// Factory Driver progression state.
#[derive(Debug, Clone, PartialEq)]
pub struct FactoryDriverState {
    pub current_mission_code: String,
    pub completed_missions: Vec<String>,
    pub best_times: BTreeMap<String, f32>,
    pub driver_rank: String,
}

impl Default for FactoryDriverState {
    fn default() -> Self {
        Self {
            current_mission_code: "0M01".to_string(),
            completed_missions: Vec::new(),
            best_times: BTreeMap::new(),
            driver_rank: "Applicant".to_string(),
        }
    }
}

impl FactoryDriverState {
    pub fn to_json(&self) -> JsonValue {
        let mut map = BTreeMap::new();
        map.insert(
            "current_mission_code".to_string(),
            JsonValue::String(self.current_mission_code.clone()),
        );
        map.insert(
            "completed_missions".to_string(),
            JsonValue::Array(
                self.completed_missions
                    .iter()
                    .map(|s| JsonValue::String(s.clone()))
                    .collect(),
            ),
        );
        let times_map: BTreeMap<String, JsonValue> = self
            .best_times
            .iter()
            .map(|(k, &v)| (k.clone(), JsonValue::Number(v as f64)))
            .collect();
        map.insert("best_times".to_string(), JsonValue::Object(times_map));
        map.insert(
            "driver_rank".to_string(),
            JsonValue::String(self.driver_rank.clone()),
        );
        JsonValue::Object(map)
    }

    pub fn from_json(val: &JsonValue) -> Self {
        let mut state = Self::default();
        if let Some(code) = val.get("current_mission_code").and_then(|v| v.as_str()) {
            state.current_mission_code = code.to_string();
        }
        if let Some(completed) = val.get("completed_missions").and_then(|v| v.as_array()) {
            state.completed_missions = completed
                .iter()
                .filter_map(|x| x.as_str().map(|s| s.to_string()))
                .collect();
        }
        if let Some(JsonValue::Object(times)) = val.get("best_times") {
            for (k, v) in times {
                if let Some(t) = v.as_f32() {
                    state.best_times.insert(k.clone(), t);
                }
            }
        }
        if let Some(rank) = val.get("driver_rank").and_then(|v| v.as_str()) {
            state.driver_rank = rank.to_string();
        }
        state
    }
}

/// Comprehensive player profile.
#[derive(Debug, Clone, PartialEq)]
pub struct PlayerProfile {
    pub version: u32,
    pub id: String,
    pub name: String,
    pub credits: u32,
    pub garage: Vec<OwnedCar>,
    pub selected_car_index: usize,
    pub evolution: EvolutionState,
    pub factory_driver: FactoryDriverState,
}

impl PlayerProfile {
    pub const CURRENT_VERSION: u32 = 1;

    /// Create a new career profile with starting 11,000 credits.
    pub fn new(name: &str) -> Self {
        let clean_name = name.trim();
        let display_name = if clean_name.is_empty() {
            "Driver"
        } else {
            clean_name
        };
        let id = format!("prof_{}", display_name.to_lowercase().replace(' ', "_"));

        Self {
            version: Self::CURRENT_VERSION,
            id,
            name: display_name.to_string(),
            credits: 11_000, // Confirmed starting credits from XXDefXX.sav
            garage: Vec::new(),
            selected_car_index: 0,
            evolution: EvolutionState::default(),
            factory_driver: FactoryDriverState::default(),
        }
    }

    /// Purchase starting car (e.g. '50 356 1100 Coupé Ferdinand for 11,000 credits).
    pub fn buy_initial_356(&mut self) -> Result<&OwnedCar, String> {
        if self.credits < 11_000 {
            return Err("Insufficient credits to purchase initial 356 (needs 11,000)".to_string());
        }
        self.credits -= 11_000;
        let car = OwnedCar {
            id: format!("car_{}", self.garage.len() + 1),
            catalog_id: 1, // '50 356 1100 Coupé Ferdinand
            display_name: "'50 356 1100 Coupé Ferdinand".to_string(),
            model_name: "356_1".to_string(),
            sim_name: "356coupe11".to_string(),
            color_index: 0,
            mileage_km: 0.0,
            base_price: 11_000,
            condition: 1.0,
            installed_parts: Vec::new(),
        };
        self.garage.push(car);
        self.selected_car_index = self.garage.len() - 1;
        Ok(&self.garage[self.selected_car_index])
    }

    /// Purchase car from market catalog (dealership or used car lot).
    pub fn buy_car(&mut self, market_car: &MarketCar) -> Result<&OwnedCar, String> {
        if self.credits < market_car.price {
            return Err(format!(
                "Insufficient credits (have {}, need {})",
                self.credits, market_car.price
            ));
        }
        self.credits -= market_car.price;
        let car = OwnedCar {
            id: format!("car_{}_{}", self.garage.len() + 1, market_car.model_name),
            catalog_id: self.garage.len() as u32 + 1,
            display_name: market_car.display_name.clone(),
            model_name: market_car.model_name.clone(),
            sim_name: market_car.sim_name.clone(),
            color_index: 0,
            mileage_km: market_car.mileage_km as f32,
            base_price: market_car.base_price,
            condition: market_car.overall_condition,
            installed_parts: market_car.initial_parts.clone(),
        };
        self.garage.push(car);
        self.selected_car_index = self.garage.len() - 1;
        Ok(&self.garage[self.selected_car_index])
    }

    /// Sell car from garage, crediting player with resale value.
    pub fn sell_car(&mut self, car_index: usize) -> Result<u32, String> {
        if car_index >= self.garage.len() {
            return Err("Car index out of bounds".to_string());
        }
        if self.garage.len() <= 1 {
            return Err("Cannot sell the last remaining car in garage".to_string());
        }
        let car = self.garage.remove(car_index);
        let resale_value = car.calculate_resale_value();
        self.credits += resale_value;
        if self.selected_car_index >= self.garage.len() {
            self.selected_car_index = self.garage.len() - 1;
        }
        Ok(resale_value)
    }

    /// Buy and install a tuning part onto selected car.
    pub fn buy_and_install_part(
        &mut self,
        car_index: usize,
        part: InstalledPart,
    ) -> Result<(), String> {
        if car_index >= self.garage.len() {
            return Err("Car index out of bounds".to_string());
        }
        if self.credits < part.price {
            return Err(format!(
                "Insufficient credits (have {}, need {})",
                self.credits, part.price
            ));
        }
        self.credits -= part.price;
        let car = &mut self.garage[car_index];
        // Replace existing part in same category if present, otherwise append
        if let Some(pos) = car
            .installed_parts
            .iter()
            .position(|p| p.category == part.category)
        {
            car.installed_parts[pos] = part;
        } else {
            car.installed_parts.push(part);
        }
        Ok(())
    }

    /// Repair car (body and installed parts) using player credits.
    pub fn repair_car(&mut self, car_index: usize) -> Result<u32, String> {
        if car_index >= self.garage.len() {
            return Err("Car index out of bounds".to_string());
        }
        let cost = self.garage[car_index].repair_cost();
        if cost == 0 {
            return Ok(0);
        }
        if self.credits < cost {
            return Err(format!(
                "Insufficient credits for repair (have {}, need {})",
                self.credits, cost
            ));
        }
        self.credits -= cost;
        self.garage[car_index].repair();
        Ok(cost)
    }

    /// Serialize profile to JSON string.
    pub fn to_json_string(&self) -> String {
        let mut map = BTreeMap::new();
        map.insert(
            "version".to_string(),
            JsonValue::Number(self.version as f64),
        );
        map.insert("id".to_string(), JsonValue::String(self.id.clone()));
        map.insert("name".to_string(), JsonValue::String(self.name.clone()));
        map.insert(
            "credits".to_string(),
            JsonValue::Number(self.credits as f64),
        );
        map.insert(
            "garage".to_string(),
            JsonValue::Array(self.garage.iter().map(|c| c.to_json()).collect()),
        );
        map.insert(
            "selected_car_index".to_string(),
            JsonValue::Number(self.selected_car_index as f64),
        );
        map.insert("evolution".to_string(), self.evolution.to_json());
        map.insert("factory_driver".to_string(), self.factory_driver.to_json());
        JsonValue::Object(map).serialize()
    }

    /// Parse profile from JSON string.
    pub fn from_json_string(json: &str) -> Result<Self, String> {
        let val = parse_json(json)?;
        let version = val
            .get("version")
            .and_then(|v| v.as_u32())
            .unwrap_or(Self::CURRENT_VERSION);
        if version > Self::CURRENT_VERSION {
            return Err(format!(
                "unsupported profile version {version}, expected <= {}",
                Self::CURRENT_VERSION
            ));
        }

        let id = val
            .get("id")
            .and_then(|v| v.as_str())
            .unwrap_or("prof_default")
            .to_string();
        let name = val
            .get("name")
            .and_then(|v| v.as_str())
            .unwrap_or("Driver")
            .to_string();
        let credits = val.get("credits").and_then(|v| v.as_u32()).unwrap_or(0);
        let selected_car_index = val
            .get("selected_car_index")
            .and_then(|v| v.as_usize())
            .unwrap_or(0);

        let mut garage = Vec::new();
        if let Some(arr) = val.get("garage").and_then(|v| v.as_array()) {
            for c_val in arr {
                garage.push(OwnedCar::from_json(c_val)?);
            }
        }

        let evolution = val
            .get("evolution")
            .map(EvolutionState::from_json)
            .unwrap_or_default();
        let factory_driver = val
            .get("factory_driver")
            .map(FactoryDriverState::from_json)
            .unwrap_or_default();

        Ok(Self {
            version,
            id,
            name,
            credits,
            garage,
            selected_car_index,
            evolution,
            factory_driver,
        })
    }

    /// Save profile atomically to disk (write to tmp file, flush, then rename).
    pub fn save_atomic(&self, target_path: &Path) -> Result<(), String> {
        if let Some(parent) = target_path.parent() {
            fs::create_dir_all(parent)
                .map_err(|e| format!("failed to create profile directory: {e}"))?;
        }

        let tmp_path = target_path.with_extension("tmp");
        let content = self.to_json_string();
        fs::write(&tmp_path, content.as_bytes())
            .map_err(|e| format!("failed to write temp profile: {e}"))?;

        // Atomic replace
        fs::rename(&tmp_path, target_path)
            .map_err(|e| format!("failed to atomically replace profile: {e}"))?;
        Ok(())
    }

    /// Load profile safely from disk.
    pub fn load_from_path(target_path: &Path) -> Result<Self, String> {
        if !target_path.exists() {
            return Err(format!(
                "profile file does not exist: {}",
                target_path.display()
            ));
        }

        let content = fs::read_to_string(target_path)
            .map_err(|e| format!("failed to read profile file: {e}"))?;
        Self::from_json_string(&content)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_new_profile_defaults() {
        let p = PlayerProfile::new("Alex");
        assert_eq!(p.name, "Alex");
        assert_eq!(p.id, "prof_alex");
        assert_eq!(p.credits, 11000);
        assert!(p.garage.is_empty());
        assert_eq!(p.evolution.unlocked_tournaments, vec![0]);
        assert_eq!(p.factory_driver.current_mission_code, "0M01");
        assert_eq!(p.factory_driver.driver_rank, "Applicant");
    }

    #[test]
    fn test_car_purchase_and_credits_deduction() {
        let mut p = PlayerProfile::new("Racer");
        assert_eq!(p.credits, 11000);
        let car = p.buy_initial_356().unwrap();
        assert_eq!(car.display_name, "'50 356 1100 Coupé Ferdinand");
        assert_eq!(car.sim_name, "356coupe11");
        assert_eq!(p.credits, 0);
        assert_eq!(p.garage.len(), 1);

        // Cannot buy again with 0 credits
        let err = p.buy_initial_356();
        assert!(err.is_err());
    }

    #[test]
    fn test_profile_json_roundtrip() {
        let mut p = PlayerProfile::new("TestPilot");
        p.buy_initial_356().unwrap();
        p.credits = 4500;
        p.evolution.completed_tournaments.push(0);
        p.evolution.total_prize_money = 4500;
        p.factory_driver.completed_missions.push("0M01".to_string());
        p.factory_driver.current_mission_code = "1m01".to_string();
        p.factory_driver.best_times.insert("0M01".to_string(), 28.5);
        p.factory_driver.driver_rank = "Junior Test Driver".to_string();

        let json = p.to_json_string();
        let loaded = PlayerProfile::from_json_string(&json).unwrap();
        assert_eq!(p, loaded);
    }

    #[test]
    fn test_atomic_file_persistence() {
        let temp_dir = std::env::temp_dir().join("nfs_test_profiles");
        let profile_path = temp_dir.join("test_save.json");

        let mut p = PlayerProfile::new("AtomicSaver");
        p.buy_initial_356().unwrap();
        p.save_atomic(&profile_path).unwrap();

        assert!(profile_path.exists());
        let reloaded = PlayerProfile::load_from_path(&profile_path).unwrap();
        assert_eq!(reloaded.name, "AtomicSaver");
        assert_eq!(reloaded.credits, 0);
        assert_eq!(reloaded.garage.len(), 1);

        // Cleanup
        let _ = fs::remove_file(profile_path);
        let _ = fs::remove_dir(temp_dir);
    }

    #[test]
    fn test_corrupt_json_rejected() {
        let corrupt = "{\"version\":1, \"name\": \"broken\", \"credits\": }";
        let res = PlayerProfile::from_json_string(corrupt);
        assert!(res.is_err());
    }

    #[test]
    fn test_buy_and_sell_market_car() {
        use crate::economy::get_dealership_catalog;
        let mut p = PlayerProfile::new("Trader");
        p.credits = 50_000;
        let catalog = get_dealership_catalog();
        let ferdinand = &catalog[0]; // 11000 CR
        let speedster = &catalog[2]; // 17500 CR

        let ferdinand_price = ferdinand.price;
        let second_price = speedster.price;

        p.buy_car(ferdinand).unwrap();
        p.buy_car(speedster).unwrap();
        assert_eq!(p.garage.len(), 2);
        assert_eq!(p.credits, 50_000 - ferdinand_price - second_price);

        // Cannot sell if only 1 car left, but can sell when 2 cars
        let resale = p.sell_car(1).unwrap();
        assert!(resale > 10_000);
        assert_eq!(p.garage.len(), 1);

        // Selling the last car fails
        assert!(p.sell_car(0).is_err());
    }

    #[test]
    fn test_parts_upgrade_and_repair_flow() {
        let mut p = PlayerProfile::new("Tuner");
        p.buy_initial_356().unwrap();
        p.credits = 5_000;

        // Upgrade brakes
        let brake_part = InstalledPart::new(101, "Racing Brakes", PartCategory::Brakes, 1200, 1.25);
        p.buy_and_install_part(0, brake_part).unwrap();
        assert_eq!(p.credits, 3_800);
        assert_eq!(p.garage[0].installed_parts.len(), 1);

        let mods = p.garage[0].performance_modifiers();
        assert!(mods.brake_multiplier > 1.2);

        // Race wear
        p.garage[0].apply_wear(100.0, 0.2); // 100km and 20% impact damage
        assert!(p.garage[0].condition < 0.8);
        assert!(p.garage[0].installed_parts[0].condition < 1.0);

        // Repair
        let cost = p.garage[0].repair_cost();
        assert!(cost > 0);
        let paid = p.repair_car(0).unwrap();
        assert_eq!(cost, paid);
        assert_eq!(p.garage[0].condition, 1.0);
        assert_eq!(p.garage[0].installed_parts[0].condition, 1.0);
    }
}
