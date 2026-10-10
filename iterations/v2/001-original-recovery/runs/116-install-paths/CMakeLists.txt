cmake_minimum_required(VERSION 3.24)
project(install_paths_116 LANGUAGES CXX)
if(NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Run 116 requires the Win32 x86 MSVC ABI")
endif()
add_executable(install_paths_probe
  ../../source/recovered/install_paths_probe.cpp
  ../../source/recovered/Porsche.exe/install_paths.cpp
  ../../source/recovered/Porsche.exe/install_paths_storage.cpp)
target_include_directories(install_paths_probe PRIVATE ../../source/include)
target_compile_features(install_paths_probe PRIVATE cxx_std_17)
target_compile_options(install_paths_probe PRIVATE /W4 /permissive- /EHsc)
target_compile_definitions(install_paths_probe PRIVATE NOMINMAX)
set_target_properties(install_paths_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
