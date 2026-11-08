# Run552: coded-audio kernel family (59a910/59abe0/59ad80/59adc0/59ae00/59b580)

Status 2026-11-09: steps 1-4 done for five bodies and all frame sub-cases;
step 4 still fails for the frame with a random dequant bitstream. Step 5
(integration) not started. See README.md "Proven so far"/"Open divergence".

Research/implementation packet for the six original bodies behind the accepted
Run550/551 processors. Scope evidence: `scope-evidence.json` (original SHA, body
SHA/bytes, complete instructions, index/callers/consumers, 551 ownership closure
754 pins/307 roots/557 source+header closure, zero body collisions).
`annotate.py` prints the same bodies with live ESP offsets (argument/scratch
resolution); `extract.py` turns the 0059ae00 instruction stream into checked C++
expressions.

## Confirmed original facts

- `0059a910` `void __cdecl(U state,U unused)`; state base is `object+0xc` of the
  accepted 550 processors, block length `0x1b0` floats, tape
  `[state+0x170,state+0xd40)` = 324 history + 432 new samples.
- Per block: 8-bit `lag`, 4-bit blend step, 6-bit coefficient index, 1-bit
  parity, 1-bit mode; dequantize 54 values per parity (`0059abe0`), zero the
  other parity (mode!=0) or 3-tap smooth it (`0059adc0`, mode==0, second gain
  `1.75`); blend `out=c1*tape[counter-lag]+c2*decoded` for 108 samples.
- Counter starts `0xd8`, step `0x6c`, four blocks while `<0x288`. Tail copies
  `0x510` bytes `state+0x830 -> state+0x170` through accepted `00598a50`, adds
  the 12 differential scalefactors four times and calls `0059ae00` at offsets
  `0,0xc,0x18` (1 block) and `0x24` (33 blocks).
- Scalefactors: `(table64[6b] - state)/4` into `state+0x110..+0x13c`
  (1x6b,3x6b,8x5b from `0x5e3504`); sign flag `idx<state+0xc` is 59abe0's mode.
- `0059abe0` `void __cdecl(U state,U flag,float* out,I stride)`: flag!=0 uses
  the 2x256 context byte table `0x5e35c4` -> 12-byte record at `0x5e37c8`
  (next-context, skip bits, level): level path `>3`, zero run `2..3`,
  unary `7+ones` + sign otherwise. flag==0 reads the low 2 payload bits and
  emits `0, -2, 0, +2` skipping 1/2 bits. `0059ad80` is the no-mask skip.
- `0059ad80` `void __cdecl(U state,U bits)`: `payload>>=bits`, one refill when
  remaining<8. `0059adc0` `void __cdecl(U p)`: 54 points,
  `out[2i]=(in[2i-5]+in[2i+5])*c3-(in[2i-3]+in[2i+3])*c2+(in[2i-1]+in[2i+1])*c1`.
- `0059b580` `void __cdecl(U p,U out)` reads `p[11]` and `p[1..11]`, runs a
  12-output lattice recursion and a triangular correction; `out` is written and
  reused. `0059ae00` `void __cdecl(U state,U offset,I count)` forms the 12-value
  window through `0059b580(state+0x110)`, then `count` blocks of 12 outputs
  `sum_j w[(j+k)%12]*M[j]`, `out[k]+=sum`, `M[11-k]=sum`, exact order per output.

## Plan

1. `audio_coded_kernel_552.{hpp,cpp}` implements the six bodies with the exact
   x87 expression order; only `0059ae00` dot products come from `extract.py`.
2. Reuse accepted owners: `0059a8c0`/`0059a800` (Run504), `00598a50` (Run519).
3. Read-only data keeps exact raw bit patterns (`std::uint32_t` tables).
4. `native-config.json` + `native-fixture.cpp.in` embed the six original bodies
   plus `0059a8c0`/`0059a800`/`00598a50` in an executable slab, relocate calls,
   absolute data operands and the `0059ad70` switch table, and compare full
   state/output at `/Od` and `/O2`; mutations must diverge.
5. Freeze, then integrate in the next batch (554) through the CMake chain.

## Boundaries (not accepted here)

Real music/ADPCM streams, malformed or truncated bitstreams, `lag` beyond the
324-sample tape, unaligned/aliased buffers, unmasked FP exceptions, concurrency,
live audio device and full startup/gameplay stay open. No guessed guards or
clamps for those paths.
