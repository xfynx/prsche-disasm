cmake_minimum_required(VERSION 3.20)
project(porsche_integration_729 LANGUAGES CXX)

include("${CMAKE_CURRENT_LIST_DIR}/../727-input-and-scene-integration/CMakeLists.txt")

# Replace the older Run400 consumer so the shared 695 state has one canonical
# production view. Run494 remains the sole canonical frame-slot release owner.
get_target_property(_entry_sources porsche_game_entry_bridges SOURCES)
list(LENGTH _entry_sources _before)
list(FILTER _entry_sources EXCLUDE REGEX "400-frame-loop-clusters/00412030\\.cpp$")
list(LENGTH _entry_sources _after)
math(EXPR _removed "${_before}-${_after}")
if(NOT _removed EQUAL 1)
  message(FATAL_ERROR "Expected exactly one Run400 consumer replacement; removed=${_removed}")
endif()
set_property(TARGET porsche_game_entry_bridges PROPERTY SOURCES "${_entry_sources}")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/frame_control_state_729.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}")
