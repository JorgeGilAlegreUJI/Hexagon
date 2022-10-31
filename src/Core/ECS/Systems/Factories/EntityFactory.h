//
// Created by jorge on 30/10/2022.
//

#ifndef HEXAGON_ENTITYFACTORY_H
#define HEXAGON_ENTITYFACTORY_H


#include <memory>
#include "../../Entities/Entity.h"
#include "../HierarchySystem.h"

namespace Core{
    class EntityFactory {
    private:
        int totalSpawnedEntities;
        std::shared_ptr<HierarchySystem> hierarchySystem;
    public:
        explicit EntityFactory(std::shared_ptr<HierarchySystem> &hierarchySystem);
        void registerEntity(std::shared_ptr<Entity> entity);
        std::shared_ptr<Entity>createAndRegisterEntity(std::string name);
    };

}

#endif //HEXAGON_ENTITYFACTORY_H
