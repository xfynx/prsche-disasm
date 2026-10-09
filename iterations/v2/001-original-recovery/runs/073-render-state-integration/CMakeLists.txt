cmake_minimum_required(VERSION 3.20)
project(render_state_integration_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original x86 MSVC ABI required")
endif()
add_executable(render_state_integration_probe
  ../../source/recovered/render_state_integration_probe.cpp
  ../../source/recovered/Porsche.exe/render_mode.cpp
  ../../source/recovered/Porsche.exe/render_settings.cpp
  ../../source/recovered/Porsche.exe/render_state_init.cpp
  ../../source/recovered/Porsche.exe/application_state.cpp
  ../../source/recovered/Porsche.exe/application_globals.cpp)
target_include_directories(render_state_integration_probe PRIVATE ../../source/include)
target_compile_features(render_state_integration_probe PRIVATE cxx_std_17)
target_compile_options(render_state_integration_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(render_state_integration_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
