cmake_minimum_required(VERSION 3.21)
project(BryceGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(BryceGame main.cpp Game.cpp Game.h Character.cpp Character.h Ability.cpp Ability.h)
