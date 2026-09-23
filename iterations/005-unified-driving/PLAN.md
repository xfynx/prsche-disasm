# 005-unified-driving: рабочий план

Начата 2026-09-23 из завершённой `004-track-topology`. `local/game` только читается.
Собственная история runs начинается с 001. Статус: завершена, тег `iteration-005`.

## Цель и критерии готовности

Общий удобный запуск desktop/web, спокойное управление прототипом и проверяемая
основа дальнейшего реверса оригинальной игры для современных ОС и браузера.

- Одинаковый каталог, заезд и скрываемый UI в web и дополнительном desktop app
  (общее WASM-приложение в окне браузера). Native Rust CLI остаётся самостоятельным;
  получает запуск без аргументов и переключение ресурсов внутри окна.
- Меню скрывается при заезде, возвращается клавишей/кнопкой; HUD можно выключить.
  Диагностика не занимает постоянную часть экрана. Потеря фокуса сбрасывает ввод.
- Общая Rust-модель управления сглаживает руль и педали. Тесты проверяют
  переходные процессы и сопоставимость траектории при разных шагах времени.
- По уточнению пользователя: демо-машинку только исправляем. Главная работа
  этапа — индекс дорожных треугольников CRP, запрос высоты/нормали с учётом
  текущего уровня дороги, синтетическая и реальная проверка геометрии.
- fmt, clippy, workspace tests, native/WASM release; загрузка 44 авто и 15 трасс.
- Визуальная проверка меню, заезда, скрытия/возврата UI и смены ресурса;
  отдельная фиксация возможностей проверки native окна.
- Факты о форматах отделены от гипотез, план следующего реверса опирается на
  SHA-256 бинарника, RVA и воспроизводимые исследовательские артефакты.

## Подтверждённое и гипотезы

Подтверждено кодом 004: native/web используют общий Renderer и ArcadeCar;
каталог и HUD реализованы отдельно в HTML/JS, native требует CLI-аргументы.
Прототип заезда использует процедурную машину: выбор модели для просмотра
не меняет автомобиль в заезде. Значения ускорения/сцепления не восстановлены из EXE.

Предыдущий план 005 преждевременно назначал коэффициенты сцепления по `.edg`
и считал `.jnc` контрольными точками круга. Чтение структур не доказывает эту
семантику. Поверхности, подвеска, следы и таймер перенесены за исследование
потребителей данных и измерение оригинала. Геометрический spatial grid входит
в 005, с явной оговоркой о выборе кандидатов по RD* и сохранением provenance.

## Выполненные задачи и исполнители

- T01: координатор — web UI, планы, интеграция и визуальная приёмка.
- T02: driving / GPT-5.6 Terra high — только `arcade.rs`, плавность и тесты.
- T03: desktop / профиль renderer GPT-5.5 high — `native.rs`, каталог и ввод.
- T04: launcher / профиль builds GPT-5.6 Luna medium — scripts запуска/сборки.
- T05: координатор — аудит доказательств реверса, воспроизводимый следующий шаг.
- T06: surface / профиль formats GPT-5.6 Terra high — nfs-assets surface.rs,
  lib.rs, track_loader.rs: индекс, запрос опоры, тесты и audit example.

Уточнение пользователя: максимум прототипа 240 км/ч; в T02 добавлены проверки
коллизий с кромками на другом уровне и проскока кромки на высокой скорости.
Полный реверс столкновений остаётся в 007–008 дорожной карты.

T01–T06 реализованы и прошли review. Все исполнители завершили работу;
текущий владелец интеграции/оставшейся приёмки — координатор.
Найдена непроверенная прежняя граница MAP-функции; см. research/topology-evidence.md.

Итоги: 72 unit tests passed, 3 специализированных GPU tests ignored; fmt/clippy
чистые, release native/WASM собраны. 44/44 авто загружаются. 109707 треугольников
на всех 15 трассах прошли centroid audit (max error 0.000164 м).
Playwright 1.57 + обычный Chromium: меню/заезд/HUD/каталог/focus passed, 0 page errors.
Native offscreen skidpad/356a осмотрены; интерактивный native и desktop launcher
проверены и подтверждены пользователем. Тег: `iteration-005`.

Исполнители не коммитят; общие Cargo-сборки последовательно у координатора.

## Проверки

```powershell
. .\scripts\tool-env.ps1
cargo fmt --manifest-path iterations/005-unified-driving/Cargo.toml --all -- --check
cargo clippy --locked --manifest-path iterations/005-unified-driving/Cargo.toml --target-dir local/builds/005-unified-driving/.cargo-target --workspace --all-targets -- -D warnings
cargo test --locked --manifest-path iterations/005-unified-driving/Cargo.toml --target-dir local/builds/005-unified-driving/.cargo-target --workspace
.\scripts\build.ps1 -Iteration 005-unified-driving -Config release -Target all
```

Дополнительные точные команды из корня:

```powershell
local/builds/005-unified-driving/.cargo-target/release/examples/audit_surface.exe local/game/GameData/Track
./scripts/validate-cars.ps1 -Viewer local/builds/005-unified-driving/windows/porsche-viewer.exe -Report local/builds/005-unified-driving/cars.tsv -Force
py -3 scripts/research/audit_topology_evidence.py
py -3 scripts/research/test_topology_evidence.py
& 'C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/node.exe' iterations/005-unified-driving/web/ui.test.mjs
& 'C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/node.exe' iterations/005-unified-driving/web/verify-browser.cjs C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/package auto iterations/005-unified-driving/runs/001-unified-driving
```

Для пересборки audit: `cargo run --locked --release --manifest-path iterations/005-unified-driving/Cargo.toml --target-dir local/builds/005-unified-driving/.cargo-target -p nfs-assets --example audit_surface -- local/game/GameData/Track`.

Этап 005 завершён и принят. Следующий этап 006: SHA/RVA и потребители `.sim`,
FE callbacks, схемы событий/профиля и контрольный сценарий каждой карьеры.
Крупный план — `docs/roadmap.md`, детальный следующий шаг — `docs/next-iteration.md`.
Гипотезы покрытия, упрощённые коллизии, сохранение Y при потере опоры и отсутствие
полного физического контакта — известные ограничения прототипа.
