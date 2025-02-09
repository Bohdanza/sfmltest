cmake_minimum_required(VERSION 3.2)

project(MySfml VERSION 1.0 LANGUAGES CXX)

add_executable(MySfml main.cpp)

target_sources(MySfml 
    PRIVATE 
        myclass.cpp
        myclass.hpp)

target_include_directories(MySfml PUBLIC ${workspaceFolder}\\build)

set_property(TARGET MySfml PROPERTY CXX_STANDARD 17)
