#Ugly shit
cmake_minimum_required(VERSION 3.4.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

#Copy content. Executable is running somewhere from out/build/Mingw64/, so Content should be there as well
add_custom_target(Content_Copy
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different ${CMAKE_SOURCE_DIR}/Content ${CMAKE_CURRENT_BINARY_DIR}/Content)

#mainCmake
project(SfmlSetup VERSION 0.1.0 LANGUAGES C CXX)

#just add your files here and get out
set(SOURCE_FILES main.cpp myclass.cpp)
add_executable(SfmlSetup ${SOURCE_FILES})

add_dependencies(SfmlSetup Content_Copy)

#change this path for SFML library location (maybe it's better to copy the whole lib to the project dir?)
set(SFML_DIR "D:/sfml/SFML-3.0.0/lib/cmake/SFML")

#change this path also
target_include_directories(SfmlSetup PRIVATE
                          "D:/sfml/SFML-3.0.0/include/"
                          )

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS Network Audio Graphics Window System Main REQUIRED)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SfmlSetup SFML::Network SFML::Audio SFML::Graphics SFML::Window SFML::System)
endif()
