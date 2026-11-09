# Run554: coded-audio kernels and original PRNG integration

Frozen552040 +553kernel003/random001 add nine originals4037B/1220Breadonly,
no writable original state;registry851. Shared audit PASS44,702 native comparisons/
373,698 events/31 mutation controls,762 effective source pins/771 listed canonical
providers. Fresh001 compiles310TUs in8 projects;131 unresolved names/139 references,
no game EXE. Both previous decoder-kernel names close; no new names.

552's six3312B bodies use static source x87 instructions with exact order, stores,
precision and stack behavior. The old1.75 coefficient is replaced by the original
qword005b2778=0.5. Independent diagnosis reproduced the precise037 divergence and
isolated that error; no process-wide precision assumption follows from an absence
of FLDCW. Native040 checks216 PC/RC/depth/sticky configurations with CW/SW/16bit
tags/live80/MXCSR/ABI plus independently embedded1144B raw PE data. Static COFF
audit verifies934 original instructions across both variants, with only the
checked local switch transport adding instructions. Production runs compiled
source instructions; original byte slabs are confined to comparison fixtures.

553 adds the678B LPC/noise-pulse10-stage kernel and47B originalrand/seed with76B
raw scalars. Exact x87 spills/order/countdown/history and actual550 partial/cached
carry composition compare with controlled random returns. Separate realLCG/seed
proof uses controlled returned thread records; game binds the PRNG to the existing
canonical formatter_crt_thread_005a545c. Actual combined kernel+realrand/liveTLS
execution remains open. The random proof observes no additional MXCSR matrix.

An inherited final-link alternatename binds old550 audio_adpcm_decode_0059a910 to
the single canonical audio_coded_decode_0059a910: both voidcdecl2, state+0xc and
unused zero argument, no wrapper or adaptation. Existing535/544 archive-alias
infrastructure proof is reused. Actual550+552 runtime composition is not claimed.
[Canonical owners](canonical-audio-owners.json) verify unique actualgetptd and
522ftol COFF definitions. [Compiler metadata](auxiliary-coff.json) checks inert
zero4B ANYCOMDAT where present in all new native/game objects; it adds no data owner.

[Intake review](intake-review.json) owns exact domains and composition boundaries.
Real streams/producers, invalid/truncated inputs, arbitrary aliases, unmasked FP,
unsupported stack/MMX/fabricatedtag domains, concurrency/liveaudio/startup/gameplay
remain open. Existing partials and AVblocked547/537005 are unchanged; no retry/bypass.

```powershell
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/554-audio-kernel-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/554-audio-kernel-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/554-audio-kernel-integration/acceptance.json
```

Passed inputs are frozen. Next independent555 panning/weight table family and
556 audio object activation/release need their own native proof before557 intake.
