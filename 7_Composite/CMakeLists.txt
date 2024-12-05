cmake_minimum_required(VERSION 3.20)
project(Composite)
set(CMAKE_CXX_STANDARD 17)
add_executable(Composite main.cpp CRTP.hpp Array_backed.hpp SumExercise.hpp)