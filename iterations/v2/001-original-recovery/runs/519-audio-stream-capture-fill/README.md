# Run519: capture fill

Native003 PASS, frozen:3 originals427B/26B state. `/Od` and `/O2` each pass
6,854 cases/24,378 events;12 mutations detected. Total13,708 cases/48,756 events.
Bodies:58acf0(112B),58f410(284B),598a50(31B). Full516 owner scan510 files and
PE-loader zero initializers are pinned in `original-evidence.json`.

Real513 worker->519 read/poll/forward-copy composition checks HRESULT==0,
stdcall3/8/5, captured/reloaded objects/counters, copy/metadata aliases and
reported Unlock length. Failed COM outputs stay opaque/unused. Stack read cursor
is slot0 after saved-register adjustment; distinct capture cursor is slot3.
Forward DWORD/byte order, overlap, masked shifts and destination-bit returns match.
Canonical WORD6b4860 preserves AND-FFFF semantics; raw DWORD transport varies
masked high bits without duplicating513's BYTE62. Cross-owner aliases stay open.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/519-audio-stream-capture-fill/native-config.json --attempt 3
```

Receipt: `local/experiments/v2-audio-stream-capture-fill-519/003/receipt.json`.
001 fixture declaration failure and002 corrected read-cursor-slot inputs remain
preserved. Only frontier:597660 void cdecl2(input,output). DSP semantics, zero
divisor/unwritten-success outputs, cross-owner/stack destination aliases, full
producer/lifetime, faults/concurrency and live COM/audio/game remain open.
