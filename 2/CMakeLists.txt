cmake_minimum_required(VERSION 3.20)
project(2)

set(CMAKE_CXX_STANDARD 14)

add_executable(2 main.cpp cpu.h cpu.cpp ram.cpp ram.h disk.cpp disk.h gpu.cpp gpu.h kbd.cpp kbd.h)
