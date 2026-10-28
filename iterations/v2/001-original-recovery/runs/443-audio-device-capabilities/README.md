# Run443: original DirectSound capabilities

Five original bodies/636B and32B of raw GUID data. Native002 PASS:4,272 cases
across `/Od` and `/O2`,32,670 callback-state events,9 detected mutations. Complete
original/raw-index bytes, cdecl/stdcall stack and nonvolatile ABI, call ordering,
HRESULT conversion, output aliases and global reloads are checked.

The probe0058e650 composes original window0058f860, DirectSound thunk00597f70,
property probe0058ea90 and cleanup0058eba0. Six separate loader-zero cells were
unowned in the complete440 source/header closure. Both16B GUIDs are raw-pinned
before pointer transport. No mock COM implementation enters production.

`platform_audio_443.cpp` binds the original Windows exports. A nonexecuted
NOENTRY DLL linked only from its actual object and SDK import libraries imports
DSOUND ordinal1 and USER32 GetDesktopWindow/GetForegroundWindow, matching the
original IAT identities. `evidence.json` pins the DLL, object and libraries.
The actual game link needs `dsound.lib`; existing USER32 linkage is reused.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/443-audio-device-capabilities/native-config.json --attempt 002
```

Frozen receipt: `local/experiments/v2-audio-device-capabilities-443/002/receipt.json`.
Attempt001 preserves a fixture assembly-variable naming compile failure; the
production code was unchanged. Run444 owns integration and shared acceptance.

Only caps.size is initialized. Successful GetCaps must write flags/capacity, and
successful QuerySupport must write its output mask; error paths do not inspect
those unwritten fields. Other caps bytes remain opaque. Controlled COM/IAT
transport does not establish live DirectSound/devices, concurrency, malformed
interfaces or full game startup. Incidental EAX values from void-used helpers
are not invented scalar return contracts.
