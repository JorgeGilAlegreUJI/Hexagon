cmake_minimum_required(VERSION 3.23)
project(Hexagon)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(SDL2 REQUIRED)

include_directories(${SDL_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 20)

add_executable(Hexagon src/Core/CoreLoop/main.cpp src/Core/CoreLoop/CoreLoop.cpp src/Core/CoreLoop/CoreLoop.h src/Core/Exceptions/SDL_Exception.h src/Core/Utils/Color.cpp src/Core/Utils/Color.h src/Core/Utils/Sprite.cpp src/Core/Utils/Sprite.h src/Core/ECS/Entities/Entity.tpp src/Core/ECS/Entities/Entity.h src/Core/ECS/Components/BaseComponent.cpp src/Core/ECS/Components/BaseComponent.h src/Core/Exceptions/Core_Exception.h src/Core/ECS/Components/SpriteRenderer.cpp src/Core/ECS/Components/SpriteRenderer.h src/Core/ECS/Systems/RenderSystem.cpp src/Core/ECS/Systems/RenderSystem.h src/Core/ECS/Systems/HierarchySystem.cpp src/Core/ECS/Systems/HierarchySystem.h src/Core/ECS/Systems/Factories/EntityFactory.cpp src/Core/ECS/Systems/Factories/EntityFactory.h src/Core/ECS/Systems/Factories/SpriteRendererFactory.cpp src/Core/ECS/Systems/Factories/SpriteRendererFactory.h src/Game/GameLoop.cpp src/Game/GameLoop.h src/Game/TileManager.cpp src/Game/TileManager.h src/Game/Tile.cpp src/Game/Tile.h)
target_link_libraries(Hexagon ${SDL2_LIBRARY}  -lmingw32 -lSDL2main -lSDL2 -lSDL2_image)


