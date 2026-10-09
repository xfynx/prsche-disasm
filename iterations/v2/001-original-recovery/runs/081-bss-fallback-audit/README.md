# Run081 — `005e8e50` fallback / heap-name storage audit

Original module: `Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The target was the duplicate native ownership at `005e8e50`: a 32-byte heap
name buffer and a one-byte file-name fallback. Evidence and index counts are
recorded in `evidence.json`.

The original image proves a zero byte at this VA, but not a 32-byte object.
The address is RVA `001e8e50`, after `.data`'s file-backed range
`001cb000..001e6fff` and inside its virtual range ending at VA `006c1538`.
The PE therefore supplies zero-filled virtual storage there; no raw file byte
or file offset exists for this address. Ghidra's data export records a zero
`/undefined1` at `005e8e50` and continues byte records through the surrounding
virtual region. These records establish initial byte contents, not C object
boundaries.

The address-reference index has 71 `READ` and 155 `DATA` references, with no
`WRITE` reference. The exported instruction listing has only two absolute
memory accesses to the VA, both reads: `004b7327` loads the default byte into
the caller's output when registry retrieval fails, and `004b74c0` loads it into
a local text buffer on the corresponding fallback path. The two registry
helpers are called from `00467470`, `0048dbe0`, `00509550`, `005099a0`,
`0041e170`, `004a5d20`, `004e04f0`, and `00508b70` (some have two call sites).
These calls show fallback consumers, not writers.

There are two additional proven string consumers. In `005684e0`, a null file
operation name is replaced with `005e8e50`; the function scans for NUL, allocates
`strlen + 1`, and copies that string. In `0059ebc0`, the address is passed as
the heap name to `005697f0`; heap initialization formats the name into LOW/HIGH
labels and copies it into the heap descriptor. `0059ebc0` is called by
`004e0760` and `0059e9d0`. The pointer is consumed as a C string and the first
byte is NUL. It is not evidence for a 32-byte source object. Other direct
`005697f0` callers use separate labels (`005c250c` / `RAM` and `005bbfdc`).

**Alias contract supported by current evidence:** both recovered names denote
views of the same zero-initialized empty-string sentinel at `005e8e50`. A
single canonical host storage with a one-byte zero string is sufficient for
the demonstrated reads and consumers; both APIs should reference that storage
rather than own separate objects. This is an observable-use contract, not a
claim that the original compiler declared an exact one-byte object. The full
original object extent remains unknown because the VA lies in a large
zero-filled section tail and no source-level boundary metadata is available.
No static direct write is indexed or present in the exported instructions, but
the audit does not cover undiscovered executable code or rule out an indirect
runtime writer. Before
changing production owners, check whether any heap lifecycle or file API passes
this pointer to an unknown writer; if not, consolidate the two native owners
to the shared empty-string backing while retaining the extent caveat.

No production files were changed. The audit uses only the indexed original
corpus, current recovered source declarations, and the PE inventory; the
original binary in `local/game` was read-only.
