# 006-game-systems: рабочий план

Начата 2026-09-23 из завершённой `005-unified-driving`. `local/game` только читается.
Собственная история runs начинается с 001. Статус: в работе, тег не создан.

## Цель и критерии готовности

Создать доказательную карту поведения оригинальной игры (NFS 5) и разработать парсеры
её ключевых форматов данных (`Simulation`, `FEData`, `savedata`) как фундамент
для последующей симуляции физики (007) и режима заезда/карьеры (008–010).

- Зафиксировать SHA-256, Image Base и карту секций исследуемых бинарников (`nfs5.exe` и сопутствующие DLL).
  Обеспечить точный перевод RVA в файловые смещения.
- Создать структурированный реестр вызовов и функций загрузки данных: подтверждающие call sites,
  аргументы, уровень уверенности, разделение установленных фактов и гипотез.
- Исследовать и реализовать парсеры конфигураций симуляции в `nfs-formats`:
  * 88 файлов `.sim` (`GameData/Simulation/*.sim`): параметры автомобиля, двигателя (RPM/Torque),
    передаточных чисел КПП, распределения массы, параметров подвески и шин.
  * 22 файла `.ais` (`GameData/Simulation/*.ais`): параметры поведения искусственного интеллекта.
- Исследовать структуры карьер и сохранений:
  * Реестр событий Evolution и Factory Driver из `FEData`: экраны, требования, этапы.
  * Формат файлов сохранений профиля в `savedata` (структура заголовка, прогресс, открытые авто).
- Подготовить воспроизводимый стенд контрольных сценариев оригинала в `local/experiments`:
  * Замеры разгона, торможения и установившегося круга для нескольких контрастных авто
    (напр. классический `356a`, среднемоторный `Boxster`, мощный `996/GT3`).
  * Фиксация телеметрии для валидации будущей симуляции в 007.
- Нулевая регрессия: fmt, clippy (`-D warnings`), прохождение всех тестов workspace,
  успешная сборка native и WASM.

## Подтверждённое и гипотезы

Подтверждено в 005:
- В `local/game/GameData/Simulation/` находится 88 файлов `.sim` и 22 файла `.ais`.
- В `iterations/005-unified-driving/research/campaign-inventory.md` задокументирован
  первичный реестр FE-колбэков, строковых идентификаторов и маркеров сохранений.
- Spatial grid статической геометрии дороги (`surface.rs`) обеспечивает точные запросы
  высоты и нормали на всех 15 трассах (ошибка < 0.0002 м).

Гипотезы и ограничения:
- Точная семантика всех полей в `.sim` требует сопоставления со структурой в памяти EXE;
  неизвестные поля сохраняются как сырые байты/структуры без домыслов.
- Запуск оригинального EXE для замеров допускается исключительно в `local/experiments`.

## Задачи и владельцы

- T01: координатор / reversing — [ВЫПОЛНЕНО] фиксация SHA-256/RVA бинарников, карта секций, функции загрузки `.sim` (VA `0x0049c750`) и `.ais` (VA `0x0049ca30`), масштабирующие коэффициенты. См. `research/simulation-evidence.md`.
- T02: formats — [ВЫПОЛНЕНО] парсеры `.sim` (`SimCar`, 328 байт) и `.ais` (`AisCar`, 304 байта) в `nfs-formats/src/sim.rs`. Валидация 88/88 `.sim` и 22/22 `.ais` файлов игры.
- T03: career / formats — [ВЫПОЛНЕНО] архитектура профиля игрока (`savedata/*.sav`, 9 секций, голова списка `0x0065b634`), парсеры `SaveFile` (`.sav`), `CarCatalogEntry` (`nfs5.car`, 109 авто), `TrackCatalogEntry` (`nfs5.trk`, 15 трасс), `FactoryMissionTemplate` (`nfs5.fac`, 34 миссии). См. `research/career-evidence.md`.
- T04: simulation bench — [ВЫПОЛНЕНО] реверс формата реплеев и телеметрии (`replay.rpl`, детерминированный поток управления по 8 суб-сэмплам на тик), парсер `ReplayFile` в `nfs-formats/src/replay.rs`, открытие 500 RPM сетки крутящего момента, baseline стенд динамики в `local/experiments/bench/sim_baseline.json`. См. `research/telemetry-evidence.md`.
- T05: координатор — [ВЫПОЛНЕНО] интеграция в workspace, 83 unit-теста, чистые `fmt` и `clippy` (`-D warnings`), полная сборка native + WASM, фиксация артефактов Run 001 (`runs/001-game-systems/`).

Итоги шага: 83 unit tests passed (32 formats, 32 assets, 19 viewer), fmt/clippy чистые, Run 001 зафиксирован.

## Проверки

```powershell
. .\scripts\tool-env.ps1
cargo fmt --manifest-path iterations/006-game-systems/Cargo.toml --all -- --check
cargo clippy --locked --manifest-path iterations/006-game-systems/Cargo.toml --target-dir local/builds/006-game-systems/.cargo-target --workspace --all-targets -- -D warnings
cargo test --locked --manifest-path iterations/006-game-systems/Cargo.toml --target-dir local/builds/006-game-systems/.cargo-target --workspace
.\scripts\build.ps1 -Iteration 006-game-systems -Config release -Target all
```

Ближайший шаг: приёмка пользователем и закрытие итерации 006 (переход к 007-physics-simulation).

