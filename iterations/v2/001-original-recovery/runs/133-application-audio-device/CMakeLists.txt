cmake_minimum_required(VERSION 3.20)
project(application_audio_device_133_probe LANGUAGES CXX)
if(NOT MSVC OR NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Run 133 requires native MSVC Win32/x86")
endif()
set(ROOT "${CMAKE_CURRENT_LIST_DIR}/../..")
get_filename_component(ROOT "${ROOT}" ABSOLUTE)
add_executable(application_audio_device_probe
  "${ROOT}/source/recovered/application_audio_device_probe.cpp"
  "${ROOT}/source/recovered/Porsche.exe/application_audio_device.cpp")
target_include_directories(application_audio_device_probe PRIVATE "${ROOT}/source/include")
target_compile_features(application_audio_device_probe PRIVATE cxx_std_17)
target_compile_definitions(application_audio_device_probe PRIVATE NOMINMAX _CRT_SECURE_NO_WARNINGS)
target_compile_options(application_audio_device_probe PRIVATE /W4 /EHsc /permissive-)
set_target_properties(application_audio_device_probe PROPERTIES
  CXX_EXTENSIONS OFF
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
