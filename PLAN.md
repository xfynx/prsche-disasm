# План восстановления Porsche Unleashed

Обновлено 2026-09-24. **011-factory-driver завершена** (тег `iteration-011`).
Следующий этап: **012-audio-cockpit**. Снимки 001–011 заморожены.

## Цель

Полный перенос на Windows, Linux, macOS и web: Evolution, Factory Driver,
остальные режимы, правила событий, экономика, профили/сохранения, интерфейс и звук.
Крупные этапы: [docs/roadmap.md](docs/roadmap.md).
Просмотрщик и аркадная машина — вспомогательные инструменты.

## Завершено: 011-factory-driver

Рабочий план: [iterations/011-factory-driver/PLAN.md](iterations/011-factory-driver/PLAN.md).
Результаты: [STATUS.md](STATUS.md). Отчёты: [Run 001](iterations/011-factory-driver/runs/001-factory-driver/README.md).

1. **T01 — реверс Factory Driver:** спецификация 34 миссий `nfs5.fac` и языковой базы `festrings.csv`.
2. **T02 — движок испытаний и трюков:** детекторы `StuntDetector` (180° slide, 360° spin, reverse J-turn, слаломные штрафы, контроль повреждений кузова).
3. **T03 — карьерные ранги и наградные авто:** от Applicant до Master Ace Driver, бонусные авто ('78 911 Turbo 3.3, '73 Carrera RS 2.7, '99 911 GT3 Factory Edition).
4. **T04 — веб-интерфейс лестницы миссий:** модальное окно `#factoryMissionsModal`, фильтры Tier 1–3, реплики Рольфа, статусы и лучшие времена.
5. **T05 — интеграция и приёмка:** 142 теста Rust passed, Clippy/Rustfmt чисты, Playwright E2E 0 errors, сборка release native и WASM.

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
- [011-factory-driver](iterations/011-factory-driver/README.md): режим Factory Driver (34 миссии, трюки, ранги).

История проверок — в STATUS.md и runs снимков. Позднее найденные дефекты
исправляются в новом снимке, не переписывая историю.

## Следующий этап: 012-audio-cockpit

Полная реализация аудиодвижка и 3D-кокпита:
- Парсинг оригинальных банков звуков двигателей и эффектов из `GameData/Audio` и `Sound/`.
- Модель интерполяции тона и громкости по оборотам RPM симулятора.
- 3D геометрия интерьера с анимированным рулевым колесом и стрелками тахометра/спидометра.
- Подробная постановка: [docs/next-iteration.md](docs/next-iteration.md).

## Постоянные правила

- `local/game` только читается; изменяющие оригинал эксперименты — в `local/experiments`.
  Ресурсы не копировать в снимки или Git.
- Новый снимок — через `scripts/new-iteration.py`, без прежних runs и кэшей.
- Перед работой сверять STATUS, активный PLAN и runs с Git и диском.
