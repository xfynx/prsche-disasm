# Run844 — Network transport prerequisites

Run843's two constructor references at `0048fc8a` and `0048fc97` pass
the existing IPX and UDP labels to `00560a90` and `005607d0`. The
functions initialize transports and return zero or a pointer to the GUID at
descriptor offset four. [Run395](../395-network-options/README.md) proves both
initializer bodies with controlled dependencies. Its `002/receipt.json`
SHA-256 is `f12719d7d241237fed27bcb16dc4443689cf215e050b16a8e6be673e03e87834`.

Run844 recovers the directly called UDP availability probe at
`005839d0..00583a55` (134 bytes), including its 12-byte prefix image at
`005c11d8`. It starts Winsock 1.1, asks `00583740` for a local address,
rejects `127.` then `0.` through the existing `005a2210` comparison ABI,
and probes `socket(2, 1, 0)`. It closes any socket other than
`INVALID_SOCKET` and attempts cleanup on every successful WSA startup.
The 400-byte WSADATA buffer stays opaque. Original WSOCK32 thunk/IAT pairs
are `005894e6/005b2360`, `005894e0/005b2374`, `00587bd8/005b2380`,
and `00587bc0/005b23c0`. The address buffer at `006b4a80` and the
hostname and import endpoints remain external.

Native attempt 001 passed 10 original comparisons per optimization at
`/Od` and `/O2`, and detected three material mutations. The fixture checks
call order, arguments, zero and high-bit socket handles, cleanup effects,
EAX and stack/nonvolatile registers. Its comparison endpoint and Winsock
effects are controlled. The 32-byte test buffer is a fixture domain.
Receipt `local/experiments/v2-network-transport-844/001/receipt.json`,
SHA-256 `b9f5fb664ddd5d248e2c2cd00d460701f8daa8738d53dd5162696529fae83f94`.
REA 002 passed eight dossiers after default sandbox attempt 001 hit
`spawn EPERM`. Receipt
`local/experiments/v2-network-transport-844-rea/002/receipt.json`,
SHA-256 `2ae4513dfba000ace05e3e0e816d11718ca9973dc52433d5ef8c3eaf6996c647`.

The two Run843 symbols remain open. The two 96-byte descriptors carry 29
distinct callback targets without registry entries. Both initializer
paths append to the same count `006abe3c`, descriptor registry
`006b4aa0` and context registry `006b4ae0` as `00582240`. Consumer
`005801b0` reads the paired entries, checks context `+4`, compares a
descriptor GUID through `005802d0` when that field is zero, then calls the
live context callback at `+8` with six stack arguments. Context
`005e1cf0` has a relocation to `00587bf0` in that slot. Arithmetic
on the registry bases alone does not establish the registry extents.
Run558's sparse period-table views overlap both bases and the UDP address
buffer but are outside Run843's accepted source graph. Future ownership
must preserve those aliases. Start with the actual `00583740` output
writes and callers, followed by the registry/context and descriptor
bindings. Run844 stays outside game CMake and the function registry.
