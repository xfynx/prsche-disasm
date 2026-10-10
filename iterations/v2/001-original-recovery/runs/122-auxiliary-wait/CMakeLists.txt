cmake_minimum_required(VERSION 3.20)
project(auxiliary_wait_0053c270_probe LANGUAGES CXX)

if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Run 122 requires the original Win32 x86 ABI")
endif()

set(ROOT "${CMAKE_CURRENT_LIST_DIR}/../..")
get_filename_component(ROOT "${ROOT}" ABSOLUTE)
add_executable(auxiliary_wait_probe
  "${ROOT}/source/recovered/auxiliary_wait_probe.cpp"
  "${ROOT}/source/recovered/Porsche.exe/auxiliary_wait.cpp")
target_include_directories(auxiliary_wait_probe PRIVATE "${ROOT}/source/include")
target_compile_features(auxiliary_wait_probe PRIVATE cxx_std_17)
target_compile_options(auxiliary_wait_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(auxiliary_wait_probe PROPERTIES
  CXX_EXTENSIONS OFF
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
