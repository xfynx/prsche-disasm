# Run 006: Base, geometry levels and materials

Дата: 2026-09-17. Проверка сборки всех моделей из `local/game/GameData/CarModel`.

Исходное состояние: запуски 003–005 показывают разнесённые панели и отсутствующие
поверхности кузова. Исправления и результаты этого запуска записываются ниже
после проверки сборки.

Native-снимки создаются реальным wgpu/Vulkan-рендерером в offscreen-режиме:

```powershell
. ./scripts/build.ps1 -Iteration 001-car-viewer -Config release -Target all
./local/builds/001-car-viewer/windows/porsche-viewer.exe view `
  --game-dir ./local/game --car 356b `
  --screenshot ./iterations/001-car-viewer/runs/006-base-assembly/356b.png `
  --width 1280 --height 720
```

Камера по умолчанию: yaw=0.75, pitch=0.27 радиана. Другие ракурсы задаются
`--yaw` и `--pitch`.
