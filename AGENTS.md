# Project rules

## Resume and publish

- Read `git status --short --branch`, [PLAN](PLAN.md), [STATUS](STATUS.md), the active iteration plan and the latest relevant run handoffs before editing. If no next iteration exists, use [docs/next-iteration.md](docs/next-iteration.md). Resume uncommitted work after interruptions.
- Use English for new work and chat. Keep the active plan current after meaningful findings and at handoff. Record scope, owners, proven facts, hypotheses, evidence, checks and the next concrete step there. Root documents point to current results. Limit logs and generated artifacts to the evidence needed.
- Commit and push each accepted batch, give the [progress report after every commit](PLAN.md#report-after-every-commit), report branch and upstream status after each push, then continue unless paused. The coordinator owns shared acceptance and main. Assigned workers may publish independent batches on isolated branches.
- Keep `local/game` read-only. Preserve completed snapshots, including 001 through 011, and immutable attempts. Keep runs in their own iteration; start each new iteration at run 001.

## Recover original behavior

- Start with the [original binary index](research/binary-index/README.md). Trace strings, imports and resource references to functions, callers and callees. Record the query, module/SHA, addresses and original calculations. For data, identify fields and consumers. For UI, retain original frames and transitions.
- Resolve missing entries by checking coverage and analysis errors, then supplement the index. Check the registry, interior entries and full `body_ranges` for overlaps. Use the adjacent `original-index-supplement.json` for manually added CFGs. Check canonical owners throughout the compiled source/header closure and bind proved providers with their actual ABI.
- Validate algorithms against original inputs, intermediate state and outputs. Apply the same standard to older code. A string, loader or SIM table alone does not establish its consumer's behavior. Preserve unknown state, original algorithms, provenance and explicit partial domains. Verify UI and gameplay visually when the build permits.
- Keep hypotheses in `local/experiments`. Introducing approximations into the game build needs explicit user agreement. Platform infrastructure must preserve original semantics. Use [CodeGraph](docs/research/codegraph-evaluation-2026-11-11.md) for navigation and verify its results against source, binary evidence, REA and native comparisons.

## Batch and validate

- Prioritize the actual unresolved linker and startup path. Defer archive-only providers until a reachable parent needs them. Group related functions and ABI bindings by subsystem. Freeze a passed batch and put later work in the next batch.
- Follow the [recovery skill](.agents/skills/porsche-recovery/SKILL.md). Reuse native harnesses, accepted proof, hash caches and manifest-driven REA. Compare bounded original behavior and ABI and use material mutations. Repeat checks only for changed inputs, failures or a specific open concern. Defer unrelated fault, alias, concurrency and FP matrices.
- Perform one shared build and audit per frozen batch. Publish one concise handoff; keep generated receipts as artifacts. Add general tooling only when it immediately replaces repeated work. Use neutral fixture executable names. Run581 recorded WinError740 for a name containing `dispatch` or `patch`; preserve failed attempts and distinguish launch errors from antivirus detections.
- Use [worker roles](docs/agents.md) and the provider assignments in [PLAN](PLAN.md). Give independent workers compact scope and file ownership. Keep the coordinator on integration and final acceptance.
