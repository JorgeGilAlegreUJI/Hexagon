//
// Created by jorge on 30/10/2022.
//

#include "GameLoop.h"
#include "../Core/ECS/Systems/RenderSystem.h"
#include "TileManager.h"


namespace Game{
    std::unique_ptr<TileManager> tileManager;
    GameLoop::GameLoop(std::shared_ptr<Core::SpriteRendererFactory> &spriteRendererFactory,
                       std::shared_ptr<Core::RenderSystem> &renderSystem,
                       std::shared_ptr<Core::EntityFactory> &entityFactory):
                       spriteRendererFactory(spriteRendererFactory),
                       renderSystem(renderSystem),
                       entityFactory(entityFactory){}

    void GameLoop::Awake() {
        tileManager = std::make_unique<TileManager>(spriteRendererFactory,entityFactory);

        renderSystem->createAndLoadSprite(tilesPath,"tile0");
        renderSystem->createAndLoadSprite(tilesPath,"tile1");
        renderSystem->createAndLoadSprite(tilesPath,"tile2");
        renderSystem->createAndLoadSprite(tilesPath,"tile3");
        renderSystem->createAndLoadSprite(tilesPath,"tile4");

    }

    void GameLoop::Start() {
        tileManager->CreateAllTiles();
    }

    void GameLoop::Update() {

    }

}