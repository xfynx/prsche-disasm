# План восстановления Porsche Unleashed

Обновлено 2026-09-26. Активна **012-campaign-fidelity** из завершённой 011.
Снимки 001–011 заморожены; замечания пользователя исправляются только в 012.

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
5. **T05 — устранение дефектов кампаний и аутентичность интерфейса:** аутентичный брифинг, устранение ошибки покупки авто, загрузка настоящих 3D-моделей Porsche в миссиях, исправление трассы Canyon.
6. **T06 — интеграция и приёмка:** 142 теста Rust passed, Clippy/Rustfmt чисты, Playwright E2E 12/12 checks 0 errors, сборка release native и WASM.

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

## Сейчас: 012-campaign-fidelity

Приоритет пользователя от 2026-09-25: исправить несоответствие интерфейса и заданий,
неверный старт Factory Driver, подлёты автомобилей и тормоз/задний ход на S.
Рабочий план: [PLAN 012](iterations/012-campaign-fidelity/PLAN.md).
T01 — экраны карьер; T02 — сценарий/старт миссий; T03 — контакты и ввод; T04 — приёмка.
Без Computer Use выполнены SCN-цели 0M01 вместо ложного завершения по кругу,
регрессия контактов/торможения, извлечение UI и сборки Windows/WASM. 151 Rust-тест и
14 браузерных проверок прошли. Визуальная приёмка открыта: камера 0M01 перекрыта геометрией,
UI 1:1 и правила оригинала требуют сверки; runtime SIM ещё подменяются таблицами.
Checkpoint 2026-09-26: все задачи остаются открытыми и частично выполненными; подробности,
ограничения и точные команды продолжения — в [PLAN 012](iterations/012-campaign-fidelity/PLAN.md)
и [Run 001](iterations/012-campaign-fidelity/runs/001-fidelity-repair/README.md).
Звук/кокпит отложены до этих исправлений: [план](docs/planned-audio-cockpit.md).

## Постоянные правила

- `local/game` только читается; изменяющие оригинал эксперименты — в `local/experiments`.
  Ресурсы не копировать в снимки или Git.
- Новый снимок — через `scripts/new-iteration.py`, без прежних runs и кэшей.
- Перед работой сверять STATUS, активный PLAN и runs с Git и диском.
