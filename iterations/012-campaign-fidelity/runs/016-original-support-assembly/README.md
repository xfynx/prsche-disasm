# Run 016 — original Base/pr readers and spatial child constructor

2026-10-05. Run внутри 012, не новая итерация. Цель — восстановить доказанные
части загрузки опор из оригинала и сравнить их с исходными инструкциями.

Перенесены чтение выбранной записи Base, primitive count/descriptor/index
helpers и исходный child constructor дерева. 317 primitive payload cases /
2536 helper outputs, 60 Base cases и 256 child cases совпали с оригинальным
x86. Rust независимо разобрал 15 трасс: 74 300 pr и 16 591 Base; source SHA,
ресурсные SHA и границы проверки сохранены в JSON/отчётах.

Источник и связь с реализацией:
[support-assembly.md](../../research/original-collision/support-assembly.md),
[spatial-insertion.md](../../research/original-collision/spatial-insertion.md).
TSV содержит исходные payloads и выходы оригинала, а не подобранные ожидания.
Результаты сборок/тестов — verification.json.

## Команды

```powershell
py -3 scripts/research/replay-support-assembly.py --run-dir iterations/012-campaign-fidelity/runs/016-original-support-assembly --source-output iterations/012-campaign-fidelity/research/original-collision/support-assembly-source.jsonl
py -3 scripts/research/replay-spatial-insertion.py --run-dir iterations/012-campaign-fidelity/runs/016-original-support-assembly
. ./scripts/tool-env.ps1
cargo test --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target -p nfs-assets --test original_support_assembly --test original_support_material --test original_support --test original_spatial --test original_contact
cargo fmt --manifest-path iterations/012-campaign-fidelity/Cargo.toml --all -- --check
cargo clippy --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target -p nfs-assets --all-targets -- -D warnings
cargo check --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target -p nfs-assets --target wasm32-unknown-unknown
```

## Остаток и передача

Производитель Base ordinal, special/alternate collider paths, ресурсный range
lookup, color/degeneracy/full polygon assembly и рекурсивная вставка дерева
ещё не восстановлены. 0x477d40 оказался инициализацией lookup cache, не выбором
Base ordinal. Следующий конкретный шаг координатора: 0x484320 и type-1 vtable
+4/+8 callbacks, затем original insertion replay на подготовленной сцене.
После — state/cadence автомобиля и игровое сравнение.

Исполнитель по insertion остановился лимитом после source export; координатор
проверил незавершённые файлы, сохранил экспорт и перенёс child constructor.
Активных назначений нет. Модули остаются вне игрового цикла; build fa56d05.
012 открыта, нативная/визуальная/игровая приёмка этим run не проведена.
