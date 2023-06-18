cmake_minimum_required(VERSION 3.25)
project(ProjAlgoritmos)

set(CMAKE_CXX_STANDARD 14)

include_directories(ProjAlgoritmos)
include_directories(ProjAlgoritmos/controller)
include_directories(ProjAlgoritmos/utils)

add_executable(ProjAlgoritmos
        ProjAlgoritmos/controller/ControllerBinder.h
        ProjAlgoritmos/controller/IController.h
        ProjAlgoritmos/utils/INode.h
        ProjAlgoritmos/utils/List.h
        ProjAlgoritmos/utils/Queue.h
        ProjAlgoritmos/utils/Stack.h
        ProjAlgoritmos/utils/Utils.h
        ProjAlgoritmos/x64/Debug/.NETFramework,Version=v4.7.2.AssemblyAttributes.cpp
        ProjAlgoritmos/Credits.cpp
        ProjAlgoritmos/Credits.h
        ProjAlgoritmos/Inicio.h
        ProjAlgoritmos/Instructions.cpp
        ProjAlgoritmos/Instructions.h
        ProjAlgoritmos/Start.cpp
        ProjAlgoritmos/Start.h ProjAlgoritmos/main.cpp)
