cmake_minimum_required(VERSION 3.20)
project(movie_header_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original x86 MSVC ABI required")
endif()
add_executable(movie_header_probe
  ../../source/recovered/movie_header_probe.cpp
  ../../source/recovered/Porsche.exe/movie_header.cpp)
target_include_directories(movie_header_probe PRIVATE ../../source/include)
target_compile_features(movie_header_probe PRIVATE cxx_std_17)
target_compile_options(movie_header_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(movie_header_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
