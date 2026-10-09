# Run046 — DirectInput startup chain

Original: `Porsche.exe` SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Index query: `rg '004a546d|0055fcf0|0055fe00|0055fe50|0053bf90|00557380|00557460' research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/references.jsonl`. Startup caller `004a5410` invokes `0055fcf0` at `004a546d`, followed by keyboard detection and joystick enumeration. The connected bodies were checked in `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm` and `decompiled.c`.

The package recovers the DirectInput initialization, keyboard ring reset, one-time exit registration, COM failure cleanup, `0055fe00` release helper, `0055fe40` exit callback, `0055fe50` state setter, `0053bf90` ring reset, and `00557460` window-handle getter. The source uses the already-owned window state storage for accelerator, input ring, class lock, and HWND. DirectInput GUIDs and keyboard data format were reconstructed from original data at `005bf970`, `005bf9b0`, `005bf8c0`, `0056f9e0`, and `0056e9e0`.

Eight deterministic x86/native cases compare a full 64 KiB COM/vtable arena, input and shared window globals, return value, and ordered API/COM/callback calls across successful setup, each COM failure stage, repeated startup, and exit cleanup. GetModuleHandleA, DirectInputCreateA, COM methods, and callback registry insertion are explicit fixtures; the verifier checks method slots, arguments, return-driven cleanup, and persistent state. It does not claim physical keyboard/device behavior or a full game launch. `0056e940` is exercised as the DirectInputCreateA import thunk, while callback-list internals at `005a2400` remain the stated recording boundary.

Reproduce with x86 MSVC:

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/046-startup-input -B local/builds/v2/001-original-recovery/startup-input-046 -G 'Visual Studio 17 2022' -A Win32
cmake --build local/builds/v2/001-original-recovery/startup-input-046 --config Release --target startup_input_probe
py -3 scripts/research/verify-v2-startup-input.py
```

`verification.json` pins original SHA, probe/source/header hashes, fixture inputs, and comparison results.
