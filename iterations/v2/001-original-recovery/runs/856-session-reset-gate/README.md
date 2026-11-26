# Run856 session reset gate

Porsche.exe SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The binary index and raw bytes identify `004030b0..004030cf` as a 32-byte
cdecl service. It reads the payload pointer at `005e66b0`; if that and the
canonical application word at `00657414` are nonzero, it loads `ECX` from
`005e752c`, pushes the payload, and calls `0040e3b0`. The child returns with
`ret 4`, establishing a one-argument MSVC x86 thiscall seam.

`session_reset_gate_856.cpp` owns the previously unowned payload and object
pointer cells and reuses the canonical `global_00657414` reference. The child
is deliberately retained as the typed `session_reset_children_0040e3b0`
boundary: its 140-byte body also requires the 105-byte `0040e440` parser,
the interior comparator at `0040e5f0`, variable-size payload records, qsort,
and the complete 0x34c-byte object extent. Those domains are not established
by this packet.

The native fixture relocates only the three absolute data operands and the
direct child call in the original body. Sixty-four combinations cover zero,
ordinary, high-bit and all-bit payload/application/object values. It compares
branching, child `ECX`, the stack argument, parent stack balance, and preserved
registers at `/Od` and `/O2`; three mutations test both gates and argument
transport.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/856-session-reset-gate/native-config.json --attempt 002
```

Attempt 002 passed 128 comparisons and all three mutation controls. The compiled child declaration uses fastcall with an unused EDX slot to preserve ECX and the callee-popped stack argument.

This standalone packet proves the parent and typed boundary only. It does not
prove `0040e3b0`, payload record bounds, parser behavior, sort ordering, live
allocation, startup, or gameplay. The coordinator owns shared integration.
