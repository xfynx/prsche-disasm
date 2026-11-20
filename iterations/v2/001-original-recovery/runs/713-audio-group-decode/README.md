# Run713: audio group decode (Run710 typed child)

The unowned 205-byte typed child `00590a80` newly exposed by integrated Run710
is recovered as a full original body. The declaration matches the accepted
Run710 caller (`audio_reverb_children_710.hpp`) byte for byte:

```cpp
std::int32_t __cdecl audio_group_decode_00590a80(const void* source,
    const void* ctx, void* scratch);
```

`00590a80..00590b4c` advances the source pointer by 4 or 8 bytes according to
`source[3]&2`, loops canonical `00599100` (Run451 audio record decoder) and
unowned `00599610` (process/reload), then dispatches the signed `record[0x17]`
entries to the signed-byte-counted callback table at device state + 0x120,
reloading both counts from raw state each pass. The outer loop follows the
decoder's non-zero "more" flag; the return is the reload child's EAX (8 in the
original). Body SHA-256 `8845ef3770ea55e96b71b14781f43cf33f0e99dcc5c7830fb69647a314ff156c`.

## Evidence

Raw PE `.text` bytes and SHA-256 pinned; single caller is accepted `005900b0`
(CALL rel at caller offset 0x50). `functions.json` (1166 entries) has no
`entry_va` 00590a80 and no overlapping `body_ranges`; the next owned body
`00590b50` (Run448) starts three bytes after this body's RET. Relocations:
`e8` to 00599100 (body offset 0x32) and 00599610 (0x4e), two absolute
`MOV DL,[0x006b49a2]` (0x62/0x9a) and one `MOV EDI,0x006b49e0` (0x8e).
`006b49a2`/`006b49e0` are interior cells of the canonical loader-zero
`.data` owner `006b48c0` (offsets 0xe2/0x120); no new owned cells. Canonical
00599100 is reused by typed binding only; 00599610 and its callees stay
unowned. Run710/705 cells are untouched. Full detail in `scope-evidence.json`
and `evidence.json`.

## Proof

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/713-audio-group-decode/native-config.json --attempt 001
```

Receipt PASS: `local/experiments/v2-audio-group-decode-713/001/receipt.json`.
60 measured cases per variant at `/Od` and `/O2`; 10/10 material mutation
controls detected; 221 input pins, 149 output pins. The fixture executes the
raw body from immutable PE bytes with both relative calls and both absolute
data references relocated to controlled endpoints, and compares callee order,
callback payload/slot/count reload, record bytes, return value and
ESP/EBP/EBX/ESI/EDI.

## Boundaries

Source flag bytes {0, 2, 3, 0xff}, 1..3 decode iterations, callback counts
0..4 plus one callback-driven count reload, record counts 1..4 and four
callback slots. Record bytes left unwritten by the decoder stay opaque. Real
00599100/00599610 interiors, live callbacks/devices, NaN/fault/concurrency
domains, full game integration and CMake/registry acceptance remain open. No
graph integration is claimed by this batch.
