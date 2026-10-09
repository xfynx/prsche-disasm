cmake_minimum_required(VERSION 3.20)
project(thread_shutdown_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original x86 MSVC ABI required")
endif()
get_filename_component(ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
add_executable(thread_shutdown_probe
  "${ROOT}/source/recovered/thread_shutdown_probe.cpp"
  "${ROOT}/source/recovered/Porsche.exe/thread_shutdown.cpp"
  "${ROOT}/source/recovered/Porsche.exe/file_threads.cpp"
  "${ROOT}/source/recovered/Porsche.exe/file_pages.cpp"
  "${ROOT}/source/recovered/Porsche.exe/heap_locks.cpp")
target_include_directories(thread_shutdown_probe PRIVATE "${ROOT}/source/include")
target_compile_features(thread_shutdown_probe PRIVATE cxx_std_17)
target_compile_options(thread_shutdown_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(thread_shutdown_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
