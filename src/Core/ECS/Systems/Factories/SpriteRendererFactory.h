//
// Created by jorge on 30/10/2022.
//

#ifndef HEXAGON_SPRITERENDERERFACTORY_H
#define HEXAGON_SPRITERENDERERFACTORY_H
#include "EntityFactory.h"
#include "../../Components/SpriteRenderer.h"


namespace Core{
    class SpriteRendererFactory {
    private:
        std::shared_ptr<EntityFactory> entityFactory;
    public:
        std::shared_ptr<RenderSystem> renderSystem;
        explicit SpriteRendererFactory(std::shared_ptr<EntityFactory> &entityFactory,std::shared_ptr<RenderSystem> &renderSystem);
        std::shared_ptr<Entity> createAndRegisterRenderedEntity(const std::string& spriteName);
    };
}

#endif //HEXAGON_SPRITERENDERERFACTORY_H
