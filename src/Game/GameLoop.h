//
// Created by jorge on 30/10/2022.
//

#ifndef HEXAGON_GAMELOOP_H
#define HEXAGON_GAMELOOP_H

#include <memory>
#include "../Core/ECS/Systems/Factories/SpriteRendererFactory.h"

namespace Game{

    class GameLoop {
    private:
        const std::string tilesPath = "Resources/Textures/Tiles/Terrain/Grass/";
        std::shared_ptr<Core::SpriteRendererFactory> spriteRendererFactory;
        std::shared_ptr<Core::RenderSystem> renderSystem;
        std::shared_ptr<Core::EntityFactory> entityFactory;
    public:
        explicit GameLoop(std::shared_ptr<Core::SpriteRendererFactory> &spriteRendererFactory,
                          std::shared_ptr<Core::RenderSystem> &renderSystem, std::shared_ptr<Core::EntityFactory> &entityFactory);
        void Awake();
        void Start();
        void Update();
    };
}


#endif //HEXAGON_GAMELOOP_H
