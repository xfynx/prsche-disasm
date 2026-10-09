cmake_minimum_required(VERSION 3.20)
project(frame_pump_004b0d70_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original x86 MSVC ABI required")
endif()
add_executable(frame_pump_probe
  ../../source/recovered/frame_pump_probe.cpp
  ../../source/recovered/Porsche.exe/frame_pump.cpp)
target_include_directories(frame_pump_probe PRIVATE ../../source/include)
target_compile_features(frame_pump_probe PRIVATE cxx_std_17)
target_compile_options(frame_pump_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(frame_pump_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
