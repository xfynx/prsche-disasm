# 002-track-viewer

Статус: завершена и проверена (тег снимка: `iteration-002`).

Цель этой итерации — загрузить и показать один реальный участок трассы
с исходной геометрией, размещением и текстурами в native-просмотрщике и в браузере.
Базовый проверяемый ресурс — `skidpad` (`skidpad.crp`, `skidpad.fsh`).
Игровые файлы в эту папку не копируются (читаются из `local/game`).

## Состав и изменения

- `crates/nfs-formats`:
  - Добавлен парсер трассовых контейнеров CRP с сигнатурой `karT` (`track.rs`).
  - Расширен декодер FSH (`lib.rs`): добавлена поддержка 16-битных форматов `0x7e` (RGB 565) и `0x78` (ARGB 1555).
- `crates/nfs-assets`:
  - Реализован `track_loader.rs`: загрузка статической геометрии трека (`Base & 0x8000 == 0`), триангуляция списков треугольников (тип 3), квадов (тип 4) и triangle strips (тип 1), сопоставление материалов по `mt+0x28` с именами FSH-текстур, трансформация координат `[x, y, -z]` с порядком обхода CCW.
- `crates/porsche-viewer`:
  - Реализована поддержка CLI аргументов `--track <name>`, `--distance`, `--center-x/y/z`, `--fov` в native и browser интерфейсах.
  - Web UI: переключение режимов Car / Track с фильтрацией каталогов `Sky/` и автозаполнением.

## Требования

- Windows с установленным Rust toolchain из [`rust-toolchain.toml`](rust-toolchain.toml)
  (`1.98.1`, target `wasm32-unknown-unknown`).
- Для native-просмотрщика — Vulkan-драйвер.
- Для браузера — браузер с WebGPU (Chrome / Edge).
- Копия игры в `local/game` в корне репозитория.

## Базовые команды проверки

Команды выполняются из корня репозитория:

```powershell
. .\scripts\tool-env.ps1
cargo fmt --manifest-path iterations/002-track-viewer/Cargo.toml --all -- --check
cargo clippy --manifest-path iterations/002-track-viewer/Cargo.toml --target-dir local/builds/002-track-viewer/.cargo-target --locked --workspace -- -D warnings
cargo test --manifest-path iterations/002-track-viewer/Cargo.toml --target-dir local/builds/002-track-viewer/.cargo-target --locked --workspace
. .\scripts\build.ps1 -Iteration 002-track-viewer -Config release -Target all
py -3 scripts/test_track_cli.py
py -3 scripts/test_iterations.py
py -3 scripts/test_inventory_tracks.py
```

## Автомобильная регрессия

Итерация полностью сохраняет функциональность просмотра автомобилей из `001-car-viewer` (44/44 модели без регрессий):

```powershell
.\local\builds\002-track-viewer\windows\porsche-viewer.exe inspect --game-dir .\local\game --car 356a
.\local\builds\002-track-viewer\windows\porsche-viewer.exe view --game-dir .\local\game --car 356a
```

## Просмотр трасс

Команды CLI для просмотра и проверки участков трасс:

```powershell
.\local\builds\002-track-viewer\windows\porsche-viewer.exe inspect --game-dir .\local\game --track skidpad
.\local\builds\002-track-viewer\windows\porsche-viewer.exe view --game-dir .\local\game --track skidpad
.\local\builds\002-track-viewer\windows\porsche-viewer.exe view --game-dir .\local\game --track skidpad --screenshot iterations/002-track-viewer/runs/001-track-baseline/skidpad.png
```

## Проверенные результаты

- [Run 001](runs/001-track-baseline/README.md):
  - `skidpad-overview.png`: общий вид площадки и внешнего трека Skidpad.
  - `skidpad-road-joint.png`: макро-план стыка фрагментов `RD0040C` и `RD0048C` (дистанция 0.00000, без видимых швов).
  - `skidpad-tirewall.png`: детальный вид шинных барьеров `tir1`, каменных стен и деревьев.
- 100% сопоставление текстур: все 107 материалов Skidpad сопоставлены с текстурами `skidpad.fsh`.
- Все 15 трасс игры успешно валидируются через CLI inspect.
- Тесты: 36 unit tests, 0 warnings clippy, fmt check, CLI smoke tests проходят.

## Ограничения

- Динамические библиотечные пропы (конусы, флаги, машины трафика), спавнящиеся по файлам `.scn`, отфильтрованы и не расставляются в статической сцене трека.
- Небо (`Sky/`) и скайбоксы пока не загружаются в сцену.
- Дорожные сплайны, физические поверхности и сетка соединений блоков (`.edg`, `.jnc`, `.map`) относятся к следующим итерациям.
