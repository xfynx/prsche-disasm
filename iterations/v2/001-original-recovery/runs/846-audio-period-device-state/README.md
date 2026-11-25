# Run846 audio period callback

The Run843 link traced its last reference to `audio_system_active_006b499c` to
`00590250`. The Porsche.exe index and [Run697 evidence](../697-audio-period-callback-and-probe-message/scope-evidence.json)
locate the original active byte at device state `006b48c0 + 0xdc`.
The setter now reads that byte before the notify stores and writes the address
of the recovered Run703 callback into `006b4898`. Runs455 and 462 call that cell.
The fixture checks the PE immediate at body offset `0x1c` before relocating it.

Native attempt 001 passed 1,280 original comparisons per build at `/Od` and
`/O2`. The adjacent-byte and unrelocated-callback mutations both diverged.
Coverage includes Run690 group-zero selectors and the existing bank message
cases. Other selectors and live audio playback remain open.

The [shared audit](validation.json) passed with 489 translation units, 1,214
source pins and 36 unresolved names / 39 references. One name closed, zero
opened. The registry still has 1,473 entries. The game executable remains unlinked.
