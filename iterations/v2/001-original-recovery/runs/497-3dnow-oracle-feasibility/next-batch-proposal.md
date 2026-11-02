# Proposed Run498: two original 3DNow PCM kernels

Scope is not yet implemented. One worker would own only
`runs/498-audio-pcm-3dnow-cpp` and
`local/experiments/v2-audio-pcm-3dnow-cpp-498`; coordinator owns active plans,
registry/build/integration and acceptance. Preserve other workers' files and
frozen490/492/495/497. No production edits until reviewed comparison evidence.

Recover0059bc40 accumulation and0059bb90 signed16 conversion as ordinary C++
count/control/address loops plus small fixed private PF/MMX instruction primitives.
Do not use SSE/host float approximations, naked whole functions or translated
whole assembly loops. No new globals/state owners are needed. The return is void;
prove actual consumers before deciding which volatile state is immaterial.

Inputs and provenance:

- Pin the original SHA from497 and exact contiguous raw extents0059bc40..de
  (159B) and0059bb90..bc32(163B). Index body160B for the latter excludes the
 3B PXOR at0059bbc4, which the observed branch graph skips; retain all163 raw
 bytes in the oracle and label the gap. Do not silently count it as160 copied
 bytes or infer a missing initialization from the disassembler.
- Reuse497 Athlon11 selection, PE extraction/disassembly and local installed
  Unicorn package. Capture emulator DLL/package and compiler tool hashes.
- Reuse490/492 case concepts and source order evidence; leave their accepted
  inputs unchanged. Read original consumers/selector and record exact cdecl
  argument order, used results and preserved-register obligations.

Compilation/execution route:

1. Compile a single standalone candidate TU at `/Od` and `/O2` with installed
   MSVC Win32, `/GS- /GR- /Zl /arch:IA32` and no CRT calls. Two extern-C entry
   exports and one inert entry symbol suffice. No `main`, WinAPI or native run.
2. Prefer a minimal linked PE with `/NODEFAULTLIB /MACHINE:X86 /FIXED`, explicit
   nonoverlapping image base, `/ENTRY` and `/EXPORT` symbols. Reject any imports,
   unresolved CRT helpers or unsupported generated instructions. Record COFF
   definitions/undefineds and map PE exports; do not write a general COFF linker.
3. Existing `verify-v2-native-batch.py:pe_at` and the original mapping patterns in
   `oracle-v2-file-operation-reuse-276.py` are reusable PE transport. Existing
   `experiment-v2-thiscall-leaves-187.py:coff_symbols` and
   `verify-v2-startup-service-516950.py:coff_symbol_bytes` cover bounded COFF
   inspection. The old application-allocator verifier executes candidate C++
   natively, so it cannot serve as the 3DNow comparison runner unchanged.
4. For each scene make fresh machines with the same Athlon11 model, memory,
   stack, GPR and FP/MMX seeds. Execute pinned original PE and actual linked
   candidate instructions to a synthetic return sentinel. Both sides use the
   same emulator; no Python implementation of arithmetic substitutes for either.
   Reject unexpected calls, imports, code exits and instruction-budget exhaustion.

Required cases and acceptance:

- Positive counts1..33 plus block/residual boundaries63/64/65; zero and small
  signed-negative padded-prefix scenes. Retain original signed/unsigned tests
  and wrapping32-bit addresses; do not introduce guards. Extreme counts outside
  finite mapped memory remain an explicit unsupported domain.
- All16 source/destination byte alignments and exact/partial overlap in both
  directions, including offsets crossing8-lane blocks and residuals. Compare
  entire mapped arena bytes and canaries. Trace source/destination read/write
  events at primitive/case cutpoints; compare required widths/order, including
  scalar S16 path's original DWORD read and load-all-source-before-store behavior.
- All65,536 S16 bit patterns plus nonzero neighboring WORDs. Accumulation covers
  signed zeros, subnormals, normal boundaries, largest finite, infinities,
  quiet/signaling NaNs and signs/payloads for both source/destination/gain.
  Results are raw bits, never tolerance comparisons or host-float expected values.
- Seed x87 CW PC/RC, sticky SW/depth, MMX registers and MXCSR. Compare observed
  FPCW/FPSW/FPTAG and FP/MMX storage before/after relevant cutpoints and FEMMS,
  then document which residues real consumers require. FEMMS alone proves an
  empty tag, not erased FP register payloads. Validate seed roundtrips before
  resetting state:497's FPTAG getter reconstructs classifications, so a written
  full tag may read differently. Prefer harness FNINIT/FLD seed instructions and
  saved FP environments for meaningful depths rather than unchecked tag writes.
- Check ESP/EBP/EBX/ESI/EDI, input/stack integrity, used returns/state and original
  ECX preservation only when proved consumer-visible. Record other registers
  without inventing C++ ABI requirements for unused volatile residue.
- Mutations must detect PFADD/PFMUL order, wrong gain lane, sign extension,
  residual direction, block source-read ordering, pointer steps, count guard and
  removed FEMMS. Both optimization levels need all required cases and mutations.

Only then may the coordinator consider typed provider integration. Receipt language
must say emulated-original-vs-emulated-compiled-C++ under pinned Athlon11. The
emulator arithmetic remains a common dependency; physical AMD instruction fidelity,
unmasked faults, full producer composition, concurrency/live audio and gameplay
remain open. A minimal linked comparison PE is not a recovered game executable.
