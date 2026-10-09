cmake_minimum_required(VERSION 3.20)
project(application_arena_probe LANGUAGES CXX)
if(NOT MSVC OR NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Run 074 requires native MSVC Win32/x86")
endif()
set(SOURCE_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../source")
get_filename_component(SOURCE_ROOT "${SOURCE_ROOT}" ABSOLUTE)
add_executable(application_arena_probe
  "${SOURCE_ROOT}/recovered/application_arena_probe.cpp"
  "${SOURCE_ROOT}/recovered/Porsche.exe/application_state.cpp"
  "${SOURCE_ROOT}/recovered/Porsche.exe/application_globals.cpp")
target_include_directories(application_arena_probe PRIVATE "${SOURCE_ROOT}/include")
target_compile_features(application_arena_probe PRIVATE cxx_std_17)
target_compile_options(application_arena_probe PRIVATE /W4 /EHsc /permissive-)
target_compile_definitions(application_arena_probe PRIVATE NOMINMAX _CRT_SECURE_NO_WARNINGS)
set_target_properties(application_arena_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
