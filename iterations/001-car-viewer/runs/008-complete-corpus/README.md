# Run 008: единый уровень и полный набор моделей

Дата: 2026-09-18. Проверяются все 44 модели с двух сторон.

Исправлены последовательные каналы `pr` (`IndexRowRef=0xffff`), включая
полностью неиндексированную геометрию. Для всей сцены выбран единый уровень
из Base: гоночные Tread LOD4/5 не подмешиваются к frontend LOD1.
Исправлены alpha-cutout колёс трафика и пограничные FSH-тайлы.

```powershell
. ./scripts/build.ps1 -Iteration 001-car-viewer -Config release -Target all
./scripts/validate-cars.ps1 -Capture -Width 960 -Height 600 `
  -Report iterations/001-car-viewer/runs/008-complete-corpus/front.tsv `
  -CaptureDir iterations/001-car-viewer/runs/008-complete-corpus/front
./scripts/validate-cars.ps1 -Capture -Width 960 -Height 600 -Yaw -2.4 -Pitch 0.2 `
  -Report iterations/001-car-viewer/runs/008-complete-corpus/rear.tsv `
  -CaptureDir iterations/001-car-viewer/runs/008-complete-corpus/rear
```

Передний ракурс: yaw=0.75, pitch=0.27. Задний: yaw=-2.4, pitch=0.2.
Светлые крестовидные полосы на диске 356 — содержимое оригинальной текстуры
TPG page4, а не дефект сборки; проверено выгрузкой атласа.
