# Run489: original pixel conversion and consumed-AL adapter

One new complete original body,267B at00468110..0046821a. Porsche.exe SHA256:
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Cached469, the matching Ghidra index and exact original bytes are reused.
No new REA session, child original, palette or original data owner is added.

This function returns a **U32 converted color in EAX**, not a bool comparator.
Formats3/11 extract5/5/5 components;4 extracts5/6/5. Their original MUL-high,
unsigned correction, bias and shift sequences scale each component to8 bits.
The implementation retains that arithmetic; bit replication is not equivalent.
Only these three formats special-case a whole-DWORD zero pixel to zero. For
nonzero input they pack opaque alpha, including cases whose extracted channels
are all zero. Formats5/6 return `pixel|ff000000`; every other format returns the
entire input pixel unchanged. No format high-bit mask or guessed default exists.

The only indexed caller is4677e0 at467e02, immediately followed by TEST AL.
Its legacy `render_display_compare_pixel_00468110` name is an explicit used-AL
adapter: `(render_pixel_convert_00468110(pixel,format)&255)!=0`. It preserves
the constructor's observed truth while the canonical core preserves full EAX.
For example,3/00000400 converts toff080000 yet the caller's truth is false.
No indexed full-EAX user is silently bound to the bool adapter.

The raw36B switch table0046821c has nine exact targets, all within the267B
body. The indexed incoming reference is its own dispatch only. It is represented
as proved branch mapping, with no duplicate readonly storage in production.
`original-evidence.json` records original instructions, hashes, all indexed
caller/references, format transport and a643-pin483 source/header closure plus
pending484/485/486 source ownership review. `ownership-review.json` records
the absence of a prior registry owner or known external table-identity consumer.

Native001 PASS at `/Od` and `/O2`: **6,818,432 cases /171,456 endpoint events
per variant**,13,636,864 comparisons /342,912 events total. All15 mutations
detected. There were no failed attempts. Source/header/fixture/config/evidence
are frozen; all301 input pins and281 output hashes were rechecked.

Each variant has6,815,744 direct input cases: exhaustive low16 bits under four
high prefixes for17 formats, every high16 value with two low patterns, and
131,072 deterministic U32 patterns. These compare full native EAX, every packed
channel/alpha and the bool adapter's exact0/1 AL against native consumed-AL
truth. They cover whole-DWORD zero distinctions, all packed component values,
format aliases, default/high-bit formats, alpha and the original rounding.
ESP/EBP/EBX/ESI/EDI are checked for raw/canonical/adapter cdecl2 calls. Occupied
80-bit x87 values, control/status/tag remain unchanged across varied PC/RC/depth.
Incidental volatile flags/registers and caller stack residue are not outputs.

The remaining2,688 scenes freshly compose the accepted484 constructor/helpers
with this actual conversion on both sides. A derived489 fixture patches the raw
caller to the real raw267B body and links the real C++ core/adapter; the old
recording pixel endpoint fails closed. The original table and its operand are
checked before oracle relocation. Existing matrix/surface/vertex/receiver
recording and terminal boundaries are retained. Balanced zero/nonzero pixel
patterns additionally exercise the constructor's equal-count branch with real
AL truth. The descriptor+8 format comes from THRASH getstate(1d); no producer
enum/default or palette behavior is invented. The format stays stable during
these controlled readback scenes.

Mutations cover both extraction layouts, masks, both biases/shifts, alpha, zero
shortcuts, default/high-bit dispatch, blue bits and using full EAX as bool.
Fresh parent composition adds proof for the changed child; frozen484 source,
fixture, receipt and every native input remain unchanged. Unchanged direct484
helper sweeps are not rerun. `coff.json` records two actual strong exports;
`/O2` has no undefined symbols. `/Od` uses only compiler-runtime `__aullshr`,
not a newly discovered original child.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/489-render-pixel-compare/native-config.json --attempt 1
```

Receipt: `local/experiments/v2-render-pixel-compare-489/001/receipt.json`.
Coordinator owns registry/CMake/shared acceptance. Actual THRASH/graphics, format
provider changes during readback, callback identity execution, faults/unmasked
FP/concurrency and full startup/display/gameplay remain open. The unrelated
005de680 descriptor owner overlap stays deferred; no frozen packet is enlarged.
