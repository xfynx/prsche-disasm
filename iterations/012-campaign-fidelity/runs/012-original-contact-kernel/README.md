# Run 012 — перенос проверенного участка контакта

2026-10-05. Активная итерация по-прежнему 012-campaign-fidelity.
Исходник: Porsche.exe SHA256
ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.

Восстановлена ветка 0x493f10: условия по силе контакта и прежней проекции скорости,
знак и величина изменения car+0x38c, очистка car+0x434. Она вызывается до обновления
проекций в 0x493e40. Проверка исполняет исходные инструкции, без замен вызовов.
468 случаев прошли, включая границы 15/20, четыре комбинации знаков, включённый/
отключённый callback и обе ветки car+0x52c mask 4. Входы и результаты:
response-replay.json; компактная выгрузка для Rust: response-fixtures.tsv.

Добавлен отдельный Rust-модуль physics/original_contact.rs. Он переносит проверенный
участок изменения состояния при уже подготовленном контакте. Регрессия сравнивает
его с 468 результатами исходного x86. Пока он не подключён к игровому циклу:
выбор контакта и связь полей исходного автомобиля с текущим solver требуют переноса.
Поверхностные/effect коды, повреждения и весь исходный solver здесь не заявляются.

Дополнительно исполнены исходные участки создания восьми точек и подготовки
геометрии выбранного ребра: 3 положения базиса и 12 edge/point случаев прошли.
Порядок концов EDG задаёт знак нормали; перестановка концов меняет знак.
Данные: geometry-replay.json. Это не полный запрос сцены/принятие контакта.

## Проверки

```powershell
py -3 scripts/research/replay-contact-response.py --output iterations/012-campaign-fidelity/runs/012-original-contact-kernel/response-replay.json --fixture-tsv iterations/012-campaign-fidelity/runs/012-original-contact-kernel/response-fixtures.tsv
py -3 scripts/research/replay-contact-geometry.py --output iterations/012-campaign-fidelity/runs/012-original-contact-kernel/geometry-replay.json
. ./scripts/tool-env.ps1
cargo test --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target -p nfs-assets --test original_contact
```

Rust regression: прошла (один тест проверяет 468 исходных состояний).
После окончательной правки прошли 103 теста nfs-assets, включая 468 состояний
в original_contact и аудит 15 трасс; cargo fmt --check, clippy --all-targets
с -D warnings и cargo check для wasm32-unknown-unknown прошли.
Журнал тестов: cargo-test.log. Полную игровую сборку не выпускали.
Поле car+0x38c связано с поворотом вокруг Y: исходный интегратор применяет
field/64 оборота за вызов. Частота вызова ещё не установлена; прямое присваивание
радиан/сек текущего solver было бы неподтверждённым преобразованием.
Подробности: [формула callback и геометрия](../../research/original-collision/angular-response.md),
[потребитель углового поля](../../research/original-collision/angular-field.md).
Следом: завершить контракт выбора/приёма контакта и связь состояния, затем подключить
перенесённые функции к заезду и сравнить движение. Последняя игровая сборка — fa56d05.
