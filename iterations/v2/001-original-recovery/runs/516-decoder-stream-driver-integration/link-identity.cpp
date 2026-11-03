// Infrastructure check: retain distinct original function identities when bodies match.
extern "C" __declspec(dllimport) void __stdcall ExitProcess(unsigned);
extern "C" __declspec(noinline) unsigned identity_zero_a(){return 0;}
extern "C" __declspec(noinline) unsigned identity_zero_b(){return 0;}
using Function=unsigned(__cdecl*)();
Function volatile first_identity=identity_zero_a,second_identity=identity_zero_b;
extern "C" void __cdecl identity_entry(){ExitProcess(first_identity!=second_identity?0u:1u);}
