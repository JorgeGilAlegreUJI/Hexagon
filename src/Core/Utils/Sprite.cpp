//
// Created by jorge on 27/10/2022.
//

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Sprite.h"

namespace Core{

    Sprite::Sprite(const std::string &path, const std::string &name, SDL_Renderer *renderer) : name(name), renderer(renderer) {
        std::string fullPath = path+name+".png";
        const char*file = fullPath.c_str();
        SDL_Surface *imageSurface = IMG_Load(file);
        texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
        SDL_QueryTexture(texture, nullptr, nullptr,&sourceRect.w,&sourceRect.h);
        SDL_FreeSurface(imageSurface);
    }
}