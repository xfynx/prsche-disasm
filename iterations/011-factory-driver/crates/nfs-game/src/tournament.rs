//! Tournament progression engine, point standings, and Era advancement.

#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub enum TournamentEra {
    Classic = 1,
    Golden = 2,
    Modern = 3,
}

impl TournamentEra {
    pub fn name(&self) -> &'static str {
        match self {
            TournamentEra::Classic => "Classic Era (1950-1969)",
            TournamentEra::Golden => "Golden Era (1970-1988)",
            TournamentEra::Modern => "Modern Era (1989-2000)",
        }
    }
}

/// A stage inside an active tournament.
#[derive(Debug, Clone, PartialEq)]
pub struct TournamentStageInfo {
    pub stage_index: usize,
    pub track_id: String,
    pub track_display_name: String,
    pub laps: usize,
    pub prize_first: u32,
    pub prize_second: u32,
    pub prize_third: u32,
}

/// Entry in the championship points standing table.
#[derive(Debug, Clone, PartialEq)]
pub struct StandingEntry {
    pub driver_name: String,
    pub is_player: bool,
    pub points: u32,
    pub total_time_sec: f32,
}

/// A full Tournament Cup definition.
#[derive(Debug, Clone, PartialEq)]
pub struct TournamentCup {
    pub id: String,
    pub title: String,
    pub description: String,
    pub era: TournamentEra,
    pub entry_fee: u32,
    pub required_car_model: Option<String>,
    pub stages: Vec<TournamentStageInfo>,
}

/// Active tournament cup runtime session.
#[derive(Debug, Clone, PartialEq)]
pub struct TournamentSession {
    pub cup: TournamentCup,
    pub current_stage_index: usize,
    pub standings: Vec<StandingEntry>,
    pub completed: bool,
    pub won: bool,
}

impl TournamentSession {
    pub fn new(cup: TournamentCup, player_name: &str) -> Self {
        let standings = vec![
            StandingEntry {
                driver_name: player_name.to_string(),
                is_player: true,
                points: 0,
                total_time_sec: 0.0,
            },
            StandingEntry {
                driver_name: "Hans Stuck".to_string(),
                is_player: false,
                points: 0,
                total_time_sec: 0.0,
            },
            StandingEntry {
                driver_name: "Jochen Mass".to_string(),
                is_player: false,
                points: 0,
                total_time_sec: 0.0,
            },
            StandingEntry {
                driver_name: "Jacky Ickx".to_string(),
                is_player: false,
                points: 0,
                total_time_sec: 0.0,
            },
        ];
        Self {
            cup,
            current_stage_index: 0,
            standings,
            completed: false,
            won: false,
        }
    }

    /// Points awarded for finishing positions (1st through 6th).
    pub fn points_for_position(pos: usize) -> u32 {
        match pos {
            1 => 10,
            2 => 6,
            3 => 4,
            4 => 3,
            5 => 2,
            6 => 1,
            _ => 0,
        }
    }

    /// Current stage info.
    pub fn current_stage(&self) -> Option<&TournamentStageInfo> {
        self.cup.stages.get(self.current_stage_index)
    }

    /// Process stage completion: award points, update standings, advance to next stage or finish.
    pub fn finish_stage(&mut self, player_time_sec: f32, player_pos: usize) -> (u32, bool) {
        if self.completed {
            return (0, self.won);
        }

        // Award player points
        let p_pts = Self::points_for_position(player_pos);
        if let Some(p) = self.standings.iter_mut().find(|s| s.is_player) {
            p.points += p_pts;
            p.total_time_sec += player_time_sec;
        }

        // Award AI points based on remaining places
        let mut ai_rank = 1;
        for s in self.standings.iter_mut().filter(|s| !s.is_player) {
            if ai_rank == player_pos {
                ai_rank += 1;
            }
            s.points += Self::points_for_position(ai_rank);
            s.total_time_sec += player_time_sec * (1.0 + (ai_rank as f32 - 1.0) * 0.03);
            ai_rank += 1;
        }

        // Sort standings descending by points, tie-break by lower total time
        self.standings.sort_by(|a, b| {
            b.points.cmp(&a.points).then_with(|| {
                a.total_time_sec
                    .partial_cmp(&b.total_time_sec)
                    .unwrap_or(std::cmp::Ordering::Equal)
            })
        });

        // Compute prize money for this stage
        let stage = &self.cup.stages[self.current_stage_index];
        let stage_prize = match player_pos {
            1 => stage.prize_first,
            2 => stage.prize_second,
            3 => stage.prize_third,
            _ => 0,
        };

        if self.current_stage_index + 1 < self.cup.stages.len() {
            self.current_stage_index += 1;
        } else {
            self.completed = true;
            self.won = self.standings.first().map(|s| s.is_player).unwrap_or(false);
        }

        (stage_prize, self.won)
    }
}

