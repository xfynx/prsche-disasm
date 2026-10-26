# Run433: modem configuration and canonical audio integration

Build003 compiles228 C++ translation units across8 projects. The link has184
unresolved names/191 references, down from190/198 in Run413. No game EXE exists.
Seven old names close; the real audio-channel child00565d60 is newly exposed.

Two frozen batches add15 original bodies/740B:

- [432](../432-modem-configuration/README.md): configuration0055e340 and two TAPI
  wrappers,289B;100,968 native cases across `/Od` and `/O2`,12 detected mutations.
  The existing caller's argument is ignored by the original body. Selected device,
  flag/size alias ordering and raw15B NUL-terminated class string are preserved.
- [434](../434-audio-canonical-bindings/README.md):12 audio helpers,451B;
  1,140 native cases across both optimizations,16 detected mutations. Four physical
  views use the accepted device-state owner. Only aligned24B critical-section
  storage is new; old421/422 files and historical proofs remain unchanged.

Shared audit PASS:102,108 cases,28 mutations,566 source pins and311 unique
canonical COFF providers. The actual source graph contains no fixture providers.
Registry ownership/dependencies reflect the15 new bodies; existing partial modem
callback/enumeration status is unchanged. No native proof was repeated for this
integration or documentation.

```powershell
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/433-startup-modem-audio-integration/build-config.json --phase configure --attempt 002
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/433-startup-modem-audio-integration/build-config.json --phase build --attempt 003
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/433-startup-modem-audio-integration/acceptance.json
```

Configure001 omitted an include directory required by receipt validation;002
declares it explicitly. Build002 stopped inside the sandbox before compiling;
its failed receipt is preserved. Build003 ran outside that restriction and
compiled every source. Earlier attempts are not relabelled as successful.

Remaining: real00565d60 composition,0058a8b0, the conflicting005659f0 ABI contracts,
audio allocation/initialization, live DLL/TAPI/device/allocator behavior,
concurrency and faulting/out-of-local domains. Full startup, display and gameplay
remain unaccepted. Next trace the audio stop consumer using the newly bound state.
