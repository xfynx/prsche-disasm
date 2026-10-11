# Run 135: application context base and member

Isolated recovery from `Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Search: binary-index function/call records for `00525e20`, `00525ec0`,
`005294c0`, `005295b0`, `005299d0`, `005299f0`, `00529a20`, `00529a40`.
The indexed callers include `004d1a90`, `004d1b50`, and `004d1ba0`.
Full inclusive body ranges and SHA-256 pins are in `verification.json`;
source hashes include the compiler inputs and transitive project headers.

Six bodies are recovered: `00525e20`, `005294c0`, `005295b0`, `005299d0`,
`00529a20`, `00529a40`. `00525ec0` is partial: its null-allocation branch
preserves incoming EAX (`00525ecc -> 00525f3a`), whereas the C++ typed
return currently normalizes this branch to zero. Two oracle cases retain
different EAX seeds to document the difference. No full return parity is
claimed for that branch. The `005299f0` aggregate-copy adapter is recovered
inside member destruction and pinned as supporting code, not counted as
another independently exposed function.
The partial destructor resides in `application_context_base_destroy_partial.cpp`,
included only by this private CMake graph. The common original library must
leave `00525ec0` unresolved until its contract is recovered.

Confirmed source details include the saved ECX high byte at `00525e85`,
the byte-only sentinel clear at `00525e96`, allocation-as-ECX at
`00525ee4`, and next-node capture after unlink but before release/notify.
Sentinel pointers are reloaded for each reset store. Member `+0xc` is
byte-cleared; constructor count is loaded after the array allocator.
Member destruction checks `[storage]` after range finalization, captures
loop bounds before block callbacks, then reloads count and array before
clear. It passes the array pointer, not storage, to `004237d0`.
`005299f0 -> 00529c20` passes two 16-byte values and a zero DWORD (36
argument bytes), preserving the original order.

Typed effect boundaries remain unresolved: allocation/release
`0059ef90`/`0059f050`, `0059eeb0`, `005262e0`, `004e4560`, `004d7da0`,
`004237d0`, `004211d0`, `0059ecb0`, `00529c20`, and `00441200`.
Known heap locks use the canonical `heap.hpp` declarations; the private
fixture records their calls without recovering native lock behavior.
Global `005e4fe8` initially contains `005e3e18`; `00525e4b..00525e58`
loads that pointer once and accesses its `+0x28` lock slot directly.
There is no extra load of `[005e3e18]` in this body. Storage ownership
remains unresolved. `005e4fec` initially points to `006af374`; its current
cell/value is reloaded on every block iteration. Neither global is
aliased to an unrelated heap implementation.

The native MSVC Win32 probe and original x86 Unicorn oracle compare 20
cases. Cases 0-5 cover allocation failure/success, an existing sentinel,
member setup, and composed `004d1a90/004d1ba0`. Cases 6-8 cover lock-slot
mutation, two nodes with callback mutation of next/root, and an empty
nonzero-count list. Cases 9-11 cover constructor count mutation, null array
after finalization, and changed destructor bounds/count/array. Cases 12-15
exercise forward overlapping copy, overlapping range-link fields,
three block allocations with changing selector pointer/value, and a
reversed range. Cases 16-19 cover a null block result, zero destruction
count, arbitrary incoming EAX on the null base destructor, and an empty
range. Full controlled arena canaries are compared before and after each
operation; original stack cleanup and nonvolatile registers are checked.
Boundary effects are controlled test doubles, not proven hidden callee
semantics, physical runtime behavior, or visual acceptance.

```powershell
& local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe `
  -S iterations/v2/001-original-recovery/runs/135-application-context-base `
  -B local/builds/v2/application-context-base-135 -A Win32
& local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe `
  --build local/builds/v2/application-context-base-135 --config Release
py -3 scripts/research/verify-v2-application-context-base.py `
  --probe local/builds/v2/application-context-base-135/bin/Release/application_context_base_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/135-application-context-base
```

Result: native MSVC Win32/x86 Release build succeeded; all 20 contracts
matched original x86. `verification.json` intentionally sets whole-packet
`native_cpp_equal_original_x86` to false because of the documented partial
null-path EAX result, and sets `verified_contract_equal_original_x86` to true.
It records the compiler version, native PE architecture, source closure,
original code/global pins, fixture hashes, and original ABI checks.

Registry proof for the six full functions: [full-verification.json](full-verification.json).
It records 16 exact scoped cases: base-constructor-only phases 0/1/2/6
(memory, EAX and trace captured before the partial destructor), full member
cases 3/4/9/10/11/16/17, and direct-helper cases 12/13/14/15/19. Its
`native_cpp_equal_original_x86` is true and partial list is empty.
Partial `00525ec0` results remain only in the honest 20-case
[verification.json](verification.json); they are excluded from the registry
proof and common production library.

This packet uses its own CMake graph. Common integration, actual game-link,
and full gameplay acceptance remain coordinator-owned and open.
