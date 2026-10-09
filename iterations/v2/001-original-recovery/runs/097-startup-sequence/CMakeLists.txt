cmake_minimum_required(VERSION 3.20)
project(startup_sequence_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original x86 MSVC ABI required")
endif()
add_executable(startup_sequence_probe
  ../../source/recovered/startup_sequence_probe.cpp
  ../../source/recovered/Porsche.exe/startup_sequence.cpp)
target_include_directories(startup_sequence_probe PRIVATE ../../source/include)
target_compile_features(startup_sequence_probe PRIVATE cxx_std_17)
target_compile_options(startup_sequence_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(startup_sequence_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
