# Run120 — application-main DWORD storage

Index query: `00606a88|00606874|005e99f4` in Porsche references, recovered
declarations, and listing. These three unresolved game-link symbols are
declared by `application_main.hpp`; their only previous C++ definitions
belonged to its isolated probe.

Original module SHA256:
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The actual PE section headers place all three DWORDs beyond the raw `.data`
end `005e7000`, inside its virtual extent ending `006c1538`. Their initial
value is the loader's zero fill. Reading file bytes at VA minus image base
would be incorrect here.

`application_main_globals.cpp` supplies one address-named owner per DWORD.
The verifier checks all 56 indexed direct references (12, 2, and 42), their
DWORD operand width, and the actual instruction bytes against the pinned PE.
Application-main consumers include `004b6d8d/9f`, `004b6ee8`, and
`004b6f01/0c/1d/23`. Values do not establish gameplay meaning; no subsystem
behavior or additional recovered function is claimed.

```powershell
py -3 scripts/research/verify-v2-application-main-globals.py
```

Production integration and the next common build/link attempt belong to
Run117. The application-main isolated fixture retains its local storage,
without linking the production owner. Full startup and the subsequent
writers remain in [validation backlog](../../../../../docs/recovery-validation-backlog.md).
