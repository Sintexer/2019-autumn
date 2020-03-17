cmake_minimum_required(VERSION 3.15)
project(Lab9_STL)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab9_STL
        Asteroid.cpp
        Asteroid.h
        BlackHole.cpp
        BlackHole.h
        Bolid.cpp
        Bolid.h
        Comet.cpp
        Comet.h
        Exc.cpp
        Exc.h
        Interface.cpp
        Interface.h
        main.cpp
        Meteor.cpp
        Meteor.h
        pch.h
        Planet.cpp
        Planet.h
        SpaceObject.cpp
        SpaceObject.h
        Star.cpp
        Star.h
        Sun.cpp
        Sun.h
        OutputTable.cpp
        OutputTable.h File.cpp File.h)
