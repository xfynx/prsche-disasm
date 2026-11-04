extern "C" __declspec(dllimport) void __stdcall ExitProcess(unsigned);
namespace porsche {void __cdecl network_lifecycle_wait_0053c380(int);void __cdecl application_audio_wait_0053c380(int);}
using Function=void(__cdecl*)(int);
Function volatile alias_pointer=porsche::network_lifecycle_wait_0053c380;
Function volatile provider_pointer=porsche::application_audio_wait_0053c380;
extern "C" void __cdecl alias_entry(){if(alias_pointer!=provider_pointer)ExitProcess(7);alias_pointer(-1234567);ExitProcess(8);}
