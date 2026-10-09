# Run077 — native window-chain link fixture

This x86 executable links and retains references to the production window
startup, worker, create, WndProc, all recovered callback bodies, thread
bootstrap, Win32 core/window bindings, and Run072 callee adapters. Its entry
point checks that the startup/thread/WndProc entries are present and all 16 unique
production callbacks used by the 27 registrations resolve. This is a native link and relocation
proof only: it does not call `window_init_0053ac20`, create a GUI window, or
start the message loop.

Original ABI evidence for the worker boundary is in `Porsche.exe` SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`:

- `0055f4f0` copies five dwords from `ThreadLaunch`, then loads the callback
  from copied field `+0x08` and performs `CALL EAX` at `0055f51d` without
  pushing arguments. Its return is ignored before thread unregister.
- The production worker body `0053b8d0..0053bad8` does not read a stack
  parameter; it loads configuration VA `006b77a0` directly. The native worker
  now has the exact zero-argument cdecl signature. `window_init` passes a typed
  `void __cdecl()` thunk, which calls the recovered worker and discards its
  EAX result just as the original bootstrap does. The x86 ABI mismatch is
  removed rather than hidden behind an incompatible function-pointer call.

The paint lock name `window_paint_lock_006a57d8` now aliases the canonical
`thread_start_lock_006a57d8` storage. Both names refer to the same original
pointer cell.

For a successful class-registration path, no unrecovered game callback is
called before the first HWND. `0053ac31` creates the class lock (`005321f0`);
the first lock bootstraps threads (`0055f320`), which creates the thread table
and lock through `0055f3b0`/`00532250`/`0056e5f0`, fills lock cells at
`0053222a`, and registers shutdown at `00557380`. At `0053222a`, startup passes
value zero to `0053c290`; Run077's fixture uses host `memset` only for this
zero-valued call and rejects other values. Run068 shows that nonzero inputs
repeat a DWORD pattern, so this bounded host service does not claim general
fidelity for `0053c290`. The fixture also provides process-exit callback
registration (`00557380` forwards to `005a2400`). The table's
27 valid startup IDs are ordered through an explicit CRT `qsort` boundary for
original `005a112b`. Native USER32/KERNEL32 wrappers handle class registration,
thread creation and CreateWindowExA.

The first post-HWND consumer identified here, `005739b0`, is recovered in
Run079 and linked into this fixture with real USER32 wrappers for `GetKeyState`
and `keybd_event`. `0053bb00` calls it at `0053bc87`, `0053bc90`, and `0053bc99`
with `(channel, desired)` equal to `(0,0)`, `(1,0)`, `(2,0)` when `0069e5a0` is
clear. The original compares the selected lock key's low toggle bit with the
desired state and sends a keydown/keyup pair only on mismatch. Run079
differentially checks this path against original x86. Run077 remains a
link/relocation proof: its entry point does not invoke the real startup or
keyboard input. In production, the worker continues with the thread-event
handshake, HWND state publication, initial placement/activation, and message
loop; unverified runtime behavior remains outside Run077's proof.

The next unresolved game algorithm on an ordinary idle route is
`005365e0`. If `GetMessageA` returns zero and callback cell `0069e5a4` is
empty, `0053b8d0` calls it at `0053ba46` with callback `0053bae0`, period 1,
and initial delay 10. Its 184-byte body rotates the scheduler counter at
`0069de20`, scans 16 callback slots at `0069dd20` (stride 0x10), and calls due
callbacks indirectly at `00536734`; the body is not yet recovered. Callback
`0053bae0` calls `00534550`, removes itself through `005366a0`, then enters the
noreturn exit path `00557370 -> 005a246e`. On a window-close route, the worker
calls `00558350(configuration)` only when the configuration pointer and its
dword at `+0x10` are nonzero, then destroys the HWND. The fullscreen-only
activation path checks running/HWND in `00565560`, reads opaque global
`006a64a0` in `00573980`, and may call ShowCursor, IsIconic, or
SetForegroundWindow.

Other typed fixture boundaries include registration diagnostics on
RegisterClassA failure; event/key translation `00560080`/`0069e5a0`, mouse/game
route `005728b0`, resize notification `005df9b8`, position-list removal
`0053a8e0`, worker idle/exit helpers `00565560`, `00573980`, `00558350`, and
heap copy/format helpers `005b0100`, `005b02c0`, `005b0480`, and `005a0fbf`.
They do not fabricate successful callbacks or a fake game loop. GUI execution
remains deferred to root.

Build the concrete executable without running it:

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/077-native-window-chain -B local/builds/v2/001-original-recovery/native-window-chain-077 -G 'Visual Studio 17 2022' -A Win32
cmake --build local/builds/v2/001-original-recovery/native-window-chain-077 --config Release --target native_window_chain
```

Run078 corrected the link fixture count assertion: the resolver contains 16 unique callback VAs; the original registrar has 27 registration rows. Both cardinalities are independently checked by the resolver and joint-registration probes.
