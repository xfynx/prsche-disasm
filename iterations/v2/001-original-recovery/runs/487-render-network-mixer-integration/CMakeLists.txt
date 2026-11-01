cmake_minimum_required(VERSION 3.20)
project(porsche_render_network_mixer_487 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../483-startup-gates-integration/CMakeLists.txt")
# Replace the defective caller explicitly; its historical source stays immutable.
get_filename_component(recovery_root "${CMAKE_CURRENT_SOURCE_DIR}/../.." ABSOLUTE)
set(old_render_source "${recovery_root}/source/recovered/Porsche.exe/render_display.cpp")
get_target_property(original_sources porsche_original SOURCES)
list(FIND original_sources "${old_render_source}" old_render_index)
if(old_render_index EQUAL -1)
    message(FATAL_ERROR "Expected exactly the canonical old render_display.cpp")
endif()
list(REMOVE_ITEM original_sources "${old_render_source}")
set_property(TARGET porsche_original PROPERTY SOURCES "${original_sources}")
target_sources(porsche_original PRIVATE
    ../484-render-constructor-repair/render_display_484.cpp
    ../484-render-constructor-repair/render_transform_484.cpp)
target_include_directories(porsche_original PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../484-render-constructor-repair")
target_sources(porsche_game_entry_bridges PRIVATE
    ../485-network-callback-lifecycle/network_callback_lifecycle_485.cpp
    ../486-audio-mixer-configuration/audio_mixer_configuration_486.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../485-network-callback-lifecycle"
    "${CMAKE_CURRENT_SOURCE_DIR}/../486-audio-mixer-configuration")
