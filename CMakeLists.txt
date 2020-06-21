cmake_minimum_required(VERSION 3.13)

project(JtOS CXX)

add_executable(JtOS file_system.cpp fs.cpp jsystem.cpp jtime.cpp linktable.cpp menu.cpp)
