cmake_minimum_required(VERSION 3.12)
project(game)

include_directories(../vendor/googletest/googletest/include/)
set(CMAKE_CXX_STANDARD 14)

link_directories(../vendor/googletest/build/lib)
add_executable(CheckersUT ../Tile.cc ../Board.cc  UnitTest.cc BoardTest.cc TileTest.cc)
target_link_libraries(CheckersUT gtest gtest_main pthread)