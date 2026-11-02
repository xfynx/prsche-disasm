cmake_minimum_required(VERSION 3.20)
project(porsche_render_pcm_file_500 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../491-callback-pixel-pcm-integration/CMakeLists.txt")
# Fresh496 proof replaces the previously PARTIAL484 caller; frozen history stays.
get_target_property(_original_sources porsche_original SOURCES)
list(LENGTH _original_sources _before_replace)
list(FILTER _original_sources EXCLUDE REGEX "render_display_484\\.cpp$")
list(LENGTH _original_sources _after_replace)
math(EXPR _removed "${_before_replace}-${_after_replace}")
if(NOT _removed EQUAL 1)
    message(FATAL_ERROR "Expected exactly one frozen484 caller in porsche_original")
endif()
set_property(TARGET porsche_original PROPERTY SOURCES "${_original_sources}")
target_sources(porsche_original PRIVATE ../496-render-present-caller-repair/render_display_496.cpp)
target_include_directories(porsche_original PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../496-render-present-caller-repair")
target_sources(porsche_game_entry_bridges PRIVATE
    ../493-audio-pcm-constructors/audio_pcm_constructors_493.cpp
    ../494-render-resource-leaves/render_resource_494.cpp
    ../494-render-resource-leaves/render_present_494.cpp
    ../494-render-resource-leaves/platform_render_resource_494.cpp
    ../495-application-audio-bank-cleanup/application_audio_bank_cleanup_495.cpp
    ../499-rooted-file-exists/rooted_file_exists_499.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../493-audio-pcm-constructors"
    "${CMAKE_CURRENT_SOURCE_DIR}/../494-render-resource-leaves"
    "${CMAKE_CURRENT_SOURCE_DIR}/../495-application-audio-bank-cleanup"
    "${CMAKE_CURRENT_SOURCE_DIR}/../496-render-present-caller-repair"
    "${CMAKE_CURRENT_SOURCE_DIR}/../499-rooted-file-exists"
)
