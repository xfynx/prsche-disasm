cmake_minimum_required(VERSION 3.20)
project(window_callback_integration_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original x86 MSVC ABI required")
endif()
get_filename_component(ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
add_executable(window_callback_integration_probe
  "${ROOT}/source/recovered/window_callbacks_integration_probe.cpp"
  "${ROOT}/source/recovered/Porsche.exe/window_callback_bindings.cpp"
  "${ROOT}/source/recovered/Porsche.exe/window_handlers.cpp"
  "${ROOT}/source/recovered/Porsche.exe/window_procedure.cpp"
  "${ROOT}/source/recovered/Porsche.exe/window_messages.cpp"
  "${ROOT}/source/recovered/Porsche.exe/window_keys.cpp")
target_include_directories(window_callback_integration_probe PRIVATE "${ROOT}/source/include")
target_compile_features(window_callback_integration_probe PRIVATE cxx_std_17)
target_compile_options(window_callback_integration_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(window_callback_integration_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
