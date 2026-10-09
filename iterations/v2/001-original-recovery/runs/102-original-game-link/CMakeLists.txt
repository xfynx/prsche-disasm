cmake_minimum_required(VERSION 3.20)

# Standalone mode reuses the iteration's canonical libraries in a private
# build tree. When included by the iteration CMake, this file defines only the
# excluded game-link target.
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    project(porsche_original_game_link_102 LANGUAGES CXX)
    get_filename_component(ITERATION_ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
    add_subdirectory("${ITERATION_ROOT}" "${CMAKE_BINARY_DIR}/common")
endif()

if(NOT TARGET porsche_original_game_link)
    foreach(required_target IN ITEMS
        porsche_original porsche_recovered_links porsche_window_links
        win32_window_bindings porsche_platform_win32)
        if(NOT TARGET ${required_target})
            message(FATAL_ERROR
                "Run102 requires the canonical common target '${required_target}'. "
                "Configure standalone from this directory or include it after the common targets.")
        endif()
    endforeach()

    add_executable(porsche_original_game_link WIN32 EXCLUDE_FROM_ALL host-entry.cpp)
    target_include_directories(porsche_original_game_link PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/../../source/include")
    target_compile_features(porsche_original_game_link PRIVATE cxx_std_17)
    target_compile_definitions(porsche_original_game_link PRIVATE
        NOMINMAX WIN32_LEAN_AND_MEAN _CRT_SECURE_NO_WARNINGS)
    target_compile_options(porsche_original_game_link PRIVATE /W4 /EHsc /permissive-)
    target_link_options(porsche_original_game_link PRIVATE
        /MACHINE:X86 "/MAP:${CMAKE_CURRENT_BINARY_DIR}/porsche_original_game_link.map")
    target_link_libraries(porsche_original_game_link PRIVATE
        porsche_original
        porsche_recovered_links
        porsche_window_links
        win32_window_bindings
        porsche_platform_win32
        user32 gdi32 kernel32)
    set_target_properties(porsche_original_game_link PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
endif()
