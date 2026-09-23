//! Factory Driver (Заводской водитель) mode implementation.
//!
//! Replicates all 34 authentic missions from `nfs5.fac`, stunt evaluation
//! (180° slide, 360° spin, reverse J-turn, cone slalom, delivery damage limits),
//! rank promotions, and bonus car awards.

use crate::parts::InstalledPart;
use crate::profile::{OwnedCar, PlayerProfile};

/// Driver rank within the Porsche Factory Test Team.
#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord)]
pub enum FactoryRank {
    Applicant = 1,
    JuniorTestDriver = 2,
    TestDriver = 3,
    SeniorTestDriver = 4,
    ChiefTestDriver = 5,
    MasterAce = 6,
}

impl FactoryRank {
    pub fn display_name(&self) -> &'static str {
        match self {
            FactoryRank::Applicant => "Кандидат (Applicant)",
            FactoryRank::JuniorTestDriver => "Младший испытатель (Junior Test Driver)",
            FactoryRank::TestDriver => "Тест-пилот (Test Driver)",
            FactoryRank::SeniorTestDriver => "Старший тест-пилот (Senior Test Driver)",
            FactoryRank::ChiefTestDriver => "Шеф-испытатель (Chief Test Driver)",
            FactoryRank::MasterAce => "Мастер-пилот Porsche (Ace Driver)",
        }
    }

    pub fn from_rank_str(s: &str) -> Self {
        match s.to_lowercase().as_str() {
            "junior test driver" => FactoryRank::JuniorTestDriver,
            "test driver" => FactoryRank::TestDriver,
            "senior test driver" => FactoryRank::SeniorTestDriver,
            "chief test driver" => FactoryRank::ChiefTestDriver,
            "master test driver" | "ace" | "master-pilot" => FactoryRank::MasterAce,
            _ => FactoryRank::Applicant,
        }
    }
}

/// Mission objectives supported in Factory Driver.
#[derive(Debug, Clone, PartialEq)]
pub enum MissionType {
    /// Navigate course / slalom within time limit; cone hits add penalty seconds.
    SlalomCourse {
        time_limit_sec: f32,
        cone_penalty_sec: f32,
    },
    /// Stunt exercise requiring a 360° spin using emergency brake.
    Spin360Exercise {
        time_limit_sec: f32,
        required_spins: u32,
    },
    /// Stunt exercise requiring a 180° slide.
    Slide180Exercise {
        time_limit_sec: f32,
        required_slides: u32,
    },
    /// Complex Porsche commercial gymkhana: 180° slide, reverse drive, 180° slide, and 360° spin.
    PorscheCommercial { time_limit_sec: f32 },
    /// Deliver vehicle across track without exceeding maximum allowable damage.
    CarDelivery {
        time_limit_sec: f32,
        max_damage_allowed: f32,
    },
    /// Head-to-head duel race against a team member (Billy, Frank, Rolf, Stephanie).
    DuelRace {
        laps: u32,
        opponent_name: &'static str,
    },
    /// Knock over specified number of rally cones in sequence.
    CaptureTheFlag {
        time_limit_sec: f32,
        total_flags: u32,
    },
}

/// A complete Factory Driver mission definition.
#[derive(Debug, Clone, PartialEq)]
pub struct FactoryMission {
    pub mission_index: usize, // 1..34
    pub code: String,         // "0M01", "1m01".."1m12", "2m01".."2m10", "3m01".."3m11"
    pub tier: u32,            // 1, 2, 3
    pub title: String,
    pub briefing: String,
    pub tip: String,
    pub car_model: String,
    pub car_sim: String,
    pub track_id: String,
    pub track_name: String,
    pub mission_type: MissionType,
    pub target_rank_on_completion: Option<FactoryRank>,
    pub reward_car: Option<OwnedCar>,
    pub pass_message: String,
    pub fail_message: String,
}

/// Stunt detector keeping track of vehicle dynamic stunts during mission.
#[derive(Debug, Clone, Default)]
pub struct StuntDetector {
    pub last_heading: f32,
    pub cumulative_yaw_radians: f32,
    pub reverse_duration_sec: f32,
    pub has_done_180: bool,
    pub has_done_360: bool,
    pub has_done_jturn: bool,
    pub cone_hits: u32,
    pub current_damage: f32, // 0.0 (mint) .. 1.0 (wrecked)
}

#[derive(Debug, Clone, PartialEq)]
pub enum StuntEvent {
    Spin180Detected,
    Spin360Detected,
    JTurnDetected,
    ConeCollision { penalty_seconds: f32 },
}

impl StuntDetector {
    pub fn new() -> Self {
        Self::default()
    }

    /// Reset stunt status for fresh attempt.
    pub fn reset(&mut self, initial_heading: f32) {
        self.last_heading = initial_heading;
        self.cumulative_yaw_radians = 0.0;
        self.reverse_duration_sec = 0.0;
        self.has_done_180 = false;
        self.has_done_360 = false;
        self.has_done_jturn = false;
        self.cone_hits = 0;
        self.current_damage = 0.0;
    }

    /// Update detector with vehicle telemetry each frame/tick.
    pub fn update(
        &mut self,
        dt: f32,
        speed_m_s: f32,
        heading_rad: f32,
        is_reverse_gear: bool,
        handbrake_pressed: bool,
        damage: f32,
    ) -> Vec<StuntEvent> {
        let mut events = Vec::new();
        self.current_damage = damage;

        if dt <= 0.0 {
            return events;
        }

        // Calculate delta heading normalized to [-pi, pi]
        let mut d_heading = heading_rad - self.last_heading;
        while d_heading > std::f32::consts::PI {
            d_heading -= 2.0 * std::f32::consts::PI;
        }
        while d_heading < -std::f32::consts::PI {
            d_heading += 2.0 * std::f32::consts::PI;
        }
        self.last_heading = heading_rad;

        // Monitor reverse driving
        if is_reverse_gear && speed_m_s < -2.0 {
            self.reverse_duration_sec += dt;
        }

        // Monitor rapid yaw rotation
        let abs_turn = d_heading.abs();
        if handbrake_pressed || speed_m_s.abs() > 4.0 {
            self.cumulative_yaw_radians += abs_turn;

            // 180° slide check (approx 2.7 radians)
            if self.cumulative_yaw_radians >= 2.7 && !self.has_done_180 {
                self.has_done_180 = true;
                events.push(StuntEvent::Spin180Detected);

                // J-turn: if was previously driving in reverse, then spun 180°
                if self.reverse_duration_sec >= 1.0 && !self.has_done_jturn {
                    self.has_done_jturn = true;
                    events.push(StuntEvent::JTurnDetected);
                }
            }

            // 360° spin check (approx 5.8 radians)
            if self.cumulative_yaw_radians >= 5.8 && !self.has_done_360 {
                self.has_done_360 = true;
                events.push(StuntEvent::Spin360Detected);
            }
        } else {
            // Decay cumulative spin when driving straight
            self.cumulative_yaw_radians = (self.cumulative_yaw_radians - dt * 2.0).max(0.0);
        }

        events
    }

