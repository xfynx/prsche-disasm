# Run435: channel stop and voice stop

Two complete Porsche.exe bodies /194 bytes: `00565d60..00565dc9` and
`0058a8b0..0058a907`. Native002 passes13,765 cases at each of `/Od` and `/O2`
(27,530 total), including cdecl ESP/EBX/ESI/EDI/EBP probes; all13 mutations are
detected. Production source, fixture, config and passed receipt are frozen.
Coordinator owns shared integration; no registry/build graph is changed here.

`audio_channel_stop_00565d60` reads the canonical active byte006b499c, returns
-10 when zero, otherwise locks, resolves the signed channel, starts voice
iteration at0xffffffff, stops each yielded voice, unlocks and returns the channel.
`audio_backend_stop_voice_0058a8b0` is **int32 cdecl(uint32)**, returning0; the old
Run400 void declaration is not reused. It captures the0xf8-byte slot, invokes its
cdecl1 callback at+c8 with slot+2c, reloads flags, gives bit1 precedence over bit2,
then reloads bit10 after the release endpoint. Table changes never replace the
captured slot. Multiplication/address arithmetic wraps as unsigned32.

The accepted actual device-owner TU and unchanged Run434 helpers are linked into
the proof. Original stop composes raw original lock/lookup/iteration/voice bodies;
every raw body SHA and relocation operand/target is checked. Full canonical state,
CS storage, both channel/voice tables, returns and per-endpoint snapshots compare.
Cases sweep all256 flags bytes, callback/endpoint flag mutations, table swaps,
count changes, inactive and invalid handles, exact-active/group exclusions,
depth wrapping and wrapped voice strides. Parent valid-handle cases use channel0;
direct voice cases also cover indices1/2/3 and wrapped indices. Positive parent
channel returns are established by original instructions but not separately
exercised in this frozen fixture.

Only the separate4-byte006b489c table pointer is newly owned. `ownership.json`
references the Run433 build and its effective shared manifest plus delta;
403 current source/header files were scanned with zero existing cell owners and
zero resolved-pin drift. The cell is outside canonical006b48b0..006b4a3b and inside
the original writable `.data` virtual tail, beyond file-backed bytes: loader zero
initialization is proved. The native fixture asserts it and the complete canonical
initial state before resetting any fixture memory.

`ownership.json` and `evidence.json` record ABI, body hashes, exact index lines,
callers, sources, proof hashes and boundaries. `coff.json` records actual production
objects at both optimization levels, their canonical references and the two real
unresolved endpoint names. Input/output hashes were rechecked after proof.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/435-audio-stop-voice/native-config.json --attempt 2
```

Receipt: `local/experiments/v2-audio-stop-435/002/receipt.json`. Attempt001 preserves
a missing namespace closing brace compile failure; it is not accepted proof.
Local435 prepare/freeze helpers only assemble this packet; they add no shared tool.

`00597010` and `00589c00` remain unresolved production endpoints, controlled only
by recording/mutation hooks here. Six uncalled device-owner dependencies fail
closed in the fixture. Callback transport, recording Win32 locks and bounded
valid memory do not establish real device behavior, concurrency, fault domains,
audio allocation/initialization, startup/display or playable-game acceptance.
