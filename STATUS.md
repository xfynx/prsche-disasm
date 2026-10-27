# Current project status

Updated 2026-10-27. Active work: [v2 / 001-original-recovery](iterations/v2/001-original-recovery/PLAN.md).

## Recovered C/C++ game

[Run440](iterations/v2/001-original-recovery/runs/440-audio-pool-cleanup-integration/README.md)
compiles 232 C++ translation units across 8 projects. The game link still has 181 unresolved
names / 188 references. **There is no recovered playable C++ game executable yet.**

The latest batch integrates five original audio pool/cleanup bodies after 115,592 native
sequences/cases, 32 detected mutations and a 576-pin audit. Existing state owners are reused.
These are batch results, not a completion percentage.
The modem enumerator/callback retain partial domains; live platform behavior is unverified.

The [Run441 composed proof](iterations/v2/001-original-recovery/runs/441-audio-stop-composition/README.md)
passes 1,392 cases and 9 mutations using the unchanged Run440 build. Positive channel
returns and real stop/cleanup/pool calls are verified in bounded native scenes.

Audio pool allocation/release and voice cleanup are integrated in their tested domains.
Audio initialization, group validation/release and actual platform/device startup remain open.
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

[Xerj source review](docs/research/xerj-evaluation-2026-10-26.md) is complete.
A bounded local retrieval trial could measure its value; no performance gain or
runtime/MCP integration has been verified here.

## Evidence and remaining checks

Use the [binary index](research/binary-index/README.md), [recovery runs](iterations/v2/001-original-recovery/runs/),
[validation backlog](docs/recovery-validation-backlog.md) and [roadmap](PLAN.md).
Older checkpoints remain in the iteration history and Git; this file describes current state.
