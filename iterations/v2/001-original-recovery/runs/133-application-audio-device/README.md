# Run 133: application audio device creation

This run recovers `00565720..0056588a` (363 bytes) and the two short direct
descriptor helpers it calls, `00565680..005656c9` (74 bytes) and
`005656d0..00565711` (66 bytes), from `Porsche.exe` SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The indexed startup caller is `004a66b0`, which consumes `00565720`'s signed
EAX result. The helper bodies are also directly called from `00565720`.

The recovered C++ preserves the active-device early exit, lazy descriptor
initialization, signed query and backend-start failures, allocation size
arithmetic, callback fallback, rollback call order, and the successful
mode-dependent word table. State is represented as an opaque 0x17c-byte span
at `006b48c0`; only bytes and words accessed by the three functions are
interpreted. The separate lazy flag at `006a5c30` is zero-filled in the
original image. Pointer cell `005e246c` initially targets the complete
60-byte author string at `005e2470`; the function dereferences the current
pointer and writes `0x53` through it. The fixture changes that pointer and
checks the new target. `005656d0` returns EAX zero, and reads descriptor
`+0x78` before its forward dword copy.

Backend/device effects remain controlled typed boundaries: `0058a4f0`,
`0058a690`, `0058fef0`, `0058aa90`, `0058aae0`, `0058e2d0`, `0058fdb0`,
`0058fe80`, `0058e2e0`, and `0058e0e0`. The boundaries do not model physical
audio I/O or hidden backend state. Their tested contract is limited to their
observed arguments, configured returns, and ordered invocation; unknown
side-effects remain outside the recovered body.

The standalone ten-case original-x86 verifier covers direct helper calls, the
already active path, cached and signed-negative channel counts, lazy-query
failure, backend-start rollback, successful starts with both mode branches,
and an overlapping descriptor that verifies the pre-copy read order.
It compares return values, the
complete addressed state span, descriptor output, marker/lazy state, ordered
boundary calls, stack cleanup, and callee-saved registers.

```powershell
cmake -S iterations/v2/001-original-recovery/runs/133-application-audio-device `
  -B local/builds/v2/application-audio-device-133 -A Win32
cmake --build local/builds/v2/application-audio-device-133 --config Release
py -3 scripts/research/verify-v2-application-audio-device.py `
  --probe local/builds/v2/application-audio-device-133/bin/Release/application_audio_device_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/133-application-audio-device
```
