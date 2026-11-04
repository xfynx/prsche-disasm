// Link infrastructure probe only; no original game algorithm.
extern "C" __declspec(dllimport) void __stdcall ExitProcess(unsigned);
#pragma comment(linker,"/alternatename:?network_lifecycle_wait_0053c380@porsche@@YAXH@Z=?application_audio_wait_0053c380@porsche@@YAXH@Z")
namespace porsche {
void __cdecl application_audio_wait_0053c380(int value){if(value==-1234567)ExitProcess(0);}
}
