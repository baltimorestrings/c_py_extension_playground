cmake_minimum_required(VERSION 3.25)
project(c_playground C)

set(CMAKE_C_STANDARD 11)

include_directories("/Library/Frameworks/Python.framework/Versions/3.6/include/python3.6m")
include_directories(/Library/Frameworks/Python.framework/Versions/3.6/include/python3.6m)
add_executable(c_playground
        src/cplay/hello.c)
