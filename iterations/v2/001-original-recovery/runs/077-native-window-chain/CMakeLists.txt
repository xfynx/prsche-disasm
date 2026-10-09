cmake_minimum_required(VERSION 3.20)
project(native_window_chain LANGUAGES CXX)

if(NOT MSVC OR NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Native MSVC Win32/x86 required")
endif()

get_filename_component(ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
set(REC "${ROOT}/source/recovered/Porsche.exe")
set(INC "${ROOT}/source/include")

add_executable(native_window_chain
  native_window_chain.cpp
  fixture_boundaries.cpp
  "${REC}/window_init.cpp"
  "${REC}/window_callback_bindings.cpp"
  "${REC}/window_channels.cpp"
  "${REC}/window_create.cpp"
  "${REC}/window_event_queue.cpp"
  "${REC}/window_handlers.cpp"
  "${REC}/window_keys.cpp"
  "${REC}/window_messages.cpp"
  "${REC}/window_position.cpp"
  "${REC}/window_procedure.cpp"
  "${REC}/window_runtime.cpp"
  "${REC}/window_state.cpp"
  "${REC}/window_threads.cpp"
  "${REC}/window_worker.cpp"
  "${REC}/file_threads.cpp"
  "${REC}/file_events.cpp"
  "${REC}/file_pages.cpp"
  "${REC}/heap.cpp"
  "${REC}/heap_locks.cpp"
  "${REC}/shared_runtime_globals.cpp"
  "${REC}/thread_shutdown.cpp"
  "${ROOT}/source/platform/win32_core.cpp"
  "${ROOT}/source/platform/win32_window.cpp"
  "${ROOT}/source/platform/window_links.cpp")

target_include_directories(native_window_chain PRIVATE "${INC}")
target_compile_features(native_window_chain PRIVATE cxx_std_17)
target_compile_definitions(native_window_chain PRIVATE NOMINMAX WIN32_LEAN_AND_MEAN)
target_compile_options(native_window_chain PRIVATE /W4 /EHsc /permissive-)
target_link_libraries(native_window_chain PRIVATE user32 gdi32 kernel32)
set_target_properties(native_window_chain PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
