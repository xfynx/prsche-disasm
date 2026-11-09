# Run552: coded-audio kernel family

Frozen040 PASS: six originals3312B,1144B exact readonly data, no new writable
state. Both `/Od` and `/O2` total38,758 comparisons/105,922 events; all16 mutations
detected. The unchanged shared read-only audit verifies305 input pins/245 outputs,
logs and compiler dependencies. `ready.json`, `coff.json` and
`verification-summary.json` own the independent packet handoff. Game integration
and the six registry entries belong to root's later554 packet.

## Original evidence and source

Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
`scope-evidence.json` pins binary-index query/callers/consumers, complete raw
instructions and551 ownership closure754pins/307roots/557source+header files.
The six bodies are59a910/706B,59abe0/397B,59ad80/58B,59adc0/61B,59ae00/1914B
and59b580/176B. `translate.py` checks each instruction byte against the immutable
PE and emits static MSVC x86 naked inline assembly in
`audio_coded_kernel_552.cpp`; `translation-evidence.json` records every mapping.
Production contains source instructions, typed canonical calls and static data.
It preserves original x87 operations/order, register lifetimes, stores, integer
flow and stack layout. The local59abe0 switch `[zero,minus,zero,plus]` uses checked
direct branches with saved/restored flags. It adds no guards or opaque-local
initialization. MSVC x86 is required.

`audit-static.py` checks actual COFF instructions at both optimization levels,
including canonical call/data relocations and every branch target. All934 original
instructions are covered (944 compiled instructions including the local switch
transport). It hashes/searches the complete accepted557-file closure and finds
no existing owner of the new data. The six1144B tables/scalars are256+348+512+4+8+16B;
`table-evidence.json` and `gen_tables.py` own their actual data extents. In particular,
the consumed12B level records start at005e37c8; the earlier scope census's
005e37c4 symbols range starts one dword earlier and is not the production extent.
The fixture compares every canonical table with independently embedded immutable
PE bytes before any oracle/compiled execution. Accepted504readbits/init and519copy
remain canonical; the game550caller itself is not executed in this packet.

## Corrected frame finding

The037 divergence was a production transcription error: original0059aaa4 is
`FMUL qword [005b2778]`, whose exact bytes encode0.5. The old C++ multiplied by1.75.
The minimal original failing stream is retained explicitly: scene
`bytes-headerzeros`, PRNG seed`0x1f4ec7c7`, both frames. Both now match exactly.
The prior inference that absence ofFLDCW proves global53-bit precision was
invalid. Static x87 source now obeys the caller's PC/RC and preserves full FP state.
The old binary64 expression helper `audio_coded_matrix_552.inc` remains a pinned
historical research artifact; production does not include it.

## Native proof

The shared native runner is unchanged. `prepare.py` emits the original-only
oracle slab with checked calls/data/switch relocations; it is fixture evidence,
not production code. Full bit-state, matrix/history/output memory, all six body
scenes, zero/unary/context/parity/mode/lag/step cases, random and initialized
multi-frame cases and the037 mismatch regression compare bit-exactly.

The216 FP configurations arePC0/2/3 x RC0..3 x incoming live depth0..5 x sticky
status0/0x25/0x453f. Each exercises all six bodies plus two-frame and actual504init
composition. The harness compares full x87 CW/SW/16-bit tag and every live80-bit
value, plus completeMXCSR. Only host FIP/FDP addresses and undefined empty-slot
contents are excluded. Incoming values contain low80-bit precision bits that
binary64 cannot retain. cdecl stack balance/nonvolatile registers/DF are checked;
all six bodies return void, and helper-used returns are covered by full downstream
state/output comparisons. Sixteen material source mutations include incorrect
mode-zero gain, smooth sign/constants, skip/refill, symbol classes, zero/unary runs,
window sign/taps, lag, scale accumulation, tail count and matrix stride.

Attempts001..040 remain immutable under
`local/experiments/v2-audio-adpcm-kernel-552/`. 037 is the old divergent source;
038 failed to compile because MSVC needs explicitST0 forFADDP/FSUBP;039 passed the
static-source/full-FP matrix and16 controls with abridged tag capture;040 adds true
16-bit tags and independent raw-table assertions. No unchanged accepted037 case
was rerun until the implementation and full FP contract changed.

```powershell
py -3 iterations/v2/001-original-recovery/runs/552-audio-adpcm-kernel/translate.py
py -3 iterations/v2/001-original-recovery/runs/552-audio-adpcm-kernel/prepare.py
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/552-audio-adpcm-kernel/native-config.json --attempt 040
py -3 iterations/v2/001-original-recovery/runs/552-audio-adpcm-kernel/finalize.py --attempt 040
```

These commands identify frozen proof origin, not a request to overwrite/rerun040.
`finalize.py` uses the shared read-only audit and staticCOFF audit without executing
any PE. Static evidence report: `local/reports/552-fp-static-audit-040.json`.

## Boundaries

Actual550caller composition, real music streams, malformed/truncated/corrupt bit
states, arbitrary external/caller-stack aliases, unmasked exceptions, incoming
stack depth beyond5 or invalid-stack states, concurrency/live audio device and
full startup/gameplay remain open. The existing smooth scene includes align0..3;
this is bounded local buffer evidence, not an arbitrary alias claim. No native
3DNow instruction executes, and blocked547/537005 were never retried.
