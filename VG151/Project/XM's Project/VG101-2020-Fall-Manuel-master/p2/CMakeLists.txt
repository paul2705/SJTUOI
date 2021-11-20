cmake_minimum_required(VERSION 2.7)
project(p2 C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-O2 -Werror -Wall -Wextra -Wpedantic")

add_executable(p2 main.c card.c card.h player.c player.h action.c action.h display.c display.h)