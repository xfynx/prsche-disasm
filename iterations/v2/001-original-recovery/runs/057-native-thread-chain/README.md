# Run057 — original thread lifecycle on real Win32

This native x86 fixture composes the actual recovered implementations: thread init `0055f320`, table init `0055f3b0`, file thread start `0055f5f0`, caller-owned window thread start `0055f420`, trampoline `0055f4f0`, register/priority/unregister, and shutdown `0055f1c0/0055f200`. Heap lock pool/create/enter/leave/destroy and file page/event wrappers execute against Run055's actual Win32 imports.

Two workers exercise the argument-taking and no-argument start paths. A test gate keeps each worker alive until the parent duplicates the registered thread handle; this avoids confusing the original self-closing thread handle with a stable join handle. After joining, the registry's three fields must be cleared by the original unregister body. The actual registered shutdown callback runs and releases the thread registry and critical sections.

Only CRT fill and callback registration remain fixture boundaries: fill forwards to host memset; registration records the callback and the fixture later invokes exactly that function. These definitions are local to this executable and are not supplied to a game target. They do not claim reconstruction of CRT allocation/exit machinery. The worker, gate and validation are test infrastructure. This proves a real OS composition of recovered thread consumers, not the original game or original worker/window loop.

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/057-native-thread-chain -B local/builds/v2/native-thread-057 -G 'Visual Studio 17 2022' -A Win32
cmake --build local/builds/v2/native-thread-057 --config Release --target native_thread_smoke
& ./local/builds/v2/native-thread-057/bin/Release/native_thread_smoke.exe
```
