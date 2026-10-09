cmake_minimum_required(VERSION 3.20)
project(object_cleanup_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original x86 MSVC ABI required")
endif()
add_executable(object_cleanup_probe
  ../../source/recovered/object_cleanup_probe.cpp
  ../../source/recovered/Porsche.exe/object_cleanup.cpp)
target_include_directories(object_cleanup_probe PRIVATE ../../source/include)
target_compile_features(object_cleanup_probe PRIVATE cxx_std_17)
target_compile_options(object_cleanup_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(object_cleanup_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
