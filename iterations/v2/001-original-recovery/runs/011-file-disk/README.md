# Run 011 — physical disk backend

Source: `Porsche.exe` SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The recovered, x86-tested entries are `00591ce0` (info), `00591df0`
(read), `00592140` (seek), and `00592290` (close).

Index queries covered the four entries, their callers in `00568530` and
`00568900`, and the actual Porsche.exe IAT records: `ReadFile` `005b21f4`,
`SetFilePointer` `005b223c`, `CloseHandle` `005b2164`,
`UnmapViewOfFile` `005b21d8`, `SetLastError` `005b21a4`, and
`GetDiskFreeSpaceA` `005b2090`. The corrected IAT address calculation is
independently recorded in `research/binary-index/static/imports.jsonl`.

Confirmed from the listing and differential execution:

- Encoded physical handles are negative `~slot`; null storage, non-negative
  handles, out-of-range slots, and inactive slots set last error 6.
- The 32-byte `PhysicalFile` offsets already declared in `files.hpp` are
  consumed at `+0 active`, `+1 device`, `+2 I/O-active`, `+4 OS handle`,
  `+8 mode`, `+0c block`, `+10 mapping`, `+14 view`, `+18 cursor`, and
  `+1c size`. Names remain provisional.
- `006aeffc..006af07b` is 32 per-device mutex cells: `00591820` clears
  exactly `0x80` bytes and each recovered entry locks the cell selected by
  the byte at `+1`.
- Info copies mode/block/size and constructs the `GetDiskFreeSpaceA` root
  from immediate dword `005c3a20`, replacing its low byte: device 3 produces
  bytes `43 3a 5c 00` (`C:\\`). It writes bytes-per-sector times available
  clusters on success.
- Read clamps cursor/request with the original signed comparisons, preserves
  the mapped-view copy path and `SleepEx(0)`, and retries only
  `ERROR_IO_PENDING` after `SleepEx(1)`. Close unmaps/closes mapping before
  closing the OS handle, then clears active after releasing the mutex.

`verify-v2-file-disk.py` ran 31 fixtures through original x86 Unicorn and
the MSVC Win32 `disk_probe`; all four entries were covered. It compares the
complete `PhysicalFile` record, output buffer/destinations, return value, and
ordered mutex/Win32/sleep calls. Evidence is `verification.json` and
`source-functions.jsonl`.

The Win32 endpoints are recording services in this test, not real disk I/O;
real lock contention, OS pending-I/O completion, and a game launch are not
accepted. The report hashes all direct and transitive ABI headers used by the
probe.

`005919a0` remains deliberately unrecovered. It is a 673-byte open path
called by `00568900` and combines slot allocation (`00591c50`), per-device
mutex creation, `GetDiskFreeSpaceA`, `CreateFileA`, `GetFileSize`,
`CreateFileMappingA`, and `MapViewOfFile`. The next bounded step is a separate
x86 fixture for `005919a0` seeded by the `00568900` call contract, with each
allocation and Win32 failure branch recorded before any implementation.

Verification:

```powershell
py -3 scripts/research/verify-v2-file-disk.py
```
