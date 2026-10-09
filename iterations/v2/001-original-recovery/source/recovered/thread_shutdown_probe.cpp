#include "porsche/thread_shutdown.hpp"
#include "porsche/file_threads.hpp"
#include "porsche/heap_locks.hpp"
#include "porsche/files.hpp"
#include <cstdint>
#include <iostream>

namespace porsche {
std::uint32_t events[256],event_args[256],event_count;
ThreadEntry table_fixture[8]{};
HeapLockCell table_lock_fixture{},start_lock_fixture{},free_lock_fixture{},other_lock_fixture{};
void event(std::uint32_t code,std::uint32_t arg){events[event_count]=code;event_args[event_count++]=arg;}
std::uint32_t pointer_id(const void* p){
  if(!p)return 0;
  if(p==table_fixture)return 10;
  if(p==&table_lock_fixture)return 1;
  if(p==&start_lock_fixture)return 2;
  if(p==&free_lock_fixture)return 3;
  if(p==&other_lock_fixture)return 99;
  return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));
}
std::uint32_t __stdcall platform_close_handle(void* h){event(3,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(h)));return 1;}
void __stdcall platform_enter_critical_section(void* p){event(1,pointer_id(p));}
void __stdcall platform_leave_critical_section(void* p){event(2,pointer_id(p));}
void __stdcall platform_delete_critical_section(void* p){event(5,pointer_id(p));}
void __stdcall platform_initialize_critical_section(void*){}
std::uint32_t __stdcall platform_virtual_free(void* p,std::uint32_t,std::uint32_t){event(4,pointer_id(p));return 1;}
void __stdcall platform_system_info(void* data){auto* out=static_cast<std::uint32_t*>(data);for(int i=0;i<9;++i)out[i]=0;out[1]=4096;}
void* __stdcall platform_virtual_alloc(void*,std::uint32_t,std::uint32_t,std::uint32_t){return nullptr;}
void __cdecl heap_fill_0053c290(void* p,std::uint32_t value,std::uint32_t bytes){
  auto* b=static_cast<std::uint8_t*>(p);for(std::uint32_t i=0;i<bytes;++i)b[i]=static_cast<std::uint8_t>(value);
}
std::uint32_t __stdcall platform_current_thread_id(){return 0;}
void* __stdcall platform_current_process(){return nullptr;}
void* __stdcall platform_current_thread(){return nullptr;}
std::uint32_t __stdcall platform_duplicate_handle(void*,void*,void*,void** out,std::uint32_t,std::int32_t,std::uint32_t){*out=nullptr;return 0;}
void* __stdcall platform_create_thread(void*,std::uint32_t,ThreadBootstrap,void*,std::uint32_t,std::uint32_t*){return nullptr;}
std::uint32_t __stdcall platform_resume_thread(void*){return 0;}
std::uint32_t __stdcall platform_thread_priority(void*,std::int32_t){return 0;}
void __cdecl thread_exit_register_00557380(void(__cdecl*)()){}
std::uint32_t __stdcall platform_sleep(std::uint32_t,std::int32_t){return 0;}
}

static std::uint32_t map_ptr(const void* p){return p?static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p)):0;}
int main(){
  std::uint32_t mode,initialized,table_present,cap,main_present,start_present,table_lock_present,free_head,n;
  while(std::cin>>mode>>initialized>>table_present>>cap>>main_present>>start_present>>table_lock_present>>free_head>>n){
    using namespace porsche;
    for(auto& entry:table_fixture)entry={};table_lock_fixture={};start_lock_fixture={};free_lock_fixture={};other_lock_fixture={};
    for(std::uint32_t i=0;i<n && i<8;++i){
      std::uint32_t handle;std::cin>>table_fixture[i].serial>>handle>>table_fixture[i].id;
      table_fixture[i].handle=reinterpret_cast<void*>(static_cast<std::uintptr_t>(handle));
    }
    event_count=0;heap_lock_free_0069cb04=free_head==1?&table_lock_fixture:free_head==2?&start_lock_fixture:free_head==3?&free_lock_fixture:free_head==9?&other_lock_fixture:nullptr;
    thread_entries_006a57e4=table_present?table_fixture:nullptr;thread_capacity_006a57e8=static_cast<std::int32_t>(cap);
    main_thread_006a57d0=main_present?reinterpret_cast<void*>(0x1111u):nullptr;
    thread_start_lock_006a57d8=start_present?&start_lock_fixture:nullptr;
    thread_table_lock_006a57ec=table_lock_present?&table_lock_fixture:nullptr;
    threads_initialized_006a57dc=initialized;main_thread_id_006a57d4=0x12345678;
    thread_exit_registered_006a57e0=0x89abcdef;thread_serial_005df6a0=0x76543210;heap_lock_pool_count_005de000=23;
    if(mode==0)thread_shutdown_0055f1c0();else thread_table_cleanup_0055f200();
    std::cout<<threads_initialized_006a57dc<<' '<<map_ptr(main_thread_006a57d0)<<' '<<main_thread_id_006a57d4
      <<' '<<thread_exit_registered_006a57e0<<' '<<thread_serial_005df6a0<<' '
      <<(thread_entries_006a57e4?1:0)<<' '<<static_cast<std::uint32_t>(thread_capacity_006a57e8)<<' '
      <<(thread_start_lock_006a57d8?2:0)<<' '<<(thread_table_lock_006a57ec?1:0)<<' '
      <<pointer_id(heap_lock_free_0069cb04)<<' '<<pointer_id(table_lock_fixture.next)<<' '<<table_lock_fixture.free_tag
      <<' '<<pointer_id(start_lock_fixture.next)<<' '<<start_lock_fixture.free_tag<<' '
      <<pointer_id(free_lock_fixture.next)<<' '<<free_lock_fixture.free_tag<<' '<<event_count;
    for(std::uint32_t i=0;i<event_count;++i)std::cout<<' '<<events[i]<<' '<<event_args[i];
    for(const auto& e:table_fixture)std::cout<<' '<<e.serial<<' '<<map_ptr(e.handle)<<' '<<e.id;
    std::cout<<'\n';
  }
}
