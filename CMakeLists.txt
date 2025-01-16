cmake_minimum_required(VERSION 3.28)
project(ProyectoFinal)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProyectoFinal main.cpp
        DDList.cpp
        DDList.h
        package.cpp
        package.h
        packageManager.cpp
        packageManager.h
        queue.cpp
        queue.h
        stack.cpp
        stack.h)
