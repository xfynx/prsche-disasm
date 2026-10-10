cmake_minimum_required(VERSION 3.24)
project(process_exit_115 LANGUAGES CXX)
if(NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Run 115 requires the Win32 x86 MSVC ABI")
endif()
add_executable(process_exit_probe
  ../../source/recovered/process_exit_probe.cpp
  ../../source/recovered/Porsche.exe/process_exit.cpp
  ../../source/recovered/Porsche.exe/exit_shutdown.cpp
  ../../source/recovered/Porsche.exe/exit_registry.cpp)
target_include_directories(process_exit_probe PRIVATE ../../source/include)
target_compile_features(process_exit_probe PRIVATE cxx_std_17)
target_compile_options(process_exit_probe PRIVATE /W4 /permissive- /EHsc)
target_compile_definitions(process_exit_probe PRIVATE NOMINMAX)
set_target_properties(process_exit_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
