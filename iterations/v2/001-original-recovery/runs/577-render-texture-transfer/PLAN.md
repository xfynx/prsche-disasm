# Run577: reachable texture allocation and transfer

Completed2026-11-16. Sol/Terra produced the original source/ownership drafts.
Luna/medium completed the shared fixture and execution. The strong coordinator
reviewed the compiled output and owns integration578 and publication. Baseline is accepted Run576 (321 TUs, 128 unresolved
names / 135 references, 792 pins / registry893). Original game assets and
passed proofs remain read-only; integration is coordinator-owned.

Original Porsche.exe SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Preliminary index/REA469 trace: 00554960/363B is cdecl6, pointer EAX; 00554d70/
107B is cdecl3. Startup constructor 00467cdc consumes allocation EAX, then
calls scheduler, copy and release. The allocator's driver callback and canonical
006a3a54 pointer write occur before dimension validation; original name copying
through the returned node occurs before its null test. Never invent a null guard.
The copy's actual 005556b0 child and allocator's actual 00554820 selector remain
explicit unless supplied by the independent child worker.

`scope-evidence.json` records the full 576 census: 321 compiled roots, 585
source/header files, 792 effective pins, no target/registered-body overlap and
no exact 006a3a54/005df2c8 data owner. 006a3a54 is an original loader-zero
DWORD; 005df2c8's original PE bytes encode 00554310. Both parent REA469 dossier
hashes match the passing cached-session receipt. 00555780 has an inclusive
65-byte body through RET and no registry overlap. Adjacent callback006a3a50,
pending006a3a58 and preferred-bytes005df2c4 remain separately owned.

Chosen five original bodies: parent 00554960/363B and 00554d70/107B, plus
Terra-owned selector00554820/255B, converter005556b0/205B and fallback00555780/
65B. The two production sources are frozen and integrated through Run578. Parent owns host-typed driver info pointer006a3a54; child
owns the comparator pointer005df2c8 initialized to a typed unresolved host
00554310 function. Actual comparator00554310 and conversion005350e0 remain
genuine unresolved children; no raw VA is used as a host function pointer.

Native005 and shared578 acceptance pass. The fixture reuses572/575 scaffolding
and actual546/521 helpers. Each compiler mode passes349 scenes/166 events with
eight material controls. The long-buffer expansion cases also exercise the
compiler vector loop. Failed001/002/004 and scalar003 are preserved. README578
owns exact commands, measured build results and unresolved domains. No active
worker assignments remain. Later work belongs to the next packet.
