# Run495: application audio-bank cleanup

Recovered original C++ for004acb80..004acc0c,141B, from Porsche.exe
SHA256ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
The sole indexed caller004b6da5 immediately calls004a88a0 and discards this
function's return/volatile scratch. The proved entry is void cdecl0. Its only
original child is accepted audio_channel_stop_00565d60; no new storage or child
provider is added.

The full487 compiler closure was verified through ManifestReader:650 pins.
Canonical478 owns the exact two adjacent bank cells00656aa8/00656aac; Run400
only declares that same array. No overlapping registered body or duplicate bank
owner exists. Raw instructions, cached469 dossier hash, caller instructions and
ownership evidence are recorded in `original-evidence.json`.

For each nonnull bank, the original captures the object, loads byte+0x2d2,
clears byte+0x40, copies the saved byte to+0x2d3 and sets+0x38/+0x3c to-1
before the first stop call. Those two leading handles are overwritten without
being stopped. It then processes exactly32 record pairs: first+0x45c+12i,
second+0x5dc+12i, with counter+0x44+4i. Both stop guards are `!=-1`, including
other negative handles. The second handle reload follows the first stop; each
counter/first/second reset follows both calls. The current object stays captured
while the next root reloads after callbacks. Unaligned DWORD access uses memcpy;
opaque neighboring bytes remain untouched except for explicit fixture mutations.

Native001 PASS at/Od and/O2:1,512 cases/167,595 events per variant,3,024 cases/
335,190 events total;13/13 meaningful mutations detected through ordinary
differential divergence. All264 input pins match. This first attempt passed;
production, fixture, config and evidence inputs are frozen.

The raw141B function and recovered C++ share actual accepted435 stop/stop_voice,
434 locks/channel lookup/voice iteration, canonical device state and478 bank
storage. Unchanged child proofs are reused. Controlled critical-section and
voice release/finalize callbacks make resets, object capture and pointer reloads
observable. Whole-object/channel/voice/device snapshots, ordered child events,
cdecl preserved registers/stack and x87 CW/SW/tag/all80-bit registers are compared.

Scenes cover inactive device, active device with no channels, and eight initialized
ungrouped voices; null/distinct/identical/overlapping roots including byte-misaligned
objects; zero/-1/other-negative/high-bit handles; root replacement/nulling, second
handle changes, record mutations and live voice-table replacement. x87 precision,
rounding and stack depth vary across cases. Mutations detect wrong bytes, leading
reset timing, signed guards, stale roots/handles, offsets/strides/counts and resets
before calls.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/495-application-audio-bank-cleanup/native-config.json --attempt 001
```

Receipt:`local/experiments/v2-application-audio-bank-cleanup-495/001/receipt.json`.
Coordinator owns registry/CMake/shared acceptance. Real resource producers,
grouped/multivoice parent composition, actual release/finalize/platform effects,
unmapped pointers, lifetime faults, concurrency and startup/gameplay remain open.
Fixture-only unused-path bindings fail closed and never enter the game graph.
