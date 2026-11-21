# Run719: audio group flag/cursor step

Recovers full `0058a970..0058aa58` (233 bytes), called twice by Run715's
`00599610` worker loop. Exact declaration:
`std::uint32_t __cdecl audio_group_step_0058a970(std::uint32_t*, const void*)`.
The COFF symbol is `?audio_group_step_0058a970@porsche@@YAIPAIPBX@Z`.

The original reads byte count `006b48e7`, compares its input cursor as signed,
and scans flag bytes at `006b48e8+cursor`. Record byte `+0x18` intersects the
`0x1c`, `0xe0` and conditional `0x03` categories. Missing required intersections
skip a row; record byte `+3 != 1` also rejects results containing `0xc0`.
Both skips and success increment the cursor. Exhaustion returns zero; success
returns the combined selected bits. The implementation retains the signed
entry/loop comparisons and unsigned cursor increment arithmetic.

Source is immutable `Porsche.exe` SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`;
body SHA-256 `b80743655e9478efe6fca1594c457a097a21ab6d9b88901741b0c1be05638656`.
Index query `0058a970` yields the complete body; raw bytes, both RET exits,
caller and two absolute references are pinned in `scope-evidence.json` and
`original-listing.asm`. Registry/main-index body ranges have zero overlaps.
Canonical `application_audio_device.cpp` storage supplies offsets `0x27/0x28`;
the actual owner TU is compiled in the fixture. Its unused backend edges fail
closed. Zero new cells and no child calls.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/719-audio-group-step/native-config.json --attempt 001
```

Receipt PASS: `local/experiments/v2-audio-group-step-719/001/receipt.json`.
136,352 cases at each of `/Od` and `/O2`, 13/13 material mutation controls,
238 input pins and 197 output pins. The complete 256-by-256 flag/mask product
runs for both gate forms (131,072 cases); 5,280 extended cases cover count
0..255, signed negative cursors -1/-2 within owner storage, INT_MAX/at-end exits,
skipped prefixes, patterned tables and record gate bytes 0/1/2/0x81/0xff.
Return/cursor, all 396 backing bytes, 64 record bytes, cursor canaries and
ESP/EBP/EBX/ESI/EDI match. The first 296 original state bytes are checked against
raw PE/loader-zero bytes before any fixture reset. No failed attempt.

The record, cursor and canonical storage are disjoint and stable. Global aliases,
invalid-memory fault parity, concurrency, actual Run715 composition, live audio
and game startup remain open. Shared CMake/registry/build acceptance belongs to
the coordinator. Passed proof inputs are frozen; `prepare.py` is initial evidence
generation and must not overwrite accepted inputs.
