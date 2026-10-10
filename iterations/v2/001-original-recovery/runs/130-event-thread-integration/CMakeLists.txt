cmake_minimum_required(VERSION 3.24)
project(event_thread_integration_probe LANGUAGES CXX)

if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Run 130 requires the original Win32 x86 ABI")
endif()

set(ROOT "${CMAKE_CURRENT_LIST_DIR}/../..")
get_filename_component(ROOT "${ROOT}" ABSOLUTE)
add_executable(event_thread_integration_probe
  "${ROOT}/source/recovered/event_thread_integration_probe.cpp"
  "${ROOT}/source/recovered/Porsche.exe/auxiliary_wait.cpp"
  "${ROOT}/source/recovered/Porsche.exe/event_lifecycle.cpp"
  "${ROOT}/source/recovered/Porsche.exe/thread_wait.cpp"
  "${ROOT}/source/recovered/Porsche.exe/shared_runtime_globals.cpp")
target_include_directories(event_thread_integration_probe PRIVATE "${ROOT}/source/include")
target_compile_features(event_thread_integration_probe PRIVATE cxx_std_17)
target_compile_definitions(event_thread_integration_probe PRIVATE NOMINMAX _CRT_SECURE_NO_WARNINGS)
target_compile_options(event_thread_integration_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(event_thread_integration_probe PROPERTIES
  CXX_EXTENSIONS OFF
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
