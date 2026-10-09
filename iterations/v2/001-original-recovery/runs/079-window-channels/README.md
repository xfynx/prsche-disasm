# Run 079 — keyboard lock-channel setup

This run reconstructs `005739b0` from the original `Porsche.exe` binary
(SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`)
and compares the native x86 C++ implementation against Unicorn execution of
the original function.

The binary index locates a 129-byte function at `005739b0..00573a30` and three
calls from `window_create_0053bb00` at `0053bc87`, `0053bc90`, and `0053bc99`.
Each caller pushes a zero desired state followed by channel 0, 1, or 2; the
cdecl entry therefore receives `(channel, desired_toggle_state)`. The function
maps those channel values to Caps Lock (`VK_CAPITAL=0x14`, scan `0x3a`), Num
Lock (`VK_NUMLOCK=0x90`, scan `0x45`), and Scroll Lock (`VK_SCROLL=0x91`, scan
`0x46`). Other channel values return without querying USER32.

At `00573a01`, the original calls `GetKeyState` for the selected virtual key
and compares its low toggle bit with the full second argument. Equal values
return without events. On mismatch, `00573a22` and `00573a29` call
`keybd_event` with the mapped key and scan code, first keydown then keyup;
Num Lock sets `KEYEVENTF_EXTENDEDKEY` on both events. The recovered routine is
cdecl and keeps USER32 as explicit typed API boundaries.

The verifier exercises 120 combinations: every valid and several invalid
channels, desired values 0/1 plus non-boolean values, and signed/unsigned
`GetKeyState` results. It compares the queried virtual key and ordered event
arguments between the original x86 function and the native C++ probe. Unicorn
hooks only the two imported USER32 APIs, using their x86 stdcall stack cleanup.
This does not execute real keyboard input or claim a GUI launch check.

Run077's separate startup fixture uses `0053c290` only at the zero-fill call
site `0053222a`. Run068 established that nonzero values repeat a DWORD pattern,
so the Run077 host boundary accepts only value zero; its `memset` use is
equivalent for that proven startup input only. This run does not generalize
that fixture boundary into a recovered implementation of `0053c290`.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/079-window-channels `
  -B local/builds/v2/001-original-recovery/window-channels-079 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/001-original-recovery/window-channels-079 --config Release
py -3 scripts/research/verify-v2-window-channels.py
```
