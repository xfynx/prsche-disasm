# Run 786: Scene Flare Entries Resolve & Sky Lookup (`00452120` Cluster)

## Scope

Additive recovery closing `Run781`'s sole open child `scene_flare_entries_resolve_00452120` and its sky/chunk lookup subtree (`7` functions, `615B` total) in `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):

- `00452120..004521b9` (`154B`): `porsche::scene_flare_entries_resolve_00452120` (`__thiscall`, `RET 0`) — resolves flare texture tags at entry `+0x04` and `+0x08` (`"null"` -> `nullptr`; sky archive match via `00460b10`/`00460c80`; fallback `bswap32(tag)` lookup in `00613e04` via `0044d320`).
- `0045dd80..0045dd85` (`6B`): `porsche::scene_flare_table_get_0045dd80` (`__cdecl`) — returns `00627e48`.
- `0045cfb0..0045cfb5` (`6B`): `porsche::scene_route_sky_get_0045cfb0` (`__thiscall`, `RET 0`) — returns `00627e4c`.
- `00460b10..00460b4a` (`59B`): `porsche::scene_sky_find_tag_00460b10` (`__thiscall`, `RET 4`) — unpacks 4-byte tag into a stack string and delegates to `00460b50`.
- `00460b50..00460c51` (`258B`): `porsche::scene_sky_find_name_00460b50` (`__thiscall`, `RET 4`) — scans 40 cached sky slots (`+0x08`/`+0xa8`), looks up archive chunks via `0053c680`, inserts into first free slot (or returns `0` if full).
- `0053c680..0053c6be` (`63B`): `porsche::scene_chunk_find_tag_0053c680` (`__cdecl`) — tail-scans archive chunk records using `0056e2a8`.
- `00460c80..00460cc4` (`69B`): `porsche::scene_sky_texture_get_00460c80` (`__thiscall`, `RET 4`) — lazily instantiates `[self + 0x198 + index*4]` via `0044da10` (`"SKY "`, `1`, `[00628130]+0x74`, `0`).

Newly owned loader-zero `.bss`: `8B` (`00627e48` `4B`, `00627e4c` `4B`). Single shared typed frontier: `0044da10` (`272B`).

## Evidence & Commands

- REA session:
  `py -3 scripts/research/run-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/786-scene-flare-entries-resolve/rea/queries.json --attempt 001`
  `py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/786-scene-flare-entries-resolve/rea/queries.json --attempt 001`
  Validation: `iterations/v2/001-original-recovery/runs/786-scene-flare-entries-resolve/rea/validation.json` (`passed: true`, 7 dossiers).
- Native differential verification (`/Od` + `/O2`, `24` cases/variant, `10/10` mutations killed):
  `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/786-scene-flare-entries-resolve/native-config.json --attempt 004`
  Receipt: `local/experiments/v2-scene-flare-entries-resolve-786/004/receipt.json` (`status: PASS`).
