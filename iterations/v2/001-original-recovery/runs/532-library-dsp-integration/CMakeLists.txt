cmake_minimum_required(VERSION 3.20)
project(porsche_library_dsp_532 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../529-dsp-state-flush-integration/CMakeLists.txt")
# The accepted loader belongs to porsche_original, not the entry bridge target.
get_target_property(_loader_sources porsche_original SOURCES)
list(LENGTH _loader_sources _before)
list(FILTER _loader_sources EXCLUDE REGEX "render_loader\\.cpp$")
list(LENGTH _loader_sources _after)
math(EXPR _removed "${_before}-${_after}")
if(NOT _removed EQUAL 1)
    message(FATAL_ERROR "Expected exactly one original loader replacement; removed=${_removed}")
endif()
set_property(TARGET porsche_original PROPERTY SOURCES "${_loader_sources}")
target_sources(porsche_original PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../528-render-library-lifecycle/render_loader_native_528.cpp")
target_include_directories(porsche_original PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../528-render-library-lifecycle")
target_sources(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../528-render-library-lifecycle/render_library_lifecycle_528.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../530-audio-dsp-core/audio_dsp_core_530.cpp"
)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../528-render-library-lifecycle"
    "${CMAKE_CURRENT_SOURCE_DIR}/../530-audio-dsp-core"
)
