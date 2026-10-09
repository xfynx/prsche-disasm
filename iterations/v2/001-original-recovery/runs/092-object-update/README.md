# Run 092 — object update and elapsed-time consumer `005588a0`

Source: `Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The binary index gives `005588a0..00558915` (118 bytes), called by
`00558c9d`. Its only static references to the owned words are in this
function: reads/writes of `006a3afc`, `006a3b00`, `006a3b04`, and a zero write
to `005deb58`. There are no existing native source owners for those VAs.
The new TU owns one `uint32_t` per address. `006a57d8` reuses the existing
`thread_start_lock_006a57d8`; configuration fallback reuses
`window_configuration_storage_006b77a0`.

`005588a0` is cdecl with one configuration pointer. Null selects the canonical
configuration. If `+0x43c` is nonzero, its vtable `+0x80` method receives that
pointer and `+0x440` as two stdcall arguments; then `+0x43c`, `+0x440`, and
byte `+0x444` are cleared. If `+0x43c` is zero, those bytes are preserved.
With a nonzero `+0x43c` object, the function calls the typed
`platform_get_tick_count()` boundary, computes 32-bit `tick - 006a3b04`, stores
the word in `006a3afc`, and uses the original signed `JLE` comparison against
`006a3b00` before updating that word. It then calls the existing lock-leave
routine for `006a57d8` and clears `005deb58`. With a zero object, it preserves
`+0x440/+0x444`, skips vtable, clock, and lock calls, clears `005deb58`, and
returns. No lock-enter occurs in this function.

The original data section maps `006a3afc/006a3b00/006a3b04` in zero-filled
virtual BSS beyond the `.data` raw extent. `005deb58` is raw-backed at file
offset `0x1deb58`; its original DWORD is also zero. The original index
identifies the indirect API
target at `005b2080` as `KERNEL32!GetTickCount` (`DWORD __stdcall(void)`). The
root-owned platform adapter should implement `platform_get_tick_count()` by
calling that API. The isolated probe provides a typed recording implementation
of the same boundary to test fixed ticks. The vtable `+0x80` method remains a
recorded no-effect boundary; its effects are not claimed.

The 31 differential cases cover: zero-object bypass, actual method invocation
and upper-threshold update, backward tick wrap, forward wrap, signed-negative
threshold, and null-argument fallback with equal-threshold method invocation, both handle identities, zero/nonzero auxiliary fields and byte flags, and signed INT boundary permutations.
They compare the touched state words and ordered method, clock, and lock calls
against original x86 execution.

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/092-object-update `
  -B local/builds/v2/001-original-recovery/object-update-092 `
  -G 'Visual Studio 17 2022' -A Win32
cmake --build local/builds/v2/001-original-recovery/object-update-092 `
  --config Release
py -3 scripts/research/verify-v2-object-update.py
```
