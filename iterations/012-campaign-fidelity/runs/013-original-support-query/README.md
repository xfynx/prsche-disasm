# Run 013 — исходные опорные полигоны и выбор уровня дороги

2026-10-05. Это run внутри активной 012-campaign-fidelity; итерация 013 не начата.

Прослежены исходные type-1 объекты опоры: треугольники/четырёхугольники,
проверка попадания в XZ и выбор по высоте центра в заданном листе дерева.
Оригинальные конструкторы, virtual predicates и цикл выбора исполнены в Unicorn:
36 проверок полигонов и 10 выборов уровня прошли. Дополнительно 10 случаев
исходной ветки quad split прошли, включая границу 0.04. Результаты:
support-replay.json; исходные результаты для Rust: polygon-fixtures.tsv и
selection-fixtures.tsv.

Найден загрузчик этих объектов из Base/pr/vt/df ресурсов. Связь материала с raw mt
и пространственный запрос ещё требуют трассировки. Текущий RD-triangle runtime не
считается восстановленным этим исследованием.

Реверс планировщика: исходный угловой интегратор зарегистрирован в очереди,
вызываемой на каждом simulation step; источник таймера — 128 Гц, производные
счётчики номинально 64 Гц. Ветки догоняющего цикла ещё нужно связать с интеграцией.

## Проверки

```powershell
py -3 scripts/research/replay-support-polygons.py --output iterations/012-campaign-fidelity/runs/013-original-support-query/support-replay.json --fixture-tsv iterations/012-campaign-fidelity/runs/013-original-support-query/polygon-fixtures.tsv --selection-tsv iterations/012-campaign-fidelity/runs/013-original-support-query/selection-fixtures.tsv
. ./scripts/tool-env.ps1
cargo test --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target -p nfs-assets --test original_support --test original_contact
```

Источник/SHA/адреса/формулы: [support-polygons.md](../../research/original-collision/support-polygons.md).
Планировщик: [integration-cadence.md](../../research/original-collision/integration-cadence.md).
Rust-перенос опорных предикатов и выбора листа завершён. Два теста original_support
сравнивают 36+10 исходных результатов; original_contact (468 состояний) тоже прошёл.
Fmt, clippy --all-targets -D warnings и wasm32 check прошли. Это перенос отдельных
функций; в игровой цикл ещё не подключён. Исполнители завершили работу.
Далее: raw flags материала и spatial leaf query, защитная ветка plane helper при
quad splitting, затем подключение к состоянию авто и игровая приёмка.
