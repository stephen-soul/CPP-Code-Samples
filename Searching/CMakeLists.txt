cmake_minimum_required(VERSION 3.9)
project(Searching)

set(CMAKE_CXX_STANDARD 17)

add_executable(Searching main.cpp userInterface.cpp userInterface.h sequentialSearch.cpp sequentialSearch.h binarySearch.cpp binarySearch.h)