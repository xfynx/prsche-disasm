cmake_minimum_required(VERSION 3.24)
project(formatter_parser_124 LANGUAGES CXX)

if(NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4 OR NOT MSVC)
  message(FATAL_ERROR "Run 124 requires Win32 x86 MSVC")
endif()
add_executable(formatter_parser_probe
  ../../source/recovered/formatter_parser_probe.cpp
  ../../source/recovered/Porsche.exe/formatter_parser.cpp
  ../../source/recovered/Porsche.exe/formatter_original.cpp)
target_include_directories(formatter_parser_probe PRIVATE ../../source/include)
target_compile_features(formatter_parser_probe PRIVATE cxx_std_17)
target_compile_options(formatter_parser_probe PRIVATE /W4 /permissive-)
