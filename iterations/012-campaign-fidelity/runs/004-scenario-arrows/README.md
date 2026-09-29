# Run 004: original scenario arrow activation

Started 2026-09-27; integration checkpoint verified. Previous goal turn made concrete progress:
wheel fix, original SCN scale, and EXE evidence recorded in Run 003.

Scope: animdefs triggerable metadata, ordered SCN links, original initial hide
and trigger selection. Resolve first activation against EXE before claiming
original start-frame behavior. Keep mission passage rules/spawn hypotheses
separate from the proven rendering mechanism. Full iteration remains OPEN.

Parser, EXE subtasks and browser acceptance complete; no active assignments.

## Implemented from source evidence

- `animdefs.txt` is now loaded by catalog/custom-file web paths and native track
  loader. ANIM metadata resolves FourCC tags, defaults triggerable=false, and
  preserves the original first-definition fallback for unknown nonzero tags.
- SCN retains ordered Geom/Trigger/unsupported slots, raw trigger parameters,
  version-specific type and signed link fields. A link to a missing, negative,
  non-geometry or non-category-1 target cannot accidentally select another prop.
- Construction hides triggerable instances using the recovered +10000 height
  operation. Supported 0M01 reset selects the first type-2 trigger's linked
  Arrow 1, preserving L A hidden. Gate transitions use source links, and negative
  links preserve the previous selection. Matching uses FourCC and exact X/Z,
  including multiple matches, as in the EXE.
- Render transforms and the existing prop collision positions use the same
  updated height. Read-only WASM telemetry exposes triggerable positions.

The reset ordering is proven under original RACE_TYPE=4; the FE producer of
that value and exact first display callback remain untraced. Mapping the
supported 0M01 mode to this scenario path is explicit. Later progression still
uses the existing reconstructed gate-entry rules; source-linked arrows do not
prove original trigger timing, penalties, spawn, camera or mission completion.
EXE details: [activation evidence](../../research/0m01-arrow-activation.md).

## Checks

- Workspace: 166 Rust tests passed, 3 GPU ignored (`workspace-tests.log`).
- Source-scenario integration passed again after switching Start lookup from
  its display name to the proven type 2 (`source-scenario-test.log`).
- Clippy `-D warnings`, rustfmt and UI state tests passed.
- Windows/WASM release builds passed (`build-release.log`).
- Chromium: 21 checks passed, 0 errors/known failures (`browser-check.json`):
  source Arrow 1 at start, real W input through the first gate to Arrow 2,
  restart back to Arrow 1, plus existing career/Quick Race checks.
- Inspected `web-factory-mission-drive.png`: car/road unobstructed, L A hidden;
  `web-factory-arrow-waypoint.png` records the next arrow. No original-frame
  comparison or complete mission playthrough is claimed.
- Frozen snapshots 001–011 have no tracked changes; local/game remains read-only.

Next concrete step: trace original start-pose setup 0x410430 and later waypoint
dispatch 0x41627b/0x470c98; replace current guessed pose/entry rules with the
recovered behavior, then play through 0M01. UI layout/fonts/layers and full
campaign/participant behavior remain outstanding parts of the full objective.
