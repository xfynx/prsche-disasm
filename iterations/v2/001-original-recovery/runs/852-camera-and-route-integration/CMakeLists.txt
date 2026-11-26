cmake_minimum_required(VERSION 3.20)
project(porsche_integration_852 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../846-audio-period-device-state/CMakeLists.txt")

get_target_property(_sources porsche_game_entry_bridges SOURCES)
list(FILTER _sources EXCLUDE REGEX "693-view-setup-teardown-scene-enter/application_view_lifecycle_693[.]cpp$")
list(FILTER _sources EXCLUDE REGEX "835-entry-fe-service/entry_fe_service_835[.]cpp$")
set_property(TARGET porsche_game_entry_bridges PROPERTY SOURCES "${_sources}")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../400-frame-loop-clusters/00414eb0.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../851-session-reset/session_reset_851.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../848-camera-transform/camera_transform_848.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../849-view-route-direction/entry_fe_service_849.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../850-view-route-storage/application_view_lifecycle_850.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../400-frame-loop-clusters"
  "${CMAKE_CURRENT_LIST_DIR}/../851-session-reset"
  "${CMAKE_CURRENT_LIST_DIR}/../848-camera-transform"
  "${CMAKE_CURRENT_LIST_DIR}/../849-view-route-direction"
  "${CMAKE_CURRENT_LIST_DIR}/../850-view-route-storage")
