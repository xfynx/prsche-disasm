# Current project status

Updated 2026-11-20. Active work: [v2 / 001-original-recovery](iterations/v2/001-original-recovery/PLAN.md).

## Recovered C/C++ game

[Run704](iterations/v2/001-original-recovery/runs/704-next-layer-integration/README.md)
compiles 407 C++ translation units across 8 projects. The link has 113 unresolved
names / 119 references. **There is no recovered playable C++ game executable yet.**

Run704 integrates 700-703: nineteen full original bodies (1,611 code bytes:
scene reset leaves, view teardown/route family, entry FE + scene route/transfer
leaves, audio finalize/period callback). Native comparisons pass 3,656 measured
cases and 49 material mutation controls at `/Od`/`/O2`; shared audit PASS,
1,007 source pins. Eighteen frontier names close; eighteen typed children open.
`00562810`/`00563440` are storage-gated (run-273 proof required); eight
excluded bodies are queued as separate packets.

Historical: Run699 integrated 695/696/697 (four bodies, 1,353B; 2,796 cases /
49 mutations / 998 pins; 403 TUs).

Historical: Run698 integrated 691/692/693 (eight full bodies, 2,479B; 374
cases / 75 mutations / 991 pins; 400 TUs; FE main-loop `004152e0`
evidence-only).

Historical: Run694 integrated 688/689/690 (seven full bodies, 1,868B; 24,380
cases / 72 mutations / 984 pins; 397 TUs).

Historical: Run687 integrated eleven partial functions (903 code bytes: `00570260`..`00570540`
in `685/001` plus `005702a0`, `00570920`, `00570990`, `00570ff0`, `00571160` in
`686/002`) and zero owned `.data`/`.rdata`/`.bss`. Native comparisons pass 1060 measured
cases / 47 material controls at `/Od`/`/O2`. Canonical owners are reused. Shared audit
verifies 977 source pins; registry 1114 retains partial domains.

Run566 also compiles six partial callback/resource entries (384 comparisons/four
controls, exact98B readonly data) into an unreferenced archive member. This does
not close a reachable game dependency; real stream-start semantics remain open.

Run685 (`001`), Run686 (`002`), and Run687 (`001`) integration are accepted within their stated bounds.
Run569 remains unaccepted deferred
research. Later draft directories do not supersede accepted build metrics. Active
iteration remains v2/001; numbered runs are recovery packets within it.

Activation4ae010 keeps descriptor bytes22/23 uninitialized and remains partial.
Earlier constructor/metric domains and Run561's true two-live-slot stop remain
open. Partial bindings do not promote semantic parent dependencies. Runs547,
558 and supplemental537005 remain blocked and unaccepted; native AMD 3DNow,
real streams/live TLS, full startup and gameplay remain open. Metrics are not
a completion percentage; detailed bounds live in the run handoffs/backlog.

The composed stop/cleanup/pool chain remains verified after the owner repair through
[Run445](iterations/v2/001-original-recovery/runs/445-audio-owner-alias-regression/README.md).
Outer-group/decoder/removal execution passes bounded seeded and direct scenarios.
Real subscribers, broader parent composition, live APIs and full startup remain open.
Detailed evidence and the next work order live in the
[iteration PLAN](iterations/v2/001-original-recovery/PLAN.md).
Full startup, display, menus, careers and gameplay still need integration/acceptance.

## Other workstreams

The [Rust iteration 012 prototype](iterations/012-campaign-fidelity/README.md) is unfinished.
Compile candidates and x86 lowering tools are research;
they are separate from accepted game code.

The independent Open-Unleashed v0.1.4 Windows release was tested with our assets in an
isolated local folder: Quick Race, garage rendering and first Factory Driver mission
all exited successfully and produced screenshots. Quick Race advanced 1,280 ticks;
the mission smoke run failed its objective and does not prove career completion.
Native Computer Use returned `spawn EPERM`, so no interactive visual acceptance is
claimed. Original asset sizes/mtimes were unchanged. This is external-port evidence,
not a successful build or fidelity proof of our C++ reconstruction.

[PR #25](https://github.com/xfynx/prsche-disasm/pull/25) is integrated into the Rust
prototype, with collision-unit and FFN metric corrections and author attribution.
Its [intake review](docs/research/pr25-integration-review-2026-10-26.md) records the
build/test/browser evidence and unsupported speech-archive boundary. Its recorders
are available for C++ recovery; the C++ checkpoint above is unchanged.

[PR #26 intake](docs/research/pr26-integration-review-2026-10-29.md) adds recorded
keyboard, object and launch/barrier evidence, repairs damage writeback and keeps
unproved new compositions behind an experimental feature. It updates the Rust
prototype and research tools; the C++ checkpoint above is unchanged.

[Xerj source review](docs/research/xerj-evaluation-2026-10-26.md) is complete.
A bounded local retrieval trial could measure its value; no performance gain or
runtime/MCP integration has been verified here.

## Evidence and remaining checks

Use the [binary index](research/binary-index/README.md), [recovery runs](iterations/v2/001-original-recovery/runs/),
[validation backlog](docs/recovery-validation-backlog.md) and [roadmap](PLAN.md).
Older checkpoints remain in the iteration history and Git; this file describes current state.
