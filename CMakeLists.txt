cmake_minimum_required(VERSION 3.5.0)
project(graphics3D VERSION 0.1)

include(CTest)
enable_testing()

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp coords.cpp renderer.cpp shape.cpp cube.cpp matrixoperations.cpp)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


