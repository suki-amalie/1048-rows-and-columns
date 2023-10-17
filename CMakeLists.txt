cmake_minimum_required(VERSION 3.25)
project(rows_n_columns)

set(CMAKE_CXX_STANDARD 17)

add_executable(rows_n_columns main.cpp Player.cpp Player.h Dice.cpp Dice.h Counter.cpp Counter.h Board.cpp Board.h Object.cpp Object.h main.h)
