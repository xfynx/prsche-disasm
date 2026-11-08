# Current project status

Updated 2026-11-09. Active work: [v2 / 001-original-recovery](iterations/v2/001-original-recovery/PLAN.md).

## Recovered C/C++ game

[Run551](iterations/v2/001-original-recovery/runs/551-diagnostic-codec-integration/README.md)
compiles307 C++ translation units across8 projects. The link has133 unresolved names/
141 references. **There is no recovered playable C++ game executable yet.**

New research (not accepted, not integrated):
[Run552](iterations/v2/001-original-recovery/runs/552-audio-adpcm-kernel/README.md)
implements the six-body coded-audio family behind the 551 processors
(59a910/59abe0/59ad80/59adc0/59ae00/59b580) and proves five bodies plus the
synthesis and many frame sub-cases bit-exactly against the original. The full frame
with a random dequant bitstream still diverges; the next step is the documented
after-blend stage probe. No game build, registry entry or pin count changed.

Latest:four originals1130B/0newdata;16,152 native comparisons/33 mutations/754pins
pass;registry842. Four names close, two real decoder-kernel names enter: ADPCM59a910
and resampler597810. Diagnostic device/formatter transport and codec caller glue
compose with existing canonical providers; full codec mathematics/formattercore/
liveoutputs remain open. Externalheap-slot569a70 binding stays unresolved; proposed
547 export was antivirus-blocked before execution. Previous5453DNow evidence
remains emulated; nativeAMD hardware fidelity is open.
Supplemental
537005 query-alias controls were antivirus-blocked before execution and are unaccepted.
Earlier constructor/metric unwritten-local paths and full platform/gameplay stay open;
earlier3DNow is emulated. These metrics are not a completion percentage.

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
