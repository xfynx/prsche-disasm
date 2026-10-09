# Run043 — keyboard detection and joystick startup enumeration

Original: `Porsche.exe` SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Index query: `rg '004a5410|00564e70|00564ab0|00564850|00565030|0055fcf0' research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d -g '*.jsonl'`. Startup caller `004a5410` calls `00564e70`, `00564ab0`, and thunk `00564850` in that order at `004a5472`, `004a5477`, and `004a547e`. Bodies were checked in `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`: caller `004a5410..004a54ac`, keyboard check `00564e70..00564ea6`, joystick enumeration `00564ab0..00564af5`, thunk `00564850..00564854`.

`00564e70` queries `GetKeyboardType(0)` and only on return 7 queries type 1. Values `0x0d01..0x0d04` inclusive set global `0069e5a0` to `005df934` and return 1; all other tested paths return 0 without changing that global. `00564ab0` sets `005deac4=1`, stores `joyGetNumDevs()` in signed global `006a5bf4`, and for a positive count calls `joyGetDevCapsA(id, stack_scratch, 0x194)` for each `id` from zero to count minus one. The API status and JOYCAPS bytes do not affect persistent state in this body. `00564850` is a tail jump to `00564ab0`.

The native probe composes these recovered functions and supplies only `GetKeyboardType`, `joyGetNumDevs`, and `joyGetDevCapsA` fixtures. The verifier executes all three original x86 entries with those API callsites intercepted, comparing the return/global state and ordered API arguments across six cases. JOYCAPS scratch bytes are zero-filled in both fixtures; no game-side joystick device behavior is claimed. The broader capacity routine `00565030` and DirectInput/event initializer `0055fcf0` remain separate recovery work because their timer, device-interface, and event callees are outside this bounded slice.

Reproduce on x86 MSVC:

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/043-startup-subsystems -B local/builds/v2/001-original-recovery/startup-subsystems-043 -G 'Visual Studio 17 2022' -A Win32
cmake --build local/builds/v2/001-original-recovery/startup-subsystems-043 --config Release --target startup_subsystems_probe
py -3 scripts/research/verify-v2-startup-subsystems.py
```

`verification.json` pins the source/probe hashes and original module SHA. This package verifies these secondary input-startup routines and their API boundaries, not a complete `004a5410` startup or game launch.
