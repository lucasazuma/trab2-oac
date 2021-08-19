cmake_minimum_required(VERSION 3.20)
project(OAC C)

set(CMAKE_C_STANDARD 99)

add_executable(OAC main.c memory.h memory.c validations.h validations.c binary.h binary.c test.c test.h)
