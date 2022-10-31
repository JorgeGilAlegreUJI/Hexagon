//
// Created by jorge on 31/10/2022.
//

#include "Tile.h"

#include <utility>
namespace Game{


    Tile::Tile(std::string name) : Entity(std::move(name)) {
        id = -1;
    }
}