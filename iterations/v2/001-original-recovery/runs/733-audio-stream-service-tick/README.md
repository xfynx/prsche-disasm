# Run733 — audio stream service tick

Status: **native PASS**. This run recovers the bounded original behavior of 11
x86 functions (994 code bytes) on the audio stream service path, including the
`00567270` tick loop and its local dispatch/refill helpers. It is ready for the
shared Run735 build/audit; it is not game, device, or playback acceptance.

## Provenance

- Original: `local/game/Porsche.exe`, SHA-256
  `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
- Index query: function/reference records around `00561680`, `005616d0`,
  `00567020`, `00567140`, `00567170`, `005671f0`, `00567270`, `0056c740`,
  `0056c790`, `00590e70`, and `00599710` under
  `research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d`. The main index omits
  `00567270`; `original-index-supplement.json` records its independently decoded
  complete CFG and exact raw range `00567270..005673a9`.
- Exact body ranges, SHA-256 values, ABI, indexed callers, reused owners, and
  typed open children are in `scope-evidence.json`. The fixture verifies all 11
  original bodies directly from the PE before relocation, plus the three used
  original strings at `005bde44`, `005bde70`, and `005bd978`.

## Native proof

Command:

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/733-audio-stream-service-tick/native-config.json --attempt 006
```

Receipt: `local/experiments/v2-audio-stream-service-tick-733/006/receipt.json`.

- `/Od`: PASS, 1,335 paired original-x86/C++ cases, 696 observed events.
- `/O2`: PASS, the same 1,335 cases and 696 events; output hash matches `/Od`
  (`4af50ff47174c72e8131512ebc221541a48221589f8edb9ec8d6397e49862e41`).
- 20/20 material mutations were detected: inactive/error returns, slot formula,
  lock/unlock order, voice/channel iteration, diagnostic line and codec offsets,
  refill wait/clamp/state behavior, SCCL/SCEL writes, chunk tag dispatch, tick
  guard, state-2 copy count, default drain budget, and state transition.
- ABI guards, event order/arguments, return values, arena state, diagnostics,
  slot iteration, state-2 restart, refill gates, and chunk drain limits are
  compared. Fixture/source dependency probes and input hashes are frozen in the
  receipt.

Pinned Run733 hashes:

- `audio_stream_service_tick_733.cpp`:
  `aea2bfb730b754869502473b9edf7068809d873bb1325bcdfce7446ba7f6ea26`
- `audio_stream_service_tick_733.hpp`:
  `cd304840bbe2001b6e6be7f8506ca1b42f5843bc888123518276a8d14335850d`
- `native-fixture.cpp.in`:
  `d2185d9eafaea7bbbc06975cbb2f83830b66c3ab225274027a44405de84d2e7e`
- `native-config.json`:
  `fb2fe8a7be07ad0b7adbf561e43a2f7042540bbeb849215dee6b4f7d349c67de`

Attempts are preserved. `001` exposed a missing fixture binding for
`00566d60`; `002` and `003` exposed invalid native arena/setup paths; `004` and
`005` showed that the lower refill-clamp mutation was not material under the
old wait matrix. Attempt `006` adds the discriminating signed-16-bit wait
threshold `30000` and passes the complete proof.

## Bounds and next dependencies

The proof uses controlled 32-bit mapped memory and callback/dependency oracles.
It does not establish live DirectSound/device transport, concurrent or reentrant
execution, arbitrary invalid-pointer fault behavior, or playback fidelity. The
child algorithms `005612a0`, `00566ea0`, and `00567060` remain typed but
unrecovered boundaries; their mocked effects prove this caller's routing only.

Next: Run735 may add these sources to the shared build and audit their real COFF
ownership/frontier. Recover the three open children separately when they become
the reachable linker/startup dependency; do not widen Run733.
