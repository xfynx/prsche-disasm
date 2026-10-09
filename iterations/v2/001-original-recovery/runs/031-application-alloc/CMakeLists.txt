cmake_minimum_required(VERSION 3.20)
project(application_alloc_probe LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
add_executable(application_alloc_probe
  ../../source/recovered/application_alloc_probe.cpp
  ../../source/recovered/Porsche.exe/application_alloc.cpp)
target_include_directories(application_alloc_probe PRIVATE ../../source/include)
set_target_properties(application_alloc_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
