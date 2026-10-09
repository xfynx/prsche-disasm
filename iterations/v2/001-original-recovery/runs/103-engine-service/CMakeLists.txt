cmake_minimum_required(VERSION 3.24)
project(engine_service_103 LANGUAGES CXX)

if(NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Run 103 requires the Win32 x86 MSVC ABI")
endif()

add_executable(engine_service_427a60_probe
  ../../source/recovered/engine_service_427a60_probe.cpp
  ../../source/recovered/Porsche.exe/engine_service_427a60.cpp)
target_include_directories(engine_service_427a60_probe PRIVATE ../../source/include)
target_compile_features(engine_service_427a60_probe PRIVATE cxx_std_17)
target_compile_options(engine_service_427a60_probe PRIVATE /W4 /permissive-)
