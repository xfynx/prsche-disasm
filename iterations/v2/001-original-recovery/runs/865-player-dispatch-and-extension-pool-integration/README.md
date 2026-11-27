# Player dispatcher and extension pool

[Build 001](build-001.json) compiles 501 Win32 translation units in eight projects. The [shared audit](validation.json) passed 53,268 comparisons and eleven mutations with 1,243 source pins. The link has **38 unresolved names / 40 references**. No executable was produced.

[Run861](../861-frame-reset-service/README.md) recovers player dispatch, including mutable loop bounds and both mirror tables. Its per-player child at `00410730` is now reachable. [Run864](../864-session-extension-pool/README.md) recovers the reset wrapper, two clears, allocation and release for the ten-record extension pool. The wrapper reaches extension creation at `00406520`. All six entry addresses are present in the automatic index. [Acceptance inputs](acceptance.json)
