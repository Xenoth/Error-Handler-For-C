cmake_minimum_required(VERSION 2.8)
project(untitled3)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c lib/ErrorHandler.h lib/ErrorEnum.h lib/ErrorHandler.c lib/StackError.c lib/ErrorEnum.c)
add_executable(error_Handler_For_C_exemple ${SOURCE_FILES})
