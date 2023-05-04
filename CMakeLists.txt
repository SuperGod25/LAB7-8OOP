cmake_minimum_required(VERSION 3.25)
project(LAB78)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LAB78
        Domain/Cheltuiala.cpp
        Domain/Cheltuiala.h
        main.cpp
        Repository/Repository.cpp
        Repository/Repository.h
        Tests/Tests.cpp
        Tests/Tests.h
        Service/Service.cpp
        Service/Service.h
        UI/UI.cpp
        UI/UI.h)
