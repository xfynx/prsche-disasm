cmake_minimum_required(VERSION 3.24)
project(window_thread_start_probe LANGUAGES CXX)
if(NOT MSVC OR NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Run 044 requires native MSVC Win32/x86")
endif()
set(ROOT "${CMAKE_CURRENT_LIST_DIR}/../..")
get_filename_component(ROOT "${ROOT}" ABSOLUTE)
add_executable(window_thread_start_probe
  "${ROOT}/source/recovered/window_threads_probe.cpp"
  "${ROOT}/source/recovered/Porsche.exe/window_threads.cpp"
  "${ROOT}/source/recovered/Porsche.exe/file_threads.cpp")
target_include_directories(window_thread_start_probe PRIVATE "${ROOT}/source/include")
target_compile_features(window_thread_start_probe PRIVATE cxx_std_17)
target_compile_options(window_thread_start_probe PRIVATE /W4 /EHsc /permissive-)
target_compile_definitions(window_thread_start_probe PRIVATE NOMINMAX _CRT_SECURE_NO_WARNINGS)
set_target_properties(window_thread_start_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
