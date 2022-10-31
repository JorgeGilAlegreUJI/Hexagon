//
// Created by jorge on 27/10/2022.
//
#include "CoreLoop.h"


namespace Core {
    CoreLoop::CoreLoop() :isRunning(true){
        hierarchySystem = std::make_shared<HierarchySystem>();
        renderSystem = std::make_shared<RenderSystem>(hierarchySystem);
        entityFactory = std::make_shared<EntityFactory>(hierarchySystem);
        spriteRendererFactory = std::make_shared<SpriteRendererFactory>(entityFactory,renderSystem);
        gameLoop = std::make_shared<Game::GameLoop>(spriteRendererFactory,renderSystem,entityFactory);
    }


    void CoreLoop::Init() {
        gameLoop->Awake();
        gameLoop->Start();
    }

    void CoreLoop::HandleEvents() {
        renderSystem->HandleEvents(isRunning);
    }

    void CoreLoop::Update() {
        gameLoop->Update();
        hierarchySystem->clearExpiredPointers();
    }

    void CoreLoop::Render() {
        renderSystem->Render();
    }

    void CoreLoop::Release() {
        renderSystem->Release();
    }



}

