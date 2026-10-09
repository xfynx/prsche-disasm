# Run 024 — renderer startup consumer 0x467470

Source: Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index query: `00467470` in functions/calls/references; the complete
`disassembly.asm` has 642 bytes through RET at 0x4676f1; body SHA256
`133bc54aa7ba8de306fa5feaa8bc50e5b9a2cbd18f9e45243bee84f6dde55582`.
Main startup
0x4b6a50 calls this consumer. The confirmed boundaries are allocator
0x59ef90, constructors 0x467700/0x4677e0, registry 0x4b7240/0x4b7340/
0x4b7220, formatter 0x5a0fbf, display 0x4b70d0, and 0x465df0/0x449b40.

The consumer allocates 0x118 bytes, calls the core constructor with the PE
publisher/title strings, stores 0x65b39c, and immediately calls vtable slot
zero using ECX=this. It copies the 0x657a38 selector. `registry` invokes
registry text key 0; empty text shows a setup error and terminates. `dx`
selects registry choice 1, appends `7`, then appends `z`; other nonempty text
appends `z` with selection zero. Registry key 2 supplies the resolution.
Other selectors format width/height from 0x657a48/0x657a4c and use selected
value 0x657a58. The consumer appends the resulting selector to the string
pointed to by 0x65b304, activates the core, allocates/constructs a 0x80-byte
display only if 0x628130 is null, passes its +0x7c/+0x74 fields to
0x4b70d0, then calls the two misc consumers.

Literal bytes confirmed from PE data: `registry` 0x5cf7bc, `dx` 0x5cf788,
`7` 0x5ccc2c, `z` 0x5cf784, `%dx%d` 0x5cf77c; publisher/title pointers
0x5d6f1c/0x5d6f20 resolve to `Electronic Arts` and
`Need for Speed - Porsche Unleashed`. Globals 0x65b39c and 0x628130 have no
existing recovered definitions and are stored separately; no FE alias was
inferred.

The probe uses controlled typed boundaries, including a real C++ virtual
slot-zero call. It compares ordered calls/arguments, selector bytes, display
object bytes, and global pointer presence on valid executions. Original
allocation-null followed by dereference is an observed fault and is not
accepted as a successful case; empty registry text invokes the nonreturning
setup path and is also excluded. String buffers are tested with bounded
values. This does not establish a working renderer or actual visual output.

Verification:

    powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1
    py -3 scripts/research/verify-v2-render-startup.py

All 26 valid cases matched original x86 and native C++ by the listed state,
returns and ordered calls. `verification.json` pins source/build dependency
SHA and fixtures; `source-functions.jsonl` pins the original body. This is
a bounded consumer proof with controlled callees, not constructor/registry/
display behavior acceptance or a visual test.
