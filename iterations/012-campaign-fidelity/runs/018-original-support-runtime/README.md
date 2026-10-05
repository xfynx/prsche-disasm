# Run 018 — подключение исходных опор к игре

2026-10-05..06, игровое подключение type-1 опор выполнено. Цель: реальный CRP → original loader →
support selection/plane → колесо в native/WASM, без RD* отбора.

Завершённые назначения: resource_support_loader — loader/ordinal/replay;
runtime_contact_trace — wheel consumer 0x499a70 и support owner/plane;
координатор — track_loader, RoadSurface, suspension, сборка и приёмка.

Подтверждено: Porsche.exe 0x499b64 вызывает 0x474060 для точки колеса,
0x499b6b получает нормаль через 0x474420, 0x499c3b — точку плоскости
через 0x4745f0. У текущего solver другой запрос лучом; нельзя объявлять
сохранённый расчёт сил восстановленной оригинальной подвеской.

Критерий: восстановленные ресурсы и запрос выполняются в игровом пути;
исходные промежуточные результаты сверены; реальные трассы загружаются;
сборки и поездка проверены. 012 этим частичным подключением не закрывается.

Подключено в исходниках: track_loader → ordinary Base resources (без 0x8000),
retained flag-1 loader → type-1 SupportTree → OriginalSupportOwner → запросы
RoadSurface и четырёх колёс SuspensionSystem. RD* и Skidpad mt53/54 эвристика
убраны. При reset кэш колёс очищается. XYZ остаются исходными; Z отражается
только на границе scene API. Силы/метрика подвески пока прежний adapter.

Исходный первый проход 0x488201 строит временное дерево; retained дерево
scene+0x24 получает второй проход 0x48839f. Predicate материалов в этом
проходе пропускает pr при raw & 0xffffff0f == 0. Scene group1 0x4781a0
отбирает Base без 0x8000; на 15 трассах исключено 1 050 library articles.
Base+4 читается из исходного payload, без жёсткого ordinal=0 и без выбора
LOD по догадке. Runtime-мутации этого поля пока не воспроизведены.

Owner replay: 10 исходных x86 случаев для выбора/двух кэшей/нормали/точки/
высоты; loader replay: 9 случаев точных degeneracy branches. Fixture-файлы
в этом run. Полные адреса и границы:
[support-loader.md](../../research/original-collision/support-loader.md),
[runtime-contact-integration.md](../../research/original-collision/runtime-contact-integration.md).

Незавершённое: смешанное дерево с type-2/box/cylinder, полный original
0x499a70 (alternate height/material branches, offsets, силы), original
prepared-contact kernel в игровом solver, сравнение реальной езды с оригиналом.

## Проверки и запуск

215 Rust tests passed, 3 ignored (включая native GPU acceptance).
fmt, workspace clippy -D warnings и porsche-viewer wasm32 check прошли.
Native/Web release собраны. Все 15 реальных track scenes загружаются.
237 395 статических type-1 полигонов; 1 050 library articles исключены.

Headless Chromium: 3 Quick Race (Skidpad, Alps, Canyon), у четырёх колёс
заполнен original polygon cache, есть нагрузка; поездки не потеряли высоту
дороги. browser-support.json сохраняет состояние до/после; PNG кадры
просмотрены координатором. Общий verify-browser: 21 check, errors=[],
knownFailures=[] — включая Factory 0M01 и Quick Race после Factory.
Это короткие regression-прогоны, не оригинальная/native визуальная приёмка
и не доказательство отсутствия провалов во всех столкновениях/переворотах.

```powershell
py -3 scripts/research/replay-support-loader.py
py -3 scripts/research/replay-support-owner.py
. ./scripts/tool-env.ps1
cargo test --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target --workspace
cargo fmt --manifest-path iterations/012-campaign-fidelity/Cargo.toml --all -- --check
cargo clippy --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target --workspace --all-targets -- -D warnings
cargo check --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target -p porsche-viewer --target wasm32-unknown-unknown
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build.ps1 -Iteration 012-campaign-fidelity -Config release -Target all
& 'C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/node.exe' iterations/012-campaign-fidelity/web/verify-original-support.cjs C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/package iterations/012-campaign-fidelity/runs/018-original-support-runtime
& 'C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/node.exe' iterations/012-campaign-fidelity/web/verify-browser.cjs C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/package auto iterations/012-campaign-fidelity/runs/018-original-support-runtime
```

Сборка для пользователя:
`local/builds/012-campaign-fidelity/Launch-desktop.cmd` (проверенный web/GPU путь),
`Launch-web.cmd` или `Launch-native.cmd` (native собран, игровой native прогон
не проведён). Старый каталог 012-runtime-sim этим run не обновляется.
Логи cargo/build — local/reports/018-support-*.log; SHA256 артефактов — verification.json.
Назначений больше нет; точный остаток и следующий шаг приведены выше и в PLAN.
