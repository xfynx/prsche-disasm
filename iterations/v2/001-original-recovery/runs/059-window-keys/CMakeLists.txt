cmake_minimum_required(VERSION 3.20)
project(window_keys_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original x86 MSVC ABI required")
endif()
get_filename_component(ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
add_executable(window_keys_probe
  "${ROOT}/source/recovered/window_keys_probe.cpp"
  "${ROOT}/source/recovered/Porsche.exe/window_keys.cpp")
target_include_directories(window_keys_probe PRIVATE "${ROOT}/source/include")
target_compile_features(window_keys_probe PRIVATE cxx_std_17)
target_compile_options(window_keys_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(window_keys_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
