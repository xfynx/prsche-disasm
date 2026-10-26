#pragma once
#include "modem_caps_open.hpp"
#include "tapi_wrappers.hpp"
namespace porsche {
extern std::uint32_t tapi_getdevconfig_cache_006ad168;
extern std::uint32_t tapi_setdevconfig_cache_006ad2a0;
std::int32_t __stdcall modem_line_get_dev_config_00584c05(std::uint32_t,void*,const char*);
std::int32_t __stdcall modem_line_set_dev_config_00584e27(std::uint32_t,const void*,std::uint32_t,const char*);
}
