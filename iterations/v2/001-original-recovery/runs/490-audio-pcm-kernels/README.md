# Run490: supported original PCM kernels

Native004 PASS, frozen:4 original bodies520B plus4B readonly data.
`/Od` and `/O2` each pass104,351 cases/1,020 callback events;12 mutations are
detected. Total:208,702 cases/2,040 events. Shared integration belongs to the
coordinator; no full-game or live-audio acceptance follows from this packet.

Recovers0059ba70(125B) x87 accumulation,0059baf0(159B) SSE accumulation,
0059b9f0(114B) signed16-to-FLOAT32 conversion and0059a350(122B) output chaining/
PCM16 conversion. Existing486 initializer0059a3d0 is reused, never duplicated.
The frozen486 name `audio_mixer_accumulate_x87_0059baf0` is retained for COFF
identity; its actual body uses MOVSS/MULSS/ADDSS/MOVAPS.

Original Porsche.exe SHA256:
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The full483643-pin compiler closure plus pending484/485/486 files proves no
owner for005c1800. New readonly bias is exactly raw0000404b /12582912.0F;
the fixture checks raw equality before reset. Canonical486 contracts are included.

The unrolled kernels preserve original instruction/load/store order and extra
incoming ECX preservation through explicit x86 bodies. Backward residuals and
whole-block reads before stores retain overlapping-buffer behavior. The output
processor captures its child, calls it with the original swapped input/output
arguments and signed parent priority, retains nonpositive child returns, writes
the x87-biased FLOAT32 back to input, then applies the original20-bit saturation.

Native cases cover all16 source/destination byte alignments for positive counts,
block/residual lengths,12 overlap offsets, all65,536 S16 bit patterns, signed zero,
subnormals, infinities, quiet/signaling NaNs and saturation neighbors. x87 PC24/
53/64, all rounding modes and stack depths0/1/3/6 include masked stack overflow.
SSE compares MXCSR rounding, FTZ, DAZ and sticky flags; current host DAZ support
is asserted. Callback argument/state mutations and used returns, memory, x87/
MXCSR and ESP/EBP/EBX/ESI/EDI plus kernel ECX preservation are checked.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/490-audio-pcm-kernels/native-config.json --attempt 4
```

Receipt: `local/experiments/v2-audio-pcm-kernels-490/004/receipt.json`.
001 failed the include-closure check,002 rejected MASM operand notation and003
hit the Windows `near` macro in a fixture loop name. Their input copies remain
local; all failed before algorithm comparison.004 is the accepted proof.

0059bc40(PFMUL/PFADD/FEMMS) and0059bb90(PI2FD/FEMMS) remain typed unresolved
3DNow providers. The host reports no3DNow capability; no replacement/fallback
or dynamic proof of those bodies is claimed. No passed486 input changes.

There are no invented count guards: zero executes a prefix block of4 x87
accumulation samples,16 aligned SSE samples or8 S16 samples. Small negative
counts also touch mapped prefixes. Nonpositive unaligned SSE can continue beyond
the finite fixture domain and remains open. Bounds are padded mapped buffers,
controlled children and masked floating exceptions. Full selector/producer
composition, unmasked faults, concurrency, real subscribers, live audio/platforms
and gameplay remain unverified.

Integration note: this frozen packet is an unintegrated instruction-body reference.
Production C++ recovery is Run492: ordinary control/addressing loops, SSE intrinsics
and bounded x87 primitives. Its original comparisons reuse these cases without
changing any490 input. Do not compile490 alongside492 or count both as recoveries.
