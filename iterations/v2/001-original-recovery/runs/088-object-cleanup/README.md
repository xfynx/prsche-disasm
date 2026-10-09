# Run 088 — renderer object cleanup consumers

Original: `Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The index reports `00557990` (100 bytes), called only by `00558350`, and
`00558c80` (45 bytes), called twice by `00557990`. `00558c80` reaches
`005588a0` (118 bytes) only when the configuration's `+0x43c` object equals
the supplied handle. That updater changes clock/lock state and calls
`GetTickCount`; it remains a typed boundary here.

`00557990` reads configuration `+0x448` and `+0x44c` as optional handles.
When `+0x448` is nonzero, it invokes the primary object's vtable `+0x28` if
configuration `+0` is nonzero. It clears `+0x454`, then `+0x450`, calls
`00558c80(configuration, +0x44c)` followed by
`00558c80(configuration, +0x448)` for nonzero handles, and clears `+0x44c`
then `+0x448`. The two configuration arguments are cdecl. Both indirect
one-pointer object methods (`vtable+0x28` and `vtable+8`) are stdcall, as
shown by their stack arguments being callee-cleaned in the original callers.
`00558c80` substitutes the canonical configuration at `006b77a0` for a null
first argument, conditionally calls `005588a0`, then invokes the handle's
vtable `+8` method. Offsets are byte-level observations; semantic ownership
of their objects is not inferred here. The conditional `005588a0` boundary
reads/writes configuration `+0x43c/+0x440/+0x444`, runtime words
`006a3afc/006a3b00/006a3b04`, and lock pointer `006a57d8`; it calls
`KERNEL32.GetTickCount`, vtable `+0x80` with two stdcall arguments, and the
shared lock-leave routine. Those effects remain outside this run.

The isolated MSVC Win32 probe compares state words and ordered callbacks with
Unicorn execution for empty handles, two handles with one updater match, and
the null-configuration fallback. The updater and both vtable implementations
are explicit no-effect recording boundaries; their effects are not part of
the equality claim. This verifies the bounded consumer control flow and
argument order, not downstream object destruction, updater timing, or a game
launch.

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/088-object-cleanup `
  -B local/builds/v2/001-original-recovery/object-cleanup-088 `
  -G 'Visual Studio 17 2022' -A Win32
cmake --build local/builds/v2/001-original-recovery/object-cleanup-088 `
  --config Release
py -3 scripts/research/verify-v2-object-cleanup.py
```
