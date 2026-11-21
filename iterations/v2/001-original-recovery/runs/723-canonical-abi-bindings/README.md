# Run723: two reachable canonical ABI bindings

Two current Run720 unresolved names refer to already accepted originals:

- Run691 `application_sim_boundary_004a6c90(const char*, int32)` binds directly
  to Run697 `application_audio_probe_message_004a6c90(const char*, uint32)`.
  Both are cdecl void with the same two stack DWORDs. Original caller `004a8cd0`
  pushes kind 3/path, calls at `004a8d98`, cleans 8 bytes and ignores EAX.
- Run693's pointer-return `scene_transfer_enter_004521c0()` binds directly to
  canonical Run702's void declaration. Its only accepted caller explicitly
  discards the return. Original `00468fb0` tail-jumps at `00469097`; no alias
  wrapper, fake pointer or invented EAX value is introduced.

Actual Run720 COFF contains both exact old UNDEF references and both canonical
definitions. Registry owners remain Run697/702; **zero new recovered functions,
original bytes, cells or game translation units**. `bindings.json` contains exact
mangled names; `evidence.json` records object hashes and original callsite evidence.

Integrate with one line after the accepted baseline:

```cmake
include("${CMAKE_CURRENT_LIST_DIR}/../723-canonical-abi-bindings/bindings.cmake")
```

It supplies two `/alternatename` options on `porsche_original_game_link`.
No `target_sources`, include directories or registry entries are required.
The `*-callers.cpp` sources are fixture-only and must not enter the game graph.
Expected closure is exactly the two old names in `bindings.json`; no new names.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/723-canonical-abi-bindings/audio-native-config.json --attempt 003
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/723-canonical-abi-bindings/scene-native-config.json --attempt 002
py -3 iterations/v2/001-original-recovery/runs/723-canonical-abi-bindings/audit.py
```

Final receipts PASS at `/Od` and `/O2`: audio003 has 1,280 regression cases
(1,024 through the bound audio caller); scene002 has 58 regression cases
(six allocation/constructor branches through the bound scene caller). Both
assert legacy/canonical address identity before scenarios. ABI, call arguments,
order and state match original x86; scene EAX is intentionally unclaimed.
One changed-kind and one omitted-scene-call control are detected. Canonical
body proofs are reused, so these counts add no recovered bodies. Four real
game COFF symbols and all final native input hashes pass the audit.

Audio001 preserves a link failure from packing both fixture callers together
while linking only the audio provider. Split fixture-only callers fix this.
Audio002/scene001 passed before explicit address identity assertions; final
audio003/scene002 include them. No frozen source or proof was edited.

Bindings are limited to the existing accepted call contracts. Any future use
of the scene pointer return needs a new verified contract. Full parent
composition, live resources/audio/scenes/startup and shared game-link acceptance
remain open. Coordinator owns shared integration. `prepare.py` is initial input
generation; passed inputs are frozen.
