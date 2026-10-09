# Run087 - original resize notification and key-data bindings

Source: Porsche.exe SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index queries: `005df9b8`, `005654d0`, `006a5c2c`, `005df934`, `0069e5a0`
in references/functions; inspect disassembly and original PE section data.

The initialized callback cell at 005df9b8 contains VA 005654d0. Its complete
seven-byte body increments the unsigned DWORD at 006a5c2c, then returns with
EAX unchanged. The WM_SIZE/WM_PAINT consumers at 0053b3b1/0053b83b test the
pointer, invoke it without arguments, and ignore EAX. The native adapter
therefore uses a void callback; its own zero result is not an original EAX
claim. The counter has one canonical BSS owner.

Startup 00564e70 writes guest data VA 005df934 to the nullable table pointer
0069e5a0. The original keyboard slice 0053b47f..0053b4a2 reads the byte at
`table + ((lParam >> 16) & 0x7f)` or preserves that scan index when null.
Only those 128 consumed data bytes are recovered, with no full-object extent
claim. Unknown guest pointers and out-of-domain indices fail explicitly.

The differential probe checks the full counter body including unsigned wrap,
the original indirect notification consumer slice, and the exact keyboard
slice for all 128 scan indices with both pointer states. It verifies that
the native table bytes equal the original mapped PE bytes. Only 005654d0 is
a newly recovered full function. The adapters and slices are not counted as
additional full original functions. No game or GUI launch is claimed.

Build with this CMake directory as source, MSVC Win32 Release; then run
`py -3 scripts/research/verify-v2-window-notifications.py --probe <exe> --report <fresh-json>`.