/// Catalog of Evolution tournaments organized by era.
pub fn get_tournaments_catalog() -> Vec<TournamentCup> {
    vec![
        // Classic Era (1950 - 1969)
        TournamentCup {
            id: "classic_356_challenge".into(),
            title: "356 Challenge".into(),
            description: "Первый турнир эры Classic. Состязание легендарных классических Porsche 356 на извилистых дорогах каньона и узких улочках Монте-Карло.".into(),
            era: TournamentEra::Classic,
            entry_fee: 750,
            required_car_model: Some("356".into()),
            stages: vec![
                TournamentStageInfo {
                    stage_index: 0,
                    track_id: "canyon".into(),
                    track_display_name: "Canyon (Каньон)".into(),
                    laps: 2,
                    prize_first: 4500,
                    prize_second: 2000,
                    prize_third: 1000,
                },
                TournamentStageInfo {
                    stage_index: 1,
                    track_id: "monaco1".into(),
                    track_display_name: "Monte Carlo 1 (Монте-Карло 1)".into(),
                    laps: 2,
                    prize_first: 4500,
                    prize_second: 2000,
                    prize_third: 1000,
                },
            ],
        },
        TournamentCup {
            id: "classic_550_trophy".into(),
            title: "550 Spyder Trophy".into(),
            description: "Кубок спортивных прототипов 550 Spyder. Скоростные участки Лазурного берега и высокогорные перевалы Альп.".into(),
            era: TournamentEra::Classic,
            entry_fee: 1500,
            required_car_model: Some("550".into()),
            stages: vec![
                TournamentStageInfo {
                    stage_index: 0,
                    track_id: "coastal".into(),
                    track_display_name: "Côte d'Azur (Лазурный берег)".into(),
                    laps: 2,
                    prize_first: 6500,
                    prize_second: 3000,
                    prize_third: 1500,
                },
                TournamentStageInfo {
                    stage_index: 1,
                    track_id: "alps".into(),
                    track_display_name: "Alps (Альпы)".into(),
                    laps: 3,
                    prize_first: 7000,
                    prize_second: 3500,
                    prize_third: 1800,
                },
            ],
        },
        TournamentCup {
            id: "classic_championship".into(),
            title: "Classic Era Championship".into(),
            description: "Финальный чемпионат эпохи Classic. Четыре этапа, победа в котором открывает Золотую эру (Golden Era)!".into(),
            era: TournamentEra::Classic,
            entry_fee: 3000,
            required_car_model: None,
            stages: vec![
                TournamentStageInfo {
                    stage_index: 0,
                    track_id: "farmland".into(),
                    track_display_name: "Normandie (Нормандия)".into(),
                    laps: 2,
                    prize_first: 8000,
                    prize_second: 4000,
                    prize_third: 2000,
                },
                TournamentStageInfo {
                    stage_index: 1,
                    track_id: "forest".into(),
                    track_display_name: "Black Forest (Шварцвальд)".into(),
                    laps: 2,
                    prize_first: 8500,
                    prize_second: 4500,
                    prize_third: 2200,
                },
                TournamentStageInfo {
                    stage_index: 2,
                    track_id: "foothills".into(),
                    track_display_name: "Pyrenees (Пиренеи)".into(),
                    laps: 3,
                    prize_first: 9000,
                    prize_second: 5000,
                    prize_third: 2500,
                },
                TournamentStageInfo {
                    stage_index: 3,
                    track_id: "monaco2".into(),
                    track_display_name: "Monte Carlo 2 (Монте-Карло 2)".into(),
                    laps: 3,
                    prize_first: 12000,
                    prize_second: 6000,
                    prize_third: 3000,
                },
            ],
        },

        // Golden Era (1970 - 1988)
        TournamentCup {
            id: "golden_914_trophy".into(),
            title: "914 Trophy".into(),
            description: "Кубок среднемоторных Porsche 914. Промзона и скоростные шоссе.".into(),
            era: TournamentEra::Golden,
            entry_fee: 2500,
            required_car_model: Some("914".into()),
            stages: vec![
                TournamentStageInfo {
                    stage_index: 0,
                    track_id: "industrial".into(),
                    track_display_name: "Zone Industrielle (Промзона)".into(),
                    laps: 2,
                    prize_first: 9000,
                    prize_second: 4500,
                    prize_third: 2000,
                },
                TournamentStageInfo {
                    stage_index: 1,
                    track_id: "autobahn".into(),
                    track_display_name: "Autobahn (Автобан)".into(),
                    laps: 3,
                    prize_first: 10000,
                    prize_second: 5000,
                    prize_third: 2500,
                },
            ],
        },
        TournamentCup {
            id: "golden_championship".into(),
            title: "Golden Era Championship".into(),
            description: "Главный кубок Золотой эпохи. Победа открывает доступ к Современной эре (Modern Era)!".into(),
            era: TournamentEra::Golden,
            entry_fee: 5000,
            required_car_model: None,
            stages: vec![
                TournamentStageInfo {
                    stage_index: 0,
                    track_id: "autobahn".into(),
                    track_display_name: "Autobahn (Автобан)".into(),
                    laps: 3,
                    prize_first: 15000,
                    prize_second: 7500,
                    prize_third: 3500,
                },
                TournamentStageInfo {
                    stage_index: 1,
                    track_id: "castle".into(),
                    track_display_name: "Schwarzwald (Замок)".into(),
                    laps: 3,
                    prize_first: 16000,
                    prize_second: 8000,
                    prize_third: 4000,
                },
                TournamentStageInfo {
                    stage_index: 2,
                    track_id: "monaco3".into(),
                    track_display_name: "Monte Carlo 3 (Монте-Карло 3)".into(),
                    laps: 3,
                    prize_first: 20000,
                    prize_second: 10000,
                    prize_third: 5000,
                },
            ],
        },

        // Modern Era (1989 - 2000)
        TournamentCup {
            id: "modern_boxster_challenge".into(),
            title: "Boxster Challenge".into(),
            description: "Турнир родстеров Porsche Boxster. Техничный трек и горный серпантин.".into(),
            era: TournamentEra::Modern,
            entry_fee: 4000,
            required_car_model: Some("boxster".into()),
            stages: vec![
                TournamentStageInfo {
                    stage_index: 0,
                    track_id: "skidpad".into(),
                    track_display_name: "Skidpad (Полигон)".into(),
                    laps: 3,
                    prize_first: 12000,
                    prize_second: 6000,
                    prize_third: 3000,
                },
                TournamentStageInfo {
                    stage_index: 1,
                    track_id: "coastal".into(),
                    track_display_name: "Côte d'Azur (Лазурный берег)".into(),
                    laps: 3,
                    prize_first: 14000,
                    prize_second: 7000,
                    prize_third: 3500,
                },
            ],
        },
        TournamentCup {
            id: "modern_world_championship".into(),
            title: "Porsche World Championship".into(),
            description: "Вершина карьеры Evolution! Борьба мощнейших суперкаров 911 GT3 и GT1 на пяти этапах за абсолютное звание чемпиона Porsche.".into(),
            era: TournamentEra::Modern,
            entry_fee: 10000,
            required_car_model: None,
            stages: vec![
                TournamentStageInfo {
                    stage_index: 0,
                    track_id: "autobahn".into(),
                    track_display_name: "Autobahn (Автобан)".into(),
                    laps: 3,
                    prize_first: 25000,
                    prize_second: 12000,
                    prize_third: 6000,
                },
                TournamentStageInfo {
                    stage_index: 1,
                    track_id: "alps".into(),
                    track_display_name: "Alps (Альпы)".into(),
                    laps: 3,
                    prize_first: 28000,
                    prize_second: 14000,
                    prize_third: 7000,
                },
                TournamentStageInfo {
                    stage_index: 2,
                    track_id: "monaco5".into(),
                    track_display_name: "Monte Carlo 5 (Монте-Карло 5)".into(),
                    laps: 4,
                    prize_first: 35000,
                    prize_second: 18000,
                    prize_third: 9000,
                },
            ],
        },
    ]
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_tournament_stage_progression_and_points() {
        let cups = get_tournaments_catalog();
        let cup = cups[0].clone(); // 356 Challenge (2 stages)
        let mut session = TournamentSession::new(cup, "TestDriver");

        assert_eq!(session.current_stage_index, 0);
        assert!(!session.completed);

        // Win stage 0 (P1)
        let (prize1, won1) = session.finish_stage(120.0, 1);
        assert_eq!(prize1, 4500);
        assert!(!won1); // not finished whole cup yet
        assert_eq!(session.current_stage_index, 1);
        assert_eq!(session.standings[0].points, 10);

        // Win stage 1 (P1)
        let (prize2, won2) = session.finish_stage(125.0, 1);
        assert_eq!(prize2, 4500);
        assert!(won2); // finished and won!
        assert!(session.completed);
        assert_eq!(session.standings[0].points, 20);
        assert!(session.won);
    }
}
