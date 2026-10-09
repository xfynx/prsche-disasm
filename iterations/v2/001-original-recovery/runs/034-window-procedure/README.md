# Run034 - original window procedure and binary search

Original Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
Queries: WNDCLASSA lpfnWndProc at53ac94 ->53aba0; its bsearch comparator53a7f0
and static CRT bsearch5a2f23. Two missing automatic function bodies added to
SHA-guarded manual index:53a7f0..53a7fe (15 bytes),53aba0..53ac1c (125 bytes).
Original dispatch invokes sorted 8-byte entries with six stdcall arguments,
initial zero output, and falls back to DefWindowProcA when absent/unhandled.
Comparator preserves SUB overflow; search preserves lower-middle choice.

329 MSVC Win32/native versus original x86 cases match, including count0..128,
found/missing keys, handled/unhandled callbacks and signed wraparound keys.
Original comparator and binary search execute directly in the x86 fixture;
only handler bodies and DefWindowProcA are typed recording endpoints.
Native configuration pointer must be supplied by the shared state owner; this
module deliberately does not invent a second copy of original window BSS.

Build isolated CMake run034 with Win32; execute
`py -3 scripts/research/verify-v2-window-procedure.py`.
No actual game handlers/rendering or original full startup acceptance claimed.
