# Run464: audio prepare, callback pump and signed clock wait

Six original helpers /156B:00565950 (59B),0053c380 (44B),0053c2e0 (6B),
00565930 (8B),00565940 (1B),0058ffd0 (38B). The two omitted callback entries
have raw PE/index evidence in `research/binary-index/supplemental/audio-probe-464.jsonl`.
Root465 owns shared REA and game integration; this worker did not launch either.

Frozen native003 PASS:149 cases /196 events at each of/Od and/O2 (298 cases /
392 events total),14 detected mutations. Original slabs compose all six bodies
with actual accepted scheduler registration/dispatch, canonical device storage,
clock-counter owner, focus getter and shared error-state owners. Controlled
callbacks provide finite clock advancement and mutate the signed callback count.
Unexecuted dependencies of reused owner TUs fail closed in the fixture; its dead
timer/window link leaves are not production state or tested helper providers.

The sole new state is loader-zero DWORD006a5c34. Complete247-TU source/header
closure (431 files) has no prior owner. Existing clock006b7c7c, device callback
slots/count and scheduler storage remain canonical. Native snapshots compare
full device/scheduler state, ordered callbacks, lazy registration, signed count
reloads, 32-bit deadline wrapping, ESP and nonvolatile ABI. The raw no-op retains
all incoming GPR/flags; MSVC emits equivalent RET0 (`c20000`) for the naked RET,
while the original is C3. COFF records this encoding explicitly; no byte-identity
claim or guessed scalar return is made.

The accepted network caller's `network_lifecycle_wait_0053c380(int32)` links to
the canonical audio wait at the same code address using `/alternatename`.
Original0048ea2a..0048ea33 pushes one argument, calls0053c380, removes4 stack
bytes and overwrites EAX with the next call. Native address equality and signed/
wrapped arguments through both names are verified. This alias adds no body count.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/464-audio-probe-startup/native-config.json --attempt 3
```

Receipt: `local/experiments/v2-audio-probe-startup-464/003/receipt.json`.
001 retained missing dead-owner fixture dependencies at link.002 passed both
native variants, but its unsigned-count mutation ran beyond valid callback
storage after a callback made the count negative.003 bounds the controlled
second callback so that the mutation produces a finite ordered-event divergence.
Production logic is unchanged. All numbered artifacts remain; native inputs are
final UTF-8 LF and frozen. Live scheduler/concurrency, invalid callback pointers,
unmapped tables and full application startup remain open.

The398B parent004a66b0 stays unresolved. Legacy131 was already partial because
arbitrary signed negative modes can index before its128B raw table window; no
new guard or cropped-table replacement is introduced. `mode-producer-navigation.json`
traces Audio.Quality through FELocalizedTextAccessor vtable005b518c/+28 getter
004bc4b0: flag+1d returns-1, otherwise raw field+18. Its constructor has four
localized choices and its setter clamps signed input, but all value/flag writers
and exact instance reachability still need proof. That trace is navigation only.
