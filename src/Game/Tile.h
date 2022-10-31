//
// Created by jorge on 31/10/2022.
//

#ifndef HEXAGON_TILE_H
#define HEXAGON_TILE_H


#include "../Core/ECS/Entities/Entity.h"

namespace Game{
class Tile : public Core::Entity{
public:
    explicit Tile(std::string name);
    int id;
    };

}

#endif //HEXAGON_TILE_H
