//
// Created by jorge on 27/10/2022.
//

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Sprite.h"

namespace Core{

    void Sprite::Draw(){
        SDL_RenderCopy(renderer,texture,&sourceRect,&rect);
    }

    Sprite::Sprite(const std::string& path,const std::string& name,SDL_Renderer *renderer,const int x,const int y): name(name),renderer(renderer){
        std::string fullPath = path+name;
        const char*file = fullPath.c_str();
        SDL_Surface *imageSurface = IMG_Load(file);
        texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
        SDL_QueryTexture(texture, nullptr, nullptr,&sourceRect.w,&sourceRect.h);
        rect.x = x;
        rect.y = y;
        rect.w = sourceRect.w;
        rect.h = sourceRect.h;
        SDL_FreeSurface(imageSurface);
    }

    const std::string Sprite::TILES_GRASS_PATH = "Resources/Textures/Tiles/Terrain/Grass/";
}