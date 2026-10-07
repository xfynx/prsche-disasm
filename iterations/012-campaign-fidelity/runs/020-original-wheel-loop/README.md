# Run 020 — original first four-wheel loop

2026-10-06. Porsche.exe SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index queries: `query-binary-index.py --binary Porsche.exe --address <VA>
--disassemble --limit 2200`; addresses and functions are saved in
`wheel-loop-source.jsonl`. This continues the concrete next step from Run 019.

`original_wheel_loop.rs` restores **0x499a70 through 0x499f16**, stopping
before later force accumulation. It requires explicit original car/component
fields and has no gameplay force binding. The live build retains Run 019's
mixed scene support and its existing force adapter. Iteration 012 stays open.

Unchanged original x86 executes its real tree query, polygon callbacks,
material RNG, twenty-part front-offset consumer, compression clamps and CRT
asin. The harness supplies synthetic car, component and scene inputs; only
the existing single-thread Win32 critical-section model replaces imports.
It stops by observation at 0x499f16; no game instruction or callee is patched.
47 complete first loops / 188 wheel states match the Rust transfer at absolute
or relative tolerance 2e-6. This bounds f64 portability of x87 intermediates;
it is not a bit-exact claim or an original driving/visual acceptance result.

Confirmed flow:

- 0x499adf..0x499b13 copies points +0x1dc and adds part+0x120 times body-up Y.
- 0x499b64 support selection reuses each wheel's owner. +0x6573f8 remaps raw
  material nibbles 1/10 to word 2; 0x494480 still sees original owner flags.
- 0x499bc4..0x499c32 uses the fallback plane +0x3e8/+0x400 if its normal Y
  is strictly above float 0.1; otherwise normal [0,1,0]. Material/RNG/front
  offset do not advance on this alternate branch.
- 0x499c37..0x499cc5 stores polygon height before adding the unrounded
  0x499730 result. Front wheels alone add sin((index/2 + owner+0x84) times
  source float 6.28318024) times 0x493bc0 times source double 1/1500.
- 0x493bc0 reads all twenty components. Kinds 4/5/8 count; contribution is
  the mean selected +0x4e4 modifiers times (1.5 - part+0x60 times source
  float 0.005), plus part+0x164. The return is the mean eligible contribution.
- 0x499d15..0x499eec writes +0x64 compression and +0x6c angle. Quality below
  2, or both global +0x657408 and car+0xdac nonzero, zero both fields.
  Otherwise the f32 support-query delta projects on body-up. Body-up Y below
  float 0.3 replaces the projection with source float -0.1.
- Positive compression caps at (part+0x124 - part+0x120) times float 0.9
  for the front pair, 0.75 for the rear pair. A projection above twice the
  unrounded cap sets its later-force multiplier to 1.25. Nonpositive
  compression clamps to part+0x124 times -1.6/-1.65 depending on owner+0x80,
  then averages with the old compression. Angle uses original asin; wheels
  1 and 3 negate it. The four accumulated support points and multipliers
  are returned for the subsequent force block, before division by four.

Fixtures cover all 16 material nibbles, a high material word/remapping,
RNG order/state, far/missing support, exact +/-4 height gates and nearby
values, fallback normal gates, inverted body, quality/global/car gates,
zero/positive/negative compression, both axle caps, 1.25 multipliers,
negative floor flags and eligible/ineligible component masks/means.
Inputs, intermediate wheel query/point/normal/noise and final compression,
angle, sum, multiplier and RNG outputs are retained in JSON/TSV.

221 workspace tests passed, 3 GPU acceptance tests ignored; fmt,
workspace/all-target clippy -D warnings, wasm32 check and native/web release
passed. Final WASM changed during recompilation; three Quick Race support
checks passed on that artifact. The general browser regression was not
completed before the user's 2026-10-08 request to commit as-is and switch to v2.
This run adds no gameplay binding; no fresh original
captures, native visual acceptance or full mission comparison were obtained.

Unfinished former next step: **0x499f16..0x49a8f8** — consume point means, compression and multiplier
locals, accumulate forces, then trace 0x49bc80/0x49ae30/0x49a900 callbacks.
The physical point/extent/basis producers and original cadence remain required
for binding. Repeated body contacts, special objects, car-car response and
T01/T02 original UI/mission acceptance also remain in iteration 012.

```powershell
py -3 scripts/research/replay-wheel-loop.py
. ./scripts/tool-env.ps1
cargo test --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target --workspace
cargo fmt --manifest-path iterations/012-campaign-fidelity/Cargo.toml --all -- --check
cargo clippy --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target --workspace --all-targets -- -D warnings
cargo check --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml --target-dir local/builds/012-campaign-fidelity/.cargo-target -p porsche-viewer --target wasm32-unknown-unknown
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build.ps1 -Iteration 012-campaign-fidelity -Config release -Target all
```

Launch remains `local/builds/012-campaign-fidelity/Launch-desktop.cmd`.
Local build/test logs: `local/reports/020-*.log`. No active workers;
work on 012 stopped at the user's request; these open tasks are preserved.
