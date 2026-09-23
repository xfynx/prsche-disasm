# Run 001: Game Systems Verification

Дата: 2026-09-23  
Итерация: `006-game-systems`  
Конфигурация: `release`, цели `native` и `wasm`  

---

## 1. Содержание запуска

Первый контрольный запуск итерации 006 объединяет исследовательскую базу бинарного реверс-инжиниринга и модули парсинга игровых форматов оригинальной NFS 5:
- **T01: Реверс-инжиниринг симуляции и AI**:
  - Точные смещения, PE-секции, функции загрузки `.sim` (`0x0049c750`) и `.ais` (`0x0049ca30`).
  - Масштабирующие коэффициенты (длины $\times 0.001$, жесткость/демпфирование $\times 0.01$, тяга $\times 25/56$).
- **T02: Парсеры физики и AI (`nfs-formats/src/sim.rs`)**:
  - `SimCar` (328 байт): 21 точка крутящего момента, передаточные числа КПП (вкл. R и N), подвеска, шины, геометрия.
  - `AisCar` (304 байта): профили ускорения (24 точки) и торможения/поворотов (40 точек).
  - 100% валидация на всех 88 файлах `.sim` и 22 файлах `.ais` из `local/game/GameData/Simulation/`.
- **T03: Карьера, каталоги и сохранения (`nfs-formats/src/career.rs`)**:
  - Реестр секций профиля `savedata/*.sav` (голова связного списка диспетчера `0x0065b634`).
  - Парсинг мастер-каталога автомобилей `nfs5.car` (109 авто $\times$ 1 648 байт).
  - Парсинг каталога трасс `nfs5.trk` (15 трасс $\times$ 1 192 байта).
  - Парсинг 34 миссий Factory Driver `nfs5.fac` (34 $\times$ 240 байт).
  - Парсинг профилей игрока (`XXDefXX.sav`, `0xfynx.sav`).
- **T04: Телеметрия, формат Replay и стенд симуляции (`nfs-formats/src/replay.rs`)**:
  - Доказано: реплеи NFS 5 — это детерминированная запись сигналов ввода управления (8 суб-сэмплов на тик), а не ключевые кадры траектории.
  - Декодирование RLE-потока ввода (руль с центром 64, газ, тормоз, передачи).
  - Парсинг 8 участников заезда из заголовка (1 408 байт на авто).
  - Открытие сетки крутящего момента: ровно 500 RPM на точку ($0..20 \times 500$ RPM).
  - Стенд замеров динамики `scripts/research/sim_bench.py` с сохранением baseline в `local/experiments/bench/sim_baseline.json`.
- **T05: Интеграция и верификация workspace**:
  - Полный набор юнит-тестов (83 теста).
  - Сборка native бинарника и WASM-пакета в `local/builds/006-game-systems`.

---

## 2. Результаты проверок

| Проверка | Команда | Статус | Артефакт |
|----------|---------|--------|----------|
| Форматирование | `cargo fmt -- --check` | **PASS** (0 diffs) | [`fmt.log`](fmt.log) |
| Статический анализ | `cargo clippy --workspace --all-targets -- -D warnings` | **PASS** (0 warnings) | [`clippy.log`](clippy.log) |
| Регрессионные тесты | `cargo test --workspace` | **PASS** (83 passed, 0 failed, 3 ignored GPU) | [`test.log`](test.log) |
| Полная сборка | `.\scripts\build.ps1 -Iteration 006-game-systems -Config release -Target all` | **PASS** (native + wasm) | [`build.log`](build.log) |

### Статистика тестового набора:
- `nfs-formats`: **32 теста** (sim, ais, career, replay, topology, fsh, crp, ini, scn)
- `nfs-assets`: **32 теста** (scene loader, 356 variants, track loader, road surface grid, diagnostics)
- `porsche-viewer`: **19 тестов** (arcade driving physics, inputs, acceleration, braking, controls)

---

## 3. Выводы и готовность

Итерация `006-game-systems` полностью выполнила все поставленные задачи. Подготовлен строгий доказательный фундамент оригинальных данных NFS 5 для реализации физической симуляции в итерации `007-physics-simulation`.
