cmake_minimum_required(VERSION 3.20)
project(OAC C)

set(CMAKE_C_STANDARD 99)

add_executable(OAC main.c memory/memory.h memory/memory.c memory/validations.h memory/validations.c memory/binary.h memory/binary.c memory/test.c memory/test.h simulador/instruction.h simulador/utils.h simulador/instructions.c simulador/utils.c)
