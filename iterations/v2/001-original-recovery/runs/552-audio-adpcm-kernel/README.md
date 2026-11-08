# Run552: coded-audio kernel family (59a910/59abe0/59ad80/59adc0/59ae00/59b580)

**Status: research packet, NOT accepted.** The scope is complete and the six
bodies are implemented, but the full 0059a910 frame proof still diverges in one
combined case (see "Open divergence"). Nothing here is integrated into the game
graph or the registry; no `ready.json`/validation exists for this run.
The plan that produced this packet is in [PLAN.md](PLAN.md).

## Scope evidence (complete)

`scope-evidence.json` pins original module SHA, body SHA/bytes, the complete
instruction stream, index callers/consumers and the 551 ownership closure
(754 effective pins/307 roots/557 source+header closure, zero body collisions).
`annotate.py` re-prints any body with live ESP resolution; `extract.py` derives
the 0059ae00 matrix block and fails if the listing shape changes; `gen_tables.py`
emits every read-only table as exact PE dwords (`table-evidence.json`).

Facts established from the original bytes:

- `0059a910` `void __cdecl(state, unused)`, 432 output floats at `state+0x680`,
  tape `state+0x170..state+0xd40` (324 history + 432 new).
- Header: one 6-bit read is both the sign source (`idx < state+0xc`) and
  scalefactor index 0; then 3x6-bit and 8x5-bit indices into `0x5e34c4`
  (`0x5e3504` is its element 16). `d=(table-state)/4`, then four rounds of
  `state+=d` interleaved with four `0059ae00` calls at offsets 0/0xc/0x18/0x24
  with counts 1/1/1/0x21.
- Per block: 8-bit lag, 4-bit step, 6-bit coefficient, 1-bit parity, 1-bit mode;
  `c1=step*0x5c1808`, `c2=state[0x10+4*coeff]` (x1.75 when mode==0); dequantize
  one parity (`0x70+parity`, stride 2) then zero the other (`0x74-parity`) or
  smooth it (`0059adc0`); blend `out=c1*tape[counter-lag+i]+c2*decoded[i]` for
  108 samples with counter 0xd8 step 0x6c; finally copy 0x510 bytes
  `state+0x830 -> state+0x170` through canonical `00598a50`.
- `0059abe0` 2x256 context table `0x5e35c4` -> 12-byte records at `0x5e37c8`
  (next context, skip bits, level). Levels >3 store the record float; 2..3 are a
  6-bit+7 zero run that never adds the single stride; 0..1 are unary `7+ones` with
  sign. flag==0 emits `0, -2, 0, +2` from the low two payload bits.
- `0059b580` seeds `h[0..10]=p[10..0]`, `h[11]=1.0`, then per output
  `acc=-(h[0]*p[11])`, taps `acc-=p[11-j]*h[j]`, `h[j-1]=acc*p[11-j]+h[j]`,
  `h[11]=acc`, `pre[k]=acc`, triangular correction from `pre[]` and `out[]`.
- Original runtime precision: `Porsche.exe` has no `fldcw`/`fnstcw` in `.text`,
  so x87 runs at the process default 0x027F (53-bit precision). The recovered
  C++ therefore uses binary64 intermediates in the original operation order and
  rounds to float only where the original stores a dword.

## Implementation

`audio_coded_kernel_552.{hpp,cpp}` + generated `audio_coded_tables_552.inc`
(exact dwords) and `audio_coded_matrix_552.inc` (12 unrolled dot products with
the original per-output summation order). Reuses accepted `0059a8c0`/`0059a800`
(Run504) and `00598a50` (Run519). All six bodies compile clean at `/Od` and `/O2`
with `/W4`.

## Proof harness

`prepare.py` builds `native-fixture.cpp.in` + `native-config.json`: nine original
bodies in an executable slab, relative calls, absolute data operands and the
`0059ad70` switch table relocated to canonical owners, with an assertion for
every image-space operand. `fixture-harness.inc` compares original vs compiled
state/output bit-exactly and checks the x87 control word (the C++ compiles to
SSE2 binary64, so x87 status/tag are not comparable) plus rounding-mode
equivalence. 15 mutations are pinned as controls.

```powershell
py -3 iterations/v2/001-original-recovery/runs/552-audio-adpcm-kernel/extract.py
py -3 iterations/v2/001-original-recovery/runs/552-audio-adpcm-kernel/gen_tables.py
py -3 iterations/v2/001-original-recovery/runs/552-audio-adpcm-kernel/prepare.py
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/552-audio-adpcm-kernel/native-config.json --attempt 038
```

Attempts 001..037 are frozen under `local/experiments/v2-audio-adpcm-kernel-552/`
(001 missing fixture include, 002 missing dead-dependency stubs, 003-013 slab
relocation faults, 014-016 zero-run/window/dispatch fixes, 017+ frame hunt).

## Proven so far (attempt 037)

Bit-exact at `/Od`: `0059ad80` (all 0..31 bit counts, 3 state shapes),
`0059adc0` (4 seeds), `0059abe0` flag 0 and 1 (8 random streams each, full state
and output), `0059b580` (6 seeds), `0059ae00` sequential offsets 0/0xc/0x18/0x24
(3 seeds), and frame sub-cases: zero stream, zero stream + zero scalefactors,
random 4-block field stream, single-field probes (parity, mode, coeff, lag 0/100/255,
step), random header with zero blocks, and the rounding-mode matrix.

## Open divergence

With a random dequant bitstream the frame still diverges: `bytes-headerzeros`
(zero header, random blocks+dequant) fails first in the matrix/output region,
while every ingredient passes in isolation and `field-stream` (random fields,
zero dequant bits) passes. The failure is not in the six bodies' formulas as
separately proven; the next concrete step is a stage probe that stops 0059a910
after the blend (patch `0x288` bound and return in a *diagnostic* slab copy) and
compares the four 108-sample blend blocks and the per-block parity/mode decisions
against a C++ build with the same stop, then narrows the first differing block.

## Boundaries

Real music/ADPCM streams, malformed/truncated bitstreams, lag beyond the tape,
unaligned/aliased buffers, unmasked FP exceptions, concurrency, live audio device
and full startup/gameplay stay open. No guards or clamps were added for them.
