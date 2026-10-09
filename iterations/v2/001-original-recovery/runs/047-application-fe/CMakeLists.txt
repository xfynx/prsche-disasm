cmake_minimum_required(VERSION 3.20)
project(application_fe_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Original Win32 MSVC ABI required")
endif()
add_executable(application_fe_probe
  ../../source/recovered/application_fe_probe.cpp
  ../../source/recovered/Porsche.exe/fe_stream.cpp
  ../../source/recovered/Porsche.exe/application_fe.cpp)
target_include_directories(application_fe_probe PRIVATE ../../source/include)
target_compile_features(application_fe_probe PRIVATE cxx_std_17)
target_compile_definitions(application_fe_probe PRIVATE NOMINMAX _CRT_SECURE_NO_WARNINGS)
target_compile_options(application_fe_probe PRIVATE /W4 /EHsc /permissive-)
target_link_options(application_fe_probe PRIVATE /OPT:REF)
set_target_properties(application_fe_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
