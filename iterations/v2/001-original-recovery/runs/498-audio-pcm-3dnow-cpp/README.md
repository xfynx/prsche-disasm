# Run498: C++ 3DNow PCM kernels, emulated comparison

Emulated003 PASS, frozen. Original Porsche.exe bytes and actual MSVC C++ code
execute under the same installed Unicorn2.1.3 Athlon11 CPU model. `/Od` and
`/O2` each pass1,042 cases,82,660 arena read/write events and55,929 PF-operation
entry snapshots;18 mutations are detected(9 per optimization). This is an
emulated common-dependency proof, not native AMD hardware acceptance.

Two candidate providers close0059bc40 accumulation and0059bb90 signed16
conversion. Public count/control/address loops are ordinary C++ with unsigned32
pointer arithmetic, backward residuals and the original signed block-loop test.
Six private branch-free primitives handle MMX gain state, scalar/eight-lane PF
operations and finalFEMMS. There are no naked functions, whole-function ASM
loops, SSE replacements, host-float arithmetic, globals or new state owners.
The fixed eight-lane primitives preserve source loads/products before stores,
pairwise destination add/store order and the scalar decoder's DWORD read.

Raw Porsche.exe SHA256:
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index queries0059bc40/0059bb90 and006b17d4/006b17d8 locate the selector and
eight actual indirect consumer sites. Indexed bodies are159B+160B=319B;
contiguous copied spans159B+163B=322B. The decoder's skipped3B PXOR at0059bbc4
is retained unchanged in the raw oracle, never inferred as an executed reset.
[original-evidence.json](original-evidence.json) records raw hashes, gap and
consumer post-call instructions. Canonical486 declarations/consumer evidence
confirm cdecl4(count,raw FLOAT32 gain,source,destination) and cdecl3(count,S16
source,F32 destination). Calls clean16/12 bytes and ignore volatile EAX/EDX/ECX
and MMX payloads.005981bf subsequently uses x87, making finalFEMMS material.

Each optimization builds baseline plus9 source mutations in one compile batch.
Minimal fixed-base comparison PEs have zero imports/relocations and are never
executed natively. COFFs define exactly the two canonical486 names with zero
undefineds. Existing PE extraction and COFF inspection helpers are reused.
Compiler dependency records pin the actual header closure; validation pins35
inputs and148 artifacts. No shared tool, registry, game build or previous run
input changed. Provider integration requires the coordinator's emulated-proof
audit extension and remains pending.

Cases cover all16 source/destination byte alignment combinations,15 overlap
offsets in both directions, positive counts1..33/63/64/65 and padded zero/-1..-8
prefixes. All65,536 S16 patterns are tested in one bulk scene. Accumulation
combines441 pairs of21 exceptional/normal FLOAT32 bit patterns with all21 gain
patterns, including signed zero, subnormals, infinities and quiet/signaling NaNs.
CW precision/rounding, x87 depths0/1/3/6, sticky flags, incoming MMX payloads and
MXCSR seeds are varied without a redundant full cross-product.

Comparisons include entire scene arena/canaries, every arena read/write's width,
order and bits, initial/final FPCW/FPSW/FPTAG/MXCSR/FP0..7, and the same state
before every PFMUL/PFADD/PI2FD/FEMMS instruction. Event streams compare by SHA256.
All original final FPTAG values areffff. Seed depths come from real FNINIT/FLD1;
CW/TOP roundtrips are asserted before execution. Tag getter classifications are
observed emulator state, not a hardware-conformance claim. ESP/EBP/EBX/ESI/EDI,
return sentinel and caller/lower stack canaries are checked. Caller-discarded
by-value argument copies may be reused by optimized C++.

Mutations detect zero guards, forward residual traversal, wrong gain lanes,
unsigned S16 extension, wrong decoder pointer steps, missingFEMMS, block-count
steps, changed multiply/add order and a premature destination store before the
remaining block source loads. These affect real memory/order or FP-state checks.

```powershell
py -3 iterations/v2/001-original-recovery/runs/498-audio-pcm-3dnow-cpp/compare.py --attempt 3
```

Receipt: `local/experiments/v2-audio-pcm-3dnow-cpp-498/003/receipt.json`, copied
unchanged to [validation.json](validation.json). Attempts are immutable:001
stopped at the compiler's C4799/WX warning for deliberately live MMX across
private calls; scoped suppression documents the final publicFEMMS contract.
002 compiled but stopped on an invalid harness requirement that by-value stack
argument copies remain unchanged.003 corrects that ABI check without changing
the candidate. The command rejects an existing attempt directory.

Both sides share Unicorn's PF arithmetic implementation. Physical AMD fidelity,
unmasked faults, extreme counts/unmapped-memory behavior, whole producer/caller
composition, concurrency, live audio and gameplay remain open. These small
comparison PEs are not recovered game executables. Frozen490/492/495/497 remain
untouched; no production integration or native-hardware acceptance is claimed.
