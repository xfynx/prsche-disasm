# Run 007: проверка полного набора моделей

Дата: 2026-09-18. Продолжение run006 после восстановления компиляции.
Цель: загрузка и визуальная проверка всех 44 моделей, исправление атласов,
прозрачности и колёс. Исходные данные только из общей папки `local/game`.

```powershell
. ./scripts/build.ps1 -Iteration 001-car-viewer -Config release -Target all
./scripts/validate-cars.ps1 -Capture -Width 960 -Height 600 `
  -Report iterations/001-car-viewer/runs/007-corpus-validation/cars.tsv `
  -CaptureDir iterations/001-car-viewer/runs/007-corpus-validation/front
./scripts/contact-sheet.ps1 `
  -InputDir iterations/001-car-viewer/runs/007-corpus-validation/front `
  -OutputDir local/builds/001-car-viewer/validation/overview-007
```

Камера: yaw=0.75, pitch=0.27. Результат прогона будет записан после проверки.
