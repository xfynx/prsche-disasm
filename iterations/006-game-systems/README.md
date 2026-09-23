# 006-game-systems

Статус: завершена.
Снимок создан из `005-unified-driving` (скрипт `scripts/new-iteration.py`).
Тег: `iteration-006`.
Собственная история runs: [001-game-systems](runs/001-game-systems/README.md). `local/game` read-only.


Цель: карта поведения оригинальной игры (NFS 5) и разработка парсеров её ключевых
форматов данных (`Simulation`, `FEData`, `savedata`). Подготовка доказательного фундамента
для симуляции физики (007) и режима заезда/карьеры (008–010).

## Основные направления

1. **Реверс-инжиниринг бинарников**:
   - Фиксация SHA-256, Image Base и смещений секций `nfs5.exe` и модулей.
   - Реестр call sites, функций загрузки и структур данных в памяти.
2. **Форматы симуляции (`nfs-formats`)**:
   - Парсинг 88 файлов `.sim` (`GameData/Simulation/*.sim`) — кривые крутящего момента,
     передачи, подвеска, шины, распределение масс.
   - Парсинг 22 файлов `.ais` (`GameData/Simulation/*.ais`) — настройки поведения AI.
3. **Системы карьер и сохранения**:
   - Схемы данных событий Evolution и Factory Driver (`FEData`).
   - Формат файлов сохранений профиля в `savedata`.
4. **Контрольный стенд замеров оригинала**:
   - Методика воспроизводимых измерений разгона/торможения/динамики в `local/experiments`.
   - Набор контрольных метрик для валидации будущей симуляции в 007.

## Запуск и проверки

Из корня репозитория:

```powershell
. .\scripts\tool-env.ps1
cargo fmt --manifest-path iterations/006-game-systems/Cargo.toml --all -- --check
cargo clippy --locked --manifest-path iterations/006-game-systems/Cargo.toml --target-dir local/builds/006-game-systems/.cargo-target --workspace --all-targets -- -D warnings
cargo test --locked --manifest-path iterations/006-game-systems/Cargo.toml --target-dir local/builds/006-game-systems/.cargo-target --workspace
.\scripts\build.ps1 -Iteration 006-game-systems -Config release -Target all
```

Детальный рабочий план: [PLAN.md](PLAN.md).
Общая дорожная карта: [docs/roadmap.md](../../docs/roadmap.md).
