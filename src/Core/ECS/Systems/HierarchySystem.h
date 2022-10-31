//
// Created by jorge on 30/10/2022.
//

#ifndef HEXAGON_HIERARCHYSYSTEM_H
#define HEXAGON_HIERARCHYSYSTEM_H


#include <vector>
#include "../Entities/Entity.h"

namespace Core{
    class HierarchySystem {
    public:
        std::vector<std::weak_ptr<Entity>> activeEntities;
        void clearExpiredPointers();
    };

}

#endif //HEXAGON_HIERARCHYSYSTEM_H
