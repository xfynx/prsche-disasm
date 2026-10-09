# Run037 — application pool startup

Original `Porsche.exe` SHA256: `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Index queries: `rg '005679f0|00591820|00580630|005806e0|0056e5f0|00557380|005a2400|005a2382' research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d -g '*.jsonl'`; instructions were checked in `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`.

`005679f0` initializes only when `006a5c7c` is null. It defaults zero disk-slot and operation counts to 64, initializes the disk-slot table, creates the two global I/O lists, requests 0xe00 bytes for the device region and clears the rounded allocation, then requests the operation pool as `operation_count * 0x30`. It prepends every complete rounded 0x30-byte record to `006a5c58`; the rounded page count therefore controls the actual list length. It then creates the pool lock, writes `0xffffffff` to `006a5c74`, and registers callback `005678f0` through `00557380`.

The initial path of `00591820` creates the disk-slot lock if missing, enters it, defaults a zero capacity to 64, allocates `capacity * 0x20` through the existing `0056e5f0` page wrapper, stores the unrounded capacity, clears the rounded table and the 0x80-byte disk-mutex array on success, then leaves the lock. `00580630` and `005806e0` are reused from `file_device.cpp` and `io_worker_lists.cpp`; `0056e5f0` is reused from `file_pages.cpp`. The small `00557380` forwarding body is included. Its `005a2400`/`005a2382` callback-registry implementation remains an explicit boundary; the original body acquires/releases the registry lock and may grow the callback array through `005a8161`/`005a8029`.

`verify-v2-application-pool.py` compares native x86 and original x86 across 6 cases, including zero/default counts, small and larger rounded operation pools, custom disk capacities, and the already-initialized fast path. It compares globals, both list records, initialized arena bytes, and ordered lock/allocation/fill/callback-registration calls. The probe records `heap_lock_create`/enter/leave, fill, Win32 allocation, and callback-registry insertion as explicit boundaries. The original and native bodies execute `005679f0`, `00591820`, `00580630`, `005806e0`, and `0056e5f0`. `verification.json` pins the source and executable hashes.

The tested path begins with the original BSS state: no device table, disk table, or disk-slot lock. `00591820` reinitialization when its table already exists delegates the `005918c0` release path, and the registered `005678f0` shutdown callback is outside this startup slice. Allocation-failure behavior is also outside the probe because the original startup immediately fills the returned pointers without null checks. These cases are not claimed as recovered startup behavior.

Reproduce:

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/037-application-pool -B local/builds/v2/001-original-recovery/application-pool -G 'Visual Studio 17 2022' -A Win32
cmake --build local/builds/v2/001-original-recovery/application-pool --config Release --target application_pool_probe
py -3 scripts/research/verify-v2-application-pool.py
```
