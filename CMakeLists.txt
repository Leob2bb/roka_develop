cmake_minimum_required(VERSION 3.16)

project(chess LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_executable(chess_test
	test.cpp
	src/chess/board.cpp
	src/chess/piece.cpp
)

add_test(NAME chess_test COMMAND chess_test)