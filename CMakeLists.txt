cmake_minimum_required(VERSION 3.10)

# Set the project name
project(DijkstraCpp)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(include)

# Add the executable
file(GLOB SOURCES "src/*.cc")
add_executable(DijkstraCpp ${SOURCES})

# Optionally, you can add any required libraries here
# target_link_libraries(DijkstraCpp <library_name>)