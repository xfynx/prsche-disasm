# Run585 frame interface release

Frozen native002 passes16 scenes (8 cases x Od/O2) and4 material controls; attempt001 is preserved. Production integration and acceptance live in [Run588](../588-frame-splash-integration/README.md). Original5693e0 (53B) and three loader-zero `.data` DWORDs `006a5ca0..006a5cab` (12B) are verified; all53 production instruction bytes match the original after five DIR32 normalizations.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/585-frame-interface-release/native-config.json --attempt 002
```
