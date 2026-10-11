cmake_minimum_required(VERSION 3.24)
project(formatter_runtime_storage_138 LANGUAGES CXX)

if(NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4 OR NOT MSVC)
  message(FATAL_ERROR "Run 138 requires Win32 x86 MSVC")
endif()

add_executable(formatter_runtime_storage_probe
  ../../source/recovered/formatter_runtime_storage_probe.cpp
  ../../source/recovered/Porsche.exe/formatter_runtime_storage.cpp)
target_include_directories(formatter_runtime_storage_probe PRIVATE ../../source/include)
target_compile_features(formatter_runtime_storage_probe PRIVATE cxx_std_17)
target_compile_options(formatter_runtime_storage_probe PRIVATE /W4 /permissive-)
