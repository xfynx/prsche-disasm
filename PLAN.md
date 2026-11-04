# Project roadmap

The goal is a working reconstruction of Need for Speed: Porsche Unleashed / Porsche 2000
from original game code and resources, followed by an architecture map and a Rust port.
Original behavior, both careers and the original UI remain the acceptance target.

## Current work

The active iteration is [v2 / 001-original-recovery](iterations/v2/001-original-recovery/PLAN.md).
Its PLAN owns detailed scope, owners, evidence, commands and handoffs. Current measured
results are in [STATUS.md](STATUS.md); historical checkpoints remain in iteration runs
and Git history.

The presentation cleanup and pending recovery batches are closed out.
[PR #25 intake](docs/research/pr25-integration-review-2026-10-26.md) integrates its
Rust prototype changes and original-code evidence, with scoped author attribution
and explicit unsupported domains. The requested
[Xerj evaluation](docs/research/xerj-evaluation-2026-10-26.md) is complete: an optional
bounded retrieval trial could measure its benefit. Next is the existing C++
dependency work; recovery acceptance remains unchanged.

Latest recovery intake: [Run532](iterations/v2/001-original-recovery/runs/532-library-dsp-integration/README.md).
Library/cache/native fallback paths and bounded DSP are integrated; metric597360 stays partial.
[PR #26 intake](docs/research/pr26-integration-review-2026-10-29.md)
adds reusable recorders and prototype ports, with unproved compositions gated off.
Next integrate verified resources and recover remaining processor/node dependencies.

## Recovery milestones

1. Recover and integrate the original C/C++ startup and subsystem dependencies, using
   canonical state owners and bounded original-x86 comparisons.
2. Link a real Win32 game executable; validate startup, resource loading and display.
3. Validate menus, Quick Race, Evolution, Factory Driver, physics, damage, AI, progression,
   used-car purchases, saves and audio against the original. Close the
   [validation backlog](docs/recovery-validation-backlog.md).
4. After original-code recovery is complete, consolidate the accepted C/C++ sources
   into one canonical `source` tree organized by subsystem and update the build paths.
   Keep immutable native fixtures, original comparisons and run history in `runs`;
   preserve function/address provenance and proof hashes through an explicit migration
   manifest. This consolidation is deferred; do not relocate sources during recovery.
5. Document how the complete game works at code level: module boundaries, state,
   lifetimes, call/data flows and platform dependencies.
6. Use that verified structure for the Rust native/web port.

The older [Rust iteration 012 prototype](iterations/012-campaign-fidelity/README.md) is unfinished
and integration is paused. Snapshots 001?011 remain immutable. New experimental paths do
not silently replace the original-recovery goal or count as full-game acceptance.

## Working rules

Use [AGENTS.md](AGENTS.md), the [recovery skill](.agents/skills/porsche-recovery/SKILL.md)
and existing shared tools. Prioritize functional dependencies; batch native validation,
reuse unchanged proof and delegate independent work. Keep `local/game` read-only.
