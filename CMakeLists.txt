cmake_minimum_required(VERSION 3.16.0)
project(rss-reader VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets)

message(STATUS "OS: ${CMAKE_SYSTEM_NAME}")

include(CTest)
enable_testing()

file(GLOB FileList
    "source/*.cpp"
    "source/*.h"
)

message(STATUS "Files in: ${PROJECT_NAME}")
foreach(File ${FileList})
    message("\tFile: ${File}")
endforeach()


set(PROJECT_SOURCES
    ${FileList}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(tinyxml2)
add_subdirectory(curlpp)

qt_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC 
    curlpp 
    tinyxml2
    Qt::Widgets
)
