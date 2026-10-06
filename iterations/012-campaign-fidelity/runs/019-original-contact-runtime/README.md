# Run 019 — mixed scene and contact preparation

2026-10-06. Live polygon+EDG tree integration and bounded original-state APIs.
Iteration 012 remains open; this is not complete original suspension/body physics.

The game loads source-constructed EDG into the same original tree as retained
type-1 polygons, in source insertion order. Four-wheel support sees this tree.
Complete EDG query, first body contact and scene-dependent response have APIs
requiring original car fields; body response still uses the existing adapter.
Wheel height branches/material state are restored separately, including strict
period comparison, all material nibbles and process-global RNG product/seed.

Source: Porsche.exe SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Queries, branches, formulas and remaining contracts:
[contact-runtime-019.md](../../research/original-collision/contact-runtime-019.md).
Exports: `contact-runtime-source.jsonl`, `mixed-query-source.jsonl`,
`edge-default-containment.txt`. Existing 0x494000/0x495020 exports remain under
research/original-collision. File EDG success bypasses temporary generation;
the mandatory clipping hypothesis was rejected at 0x4880ed.

Unchanged original x86 and Rust differential checks: 3 full mixed trees / 27
EDG queries; 8 first body contacts/no-hit paths and fallback segment starts;
45 complete scene-dependent responses; 5 wheel branches / 29 material states.
These cover record order/splits, owner gate/cache, height ties, endpoint order,
constructor adjustment, correction, angular callback, four points/reset fields,
all 16 material nibbles, exact gate/period boundaries and nonidentity RNG.

220 workspace Rust tests passed, 3 GPU acceptance tests ignored. Final RNG
precision correction passed its two targeted tests. fmt/clippy -D warnings,
wasm32 check and native+web release passed. All 15 tracks contain their source
EDG vector in the live tree. Quick Race on Skidpad/Alps/Canyon and 21 general
browser checks passed: errors=[], knownFailures=[]. Skidpad PNG inspected.
Short browser runs are not original/native visual acceptance or proof that
all map exits, rolls and impacts are fixed. Hashes/details: verification.json.

No active workers. Coordinator completed the partial code after mixed worker
quota, corrected original constructor/RNG semantics and integrated geometry.
Remaining: full 0x499a70 forces/fallback/front offsets; car extent/wheel/basis
producers and angular cadence; repeated contacts/large-impact/effect callbacks;
original car-car contacts, special box/cylinder scene records and no-EDG
generation. T01/T02 original UI/mission/spawn/results/penalties and full 0M01
comparison remain required; none is silently deferred out of iteration 012.
Next: 0x499bc4..0x499d15 fallback and front offset 0x493bc0, then wheel
+0x64/+0x6c at 0x499d15..0x499eec and downstream forces. Extent creation:
follow 0x4110a0 before its 0x410730 reset, not visible mesh bounds by analogy.

```powershell
py -3 scripts/research/replay-mixed-support.py
py -3 scripts/research/replay-body-selection.py
py -3 scripts/research/replay-scene-response.py
py -3 scripts/research/replay-wheel-state.py
. ./scripts/tool-env.ps1
cargo test --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target --workspace
cargo fmt --manifest-path iterations/012-campaign-fidelity/Cargo.toml --all -- --check
cargo clippy --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target --workspace --all-targets -- -D warnings
cargo check --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target -p porsche-viewer --target wasm32-unknown-unknown
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build.ps1 -Iteration 012-campaign-fidelity -Config release -Target all
& 'C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/node.exe' iterations/012-campaign-fidelity/web/verify-original-support.cjs C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/package iterations/012-campaign-fidelity/runs/019-original-contact-runtime
& 'C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/node.exe' iterations/012-campaign-fidelity/web/verify-browser.cjs C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/package auto iterations/012-campaign-fidelity/runs/019-original-contact-runtime
```

Launch: `local/builds/012-campaign-fidelity/Launch-desktop.cmd`; native also
built (`Launch-native.cmd`), native gameplay not accepted. Old `012-runtime-sim`
directory is not updated. Build/test logs: local/reports/019-*.log.
