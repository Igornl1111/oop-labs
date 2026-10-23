cmake_minimum_required(VERSION 3.10)
project(Library)

set(SOURCE_FILES
        include/Student.h
        src/Student.cpp
)

add_library(Library ${SOURCE_FILES})
target_include_directories(Library PUBLIC include)