cmake_minimum_required(VERSION 3.5.0)
project(SfmlSetup VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "D:/sfml/SFML-3.0.0/lib/cmake/SFML")

set(SOURCE_FILES main.cpp myclass.cpp)
add_executable(SfmlSetup ${SOURCE_FILES})

target_include_directories(SfmlSetup PRIVATE
                          "D:/sfml/SFML-3.0.0/include/"
                          )

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS Network Audio Graphics Window System Main REQUIRED)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    # SFML version >= 2.5
    #In SFML Version 2.5 or later, ${SFML_LIBRARIES}, ${SFML_DEPENDENCIES}, ${SFML_INCLUDE_DIR} no longer exist. Specify libraries individually.
    target_link_libraries(SfmlSetup SFML::Network SFML::Audio SFML::Graphics SFML::Window SFML::System)
endif()