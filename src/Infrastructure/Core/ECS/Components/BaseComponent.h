//
// Created by jorge on 28/10/2022.
//

#ifndef HEXAGON_BASECOMPONENT_H
#define HEXAGON_BASECOMPONENT_H

#include <memory>

namespace Core{
    class Entity; //Forward Declaration
    class BaseComponent {
    public:
        std::shared_ptr<Entity> entity;
        virtual ~BaseComponent()=0;
    };
}

#endif //HEXAGON_BASECOMPONENT_H
