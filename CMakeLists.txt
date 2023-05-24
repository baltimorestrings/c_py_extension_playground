cmake_minimum_required(VERSION 3.25)
project(c_playground C)

set(CMAKE_C_STANDARD 11)
include_directories("/opt/homebrew/Cellar/python@3.8/3.8.16/Frameworks/Python.framework/Versions/3.8/include/python3.8")
include_directories("/opt/homebrew/Cellar/python@3.8/3.8.16/Frameworks/Python.framework/Versions/3.8/include/python3.8")

set(CMAKE_EXE_LINKER_FLAGS "-L/opt/homebrew/opt/python@3.8/Frameworks/Python.framework/Versions/3.8/lib/python3.8/config-3.8-darwin -ldl -framework CoreFoundation")

add_compile_options(-Wno-unused-result -Wsign-compare -Wunreachable-code -fno-common -dynamic -DNDEBUG -g -fwrapv -O3 -Wall -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX12.sdk)

add_executable(standalone_run hello_full_program.c)
