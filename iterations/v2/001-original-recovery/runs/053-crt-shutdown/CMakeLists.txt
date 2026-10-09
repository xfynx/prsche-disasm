cmake_minimum_required(VERSION 3.24)
project(crt_shutdown_probe LANGUAGES CXX)
if(NOT MSVC OR NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Run 053 requires native MSVC Win32/x86")
endif()
set(ROOT "${CMAKE_CURRENT_LIST_DIR}/../..")
get_filename_component(ROOT "${ROOT}" ABSOLUTE)
add_executable(crt_shutdown_probe
  "${ROOT}/source/recovered/exit_shutdown_probe.cpp"
  "${ROOT}/source/recovered/Porsche.exe/exit_shutdown.cpp"
  "${ROOT}/source/recovered/Porsche.exe/exit_registry.cpp")
target_include_directories(crt_shutdown_probe PRIVATE "${ROOT}/source/include")
target_compile_features(crt_shutdown_probe PRIVATE cxx_std_17)
target_compile_options(crt_shutdown_probe PRIVATE /W4 /EHsc /permissive-)
target_compile_definitions(crt_shutdown_probe PRIVATE NOMINMAX _CRT_SECURE_NO_WARNINGS)
set_target_properties(crt_shutdown_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
