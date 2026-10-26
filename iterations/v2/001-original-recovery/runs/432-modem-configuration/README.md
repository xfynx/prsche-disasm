# Run432: modem configuration

Three original bodies,289B: configuration0055e340 and lazy GetDevConfig00584c05 /
SetDevConfig00584e27. Final native003 PASS:100,968 cases across `/Od` and `/O2`,
12 detected mutations. Passed production sources, fixture and config are frozen.
Integration belongs to Run433; this batch does not claim a linked or playable game.

The143B configuration body ignores its caller's line argument and uses canonical
005df478, including the reload after getter success. Its8000-byte local is zeroed;
needed/total comparison is unsigned; flags at config+0x5c lose exactly bits0..2;
size is reread after the flags store; setter nonzero normalizes to1. Header alias
cases detect that order. Wrappers preserve initial resolver error bits, failure
sentinel, repeated calls, stdcall argument order, returns and callee-save/stack ABI.

[Evidence](evidence.json) records SHA, full ranges, original data and boundaries.
[Ownership](ownership.json) searches393 paths in the complete accepted413 closure:
selected005df478 remains in403, resolver00584a60 remains in411; only caches006ad168 /
006ad2a0 are new, with original PE zero-fill evidence. Native fixtures link actual
403/401/374 owners. [COFF](coff-evidence.json) confirms the new providers and original
410 caller/411 resolver types. Controlled resolver and unused fail-closed endpoints
are fixture code only. The raw47B stackprobe is an oracle dependency, not new recovery.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/432-modem-configuration/native-config.json --attempt 003
```

The existing003 directory is immutable. Its receipt is
`local/experiments/v2-modem-configuration-native-432/003/receipt.json`.
001 preserves a missing fixture-dependency link failure.002 passed but extracted
14 class bytes without the terminating NUL; final003 uses the verified15B span.
All current source/config/fixture bytes were UTF-8 LF before003 proof.

Malformed header sizes, unaligned offsets and wrapping offsets whose flags DWORD
stays in the physical local are covered, including an untouched zero getter output.
Outside-local accesses, stack-fault/cookie equivalence, real API dereference of
malformed pointers/sizes, null proc faults, concurrency and live DLL/TAPI/device
composition remain unverified. No bounds checks or guessed semantics were added.
Existing403/411 partial domains and startup/display/gameplay acceptance remain open.
