# Run476: original packed sample converter

Recovered C++ for Porsche.exe0059bce0..0059bd1d,62 original bytes;
SHA256ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
No new storage or dependencies. The indexed sole caller00598940 pushes
destination/source/count and ignores the result; raw post-call instructions
replace CL/EDX and flags before use. Original volatile-register preservation
does not impose an additional consumer contract. Production is ordinary C++.

The recovered loop reads two unaligned DWORD pairs before either store,
interleaves second-plane then first-plane16-bit samples, and traverses backwards.
Address arithmetic wraps32bits. The first iteration is unconditional; signed
pre-subtract count>2 reproduces the original SUB2/JG condition, including overflow.
There is no guessed count guard or inferred buffer-capacity restriction.

Native001 PASS at/Od and/O2:4,500 cases each,9,000 total; seven detected mutations.
Tests compare the complete8KB arena, cdecl ESP/EBP/EBX/ESI/EDI and preserved x87
CW/SW/tag/all80-bit registers. They vary25 counts,15 destination offsets, three
patterns and four source alignments. Counts include normal/odd/zero and bounded
wrapping nonpositive probes; offsets cover separate/in-place/forward/backward
overlap and byte misalignment. x87precision/rounding/depth vary across cases.
The tests do not require unused volatile EAX/ECX/EDX or flags to match.

`original-evidence.json` records the binary-index queries,31 raw instructions,
body hash, ABI, caller and full472 ManifestReader ownership check:626 verified
pins, no compiler-source/header owner. Registered indexed body ranges also have
no overlap. CachedREA465002 parent navigation was reused; no new session.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/476-audio-sample-converter/native-config.json --attempt 001
```

Receipt:`local/experiments/v2-audio-sample-converter-476/001/receipt.json`.
Native inputs are frozen. Coordinator owns registry/CMake/shared integration.
Actual473+475+476 composition, unmapped/null faults, concurrent memory access,
live PCM/devices and startup/gameplay remain unverified. Edge probes establish
mapped original behavior; they do not establish production caller validity.
