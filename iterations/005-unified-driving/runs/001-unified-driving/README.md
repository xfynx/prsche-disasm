# Run 001 — общая среда и поверхность трассы

2026-09-23. Снимок 005 завершён и принят: интерактивная проверка
native-окна и desktop-лаунчера выполнена и подтверждена пользователем. `local/game` только читался.

## Результаты

- `test.log`: 72 passed (32 assets, 21 formats, 19 viewer), 3 GPU tests ignored.
- `clippy.log`: workspace/all-targets `-D warnings` passed; fmt check passed.
- `build.log`: release native и WASM, общий Rust код. Cargo/MSVC предупреждает
  о совпадении имени PDB lib/bin; сборка успешна, это не предупреждение Clippy.
- `cars.tsv`: 44/44 оригинальные модели загружаются.
- `surface-audit.log`: 15/15 трасс, 109707 принятых треугольников, все центроиды
  опрошены, omitted=0, худшая ошибка высоты 0.000164 м. Проверка внутренней
  согласованности геометрии не доказывает соответствие коллизиям EXE.
- `browser-check.json`: Playwright 1.57, Chromium 143, обычное окно с аппаратным
  WebGPU. Начальная загрузка skidpad, газ+руль (63 км/ч в сценарии), Esc/H,
  alps/356a, диагностика, потеря фокуса (17→14 км/ч), ошибок страницы 0.
- `web-menu.png`, `web-drive.png`, `web-hidden-hud.png`, `web-alps.png`,
  `web-car.png`: осмотрены. Меню скрывается, HUD не перекрывает центр дороги,
  модель и окружение загрузились. Меню осознанно перекрывает часть орбитальной
  сцены; Esc освобождает весь viewport.
- `native-skidpad.png`, `native-356a.png`: offscreen Vulkan осмотрены;
  трасса/окружение и автомобиль без новой явной геометрической регрессии.

## Воспроизведение

Команды сборки/tests/clippy/audit/corpus — в [PLAN](../../PLAN.md).
Web-тест сам запускает и останавливает принадлежащий ему loopback-сервер:

```powershell
& 'C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/node.exe' iterations/005-unified-driving/web/verify-browser.cjs C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/package auto iterations/005-unified-driving/runs/001-unified-driving
local/builds/005-unified-driving/windows/porsche-viewer.exe view --game-dir local/game --track skidpad --screenshot iterations/005-unified-driving/runs/001-unified-driving/native-skidpad.png
local/builds/005-unified-driving/windows/porsche-viewer.exe view --game-dir local/game --car 356a --screenshot iterations/005-unified-driving/runs/001-unified-driving/native-356a.png
```

Пути runtime зависят от машины; новые зависимости не устанавливались.
Computer Use недоступен (native pipe missing), подключённых Browser Use нет.
По предложению пользователя проверено через Playwright. Headless-shell не дал
WebGPU adapter; обычный Chromium отработал. Ошибка favicon 404 первого GUI-прогона
устранена data favicon, финальный browser-check.json успешен. Предыдущие
диагностические browser-failure.json/web-failure.png сохраняют историю попытки.

## Ограничения

Нет приёмки Linux/macOS. Интерактивная работа native-окна и desktop-лаунчера
проверена и подтверждена пользователем в Windows.
Сцена в WebGPU темнее offscreen Vulkan: различие уже видно на 356a и требует
отдельной проверки color-space/presentation; полного визуального паритета не заявляем.
Коллизии остаются прототипом: нет геометрических контактов с пропами/стенами,
классификации покрытий по оригинальному коду, динамики падения/подвески.
