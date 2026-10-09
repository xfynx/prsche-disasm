cmake_minimum_required(VERSION 3.20)
project(window_shutdown_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original x86 MSVC ABI required")
endif()
add_executable(window_shutdown_probe
  ../../source/recovered/window_shutdown_probe.cpp
  ../../source/recovered/Porsche.exe/window_shutdown.cpp
  ../../source/recovered/Porsche.exe/window_scheduler.cpp)
target_include_directories(window_shutdown_probe PRIVATE ../../source/include)
target_compile_features(window_shutdown_probe PRIVATE cxx_std_17)
target_compile_options(window_shutdown_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(window_shutdown_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
