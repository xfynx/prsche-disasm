# Run849 route direction

Porsche.exe (SHA in the native config), 004632b6..004632c2 loads a dword
from 00657430 and conditionally negates the route dot product. The binary
index records the read in 00463260. Run835 recovered the branch but declared
a scalar, whereas application_globals.cpp defines a reference into the
application-state arena at byte 0x48. The replacement header uses that ABI.
The other 16 functions retain their Run835 implementations.

Native attempt 001 passed 48 cases per optimization. The fixture writes
through the arena, checks that clearing it clears the flag, and compares route
selection against the original with upper-byte flags. The byte-load and
adjacent-word mutations both diverged. Hardware and gameplay remain open.
