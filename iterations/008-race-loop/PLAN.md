# 008-race-loop: рабочий план

Начата 2026-09-23 из завершённой `007-physics-simulation`. `local/game` только читается.  
Собственная история runs начинается с 001. Статус: в работе, тег не создан.

## Цель и критерии готовности

Реализовать законченный гоночный заезд (одиночный и против соперников ИИ) от предстартового отсчёта до финиша и таблицы результатов, объединяющий 6 DOF физику (007), топологию трасс (004-005) и форматы ИИ (006).

- **Конечный автомат состояния заезда (Race State Machine)**:
  - Состояния: `Loading`, `Countdown(3..2..1..GO)`, `Racing`, `Paused`, `Finished`, `Results`.
  - Точный тайминг: общий секундомер, время круга, лучший круг (`best_lap`), дельты сплитов.
- **Маршрутная система и чекпоинты (Track Course & Checkpoints)**:
  - Осевая линия и контрольные створы (чекпоинты) на базе `.jnc`, `.edg`, `.map`.
  - Поддержка круговых трасс и спринтов (Point-to-Point).
  - Защита от срезок, детекция движения в неверную сторону («Wrong Way»).
- **Коллизии с дорожными барьерами**:
  - Упруго-пластический импульс отскока от кромок полотна `.edg`.
  - Потеря скорости и управляемости при скользящем трении об отбойник без вылета в бесконечность.
- **ИИ соперники**:
  - Управление ботами по профилям `AisCar` из `.ais`.
  - Следование траектории, удержание в пределах полотна, стартовая решётка до 8 машин.
  - Таблица текущих позиций (1..8) по пройденной дистанции.
- **Гоночный интерфейс и экран результатов**:
  - HUD: текущая позиция (P1/8), круг (Lap 1/3), секундомер, таймер лучшего круга, индикатор Wrong Way.
  - Окно финиша: итоговые времена, отрывы (+gap), лучший круг.
- **Нулевая регрессия**:
  - `cargo fmt --check` чистый.
  - `cargo clippy -- -D warnings` чистый.
  - 100% unit и integration тестов проходят.
  - Сборка release native и WASM.

## Задачи и статус выполнения

- [x] **T01: race state machine & timing** — конечный автомат гонки (`RaceSession`): состояния `Countdown(3..2..1..GO)`, `Racing`, `Paused`, `Finished`, `Results`, таймеры кругов, дельт и лучшего круга (`nfs-assets/src/race/state.rs`).
- [x] **T02: track course & checkpoints** — реверс-инжиниринг формата `.lsp` (Line Spline Path), парсер 30 файлов трасс, построение маршрута трассы (`TrackCourse`), автоматическая классификация круговая/спринт (gap < 60м), чекпоинт-створы, фиксация кругов, детекция Wrong Way (`nfs-assets/src/race/course.rs`, `nfs-formats/src/topology.rs`).
- [x] **T03: barrier collision** — физика отскока от кромок полотна `.edg`: вычисление точки контакта, нормали барьера и упруго-пластического импульса отскока с трением (`nfs-assets/src/race/collision.rs`).
- [x] **T04: AI opponents & grid** — соперники ИИ (`AiOpponent`): профили `AisCar` из `.ais`, следование по траектории с чистым преследованием (pure pursuit) и контролем скорости по кривизне $v = \sqrt{a_{lat}/\kappa}$, стартовая решётка до 8 машин (`calculate_grid_slot`), расчёт позиций (`nfs-assets/src/race/ai.rs`).
- [x] **T05: race HUD & results UI** — гоночный HUD (позиция P1/4, круг, секундомер, таймер лучшего круга, пульсирующий баннер отсчёта, предупреждение Wrong Way) и модальное окно финиша в Web и Native окнах (`porsche-viewer`, `web/main.js`, `web/style.css`, `web/index.html`).
- [x] **T06: integration, verification & run 001** — headless integration тест полного цикла заезда (`tests/race_integration.rs`), проверка сборки release native/WASM, оформление Run 001 (`runs/001-race-loop/README.md`).

## Проверки

```powershell
. .\scripts\tool-env.ps1
cargo fmt --manifest-path iterations/008-race-loop/Cargo.toml --all -- --check
cargo clippy --locked --manifest-path iterations/008-race-loop/Cargo.toml --target-dir local/builds/008-race-loop/.cargo-target --workspace --all-targets -- -D warnings
cargo test --locked --manifest-path iterations/008-race-loop/Cargo.toml --target-dir local/builds/008-race-loop/.cargo-target --workspace
.\scripts\build.ps1 -Iteration 008-race-loop -Config release -Target all
```
