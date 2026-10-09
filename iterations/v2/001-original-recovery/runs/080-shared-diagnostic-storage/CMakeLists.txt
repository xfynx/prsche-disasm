cmake_minimum_required(VERSION 3.20)
project(shared_diagnostic_storage_probe LANGUAGES CXX)

get_filename_component(REPO_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../" ABSOLUTE)
set(SOURCE_ROOT "${REPO_ROOT}/iterations/v2/001-original-recovery/source")

add_executable(shared_diagnostic_storage_probe
    "${CMAKE_CURRENT_SOURCE_DIR}/shared_diagnostic_storage_probe.cpp"
    "${SOURCE_ROOT}/recovered/Porsche.exe/shared_runtime_globals.cpp")
target_include_directories(shared_diagnostic_storage_probe PRIVATE "${SOURCE_ROOT}/include")
target_compile_features(shared_diagnostic_storage_probe PRIVATE cxx_std_17)
if(MSVC)
    target_compile_options(shared_diagnostic_storage_probe PRIVATE /W4 /EHsc /permissive-)
    target_link_options(shared_diagnostic_storage_probe PRIVATE /machine:X86)
endif()
set_target_properties(shared_diagnostic_storage_probe PROPERTIES
    CXX_EXTENSIONS OFF
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
