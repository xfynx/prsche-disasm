# Run501: PCM stream lookup and callback

Native004 PASS, frozen:2 original C++ bodies305B plus64B canonical slot state.
`/Od` and `/O2` each pass67,620 cases/4,325 events; all12 mutations are detected.
Total135,240 cases/8,650 events. No related ADPCM/nibble/resampler body is included.

Porsche.exe SHA256:
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Lookup0059c130 is60B; stream callback0059ca50 is245B through both original
RET exits0059cb21/0059cb44. The omitted callback is fully recorded in the
run-owned `original-index-supplement.json`, with its493 constructor assignment.
Indexed instructions/raw PE resolved the bodies; no REA session was repeated.

The64B owner `audio_stream_slots_006b7cc0[16]` follows actual base/stride/end
instructions0059c139/0059c153/0059c157: exclusive end006b7d00. Independent
allocator scan00561215..00561228 has the same range, and0056125f stores the
selected slot. The pointer table occupies the loader-zeroed virtual tail of
the PE .data section. It ends before485's canonical list at006b7d00. The
current491 closure includes267 TUs/477 source/header files, with no missing
quoted includes and no existing table owner. Registered indexed body overlap
is also checked. The fixture asserts all16 initial zero slots and canonical
channel/decoder pointers before reset. No capacity was inferred from names.

Lookup is I32 cdecl1(owner), using accepted434 channel lookup00589d20 and the
canonical434 channel arena/count views. It compares the used result directly:
owner=-8 can match an invalid handle. No guessed failure guard is introduced.
The stream callback is I32 cdecl5(object,count,input,output,flags); input and
flags are unused. It acknowledges previous samples before testing signed
count, then clears the previous count after the callback. Signed cursor/chunk
comparisons, reloaded child-mutated fields, used accumulated return and EOF
zero-fill ordering follow the original instructions.

The original uses its saved output argument stackword as acquire length-out
storage. The C++ local retains that word's initial output-pointer value and
persists across calls; endpoint traces compare the word before each write.
EOF returns captured progress and clears the output tail only after progress.
Output may alias object fields. All control, arithmetic and memory operations
are ordinary C++, without ASM, intrinsics or new safety guards.

Native comparisons reuse the unchanged434 lookup/zero-fill,493 PCM8 and492
S16 providers. Cases cover65,536 slot masks, first/last/duplicate slot matches,
invalid/negative/inactive handles, member-byte transport, signed count/cursor
branches, prior acknowledgment, acquire/decoder state mutations, EOF after
progress, output/table/state overlap, x87 state and used cdecl ABI.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/501-audio-pcm-stream-lookup/native-config.json --attempt 4
```

Receipt: `local/experiments/v2-audio-pcm-stream-lookup-501/004/receipt.json`.
All passed inputs/output hashes and the full491 closure hashes were rechecked.
Passed004 source/config/fixture inputs are frozen; do not enlarge this batch.

Attempts001..003 remain immutable:001 inherited a now-duplicate fixture
next-voice stub when linking the actual434 owner TU; it was removed.002/003
both passed production `/Od` and `/O2`, but acquire-predicate mutations entered
unsafe zero/negative-block paths (timeout/unhandled access violation), so their
expected-exit controls failed. The revised control changes only the acquired
length store by one, keeping the mutant execution bounded. Production source
was unchanged throughout these attempts.

Exactly two typed frontiers remain:00561800(190B), U32 cdecl3(slot,member,
U32*length) acquire, and005618c0(50B), void cdecl3(slot,member,count) acknowledge.
Their fixture endpoints establish ABI/state transport only. There are no
production substitutes. Next recover these two actual stream-record providers
and trace their producer/lifetime; keep other coded formats in separate batches.
Full slot allocation/lifetime, zero/negative acquired lengths, inaccessible
memory/unmasked faults, concurrency and live audio/game acceptance remain open.
Coordinator owns common integration/registry/build/docs/commit.
