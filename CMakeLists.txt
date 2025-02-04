cmake_minimum_required(VERSION 3.10)

project(dijkstra-cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(dijkstra)

add_executable(dijkstra_main main.cc)
target_include_directories(dijkstra_main PRIVATE ${CMAKE_SOURCE_DIR}/dijkstra)
target_link_libraries(dijkstra_main dijkstra)
