cmake_minimum_required(VERSION 3.20)
project(mouse_input_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original x86 MSVC ABI required")
endif()
add_executable(mouse_input_probe
  ../../source/recovered/mouse_input_probe.cpp
  ../../source/recovered/Porsche.exe/mouse_input.cpp)
target_include_directories(mouse_input_probe PRIVATE ../../source/include)
target_compile_features(mouse_input_probe PRIVATE cxx_std_17)
target_compile_options(mouse_input_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(mouse_input_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
