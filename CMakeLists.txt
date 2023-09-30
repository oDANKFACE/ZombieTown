cmake_minimum_required(VERSION 3.26)
project(ZombieTown)

set(CMAKE_CXX_STANDARD 17)

add_executable(ZombieTown main.cpp
        include/Game.h
        src/Game.cpp
        include/Character.h
        src/Character.cpp
        src/Event.cpp
        include/Event.h
        include/EventManager.h
        src/EventManager.cpp
        include/Location.h)
