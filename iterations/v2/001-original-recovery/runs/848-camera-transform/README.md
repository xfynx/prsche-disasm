# Run848 camera transform wrapper

Run835's camera transform at 004618b0 reaches 00532a40. The wrapper saves
the matrix and destination stride, sets the stride to 12, calls 0055a930 in
mode 2 and restores the matrix followed by the stride. Setters 00559a40
and 00559ab0 preserve and return the previous values. A null matrix or zero
stride invalidates the cached mode; setting a non-null matrix marks it dirty.
The original cached mode and stride are -1 and 32; the matrix and dirty
word occupy loader-zero state. See [Run845](../845-transform-vectors-trace/README.md)
for the original ranges, data and PACODE branches.

[Native attempt 002](native-config.json) passed 46,848 comparisons per
optimization, including 46,080 wrapper calls, and detected seven mutations.
Attempt 001 hit WinError740 starting a mutation executable; the production
source was unchanged for attempt 002. The dispatch endpoint is controlled
in the fixture and unresolved in the game. Its x87, SSE and 3DNow kernels
remain open.
