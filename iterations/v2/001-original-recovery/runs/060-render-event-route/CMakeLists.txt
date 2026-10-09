cmake_minimum_required(VERSION 3.20)
project(render_event_route_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original x86 MSVC ABI required")
endif()
add_executable(render_event_route_probe
  ../../source/recovered/render_event_route_probe.cpp
  ../../source/recovered/Porsche.exe/render_event_route.cpp
  ../../source/recovered/Porsche.exe/mouse_input.cpp
  ../../source/recovered/Porsche.exe/render_driver_calls.cpp)
target_include_directories(render_event_route_probe PRIVATE ../../source/include)
target_compile_features(render_event_route_probe PRIVATE cxx_std_17)
target_compile_options(render_event_route_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(render_event_route_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
