cmake_minimum_required(VERSION 3.27)
project(Bugs_Board_CA2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bugs_Board_CA2 main.cpp
        Bug.h
        Bug.cpp
        Board.cpp
        Board.h
        BugTypes/Crawler.cpp
        BugTypes/Crawler.h
        BugTypes/Hopper.cpp
        BugTypes/Hopper.h)
