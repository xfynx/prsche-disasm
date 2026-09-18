# Run 010: смещение глубины из материала

2026-09-18. Проверка всех 44 моделей после run009 и исправления фар 356b.

Численная диагностика 356b: луч от камеры к Light1 пересекает Body и Light1
при одинаковом t=0.919246852. Body использует mt4, Light1 — mt12. Материалы
различаются только mt+0x114 (signed 0 против -3) и +0x134 (0 против 2).
У pr TransInfo: 0 против 0x200. Каналы обоих pr имеют одинаковые Level/RMOffs.

Loader читает signed mt+0x114; renderer использует его как constant depth bias,
без смещения вершин и фильтрации по именам. В корпусе встречаются значения
{-10,-3,-2,-1,0,1,3,5}. Их точное соответствие оригинальному raster runtime ещё
не подтверждено дизассемблированием; устранение перекрытия проверяется GPU.
Сортировка по номеру материала была контрольным опытом, в рабочем renderer
не используется: глубину задаёт исходное поле материала.

`paint_mask_gpu` и `coplanar_material_bias_gpu` проверяют пиксели synthetic scene;
`headlight_layers` проверяет реальные части 356b. Все три GPU-теста проходят.

```powershell
. ./scripts/tool-env.ps1
. ./scripts/build.ps1 -Iteration 001-car-viewer -Config release -Target all
./scripts/validate-cars.ps1 -Capture -Width 960 -Height 600 -Report iterations/001-car-viewer/runs/010-material-depth/front.tsv -CaptureDir iterations/001-car-viewer/runs/010-material-depth/front
./scripts/validate-cars.ps1 -Capture -Width 960 -Height 600 -Yaw -2.4 -Pitch 0.2 -Report iterations/001-car-viewer/runs/010-material-depth/rear.tsv -CaptureDir iterations/001-car-viewer/runs/010-material-depth/rear
cargo test --manifest-path iterations/001-car-viewer/Cargo.toml --target-dir local/builds/001-car-viewer/.cargo-target -p porsche-viewer gpu_diagnostics -- --ignored
```

## Результат

- Release: 44/44 загрузки; 44 front + 44 rear, оба TSV без отказов.
- Все 88 снимков осмотрены через 10 contact sheets. Ранее пропавшие фары
  356b/cop356/cop356_german видны; кузова и колёса собраны, новых явных дефектов
  на этих ракурсах не обнаружено. Это не проверка всех стилей/LOD/повреждений.
- Дополнительные 356a-red, 356b-red, 928-red, cop356-red: лампы и хром не
  окрашиваются вместе с кузовом; запечённое оформление police сохраняется.
- Workspace check/test/fmt проходят: 30 обычных тестов; три GPU-теста отдельно.
- Native release и WASM собраны. Python test_iterations.py: 1/1.
- Интерактивные native/WebGPU smoke остаются открытыми: CUA вернул apps=[] /
  browsers=[]. Наличие WASM и HTTP200 не является графической проверкой.

Порядок ручной проверки: загрузить 356b, вращать, приблизить/отдалить, нажать C
и R, изменить размер окна. В web дополнительно загрузить 928 после 356b
и проверить переключение модели без перезагрузки страницы.
Сайт запущен на http://127.0.0.1:8000/; HTML/JS/WASM отвечают HTTP200.

## Приёмка 2026-09-19

Пользователь подтвердил «браузер ок, работает» и разрешил завершить этап/коммитить.
Браузерный запуск принят по ручной проверке пользователя. Подробный протокол
каждого действия не предоставлен; отдельный native UI smoke не подтверждён.
Native offscreen проверен ранее. Повторные fmt, 30 unit и 3 GPU tests проходят.
Итерация закрыта с этими явно записанными ограничениями; тег `iteration-001`.
