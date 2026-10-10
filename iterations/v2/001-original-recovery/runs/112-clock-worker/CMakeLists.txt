cmake_minimum_required(VERSION 3.24)
project(clock_worker_00565270 LANGUAGES CXX)

if(NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Run 112 requires the original Win32 x86 ABI")
endif()

set(ROOT "${CMAKE_CURRENT_LIST_DIR}/../..")
get_filename_component(ROOT "${ROOT}" ABSOLUTE)
add_executable(clock_worker_probe
  "${ROOT}/source/recovered/clock_worker_probe.cpp"
  "${ROOT}/source/recovered/Porsche.exe/clock_worker.cpp")
target_include_directories(clock_worker_probe PRIVATE "${ROOT}/source/include")
target_compile_features(clock_worker_probe PRIVATE cxx_std_17)
target_compile_definitions(clock_worker_probe PRIVATE NOMINMAX _CRT_SECURE_NO_WARNINGS)
target_compile_options(clock_worker_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(clock_worker_probe PROPERTIES
  CXX_EXTENSIONS OFF
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
