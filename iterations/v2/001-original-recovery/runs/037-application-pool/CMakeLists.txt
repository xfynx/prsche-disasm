cmake_minimum_required(VERSION 3.20)
project(application_pool_probe LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
add_executable(application_pool_probe
  ../../source/recovered/application_pool_probe.cpp
  ../../source/recovered/Porsche.exe/application_pool.cpp
  ../../source/recovered/Porsche.exe/file_pages.cpp
  ../../source/recovered/Porsche.exe/file_device.cpp
  ../../source/recovered/Porsche.exe/io_worker_lists.cpp)
target_include_directories(application_pool_probe PRIVATE ../../source/include)
set_target_properties(application_pool_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
