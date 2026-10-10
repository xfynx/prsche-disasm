cmake_minimum_required(VERSION 3.24)
project(thread_wait_0055fa10_probe LANGUAGES CXX)

if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Run 127 requires the original Win32 x86 ABI")
endif()

set(ROOT "${CMAKE_CURRENT_LIST_DIR}/../..")
get_filename_component(ROOT "${ROOT}" ABSOLUTE)
add_executable(thread_wait_probe
  "${ROOT}/source/recovered/thread_wait_probe.cpp"
  "${ROOT}/source/recovered/Porsche.exe/thread_wait.cpp")
target_include_directories(thread_wait_probe PRIVATE "${ROOT}/source/include")
target_compile_features(thread_wait_probe PRIVATE cxx_std_17)
target_compile_definitions(thread_wait_probe PRIVATE NOMINMAX _CRT_SECURE_NO_WARNINGS)
target_compile_options(thread_wait_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(thread_wait_probe PROPERTIES
  CXX_EXTENSIONS OFF
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
