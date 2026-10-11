cmake_minimum_required(VERSION 3.24)
project(formatter_integration_134 LANGUAGES CXX)

if(NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4 OR NOT MSVC)
  message(FATAL_ERROR "Run 134 requires Win32 x86 MSVC")
endif()

add_executable(formatter_integration_probe
  formatter_entry32_adapter.cpp
  formatter_integration_probe.cpp
  ../../source/recovered/Porsche.exe/formatter_entry.cpp
  ../../source/recovered/Porsche.exe/formatter_parser_entry_bridge.cpp
  ../../source/recovered/Porsche.exe/formatter_original.cpp
  ../../source/recovered/Porsche.exe/formatter_parser.cpp
  ../../source/recovered/Porsche.exe/formatter_cleanup.cpp
  ../../source/recovered/Porsche.exe/formatter_runtime.cpp
  ../../source/platform/formatter_runtime_links.cpp)
target_include_directories(formatter_integration_probe PRIVATE ../../source/include)
target_compile_features(formatter_integration_probe PRIVATE cxx_std_17)
target_compile_options(formatter_integration_probe PRIVATE /W4 /permissive-)
