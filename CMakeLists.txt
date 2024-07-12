cmake_minimum_required(VERSION 3.5.0)
project(graphics3D VERSION 0.1)

include(CTest)
enable_testing()

find_package(SDL2 REQUIRED )
include_directories(${SDL2_INCLUDE_DIRS})
find_package(glm REQUIRED)
include_directories(${GLM_INCLUDE_DIRS})


add_executable(${PROJECT_NAME} src/main.cpp src/coords.cpp src/renderer.cpp src/shape.cpp src/cube.cpp src/matrixoperations.cpp src/pyramid.cpp)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} glm::glm)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


