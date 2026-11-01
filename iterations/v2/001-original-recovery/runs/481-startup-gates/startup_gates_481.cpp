// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// 00415dc0 /40B,004b0fa0 /55B,00560030 /19B. Exact6B newly owned data;
// application arena, frame flag and scheduler/event providers remain canonical.
#include "startup_gates_481.hpp"
#include "porsche/application_state.hpp"
#include "porsche/frame_pump.hpp"
#include "porsche/window_runtime.hpp"
#include "porsche/window_event_queue.hpp"
#include "porsche/file_disk.hpp"
namespace porsche {
namespace {std::uint8_t gate_bytes_005cc81c[2]={1,1};}
std::uint8_t& startup_gate_byte_005cc81c=gate_bytes_005cc81c[0];
std::uint8_t& startup_gate_byte_005cc81d=gate_bytes_005cc81c[1];
std::uint32_t startup_gate_word_00606ae8=0;
void __cdecl startup_sequence_call_00415dc0(){
    startup_gate_byte_005cc81c=1;
    startup_gate_byte_005cc81d=1;
    if(application_state_006573e8.words_[(0x657404-application_state_base_va)/4]<=4u) startup_gate_word_00606ae8=4;
}
void __cdecl startup_sequence_call_004b0fa0(){
    frame_pump_004b0d70();
    timed_callbacks_005366e0(0);
    while(frame_pump_byte_006573e0!=0){
        timed_callbacks_005366e0(0);
        file_sleep_0055f740(10);
    }
    frame_pump_004b0d70();
}
void __cdecl game_setup_update_00560030(){
    while(window_event_dequeue_0053aa60()!=0){}
}
}
