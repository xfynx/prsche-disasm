# Run110 — missing clock-worker entry

Search: `006b7c40` writes in the original index and full disassembly. The only
direct increment is inside omitted entry `00565270..0056533e`,207 bytes.
Porsche.exe SHA is pinned by the script/report and supplementary index.
`00565030` pushes this callback at00565135 into0055f420 at0056513a.
The complete contiguous instruction bytes and terminal RET match the original.
This adds a navigation record, not a recovered C++ function.

The worker reads GetTickCount through IAT005b2080, creates/waits/closes an event,
increments006b7c40/006b7c7c once per enabled iteration, and calls eight nullable
zero-argument callbacks at006b7c20..006b7c3f. A wrapped32-bit accumulator uses
raw multiplier1193 and signed carry through SAR16 into006b7c44. No semantic
unit beyond the imported tick source is inferred here.

Next: recover this worker together with setup00565030, cleanup00564fa0,
thread producer0055f420 and timer producer. The pending WM_CLOSE terminal-path
check stays open; manually incrementing the tick in a fixture would not prove
the original producer. Reuse canonical current_tick006b7c40 and
timer_rate005deb48 owners when implementing; don't create duplicate cells.

```powershell
py -3 scripts/research/index-v2-clock-worker.py --update-index
py -3 scripts/research/v2_manual_index.py
```
