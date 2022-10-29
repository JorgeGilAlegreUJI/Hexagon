//
// Created by jorge on 27/10/2022.
//
#include "CoreLoop.h"
//#include "../ECS/Components/SpriteRenderer.h"


namespace Core {
    CoreLoop::CoreLoop() :isRunning(true){
        renderSystem = std::make_unique<RenderSystem>();
    }

    void CoreLoop::Init() {
        std::shared_ptr<Core::Entity> e;
        e = std::make_shared<Entity>("test0");
        e->setLocalPosition(100,100);
        e->localScale = 2;
        renderSystem->createAndLoadSprite("Resources/Textures/Tiles/Terrain/Grass/","grass_01.png");
        std::shared_ptr<SpriteRenderer> sr = std::make_shared<SpriteRenderer>(renderSystem->loadedSprites.at("grass_01.png"));
        e->addComponent<SpriteRenderer>(sr,e);
        renderSystem->activeRenderers.push_back(sr);

    }

    void CoreLoop::HandleEvents() {
        renderSystem->HandleEvents(isRunning);
    }


    void CoreLoop::Update() {

    }

    void CoreLoop::Render() {
        renderSystem->Render();
    }

    void CoreLoop::Release() {
        renderSystem->Release();
    }



}

