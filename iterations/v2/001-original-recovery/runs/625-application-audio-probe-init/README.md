# Run625 application audio probe init (`004a66b0`)

Bounded native x86-vs-C++ recovery proof for:
- `porsche::application_audio_probe_initialize_004a66b0` (`004a66b0..004a683d`, 398B, sha256 `a9ac30a2e2c2ddb8191cf4198eaf8c3932d6f3f4f2bbc5e7238cf3ce3b297e91`)
- Owned `.rdata` table `porsche::application_audio_mode_data_005b4ac0` (`005b4ac0..005b4b3f`, 128B, sha256 `1971f9131f19a90589aa38b61716f75b521469ab8ef7799874f5de89f991ef01`)

Reuses canonical declarations (`porsche/application_services.hpp`, `porsche/application_audio_init.hpp`, `porsche/application_audio_device.hpp`, `porsche/application_state.hpp`, `porsche/file_events.hpp`) without redefining `application_audio_device_configured_00655d40` or `application_audio_post_setup_004ab470`.

## Verification

- Attempt `002` (`local/experiments/v2-application-audio-probe-init-625/002/receipt.json`): **PASS** (`001` preserved prior to renaming `application_audio_probe_init_625.cpp` -> `application_audio_init_625.cpp` for `audit-v2-native-game-batch.py` game filename policy)
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/625-application-audio-probe-init/native-config.json --attempt 002`
  - `/Od` and `/O2` both compiled cleanly (`/W4`) and printed `application_audio_probe_init_original_x86_vs_cpp=PASS cases=249 events=1241`, verifying exact 128-byte `.rdata` table match and comparing relocated original x86 against C++ across `query_config` failure, `mode` `-8..5`, `gate` `0/1`, `descriptor[8]`/format scan/rate clamp boundaries, `create_device` failure without retry (`004a680b: jl 0x004a66db`), `timer_rate_005deb48` `CDQ; SUB; SAR` division, and mid-call callee state mutations.
  - Mutation controls (`wrong-create-failure-guard`, `wrong-mode-three-cutoff`, `wrong-interval-rounding`, `wrong-max-rate-clamp`) all exited `1` on `divergence`.

## Boundaries

Bounded test domain covers `mode` in `[-8, 5]`, descriptor format counts within the 124-byte `AudioInitDescriptor`, and test-only providers for `application_state_006573e8`, `application_audio_buffer_00655d44`, `application_audio_device_configured_00655d40`, `timer_rate_005deb48`, and callees `00565950`/`00565680`/`005656d0`/`00565720`/`0053c380`/`004ab470`. Mode values `< -8`, out-of-bounds descriptor format counts (`0x0b + count > 0x7c`), and production CMake/registry integration remain open.
