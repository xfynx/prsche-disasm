cmake_minimum_required(VERSION 3.24)
project(formatter_entry_108 LANGUAGES CXX)

if(NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4 OR NOT MSVC)
  message(FATAL_ERROR "Run 108 requires the Win32 x86 MSVC ABI")
endif()

add_executable(formatter_entry_probe
  ../../source/recovered/formatter_entry_probe.cpp
  ../../source/recovered/Porsche.exe/formatter_entry.cpp)
target_include_directories(formatter_entry_probe PRIVATE ../../source/include)
target_compile_features(formatter_entry_probe PRIVATE cxx_std_17)
target_compile_options(formatter_entry_probe PRIVATE /W4 /permissive-)
