# План восстановления Porsche Unleashed

Обновлено 2026-09-24. **009-game-shell завершена** (тег `iteration-009`).
Следующий этап: **010-evolution-career**. Снимки 001–009 заморожены.

## Цель

Полный перенос на Windows, Linux, macOS и web: Evolution, Factory Driver,
остальные режимы, правила событий, экономика, профили/сохранения, интерфейс и звук.
Крупные этапы: [docs/roadmap.md](docs/roadmap.md).
Просмотрщик и аркадная машина — вспомогательные инструменты.

## Завершено: 009-game-shell

Рабочий план: [iterations/009-game-shell/PLAN.md](iterations/009-game-shell/PLAN.md).
Результаты: [STATUS.md](STATUS.md). Отчёты: [Run 001](iterations/009-game-shell/runs/001-controls-regression/README.md), [Run 002](iterations/009-game-shell/runs/002-game-shell/README.md).

1. **T00 — регресс управления:** устранена инверсия руля 6 DOF, подтверждено сохранение правильных знаков на синтетических и реальных трассах.
2. **T01 — общая модель экранов:** крейт `nfs-game`, автомат экранов `Screen`, идемпотентная обработка результатов.
3. **T02 — профиль и сохранения:** `PlayerProfile` (11 000 CR, гараж, ранги), атомарное сохранение `.tmp` -> rename, `localStorage` и JSON импорт/экспорт.
4. **T03 — правила событий:** исследование `nfs5.trn` и `nfs5.fac`, парсеры турниров и миссий в `nfs-formats`, отчёт [`research/first-events-evidence.md`](iterations/009-game-shell/research/first-events-evidence.md).
5. **T04 — первые сквозные события карьер:** Evolution 356 Challenge (Canyon, Monaco 1; 4 500 CR) и Factory Driver 0M01 (Skidpad, Boxster, 32.0 с).
6. **T05 — базовый звук и приёмка:** синтезатор WebAudio (RPM двигателя, визг шин, сигналы), WinMM beeper для native, модалы брифинга и результатов. Все 129 тестов Rust и 10 тестов Chromium WebGPU пройдены.

## Завершённые снимки

- [001-car-viewer](iterations/001-car-viewer/README.md): модели автомобилей.
- [002-track-viewer](iterations/002-track-viewer/README.md): геометрия трасс.
- [003-track-environment](iterations/003-track-environment/README.md): окружение.
- [004-track-topology](iterations/004-track-topology/README.md): топология, прототип заезда.
- [005-unified-driving](iterations/005-unified-driving/README.md): общий запуск, поверхность.
- [006-game-systems](iterations/006-game-systems/README.md): форматы игровых систем.
- [007-physics-simulation](iterations/007-physics-simulation/README.md): симуляция автомобиля.
- [008-race-loop](iterations/008-race-loop/README.md): цикл гонки и соперники.
- [009-game-shell](iterations/009-game-shell/README.md): оболочка, профили, первые события карьер, звук.

История проверок — в STATUS.md и runs снимков. Позднее найденные дефекты
исправляются в новом снимке, не переписывая историю.

## Следующий этап: 010-evolution-career

Полная реализация режима Evolution (эпоха Classic):
- Все турниры и кубки эры Classic из `nfs5.trn`.
- Древо прогрессии эпох (Classic -> Golden -> Modern).
- Рынок подержанных и новых авто: покупка, продажа, износ деталей.
- Магазин запчастей и ремонт: реверс структур запчастей и модификаторов ТТХ автомобиля.
- Подробная постановка: [docs/next-iteration.md](docs/next-iteration.md).

## Постоянные правила

- `local/game` только читается; изменяющие оригинал эксперименты — в `local/experiments`.
  Ресурсы не копировать в снимки или Git.
- Новый снимок — через `scripts/new-iteration.py`, без прежних runs и кэшей.
- Перед работой сверять STATUS, активный PLAN и runs с Git и диском.
