//
// Created by jorge on 30/10/2022.
//

#include <SDL2/SDL_timer.h>
#include "SpriteRendererFactory.h"

namespace Core{

    SpriteRendererFactory::SpriteRendererFactory(std::shared_ptr<EntityFactory> &entityFactory,std::shared_ptr<RenderSystem> &renderSystem)
    : entityFactory(entityFactory),renderSystem(renderSystem) {}

    std::shared_ptr<Entity> SpriteRendererFactory::createAndRegisterRenderedEntity(const std::string &spriteName) {
        std::shared_ptr<Entity> entity = entityFactory->createAndRegisterEntity("Rendered Entity: " + spriteName);
        std::shared_ptr<SpriteRenderer> sr = std::make_shared<SpriteRenderer>(spriteName,renderSystem);
        entity->addComponent<SpriteRenderer>(sr);
        return entity;
    }
}