cmake_minimum_required(VERSION 3.28)
project(Games)

set(CMAKE_CXX_STANDARD 17)

add_executable(Games src/main.cpp
        src/games/hangman.h)
