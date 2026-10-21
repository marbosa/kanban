cmake_minimum_required(VERSION 4.1)
project(kanban)

set(CMAKE_CXX_STANDARD 17)

add_executable(kanban
        main.cpp
        dominios.cpp
        dominios.h
)
