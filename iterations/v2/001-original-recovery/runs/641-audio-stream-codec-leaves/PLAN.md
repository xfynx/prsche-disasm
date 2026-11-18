# Run641: Audio stream codec leaves (`0056bce0`, `0056bd10`, `0056c380`, `0056c3e0`, `0056c540`)

## Goal
Recover the five zero-unrecovered-callee audio stream codec leaf helpers from `local/game/Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`) to unblock `0056c420` / `0056c140` -> `audio_stream_codec_destroy_0056b3b0`:
- `0056bce0` (41B): `audio_stream_ring_contains_0056bce0`
- `0056bd10` (83B): `audio_stream_request_unlink_0056bd10`
- `0056c380` (90B): `audio_stream_consume_bytes_0056c380`
- `0056c3e0` (58B): `audio_stream_request_lookup_0056c3e0`
- `0056c540` (221B): `audio_stream_get_0056c540`

## Confirmed Facts
- `0056c575` raw PE bytes `ff 15 f0 eb 5d 00` are an indirect call `call dword ptr [0x005debf0]` (`diagnostic_handler_005debf0`), identical to `0056aff0`.
- `005bdd88` (`"STREAM_get - invalid stream handle\n"`, 36B incl NUL, sha256 `b9051bbf37f4e477effc3d6a97182d32925e1445257dfe4608abf8388db2bf3d`) had no prior owner and is owned by `641`.
- `005bd978` (`"\\real\\cmn\\stream.c"`, 19B) is reused from `Run629` (`stream_source_file_005bd978`).
- `005deb74`, `005deb78`, `005debf0`, `005322b0`, `005322c0`, `005681b0`, and `0056b380` are reused from existing canonical headers.

## Verification Status
- `attempt 003` (`local/experiments/v2-audio-stream-codec-leaves-641/003/receipt.json`): **PASS** (`cases=88`, `events=41`, `/Od` + `/O2`, 9 material mutations detected with exit 1 on `divergence`).
- Command:
```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/641-audio-stream-codec-leaves/native-config.json --attempt 003
```

## Remaining Boundaries
- Bounded `PARTIAL` native proof (8 KiB mapped arena; controlled lock, file-op-group, and diagnostic endpoints); parent callers (`0056c140`/`0056c420`/`0056b3b0`) and production CMake/registry integration remain for shared batch `642`.
