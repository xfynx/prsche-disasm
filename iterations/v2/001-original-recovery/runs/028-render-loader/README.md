# Run 028 — THRASH driver DLL loader 0x574fa0

Source `Porsche.exe` SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index query: consumer `0x57569b` → callee `0x574fa0` in
`research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl`, then
`functions.jsonl`, `references.jsonl`, `strings.jsonl` and complete
`0x574fa0..0x5755fd` assembly in
`research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`.
The original function has 1630 bytes, body SHA256
`eef719ec7468df19d74f170a5b47dbf935d0d3ad34a133ab4c39ce911ec19cde`.

The argument is a DLL name supplied by the caller. Null reports at source
`set3d.c:0x76` and returns zero. A nonnull name is formatted with `%s` at
`0x5ccb84`, passed to `LoadLibraryA` at `0x575001`, then, on failure,
formatted with `%sz` at `0x5c0dcc` and retried at `0x575024`. Both-fail
reports an error using `GetLastError` and DirectX version helper `0x574eb0`,
choosing the `<7` or `>=7` message; it returns zero. These are exact
branches, not an assumed fixed driver filename.

On load, 36 ordered `GetProcAddress` calls fill the THRASH table at
`0x6bd910..0x6bd9b8`, plus four aliases. Export names are the decorated
`_THRASH_*@N` strings at `0x5c0ac4..0x5c0dbc`. The validator at
`0x5752f2..0x575492` checks its required slots and frees a missing-export
DLL, reporting source line `0xf8`. `_THRASH_getstate@4` and
`_THRASH_tfree@4` can be absent; after validation they receive native
fallback addresses `0x574f80` and `0x574f90`. The GetModuleHandleA result,
when nonzero, is passed to DisableThreadLibraryCalls.

Success records the driver-name pointer at `0x6a64b4`, calls
`_THRASH_setstate@8(0x1f,0x6b)`, calls `0x594f00` with the cleanup token,
then calls `_THRASH_about@0`. About magic `0x33444658` or `0x33444632`
sets flag `0x5deb70`; other values leave it clear. The loader returns one.
The surrounding selector and driver implementation remain separate work.

The native source retains the original 43-word table and global state.
Win32 imports, formatter, DirectX helper, report callback, cleanup helper,
and exported calls are typed recording boundaries in the probe. This
establishes loader control flow and binding order, not behavior of those
libraries or a visible window. The next route is caller `0x575640` and the
selected DLL's `_THRASH_window@4` export (`0x6bd9b0`).

Verification (MSVC 19.44, Win32 Release):

    . ./scripts/tool-env.ps1
    cmake -S iterations/v2/001-original-recovery/runs/028-render-loader -B local/builds/v2/render-loader-028 -G 'Visual Studio 17 2022' -A Win32
    cmake --build local/builds/v2/render-loader-028 --config Release --target render_loader_probe
    py -3 scripts/research/verify-v2-render-loader.py

59/59 cases matched original Unicorn x86, comparing the complete export
table, globals, returns and ordered calls. Cases include every missing
export, primary/fallback load, null name, both DirectX error variants,
optional fallback exports, module handle, and about magic. Evidence and
fixture hashes are in `verification.json` and `source-functions.jsonl`.
