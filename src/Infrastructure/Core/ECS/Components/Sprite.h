//
// Created by jorge on 27/10/2022.
//

#ifndef HEXAGON_SPRITE_H
#define HEXAGON_SPRITE_H

#include <string>
#include "BaseComponent.h"
#include "../Entities/Entity.h"

namespace Core{
    class Sprite : public BaseComponent{
    public:
        Sprite(Entity *entity, const std::string &path, const std::string &name, SDL_Renderer *renderer,
               int x, int y);
        void Draw();
        SDL_Rect rect{};
        std::string name;
    private:
        SDL_Texture *texture;
        SDL_Renderer *renderer;
        SDL_Rect sourceRect{};
    };
}


#endif //HEXAGON_SPRITE_H
