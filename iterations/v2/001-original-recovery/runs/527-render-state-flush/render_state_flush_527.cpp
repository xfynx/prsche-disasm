// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Full535b00/51B +535a60/44B;112B mutable records +28B mutable callbacks.
#include "render_state_flush_527.hpp"
#include "render_buffer_523.hpp"
#include "porsche/render_mode.hpp"
#include "porsche/render_settings.hpp"
namespace porsche {
using U=std::uint32_t;
U render_state_flush_records_005de6bc[28]={5,0,7,1,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
U render_state_flush_callbacks_005de72c[7]={
    reinterpret_cast<U>(&render_buffer_state_00540480),
    reinterpret_cast<U>(&render_buffer_state_00540480),
    reinterpret_cast<U>(&render_buffer_state_00540480),
    reinterpret_cast<U>(&render_resource_option_state_00535a60),
    reinterpret_cast<U>(&render_buffer_state_00540480),
    reinterpret_cast<U>(&render_resource_texture_state_00535a90),
    reinterpret_cast<U>(&render_resource_texture_state_00535a90)
};
U __cdecl render_resource_option_state_00535a60(U key,U value){
    if(render_mode_option_0069dd1d!=0&&value!=0)value=3;
    return render_settings_set_state_006bd97c(key,value);
}
void __cdecl render_resource_flush_states_00535b00(){
    using Callback=U(__cdecl*)(U,U);
    // Original EDI walks5de72c..748 in4B steps; ESI walks two7-pair blocks.
    for(U i=0;i<7;++i){
        const U value1=render_state_flush_records_005de6bc[2*i+1];
        const U key1=render_state_flush_records_005de6bc[2*i];
        (void)reinterpret_cast<Callback>(render_state_flush_callbacks_005de72c[i])(key1,value1);
        const U value2=render_state_flush_records_005de6bc[2*i+15];
        const U key2=render_state_flush_records_005de6bc[2*i+14];
        (void)reinterpret_cast<Callback>(render_state_flush_callbacks_005de72c[i])(key2,value2);
    }
}
}
