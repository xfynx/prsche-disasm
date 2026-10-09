# Run 097 — ordered engine startup sequence

This run recovers `004b67b0..004b68e6` (311 bytes) from `Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. The
binary index identifies `004b6d88` as a caller from the main-loop body at
`004b6a50`; that path reaches it only after freeing the FE stream and while
`frame_active` is true. The function itself takes no stack arguments.

The recovered body preserves the direct sequence from the disassembly. Its
first call loads the service pointer from `0069ed0c`, reads the receiver DWORD
at `service+4`, and passes that value in ECX to `00536080`. The ordered calls then include
the phase notifications `1, 2, 4, 5, 6, 7`, direct zero writes to
`00606ac0/00606ac4`, repeated frame/service functions, and the report value
returned by `00569a90`. It conditionally invokes `0048cdf0` only when
`startup_network_00628c70` is non-null, its DWORD at `+8` is nonzero, and its
byte at `+0xbf` is zero. It finishes with phase `10`, the `00657444` text
consumer, then the original unconditional tail transfer to `004691c0`.

Phase calls use the existing `splash_progress_004a4a70(std::int32_t)` API and
the production source links to the recovered splash consumer. The standalone
probe substitutes a recording fixture at that same typed boundary. Other
engine/service callees remain typed recording boundaries: this run verifies
the 004b67b0 call order, arguments, direct global writes, network condition,
and handoff, without claiming their internal algorithms. The final tail target
is intercepted in the oracle and recorded by the fixture so both stop at the
same boundary.

`00606ac0` and `00606ac4` are separate DWORDs; the indexed data records each
initially as zero. `0069ed0c` is reused through the existing
`game_setup_movie_service_0069ed0c` owner, and the network cell is reused from
`startup_services.hpp`; no overlapping arena is introduced.

Four differential cases cover a null network pointer, a present but
disconnected network object, the blocked flag, and the branch that calls
`0048cdf0`. Each also uses a different `00569a90` return value to verify the
report argument. The verifier checks the complete ordered boundary trace,
the two zeroed DWORDs, tail transfer, and restored entry stack.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/097-startup-sequence `
  -B local/builds/v2/001-original-recovery/startup-sequence-097 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/001-original-recovery/startup-sequence-097 --config Release
py -3 scripts/research/verify-v2-startup-sequence.py `
  --probe local/builds/v2/001-original-recovery/startup-sequence-097/bin/Release/startup_sequence_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/097-startup-sequence
```
