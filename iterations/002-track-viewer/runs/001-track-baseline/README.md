# Run 001: track baseline (skidpad)

- Дата: 2026-09-22
- Трасса: `skidpad` (`skidpad.crp`, `skidpad.fsh`)
- Цель: проверить рендеринг первого полноценного участка трассы: дорожное полотно, стык между смежными блоками (`RD0040C` и `RD0048C`), текстурирование и объекты окружения (шинные отбойники, деревья, строения).
- Сборка: native release (`porsche-viewer.exe`) + web (`viewer_impl_bg.wasm`)

## Команды

```powershell
. .\scripts\tool-env.ps1

# 1. Сборка всех артефактов (native + wasm)
.\scripts\build.ps1 -Iteration 002-track-viewer -Target all

# 2. Обзорный вид трассы
.\local\builds\002-track-viewer\windows\porsche-viewer.exe view `
  --game-dir local/game --track skidpad `
  --screenshot iterations/002-track-viewer/runs/001-track-baseline/skidpad-overview.png `
  --pitch 0.65 --yaw 0.5 --width 1280 --height 720

# 3. Детальный вид дорожного полотна и стыка фрагментов RD0040C и RD0048C
.\local\builds\002-track-viewer\windows\porsche-viewer.exe view `
  --game-dir local/game --track skidpad `
  --screenshot iterations/002-track-viewer/runs/001-track-baseline/skidpad-road-joint.png `
  --center-x 105.8 --center-y 0.2 --center-z -195.3 --distance 45.0 --pitch 0.4 --yaw 2.3 `
  --width 1280 --height 720

# 4. Детальный вид объектов окружения (шинные отбойники TIREWALL01, каменная стена, деревья)
.\local\builds\002-track-viewer\windows\porsche-viewer.exe view `
  --game-dir local/game --track skidpad `
  --screenshot iterations/002-track-viewer/runs/001-track-baseline/skidpad-tirewall.png `
  --center-x -97.4 --center-y 0.8 --center-z 181.1 --distance 30.0 --pitch 0.2 --yaw 1.2 `
  --width 1280 --height 720
```

## Полученные скриншоты

1. `skidpad-overview.png` — полный вид кругового трека Skidpad, внутренней бетонной площадки, внешнего асфальтового кольца и прилегающего ландшафта (поля, холмы, деревья).
2. `skidpad-road-joint.png` — макро-план дорожного полотна на стыке блоков `RD0040C` и `RD0048C`: идеальное совпадение геометрии вершин (расстояние 0.00000), непрерывная разметка и текстура асфальта без швов.
3. `skidpad-tirewall.png` — объекты окружения: трёхмерные секции шинных отбойников (`tir1`), каменная ограда вдоль внешнего радиуса, цветущие деревья и строения на заднем плане.
4. `skidpad.png` — общий ракурс с камеры по умолчанию.

## Наблюдения и результаты

- Дорожное полотно и ландшафт трека `skidpad` (385 мешей LOD0, 6848 полигонов) рендерятся корректно, со 100% сопоставлением материалов и текстур (98 текстур FSH, 107 материалов CRP).
- Динамические библиотечные пропы (статьи с флагом `Base & 0x8000 != 0`), спавнящиеся сценарием `.scn` на контрольных точках, отфильтрованы из статической сцены трека.
- Регрессия отсутствует: все 44 автомобиля из итерации `001-car-viewer` успешно валидируются и загружаются (`verify_all_cars.py`: 44/44 passed).
- Добавлена поддержка 16-битных форматов пикселей FSH `0x7e` (RGB 565) и `0x78` (ARGB 1555), благодаря чему все 15 трасс игры успешно парсятся и загружаются через CLI `inspect`.
