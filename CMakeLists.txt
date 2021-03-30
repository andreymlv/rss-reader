cmake_minimum_required(VERSION 3.16.0)
project(rss-reader VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

message(STATUS "OS: ${CMAKE_SYSTEM_NAME}")

include(CTest)
enable_testing()


add_executable(rss-reader 
    source/main.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(tinyxml2)
add_subdirectory(curlpp)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

target_link_libraries(${PROJECT_NAME} curlpp tinyxml2 Qt6::Widgets)
