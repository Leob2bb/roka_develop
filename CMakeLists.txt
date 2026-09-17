cmake_minimum_required(VERSION 3.16)

project(roka_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_executable(roka_test test.cpp)

add_test(NAME roka_test COMMAND roka_test)