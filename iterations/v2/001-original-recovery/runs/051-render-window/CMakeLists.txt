cmake_minimum_required(VERSION 3.20)
project(render_window_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original x86 MSVC ABI required")
endif()
add_executable(render_window_probe
  ../../source/recovered/render_window_probe.cpp
  ../../source/recovered/Porsche.exe/render_window.cpp)
target_include_directories(render_window_probe PRIVATE ../../source/include)
target_compile_features(render_window_probe PRIVATE cxx_std_17)
target_compile_options(render_window_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(render_window_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
