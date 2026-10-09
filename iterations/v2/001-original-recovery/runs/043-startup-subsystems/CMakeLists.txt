cmake_minimum_required(VERSION 3.20)
project(startup_subsystems_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original Win32 MSVC ABI required")
endif()
add_executable(startup_subsystems_probe
  ../../source/recovered/startup_subsystems_probe.cpp
  ../../source/recovered/Porsche.exe/startup_subsystems.cpp)
target_include_directories(startup_subsystems_probe PRIVATE ../../source/include)
target_compile_features(startup_subsystems_probe PRIVATE cxx_std_17)
target_compile_definitions(startup_subsystems_probe PRIVATE NOMINMAX)
target_compile_options(startup_subsystems_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(startup_subsystems_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
