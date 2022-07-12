cmake_minimum_required(VERSION 3.19)
project(toDoList)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(test)
set(SOURCE_FILES Activity.cpp Activity.h ListOfActivity.cpp ListOfActivity.h Date.cpp Date.h Hour.cpp Hour.h)

add_executable(toDoList main.cpp Activity.cpp Activity.h ListOfActivity.cpp ListOfActivity.h Date.cpp Date.h Hour.cpp Hour.h)
add_library(core ${SOURCE_FILES} Activity.cpp Activity.h ListOfActivity.cpp ListOfActivity.h Date.cpp Date.h Hour.cpp Hour.h)
target_link_libraries(toDoList core)
