# 010-evolution-career: рабочий план

Завершена 2026-09-24. Статус: ВЫПОЛНЕНА (ACCEPTED).
Снимки 001–009 и local/game неизменны. Run 001 закрыт.

## Цель и критерии

Полный режим карьеры **Evolution**:
1. Все турниры и кубки эпохи Classic (1950–1969) из `nfs5.trn`. [Выполнено]
2. Древо прогрессии эпох (Classic -> Golden -> Modern). [Выполнено]
3. Экономика авторынка: покупка/продажа новых и подержанных авто с учётом износа и пробега. [Выполнено]
4. Магазин запчастей и тюнинг: покупка, установка модификаций, ремонт изношенных узлов с прямым влиянием на массу, мощность двигателя и сцепление шин. [Выполнено]
5. Физический аудит качества трасс: проверка всех 15 трасс на отсутствие дыр геометрии, коллизии с барьерами и стабильность удержания машины на полотне без проваливания. [Выполнено]
6. Сохранение полной информации об автопарке, износе и модификациях в профиле игрока (`PlayerProfile`). [Выполнено]

## Задачи и результаты

- [x] T01: Бинарный реверс турниров, запчастей и рынка авто (исследователь/formats).
  - Спецификация 35 турниров `nfs5.trn` и 683 записей запчастей `nfs5.prt`.
  - Отчёт в `research/evolution-evidence.md`. Модули в `crates/nfs-formats/src/career.rs`.
- [x] T02: Турнирный движок `TournamentSession` в `nfs-game`.
  - Зачётная система кубков (10, 6, 4, 3, 2, 1), турнирная таблица очков между этапами, призовые выплаты, условия открытия следующих кубков.
  - Реализовано в `crates/nfs-game/src/tournament.rs`.
- [x] T03: Авторынок и гараж (`Dealership`).
  - Покупка новых автомобилей из салона и подержанных со случайным/историческим пробегом и износом.
  - Продажа автомобилей из гаража по остаточной рыночной стоимости.
  - Реализовано в `crates/nfs-game/src/economy.rs` и `crates/nfs-game/src/profile.rs`.
- [x] T04: Магазин запчастей, тюнинг и ремонт (`PartsShop`).
  - Каталог узлов: двигатель (впуск/выпуск/распредвал), тормоза, подвеска (пружины/стабилизаторы), шины (дорожные/спортивные/слики), облегчение кузова.
  - Расчёт износа, ухудшение модификаторов и процедура ремонта.
  - Реализовано в `crates/nfs-game/src/parts.rs`.
- [x] T05: Физический аудит качества всех 15 трасс (дыры, барьеры, out-of-bounds).
  - Автоматизированный стенд проверки всех 15 трасс в `crates/nfs-assets/tests/track_physics_audit.rs`.
  - 100% удержание барьерами (0 туннелирований на скоростях 144 и 252 км/ч), сплошность полотна 73.9%..100.0%.
  - Отчёт в `research/track-physics-audit.md`.
- [x] T06: UI интеграция, регресс и приёмка (Run 001).
  - Веб- и нативный интерфейс турниров, автосалона и магазина запчастей.
  - 138 тестов Rust passed, clippy `-D warnings` 0 warnings, rustfmt clean, Playwright Chromium checks passed (0 errors).
  - Приёмка оформлена в `runs/001-evolution-career/README.md`.

## Проверки

```powershell
. ./scripts/tool-env.ps1
cargo fmt --manifest-path iterations/010-evolution-career/Cargo.toml --all -- --check
cargo test --locked --manifest-path iterations/010-evolution-career/Cargo.toml --target-dir local/builds/010-evolution-career/.cargo-target --workspace
cargo clippy --locked --manifest-path iterations/010-evolution-career/Cargo.toml --target-dir local/builds/010-evolution-career/.cargo-target --workspace --all-targets -- -D warnings
node iterations/010-evolution-career/web/ui.test.mjs
./scripts/build.ps1 -Iteration 010-evolution-career -Config release -Target all
```
