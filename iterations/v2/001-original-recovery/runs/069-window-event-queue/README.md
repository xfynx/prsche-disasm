# Run069 — original window input event ring

Source: immutable `local/game/Porsche.exe`, SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Binary-index query: entries `0053a9e0` and `0053aa60` in `research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl`, callers in `calls.jsonl`, and exact instruction ranges in `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`.

`0053a9e0` is a three-argument cdecl enqueue. It reads the lock and initial write slot before lock entry, writes a 16-bit first argument at slot `+2`, rereads the write cursor, then stores argument 2 at `+1` and argument 3 at `+0`. Records use four-byte stride; the 16-bit write covers both bytes +2 and +3. After incrementing the current write cursor modulo capacity, it advances the read cursor if write catches read. This preserves one empty slot and drops the oldest event on a full ring. The enqueue body does not set a meaningful result in EAX; callers use it for side effects.

`0053aa60` locks the same ring and returns `(payload << 16) | value`. It drains records while the queue is nonempty and the current value is zero. A nonzero signed 16-bit value from record bytes `+2/+3` is returned directly. When that word is zero, it calls `00560080(payload, type)` and uses that result; zero means continue to the next record. The read cursor advances after each consumed record, including records whose translation is zero. The lock is held across translation. The existing global owners provide capacity/read/write/lock; this package owns the previously unowned 128-byte record array at `0069e4e0`.

The differential fixture compares both complete function bodies against original x86, including resulting record bytes/cursors and ordered enter/translate/leave calls. `005322b0/005322c0` and input translation `00560080` are explicit typed boundaries. The translation fixture is deterministic and tests the consumer's handling of zero/nonzero results; it does not claim recovery of the engine's input translation semantics. Capacities are limited to the initialized original range 1–32; divide-by-zero and out-of-range states are not modeled.

The probe covers empty/full ring behavior, overwrite, capacity 1/2/4/32, cursor wrap, untouched nonselected slots, signed stored values, skipped zero translations, and lock ordering.

```powershell
. .\scripts\tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/069-window-event-queue -B local/builds/v2/window-event-queue-069 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/window-event-queue-069 --config Release --target window_event_queue_probe
py -3 scripts/research/verify-v2-window-event-queue.py --report-dir iterations/v2/001-original-recovery/runs/069-window-event-queue
```
