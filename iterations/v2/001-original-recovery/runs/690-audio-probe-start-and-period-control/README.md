# Run690: audio probe start 004a8b80 and period control 00565c70

Original Porsche.exe SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.

- `00565c70..00565cc9` (90B) `application_audio_period_control_00565c70`, cdecl5 void.
  Selector keeps original `AND AL,1F` semantics (`flags & 0xffffff1f`); stores
  arg3/arg4/arg5 dwords at period-cell group base `006b4a08 + selector*16`
  offsets +0/+8/+0xc (group 0 = accepted device state data offsets
  0x148/0x150/0x154), calls the 00590250 boundary, then forwards to the
  accepted Run610 `frame_services_boundary_00565cd0` with arg2 only when the
  captured arg3 was nonzero.
- `004a8b80..004a8ccb` (332B) `application_audio_probe_start_004a8b80`, cdecl0
  void. Signed mode gate on arena word `00657c98` (>2 return); builds
  `<prefix>replay.spl` from the BSS pointer `0065b318` and passes
  `(name, 005d14b0, 0x3c)` to the accepted Run658
  `resource_loadat_quiet_0059db50`; re-copies the prefix pointer (original
  004a8c26 reload), appends `Lil` only when the re-read mode is signed >1,
  appends `fesfx`, and calls the unowned 004a6c90 boundary as `(name, 7)`.

## Sources and data

`application_audio_probe_690.cpp/.hpp`. New cells: `0065b318` char* (BSS,
writer unindexed), literal bytes `005cce90` "replay", `005d1a04` ".spl",
`005d1a14` "fesfx", `005d1a1c` "Lil". Reused: 00565cd0 (Run610), 0059db50
(Run658), device state `006b48c0`, `frame_services_word_005d14b0`. Unowned
typed boundaries: `audio_period_callback_set_00590250` (run558 draft is
unaccepted research, not linked), `application_audio_probe_message_004a6c90`
(caller ignores its EAX). Run558's sparse view arrays are not used; the group
0..2 cells lie inside the accepted device state storage.

## Proof

`py -3 scripts/research/verify-v2-native-batch.py --config
iterations/v2/001-original-recovery/runs/690-audio-probe-start-and-period-control/native-config.json
--attempt 004` → receipt PASS at
`local/experiments/v2-audio-probe-start-and-period-control-690/004/receipt.json`.

- 11667 cases (11520 period-control + 147 probe start), 36690
  recorded endpoint events, identical at `/Od` and `/O2` (`/Oy-`, GS variants
  pinned in the receipt).
- 14/14 material mutations detected with exit 1 + divergence marker: store
  offsets (+0/+8/+0xc), the `|0xe0` fixup mask, callback argument, forward
  branch/value, both mode gates, loadat max/buffer, dropped post-load prefix
  re-copy, spl literal, message kind.
- The raw 00565c70 body's 00565cd0 calls are relocated to the accepted Run610
  body, so the differential also exercises the real send-level chain; 00590250,
  0059db50 and 004a6c90 are controlled recording endpoints on both sides
  (fixture-only; production calls the declared boundaries).

## Boundaries / deferred

- Period selector groups 1..31 and upper-24-bit wild addresses are outside the
  observed caller domain; writes there have no accepted host mapping (run558's
  sparse map remains unaccepted research). Differential domain: observed group
  0 flags `00/20/80/a0/e0`.
- 00590250, 005901b0, 004a6c90 bodies remain unrecovered; the load effect of
  0059db50 is exercised only as a recording endpoint (no live file acceptance).
- Unindexed writers of `0065b318` (004a8660/004a8cd0/004acc10/004affd0 are all
  unrecovered readers) remain open; no live game or audio-device acceptance.
- Attempts 001-003 are preserved failed/setup attempts; 004 is the receipt.
