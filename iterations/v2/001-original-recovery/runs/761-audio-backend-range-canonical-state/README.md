# Run761 audio backend range on canonical state

Run761 replaces Run755's typed extern placeholders with direct reads from Run434's `application_audio_device_state_006b48c0`. The voice limit is byte `+0x1d` (`006b48dd`); the priority limit is a signed word at `+0xe4` (`006b49a4`). This removes two unresolved names without adding duplicate storage.

Native x86 comparison passes at `/Od` and `/O2`: 327,680 cases per variant and 3/3 material mutations. The full shared audit against Run757 passes: 442 translation units, 100 unresolved names / 107 references, 1,092 source pins, and no executable. It closes both device-limit symbols, with no new linker names.

Controlled mapped state and valid pointers are covered. Device discovery, full voice allocation, hardware playback, startup, and gameplay remain open.
