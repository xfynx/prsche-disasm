# Run468: fixed angular vector and quarter lookup

Porsche.exe00597f80..00598011 (146B) and0059b630..0059b689 (90B)
form a closed2-body graph. Raw257-WORD quarter table005e3924..005e3b25
is copied exactly, retains original writability and has no competing owner in
Run467's complete compiler closure. Two original readonly scalar words are
copied bit-exactly. New original storage522B, no regenerated sin/cos table.
original-evidence.json records raw SHA/ranges, references, sections and ownership.

Native001 passes first attempt:6,474 cases at each /Od and/O2 (12,948 total),
14 detected mutation controls. All1,024 phase indices with two high-bit prefixes,
4,096 direction/elevation pairs,324 x87 precision/rounding/depth edge scenes,
and6 table-output alias scenes compare full output/table bytes, CW/SW/tag,
80-bit register data and preserved cdecl ABI. Original table/scalar bytes are
asserted before fixture reset. Relocated code is raw original bytes; synthetic
carriers supply the cdecl calls and scratch stack. No controlled child replaces
the lookup: raw vector calls raw lookup; recovered vector calls recovered lookup.

Original argument cells are scratch; both known callers discard them and the
vector's incidental volatile EAX. Output writes precede the last lookup, including
when they alter a later table entry. The lookup returns zero-extended WORD values
with quadrant sign and only uses low10 phase bits. x87 intermediate float stores
and operation order are retained in a small assembly island; indexing/control
remain C++. This establishes behavior, not byte-identical recompiled functions.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/468-audio-fixed-vector/native-config.json --attempt 001
```

Attempt001 is immutable. Unmapped output pointers, arbitrary table writers,
concurrency/live audio and full462 consumer/startup/game composition remain open.
REA465002 owns vector navigation; cached469001 owns lookup navigation. COFF and
rechecked input/receipt hashes are recorded beside this README.
