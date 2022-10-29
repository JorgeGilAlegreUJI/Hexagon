//
// Created by jorge on 27/10/2022.
//

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Sprite.h"
#include "../../../Exceptions/Core_Exception.h"
//#include "BaseComponent.h"

namespace Core{

    void Sprite::Draw(){
        SDL_RenderCopy(renderer,texture,&sourceRect,&rect);
    }

    Sprite::Sprite(Entity *entity, const std::string &path, const std::string &name, SDL_Renderer *renderer,
                   int x,int y) : BaseComponent(entity), name(name), renderer(renderer) {
        if(entity == nullptr){
            //std::string message =  name + ;
            throw Core_Exception(name + "'s entity was null when creating component Sprite");
        }
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
        auto pointer = std::unique_ptr<BaseComponent>(this);
        entity->addComponent<Sprite>(this);
        //entity->addComponent<Sprite>(this);
//        std::cout<< "hi" << std::endl;
//        std::cout<< entity->MSG << std::endl;
    }
}