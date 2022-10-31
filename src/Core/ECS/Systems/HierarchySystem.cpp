//
// Created by jorge on 30/10/2022.
//

#include "HierarchySystem.h"

namespace Core{

    void HierarchySystem::clearExpiredPointers() {
        for (unsigned i = activeEntities.size(); i-- != 0; ) {
           if(activeEntities[i].expired())activeEntities.erase(activeEntities.begin() + i);
        }

    }
}