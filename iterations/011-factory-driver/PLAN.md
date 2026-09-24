# 011-factory-driver: рабочий план

Завершена 2026-09-24. Статус: ВЫПОЛНЕНА (ACCEPTED).
Снимки 001–010 и local/game неизменны. Run 001 закрыт.

## Цель и критерии

Полный режим карьеры **Factory Driver (Заводской водитель)** и устранение дефектов кампаний:
1. Все 34 миссии из оригинального файла `nfs5.fac` и языковой базы `festrings.csv`. [Выполнено]
2. Детекторы трюков: разворот на 180°, волчок на 360° с ручником, полицейский разворот (J-turn задним ходом), слалом вокруг конусов со штрафами (+2.0с) и контроль порога повреждений кузова. [Выполнено]
3. Система карьерного роста пилота: от Кандидата (Applicant) до Мастера-пилота (Master Ace Driver) Porsche. [Выполнено]
4. Наградные автомобили за ключевые этапы, автоматически начисляемые в гараж профиля (`'78 911 Turbo 3.3`, `'73 911 Carrera RS 2.7`, `'99 911 GT3 Factory Edition`). [Выполнено]
5. Веб-интерфейс лестницы миссий с репликами шеф-инструктора Рольфа, фильтрами по уровням сложности (Tier 1–3) и карточками статуса (Пройдено / Доступно / Заблокировано). [Выполнено]
6. Сохранение полной информации о ранге, пройденных миссиях и лучших временах в `PlayerProfile`. [Выполнено]
7. **Устранение дефектов кампаний и аутентичность интерфейса**:
   - Аутентичный стиль брифинга NFS: Porsche Unleashed (плашка Рольфа, титан/золото, карточка спецификаций спорткара). [Выполнено]
   - Устранение ошибки покупки авто (`missing or invalid 'version'`). [Выполнено]
   - Загрузка настоящих 3D-моделей Porsche (`.crp`/`.fsh`) и параметров симуляции в сюжетных заданиях вместо коробчатой заглушки. [Выполнено]
   - Исправление трассы Canyon и заземления машины со старта Evolution. [Выполнено]

## Задачи и результаты

- [x] T01: Бинарный реверс миссий Factory Driver (`nfs5.fac`) и текстовой базы `festrings.csv`.
  - Извлечены параметры всех 34 миссий: треки, авто, типы заданий, нормативы времени, брифинги и реплики Рольфа.
  - Документировано в `research/missions_catalog.md` и `research/factory-driver-evidence.md`.
- [x] T02: Движок миссий и трюков `factory_driver.rs` в `crates/nfs-game`.
  - Модели трюков: `StuntDetector` (180° slide, 360° spin, reverse J-turn, cone collision penalties, damage monitor).
  - Оценка выполнения: `evaluate_mission()`, `apply_mission_completion()`.
  - Тесты: 4 специализированных теста в `factory_driver::tests`.
- [x] T03: Карьерные ранги и наградные автомобили.
  - Карьерная лестница: Applicant -> Junior Test Driver -> Test Driver -> Senior Test Driver -> Chief Test Driver -> Master Ace.
  - Наградные автомобили за миссии 13, 23 и 34 с уникальными заводскими модификациями.
- [x] T04: UI лестницы испытаний и интеграция с Web/WASM.
  - Модальное окно `#factoryMissionsModal`, фильтрация по Tier 1–3, отображение статусов и рекордов.
  - Экспорт функций `shell_get_factory_missions` и `shell_complete_factory_mission` в `browser.rs`.
- [x] T05: Устранение дефектов сюжетных кампаний и интерфейса:
  - Брифинг в стиле Porsche Unleashed: карточка авто со спецификациями (л.с., масса, привод), цитата Рольфа, цели, призы.
  - Покупка авто: lenient deserialization профиля в `profile.rs` и `main.js` с `version: 1`.
  - Реальные авто: `viewer.set_car_model(...)` с динамической заменой мешей и текстур.
  - Трасса Canyon: фильтрация `fedata/trackart`, заземление `road_surface.query`, ориентация камеры.
- [x] T06: Автоматизированные тесты, регресс управления и приёмка (Run 001).
  - 142 теста Rust passed across workspace, Clippy `-D warnings` 0 warnings, Rustfmt clean.
  - Playwright Chromium checks: 12/12 проверок (0 errors), регресс руления в аркаде и симуляторе подтверждён, заезды на Canyon и миссии 0M01 подтверждены.
  - Оформлена приёмка в `runs/001-factory-driver/README.md`.

## Проверки

```powershell
. ./scripts/tool-env.ps1
cargo fmt --manifest-path iterations/011-factory-driver/Cargo.toml --all -- --check
cargo test --locked --manifest-path iterations/011-factory-driver/Cargo.toml --target-dir local/builds/011-factory-driver/.cargo-target --workspace
cargo clippy --locked --manifest-path iterations/011-factory-driver/Cargo.toml --target-dir local/builds/011-factory-driver/.cargo-target --workspace --all-targets -- -D warnings
node iterations/011-factory-driver/web/ui.test.mjs
./scripts/build.ps1 -Iteration 011-factory-driver -Config release -Target all
```
