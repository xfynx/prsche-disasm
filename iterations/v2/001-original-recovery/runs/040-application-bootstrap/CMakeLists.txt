cmake_minimum_required(VERSION 3.20)
project(application_bootstrap_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original Win32 MSVC ABI required")
endif()
add_executable(application_bootstrap_probe
  ../../source/recovered/application_bootstrap_probe.cpp
  ../../source/recovered/Porsche.exe/application_heap.cpp
  ../../source/recovered/Porsche.exe/application_heap_init.cpp
  ../../source/recovered/Porsche.exe/application_alloc.cpp
  ../../source/recovered/Porsche.exe/heap.cpp)
target_include_directories(application_bootstrap_probe PRIVATE ../../source/include)
target_compile_features(application_bootstrap_probe PRIVATE cxx_std_17)
target_compile_definitions(application_bootstrap_probe PRIVATE NOMINMAX _CRT_SECURE_NO_WARNINGS)
target_compile_options(application_bootstrap_probe PRIVATE /W4 /EHsc /permissive- /Gy /Gw)
target_link_options(application_bootstrap_probe PRIVATE /OPT:REF)
set_target_properties(application_bootstrap_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
