cmake_minimum_required(VERSION 3.28)
project(ProyectoFinal)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProyectoFinal main.cpp
        DDList.h
        package.cpp
        package.h
        packageManager.cpp
        packageManager.h
        queue.h
        stack.h
        camion.h
        AVLTree.h
        cliente.cpp
        cliente.h
        HashTable.h)
