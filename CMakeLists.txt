cmake_minimum_required(VERSION 3.6)
project(apuntes_02_12)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c)
add_executable(apuntes_02_12 ${SOURCE_FILES})