    /// Register a cone collision.
    pub fn register_cone_hit(&mut self, penalty_seconds: f32) -> StuntEvent {
        self.cone_hits += 1;
        StuntEvent::ConeCollision { penalty_seconds }
    }
}

/// Catalog of all 34 authentic Factory Driver missions.
pub fn get_factory_missions_catalog() -> Vec<FactoryMission> {
    vec![
        // Tier 1: Applicant & Junior Test Driver (Missions 1 to 13)
        FactoryMission {
            mission_index: 1,
            code: "0M01".into(),
            tier: 1,
            title: "Applying Test".into(),
            briefing: "Вы хотите стать частью команды испытателей Porsche? Покажите свое мастерство на автодроме Weissach Skid Pad: объезжайте конусы по стрелкам, не сбивая их.".into(),
            tip: "Используйте мягкое руление на Porsche Boxster. Сбитые конусы добавляют штрафные секунды.".into(),
            car_model: "boxster".into(),
            car_sim: "boxster".into(),
            track_id: "skidpad".into(),
            track_name: "Weissach Skid Pad".into(),
            mission_type: MissionType::SlalomCourse { time_limit_sec: 32.0, cone_penalty_sec: 2.0 },
            target_rank_on_completion: Some(FactoryRank::JuniorTestDriver),
            reward_car: None,
            pass_message: "Добро пожаловать в команду! Я Рольф, старший инструктор испытателей Porsche. Отличное начало!".into(),
            fail_message: "К сожалению, вам не хватило скорости или аккуратности. Потренируйтесь и попробуйте снова.".into(),
        },
        FactoryMission {
            mission_index: 2,
            code: "1m01".into(),
            tier: 1,
            title: "Simple Slalom".into(),
            briefing: "Первый рабочий день: короткий слалом на автодроме Skid Pad. Лимит времени — 26 секунд.".into(),
            tip: "Не превышайте предел сцепления в поворотах между конусами.".into(),
            car_model: "boxster".into(),
            car_sim: "boxster".into(),
            track_id: "skidpad".into(),
            track_name: "Weissach Skid Pad".into(),
            mission_type: MissionType::SlalomCourse { time_limit_sec: 26.0, cone_penalty_sec: 2.0 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Неплохо для новичка! Время уложилось в норматив.".into(),
            fail_message: "Слишком медленно. 26 секунд — это более чем достаточно для этого отрезка.".into(),
        },
        FactoryMission {
            mission_index: 3,
            code: "1m02".into(),
            tier: 1,
            title: "S-turn".into(),
            briefing: "Прохождение связки S-образных виражей на классическом Carrera RS. Лимит 32 секунды. Любое повреждение машины ведет к дисквалификации!".into(),
            tip: "Идеальная траектория — ключ к успеху. Не задевайте обочины.".into(),
            car_model: "911_rs".into(),
            car_sim: "911carrerars".into(),
            track_id: "foothills".into(),
            track_name: "Schwarzwald Foothills".into(),
            mission_type: MissionType::CarDelivery { time_limit_sec: 32.0, max_damage_allowed: 0.02 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Идеальная точность и ни единой царапины на легендарном RS!".into(),
            fail_message: "Машина повреждена или превышен лимит времени. Будьте аккуратнее!".into(),
        },
        FactoryMission {
            mission_index: 4,
            code: "1m03".into(),
            tier: 1,
            title: "360 Spin".into(),
            briefing: "Контроль над заносом: выполните разворот на 360 градусов вправо в створе конусов с помощью ручного тормоза и продолжайте движение.".into(),
            tip: "Разгонитесь, дерните ручник и резко выверните руль вправо для полного оборота.".into(),
            car_model: "boxster".into(),
            car_sim: "boxster".into(),
            track_id: "skidpad".into(),
            track_name: "Weissach Skid Pad".into(),
            mission_type: MissionType::Spin360Exercise { time_limit_sec: 30.0, required_spins: 1 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Блестящий волчок на 360 градусов! Контроль машины на высоте.".into(),
            fail_message: "Разворот не был завершен полностью в пределах створа конусов.".into(),
        },
        FactoryMission {
            mission_index: 5,
            code: "1m04".into(),
            tier: 1,
            title: "Open Road Slalom".into(),
            briefing: "Спор со старшим тест-пилотом Фрэнком: пройдите скоростной слалом на шоссе менее чем за 28 секунд на 911 Turbo.".into(),
            tip: "Управляйте тягой мощного турбомотора: резкий газ может сорвать заднюю ось.".into(),
            car_model: "930_turbo".into(),
            car_sim: "911turbo33".into(),
            track_id: "autobahn".into(),
            track_name: "Autobahn".into(),
            mission_type: MissionType::SlalomCourse { time_limit_sec: 28.0, cone_penalty_sec: 2.0 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Фрэнк проспорил! Ты доказал, что этот Turbo способен на большее.".into(),
            fail_message: "Не уложился в 28 секунд. Фрэнк остался при своем мнении.".into(),
        },
        FactoryMission {
            mission_index: 6,
            code: "1m05".into(),
            tier: 1,
            title: "Car Delivery 1".into(),
            briefing: "Доставка 911 Turbo на другую сторону Лазурного берега к докам. Ни единой царапины!".into(),
            tip: "Соблюдайте дистанцию на узких улочках.".into(),
            car_model: "930_turbo".into(),
            car_sim: "911turbo33".into(),
            track_id: "coastal".into(),
            track_name: "Côte d'Azur".into(),
            mission_type: MissionType::CarDelivery { time_limit_sec: 65.0, max_damage_allowed: 0.03 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Автомобиль доставлен в идеальном состоянии точно к погрузке.".into(),
            fail_message: "Клиент не примет помятый автомобиль. Попробуйте еще раз.".into(),
        },
        FactoryMission {
            mission_index: 7,
            code: "1m06".into(),
            tier: 1,
            title: "Extended Slalom".into(),
            briefing: "Длинный лесной слалом от старого города до леса за 50 секунд. Не сбивайте конусы!".into(),
            tip: "Держите средний темп, плавные перекладки руля берегут драгоценные доли секунды.".into(),
            car_model: "944".into(),
            car_sim: "944".into(),
            track_id: "forest".into(),
            track_name: "Schwarzwald Forest".into(),
            mission_type: MissionType::SlalomCourse { time_limit_sec: 50.0, cone_penalty_sec: 2.0 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Отличное чувство габаритов и ритма трассы!".into(),
            fail_message: "Сбитые конусы привели к перерасходу времени.".into(),
        },
        FactoryMission {
            mission_index: 8,
            code: "1m07".into(),
            tier: 1,
            title: "Frank's Challenge".into(),
            briefing: "Фрэнк проехал сложную связку автодрома за 58 секунд. Сможете побить его время?".into(),
            tip: "Апексы шпилек проходите по внутреннему радиусу.".into(),
            car_model: "901".into(),
            car_sim: "911coupe".into(),
            track_id: "skidpad".into(),
            track_name: "Weissach Skid Pad".into(),
            mission_type: MissionType::SlalomCourse { time_limit_sec: 58.0, cone_penalty_sec: 2.0 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Время Фрэнка повержено! Команда начинает признавать твой авторитет.".into(),
            fail_message: "Фрэнк все еще быстрее. Попробуйте чище пройти шпильки.".into(),
        },
        FactoryMission {
            mission_index: 9,
            code: "1m08".into(),
            tier: 1,
            title: "Car Delivery 2".into(),
            briefing: "Срочная доставка Boxster в промзону к отгрузке. Время поджимает, берегите кузов.".into(),
            tip: "Остерегайтесь узких проездов между ангарами.".into(),
            car_model: "boxster".into(),
            car_sim: "boxster".into(),
            track_id: "industrial".into(),
            track_name: "Zone Industrielle".into(),
            mission_type: MissionType::CarDelivery { time_limit_sec: 55.0, max_damage_allowed: 0.04 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Груз сдан вовремя без единого повреждения.".into(),
            fail_message: "Опоздание или повреждение кузова привело к срыву отгрузки.".into(),
        },
        FactoryMission {
            mission_index: 10,
            code: "1m09".into(),
            tier: 1,
            title: "Capture the Flag 1".into(),
            briefing: "Традиционная игра испытателей: последовательно сбейте 12 конусов-флагов по указаниям маршрута.".into(),
            tip: "Следите за направлением стрелок к следующему конусу.".into(),
            car_model: "911_rs".into(),
            car_sim: "911carrerars".into(),
            track_id: "canyon".into(),
            track_name: "Côte d'Azur Canyon".into(),
            mission_type: MissionType::CaptureTheFlag { time_limit_sec: 75.0, total_flags: 12 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Все 12 флагов взяты в идеальной последовательности!".into(),
            fail_message: "Не успели собрать все флаги до истечения времени.".into(),
        },
        FactoryMission {
            mission_index: 11,
            code: "1m10".into(),
            tier: 1,
            title: "More 360's".into(),
            briefing: "Механик Клаус просит протестировать стояночный тормоз на 993 Turbo: выполните два полных разворота на 360°.".into(),
            tip: "Удерживайте ручник и газ до завершения полного вращения.".into(),
            car_model: "993".into(),
            car_sim: "993carrera".into(),
            track_id: "skidpad".into(),
            track_name: "Weissach Skid Pad".into(),
            mission_type: MissionType::Spin360Exercise { time_limit_sec: 38.0, required_spins: 2 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Клаус доволен: тормоза и баланс шасси работают безупречно.".into(),
            fail_message: "Не удалось выполнить оба вращения за отведенное время.".into(),
        },
        FactoryMission {
            mission_index: 12,
            code: "1m11".into(),
            tier: 1,
            title: "Demo a 996".into(),
            briefing: "Демонстрация нового Porsche 996 Carrera VIP-клиенту в каньоне: агрессивно, быстро, но предельно чисто.".into(),
            tip: "Покажите мощь водяного охлаждения и устойчивость шасси 996.".into(),
            car_model: "996".into(),
            car_sim: "996carrera".into(),
            track_id: "canyon".into(),
            track_name: "Côte d'Azur Canyon".into(),
            mission_type: MissionType::CarDelivery { time_limit_sec: 42.0, max_damage_allowed: 0.02 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Клиент в восторге от управляемости! Контракт подписан.".into(),
            fail_message: "Грубая езда или повреждения напугали клиента.".into(),
        },
        FactoryMission {
            mission_index: 13,
            code: "1m12".into(),
            tier: 1,
            title: "1st Promotion".into(),
            briefing: "Главный квалификационный экзамен на звание Тест-пилота (Test Driver). Пройдите горную трассу Альп в сложных погодных условиях за 110 секунд.".into(),
            tip: "Холодный асфальт снижает сцепление шин. Тормозите заранее.".into(),
            car_model: "911_rs".into(),
            car_sim: "911carrerars".into(),
            track_id: "alps".into(),
            track_name: "Alps".into(),
            mission_type: MissionType::SlalomCourse { time_limit_sec: 110.0, cone_penalty_sec: 3.0 },
            target_rank_on_completion: Some(FactoryRank::TestDriver),
            reward_car: Some(OwnedCar {
                id: "reward_930_turbo".into(),
                catalog_id: 122,
                display_name: "'78 911 Turbo 3.3 (Test Team Reward Edition)".into(),
                model_name: "930".into(),
                sim_name: "911turbo33".into(),
                color_index: 1,
                mileage_km: 1200.0,
                base_price: 48000,
                condition: 1.0,
                installed_parts: vec![
                    InstalledPart::new(13, "Factory Blueprinted Engine", crate::parts::PartCategory::Engine, 2500, 1.15),
                    InstalledPart::new(37, "Competition Brakes", crate::parts::PartCategory::Brakes, 1200, 1.25),
                ],
            }),
            pass_message: "Поздравляем! Вы официально повышены до Тест-пилота (Test Driver) Porsche! Наградной автомобиль '78 911 Turbo 3.3 добавлен в ваш гараж.".into(),
            fail_message: "Квалификационный норматив не взят. Попробуйте еще раз.".into(),
        },

        // Tier 2: Test Driver to Chief Test Driver (Missions 14 to 23)
        FactoryMission {
            mission_index: 14,
            code: "2m01".into(),
            tier: 2,
            title: "Car Delivery 3".into(),
            briefing: "Доставка эксклюзивного 993 клиенту программы Porsche Exclusive в старинный замок.".into(),
            tip: "Брусчатка замка требует плавных движений рулем.".into(),
            car_model: "993".into(),
            car_sim: "993carrera".into(),
            track_id: "castle".into(),
            track_name: "Castelletto".into(),
            mission_type: MissionType::CarDelivery { time_limit_sec: 58.0, max_damage_allowed: 0.02 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Клиент восхищен пунктуальностью и сохранностью машины.".into(),
            fail_message: "Машина повреждена или не успела к встрече.".into(),
        },
        FactoryMission {
            mission_index: 15,
            code: "2m02".into(),
            tier: 2,
            title: "Snow Testing".into(),
            briefing: "Тестирование системы полного привода Carrera 4 на заснеженных перевалах Альп за 45 секунд.".into(),
            tip: "Полный привод отлично вытягивает машину газом из скольжения.".into(),
            car_model: "996".into(),
            car_sim: "996carrera".into(),
            track_id: "alps".into(),
            track_name: "Alps".into(),
            mission_type: MissionType::SlalomCourse { time_limit_sec: 45.0, cone_penalty_sec: 2.0 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Данные телеметрии полного привода подтвердили расчеты инженеров.".into(),
            fail_message: "Слишком много скольжений привели к потере темпа.".into(),
        },
        FactoryMission {
            mission_index: 16,
            code: "2m03".into(),
            tier: 2,
            title: "Klaus' Delivery".into(),
            briefing: "Срочная доставка запчастей Клаусу в индустриальный сектор.".into(),
            tip: "Не теряйте времени на разворотах между складами.".into(),
            car_model: "944".into(),
            car_sim: "944".into(),
            track_id: "industrial".into(),
            track_name: "Zone Industrielle".into(),
            mission_type: MissionType::CarDelivery { time_limit_sec: 48.0, max_damage_allowed: 0.03 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Клаус вовремя получил детали для сборки!".into(),
            fail_message: "Запчасти доставлены с опозданием.".into(),
        },
        FactoryMission {
            mission_index: 17,
            code: "2m04".into(),
            tier: 2,
            title: "Billy's First Day".into(),
            briefing: "Новый тест-пилот Билли прибыл в команду. Покажите ему мастер-класс на автодроме Skid Pad за 34 секунды.".into(),
            tip: "Покажите идеальную точность на перекладках.".into(),
            car_model: "boxster".into(),
            car_sim: "boxster".into(),
            track_id: "skidpad".into(),
            track_name: "Weissach Skid Pad".into(),
            mission_type: MissionType::SlalomCourse { time_limit_sec: 34.0, cone_penalty_sec: 2.0 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Билли впечатлен вашим мастерством!".into(),
            fail_message: "Вы не смогли показать новичку должный пример.".into(),
        },
        FactoryMission {
            mission_index: 18,
            code: "2m05".into(),
            tier: 2,
            title: "Billy's Challenge".into(),
            briefing: "Билли бросает вам вызов на холмах Шварцвальда. Победите его в очной дуэли!".into(),
            tip: "Удерживайте внутреннюю траекторию в скоростных дугах.".into(),
            car_model: "930_turbo".into(),
            car_sim: "911turbo33".into(),
            track_id: "foothills".into(),
            track_name: "Schwarzwald Foothills".into(),
            mission_type: MissionType::DuelRace { laps: 1, opponent_name: "Billy" },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Билли повержен! Его хвастовство быстро улеглось.".into(),
            fail_message: "Билли финишировал первым. Репутация требует реванша.".into(),
        },
        FactoryMission {
            mission_index: 19,
            code: "2m06".into(),
            tier: 2,
            title: "Boxster Test".into(),
            briefing: "Комплексное тестирование доработанного прототипа Boxster на автодроме.".into(),
            tip: "Проверьте отзывчивость модифицированной подвески.".into(),
            car_model: "boxster".into(),
            car_sim: "boxster".into(),
            track_id: "skidpad".into(),
            track_name: "Weissach Skid Pad".into(),
            mission_type: MissionType::SlalomCourse { time_limit_sec: 40.0, cone_penalty_sec: 2.0 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Прототип подтвердил отличную сбалансированность шасси.".into(),
            fail_message: "Время заезда превысило установленный инженерами лимит.".into(),
        },
        FactoryMission {
            mission_index: 20,
            code: "2m07".into(),
            tier: 2,
            title: "Team Race 1".into(),
            briefing: "Командная вечерняя гонка по загородным дорогам против Билли и коллег.".into(),
            tip: "Узкие проезды требуют аккуратности при обгонах.".into(),
            car_model: "993".into(),
            car_sim: "993carrera".into(),
            track_id: "farmland".into(),
            track_name: "Farmland".into(),
            mission_type: MissionType::DuelRace { laps: 1, opponent_name: "Billy" },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Уверенная победа в командной гонке!".into(),
            fail_message: "Соперники обошли вас на финишной прямой.".into(),
        },
        FactoryMission {
            mission_index: 21,
            code: "2m08".into(),
            tier: 2,
            title: "Capture the Flag 2".into(),
            briefing: "Ночной 'Захват флага' на улочках Монте-Карло: побейте рекорд Рольфа, собрав все контрольные флаги.".into(),
            tip: "Резкие торможения перед шпильками сберегут секунды.".into(),
            car_model: "911_rs".into(),
            car_sim: "911carrerars".into(),
            track_id: "monaco1".into(),
            track_name: "Monte Carlo 1".into(),
            mission_type: MissionType::CaptureTheFlag { time_limit_sec: 68.0, total_flags: 14 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Старый рекорд Рольфа пал! Ты настоящий виртуоз узких улочек.".into(),
            fail_message: "Время Рольфа устояло. Попробуйте еще раз.".into(),
        },
        FactoryMission {
            mission_index: 22,
            code: "2m09".into(),
            tier: 2,
            title: "Billy's Stunt Course".into(),
            briefing: "Билли установил рекорд на каскадерской полосе Skid Pad. Докажите свое превосходство на 911 GT3!".into(),
            tip: "Используйте избыточную поворачиваемость GT3.".into(),
            car_model: "gt3".into(),
            car_sim: "996gt3".into(),
            track_id: "skidpad".into(),
            track_name: "Weissach Skid Pad".into(),
            mission_type: MissionType::SlalomCourse { time_limit_sec: 35.0, cone_penalty_sec: 2.0 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Билли окончательно признал ваше лидерство!".into(),
            fail_message: "Время Билли оказалось лучше. Соберитесь и повторите.".into(),
        },
        FactoryMission {
            mission_index: 23,
            code: "2m10".into(),
            tier: 2,
            title: "Carrera RS Race with Rolf".into(),
            briefing: "Рольф уходит на пенсию и лично рекомендует вас на должность Шеф-испытателя. Очная дуэль на легендарных 1973 Carrera RS на любимой трассе Рольфа!".into(),
            tip: "Рольф знает каждый сантиметр этой трассы. Атакуйте на торможениях.".into(),
            car_model: "911_rs".into(),
            car_sim: "911carrerars".into(),
            track_id: "canyon".into(),
            track_name: "Côte d'Azur Canyon".into(),
            mission_type: MissionType::DuelRace { laps: 1, opponent_name: "Rolf" },
            target_rank_on_completion: Some(FactoryRank::ChiefTestDriver),
            reward_car: Some(OwnedCar {
                id: "reward_carrera_rs_73".into(),
                catalog_id: 115,
                display_name: "'73 911 Carrera RS 2.7 (Rolf's Personal Legend Edition)".into(),
                model_name: "911_rs".into(),
                sim_name: "911carrerars".into(),
                color_index: 2,
                mileage_km: 850.0,
                base_price: 65000,
                condition: 1.0,
                installed_parts: vec![
                    InstalledPart::new(16, "Rolf Custom Camshafts", crate::parts::PartCategory::Engine, 3500, 1.25),
                    InstalledPart::new(43, "Sport Lowering Springs", crate::parts::PartCategory::Springs, 1500, 1.30),
                    InstalledPart::new(51, "Semi-Slick Racing Compound", crate::parts::PartCategory::Tires, 2200, 1.25),
                ],
            }),
            pass_message: "Рольф: 'Эта гонка запомнится мне навсегда! Ты достоин стать Шеф-испытателем команды Porsche! Мой личный Carrera RS теперь твой.'".into(),
            fail_message: "Опыт Рольфа взял верх. Попробуйте еще раз превзойти мастера.".into(),
        },

        // Tier 3: Senior / Chief Test Driver to Master Ace (Missions 24 to 34)
        FactoryMission {
            mission_index: 24,
            code: "3m01".into(),
            tier: 3,
            title: "Race Car Test".into(),
            briefing: "Финальная обкатка боевого прототипа 911 GT1 перед отправкой гоночной команде на Автобане.".into(),
            tip: "Колоссальная прижимная сила раскрывается на скорости свыше 200 км/ч.".into(),
            car_model: "gt1".into(),
            car_sim: "911gt1".into(),
            track_id: "autobahn".into(),
            track_name: "Autobahn".into(),
            mission_type: MissionType::SlalomCourse { time_limit_sec: 42.0, cone_penalty_sec: 2.0 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Болид GT1 полностью готов к гонке 24 часа Ле-Мана!".into(),
            fail_message: "Прототип не уложился в график подготовки.".into(),
        },
        FactoryMission {
            mission_index: 25,
            code: "3m02".into(),
            tier: 3,
            title: "Dieter's Late".into(),
            briefing: "Директор завода Дитер опаздывает на экспресс-поезд. Довезите его на вокзал в целости и сохранности!".into(),
            tip: "Высокая скорость, но без резких ударов о бордюры.".into(),
            car_model: "996".into(),
            car_sim: "996carrera".into(),
            track_id: "monaco2".into(),
            track_name: "Monte Carlo 2".into(),
            mission_type: MissionType::CarDelivery { time_limit_sec: 50.0, max_damage_allowed: 0.02 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Дитер успел на поезд за секунду до отправления и впечатлен вашим хладнокровием.".into(),
            fail_message: "Поезд ушел или машина получила повреждения.".into(),
        },
        FactoryMission {
            mission_index: 26,
            code: "3m03".into(),
            tier: 3,
            title: "Stephanie's Slalom".into(),
            briefing: "Стефани (Ас команды) подготовила сверхсложный слалом на проселочной дороге. Проверьте свое мастерство!".into(),
            tip: "Узкая колея не прощает ошибок траектории.".into(),
            car_model: "993".into(),
            car_sim: "993carrera".into(),
            track_id: "farmland".into(),
            track_name: "Farmland".into(),
            mission_type: MissionType::SlalomCourse { time_limit_sec: 48.0, cone_penalty_sec: 2.0 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Стефани: 'А ты и правда так хорош, как о тебе говорят.'".into(),
            fail_message: "Слишком медленно для уровня лучших пилотов команды.".into(),
        },
        FactoryMission {
            mission_index: 27,
            code: "3m04".into(),
            tier: 3,
            title: "Billy's Challenge 2".into(),
            briefing: "Финальная попытка Билли вернуть лидерство на сложнейшем треке промзоны.".into(),
            tip: "Позднее торможение перед шпилькой гарантирует победу.".into(),
            car_model: "gt3".into(),
            car_sim: "996gt3".into(),
            track_id: "industrial".into(),
            track_name: "Zone Industrielle".into(),
            mission_type: MissionType::DuelRace { laps: 1, opponent_name: "Billy" },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Билли окончательно капитулировал перед вашим мастерством.".into(),
            fail_message: "Билли сумел вырваться вперед.".into(),
        },
        FactoryMission {
            mission_index: 28,
            code: "3m05".into(),
            tier: 3,
            title: "Stephanie's Challenge".into(),
            briefing: "Стефани готова сразиться с вами на горных серпантинах Альп. Победите её лучшее время!".into(),
            tip: "Скоростные перепады высот требуют предельной концентрации.".into(),
            car_model: "gt3".into(),
            car_sim: "996gt3".into(),
            track_id: "alps".into(),
            track_name: "Alps".into(),
            mission_type: MissionType::SlalomCourse { time_limit_sec: 62.0, cone_penalty_sec: 2.0 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Время Стефани превзойдено! Вы в шаге от звания абсолютного Аса.".into(),
            fail_message: "Стефани все еще удерживает рекорд серпантина.".into(),
        },
        FactoryMission {
            mission_index: 29,
            code: "3m06".into(),
            tier: 3,
            title: "Team Race 2".into(),
            briefing: "Вечерний заезд лучших испытателей завода вокруг замка Castelletto.".into(),
            tip: "Держите максимальную среднюю скорость на скоростных прямых.".into(),
            car_model: "930_turbo".into(),
            car_sim: "911turbo33".into(),
            track_id: "castle".into(),
            track_name: "Castelletto".into(),
            mission_type: MissionType::DuelRace { laps: 2, opponent_name: "Frank" },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Победа над ветеранами заводской команды!".into(),
            fail_message: "Ветераны команды оказались опытнее.".into(),
        },
        FactoryMission {
            mission_index: 30,
            code: "3m07".into(),
            tier: 3,
            title: "Porsche Commercial".into(),
            briefing: "Съемки телевизионного рекламного ролика Porsche: разворот на 180° в створе конусов, движение задним ходом, разворот на 180° в движении вперед, слалом и эффектный волчок на 360° в финале!".into(),
            tip: "Используйте ручник и реверс для четких трюков. Не сбивайте съемочные пилоны.".into(),
            car_model: "996".into(),
            car_sim: "996carrera".into(),
            track_id: "skidpad".into(),
            track_name: "Weissach Skid Pad".into(),
            mission_type: MissionType::PorscheCommercial { time_limit_sec: 55.0 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Снято с первого дубля! Режиссер в полном восторге от трюков!".into(),
            fail_message: "Трюки выполнены не полностью или сбиты съемочные маркеры.".into(),
        },
        FactoryMission {
            mission_index: 31,
            code: "3m08".into(),
            tier: 3,
            title: "Race Car Test 2".into(),
            briefing: "Гоночный 911 GT1 восстановлен механиками. 3 боевых круга в Монте-Карло без единого контакта с барьерами!".into(),
            tip: "Карбоновые тормоза эффективны при сильном нагреве.".into(),
            car_model: "gt1".into(),
            car_sim: "911gt1".into(),
            track_id: "monaco3".into(),
            track_name: "Monte Carlo 3".into(),
            mission_type: MissionType::CarDelivery { time_limit_sec: 140.0, max_damage_allowed: 0.02 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Все 3 круга пройдены безупречно чисто на пределе скорости!".into(),
            fail_message: "Машина коснулась отбойника или не уложилась во время.".into(),
        },
        FactoryMission {
            mission_index: 32,
            code: "3m09".into(),
            tier: 3,
            title: "Dieter's Challenge".into(),
            briefing: "Дитер организовал секретную гонку с профессиональными заводскими пилотами Ле-Мана в Монте-Карло!".into(),
            tip: "Защищайте траекторию на выходе из шиканы.".into(),
            car_model: "gt1".into(),
            car_sim: "911gt1".into(),
            track_id: "monaco4".into(),
            track_name: "Monte Carlo 4".into(),
            mission_type: MissionType::DuelRace { laps: 2, opponent_name: "Dieter" },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Дитер и пилоты Ле-Мана стоя аплодируют вашей победе!".into(),
            fail_message: "Заводские пилоты Ле-Мана одержали победу.".into(),
        },
        FactoryMission {
            mission_index: 33,
            code: "3m10".into(),
            tier: 3,
            title: "Joy Ride".into(),
            briefing: "Клаус собрал первый серийный 996 Turbo 2000 года. Прокатитесь по каньону, оценив мощь твин-турбо, не оставив ни царапины!".into(),
            tip: "Управляйте тягой: 420 л.с. разгоняют машину мгновенно.".into(),
            car_model: "996".into(),
            car_sim: "996carrera".into(),
            track_id: "canyon".into(),
            track_name: "Côte d'Azur Canyon".into(),
            mission_type: MissionType::CarDelivery { time_limit_sec: 45.0, max_damage_allowed: 0.01 },
            target_rank_on_completion: None,
            reward_car: None,
            pass_message: "Машина вернулась в бокс девственно чистой и обкатанной!".into(),
            fail_message: "Клаус заметил малейшее повреждение. Выговор от руководства!".into(),
        },
        FactoryMission {
            mission_index: 34,
            code: "3m11".into(),
            tier: 3,
            title: "Ace Challenge".into(),
            briefing: "Финальная битва за титул абсолютного Мастера-испытателя Porsche! Дуэль против непобедимой Стефани на новеньких 911 Turbo на Лазурном берегу!".into(),
            tip: "Это решающий заезд всей вашей карьеры. Не уступайте ни миллиметра трассы!".into(),
            car_model: "996".into(),
            car_sim: "996carrera".into(),
            track_id: "coastal".into(),
            track_name: "Côte d'Azur".into(),
            mission_type: MissionType::DuelRace { laps: 2, opponent_name: "Stephanie (Ace)" },
            target_rank_on_completion: Some(FactoryRank::MasterAce),
            reward_car: Some(OwnedCar {
                id: "reward_996_gt3_factory".into(),
                catalog_id: 221,
                display_name: "'99 911 GT3 (Factory Master Ace Special Edition)".into(),
                model_name: "gt3".into(),
                sim_name: "996gt3".into(),
                color_index: 0,
                mileage_km: 150.0,
                base_price: 125000,
                condition: 1.0,
                installed_parts: vec![
                    InstalledPart::new(16, "Factory Cup Engine Spec (380 hp)", crate::parts::PartCategory::Engine, 8500, 1.30),
                    InstalledPart::new(37, "Carbon Ceramic Brake Kit", crate::parts::PartCategory::Brakes, 4500, 1.40),
                    InstalledPart::new(43, "Motorsport Adjustable Coilovers", crate::parts::PartCategory::Springs, 3200, 1.40),
                    InstalledPart::new(51, "Michelin Pilot Sport Cup Slicks", crate::parts::PartCategory::Tires, 3800, 1.35),
                ],
            }),
            pass_message: "НЕВЕРОЯТНО! Вы обошли Стефани и завоевали титул Мастера-испытателя (Ace Driver) Porsche! Наградной суперкар '99 911 GT3 Factory Edition передан вам навсегда!".into(),
            fail_message: "Стефани сохранила титул Аса. Вы были так близки! Попробуйте снова!".into(),
        },
    ]
}

/// Evaluation result of a mission attempt.
#[derive(Debug, Clone, PartialEq)]
pub struct MissionEvaluation {
    pub passed: bool,
    pub total_time_seconds: f32,
    pub raw_time_seconds: f32,
    pub penalty_seconds: f32,
    pub feedback_message: String,
    pub promotion_rank: Option<FactoryRank>,
    pub awarded_car: Option<OwnedCar>,
}

/// Evaluate mission result against objectives and telemetry.
pub fn evaluate_mission(
    mission: &FactoryMission,
    raw_time_seconds: f32,
    stunts: &StuntDetector,
    is_race_winner: bool,
) -> MissionEvaluation {
    let penalty_seconds = stunts.cone_hits as f32 * 2.0;
    let total_time_seconds = raw_time_seconds + penalty_seconds;

    let (passed, reason) = match &mission.mission_type {
        MissionType::SlalomCourse { time_limit_sec, .. } => {
            if total_time_seconds <= *time_limit_sec {
                (true, mission.pass_message.clone())
            } else {
                (
                    false,
                    format!(
                        "Превышен лимит времени ({:.1}с при нормативе {:.1}с). {}",
                        total_time_seconds, time_limit_sec, mission.fail_message
                    ),
                )
            }
        }
        MissionType::Spin360Exercise { time_limit_sec, .. } => {
            if !stunts.has_done_360 {
                (
                    false,
                    format!("Разворот на 360° не зафиксирован! {}", mission.fail_message),
                )
            } else if total_time_seconds > *time_limit_sec {
                (
                    false,
                    format!(
                        "Разворот выполнен, но превышен лимит времени ({:.1}с > {:.1}с).",
                        total_time_seconds, time_limit_sec
                    ),
                )
            } else {
                (true, mission.pass_message.clone())
            }
        }
        MissionType::Slide180Exercise { time_limit_sec, .. } => {
            if !stunts.has_done_180 {
                (
                    false,
                    format!("Разворот на 180° не зафиксирован! {}", mission.fail_message),
                )
            } else if total_time_seconds > *time_limit_sec {
                (
                    false,
                    format!(
                        "Превышен лимит времени ({:.1}с > {:.1}с).",
                        total_time_seconds, time_limit_sec
                    ),
                )
            } else {
                (true, mission.pass_message.clone())
            }
        }
        MissionType::PorscheCommercial { time_limit_sec } => {
            let stunts_ok = stunts.has_done_180 && stunts.has_done_360 && stunts.has_done_jturn;
            if !stunts_ok {
                (false, "Не выполнены все обязательные трюки рекламного ролика (180° занос, езда задом с J-turn разворотом, 360° волчок).".into())
            } else if total_time_seconds > *time_limit_sec {
                (
                    false,
                    format!(
                        "Трюки выполнены, но время превышено ({:.1}с > {:.1}с).",
                        total_time_seconds, time_limit_sec
                    ),
                )
            } else {
                (true, mission.pass_message.clone())
            }
        }
        MissionType::CarDelivery {
            time_limit_sec,
            max_damage_allowed,
        } => {
            if stunts.current_damage > *max_damage_allowed {
                (
                    false,
                    format!(
                        "Автомобиль поврежден ({:.1}% > {:.1}% допустимых)! {}",
                        stunts.current_damage * 100.0,
                        max_damage_allowed * 100.0,
                        mission.fail_message
                    ),
                )
            } else if total_time_seconds > *time_limit_sec {
                (
                    false,
                    format!(
                        "Превышен лимит времени доставки ({:.1}с > {:.1}с).",
                        total_time_seconds, time_limit_sec
                    ),
                )
            } else {
                (true, mission.pass_message.clone())
            }
        }
        MissionType::DuelRace { opponent_name, .. } => {
            if is_race_winner {
                (true, mission.pass_message.clone())
            } else {
                (
                    false,
                    format!("Соперник {} финишировал впереди вас!", opponent_name),
                )
            }
        }
        MissionType::CaptureTheFlag {
            time_limit_sec,
            total_flags,
        } => {
            if stunts.cone_hits < *total_flags {
                (
                    false,
                    format!(
                        "Собрано только {} флагов из {}. {}",
                        stunts.cone_hits, total_flags, mission.fail_message
                    ),
                )
            } else if raw_time_seconds > *time_limit_sec {
                (
                    false,
                    format!(
                        "Время вышло ({:.1}с > {:.1}с).",
                        raw_time_seconds, time_limit_sec
                    ),
                )
            } else {
                (true, mission.pass_message.clone())
            }
        }
    };

    MissionEvaluation {
        passed,
        total_time_seconds,
        raw_time_seconds,
        penalty_seconds,
        feedback_message: reason,
        promotion_rank: if passed {
            mission.target_rank_on_completion
        } else {
            None
        },
        awarded_car: if passed {
            mission.reward_car.clone()
        } else {
            None
        },
    }
}

/// Advance player profile upon completing a Factory Driver mission.
pub fn apply_mission_completion(
    profile: &mut PlayerProfile,
    mission_idx: usize,
    time_taken: f32,
    stunts: &StuntDetector,
    is_race_winner: bool,
) -> Result<MissionEvaluation, String> {
    let catalog = get_factory_missions_catalog();
    let mission = catalog
        .iter()
        .find(|m| m.mission_index == mission_idx)
        .ok_or_else(|| format!("Mission index {} not found", mission_idx))?;

    let eval = evaluate_mission(mission, time_taken, stunts, is_race_winner);

    if eval.passed {
        // Record completed mission code
        if !profile
            .factory_driver
            .completed_missions
            .contains(&mission.code)
        {
            profile
                .factory_driver
                .completed_missions
                .push(mission.code.clone());
        }

        // Update best time
        let existing = profile
            .factory_driver
            .best_times
            .get(&mission.code)
            .copied()
            .unwrap_or(f32::MAX);
        if eval.total_time_seconds < existing {
            profile
                .factory_driver
                .best_times
                .insert(mission.code.clone(), eval.total_time_seconds);
        }

        // Unlock next mission code
        if let Some(next_mission) = catalog.iter().find(|m| m.mission_index == mission_idx + 1) {
            profile.factory_driver.current_mission_code = next_mission.code.clone();
        }

        // Handle promotion
        if let Some(rank) = eval.promotion_rank {
            profile.factory_driver.driver_rank = rank.display_name().to_string();
        }

        // Handle bonus car award
        if let Some(car) = &eval.awarded_car {
            if !profile.garage.iter().any(|c| c.id == car.id) {
                profile.garage.push(car.clone());
            }
        }
    }

    Ok(eval)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_all_34_missions_present_and_continuous() {
        let catalog = get_factory_missions_catalog();
        assert_eq!(catalog.len(), 34);
        for (i, m) in catalog.iter().enumerate() {
            assert_eq!(m.mission_index, i + 1);
            assert!(!m.code.is_empty());
            assert!(!m.title.is_empty());
            assert!(!m.track_id.is_empty());
            assert!(!m.car_model.is_empty());
        }
    }

    #[test]
    fn test_stunt_detector_180_and_360_spins() {
        let mut detector = StuntDetector::new();
        detector.reset(0.0);

        // Turn right by 170 degrees (approx 2.96 rad)
        let events = detector.update(0.1, 15.0, 2.96, false, true, 0.0);
        assert!(detector.has_done_180);
        assert!(events.contains(&StuntEvent::Spin180Detected));

        // Complete a full 360 degree spin (total > 5.8 rad)
        let events2 = detector.update(0.1, 15.0, 5.9, false, true, 0.0);
        assert!(detector.has_done_360);
        assert!(events2.contains(&StuntEvent::Spin360Detected));
    }

    #[test]
    fn test_stunt_detector_jturn_in_reverse() {
        let mut detector = StuntDetector::new();
        detector.reset(0.0);

        // Drive backwards for > 1.0 second
        for _ in 0..15 {
            detector.update(0.1, -6.0, 0.0, true, false, 0.0);
        }
        assert!(detector.reverse_duration_sec >= 1.0);

        // Quick 180 whip around
        let events = detector.update(0.1, -2.0, 3.0, false, true, 0.0);
        assert!(detector.has_done_180);
        assert!(detector.has_done_jturn);
        assert!(events.contains(&StuntEvent::JTurnDetected));
    }

    #[test]
    fn test_mission_progression_and_reward_cars() {
        let mut profile = PlayerProfile::new("Test Driver");
        assert_eq!(profile.factory_driver.driver_rank, "Applicant");
        assert_eq!(profile.factory_driver.current_mission_code, "0M01");

        // Complete mission 1
        let stunts = StuntDetector::new();
        let eval = apply_mission_completion(&mut profile, 1, 28.5, &stunts, false).unwrap();
        assert!(eval.passed);
        assert_eq!(profile.factory_driver.current_mission_code, "1m01");
        assert_eq!(
            profile.factory_driver.driver_rank,
            FactoryRank::JuniorTestDriver.display_name()
        );

        // Complete mission 13 (Promotion to Test Driver + 930 Turbo reward)
        let eval13 = apply_mission_completion(&mut profile, 13, 98.0, &stunts, false).unwrap();
        assert!(eval13.passed);
        assert!(profile.garage.iter().any(|c| c.id == "reward_930_turbo"));
        assert_eq!(
            profile.factory_driver.driver_rank,
            FactoryRank::TestDriver.display_name()
        );

        // Complete mission 23 (Carrera RS Duel + Promotion to Chief Test Driver + Rolf's RS)
        let eval23 = apply_mission_completion(&mut profile, 23, 110.0, &stunts, true).unwrap();
        assert!(eval23.passed);
        assert!(profile
            .garage
            .iter()
            .any(|c| c.id == "reward_carrera_rs_73"));
        assert_eq!(
            profile.factory_driver.driver_rank,
            FactoryRank::ChiefTestDriver.display_name()
        );

        // Complete mission 34 (Ace Challenge Duel + Promotion to Master Ace + 996 GT3)
        let eval34 = apply_mission_completion(&mut profile, 34, 125.0, &stunts, true).unwrap();
        assert!(eval34.passed);
        assert!(profile
            .garage
            .iter()
            .any(|c| c.id == "reward_996_gt3_factory"));
        assert_eq!(
            profile.factory_driver.driver_rank,
            FactoryRank::MasterAce.display_name()
        );
    }
}
