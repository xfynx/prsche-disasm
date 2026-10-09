cmake_minimum_required(VERSION 3.20)
project(application_heap_init_probe LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
add_executable(application_heap_init_probe
  ../../source/recovered/application_heap_init_probe.cpp
  ../../source/recovered/Porsche.exe/application_heap_init.cpp
  ../../source/recovered/Porsche.exe/application_heap.cpp)
target_include_directories(application_heap_init_probe PRIVATE ../../source/include)
set_target_properties(application_heap_init_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
