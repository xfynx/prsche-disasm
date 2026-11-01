# Run482: renderer call-contract audit

Read-only original-byte audit confirms concrete defects in the existing4677e0
constructor's unknown-child bindings. findings.json pins the old source/probe/
proof, original fragment and helper hashes/ABIs. Surface init uses raw47800000
rather than current40800000, dimensions use signedFILD, and queued arguments/ECX
receivers/RET12/RET16 differ from the current transform wrappers.

Prior136 proof compares call tags at these endpoints, discarding arguments,
receivers and matrix outputs. Its immutable204-case result remains historical;
constructor registry acceptance is reduced to PARTIAL until fresh proof covers
those effects. Compilation or supplying guessed helper wrappers cannot repair it.

No production source or existing proof input changes here. A new repaired caller
and real helper packet must compare full argument/state flow and explicitly
replace the old TU in a shared build/audit. The48B descriptor5de680..6af overlaps
canonical window state5de6ac; an independent descriptor copy is forbidden.
This audit is not recovered-function acceptance or a playable-game result.
