# Run 009: согласованный style1 и маска краски

2026-09-18. Продолжение run008: все 44 модели там загружались, но отсутствовали
колёса 928/944/cop993 и части f901. Причина — безусловный type0 вместо TPG style1.
Геометрические и текстурные группы выбираются раздельно по одному стилю.

Внешняя текстура использует alpha как разметку окраски: 255 у фар/хрома,
промежуточные значения у кузова. Тестовый цвет не должен менять alpha255.
Это ещё не полная реализация CLR-палитры оригинальной игры.

Результат debug-прогона: 44/44 inspect/capture, 88 снимков front/rear осмотрены.
Колёса 928/944/cop993 и оформление f901 восстановлены. Остался дефект:
356b/cop356/cop356_german — кузов скрывает основные фары. Изолированный Light1
виден; вместе с Body пропадает. Culling off не помог (356b-no-cull.png).
Итерация этим запуском не закрывается. Ресурсы local/game не меняются.

356a-red.png подтверждает окраску кузова без окраски фар/хрома. Отдельный
`paint_mask_gpu` тест проверяет реальные пиксели шейдера (лампа alpha255 не
меняется, кузов alpha204 меняется и остаётся непрозрачным, alpha0 вырезается).
`356b-red/white.png` сняты до exterior Mask; `356b-mask-red.png` после Mask;
`front`/`rear` — после согласованного style-selection.

```powershell
. ./scripts/build.ps1 -Iteration 001-car-viewer -Config release -Target all
./local/builds/001-car-viewer/windows/porsche-viewer.exe view --game-dir local/game --car 356b --screenshot iterations/001-car-viewer/runs/009-style-paint/356b-red.png --paint-index 1 --width 960 --height 600
./scripts/validate-cars.ps1 -Capture -Width 960 -Height 600 -Report iterations/001-car-viewer/runs/009-style-paint/front.tsv -CaptureDir iterations/001-car-viewer/runs/009-style-paint/front
./scripts/validate-cars.ps1 -Capture -Width 960 -Height 600 -Yaw -2.4 -Pitch 0.2 -Report iterations/001-car-viewer/runs/009-style-paint/rear.tsv -CaptureDir iterations/001-car-viewer/runs/009-style-paint/rear
```
