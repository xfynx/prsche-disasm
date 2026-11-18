cmake_minimum_required(VERSION 3.20)
project(porsche_integration_675 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../672-bigheader-loud-and-font-state-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../673-render-loader-directx-and-startup-alloc/render_loader_directx_673.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../674-render-depth-helper-leaves/render_depth_helpers_674.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../673-render-loader-directx-and-startup-alloc"
  "${CMAKE_CURRENT_SOURCE_DIR}/../674-render-depth-helper-leaves")
