cmake_minimum_required(VERSION 3.20)
project(object_update_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original x86 MSVC ABI required")
endif()
add_executable(object_update_probe
  ../../source/recovered/object_update_probe.cpp
  ../../source/recovered/Porsche.exe/object_update.cpp)
target_include_directories(object_update_probe PRIVATE ../../source/include)
target_compile_features(object_update_probe PRIVATE cxx_std_17)
target_compile_options(object_update_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(object_update_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
