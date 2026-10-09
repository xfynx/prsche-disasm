cmake_minimum_required(VERSION 3.20)
project(window_exit_cleanup_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original x86 MSVC ABI required")
endif()
add_executable(window_exit_cleanup_probe
  ../../source/recovered/window_exit_cleanup_probe.cpp
  ../../source/recovered/Porsche.exe/window_exit_cleanup.cpp)
target_include_directories(window_exit_cleanup_probe PRIVATE ../../source/include)
target_compile_features(window_exit_cleanup_probe PRIVATE cxx_std_17)
target_compile_options(window_exit_cleanup_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(window_exit_cleanup_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
