# Run512: nibble decoder recovery

READY: native003 frozen, both/Od and/O2 PASS,14 new mutations detected.
Two new original leaves:0059a5a0 x87185B and0059a660 SSE200B. Ordinary C++
loops use private straight-line arithmetic primitives and opaque U32-address
memory transport. Both indexed bodies and raw hashes are in original-evidence.json;
504/scope-evidence.json retains actual constructor/process consumers.

Original Porsche.exe SHA256:
ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.

## Ownership and integration

- Replace486's audio_mixer_configuration_486.cpp TU explicitly with this run's
  same-named placement-only clone; do not link both. Reversing only the.nibl$a
  section annotation restores its exact bytes. Its header is byte-identical.
  No existing486 source/header, game graph or accepted attempt was edited.
- Add audio_nibble_decoders_512.cpp and nibble_memory_512.cpp. The latter keeps
  memory operations opaque across translation units; no cross-object typed
  indexing or whole-program optimization assumption replaces these operations.
- The existing208-float audio_mixer_nibble_lookup_006b04c0 symbol/type remains.
  Its832B.nibl$a is followed by a separate192B zero-initialized RW.nibl$b tail.
  Native gates require actual832B adjacency/RW permissions and canaries surviving
  every original/C++ initializer. Recheck adjacency in the eventual game EXE.
- The other new owner is the80B original writable physical window5e3b28..77,
  including32B initial coefficient views and48B adjacent bytes. Its offset48
  is shared DWORD scratch5e3b58 for future59cd70; never duplicate that owner.
  physical-views.json pins all bytes, writers, xrefs and relocation analysis.
- These272B preserve physical reads for all256 header byte values; they do not
  establish sixteen semantic predictors/rows or an asset validation contract.
  Fixture-only192B.niph$b output slack permits safe high-window write aliases;
  it is not production storage or a production capacity claim.

## Proof

The shared fixture includes fresh complete486 original/native regression plus
the two raw decoder bodies. It compares whole mapped memory, mutable high/LUT/
tail windows, cdecl preserved state, x87 control/status/tags/nonempty values and
MXCSR. Empty x87 residue, instruction/data pointers and volatile XMM/GPR residue
are excluded because actual consumers do not use them.

New cases cover all256 headers with canonical initialized LUT/zero tail;
mutable windows with distinct NaNs, infinities, subnormals and signed zeros;
one/two blocks and residual counts; x87 PC/RC/depth0..8 and initial status;
MXCSR RC/FTZ/DAZ/status; input/output/state/table/window aliases; and mapped
count<=0 ECX-residue cases. x87 low-nibble read precedes even FSTP; SSE reads
it afterwards. x87 lookahead precedes odd FSTP, including the final extra byte.

Attempt001 exposed MSVC/O2 intrinsic operand commutation changing distinct NaN
payloads; two tiny ordered MULSS/ADDSS primitives correct it. Baseline002 passes
12,760 decoder cases plus4,353 old486 cases/31,368 events per/Od and/O2.
Native003 repeats both comparisons with14 new detected decoder/layout mutations:
34,226 cases/62,736 events total,395 input pins/473 outputs. validation.json and
coff.json record hashes, actual object ownership and exact RW section extents.
Accepted486's unchanged11 semantic controls are reused with rechecked pins;
they are not counted among the14 new controls. Failed attempts remain local.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/512-audio-nibble-decoders/native-config-mutations.json --attempt 3
```

No guard changes the original nonpositive x87 path: incoming history2 raw bits
remain ECX if no block ran, producing U32-wrapped output+ECX*8-4/-8 addresses.
Only safely mapped examples are proven. Arbitrary faults/unmapped storage,
unmasked FP exceptions, concurrency/indirect writers, live assets/full process
composition and the3DNow decoder59a730/resampler59cd70 remain open. No native
3DNow or gameplay acceptance claim.
