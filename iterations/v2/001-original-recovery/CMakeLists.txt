cmake_minimum_required(VERSION 3.20)

project(porsche_v2_recovery_probe LANGUAGES CXX)
if(NOT MSVC)
    message(FATAL_ERROR "The measured v2 recovery toolchain is MSVC")
endif()

if(NOT WIN32)
    message(FATAL_ERROR "v2 native probe build requires Windows/MSVC; no cross-platform game target is defined")
endif()

if(NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
    message(FATAL_ERROR "v2 recovery probe must be configured as 32-bit Win32/x86 (pointer size is ${CMAKE_SIZEOF_VOID_P})")
endif()

set(PORSCHE_SOURCE_ROOT "${CMAKE_CURRENT_LIST_DIR}/source")
set(PORSCHE_RECOVERY_PROBE "${PORSCHE_SOURCE_ROOT}/recovered/recovery_probe.cpp")
set(PORSCHE_RECOVERY_INCLUDE "${PORSCHE_SOURCE_ROOT}/include")
set(PORSCHE_RECOVERY_SOURCES_FILE "${PORSCHE_SOURCE_ROOT}/recovered/sources.cmake")

if(NOT EXISTS "${PORSCHE_RECOVERY_PROBE}")
    message(FATAL_ERROR "No recovered source exists: expected ${PORSCHE_RECOVERY_PROBE}")
endif()

set(PORSCHE_RECOVERED_SOURCES "")

# This optional file is the only supported way to add explicitly recovered
# source objects. It may append to PORSCHE_RECOVERED_SOURCES; it must not copy
# original game binaries or introduce guessed game logic.
if(EXISTS "${PORSCHE_RECOVERY_SOURCES_FILE}")
    include("${PORSCHE_RECOVERY_SOURCES_FILE}")
endif()

add_library(porsche_original STATIC ${PORSCHE_RECOVERED_SOURCES})
add_executable(recovery_probe "${PORSCHE_RECOVERY_PROBE}")
add_executable(fe_stream_probe "${PORSCHE_SOURCE_ROOT}/recovered/fe_stream_probe.cpp")
add_executable(heap_probe "${PORSCHE_SOURCE_ROOT}/recovered/heap_probe.cpp")
add_executable(files_probe "${PORSCHE_SOURCE_ROOT}/recovered/files_probe.cpp")
add_executable(device_probe "${PORSCHE_SOURCE_ROOT}/recovered/device_probe.cpp")
add_executable(worker_probe "${PORSCHE_SOURCE_ROOT}/recovered/worker_probe.cpp")
add_executable(wait_probe "${PORSCHE_SOURCE_ROOT}/recovered/wait_probe.cpp")
add_executable(event_probe "${PORSCHE_SOURCE_ROOT}/recovered/event_probe.cpp")
add_executable(thread_probe "${PORSCHE_SOURCE_ROOT}/recovered/thread_probe.cpp")
add_executable(joint_disk_probe "${PORSCHE_SOURCE_ROOT}/recovered/joint_disk_probe.cpp")
target_link_libraries(joint_disk_probe PRIVATE porsche_original)
add_executable(disk_probe "${PORSCHE_SOURCE_ROOT}/recovered/disk_probe.cpp")
target_link_libraries(disk_probe PRIVATE porsche_original)
add_executable(fe_callbacks_probe "${PORSCHE_SOURCE_ROOT}/recovered/fe_callbacks_probe.cpp"
    "${PORSCHE_SOURCE_ROOT}/recovered/Porsche.exe/fe_callbacks.cpp")
target_include_directories(fe_callbacks_probe PRIVATE "${PORSCHE_RECOVERY_INCLUDE}")
target_compile_features(fe_callbacks_probe PRIVATE cxx_std_17)
add_executable(input_probe "${PORSCHE_SOURCE_ROOT}/recovered/input_probe.cpp"
    "${PORSCHE_SOURCE_ROOT}/recovered/Porsche.exe/input_state.cpp")
add_executable(lock_probe "${PORSCHE_SOURCE_ROOT}/recovered/lock_probe.cpp"
    "${PORSCHE_SOURCE_ROOT}/recovered/Porsche.exe/heap_locks.cpp")
add_executable(disk_open_probe "${PORSCHE_SOURCE_ROOT}/recovered/disk_open_probe.cpp"
    "${PORSCHE_SOURCE_ROOT}/recovered/Porsche.exe/disk_open.cpp")
add_executable(input_buffer_probe "${PORSCHE_SOURCE_ROOT}/recovered/input_buffer_probe.cpp"
    "${PORSCHE_SOURCE_ROOT}/recovered/Porsche.exe/input_buffer.cpp")
add_executable(bootstrap_probe "${PORSCHE_SOURCE_ROOT}/recovered/bootstrap_probe.cpp")
target_link_libraries(bootstrap_probe PRIVATE porsche_original)
add_executable(startup_services_probe "${PORSCHE_SOURCE_ROOT}/recovered/startup_services_probe.cpp"
    "${PORSCHE_SOURCE_ROOT}/recovered/Porsche.exe/startup_services.cpp")
add_executable(resource_paths_probe "${PORSCHE_SOURCE_ROOT}/recovered/resource_paths_probe.cpp"
    "${PORSCHE_SOURCE_ROOT}/recovered/Porsche.exe/resource_paths.cpp")
add_executable(render_startup_probe "${PORSCHE_SOURCE_ROOT}/recovered/render_startup_probe.cpp"
    "${PORSCHE_SOURCE_ROOT}/recovered/Porsche.exe/render_startup.cpp")
add_executable(application_heap_probe "${PORSCHE_SOURCE_ROOT}/recovered/application_heap_probe.cpp"
    "${PORSCHE_SOURCE_ROOT}/recovered/Porsche.exe/application_heap.cpp")
add_executable(render_objects_probe "${PORSCHE_SOURCE_ROOT}/recovered/render_objects_probe.cpp"
    "${PORSCHE_SOURCE_ROOT}/recovered/Porsche.exe/render_objects.cpp")
add_executable(window_runtime_probe "${PORSCHE_SOURCE_ROOT}/recovered/window_runtime_probe.cpp"
    "${PORSCHE_SOURCE_ROOT}/recovered/Porsche.exe/window_runtime.cpp")
add_executable(render_loader_probe "${PORSCHE_SOURCE_ROOT}/recovered/render_loader_probe.cpp"
    "${PORSCHE_SOURCE_ROOT}/recovered/Porsche.exe/render_loader.cpp"
)
add_executable(window_create_probe "${PORSCHE_SOURCE_ROOT}/recovered/window_create_probe.cpp"
    "${PORSCHE_SOURCE_ROOT}/recovered/Porsche.exe/window_create.cpp"
    "${PORSCHE_SOURCE_ROOT}/recovered/Porsche.exe/window_init.cpp"
)
add_executable(application_alloc_probe "${PORSCHE_SOURCE_ROOT}/recovered/application_alloc_probe.cpp"
    "${PORSCHE_SOURCE_ROOT}/recovered/Porsche.exe/application_alloc.cpp"
)
add_executable(application_heap_init_probe "${PORSCHE_SOURCE_ROOT}/recovered/application_heap_init_probe.cpp"
    "${PORSCHE_SOURCE_ROOT}/recovered/Porsche.exe/application_heap_init.cpp"
    "${PORSCHE_SOURCE_ROOT}/recovered/Porsche.exe/application_heap.cpp"
)
add_executable(window_procedure_probe "${PORSCHE_SOURCE_ROOT}/recovered/window_procedure_probe.cpp"
    "${PORSCHE_SOURCE_ROOT}/recovered/Porsche.exe/window_procedure.cpp"
)
foreach(probe input_probe lock_probe disk_open_probe input_buffer_probe startup_services_probe resource_paths_probe render_startup_probe render_objects_probe window_runtime_probe application_heap_probe render_loader_probe window_create_probe application_alloc_probe application_heap_init_probe window_procedure_probe)
    target_include_directories(${probe} PRIVATE "${PORSCHE_RECOVERY_INCLUDE}")
    target_compile_features(${probe} PRIVATE cxx_std_17)
endforeach()
foreach(probe disk_probe fe_callbacks_probe input_probe lock_probe joint_disk_probe disk_open_probe input_buffer_probe bootstrap_probe startup_services_probe resource_paths_probe render_startup_probe render_objects_probe window_runtime_probe application_heap_probe render_loader_probe window_create_probe application_alloc_probe application_heap_init_probe window_procedure_probe)
    target_compile_definitions(${probe} PRIVATE _CRT_SECURE_NO_WARNINGS NOMINMAX)
    target_compile_options(${probe} PRIVATE /W4 /EHsc /permissive-)
    target_link_options(${probe} PRIVATE /machine:X86 "/MAP:${CMAKE_BINARY_DIR}/${probe}.map")
    set_target_properties(${probe} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
endforeach()

target_link_libraries(thread_probe PRIVATE porsche_original)
target_compile_definitions(thread_probe PRIVATE _CRT_SECURE_NO_WARNINGS NOMINMAX)
target_compile_options(thread_probe PRIVATE /W4 /EHsc /permissive-)
target_link_options(thread_probe PRIVATE /machine:X86 "/MAP:${CMAKE_BINARY_DIR}/thread_probe.map")
set_target_properties(thread_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
target_link_libraries(event_probe PRIVATE porsche_original)
target_compile_definitions(event_probe PRIVATE _CRT_SECURE_NO_WARNINGS NOMINMAX)
target_compile_options(event_probe PRIVATE /W4 /EHsc /permissive-)
target_link_options(event_probe PRIVATE /machine:X86 "/MAP:${CMAKE_BINARY_DIR}/event_probe.map")
set_target_properties(event_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
target_link_libraries(wait_probe PRIVATE porsche_original)
target_compile_definitions(wait_probe PRIVATE _CRT_SECURE_NO_WARNINGS NOMINMAX)
target_compile_options(wait_probe PRIVATE /W4 /EHsc /permissive-)
target_link_options(wait_probe PRIVATE /machine:X86 "/MAP:${CMAKE_BINARY_DIR}/wait_probe.map")
set_target_properties(wait_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
target_link_libraries(worker_probe PRIVATE porsche_original)
target_compile_definitions(worker_probe PRIVATE _CRT_SECURE_NO_WARNINGS NOMINMAX)
target_compile_options(worker_probe PRIVATE /W4 /EHsc /permissive-)
target_link_options(worker_probe PRIVATE /machine:X86 "/MAP:${CMAKE_BINARY_DIR}/worker_probe.map")
set_target_properties(worker_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
target_link_libraries(device_probe PRIVATE porsche_original)
target_compile_definitions(device_probe PRIVATE _CRT_SECURE_NO_WARNINGS NOMINMAX)
target_compile_options(device_probe PRIVATE /W4 /EHsc /permissive-)
target_link_options(device_probe PRIVATE /machine:X86 "/MAP:${CMAKE_BINARY_DIR}/device_probe.map")
set_target_properties(device_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
target_link_libraries(files_probe PRIVATE porsche_original)
target_compile_definitions(files_probe PRIVATE _CRT_SECURE_NO_WARNINGS NOMINMAX)
target_compile_options(files_probe PRIVATE /W4 /EHsc /permissive-)
target_link_options(files_probe PRIVATE /machine:X86 "/MAP:${CMAKE_BINARY_DIR}/files_probe.map")
set_target_properties(files_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
target_link_libraries(heap_probe PRIVATE porsche_original)
target_compile_definitions(heap_probe PRIVATE _CRT_SECURE_NO_WARNINGS)
target_compile_options(heap_probe PRIVATE /W4 /EHsc /permissive-)
target_link_options(heap_probe PRIVATE /machine:X86 "/MAP:${CMAKE_BINARY_DIR}/heap_probe.map")
set_target_properties(heap_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
target_link_libraries(fe_stream_probe PRIVATE porsche_original)
target_compile_options(fe_stream_probe PRIVATE /W4 /EHsc /permissive-)
target_link_options(fe_stream_probe PRIVATE /machine:X86 "/MAP:${CMAKE_BINARY_DIR}/fe_stream_probe.map")
set_target_properties(fe_stream_probe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(PORSCHE_RECOVERY_TARGET recovery_probe)

target_include_directories(porsche_original PUBLIC "${PORSCHE_RECOVERY_INCLUDE}")
target_compile_features(porsche_original PUBLIC cxx_std_17)
target_link_libraries(recovery_probe PRIVATE porsche_original)
target_include_directories(recovery_probe PRIVATE "${PORSCHE_RECOVERY_INCLUDE}")
target_compile_features(recovery_probe PRIVATE cxx_std_17)
target_compile_definitions(recovery_probe PRIVATE PORSCHE_V2_RECOVERY_PROBE=1)

if(MSVC)
    target_compile_definitions(porsche_original PRIVATE _CRT_SECURE_NO_WARNINGS)
    target_compile_options(porsche_original PRIVATE /W4 /EHsc /permissive-)
    target_compile_options(recovery_probe PRIVATE /W4 /EHsc /permissive-)
    target_link_options(recovery_probe PRIVATE /machine:X86 "/MAP:${CMAKE_BINARY_DIR}/recovery_probe.map")
endif()

set(PORSCHE_TOOLCHAIN_COMPILER "${CMAKE_CXX_COMPILER}")
string(REPLACE "\\" "/" PORSCHE_TOOLCHAIN_COMPILER "${PORSCHE_TOOLCHAIN_COMPILER}")
set(PORSCHE_TOOLCHAIN_PLATFORM "${CMAKE_GENERATOR_PLATFORM}")
file(WRITE "${CMAKE_BINARY_DIR}/build-toolchain.json"
    "{\n"
    "  \"compiler\": \"${PORSCHE_TOOLCHAIN_COMPILER}\",\n"
    "  \"compiler_id\": \"${CMAKE_CXX_COMPILER_ID}\",\n"
    "  \"compiler_version\": \"${CMAKE_CXX_COMPILER_VERSION}\",\n"
    "  \"pointer_size\": ${CMAKE_SIZEOF_VOID_P},\n"
    "  \"generator_platform\": \"${PORSCHE_TOOLCHAIN_PLATFORM}\"\n"
    "}\n")

set_target_properties(recovery_probe PROPERTIES
    CXX_EXTENSIONS OFF
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Explicit native Win32 fixture; not an original game executable.
add_subdirectory(runs/036-native-window native-window)
