cmake_minimum_required(VERSION 3.20)
project(input_snapshot_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original x86 MSVC ABI required")
endif()
add_executable(input_snapshot_probe
  ../../source/recovered/input_snapshot_probe.cpp
  ../../source/recovered/Porsche.exe/input_snapshot.cpp
  ../../source/recovered/Porsche.exe/input_state.cpp
  ../../source/recovered/Porsche.exe/input_buffer.cpp
  ../../source/recovered/Porsche.exe/shared_runtime_globals.cpp)
target_include_directories(input_snapshot_probe PRIVATE ../../source/include)
target_compile_features(input_snapshot_probe PRIVATE cxx_std_17)
target_compile_options(input_snapshot_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(input_snapshot_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
