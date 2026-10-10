# Run 105 — frame service state save/restore helpers

This run recovers 004ab150..004ab1f7 (168 bytes) and 004ab200..004ab269
(106 bytes), both no-argument cdecl functions, from Porsche.exe, SHA-256
ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
The index shows callers 00415110 and 004152e0; Run 101's 004b0d70 also calls
each helper.

004ab150 returns the gate word 00657c94 immediately if it is nonzero.
Otherwise it calls 004af900(0,0), walks 73 records with an eight-byte stride
starting at 00656180, and calls 00566340(record_word,0) for each record whose
first DWORD is not 0xffffffff. It calls 004ae3c0(0) and tests byte 00656868;
when set, it calls 00565cd0(0,0) and clears adjacent bytes 00656869 and
00656868. It then calls 004ad510, copies the five DWORDs at 00657ca0..00657cb0
from the shared ApplicationStateArena into 005d1740..005d1750, and returns
the value read from 00657cac.

004ab200 has the same early gate. Otherwise it computes the low 32 bits of
005d14b0 * 005d1740 and applies the original signed arithmetic shift right by
seven. It calls 004ae8c0(shifted), then 004ae4d0(0,0), then the existing
00516950 no-op leaf. Finally it copies the five DWORDs at 005d1740..005d1750
back to 00657ca0..00657cb0 and returns the value at 005d1748.

The 73-record table is represented as 146 raw DWORDs; the second DWORD of each
record is preserved without assigning it a meaning. The two adjacent flag
bytes share one exact two-byte owner. The five renderer-state DWORDs are
initialized to their raw .data values (0x7f each), and 005d14b0 to 0x50; the
five application-state words reuse the already shared arena. The x86 oracle
maps these exact states, controls boundary effects, compares every record
DWORD, both flags, both five-word groups, return EAX, ordered call arguments
and stack cleanup, and checks ESI preservation. Seven cases cover both gate
paths, record sentinels, the conditional flag call, positive and negative
shifted products, and the reverse copy.

The internal behavior of 004af900, 00566340, 004ae3c0, 00565cd0, 004ad510,
004ae8c0, and 004ae4d0 remains outside this recovery; they are recorded effect
boundaries. The fixture controls the byte and renderer-word updates consumed
by these bodies and does not claim the services have no other effects. Other
consumers of the shared 005d words and record table remain open.

Standalone build and proof:

    cmake -S iterations/v2/001-original-recovery/runs/105-frame-services -B local/builds/v2/frame-services-105 -A Win32
    cmake --build local/builds/v2/frame-services-105 --config Release
    py -3 scripts/research/verify-v2-frame-services.py --probe local/builds/v2/frame-services-105/bin/Release/frame_services_probe.exe --report-dir iterations/v2/001-original-recovery/runs/105-frame-services
