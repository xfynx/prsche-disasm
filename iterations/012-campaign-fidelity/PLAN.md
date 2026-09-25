# 012-campaign-fidelity: рабочий план

Начата 2026-09-25 из 011; checkpoint 2026-09-26. В работе, тега нет.
001–011 заморожены; local/game только чтение. Назначений агентам сейчас нет.
Цель: устранить расхождения экранов карьер, миссий/старта и физики с оригиналом.
Постановка: [docs/next-iteration.md](../../docs/next-iteration.md).

## Задачи и готовность

- [ ] T01 — UI один-в-один: переход Evolution к выбору кубка исправлен, Factory-изображения
  исключены из Evolution, briefing частично следует LAY 640x480. Не готовы оригинальные
  комнаты, шрифты, слои, привязки контролов и переходы. Нужны кадры оригинала и сравнение.
- [ ] T02 — миссии: 0M01 использует SCN Start и MESH04 support, последовательность waypoint
  1–5 → End и тайм-аут. LSP не завершает Factory; неподдержанные цели не получают награду.
  Это реконструкция, а не доказанные правила EXE. Не доказаны offset старта, направление/
  ширина триггеров как условия победы, конусы/штрафы. На кадре камера перекрыта геометрией.
- [ ] T03 — физика/ввод: исправлены первый контакт/повторный контакт, фантомный пол,
  плечи осей, S тормоз→стоп→назад и W обратно. CPU и браузерная регрессия прошли.
  Оригинальное поведение не подтверждено; runtime пока создаёт параметры по таблицам.
- [ ] T04 — приёмка: 151 Rust-тест passed, 3 GPU ignored, fmt/Clippy/UI чисты;
  release Windows/WASM собраны, 14 автоматических browser checks без ошибок.
  Осмотр кадра обнаружил перекрытие камеры: визуальная приёмка и реальное прохождение открыты.

## Факты и границы доказательства

Старый демпфер использовал compression/dt при новом контакте, RoadSurface miss превращался
в пол y=0. Для заявленного заднего распределения веса плечи осей были переставлены.
Калибровка ранее принимала почти вертикальную машину при 52 км/ч за остановившуюся;
теперь проверяет горизонтальную скорость, высоту, наклон и контакт каждого шага торможения.
На реальных SIM: 356 — 54.7 м / 3.92 с, Boxster — 43.3 м / 3.08 с со 100 км/ч.
Тест ищет ресурсы от CARGO_MANIFEST_DIR, не от случайного cwd; fallback отмечается явно.

SCN Start — центр триггера, не доказанная стартовая позиция автомобиля. Порядок/ширина зон
и движение вперёд по центрам — рабочая гипотеза. Подробности в research/mission-fidelity.md.
`renderer.rs::configure_sim_for_model` ещё использует таблицы и искусственную кривую момента;
визуальная модель машины не доказывает использование соответствующего оригинального SIM.

119 UI PNG воспроизводятся scripts/extract-fe-ui.ps1 в local/derived/fe-ui и отдаются
сервером read-only по /assets/. Ресурсы не входят в снимок/Git. Повторные FSH ID выбираются
по прежнему правилу последнего элемента; оригинальная семантика слоёв ещё не установлена.

## Проверки из корня

```powershell
. ./scripts/tool-env.ps1
cargo test --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target --workspace
cargo fmt --manifest-path iterations/012-campaign-fidelity/Cargo.toml --all -- --check
cargo clippy --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target --workspace --all-targets -- -D warnings
node iterations/012-campaign-fidelity/web/ui.test.mjs
./scripts/extract-fe-ui.ps1
./scripts/build.ps1 -Iteration 012-campaign-fidelity -Config release -Target all
node iterations/012-campaign-fidelity/web/verify-browser.cjs C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/package auto iterations/012-campaign-fidelity/runs/001-fidelity-repair
```

Логи, снимки и ограничения: [Run 001](runs/001-fidelity-repair/README.md).
При необходимости node доступен по C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/node.exe.

## Ближайшие шаги

1. После перезапуска проверить Computer Use по docs/computer-use-recovery.md. Снять оригинальные
   GameSetup/Factory/Evolution/briefing/map и старт 0M01; сравнить положение авто/камеры и цели.
2. Установить источник геометрии, закрывающей камеру 0M01, и правильный staging offset/камеру.
   Не скрывать объекты и не выбирать произвольный offset вместо доказанного исправления.
3. Подключить реальные карьерные car_sim к parser/runtime; регрессия на 356/Boxster + held S/W.
4. Восстановить оригинальные комнаты, шрифты и UI-переходы, сверить 1:1. Доказать правила 0M01
   по EXE/оригиналу и пройти её реальным вводом; затем расширять покрытие остальных миссий.
5. Повторять затронутые проверки по изменениям. 012 не закрывать по успешной сборке или тестам.
