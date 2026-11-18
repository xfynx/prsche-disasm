# Current project status

Updated 2026-11-18. Active work: [v2 / 001-original-recovery](iterations/v2/001-original-recovery/PLAN.md).

## Recovered C/C++ game

[Run654](iterations/v2/001-original-recovery/runs/654-movie-setup-codec-release-integration/README.md)
compiles 373 C++ translation units across 8 projects. The link has 80 unresolved names /
85 references (closing `game_setup_movie_004dd4a0`, `game_setup_resource_open_0059e440`,
`audio_stream_service_release_00566e10`, `audio_stream_codec_destroy_0056b3b0`, and
`audio_stream_codec_reset_0056c420`, while `0056c620` exposes `audio_stream_codec_refill_0056baf0`).
**There is no recovered playable C++ game executable yet.**

Run654 integrates eight partial functions (2534 code bytes total: `00472860`/`0059e440`/`004dd4a0`
in `652/003` plus `00566e10`/`0056b3b0`/`0056c140`/`0056c420`/`0056c620` in `653/008`), 28B `.data`
(`005d998c`/`005d999c`), and 273B `.rdata` (`005bdaa0`, `005bdd30..005bde43`). Native comparisons
pass 122 measured cases / 24 material controls at `/Od`/`/O2`. Canonical owners are reused. Shared
audit verifies 924 source pins; registry 1016 retains partial domains.

Run566 also compiles six partial callback/resource entries (384 comparisons/four
controls, exact98B readonly data) into an unreferenced archive member. This does
not close a reachable game dependency; real stream-start semantics remain open.

Run652 (`003`), Run653 (`008`), and Run654 (`001`) integration are accepted within their stated bounds.
Run655 (`0055ff60` + `0048d350` + `0048cdf0`) is active for integration in Run657.
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
