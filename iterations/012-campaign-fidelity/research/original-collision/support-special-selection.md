# Original special support-object selection

2026-10-05. `Porsche.exe` SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index queries for `0x628ba0`, `0x4876e0`, `0x47ee40`, `0x47eba0`,
`0x47dcf0`, `0x47ed90`, `0x4750b0`, `0x486690`, and `0x486c20` are saved
verbatim in [support-special-selection-source.jsonl](support-special-selection-source.jsonl).
That source also records selected lines and SHA256
`8fc17129cadd103ecb2e69484ffc040bee89f35afe64b1c7819a4778106f3ef4`
of the read-only asset `local/game/GameData/Track/animdefs.txt`.

## Producer and lookup

`0x471bed` calls scene setup `0x4876e0`. At `0x487823..0x48785a`, that
setup formats a path from global prefix `0x65b2b8` and literal
`animdefs.txt` (`0x5d05ec`), calls `0x47ee40` to allocate the eight-byte
global holder at `0x628ba0`, then calls `0x47eba0` with that path.
`0x47ee40` clears both holder pointers. `0x47eba0` reads the text, recognizes
`section:anim` and `section:audio`, and appends parsed records to separate
pointer vectors in the holder. Its `section:anim` parser at `0x47dcf0`
allocates an 0x8c-byte record, initializes `+8` to float 0.5 and `+0x10`
to zero, parses `tag` into the four-byte word at `+0` (uppercasing its four
bytes), and appends its pointer to the first vector via `0x525ae0`.
The exact runtime value of the path prefix has not been traced here; the
matching shipped asset is at `GameData/Track/animdefs.txt`.

`0x4751a4..0x4751ae` supplies `u32(Base+0x44)` to `0x47ed90` using the
first vector in `0x628ba0`. `0x47ed90` linearly compares that word with
`record+0`, returning the first exact match. If the first vector or query tag
is null it returns null; the global holder itself must be valid. With a
nonempty vector and an unmatched nonzero
tag it returns **the first animation record**, not null (`0x47edcc..d4`).
In the shipped file the first `SECTION:ANIM` is `ENDW` with `kBox`.
The lookup is therefore ordered and has a meaningful fallback; a map that
returns no entry on a miss would change behavior.

Read-only `inspect_crp.py` decoding of the 15 shipped track CRPs found
16,591 Base payloads: 12,405 have zero at `Base+0x44`, and 4,186 have a
nonzero tag. This is a resource census, not a replay of all lookup calls.

## Collision type and branch

`0x47dcf0` recognizes `collideType` at `0x47dfdc`; its comparisons at
`0x47e05d..0x47e145` write record `+0x10` as `kCylinder` = 1,
`kBox` = 2, or `kSmackable` = 3. The record default is 0. For example,
the file assigns `TEMP` to cylinder, `ENDW` to box, `SIGN` to smackable,
and `FNSH` to `0`; these values are resource data, not tag-name heuristics.

`0x4751bd..0x475335` checks the returned record's `+0x10`: type 1
allocates a 0x38-byte object and calls constructor `0x486690` (the
`+8` float and `+0x14` byte are read in this branch); type 2 allocates a
0x68-byte object and calls `0x486c20` using the scene-derived geometry.
Both append one pointer to the output vector and jump past the ordinary
static primitive loop. Null, 0, and 3 reach `0x47533a`, where Base record
byte zero gates the static primitive branch. This identifies why special
type 1/2 records differ from the static support path without assigning
untraced gameplay meaning to those shapes.

The producer of the **current** `Base+4` ordinal remains unresolved. The
special path reads `Base+0x44` independently of that ordinal. Next trace:
follow the writes selecting `Base+4` through the Base resource/object owner,
and replay `0x47eba0` with the shipped `animdefs.txt` before binding its
record order/fallback to runtime. This report is read-only; no game code
or resource has changed.
