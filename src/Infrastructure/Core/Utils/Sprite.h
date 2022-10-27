//
// Created by jorge on 27/10/2022.
//

#ifndef HEXAGON_SPRITE_H
#define HEXAGON_SPRITE_H

#include <string>

namespace Core{
    class Sprite {
    public:
        Sprite(const std::string& path,const std::string& name, SDL_Renderer *renderer, const int x, const int y);
        void Draw();
        static const std::string TILES_GRASS_PATH;

        SDL_Rect rect;
        std::string name;
    private:
        SDL_Texture *texture;
        SDL_Renderer *renderer;
        SDL_Rect sourceRect;


    };
}


#endif //HEXAGON_SPRITE_H
