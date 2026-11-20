# Run697: audio period callback 00590250 and probe message 004a6c90

Original Porsche.exe SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Both targets are the unowned typed boundaries declared in accepted Run690
(`application_audio_probe_690.hpp/.cpp`); their declarations are reproduced verbatim
in `audio_period_callback_probe_697.hpp` so this TU now defines them.

## Bodies and ABI

- `00590250..00590287` (56B) `application_audio_period_callback_set_00590250`,
  `std::int32_t __cdecl(std::uint32_t flags)` — one stack argument at `[ESP+4]`,
  plain `RET`, `EAX=0`. The `(uint,uint)` pair in the task note is the *callee*
  `005901b0(flags, period_value)`, not 00590250's own signature (verified from the
  one-argument prologue and the accepted Run690 callsite/mutation). Semantics:
  `selector = flags & 0xffffff1f` (`AND AL,0x1f` preserves upper 24 bits); store
  `CL` at `[0x6b4886+selector]`; store constant `0x005901b0` at `0x6b4898`; when
  byte `0x6b499c` is nonzero, read `[0x6b4a08+selector*16]` and call
  `005901b0(flags, period)`.
- `004a6c90..004a6d3f` (176B) `application_audio_probe_message_004a6c90`,
  `void __cdecl(const char* text, std::uint32_t kind)` — caller ignores EAX, so the
  accepted `void` declaration is kept. Builds `<text>.bnk` in a 0x50-byte local,
  opens via `0059d9b0(name, 0x10)`, reports `005a177b(format, buffer)` on a null
  handle, else runs `0059dd00(name)` and the four-argument tail
  `004a6bc0(text, bank_result, handle, kind)` (four stack args confirmed from the
  callee prologue and the caller's reused argument area).

## Ownership decisions

- New cells owned only here: `005d1444` (40B, `"AudioCmn_LoadBank(): DID NOT LOAD '%s'\n"`)
  and `005d146c` (5B, `".bnk"`); raw bytes pinned before relocation.
- Reused canonical state, not redefined: `006b499c` (400 active byte / device +0xdc),
  `006b4886` (462 notify kind), `006b4898` (455 device callback),
  `006b4a08` (462 notify value / device +0x148).
- Reused accepted providers: `0059d9b0` (Run649 `resource_open_quiet_0059d9b0`),
  `0059dd00` (`resource_predicate_0059dd00`), `005a177b` (existing declared
  `render_display_texture_report_005a177b` boundary).
- Unowned typed boundaries, no invented bodies/callbacks: `005901b0`, `004a6bc0`.
  These are new frontier names for integration.

## Proof

`py -3 scripts/research/verify-v2-native-batch.py --config
iterations/v2/001-original-recovery/runs/697-audio-period-callback-and-probe-message/native-config.json
--attempt 004` → PASS at
`local/experiments/v2-audio-period-callback-and-probe-message-697/004/receipt.json`.

- 1,280 measured cases / 3,200 recorded endpoint events at both `/Od` and `/O2`
  (identical output SHA `1096f0d6…`) — 256 period-callback cases (observed flags
  group 0, active gate, period dword, endpoint effects) + 1,024 probe-message
  cases (8 text inputs, both handle branches, four predicate values, four kinds).
- 16/16 material mutations detected with exit 1 + divergence marker: notify byte,
  callback store/constant, active gate, period offset/args/return/call, suffix,
  open flags, handle gate, diagnostic format, predicate name, finalize kind/text/call.
- Raw original body/literal SHA and initial canonical cell state asserted before
  relocation; synthetic callsite setup/RET and all endpoint recording are fixture
  code only. Two new frontier boundaries are controlled recording endpoints.

## Boundaries / deferred

- `00590250` selector != 0 / upper-24-bit wild addresses have no accepted host
  mapping (same boundary as Run690 period groups 1..31); proof domain is observed
  group 0 only.
- `004a6c90` 0x50-byte local has no original bounds check; proof text inputs fit
  with the 4-byte suffix. Real file/device effects, bank registration and the
  `005901b0`/`004a6bc0` bodies remain unrecovered.
- Attempts 001–003 are preserved failed/setup attempts (001 wrong 5-byte string
  SHA; 002 undetected diagnostic mutation from a harness knob reset; 003 raw
  stack-buffer pointer recorded as an event arg); 004 is the receipt. No accepted
  input was rewritten after the PASS.

## Changed files

New run directory only: `audio_period_callback_probe_697.{hpp,cpp}`,
`native-fixture.cpp.in`, `native-config.json`, `scope-evidence.json`, `README.md`.
No registry, CMake, shared manifest, plan, doc, script or other run was modified;
`local/game` remains read-only.
