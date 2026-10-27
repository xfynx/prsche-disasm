# Run440: audio pool allocation and voice cleanup

Build001 compiles232 C++ translation units across8 projects. Four existing names
close with no new unresolved child:181 names/188 references remain, no game EXE.
Five original bodies/836B are added; the void release facade adds no body count.

- [438](../438-audio-pool-allocator/README.md):0058aa60/0058aae0/0058ac30,476B;
  7,058 sequences/57,788 intermediate steps,16 detected mutations. Original raw
  allocator/clamp and434 configure compose; signed/wrapped sizes, header aliases,
  captured pool pointers and descriptor moves retain original ordering.
- [439](../439-audio-voice-cleanup/README.md):00597010/00589c00,360B;
  108,534 cases,16 mutations. Captured next pointers, embedded-node exclusions,
  signed counts, sentinel-prefix reads and timestamp reloads are preserved.

Shared audit PASS:115,592 native sequences/cases across `/Od` and `/O2`,32 mutations,
576 pins and322 unique canonical COFF exports. Existing434/435/device state is
reused without new physical storage. No fixture providers enter production.
Both frozen proofs were reused; integration built/audited once.

```powershell
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/440-audio-pool-cleanup-integration/build-config.json --phase configure --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/440-audio-pool-cleanup-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/440-audio-pool-cleanup-integration/acceptance.json
```

Full receipts/logs: `local/experiments/v2-audio-pool-cleanup-game-440`.
438 has a conservative C4701 offset warning; each path assigns before use.
439 attempt001 failed one mutation's loop cap;002 corrects that control with the
same production/fixture. Failed local receipts are preserved.

Native439 controls0058ac30; actual combined stop/voice/pool execution is not yet
claimed. Next prove that chain and positive parent returns deferred in435, reusing
the unchanged440 game build. Then trace startup initialization0058a4f0/0058a690.
00590070/00565990, live devices/platform/startup, malformed/cyclic or faulting memory,
concurrency and full gameplay remain open;403/411 remain PARTIAL.
