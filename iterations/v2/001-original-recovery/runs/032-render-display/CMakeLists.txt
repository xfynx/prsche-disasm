cmake_minimum_required(VERSION 3.20)
project(render_display_original_probe LANGUAGES CXX)
if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
    message(FATAL_ERROR "Run 032 probe requires MSVC Win32/x86")
endif()
set(SOURCE_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../source")
add_executable(render_display_probe
    "${SOURCE_ROOT}/recovered/render_display_probe.cpp"
    "${SOURCE_ROOT}/recovered/Porsche.exe/render_display.cpp"
    "${SOURCE_ROOT}/recovered/Porsche.exe/render_objects.cpp")
target_include_directories(render_display_probe PRIVATE "${SOURCE_ROOT}/include")
target_compile_features(render_display_probe PRIVATE cxx_std_17)
target_compile_options(render_display_probe PRIVATE /W4 /EHsc /permissive-)
target_compile_definitions(render_display_probe PRIVATE NOMINMAX _CRT_SECURE_NO_WARNINGS)
set_target_properties(render_display_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
