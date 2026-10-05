# Run 015 — original support material and plane helpers

2026-10-05. Run внутри 012, не новая итерация.

Исходный material word найден в **mt payload+0x00**. Прослежены создание
владельца сцены, передача material container и запись raw payload pointer.
208 случаев исходных pointer/field/consumer instructions прошли в Unicorn.
Отдельно 10 наборов geometry исполнены через исходные plane/gap helpers;
10 прежних original split-branch результатов взяты из Run 013.

Материал и plane/gap/split перенесены в pure Rust. Rust-тест сравнил исходные
выходы и независимо разобрал материалы всех 15 трасс — 3651 mt entries.
Всего прошли 11 Rust-тестов вместе с contact/support/spatial; fmt, clippy
--all-targets -D warnings и wasm32 check чисты. verification.json сохраняет итог.

Источник/SHA/адреса/границы:
[material-loader.md](../../research/original-collision/material-loader.md),
[support-plane.md](../../research/original-collision/support-plane.md).

## Команды

```powershell
py -3 scripts/research/replay-support-material.py --output iterations/012-campaign-fidelity/runs/015-original-support-loader/material-replay.json --fixture-tsv iterations/012-campaign-fidelity/runs/015-original-support-loader/material-fixtures.tsv --census-output iterations/012-campaign-fidelity/runs/015-original-support-loader/material-census.json
py -3 scripts/research/replay-support-plane.py --output iterations/012-campaign-fidelity/runs/015-original-support-loader/plane-replay.json --fixture-tsv iterations/012-campaign-fidelity/runs/015-original-support-loader/plane-fixtures.tsv --split-fixture-tsv iterations/012-campaign-fidelity/runs/015-original-support-loader/plane-split-fixtures.tsv --source-output iterations/012-campaign-fidelity/research/original-collision/support-plane-source.jsonl
. ./scripts/tool-env.ps1
cargo test --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target -p nfs-assets --test original_support_material --test original_support --test original_spatial --test original_contact
cargo fmt --manifest-path iterations/012-campaign-fidelity/Cargo.toml --all -- --check
cargo clippy --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target -p nfs-assets --all-targets -- -D warnings
cargo check --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target -p nfs-assets --target wasm32-unknown-unknown
```

## Остаток

Материалный replay исключает allocation/renderer lookup и использует выделенные
буферы; plane replay использует synthetic geometry. Назначение индивидуальных
flags (включая friction) не выведено из чисел. Полный loader, tree insertion,
state/cadence автомобиля и игровая приёмка ещё открыты. Ни один из этих pure
модулей пока не подключён к заезду; игровая сборка остаётся fa56d05.

Исполнители завершили работу. Следующий конкретный участок — Base/pr/vt selection
в 0x4750b0 и заполнение дерева в 0x484ae0 / child constructor 0x483bd0.
