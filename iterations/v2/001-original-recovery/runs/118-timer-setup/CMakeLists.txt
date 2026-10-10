cmake_minimum_required(VERSION 3.24)
project(timer_setup_00565030 LANGUAGES CXX)

if(NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Run 118 requires the original Win32 x86 ABI")
endif()

set(ROOT "${CMAKE_CURRENT_LIST_DIR}/../..")
get_filename_component(ROOT "${ROOT}" ABSOLUTE)
add_executable(timer_setup_probe
  "${ROOT}/source/recovered/timer_setup_probe.cpp"
  "${ROOT}/source/recovered/Porsche.exe/timer_setup.cpp"
  "${ROOT}/source/recovered/Porsche.exe/shared_runtime_globals.cpp")
target_include_directories(timer_setup_probe PRIVATE "${ROOT}/source/include")
target_compile_features(timer_setup_probe PRIVATE cxx_std_17)
target_compile_definitions(timer_setup_probe PRIVATE NOMINMAX _CRT_SECURE_NO_WARNINGS)
target_compile_options(timer_setup_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(timer_setup_probe PROPERTIES
  CXX_EXTENSIONS OFF
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
