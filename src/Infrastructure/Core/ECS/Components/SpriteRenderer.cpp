//
// Created by jorge on 29/10/2022.
//

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>

#include <utility>
#include "SpriteRenderer.h"
namespace Core{
    void SpriteRenderer::Draw(){
        rect.x = entity->getGlobalX();
        rect.y = entity->getGlobalY();
        SDL_QueryTexture(sprite->texture, nullptr, nullptr,&sprite->sourceRect.w,&sprite->sourceRect.h);
        rect.w = sprite->sourceRect.w;
        rect.w *= (int)entity->getGlobalScale();
        rect.h = sprite->sourceRect.h;
        rect.h *= (int)entity->getGlobalScale();
        SDL_RenderCopy(sprite->renderer,sprite->texture,&sprite->sourceRect,&rect);
    }

    SpriteRenderer::SpriteRenderer(std::shared_ptr<Sprite> spr) : sprite(std::move(spr)),layer(0){}
}