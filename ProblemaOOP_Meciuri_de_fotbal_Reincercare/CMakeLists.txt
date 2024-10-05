cmake_minimum_required(VERSION 3.28)
project(ProblemaOOP_Meciuri_de_fotbal_Reincercare)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProblemaOOP_Meciuri_de_fotbal_Reincercare main.cpp
        Meci.h
        Meci.cpp
        Repo.h
        Repo.cpp
        Service.h
        Service.cpp
        UI.h
        UI.cpp)
