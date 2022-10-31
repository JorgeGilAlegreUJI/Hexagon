//
// Created by jorge on 27/10/2022.
//

#ifndef HEXAGON_CORELOOP_H
#define HEXAGON_CORELOOP_H
#include "../ECS/Systems/RenderSystem.h"
#include "../ECS/Systems/Factories/EntityFactory.h"
#include "../ECS/Systems/Factories/SpriteRendererFactory.h"
#include "../../Game/GameLoop.h"

namespace Core {
    class CoreLoop {
    public:
        explicit CoreLoop();
        void Init();
        void HandleEvents();
        void Update();
        void Render();
        void Release();
        bool isRunning;
    private:
        std::shared_ptr<RenderSystem> renderSystem;
        std::shared_ptr<HierarchySystem> hierarchySystem;
        std::shared_ptr<EntityFactory> entityFactory;
        std::shared_ptr<SpriteRendererFactory> spriteRendererFactory;
        std::shared_ptr<Game::GameLoop> gameLoop;
    };
}


#endif //HEXAGON_CORELOOP_H
