cmake_minimum_required(VERSION 3.5)
project(p2 C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(onecard main.c cards.c cards.h game.c game.h player.c player.h round.c round.h structure.h)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Werror -Wall -Wextra -Wconversion -Wvla -Wpedantic" CACHE STRING "Set C++ Compiler Flags" FORCE)

