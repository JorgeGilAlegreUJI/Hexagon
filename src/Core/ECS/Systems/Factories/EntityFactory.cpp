//
// Created by jorge on 30/10/2022.
//

#include "EntityFactory.h"

namespace Core{
    std::shared_ptr<Entity> Core::EntityFactory::createAndRegisterEntity(std::string name) {
        name += "(" + std::to_string(totalSpawnedEntities) + ")";
        std::shared_ptr<Entity> entity = std::make_shared<Entity>(name);
        registerEntity(entity);
        return entity;
    }

    EntityFactory::EntityFactory(std::shared_ptr<HierarchySystem> &hierarchySystem) : hierarchySystem(hierarchySystem), totalSpawnedEntities(0){}

    void EntityFactory::registerEntity(std::shared_ptr<Entity> entity) {
        hierarchySystem->activeEntities.push_back(std::weak_ptr<Entity>(entity));
        totalSpawnedEntities++;
    }

}

