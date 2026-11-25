# Original C/C++ recovery handoff

**Paused at Run846.** For the measured corpus, registry and shared build, see [current status](../../../STATUS.md). The coordinator owns registry changes, the shared Win32 build, acceptance and publication. No workers are active.

## Next dependencies

- [Run844, network transports](runs/844-network-option-queries/README.md). The UDP availability probe at `005839d0` passed standalone native comparison. Before integrating the UDP/IPX initializers, trace callback `00587bf0` at context offset +8 and determine registry bounds and ownership. The descriptors reference 29 callbacks. The local-address provider and buffer are still open.
- [Run845, camera transform](runs/845-transform-vectors-trace/README.md). The camera reaches `00532a40` in mode 2. The original dispatch selects x87, SSE or 3DNow. Trace cache/scratch writers, then compare the three paths, including stride and FP state. A production provider and differential proof are pending.
- [Run846, audio period callback](runs/846-audio-period-device-state/README.md). Integrated. The proof covers group-zero selectors. Other selectors and live playback remain open.

Run772 is archived locally in `local/experiments/v2-run772-exploration/` (two extraction scripts and two dumps). The IAT script reuses the first slot address for each DLL, so the dump cannot establish slot ownership. [Run806](runs/806-input-caps-query/README.md) recovered the input-capability continuation and [Run809](runs/809-scene-reset-and-input-caps-integration/README.md) integrated it. For later CRT shutdown work see [Run838](runs/838-crt-shutdown-and-env-closers/README.md) and [Run841](runs/841-entry-fe-service-and-crt-shutdown-integration/README.md). Run840 was named in earlier plans but its scope and artifacts could not be located.

## Acceptance and commands

Keep a SHA-addressed listing and decompilation outcome for each original function and account for unclassified bytes and unresolved edges. Prove new C/C++ behavior against original x86, check ABI and state ownership including overlapping ranges, then build and audit one frozen batch. Keep narrower domains partial. Use the [recovery procedure](../../../.agents/skills/porsche-recovery/SKILL.md) for a new packet and fresh attempt IDs.

From the repository root, these read or audit existing results. The shared audit needs the matching local build and native receipts.

```powershell
py -3 scripts/research/recovery-progress.py
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/846-audio-period-device-state/acceptance.json
```

[Run history](runs/) contains per-batch proofs, commands and known limits. The [full handoff through Run846](https://github.com/xfynx/prsche-disasm/blob/9bc538dcdaaa3915ac5d1e7e77dfd071d2056465/iterations/v2/001-original-recovery/PLAN.md) preserves prior assignments, hypotheses, exact verification commands and the compiler/ABI research trail.
