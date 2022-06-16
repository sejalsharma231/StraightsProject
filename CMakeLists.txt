cmake_minimum_required(VERSION 3.17)
project(straights)

set(CMAKE_CXX_STANDARD 14)

add_executable(straights main.cpp player.h game.cpp game.h deck.cpp deck.h card.cpp card.h human.cpp human.h player.cpp table.cpp table.h computer.cpp computer.h)