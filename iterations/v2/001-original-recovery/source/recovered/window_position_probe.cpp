#include "porsche/window_position.hpp"
#include "porsche/window_state.hpp"
#include "porsche/window_worker.hpp"
#include <iostream>

namespace porsche {
OriginalWindowConfiguration config{};
std::uint32_t& window_running_006b7c14=config.running_006b7c14;
std::uint32_t& window_width_006b77b4=config.width_006b77b4;
std::uint32_t& window_height_006b77b8=config.height_006b77b8;
std::uint8_t& window_fullscreen_006b7c01=config.fullscreen_006b7c01;
std::int32_t& window_pos_x_006b7c08=config.pos_x_006b7c08;
std::int32_t& window_pos_y_006b7c0c=config.pos_y_006b7c0c;
void*& window_hwnd_006b7bf8=config.hwnd_006b7bf8;
std::uint32_t class_refcount_0069e594,window_saved_parameter_0069e57c,window_saved_parameter_0069e580;
const char* window_class_name_0069e5a8="DLL";
void* window_instance_006b7794=reinterpret_cast<void*>(0x4444u);
std::uint32_t window_override_0069e5b0;
std::int32_t window_override_x_006bda00,window_override_y_006bda04;
std::uint32_t spi_calls,remove_calls,unregister_calls,idle_calls,timed_calls,metrics_calls,resize_calls;
std::uint32_t spi_action[2],spi_ui[2],resize_args[5],clear_after;
std::uint32_t remove_args[4]{};
std::int32_t metric_x,metric_y;
WindowPositionRect client_rect_fixture{0,0,640,480},work_rect_fixture{0,0,1920,1080};
std::int32_t frame_left=-8,frame_top=-31,frame_right=8,frame_bottom=8,style_fixture=0x10,exstyle_fixture=0x20;
std::int32_t screen_origin_x=100,screen_origin_y=200;
std::uint32_t rect_calls,style_calls,adjust_calls,setpos_calls,client_to_screen_calls;
std::int32_t setpos_args[6];
std::uint32_t __stdcall window_system_parameters(std::uint32_t action,std::uint32_t ui,void*,std::uint32_t) {
  if(spi_calls<2){spi_action[spi_calls]=action;spi_ui[spi_calls]=ui;}++spi_calls;return 1;
}
std::uint32_t __cdecl window_position_remove_0053a8e0(std::uint32_t a,std::uint32_t b,std::uint32_t c,std::uint32_t d){++remove_calls;remove_args[0]=a;remove_args[1]=b;remove_args[2]=c;remove_args[3]=d;return 1;}
std::uint32_t __stdcall window_position_unregister_class(const char*,void*){++unregister_calls;return 1;}
std::uint32_t __cdecl window_position_idle_0055f740(std::uint32_t){++idle_calls;if(clear_after && idle_calls>=clear_after)window_hwnd_006b7bf8=nullptr;return 0;}
std::uint32_t __cdecl window_position_timed_005366e0(std::uint32_t){++timed_calls;return 0;}
std::int32_t __stdcall window_position_get_system_metrics(std::int32_t index){++metrics_calls;return index?metric_y:metric_x;}
std::uint32_t __stdcall window_position_get_client_rect(void*,WindowPositionRect* rect){++rect_calls;*rect=client_rect_fixture;return 1;}
std::int32_t __stdcall window_position_get_window_long(void*,std::int32_t index){++style_calls;return index==-20?exstyle_fixture:style_fixture;}
std::uint32_t __stdcall window_position_adjust_window_rect_ex(WindowPositionRect* rect,std::uint32_t,std::int32_t,std::uint32_t){
  ++adjust_calls;rect->left+=frame_left;rect->top+=frame_top;rect->right+=frame_right;rect->bottom+=frame_bottom;return 1;
}
std::uint32_t __stdcall window_position_system_parameters(std::uint32_t action,std::uint32_t ui,void* data,std::uint32_t flags){
  if(action==0x30){*static_cast<WindowPositionRect*>(data)=work_rect_fixture;return 1;}
  return window_system_parameters(action,ui,data,flags);
}
std::uint32_t __stdcall window_position_set_window_pos(void*,void*,std::int32_t x,std::int32_t y,std::int32_t w,std::int32_t h,std::uint32_t flags){
  ++setpos_calls;setpos_args[0]=x;setpos_args[1]=y;setpos_args[2]=w;setpos_args[3]=h;setpos_args[4]=static_cast<std::int32_t>(flags);return 1;
}
std::uint32_t __stdcall window_position_client_to_screen(void*,WindowPositionPoint* point){
  if(client_to_screen_calls++==0){point->x+=screen_origin_x;point->y+=screen_origin_y;}
  else {point->x+=screen_origin_x;point->y+=screen_origin_y;}return 1;
}
}
int main(){
  unsigned mode,hwnd,refs,saved1,saved2,cycles,mx,my,w,h;
  while(std::cin>>mode>>hwnd>>refs>>saved1>>saved2>>cycles>>mx>>my>>w>>h){
    using namespace porsche;
    config={};window_hwnd_006b7bf8=reinterpret_cast<void*>(hwnd?0x1234u:0u);class_refcount_0069e594=refs;
    window_saved_parameter_0069e57c=saved1;window_saved_parameter_0069e580=saved2;clear_after=cycles;
    spi_calls=remove_calls=unregister_calls=idle_calls=timed_calls=metrics_calls=resize_calls=0;
    rect_calls=style_calls=adjust_calls=setpos_calls=client_to_screen_calls=0;
    spi_action[0]=spi_action[1]=spi_ui[0]=spi_ui[1]=0;metric_x=static_cast<std::int32_t>(mx);metric_y=static_cast<std::int32_t>(my);
    for(auto& a:resize_args)a=0;
    for(auto& a:remove_args)a=0;
    window_pos_x_006b7c08=window_pos_y_006b7c0c=0;
    window_override_0069e5b0=mode==3?1u:0u;
    window_override_x_006bda00=static_cast<std::int32_t>(mx);window_override_y_006bda04=static_cast<std::int32_t>(my);
    if(mode==0)window_position_cleanup_0053bcb0();
    else if(mode==1)window_position_center_0053bec0(static_cast<std::int32_t>(w),static_cast<std::int32_t>(h));
    else window_position_resize_0053bd40(mode==3?0:static_cast<std::int32_t>(mx),mode==3?0:static_cast<std::int32_t>(my),static_cast<std::int32_t>(w),static_cast<std::int32_t>(h));
    std::cout<<class_refcount_0069e594<<' '<<static_cast<unsigned>(window_hwnd_006b7bf8!=nullptr)<<' '
      <<spi_calls<<' '<<remove_calls<<' '<<unregister_calls<<' '<<idle_calls<<' '<<timed_calls<<' '
      <<metrics_calls<<' '<<resize_calls<<' '<<spi_action[0]<<' '<<spi_action[1]<<' '<<spi_ui[0]<<' '<<spi_ui[1];
    for(auto a:resize_args)std::cout<<' '<<a;
    std::cout<<' '<<rect_calls<<' '<<style_calls<<' '<<adjust_calls<<' '<<setpos_calls<<' '<<client_to_screen_calls
      <<' '<<static_cast<std::uint32_t>(setpos_args[0])<<' '<<static_cast<std::uint32_t>(setpos_args[1])
      <<' '<<static_cast<std::uint32_t>(setpos_args[2])<<' '<<static_cast<std::uint32_t>(setpos_args[3])
      <<' '<<static_cast<std::uint32_t>(setpos_args[4])<<' '<<static_cast<std::uint32_t>(window_pos_x_006b7c08)
      <<' '<<static_cast<std::uint32_t>(window_pos_y_006b7c0c)<<' '<<window_width_006b77b4<<' '<<window_height_006b77b8;
    for(auto a:remove_args)std::cout<<' '<<a;
    std::cout<<'\n';
  }
}
