# Run 002: приёмка 009-game-shell

Дата: 2026-09-24. Снимок: 009-game-shell.
Все задачи T00–T05 завершены. Итерация готова к закрытию и фиксации.

## Выполненные задачи и архитектура

1. **Бинарная база первого турнира и миссии (T03)**:
   - Исследованы структуры `nfs5.fac` (34 записи по 240 байт) и `nfs5.trn` (35 турниров по 3392 байта).
   - Расширен `nfs-formats`: добавлены парсеры `parse_tournaments` (`TournamentRecord`, `TournamentStage`), обновлён `FactoryMissionTemplate`.
   - Зафиксированы правила: 356 Challenge (Canyon, Monaco 1; 4 участника, вступительный взнос 2 000 CR, призовые 4 500 CR) и 0M01 Applying Test (Skidpad, Boxster, лимит 32.0 с).
   - Описание зафиксировано в [`research/first-events-evidence.md`](../../research/first-events-evidence.md).

2. **Модель игровой оболочки и карьер (T01, T02, T04)**:
   - Создан независимый Rust-крейт [`crates/nfs-game`](../../crates/nfs-game) (std + `nfs-formats`, 0 внешних зависимостей).
   - Реализована машина экранов `Screen` (`MainMenu`, `ProfileSelect`, `ModeSelect`, `EventBriefing`, `Loading`, `Racing`, `Results`).
   - Реализован профиль игрока `PlayerProfile`: баланс (начальный 11 000 CR), гараж, выбранная машина, ранги Factory Driver, открытые эпохи Evolution.
   - Реализовано атомарное сохранение профиля на диск (`.tmp` -> rename) и JSON-сериализатор/парсер.
   - Реализована идемпотентная обработка наград и защита от устаревших запросов загрузки при отмене.

3. **Интеграция Native и Web (T01, T02, T05)**:
   - `crates/porsche-viewer`: подключены WASM-экспорты (`shell_profile_new`, `shell_profile_buy_356`, `shell_apply_event_result`, `shell_get_first_evolution_event`, `shell_get_first_factory_event`).
   - Native: интеграция `GameShell`, атомарное сохранение `profile.json`, выбор трасс карьер по F2/F3, звуковые сигналы pass/fail через WinMM beeper.
   - Web: добавлены модальные окна (брифинг события, управление профилем, результаты заезда со спич-баллоном), профильная панель в шапке, WebAudio синтезатор (обороты двигателя RPM, визг шин при заносе, звуковые сигналы таймера и финиша).

4. **Регресс управления и физики (T00)**:
   - Подтверждено сохранение правильных знаков поворота колёс и курса в 6 DOF и аркадной модели.
   - Все 21 тест `porsche-viewer` (включая `test_car_steering_direction`, `steering_direction_forward_reverse_at_rotated_headings`) стабильно зелёные.

## Проверки и результаты

- **Cargo Test**: 129 passed (59 nfs-assets, 4 calibration bench, 1 race integration, 34 nfs-formats, 10 nfs-game, 21 porsche-viewer lib), 3 GPU tests ignored.
- **Cargo Clippy**: workspace/all-targets, `-D warnings` — без предупреждений.
- **Cargo Fmt**: `--check` — чисто.
- **UI Test**: `node iterations/009-game-shell/web/ui.test.mjs` — passed (проверены руль WASD/стрелки, потеря фокуса, модалы карьер, профиль, тумблер звука).
- **Сборка релизов**: `scripts/build.ps1 -Iteration 009-game-shell -Config release -Target all` — собраны Windows native (`porsche-viewer.exe`) и WebAssembly (`viewer_impl_bg.wasm` + `viewer_impl.js`).
- **Браузерная верификация WebGPU**: `verify-browser.cjs` выполнил 10 проверок в Chromium:
  - `skidpad boot`
  - `sim left headingRight=-0.2586`
  - `sim right headingRight=0.2022`
  - `arcade left headingRight=-0.2105`
  - `arcade right headingRight=0.2077`
  - `drive + simultaneous throttle/steer; speed=63`
  - `Esc restores menu; H hides HUD`
  - `alps/car catalog switch; diagnostic panel`
  - `focus release 1 -> 0`
  - Ошибки страницы: 0 (`errors: []`). Скриншоты сохранены в этой папке.
- **Native CLI**: `porsche-viewer.exe inspect --game-dir local/game --car 356a` завершается с кодом 0 и выводит диагностику без сбоев.
