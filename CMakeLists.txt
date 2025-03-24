cmake_minimum_required(VERSION 3.16)
project(BowlingGame)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_BUILD_TYPE Debug)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(BowlingGame 
    src/main.cpp
    src/Player.cpp 
    src/Frame.cpp
    src/BowlingUnit.cpp)
