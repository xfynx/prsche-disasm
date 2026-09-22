# 003-track-environment

Статус: завершена и проверена (тег снимка: `iteration-003`).

Цель этой итерации — воспроизвести полное визуальное окружение трассы на примере `skidpad`:
1. Расстановка динамических библиотечных объектов трека (`Base & 0x8000 != 0`) по данным сценария расстановки (`.scn`).
2. Загрузка и рендеринг купола/скайбокса неба (`Sky*.fsh`), привязанного к треку, с круговой панорамой горизонта.
3. Сохранение полной регрессионной стабильности для автомобилей (44 модели) и базового статического отображения всех 15 трасс.

Игровые файлы в эту папку не копируются (читаются из общего read-only каталога `local/game`).

## Состав и изменения

- `crates/nfs-formats`:
  - Добавлен парсер сценариев расстановки `.scn` (`scn.rs`): декодирование мировых координат `[X, Y, Z]`, матрицы ориентации 3x3 и FourCC идентификатора объекта (`CONE`, `ARW1` и др.).
- `crates/nfs-assets`:
  - Расширен `track_loader.rs`:
    - Извлечение мешей библиотечных пропов из CRP по флагу `Base & 0x8000 != 0` и FourCC со смещения `Base:0 +0x44`.
    - Сохранение шаблонов пропов в `scene.prop_articles` и добавление их мешей после статической геометрии полотна (`static_mesh_count`), что полностью предотвращает появление парящих объектов в центре трека `(0, 0, 0)`.
    - Загрузка панорамы горизонта `horz` из `Sky/<track>.fsh`.
    - Улучшена фильтрация ресурсов: отсечение меню-арта (`fedata`, `trackart`) и изоляция текстур неба от текстур полотна трассы.
- `crates/porsche-viewer`:
  - Контракт `Scene` расширен полями `prop_articles`, `prop_instances`, `sky_texture`. Реализован трейт `Default`.
  - Шейдер `sky.wgsl`: развёртка двух вертикально расположенных тайлов 256x128 текстуры `horz` в единую непрерывную 360-градусную цилиндрическую панораму горизонта с плавным переходом в фоновый цвет земли/неба `(0.647, 0.518, 0.388)` в надир.
  - Рендерер `renderer.rs`: проход отрисовки скайбокса (depth = 0.99999, без трансляции камеры, только вращение), отрисовка статической геометрии полотна (identity model matrix) и проход инстанцирования пропов (`PropDraw`) с индивидуальными model-матрицами.

## Требования

- Windows с установленным Rust toolchain из [`rust-toolchain.toml`](rust-toolchain.toml) (`1.98.1`, target `wasm32-unknown-unknown`).
- Для native-просмотрщика — Vulkan-драйвер.
- Для браузера — браузер с поддержкой WebGPU (Chrome / Edge).
- Копия игры в `local/game` в корне репозитория.

## Базовые команды проверки

Команды выполняются из корня репозитория:

```powershell
. .\scripts\tool-env.ps1
cargo fmt --manifest-path iterations/003-track-environment/Cargo.toml --all -- --check
cargo clippy --manifest-path iterations/003-track-environment/Cargo.toml --target-dir local/builds/003-track-environment/.cargo-target --locked --workspace -- -D warnings
cargo test --manifest-path iterations/003-track-environment/Cargo.toml --target-dir local/builds/003-track-environment/.cargo-target --locked --workspace
. .\scripts\build.ps1 -Iteration 003-track-environment -Config release -Target all
py -3 scripts/test_track_cli.py
```

## Просмотр окружения и пропов

Команды CLI для просмотра трассы с пропами и небом:

```powershell
# Обзорный осмотр трека skidpad
.\local\builds\003-track-environment\windows\porsche-viewer.exe view --game-dir .\local\game --track skidpad

# Макро-вид расставленного конуса на асфальте
.\local\builds\003-track-environment\windows\porsche-viewer.exe view `
  --game-dir .\local\game --track skidpad `
  --center-x -16.17 --center-y 0.0 --center-z -144.58 --distance 8.0 --pitch 0.2 --yaw 0.5

# Макро-вид стартовой стрелки
.\local\builds\003-track-environment\windows\porsche-viewer.exe view `
  --game-dir .\local\game --track skidpad `
  --center-x -7.33 --center-y 1.5 --center-z -150.21 --distance 18.0 --pitch 0.15 --yaw 0.3
```

## Результаты верификации

- **[Run 001](runs/001-environment-baseline/README.md)**: offscreen Vulkan-снимки трека `skidpad`:
  - `skidpad-overview.png`: общий вид с высоты с расставленными пропами и горизонтом.
  - `skidpad-cone-macro.png`: макро-вид конуса `CONE`, стоящего точно на асфальте.
  - `skidpad-arrow-macro.png`: макро-вид стартового указателя `ARW1`.
  - `skidpad-driver-view.png`: вид с водительской позиции на трассу, конус, здания и горизонт.
- **Нулевая регрессия**:
  - Автомобили: 44/44 модели успешно загружаются через `inspect`.
  - Трассы: 15/15 трасс игры успешно загружаются с пропами и небом через `inspect`.
- **Тесты**: 40 unit-тестов проходят, Clippy чист, форматирование соблюдено, сборки native и WASM успешны.
