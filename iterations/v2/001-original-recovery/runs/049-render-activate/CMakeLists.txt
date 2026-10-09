cmake_minimum_required(VERSION 3.20)
project(render_activate_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original x86 MSVC ABI required")
endif()
add_executable(render_activate_probe
  ../../source/recovered/render_activate_probe.cpp
  ../../source/recovered/Porsche.exe/render_activate.cpp)
target_include_directories(render_activate_probe PRIVATE ../../source/include)
target_compile_features(render_activate_probe PRIVATE cxx_std_17)
target_compile_options(render_activate_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(render_activate_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
