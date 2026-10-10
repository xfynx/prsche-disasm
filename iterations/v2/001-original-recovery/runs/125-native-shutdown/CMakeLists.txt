cmake_minimum_required(VERSION 3.24)
project(native_shutdown_125 LANGUAGES CXX)
if(NOT WIN32 OR NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Run125 requires MSVC Win32 x86")
endif()
add_executable(native_shutdown_probe
  native_shutdown_probe.cpp
  ../../source/platform/win32_shutdown.cpp)
target_include_directories(native_shutdown_probe PRIVATE ../../source/include)
target_compile_features(native_shutdown_probe PRIVATE cxx_std_17)
target_compile_options(native_shutdown_probe PRIVATE /W4 /EHsc /permissive-)
target_compile_definitions(native_shutdown_probe PRIVATE NOMINMAX WIN32_LEAN_AND_MEAN)
set_target_properties(native_shutdown_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
