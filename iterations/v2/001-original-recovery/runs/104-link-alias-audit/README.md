# Run 104 - Run102 unresolved alias audit

Read-only audit of the captured Run102 link frontier (251 unique symbols / 263
references). It correlates decorated C++ link names with the recovered-function
registry, original Ghidra function and call indexes, the original disassembly,
and current declarations/definitions. It does not alter the recovered sources
or shared build files.

Run102 contains three groups that map to already recovered entries with
matching address and ABI evidence. Two are already bridged in the current
common source: `startup_sequence_call_00427a60()` to
`engine_service_00427a60()`, and both `*_004b0d70()` spellings to
`frame_pump_004b0d70()`. The fresh Run098 frontier confirms those three names
are resolved. `render_depth_failure_00557370()` can map to the existing
`window_shutdown_process_exit_00557370()`, but remains unresolved; its terminal
005a246e callee still needs one non-returning production implementation.
Same-address names at 0059d650, 00532e10, 00534480, and 004dc850 are internal
branches or partial entry recoveries; they are not safe alias bridges.

Two larger same-entry groups merit ABI normalization, but their native bodies
are not recovered: the 11 formatting names at 005a0fbf target one variadic
original entry, and three exit names at 005a246e target one terminal routine.
The report records all 23 duplicate-VA groups, original direct-call xref counts,
index entry ranges, decorated type encodings, recovery-registry matches, and
source/index hashes. Shared data/vtable slots without original code entries are
kept distinct from function aliases.

The baseline has 166 distinct VA suffixes: 7 match a recovered registry entry
(4 full and 3 partial), 126 have an indexed code entry with no recovered
registry body, and 33 have no Ghidra function entry. Those groups remain open
until callers and entry ABI support a real recovery; matching suffixes alone
does not justify an adapter.

Run102 remains the historical frontier baseline. Run098 is only a read-only
cross-check showing which aliases have since linked; its report and source
closure remain separate.

Recreate the audit report without building or editing production code:

```powershell
py -3 iterations/v2/001-original-recovery/runs/104-link-alias-audit/audit.py
```

`report.json` is a link-failure diagnosis, not a claim that the game links or
runs. The specific next traces for partial entries are recorded in the report.
