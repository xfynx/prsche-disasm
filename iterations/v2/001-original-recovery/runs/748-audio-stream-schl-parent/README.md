# Run 748: Audio Stream `SCHl` Parent (`00566ea0`)

## Result

Recovered the reachable `audio_stream_service_chunk_schl_00566ea0` parent
(`00566ea0..00567011`, 370 bytes, SHA-256
`dd84e42c82e79485f8c9a0c364c6a00c979a958e7194842ac7ba1204bedf98e8`).
It closes Run744's parent boundary without adding owned data or recovering the
separate `005612a0` voice-start subtree.

The implementation reuses canonical `006b7740` service storage, `006b48c0`
device state, `0056c620`, `00590e70`, and Run744's committed `00590f70` /
`00590ef0` providers. Registry and all run supplement `body_ranges` have zero
overlap with the new body.

## Evidence and verification

- Binary index: one reachable caller at `005671a7` in Run733's `00567170`.
- Raw PE: Porsche.exe SHA-256
  `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`,
  body offset `0x166ea0`, exact body hash above.
- REA `002`: one complete dossier and five direct callees; audit PASS. REA
  `001` preserves the sandbox `spawn EPERM` failure.
- Native `003`: `/Od` and `/O2` PASS, 7 cases / 34 events each, 13/13
  mutations detected. Full mapped memory, canonical state, child calls, return,
  nonvolatile registers, ESP and x87/MXCSR are compared.
- Run744's accepted parser proof is reused unchanged: both parent sides call
  that committed provider while the original parent x86 is compared with C++.

Attempts `001` and `002` are retained. `001` showed direct notification-list
seeding is erased by the parser; token `0x14` is the producer. `002` exposed
the callback payload layout: proved dwords are at offsets 0, 4, 8 and 16;
offset 12 is original-unwritten and stays opaque.

```powershell
py -3 scripts/research/run-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/748-audio-stream-schl-parent/rea-queries.json --attempt 002
py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/748-audio-stream-schl-parent/rea-queries.json --attempt 002
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/748-audio-stream-schl-parent/native-config.json --attempt 003
```

## Boundary

Valid mapped slot/stream/chunk/list inputs are covered. Notification callbacks
are controlled; their real bodies remain open. `005612a0` is a controlled typed
endpoint; its 791-byte body/backend children, live playback, faults,
concurrency, startup and gameplay remain open. This is standalone proof, not
shared-game integration or an executable.
