# 001-car-viewer: итоговый план

Закрыта 2026-09-19 по приёмке пользователя. Тег: iteration-001.
Дальнейшие изменения — только в следующем самостоятельном снимке.

## Цель и критерии

Все 44 CRP/TPG из read-only local/game: целые кузова, колёса, фары, текстуры.
Полный inspect, GPU-снимки с двух сторон и осмотр, workspace check/test,
native/WASM build, интерактивный smoke native и браузера. Тестовая окраска
не меняет фары/хром; полная CLR-палитра пока не реализована. Без новых хоткеев.

## Подтверждено / выполнено

- Масштаб /5 один раз, перенос tr нужен, Z отражается один раз.
- После Z не переставлять CW-индексы: устранено отсечение кузова.
- Строки материала заканчиваются первым NUL.
- pr.IndexRowRef=0xffff — последовательный канал; остальные выбирают строку
  индексов, Offset/stride добавляется. nd=0 допустим.
- Единый уровень сцены: минимальный ненулевой из Base, fallback части на 0;
  гоночные Tread4/5 не добавляются к frontend1.
- TPG style1 задаёт geometry/type и texture/type раздельно, default type0.
- FSH-тайлы обрезаются по границе; 0xfff/0xffff -> -1 — вывод по данным,
  не подтверждённый реверсом runtime.
- Run008: 44/44 загрузки, 88 снимков осмотрены; отсутствовали колёса 928/944/cop993
  и части f901. Run009: style-selection исправляет их, 88 снимков осмотрены.
- 30 workspace-тестов и три явных GPU-теста проходят, native/WASM собраны.
- Светлые полосы на дисках 356 есть в исходной текстуре.
- Web import исправлен на package/viewer_impl.js; HTTP200 не доказывает графику.

## Итог и ограничения

- Выполнены маска краски, интеграция и визуальные проверки, документация.
  Alpha255 сохраняет фары/хром, промежуточный alpha окрашивается; полная CLR-семантика не доказана.
- Агент formats завершён (лимит). Его selection и ray audit приняты;
  незавершённый вывод metadata подключён и проверен координатором.
- Light1/Body имеют одинаковую глубину; mt+0x114 содержит signed -3/0.
  Это поле теперь задаёт depth bias. GPU-регрессия проходит, фары видны.
  Runtime-семантика единиц bias ещё не подтверждена дизассемблированием.
- Run010 завершён: 44/44, 88 front/rear снимков осмотрены. Пропавшие фары
  исправлены, новых явных дефектов на этих ракурсах не обнаружено.
- 356a/356b/928 red-снимки подтверждают сохранение цвета ламп/хрома.
- Check/test/fmt, release native/WASM и Python snapshot-тест пройдены.
- 2026-09-19 пользователь подтвердил браузер и разрешил закрытие/коммит.
- Отдельный native UI smoke не подтверждён; native проверен offscreen Vulkan.
  Закрытие принято с этим ограничением, без утверждения о пройденном native UI.
- Повторные fmt, 30 unit и 3 GPU tests проходят. Активных задач/субагентов нет.

## Следующий шаг

Следующий этап — 002-track-viewer: read-only инвентаризация трасс, выбор участка,
самостоятельный снимок из 001, парсер/Scene и native/WASM-проверки.
План: docs/next-iteration.md в корне проекта. Реализация ещё не начата.
CLR/все стили/повреждения/анимации остаются вне подтверждённого результата.

## Команды

```powershell
. ./scripts/tool-env.ps1
cargo test --manifest-path iterations/001-car-viewer/Cargo.toml --target-dir local/builds/001-car-viewer/.cargo-target --locked --workspace
cargo test --manifest-path iterations/001-car-viewer/Cargo.toml --target-dir local/builds/001-car-viewer/.cargo-target -p porsche-viewer gpu_diagnostics -- --ignored
. ./scripts/build.ps1 -Iteration 001-car-viewer -Config release -Target all
./local/builds/001-car-viewer/windows/porsche-viewer.exe view --game-dir local/game --car 356b
py -3 scripts/serve-web.py --iteration 001-car-viewer --port 8000
py -3 scripts/test_iterations.py
```

Историю runs не перезаписывать: 006 winding, 007 ошибки корпуса,
008 последовательные pr/LOD, 009 style/paint, 010 material depth (92 снимка).
Команды пакетной проверки сохранены в run010/README.md; новый опыт делать в run011.
