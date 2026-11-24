cmake_minimum_required(VERSION 3.20)
project(porsche_integration_824 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../820-sim-audio-and-scene-insert-integration/CMakeLists.txt")
include("${CMAKE_CURRENT_LIST_DIR}/../822-splash-sprite-blend-leaves/bindings.cmake")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../807-render-color-pack/render_color_pack_807.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../817-splash-draw-sprite/sprite_draw_817.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../822-splash-sprite-blend-leaves/sprite_blend_leaves_822.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../807-render-color-pack"
  "${CMAKE_CURRENT_LIST_DIR}/../817-splash-draw-sprite"
  "${CMAKE_CURRENT_LIST_DIR}/../822-splash-sprite-blend-leaves")
