# Run691: application sim teardown / startup playlist / Sim De-init

Original Porsche.exe SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
All three bodies were read against `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`
and their raw bytes and hashes re-verified against the pinned PE before proof.

## Bodies (1043 code bytes)

- `004a88a0..004a8a76` (471B) `application_main_function_004a88a0`, cdecl0 void.
  Audio-bank/frame teardown (32 x 0x18 records at `00656528`, 73 DWORD pairs at
  `00656180`), flag reset at `00656868/69`, signed-clock load-progress pump with
  arena record scan (`0065808c + 0x580*i`, object +0 / mode +8, mode == 2 only),
  and the `<2` tail branch through `004ae470`/`004ae4d0`. Caller `004b6daa` in
  `004b6a50`.
- `004a8cd0..004a8dba` (235B) `startup_sequence_call_004a8cd0`, cdecl0 void.
  Builds `<track>Lil SND_coll` from the reused `0065b318` prefix pointer with
  signed mode gates on `00657c98`, calls `004acc10`/`004ad4d0`/`004a6c90(path,3)`,
  then writes `006564a0[5].raw_00=0xfffffffe` and `[2].raw_00=0xfffffffd`.
  Caller `004b6849` in `004b67b0`.
- `004b68f0..004b6a40` (337B) `application_main_function_004b68f0`, cdecl0 void.
  Per-player copy-out from `005e8b34` objects into the `005e75a0` 0x96-DWORD
  blocks (stride 0x258), teardown call chain, and the two `"Sim De-init "` /
  `"Done\n"` formatter logs. Counter is the original signed 16-bit `MOVSX BX`.
  Caller `004b6f2f` in `004b6a50`.

All three facade signatures match the accepted caller headers exactly
(`source/include/porsche/application_main.hpp`, `startup_sequence.hpp`).
Registry `source/recovered/functions.json` (1114 entries) lists these VAs only as
unrecovered dependencies; a programmatic `entry_va`/`body_ranges` check found zero
overlaps. No body was previously owned.

## Sources and data ownership

`application_sim_teardown_691.cpp/.hpp`, UTF-8 LF. Newly owned storage: the
`00656528` record table (0x300B), the `005d1a20` "SND_coll" literal (12B), and
the `005d6e60` "Done\n" (6B) / `005d6e68` "Sim De-init " (13B) literals. Raw
initial bytes of all literals are pinned against the PE before any relocation.

`0065b318` and `005d1a1c` ("Lil") are **not** duplicated here: they are compiled
owners of the accepted Run690 provider `application_audio_probe_690.cpp`
(`application_audio_path_prefix_0065b318`, `application_audio_lil_text_005d1a1c`;
confirmed in the Run694 game-graph validation). Run691 binds those exact symbols.
Other canonical providers are reused unchanged (see `scope-evidence.json`).

`005e8b34` and `005e75a0` remain explicitly unresolved original BSS extents; the
fixture owns bounded allocations, and no production storage is claimed.

## Proof

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/691-app-sim-teardown-audio-unload/native-config.json --attempt 007
```

Receipt: `local/experiments/v2-app-sim-teardown-audio-unload-691/007/receipt.json` — **PASS**.
Relocated original x86 bodies execute directly and are compared with the C++
bodies at `/Od` and `/O2` on call order/arguments, used returns, ABI
(ESP/EBP/EBX/ESI/EDI), exceptions, and final arena/table/object bytes.
34 scenarios per variant (17 unload + 11 playlist + 6 deinit = 68 measured case
runs), 44 material mutation controls (all detected), 429 pinned inputs, 198
receipts. Earlier attempts 001–006 are preserved: 001/002 found and fixed an
unsigned mode gate and a null-name fixture crash; 003/004 replaced two
non-material mutations; 005 passed before the Run690 ownership conflict was
found; 006 repaired the mutation anchors after reuse correction.

## Boundaries

The 21 unowned typed boundaries (callsite ABI only), scenario-controlled
`004a8570`/`004b04d0` returns, unchecked arena record domain, signed 16-bit
counter domain, NUL-only track-string extent, unresolved table extents, and the
real load/audio/subscriber effects stay explicit. This packet is a native
differential proof only: no game build, registry edit, CMake change or shared
manifest change was made here. Broader parent composition, live endpoints and
full startup remain open.
