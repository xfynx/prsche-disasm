#include "modem_configuration.hpp"
#include <cstring>
namespace porsche {
using U=std::uint32_t;
using I=std::int32_t;
static_assert(sizeof(void*)==4);
U tapi_getdevconfig_cache_006ad168=0;
U tapi_setdevconfig_cache_006ad2a0=0;
namespace {
const char get_name_005c1250[]="lineGetDevConfig";
const char set_name_005c12cc[]="lineSetDevConfig";
const char class_005bcb3c[]="comm/datamodem";
U address(const void* p){return static_cast<U>(reinterpret_cast<std::uintptr_t>(p));}
void* pointer(U value){return reinterpret_cast<void*>(static_cast<std::uintptr_t>(value));}
U load(U value){U result;std::memcpy(&result,pointer(value),4);return result;}
void store(U value,U data){std::memcpy(pointer(value),&data,4);}
template<class F,class... A>
I dispatch(U& cache,const char* name,A... args){
    if(cache==0){
        const I result=tapi_resolve_00584a60(name,&cache);
        if(result!=0){cache=0xffffffffu;return result;}
    }
    const U target=cache;
    if(target==0xffffffffu)return static_cast<I>(0x80000049u);
    return reinterpret_cast<F>(static_cast<std::uintptr_t>(target))(args...);
}
}
I __stdcall modem_line_get_dev_config_00584c05(U device,void* buffer,const char* device_class){
    using F=I(__stdcall*)(U,void*,const char*);
    return dispatch<F>(tapi_getdevconfig_cache_006ad168,get_name_005c1250,device,buffer,device_class);
}
I __stdcall modem_line_set_dev_config_00584e27(U device,const void* config,U size,const char* device_class){
    using F=I(__stdcall*)(U,const void*,U,const char*);
    return dispatch<F>(tapi_setdevconfig_cache_006ad2a0,set_name_005c12cc,device,config,size,device_class);
}
U __cdecl modem_line_configure_0055e340(U){
    alignas(4) unsigned char buffer[8000]={};
    const U base=address(buffer);
    store(base,8000);
    if(modem_line_get_dev_config_00584c05(modem_selected_device_005df478,buffer,class_005bcb3c)!=0)return 0;
    if(load(base+4u)>load(base))return 0;
    const U config=base+load(base+20u);
    const U device=modem_selected_device_005df478;
    store(config+0x5cu,load(config+0x5cu)&~7u);
    const U size=load(base+16u);
    return modem_line_set_dev_config_00584e27(device,pointer(config),size,class_005bcb3c)!=0?1u:0u;
}
}
