# Run540 texture cleanup and scalar reader

Confirmed scope:554cc0 full170B and56e290 full24B. Coordinator continues after
worker usage limit; no respawn.539 build001 effective737 pins verified;
301 compiled roots yield545 source/header files with no canonical body overlap.
537 owns32x48B slots and is reused. New state is006a3a40 loader-zero DWORD;
exact30B diagnostic file and48B message have direct original consumers.
531f90 is existing canonical free_00531f90 inheap.cpp, no new child provider.

Confirmed reader semantics: unconditional4B read,BSWAP thenSHR CL; shift count
wraps and masks31. Count0 is not a no-read case. Cleanup unlinks head/interior,
decrements slot/total counts, frees live+14/+1c fields and texture in order;
missing node reports canonical diagnostics without decrement/free.

Production and frozen002native proof are ready. Shared verify-v2-native-batch.py reuses537/536
ABI/x87/relocation oracle helpers; actual537format/destructor composition,
direct reader fullDWORD counts/guard-page read bounds, callback-mutating frees,
slots0..31/finite lists and alias cases. Keep failed attempts. No AV bypass,
renaming/retry/exclusion of blocked537005. Only this run/local540 helpers writable.

001 fixture compile used a nonexistent getter suffix; failed inputs retained in
local001-inputs.002 production unchanged, bothOd/O2 pass220188cases/451840events
each;all17mutation controls detected. Shared receipt audit verifies264inputs/
281outputs. No unrelated537749k regression repeated. Passed inputs immutable.
Coordinator owns next542shared intake of540only;541scope remains unaccepted.
