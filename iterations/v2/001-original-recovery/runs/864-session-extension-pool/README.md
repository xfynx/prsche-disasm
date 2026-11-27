# Session extension pool

Run864 recovers five original Porsche.exe bodies (SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`). [Scope evidence](scope-evidence.json) pins their bytes, occupied ranges, initial data and ownership search. The original listing and indexed bodies cover all five entries; no CFG supplement is needed.

`00406710` calls `0040b4b0`, then tail-jumps to the real cdecl dependency `session_extension_service_00406520`. Its C++ provider retains the existing `frame_reset_service_00406710` binding. The two byte-identical 22-byte clears (`0040b490`, `0040b4b0`) zero ten DWORD flags at `005e7484` and the separate counter at `005e747c`. They leave the 1600-byte record store at `005e6e38..005e7477` unchanged. `0040b530` scans for the first zero flag, sets it to one and returns its 0xa0-byte record; exhaustion returns null. Its caller-popped size argument is completely ignored, including zero and oversized requests. `0040b570` clears a flag only for an exact record-base pointer; null, interior, one-past and unrelated pointers leave every flag unchanged. Allocation/release preserve the counter and record bytes.

No registry entry/body range overlaps these bodies. A conservative inventory of Run860 generated project sources and their quoted-header closure finds only the existing frame caller/declaration for `00406710`; there are no competing state definitions. The generated project inventory is a superset of the actual compiler inputs. Shared integration must supply the authoritative compiled COFF audit. Original PE section bytes plus virtual zero fill establish the three initially zero stores; the record store has 456 file-backed zero bytes and 1144 zero-fill bytes. Nearby gaps and other session counters are not claimed by this packet.

Native attempt `002` passed **26,624 comparisons at each of /Od and /O2**, plus five detected mutations. The total includes 3,072 repeated clear/wrapper checks per variant (23,552 distinct operation/mask combinations). All 1024 occupancy masks exercise both clears, ordered wrapper transport, five ignored size values and 15 release-pointer classes. Nonzero flags include high-bit values. The fixture compares exact flag/counter bytes, returned pointers, untouched record bytes, original-state guards, cdecl stack balance and nonvolatile registers. It checks production initial state before fixture resets and validates raw wrapper targets before relocating them. The child at `00406520` is a fail-closed harness endpoint asserting clear-before-call and exactly one call; its actual behavior remains unrecovered. No fixture provider belongs in the game graph.

Mutations detect wrong record stride, a size restriction, incorrect release value, omitted counter clear and reversed wrapper order. Source/header/fixture text used LF before proof. Reproduce with a fresh attempt number:

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/864-session-extension-pool/native-config.json --attempt 003
```

This packet establishes bounded native pool semantics and wrapper transport. Shared build acceptance, the `00406520` child, live session consumers and startup/gameplay remain coordinator work.
