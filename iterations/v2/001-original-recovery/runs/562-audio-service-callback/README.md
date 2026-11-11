# Run562: audio service callback child investigation

`004ad950`, a 101-byte string-processing child, passes bounded direct original
x86 comparison. Attempts use original Porsche.exe SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`;
body SHA256 is `9799fa1351b18bda7d713eed1d273852f7b4617e28663eb702718625693582a7`.
REA attempt 003 and its read-only audit pass. The binary index and REA record
the complete indexed body; the Run556 raw callback supplement records its
otherwise unattributed call at `004adbf4`. That call discards EAX.

The child clears object offsets 8..23, copies up to 31 characters after the
first dash, terminates the embedded buffer at +32 and stores the pointer at +4;
on a second dash it stores the following input pointer at +8. The original reads
and writes in order, including input/output overlap. Test attempt 003 compares
96 cases per `/Od` and `/O2`, whole 1024-byte arenas and cdecl stack/nonvolatile
registers; three mutations detect. Cases include empty, one/two dashes, lengths
past 31, four object alignments and input at output buffer start. Original x86
is copied unchanged to an executable test slab. No arbitrary alias/fault,
unbounded input, full FPU, unidentified indirect callers or callback-composition
claim is made. The original leaves EAX as the object address, whereas the C++
return is void. Both indexed and REA-observed call sites immediately replace
EAX, so its value is unused there; see `caller-return-evidence.json`. This is
not game acceptance.

The Run560 manifest census in `scope-evidence.json` covers 770 effective pins,
313 compiled roots and 570 source/header files; it finds no source ownership or
registry body overlap for either child. `004ad8b0` reads canonical root owned by
Run478 and calls `005666f0` and `00567720`. Static tracing now shows that the
initially unwritten local is written by `005665b0` on every normal return: zero
on no match, otherwise a decoded 3- or 4-byte field. The caller consumes it only
for a nonnegative channel. Diagnostic callbacks and faults remain boundaries;
this conclusion has not been native-compared. Full raw instruction evidence and
the next proof packet are in `output-trace-evidence.json` and `PLAN.md`. The main
callback has many other children and remains unaccepted.

REA attempt 001 failed on BOM in the config; 002 hit sandbox `spawn EPERM`;
003 passed outside the sandbox. Native attempt 001 failed to compile because a
local named `sp` conflicted with an assembly register; 002 passed both base
variants but the first detected mutation lacked a flushed diagnostic; 003
corrected the harness and passed. Failed artifacts remain under `local/experiments`.

```powershell
py -3 scripts/research/run-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/562-audio-service-callback/rea-queries.json --attempt 003
py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/562-audio-service-callback/rea-queries.json --attempt 003
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/562-audio-service-callback/native-config.json --attempt 003
```

These commands identify the frozen attempts, not a request to overwrite them.
See `PLAN.md` for the next concrete trace. No shared CMake, registry, original
game files or blocked executable were changed or executed.
