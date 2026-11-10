# CodeGraph bounded trial

CodeGraph v1.6.2 Windows release was downloaded to `local/experiments/codegraph-v1.6.2`;
its SHA-256 `7455e817ee8032666867a1badeb799b8a884c5f4fea9b444e088a02069b6deea`
matched the published release checksum. No global installation or agent configuration
was changed. Telemetry and the daemon were disabled for the trial.

An isolated copy of active `source` indexed 418 files, 6,717 nodes and 18,787 edges
in 2.2 seconds; three headers produced no symbols after parse errors. This excludes
the run-owned translation units that form much of the game build, so the graph is
not a complete ownership inventory and the copy does not update automatically.

The targeted `callers application_audio_period_control_00565c70` query identified
four caller functions but attributed all of them to one probe definition and none
to a second probe definition. `rg --no-ignore` found six call sites, two declarations
and two probe definitions; ordinary `rg` skips the `Porsche.exe` directory under
the existing ignore rules. The query is useful for navigation, not proof of C++
linkage, ABI, canonical ownership or original behavior. Verify against the actual
build closure and use REA and the binary index for original evidence. No measured
end-to-end recovery speedup supports permanent MCP or project-wide integration yet.

Executable and trial index remain local and disposable. See the upstream
[CodeGraph repository](https://github.com/colbymchenry/codegraph) for its CLI.
