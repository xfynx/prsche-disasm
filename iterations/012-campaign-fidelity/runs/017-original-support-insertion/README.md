# Run 017 — original insertion → tree → cached support query

2026-10-05. Run внутри 012. Восстановлены исходные центр/границы type-1
полигонов, node/object predicate, динамическая вставка, деление листьев и
перераспределение записей. Эти модули соединены с исходным cached query.

38 callback и 304 predicate cases, 36 полных снимков дерева и 72 полных
запроса опоры совпали с исходным x86. Проверяются packed nodes, наличие детей,
порядок/дубликаты записей, выбор полигона и обновление cache. Исполнены реальные
original allocator/vector callbacks; только импортированные Win32 locks
моделируются для одного потока. Подготовленная heap arena — 4 MiB.

Источник/SHA/команды/границы:
[support-tree.md](../../research/original-collision/support-tree.md),
[support-bounds.md](../../research/original-collision/support-bounds.md),
[support-special-selection.md](../../research/original-collision/support-special-selection.md).
Исходные выходы и промежуточные деревья сохранены в TSV; подробности — JSON.
Итог проверки — verification.json.

Special-таблица найдена: animdefs.txt → 0x47eba0 → 0x628ba0. Lookup 0x47ed90
для неизвестного ненулевого Base+0x44 возвращает первую запись ENDW/kBox.
Из 16 591 Base на 15 трассах 4 186 имеют ненулевой тег; точный выбор объекта
нельзя заменить проверкой наличия тега. Это трассировка источника, ещё без
переноса parser/lookup и без replay этой ветки. Назначения исполнителей завершены.

## Команды

```powershell
py -3 scripts/research/replay-support-bounds.py --run-dir iterations/012-campaign-fidelity/runs/017-original-support-insertion --source-output iterations/012-campaign-fidelity/research/original-collision/support-bounds-source.jsonl
py -3 scripts/research/replay-support-tree.py --run-dir iterations/012-campaign-fidelity/runs/017-original-support-insertion --source-output iterations/012-campaign-fidelity/research/original-collision/support-tree-source.jsonl
. ./scripts/tool-env.ps1
cargo test --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target -p nfs-assets --test original_support_tree --test original_support_bounds --test original_support_assembly --test original_support_material --test original_support --test original_spatial --test original_contact
cargo fmt --manifest-path iterations/012-campaign-fidelity/Cargo.toml --all -- --check
cargo clippy --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target -p nfs-assets --all-targets -- -D warnings
cargo check --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target -p nfs-assets --target wasm32-unknown-unknown
```

## Остаток

Оригинальная сцена теперь строится и опрашивается в отдельном модуле на
предоставленных type-1 polygons. Подключение реальных ресурсов требует полного
loader, затем связи с состоянием авто. Следом 0x475543..0x47591e и special
lookup 0x47ed90; гипотезы по выбору ресурсов не подключаются к игре.
Игровая сборка остаётся fa56d05, 012 открыта; визуальная/native игровая приёмка
этим run не проведена. Цель дальнейшего подключения — одна трасса в 012.
