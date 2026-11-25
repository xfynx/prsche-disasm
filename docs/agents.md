# Recovery workers

[PLAN.md](../PLAN.md) specifies the coordinator and worker models for Codex and other providers. Select from models actually available in the client. Check the effective model and effort before assigning a fixed profile. The [sample configs](../agent-configs/README.md) and legacy Cursor roles are client-specific examples.

- **Coordinator / planner** owns scope, ambiguous reverse engineering, the registry, shared builds, acceptance and publication. A small blocking task can stay with the coordinator.
- **Builds** handles inventories, scripts, CI, reproducibility and documentation. **Formats** handles known parser layouts and resources. **Renderer** handles wgpu, native/web and GPU behavior. Assign ordinary implementation and its fixtures to a bounded worker.
- Usually run one or two independent packets with disjoint files. Send the original addresses, known inputs/outputs, allowed paths, required comparison and stop condition. Preserve other work in the checkout and keep originals read-only.
- The coordinator confirms new addresses against the registry and overlap ranges before implementation. While workers run, do independent work and serialize builds sharing a target.
- After two failed attempts on one ambiguity, send evidence to the coordinator. At a quota limit, preserve the uncommitted work and resume with an adequate available worker. If delegation is unavailable, report it and continue sequentially.
- Return findings, changed files, checks and remaining boundaries in at most eight lines. Workers keep their assigned task and publish only on explicit assignment. Close the worker after acceptance.

[Project rules](../AGENTS.md) cover the original-code method, batch acceptance and Git handoff.
