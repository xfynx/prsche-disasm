cmake_minimum_required(VERSION 3.20)
project(frame_services_004ab150_004ab200_probe LANGUAGES CXX)
if(NOT MSVC OR NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Run 105 requires native MSVC Win32/x86")
endif()
set(ROOT "${CMAKE_CURRENT_LIST_DIR}/../..")
get_filename_component(ROOT "${ROOT}" ABSOLUTE)
add_executable(frame_services_probe
  "${ROOT}/source/recovered/frame_services_probe.cpp"
  "${ROOT}/source/recovered/Porsche.exe/frame_services.cpp"
  "${ROOT}/source/recovered/Porsche.exe/application_state.cpp")
target_include_directories(frame_services_probe PRIVATE "${ROOT}/source/include")
target_compile_features(frame_services_probe PRIVATE cxx_std_17)
target_compile_definitions(frame_services_probe PRIVATE NOMINMAX _CRT_SECURE_NO_WARNINGS)
target_compile_options(frame_services_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(frame_services_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
