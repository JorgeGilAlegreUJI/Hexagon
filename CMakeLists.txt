cmake_minimum_required(VERSION 3.23)
project(Hexagon)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(SDL2 REQUIRED)

include_directories(${SDL_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 20)

add_executable(Hexagon src/Infrastructure/Core/CoreLoop/main.cpp src/Infrastructure/Core/CoreLoop/CoreLoop.cpp src/Infrastructure/Core/CoreLoop/CoreLoop.h src/Infrastructure/Exceptions/SDL_Exception.h src/Infrastructure/Core/Utils/Color.cpp src/Infrastructure/Core/Utils/Color.h src/Infrastructure/Core/ECS/Components/Sprite.cpp src/Infrastructure/Core/ECS/Components/Sprite.h src/Infrastructure/Core/ECS/Entities/Entity.tpp src/Infrastructure/Core/ECS/Entities/Entity.h src/Infrastructure/Core/ECS/Components/BaseComponent.cpp src/Infrastructure/Core/ECS/Components/BaseComponent.h src/Infrastructure/Exceptions/Core_Exception.h)
target_link_libraries(Hexagon ${SDL2_LIBRARY}  -lmingw32 -lSDL2main -lSDL2 -lSDL2_image)


