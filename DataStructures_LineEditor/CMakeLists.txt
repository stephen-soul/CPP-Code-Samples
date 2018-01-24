cmake_minimum_required(VERSION 3.9)
project(DataStructures_LineEditor)

set(CMAKE_CXX_STANDARD 17)

add_executable(DataStructures_LineEditor main.cpp Editor.cpp Editor.h Node.h LinkedList.cpp LinkedList.h)