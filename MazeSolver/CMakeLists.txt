cmake_minimum_required(VERSION 3.9)
project(MazeSolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(MazeSolver main.cpp mazeFileIO.cpp mazeFileIO.h userInterface.cpp userInterface.h stack.cpp stack.h stackNode.cpp stackNode.h)