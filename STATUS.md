# Current project status

Updated 2026-11-17. Active work: [v2 / 001-original-recovery](iterations/v2/001-original-recovery/PLAN.md).

## Recovered C/C++ game

[Run603](iterations/v2/001-original-recovery/runs/603-render-display-input-integration/README.md)
compiles339 C++ translation units across8 projects. The link has113 unresolved names/
118 references. **There is no recovered playable C++ game executable yet.**

Run603 integrates partial `0056a680` (38B), `004b70d0` (112B) and `00586cd0` (63B)
from frozen601001 and602001 plus 12B file-backed and 808B loader-zero `.data`.
Native comparisons pass1240 cases/eight controls atOd/O2. Canonical startup
noop, x87 `_ftol`, display texture height and window tick owners are reused.
Shared audit verifies838 pins/913 providers; registry923 retains partial domains.

Run566 also compiles six partial callback/resource entries (384 comparisons/four
controls, exact98B readonly data) into an unreferenced archive member. This does
not close a reachable game dependency; real stream-start semantics remain open.

Run601 native001, Run602 native001 and Run603 integration are accepted within their stated bounds.
Run604 render initialize callbacks and605 render driver context mode are active pending packets.
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
