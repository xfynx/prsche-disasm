cmake_minimum_required(VERSION 3.20)
project(porsche_native_thread_chain LANGUAGES CXX)
if(NOT MSVC OR NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
    message(FATAL_ERROR "Native MSVC Win32/x86 required")
endif()
get_filename_component(ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
add_subdirectory(../055-native-platform platform)
add_executable(native_thread_smoke native_thread.cpp
    "${ROOT}/source/recovered/Porsche.exe/file_threads.cpp"
    "${ROOT}/source/recovered/Porsche.exe/window_threads.cpp"
    "${ROOT}/source/recovered/Porsche.exe/thread_shutdown.cpp"
    "${ROOT}/source/recovered/Porsche.exe/heap_locks.cpp"
    "${ROOT}/source/recovered/Porsche.exe/file_pages.cpp"
    "${ROOT}/source/recovered/Porsche.exe/file_events.cpp")
target_link_libraries(native_thread_smoke PRIVATE porsche_platform_win32)
target_compile_definitions(native_thread_smoke PRIVATE NOMINMAX WIN32_LEAN_AND_MEAN _CRT_SECURE_NO_WARNINGS)
target_compile_options(native_thread_smoke PRIVATE /W4 /EHsc /permissive-)
set_target_properties(native_thread_smoke PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
