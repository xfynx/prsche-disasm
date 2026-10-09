cmake_minimum_required(VERSION 3.20)
project(game_setup_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original x86 MSVC ABI required")
endif()
add_executable(game_setup_probe
  ../../source/recovered/game_setup_probe.cpp
  ../../source/recovered/Porsche.exe/game_setup.cpp)
target_include_directories(game_setup_probe PRIVATE ../../source/include)
target_compile_features(game_setup_probe PRIVATE cxx_std_17)
target_compile_options(game_setup_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(game_setup_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
