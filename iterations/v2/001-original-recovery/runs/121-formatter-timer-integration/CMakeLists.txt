cmake_minimum_required(VERSION 3.24)
project(startup_timing_integration_121 LANGUAGES CXX)
if(NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4 OR NOT MSVC)
  message(FATAL_ERROR "Run 121 requires the original Win32 x86 MSVC ABI")
endif()

set(ROOT "${CMAKE_CURRENT_LIST_DIR}/../..")
get_filename_component(ROOT "${ROOT}" ABSOLUTE)
add_executable(startup_timing_integration_probe
  "${ROOT}/source/recovered/startup_timing_integration_probe.cpp"
  "${ROOT}/source/recovered/Porsche.exe/timer_setup.cpp"
  "${ROOT}/source/recovered/Porsche.exe/clock_worker.cpp"
  "${ROOT}/source/recovered/Porsche.exe/file_events.cpp"
  "${ROOT}/source/recovered/Porsche.exe/auxiliary_wait.cpp"
  "${ROOT}/source/recovered/Porsche.exe/formatter_original.cpp"
  "${ROOT}/source/recovered/Porsche.exe/shared_runtime_globals.cpp"
  "${ROOT}/source/recovered/Porsche.exe/window_runtime.cpp"
  "${ROOT}/source/platform/startup_timer_links.cpp")
target_include_directories(startup_timing_integration_probe PRIVATE "${ROOT}/source/include")
target_compile_features(startup_timing_integration_probe PRIVATE cxx_std_17)
target_compile_definitions(startup_timing_integration_probe PRIVATE NOMINMAX _CRT_SECURE_NO_WARNINGS)
target_compile_options(startup_timing_integration_probe PRIVATE /W4 /EHsc /permissive-)
target_link_libraries(startup_timing_integration_probe PRIVATE winmm)
set_target_properties(startup_timing_integration_probe PROPERTIES
  CXX_EXTENSIONS OFF
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
