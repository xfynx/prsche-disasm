cmake_minimum_required(VERSION 3.20)
project(application_services_128_probe LANGUAGES CXX)
if(NOT MSVC OR NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Run 128 requires native MSVC Win32/x86")
endif()
set(ROOT "${CMAKE_CURRENT_LIST_DIR}/../..")
get_filename_component(ROOT "${ROOT}" ABSOLUTE)
add_executable(application_services_probe
  "${ROOT}/source/recovered/application_services_probe.cpp"
  "${ROOT}/source/recovered/Porsche.exe/application_services.cpp"
  "${ROOT}/source/recovered/Porsche.exe/application_state.cpp"
  "${ROOT}/source/recovered/Porsche.exe/install_paths_storage.cpp")
target_include_directories(application_services_probe PRIVATE "${ROOT}/source/include")
target_compile_features(application_services_probe PRIVATE cxx_std_17)
target_compile_definitions(application_services_probe PRIVATE NOMINMAX _CRT_SECURE_NO_WARNINGS)
target_compile_options(application_services_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(application_services_probe PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_library(application_service_platform_compile OBJECT
  "${ROOT}/source/platform/application_service_links.cpp")
target_include_directories(application_service_platform_compile PRIVATE "${ROOT}/source/include")
target_compile_features(application_service_platform_compile PRIVATE cxx_std_17)
target_compile_definitions(application_service_platform_compile PRIVATE NOMINMAX _CRT_SECURE_NO_WARNINGS)
target_compile_options(application_service_platform_compile PRIVATE /W4 /EHsc /permissive-)
