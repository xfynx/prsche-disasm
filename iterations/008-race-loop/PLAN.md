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

- [ ] **T01: race state machine & timing** — конечный автомат гонки (`RaceStateMachine`): состояния `Countdown`, `Racing`, `Paused`, `Finished`, `Results`, таймеры кругов и дельт.
- [ ] **T02: track course & checkpoints** — построение маршрута трассы (`TrackCourse`): осевая линия из `.jnc`/`.map`, чекпоинт-створы поперек полотна, фиксация кругов, направление (Forward/Reverse), детекция Wrong Way.
- [ ] **T03: barrier collision** — физика отскока от кромок полотна `.edg`: вычисление точки контакта, нормали барьера и импульса отскока шасси.
- [ ] **T04: AI opponents & grid** — соперники ИИ (`AiController`): профили `AisCar`, следование по траектории с контролем скорости в поворотах, стартовая решётка, расчёт позиций.
- [ ] **T05: race HUD & results UI** — гоночный HUD (позиция, круг, секундомер, предупреждения) и экран результатов в Web и Native окнах.
- [ ] **T06: integration, verification & run 001** — headless integration тест полного цикла заезда, проверка сборки native/WASM, оформление Run 001.

## Проверки

```powershell
. .\scripts\tool-env.ps1
cargo fmt --manifest-path iterations/008-race-loop/Cargo.toml --all -- --check
cargo clippy --locked --manifest-path iterations/008-race-loop/Cargo.toml --target-dir local/builds/008-race-loop/.cargo-target --workspace --all-targets -- -D warnings
cargo test --locked --manifest-path iterations/008-race-loop/Cargo.toml --target-dir local/builds/008-race-loop/.cargo-target --workspace
.\scripts\build.ps1 -Iteration 008-race-loop -Config release -Target all
```
