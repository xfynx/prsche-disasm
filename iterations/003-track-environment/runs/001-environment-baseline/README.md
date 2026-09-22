# Run 001: environment baseline (skidpad props & sky)

- Дата: 2026-09-22
- Трасса: `skidpad` (`skidpad.crp`, `skidpad.fsh`, `skidpad_st1.scn`, `Sky/Skidpad.fsh`)
- Цель: проверить рендеринг визуального окружения трека `skidpad`:
  1. Динамические пропы, расставленные по файлу сценария `.scn` (конусы `CONE`, указатели `ARW1`).
  2. Фоновый купол/скайбокс неба из `Sky/Skidpad.fsh` (`horz`) с круговой панорамой горизонта.
  3. Сохранение полной регрессионной стабильности автомобилей (44 модели) и трасс (15 трасс).
- Сборка: native release (`porsche-viewer.exe`) + web (`viewer_impl_bg.wasm`)

## Команды

```powershell
. .\scripts\tool-env.ps1

# 1. Сборка всех артефактов (native + wasm)
.\scripts\build.ps1 -Iteration 003-track-environment -Config release -Target all

# 2. Обзорный вид трека с небом и расставленными объектами сценария
.\local\builds\003-track-environment\windows\porsche-viewer.exe view `
  --game-dir local/game --track skidpad `
  --screenshot iterations/003-track-environment/runs/001-environment-baseline/skidpad-overview.png

# 3. Макро-вид дорожного конуса CONE на полотне трека
.\local\builds\003-track-environment\windows\porsche-viewer.exe view `
  --game-dir local/game --track skidpad `
  --center-x -16.17 --center-y 0.0 --center-z -144.58 --distance 8.0 --pitch 0.2 --yaw 0.5 `
  --screenshot iterations/003-track-environment/runs/001-environment-baseline/skidpad-cone-macro.png

# 4. Макро-вид стартовой стрелки ARW1 над полотном
.\local\builds\003-track-environment\windows\porsche-viewer.exe view `
  --game-dir local/game --track skidpad `
  --center-x -7.33 --center-y 1.5 --center-z -150.21 --distance 18.0 --pitch 0.15 --yaw 0.3 `
  --screenshot iterations/003-track-environment/runs/001-environment-baseline/skidpad-arrow-macro.png

# 5. Вид с уровня глаз водителя (трасса, конус, строения, стена, горизонт)
.\local\builds\003-track-environment\windows\porsche-viewer.exe view `
  --game-dir local/game --track skidpad `
  --center-x -16.17 --center-y 1.0 --center-z -144.58 --distance 3.0 --pitch 0.05 --yaw 1.2 `
  --screenshot iterations/003-track-environment/runs/001-environment-baseline/skidpad-driver-view.png
```

## Полученные скриншоты

1. `skidpad-overview.png` — общий вид трека `skidpad` с высоты: видны все 11 расставленных объектов сценария (конусы разметки слалома и стартовая стрелка) и фоновая панорама холмов и неба.
2. `skidpad-cone-macro.png` — макро-план дорожного конуса `CONE`: объект стоит точно на поверхности асфальта, без парения и смещений, видны светоотражающая полоса, ограждение трека и горизонт.
3. `skidpad-arrow-macro.png` — крупный план указателя направления `ARW1`: корректная ориентация по матрице 3x3 из `.scn` и привязка текстуры.
4. `skidpad-driver-view.png` — вид с водительской позиции на трассу: конус первого створа, асфальтовое покрытие, здания базы, деревья, каменная стена и естественный горизонт за ней.

## Результаты проверок

- Сценарий `.scn`: парсер `nfs-formats/src/scn.rs` извлекает координаты, FourCC и матрицу вращения. В `skidpad_st1.scn` успешно сопоставлены 11/11 элементов.
- Библиотечные пропы (`Base & 0x8000 != 0`): меши извлекаются из статей CRP, сохраняются в шаблонах пропов сцены и инстанцируются в мировые координаты без артефактов в центре трека.
- Скайбокс: панорамная текстура горизонта `horz` из `Sky/<track>.fsh` (256x256, два тайла по 180°) разворачивается в круговой цилиндр 360° с плавной интерполяцией в зенит и надир.
- Регрессия автомобилей: 44/44 модели успешно загружаются через `inspect` (0 регрессий).
- Регрессия трасс: 15/15 трасс игры успешно загружаются с пропами и небом (0 регрессий).
- Тесты: 40 unit-тестов проходят (`cargo test`), `cargo clippy -- -D warnings` чист, `cargo fmt` проверен.
