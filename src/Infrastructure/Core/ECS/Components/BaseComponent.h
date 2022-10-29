//
// Created by jorge on 28/10/2022.
//

#ifndef HEXAGON_BASECOMPONENT_H
#define HEXAGON_BASECOMPONENT_H

namespace Core{
    class Entity; //Forward Declaration
    class BaseComponent {
    public:
        Entity* entity;
        explicit BaseComponent(Entity* entity);
        virtual ~BaseComponent()=0;
    };

}

#endif //HEXAGON_BASECOMPONENT_H
