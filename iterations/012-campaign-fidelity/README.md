# 012-campaign-fidelity

Промежуточный checkpoint: [что работает, ограничения и запуск](runs/007-publish-checkpoint/README.md).

В работе. Создана из 011 без прежних runs. Исправления соответствия карьер оригиналу,
старта Factory Driver, подвески и торможения/заднего хода. [Рабочий план](PLAN.md),
[checkpoint run 001](runs/001-fidelity-repair/README.md).

[Run 006](runs/006-mission-playthrough/README.md): восстановлена опора всей
площадки Skidpad по исходным секторам mt53/mt54. 169 Rust-тестов passed,
Windows/WASM собраны. Полный клавиатурный заезд доходит до 4/6 точек без
падения, но теряет разворот и получает тайм-аут; прохождение ещё открыто.
Последующая диагностика подтвердила переворот: исправлены стабилизатор и лучи
подвески, 172 Rust-теста passed. Заезд всё ещё не пройден; следующий шаг —
неподтверждённая трактовка полей SIM как колеи и источник геометрии колёс в EXE.

Продолжение: [Run 002 — SIM и Quick Race](runs/002-runtime-sim/README.md).
В главном меню Quick Race позволяет выбрать трассу/автомобиль, 1/3/5 кругов и
0/3 соперника; на спринте один заезд. Гараж, деньги и карьерные награды не меняются.
Карьерные заезды и Quick Race загружают оригинальный SIM после модели; отсутствие
или повреждение SIM блокирует старт. Каталог доступных вариантов пока неполный.

```powershell
./scripts/build.ps1 -Iteration 012-campaign-fidelity -Config release -Target all
./scripts/extract-fe-ui.ps1
./scripts/launch-viewer.ps1 -Iteration 012-campaign-fidelity -Mode desktop
```

Снимки 001–011 и local/game неизменны. [Run 005](runs/005-trigger-contract/README.md):
169 Rust-тестов passed, 3 GPU ignored; Chromium 21 checks passed, 0 JS errors/known failures.
Контрольные точки используют восстановленную проверку диагоналей корпуса и условий SCN;
адаптер размеров/позы ещё требует сравнения с оригинальным bounds/contact path.
Исправлен тормозной импульс колёс (8/8 повторов R→вперёд), применён масштаб SCN v4.
Windows/WASM release собраны. Стартовая камера 0M01 больше не закрыта стрелкой L A:
подключены animdefs triggerable и выбор по ссылкам SCN при reset/прохождении триггеров.
Проверены Start→Arrow 1, первый waypoint→Arrow 2 и повтор. Визуальная приёмка оригинала
остаётся открытой: UI ещё не 1:1, правила, spawn и камера требуют дальнейшей проверки.
