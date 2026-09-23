# План восстановления Porsche Unleashed

Обновлено 2026-09-24. **010-evolution-career завершена** (тег `iteration-010`).
Следующий этап: **011-factory-driver**. Снимки 001–010 заморожены.

## Цель

Полный перенос на Windows, Linux, macOS и web: Evolution, Factory Driver,
остальные режимы, правила событий, экономика, профили/сохранения, интерфейс и звук.
Крупные этапы: [docs/roadmap.md](docs/roadmap.md).
Просмотрщик и аркадная машина — вспомогательные инструменты.

## Завершено: 010-evolution-career

Рабочий план: [iterations/010-evolution-career/PLAN.md](iterations/010-evolution-career/PLAN.md).
Результаты: [STATUS.md](STATUS.md). Отчёты: [Run 001](iterations/010-evolution-career/runs/001-evolution-career/README.md).

1. **T01 — реверс Evolution:** спецификация 35 кубков `nfs5.trn` и 683 деталей `nfs5.prt`.
2. **T02 — турнирный движок:** зачётная система (10-6-4-3-2-1), прогрессия этапов, призовой фонд.
3. **T03 — авторынок:** автосалон новых авто и рынок Б/У с учётом пробега и формулы остаточной стоимости.
4. **T04 — магазин запчастей и ремонт:** тюнинг узлов, расчёт износа и ремонт.
5. **T05 — физический аудит всех 15 трасс:** 0 туннелирований на скоростях до 252 км/ч, проверка полотна.
6. **T06 — интеграция и приёмка:** 138 тестов Rust, clippy/fmt чисты, Playwright E2E 0 errors, нативная и веб-сборки. Документированы скрипты в `docs/scripts.md`.

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
- [010-evolution-career](iterations/010-evolution-career/README.md): режим Evolution, экономика, тюнинг, 15-track аудит.

История проверок — в STATUS.md и runs снимков. Позднее найденные дефекты
исправляются в новом снимке, не переписывая историю.

## Следующий этап: 011-factory-driver

Полная реализация режима **Factory Driver (Заводской водитель)**:
- 34 миссии из `nfs5.fac` с полной цепочкой испытаний (слалом, развороты 180°/360°, J-turn, доставка, дуэли).
- Детекторы трюков: разворот на 180 градусов, разворот на 360 градусов, сбитые конусы/штрафы, движение задним ходом.
- Карьерный рост заводского пилота (ранги от Испытателя до Шеф-пилота Porsche) и призовые автомобили в гараж.
- Голосовые и текстовые реплики старшего инструктора (Рольфа).
- Магазин запчастей и ремонт: реверс структур запчастей и модификаторов ТТХ автомобиля.
- Подробная постановка: [docs/next-iteration.md](docs/next-iteration.md).

## Постоянные правила

- `local/game` только читается; изменяющие оригинал эксперименты — в `local/experiments`.
  Ресурсы не копировать в снимки или Git.
- Новый снимок — через `scripts/new-iteration.py`, без прежних runs и кэшей.
- Перед работой сверять STATUS, активный PLAN и runs с Git и диском.
