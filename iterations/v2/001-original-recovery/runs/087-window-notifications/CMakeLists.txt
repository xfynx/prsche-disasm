cmake_minimum_required(VERSION 3.20)
project(window_notifications LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "MSVC x86 required")
endif()
get_filename_component(ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
add_executable(window_notifications_probe
  "${ROOT}/source/recovered/window_notifications_probe.cpp"
  "${ROOT}/source/recovered/Porsche.exe/window_input_bindings.cpp")
target_include_directories(window_notifications_probe PRIVATE "${ROOT}/source/include")
target_compile_features(window_notifications_probe PRIVATE cxx_std_17)
target_compile_options(window_notifications_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(window_notifications_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
