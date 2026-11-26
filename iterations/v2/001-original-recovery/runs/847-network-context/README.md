# Run847 network context creation

The UDP/IPX contexts reach 00587bf0 through offset +8 of 005e1cf0.
005801b0 calls this cdecl callback with six stack arguments. Its 195 bytes and
two returns are recorded in the [index supplement](original-index-supplement.json).
REA attempt 002 could not resolve the missing function. The supplementary
CFG was decoded from the SHA-pinned PE and covers every instruction.

The callback increments the refcount at 006ad748 before startup. Failure at
startup or open retains that increment. On the first open it registers the
service while holding the shared lock. It reloads the transport descriptor
around calls, stores the handle and copies the identity and bounded names.
Native attempt 003 passed 56 comparisons across both builds and five mutations.
The [native config](native-config.json) identifies the original body and cases.

Standalone proof only. Real descriptor creation, refcount ownership and
receive/service callbacks 00582320 and 00587cc0 remain prerequisites for
production integration. See [Run844](../844-network-option-queries/README.md)
for the live initializer references, registry bases and descriptor overlap.
