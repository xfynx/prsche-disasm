cmake_minimum_required(VERSION 3.24)
project(resource_dispatch_113 LANGUAGES CXX)

if(NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Run 113 requires the Win32 x86 MSVC ABI")
endif()

add_executable(resource_dispatch_probe
  ../../source/recovered/resource_dispatch_probe.cpp
  ../../source/recovered/Porsche.exe/resource_dispatch.cpp)
target_include_directories(resource_dispatch_probe PRIVATE ../../source/include)
target_compile_features(resource_dispatch_probe PRIVATE cxx_std_17)
target_compile_options(resource_dispatch_probe PRIVATE /W4 /permissive- /EHsc)
target_compile_definitions(resource_dispatch_probe PRIVATE NOMINMAX)
