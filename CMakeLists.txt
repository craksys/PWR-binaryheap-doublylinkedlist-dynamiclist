cmake_minimum_required(VERSION 3.26)
project(SDIZO)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SDIZO
        Kopiec.cpp
        Kopiec.h
        Lista.cpp
        Lista.h
        Lista2.cpp
        Lista2.h
        STIZO.cpp
        Tablica.cpp
        Tablica.h)
