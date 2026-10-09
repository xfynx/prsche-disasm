cmake_minimum_required(VERSION 3.20)
project(porsche_native_window_smoke LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original Win32 MSVC ABI required")
endif()
add_executable(native_window_smoke native_window.cpp
  ../../source/recovered/Porsche.exe/window_runtime.cpp
  ../../source/recovered/Porsche.exe/window_create.cpp
  ../../source/recovered/Porsche.exe/window_procedure.cpp)
target_include_directories(native_window_smoke PRIVATE ../../source/include)
target_compile_features(native_window_smoke PRIVATE cxx_std_17)
target_compile_definitions(native_window_smoke PRIVATE NOMINMAX _CRT_SECURE_NO_WARNINGS)
target_compile_options(native_window_smoke PRIVATE /W4 /EHsc /permissive- /Gy /Gw)
target_link_options(native_window_smoke PRIVATE /OPT:REF)
target_link_libraries(native_window_smoke PRIVATE user32 gdi32)
set_target_properties(native_window_smoke PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
