cmake_minimum_required(VERSION 3.20)
project(window_links_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Win32 x86 MSVC ABI required")
endif()
add_executable(window_links_probe
  compile_fixture.cpp
  ../../source/platform/window_links.cpp
  ../../source/platform/win32_window.cpp
  ../../source/platform/win32_core.cpp
  ../../source/recovered/Porsche.exe/file_events.cpp
  ../../source/recovered/Porsche.exe/heap_locks.cpp
  ../../source/recovered/Porsche.exe/window_position.cpp
  ../../source/recovered/Porsche.exe/window_runtime.cpp)
target_include_directories(window_links_probe PRIVATE ../../source/include)
target_compile_features(window_links_probe PRIVATE cxx_std_17)
target_compile_options(window_links_probe PRIVATE /W4 /EHsc /permissive-)
target_link_libraries(window_links_probe PRIVATE user32 gdi32 kernel32)
set_target_properties(window_links_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
