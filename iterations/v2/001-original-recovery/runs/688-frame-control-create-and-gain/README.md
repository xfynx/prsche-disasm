# Run688 input FF frame control: slot gain set and effect create (`005333a0`, `005334e0`)

Resumed batch (previous worker died on provider credits; its partial sources were
verified against the pinned PE before reuse, two material errors corrected).
`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.

- `porsche::input_slot_set_ff_gain_005333a0` (`005333a0..0053347b`, 219B, `__cdecl`,
  sha256 `0213f5258a30f577c267534e261bd3be071422201a6c09675b98453656fb5a06`): gates on
  `input_slot_has_device_00532b50(slot)` and `input_slots_006be040[slot].flags_04` bit 0;
  builds the 0x14-byte gain block `{0x14,0x10,0,0,gain}` with gain clamped
  (`>100 -> 10000`, `<0 -> 0`, else `gain*100`); unloads every loaded effect record
  (`frame_control_effects_0069cb10[i].input_slot_8c != -1 -> frame_control_slot_unload_005337e0(i)`),
  sends the block through device vtable `+0x18` (`__stdcall`, `(device,7,&block)`), then
  re-downloads loaded records via `frame_control_slot_download_00533760(i)`.
- `porsche::frame_control_slot_create_005334e0` (`005334e0..005336f4`, 532B, `__cdecl`,
  sha256 `d72769c2d01bc09afd298358e5ba28e8359912674b9da9a034521a567ace84b1`): claims a record via
  `frame_control_slot_find_free_00533730`, gates the slot, fills the 0x90 record (duration as-is,
  `gain*100`, button `-1` kept else `+0x30`, repeat, `direction*100 mod 2^32`, axes `{0}` / `{4}` /
  `{0,4}` by `params+0x3c`, 0x30-byte type block copied from `params+0x04` by
  `heap_copy_dispatch_005323e0`, descriptor `0x34/0x22/0x7d0`, `directions->+0x78`, `+0x7c/+0x80=0`,
  `type->+0x84`, `slot->+0x8c`); switch table `005336f4` (raw PE): type 0 -> 4 bytes, 1 -> 8,
  2..6 -> 0x10, 7 and 9..12 -> 0x18, 8 -> 0x30 + direction `0x2328`; `type > 12` -> `-1` with the
  record left claimed; GUID from table `005bb3b0[type]`, device vtable `+0x48`
  (`__stdcall`, `(device,guid,&entry,&entry+0x88,0)`); HRESULT != 0 -> `-1`, else
  `frame_control_slot_unload_005337e0(record)` and return the record index.

Corrections over the dead session's partial sources (raw-PE verified):
- GUID blob 0 was `{13541C59}` (Sine); the pinned PE has `{13541C20}` (ConstantForce) —
  the twelve blobs at `005bf9d0..005bfa8f` are `{13541C20..13541C2B}` contiguous.
- Switch mapping was wrong: the worker placed type 7 with the 0x10 group and swapped
  types 8/9; the raw jump table at `005336f4` gives type 8 -> `0053369c` (0x30 bytes +
  direction `0x2328`) and type 9 -> `00533690` (0x18 bytes). Fixture jump-target rebasing
  updated accordingly.
- `type_params_30` (`[ESI+0x69cb40]=EBX`, 00533641) was never written; restored
  (`&entry.type_specific_34`), caught by the create-stub type-parameter transport.

Owned data (unowned before this run, verified by registry + run-source search):
- `.rdata` `005bf9d0..005bfa8f` GUID blobs (read only by `005334e0`, indirect).
- `.rdata` `005bb3b0..005bb3cb` 13-dword GUID pointer table (types 8/9 share `005bfa40`,
  type 2 addresses `005bfa80`; read only by `005334e0`).
- `.bss` `0069cb10..0069dd0f` 32 x 0x90-byte effect records (full-record storage).

Reused canonical providers: `input_slot_has_device_00532b50` (run 676),
`heap_copy_dispatch_005323e0` (heap.cpp), `frame_control_slot_find_free_00533730` /
`frame_control_slot_download_00533760` / `frame_control_slot_unload_005337e0` (run 680),
`input_slots_006be040` / `InputDevice` (`porsche/input_state.hpp`).

## Verification

- Attempt `001`: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/688-frame-control-create-and-gain/native-config.json --attempt 001`
  - PASS at `/Od` and `/O2` (`/W4`); original x86 bodies relocated against the production
    arrays with per-displacement count checks; switch table and GUID table rebased.
  - Cases: 16 gain cases x sides (clamp corners incl. `INT_MAX`/`INT_MIN`, flags bit 0,
    device gate, record-load patterns 0/odd/even/{0,7,31}, block id/vtable transport,
    `HRESULT` recording) and 35 create cases x sides (type sweep 0..13 + `0xffffffff`,
    axes cross, create failure/success, slot -1/0/5/31/32, record 0/7/31, duration/gain/
    button/repeat/direction corners incl. `-1` keep and `mod 2^32` multiply).
  - 28 material `wrong-*` mutations all detected (see `evidence.json` / receipt).
  - Synthetic callsite setup (arg pushes, register/FPU seeding, RET framing) and the
    controlled vtable/`00532b50`/`005337xx`/`005323e0` endpoints are harness code
    (fail-closed poison vtable), bounded transport only.

## Boundaries

- Interface identity behind device vtable `+0x18` / `+0x48` not established (COM transport only).
- `axes_20` points at per-call stack storage in the original too; contents pinned during the
  vtable call, the pointer value is per-side.
- Caller `00411d20` (only caller of both targets; params construction and the `0x5e9420`
  result table) is unowned frontier reached from the accepted `startup_sequence_call_004121b0`
  chain; only its call sites/ABI were used.
- Unowned frontier consumers of record cells (`00533910`-region, `00533b40`-region,
  `005365xx`-region) still to recover; they must reuse the record extern declared here, not
  redefine the array.
- Record cells `+0x80/+0x88/+0x8c` are semantically owned by run 494's
  `frame_control_slot_fields_494` (consumed by run 676/680/683 functions); this run owns the
  full 0x90-byte record storage — single-storage reconciliation between the two host arrays
  is an integration decision for the coordinator.
- No live DirectInput hardware acceptance; CPU-specific flag/x87 behavior out of domain.
- `scripts/research/tmp-run688-extract.py` (stray leftover) untouched for the coordinator.
