# Camera, route storage and session reset integration

[Build 003](build-003.json) compiled 492 Win32 translation units in eight projects.
The [shared audit](validation.json) passed 109,098 original-x86 comparisons,
34 mutation controls and 1,221 source pins. Four linker names closed. The
transform dispatch and seven session-reset callees are newly reachable, bringing
the frontier from 36 names / 39 references to **40 names / 42 references**.
The game does not yet link. The registry gained six original function addresses.

- [848](../848-camera-transform/README.md) binds the camera wrapper and its two setters.
- [849](../849-view-route-direction/README.md) binds the direction flag to the existing application-state reference.
- [850](../850-view-route-storage/README.md) shares route count and pointer storage with the audio and FE resets, and updates the live camera preset in place.
- [851](../851-session-reset/README.md) binds three reset leaves. The existing Run692/015 receipt covers the startup reset body in Run400. Its registry row now identifies the actual TU and ten callees.

Configure 002 selected a different directory with the same Run400 number.
Its build report lacks the new sources and is excluded from acceptance.
Attempt 003 used the exact Run400 path and a fresh build directory. See the
[build config](build-config.json) and [acceptance config](acceptance.json).
