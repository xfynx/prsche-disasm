# Run857: wide CRT environment setter

Recovers the complete `005aa039` wide environment setter plus seven directly required table, conversion and wide-string helpers. It reuses Run838's narrow/wide environment storage and allocator providers, owns the previously unbound initial-wide-environment pointer `006afcd4`, and preserves the original insert, replace, remove, copy-on-first-write, conversion and OS-mirroring branches.

Native attempt 005 compares all eight raw original bodies with recovered C++ at `/Od` and `/O2`: 13 setter scenarios and 42 controlled callee/API events per variant, including invalid options, both missing-table paths, initial-table copying, allocation/reallocation failures, narrow-to-wide conversion, insertion, replacement, removal, and ignored `SetEnvironmentVariableW` return behavior. All five material mutations are detected.

The fixture alone redirects `MultiByteToWideChar` and `SetEnvironmentVariableW`; production defaults to the real Kernel32 endpoint. The sole new game-level unresolved boundary is locale-sensitive `crt_wcsnicoll_005ad68c` (`005ad68c`). It remains explicit rather than introducing an ASCII-only approximation.
