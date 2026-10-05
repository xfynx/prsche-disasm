# Run 014 — original spatial support query

2026-10-05. Run внутри активной 012, не новая итерация.

Прослежены исходные packed XZ node bounds, point traversal и cache selection.
12 инициализаций grid / 112 bounds / 112 traversal / 336 cache случаев прошли
на исходных x86-инструкциях. Найдены включённые границы cache, выбор positive
half при равенстве и возврат исходного root при отсутствующей ветке.

Источник, SHA, адреса и ограничения:
[spatial-query.md](../../research/original-collision/spatial-query.md).
Material flags trace:
[support-material.md](../../research/original-collision/support-material.md).
Подтверждён путь PCollideArticleBundle → owner → material flags; смещение raw mt
остаётся неизвестным. Следующая точка трассировки — источник `[wrapper]` при
0x4832d2 и запись owner+0x2c. Исполнители закончили работу.

## Проверки

```powershell
py -3 scripts/research/replay-spatial-support.py --output iterations/012-campaign-fidelity/runs/014-original-spatial-query/spatial-replay.json --fixtures-dir iterations/012-campaign-fidelity/runs/014-original-spatial-query --source-output iterations/012-campaign-fidelity/research/original-collision/spatial-source.jsonl
. ./scripts/tool-env.ps1
cargo test --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target -p nfs-assets --test original_spatial --test original_support --test original_contact
```

В Rust перенесены grid initialization, packed bounds, traversal и cache resolution:
четыре новых теста сравнили все 572 исходных результата. Вместе с contact/support
прошли семь Rust-тестов; fmt, clippy --all-targets -D warnings и wasm32 check чисты.

```powershell
cargo fmt --manifest-path iterations/012-campaign-fidelity/Cargo.toml --all -- --check
cargo clippy --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target -p nfs-assets --all-targets -- -D warnings
cargo check --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target -p nfs-assets --target wasm32-unknown-unknown
```

Эта проверка использует
synthetic arena и пустые исходные record vectors; не доказывает scene loading,
построение дерева или езду. Игровая сборка остаётся fa56d05, 012 открыта.
