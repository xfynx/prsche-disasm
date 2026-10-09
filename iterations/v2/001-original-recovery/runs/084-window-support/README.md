# Run084 — window support helpers

Original: `Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index evidence is in `research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/`;
the instruction bodies are in `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`.

`0053a8e0` is a four-argument cdecl helper. It reads the canonical HWND
`006b7bf8`; no HWND returns zero without an API call. A nonzero fourth argument
selects `SendNotifyMessageA`, while zero selects `PostMessageA` and may query
`GetLastError`. Both branches pass API arguments in the order
`(hwnd, arg0, arg2, arg1)`, directly following the original pushes. The helper
preserves the original return conversion, including its distinct send and post
failure behavior. Its only indexed game caller is `0053bcb0` at `0053bcef`;
that assembly pushes `0,0,0,0x466`, so the actual ABI arguments are
`(0x466,0,0,0)` and the API receives `PostMessageA(hwnd,0x466,0,0)`. The older
`window_position.cpp` caller currently passes the message in the fourth
parameter; Run084 does not edit that existing source, and the caller needs the
separately coordinated argument-order correction before integration.

`00565560` returns one iff both canonical window `running_006b7c14` and
`hwnd_006b7bf8` are nonzero. `00573980` returns the raw DWORD at `006a64a0`.
The latter has direct writers at `00575746` and `00575759` which store one and
zero inside a lock-protected setter body. Its semantic name remains opaque;
the standalone production TU owns one zero-initialized DWORD because the VA is
in the PE `.data` virtual zero-fill tail. The HWND/running accesses reuse the
existing `OriginalWindowConfiguration` owner and aliases.

Indexed direct caller sites are `0053bcef` for `0053a8e0`, and `004ad9d5`,
`004dc638`, `004e25af`, `004e27da`, `0053ba91` for `00565560`. `00573980` is
called at `0053ba9a`; `00565950` also stores its code address at `006b4934` at
`00565955`. The consumer of that stored address remains outside this package.

The verifier executes the three original x86 bodies under Unicorn and compares
return values, final state, and the ordered USER32/KERNEL32 boundary trace with
the native C++ probe. It covers no-HWND, both message APIs, API success/failure,
last-error cases, all activation truth combinations, and opaque getter values.
OS behavior is fixture-controlled at typed boundaries; no unknown game helper
is replaced with a success stub.

Build and verify independently:

```powershell
cmake -S iterations/v2/001-original-recovery/runs/084-window-support `
  -B local/builds/v2/001-original-recovery/window-support-084 -A Win32
cmake --build local/builds/v2/001-original-recovery/window-support-084 --config Release
py -3 scripts/research/verify-v2-window-support.py `
  --probe local/builds/v2/001-original-recovery/window-support-084/bin/Release/window_support_probe.exe `
  --report local/builds/v2/run084-window-support-check/verification.json
```

Run084 does not change prior window sources, headers, shared CMake files, or the
registry. The caller-order fix is an integration dependency owned by root.
