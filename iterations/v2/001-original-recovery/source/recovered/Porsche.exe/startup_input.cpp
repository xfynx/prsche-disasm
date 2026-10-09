#include "porsche/startup_input.hpp"
#include "porsche/files.hpp"
#include "porsche/heap.hpp"

namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
void* startup_direct_input_006a5b14=nullptr;
void* startup_keyboard_device_006a5b18=nullptr;
std::uint32_t startup_input_initialized_006a5b1c=0;
std::uint32_t startup_input_cleanup_registered_006a5b20=0;
void* startup_input_key_callback_005df6a4=nullptr;

namespace {
struct InputGuid {std::uint32_t a;std::uint16_t b,c;std::uint8_t d[8];};
struct DeviceObjectFormat {const InputGuid* guid;std::uint32_t offset,type,flags;};
struct DeviceDataFormat {std::uint32_t size,object_size,flags,data_size,object_count;const DeviceObjectFormat* objects;};
using ComResult=std::int32_t (__stdcall*)(void*);
using CreateDevice=std::int32_t (__stdcall*)(void*,const InputGuid*,void**,void*);
using QueryInterface=std::int32_t (__stdcall*)(void*,const InputGuid*,void**);
using SetDataFormat=std::int32_t (__stdcall*)(void*,const DeviceDataFormat*);
using SetCooperativeLevel=std::int32_t (__stdcall*)(void*,void*,std::uint32_t);

// Bytes are the original GUIDs and DIDATAFORMAT at 005bf970/005bf9b0/
// 005bf8c0/0056f9e0/0056e9e0, translated into native-addressable data.
constexpr InputGuid keyboard_key_guid{0x55728220,0xd33c,0x11cf,{0xbf,0xc7,0x44,0x45,0x53,0x54,0,0}};
constexpr InputGuid system_keyboard_guid{0x6f1d2b61,0xd5a0,0x11cf,{0xbf,0xc7,0x44,0x45,0x53,0x54,0,0}};
constexpr InputGuid keyboard_device2_guid{0x5944e682,0xc92e,0x11cf,{0xbf,0xc7,0x44,0x45,0x53,0x54,0,0}};
constexpr DeviceObjectFormat keyboard_objects[3]={{&keyboard_key_guid,0,0x8000000c,0},
    {&keyboard_key_guid,1,0x8000010c,0},{&keyboard_key_guid,2,0x8000020c,0}};
constexpr DeviceDataFormat keyboard_data_format{0x18,0x10,2,0x100,3,keyboard_objects};
void* vtable(void* object){return object?*static_cast<void**>(object):nullptr;}
template<class T>T method(void* object,std::uint32_t slot){
    return reinterpret_cast<T>(static_cast<void**>(vtable(object))[slot]);
}
}

// 0053bf90: reset the shared keyboard event ring and clamp capacity to 1..32.
void __cdecl startup_input_reset_key_ring_0053bf90(std::uint32_t count){
    auto signed_count=static_cast<std::int32_t>(count);
    if(signed_count>0x20)signed_count=0x20;else if(signed_count<1)signed_count=1;
    window_input_capacity_0069e560=static_cast<std::uint32_t>(signed_count);
    window_input_read_0069e0d8=0;window_input_write_0069e568=0;
}

// 0055fe50: state 0 resets the ring; state 10 installs the callback pointer.
std::uint32_t __cdecl startup_input_set_key_state_0055fe50(std::uint32_t state,void* value){
    if(!state){startup_input_reset_key_ring_0053bf90(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(value)));return 1;}
    if(state==10){startup_input_key_callback_005df6a4=value;return 1;}
    diagnostic_file_005deb74="\\real\\patch3\\pc\\key.c";diagnostic_line_005deb78=0x10a;
    diagnostic_handler_005debf0("[KEY] - Invalid setstate\n");
    return 0;
}

// 0055fe00: unacquire/release keyboard interface, then release DirectInput.
void __cdecl startup_input_release_0055fe00(){
    if(startup_keyboard_device_006a5b18){
        method<ComResult>(startup_keyboard_device_006a5b18,8)(startup_keyboard_device_006a5b18);
        method<ComResult>(startup_keyboard_device_006a5b18,2)(startup_keyboard_device_006a5b18);
        startup_keyboard_device_006a5b18=nullptr;
    }
    if(startup_direct_input_006a5b14){
        method<ComResult>(startup_direct_input_006a5b14,2)(startup_direct_input_006a5b14);
        startup_direct_input_006a5b14=nullptr;
    }
}

// 0055fe40: registered process-exit cleanup.
void __cdecl startup_input_exit_cleanup_0055fe40(){
    startup_input_release_0055fe00();startup_input_initialized_006a5b1c=0;
}

// 00557460: return the shared window handle used for cooperative input mode.
void* __cdecl startup_window_handle_00557460(){return window_hwnd_006b7bf8;}

// 0055fcf0..0055fdf4. COM methods remain direct vtable calls, preserving each
// original argument order/result branch; OS calls and callback registry are boundaries.
std::uint32_t __cdecl startup_input_initialize_0055fcf0(){
    if(!startup_input_initialized_006a5b1c){
        startup_input_initialized_006a5b1c=1;worker_accelerator_006bd9dc=0;
        if(!class_lock_0069e59c)class_lock_0069e59c=heap_lock_create_005321f0();
        startup_input_set_key_state_0055fe50(0,reinterpret_cast<void*>(0x20));
    }
    if(!startup_direct_input_006a5b14){
        if(startup_input_direct_input_create(startup_input_get_module_handle(),0x500,
                                              &startup_direct_input_006a5b14,nullptr)==0){
            void* temporary_device=nullptr;
            const auto create=method<CreateDevice>(startup_direct_input_006a5b14,3);
            if(create(startup_direct_input_006a5b14,&system_keyboard_guid,&temporary_device,nullptr)==0){
                const auto query=method<QueryInterface>(temporary_device,0);
                const auto query_result=query(temporary_device,&keyboard_device2_guid,
                                              &startup_keyboard_device_006a5b18);
                method<ComResult>(temporary_device,2)(temporary_device);
                if(query_result==0){
                    const auto set_format=method<SetDataFormat>(startup_keyboard_device_006a5b18,11);
                    if(set_format(startup_keyboard_device_006a5b18,&keyboard_data_format)==0){
                        const auto cooperative=method<SetCooperativeLevel>(startup_keyboard_device_006a5b18,13);
                        if(cooperative(startup_keyboard_device_006a5b18,startup_window_handle_00557460(),6)==0)
                            goto initialize_complete;
                    }
                }
            }
        }
        startup_input_release_0055fe00();
    }
initialize_complete:
    if(!startup_input_cleanup_registered_006a5b20){
        thread_exit_register_00557380(startup_input_exit_cleanup_0055fe40);
        startup_input_cleanup_registered_006a5b20=1;
    }
    return startup_input_initialized_006a5b1c;
}
}
