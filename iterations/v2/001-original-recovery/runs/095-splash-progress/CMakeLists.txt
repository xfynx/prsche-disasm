cmake_minimum_required(VERSION 3.20)
project(porsche_splash_progress_095 LANGUAGES CXX)

if(NOT WIN32 OR NOT MSVC)
    message(FATAL_ERROR "Run095 probe requires native MSVC on Windows")
endif()

set(SOURCE_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../source")
add_executable(splash_progress_probe
    "${SOURCE_ROOT}/recovered/splash_progress_probe.cpp"
    "${SOURCE_ROOT}/recovered/Porsche.exe/splash_progress.cpp"
    "${SOURCE_ROOT}/recovered/Porsche.exe/application_state.cpp"
    "${SOURCE_ROOT}/recovered/Porsche.exe/application_globals.cpp")
target_include_directories(splash_progress_probe PRIVATE "${SOURCE_ROOT}/include")
target_compile_features(splash_progress_probe PRIVATE cxx_std_17)
target_compile_definitions(splash_progress_probe PRIVATE NOMINMAX _CRT_SECURE_NO_WARNINGS)
target_compile_options(splash_progress_probe PRIVATE /W4 /EHsc /permissive- /fp:precise)
set_target_properties(splash_progress_probe PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
