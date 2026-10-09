cmake_minimum_required(VERSION 3.24)
project(window_worker_original_probe LANGUAGES CXX)
if(NOT MSVC OR NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Run 035 requires native MSVC Win32/x86")
endif()
set(ROOT "${CMAKE_CURRENT_LIST_DIR}/../..")
get_filename_component(ROOT "${ROOT}" ABSOLUTE)
add_executable(window_worker_probe
  "${ROOT}/source/recovered/window_worker_probe.cpp"
  "${ROOT}/source/recovered/Porsche.exe/window_worker.cpp"
  "${ROOT}/source/recovered/Porsche.exe/window_runtime.cpp")
target_include_directories(window_worker_probe PRIVATE "${ROOT}/source/include")
target_compile_features(window_worker_probe PRIVATE cxx_std_17)
target_compile_options(window_worker_probe PRIVATE /W4 /EHsc /permissive-)
target_compile_definitions(window_worker_probe PRIVATE NOMINMAX _CRT_SECURE_NO_WARNINGS)
set_target_properties(window_worker_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
