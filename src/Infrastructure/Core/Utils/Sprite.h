//
// Created by jorge on 27/10/2022.
//

#ifndef HEXAGON_SPRITE_H
#define HEXAGON_SPRITE_H

#include <string>
#include "../ECS/Components/BaseComponent.h"
#include "../ECS/Entities/Entity.h"

namespace Core{
    class Sprite {
    public:
        Sprite(const std::string &path, const std::string &name, SDL_Renderer *renderer);
        SDL_Renderer *renderer;
        std::string name;
        SDL_Texture *texture;
        SDL_Rect sourceRect{};
    };
}


#endif //HEXAGON_SPRITE_H
