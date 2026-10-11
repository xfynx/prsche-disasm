cmake_minimum_required(VERSION 3.24)
project(formatter_cleanup_132 LANGUAGES CXX)

if(NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4 OR NOT MSVC)
  message(FATAL_ERROR "Run 132 requires Win32 x86 MSVC")
endif()

add_executable(formatter_cleanup_probe
  ../../source/recovered/formatter_cleanup_probe.cpp
  ../../source/recovered/Porsche.exe/formatter_cleanup.cpp
  ../../source/recovered/Porsche.exe/formatter_original.cpp)
target_include_directories(formatter_cleanup_probe PRIVATE ../../source/include)
target_compile_features(formatter_cleanup_probe PRIVATE cxx_std_17)
target_compile_options(formatter_cleanup_probe PRIVATE /W4 /permissive-)
