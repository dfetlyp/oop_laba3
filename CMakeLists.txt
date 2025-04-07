cmake_minimum_required(VERSION 3.10)
project(laba3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(first src/first.cpp)
add_executable(unique_ptr src/unique_ptr.cpp)
add_executable(shared_ptr src/shared_ptr.cpp)
add_executable(weak_ptr src/weak_ptr.cpp)

