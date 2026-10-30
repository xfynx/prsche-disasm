# Run451: original audio record decoder

Three original bodies/1,533B:00599100 decoder,00599760 token reader and0059bd90
integer reader. Native004 passes `/Od` and `/O2`:183 cases and147 intermediate
memory checks per variant (366/294 total), with12 detected mutations. All624
registered entry/body ranges have zero overlap. REA453001 is reused.

The public decoder matches448's cdecl(cursor,record) symbol. Its0x464-byte frame
and164B record retain unwritten state; the naked stack adapter passes that backing
to the C++ core. No full clear or count guard is added. The parser preserves
inherited value/payload/length cells for controls and large payloads, exact cursor
progression, signed1/2/3-byte correction, unsigned extended lengths and x86 wrap.
Checks compare whole mapped memory after token calls and each decoder continuation,
including cursor/record aliases, signed callback count wrap, duplicate14 tokens,
98..9b arrays, packed defaults, flag remapping and seeded first-large payloads.

The new immutable8B default at original005e3498 is `{0x7fffffff,127}`.
Raw PE bytes and absence of overlapping relocations are checked before normalizing
its pointer to actual host storage. Consumer00590420 reads both DWORDs and retains
the pointer for00589560's duration/value indexing; the default frame count is1.
Ownership search covers417 current450 source/header paths. No other provider was
found. No neighboring data extent or valid nondefault frame count is inferred.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/451-audio-record-decoder/native-config.json --attempt 004
```

Receipt: `local/experiments/v2-audio-record-decoder-451/004/receipt.json`.
Inputs are UTF-8 LF and frozen.001 retained a fixture standard-library link failure;
002's raw-data guard caught a misaligned surrounding-hex interpretation before
semantic comparison.003 passed both main variants but showed missing coverage for
opaque retained values;004 adds that fixture case with unchanged production.
Exact failed-attempt inputs are archived locally; attempts are immutable.

Mapped padding in the129-append case proves unchecked signed-byte indexing;
it does not establish safety for arbitrary counts in448's164B backing. Readable
inputs and mapped output domains are required. Invalid/faulting memory, unbounded
malformed streams, concurrency, real448+451+452 composition, subscribers and live
startup/gameplay remain unverified here. Run453 owns shared integration/acceptance.
The next concrete check is composed448 caller with the accepted decoder/remover,
then actual subscribers/436 parent. No game executable or visual acceptance is claimed.
