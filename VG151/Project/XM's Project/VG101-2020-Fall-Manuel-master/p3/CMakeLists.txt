cmake_minimum_required(VERSION 2.7)
project(p3)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})

add_executable(p3_part1 part1.cpp header.h basic.cpp)
add_executable(p3_part2 part2.cpp coloredFig.cpp coloredFig.h vehicle.cpp vehicle.h parkingLot.cpp parkingLot.h)

target_link_libraries(p3_part2 ${GLUT_LIBRARY} ${OPENGL_LIBRARY} m)
