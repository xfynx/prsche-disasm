cmake_minimum_required(VERSION 3.20)
project(window_state_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Run039 requires MSVC x86 layout")
endif()
add_executable(window_state_probe
  ../../source/recovered/window_state_probe.cpp
  ../../source/recovered/Porsche.exe/window_create.cpp
  ../../source/recovered/Porsche.exe/window_worker.cpp
  ../../source/recovered/Porsche.exe/window_state.cpp)
target_include_directories(window_state_probe PRIVATE ../../source/include)
target_compile_features(window_state_probe PRIVATE cxx_std_17)
target_compile_options(window_state_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(window_state_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
