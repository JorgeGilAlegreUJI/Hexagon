cmake_minimum_required(VERSION 3.23)
project(Hexagon)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(SDL2 REQUIRED)

include_directories(${SDL_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 20)

add_executable(Hexagon main.cpp)
target_link_libraries(Hexagon ${SDL2_LIBRARY}  -lmingw32 -lSDL2main -lSDL2)


