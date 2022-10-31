//
// Created by jorge on 29/10/2022.
//
#include <SDL2/SDL_image.h>
#include "SpriteRenderer.h"
#include "../Systems/RenderSystem.h"

namespace Core{
    void SpriteRenderer::Draw(){
        auto tempSharedPointer = entity.lock();
        rect.x = tempSharedPointer->getGlobalX();
        rect.y = tempSharedPointer->getGlobalY();
        rect.w = (int)((float)sprite->sourceRect.w * tempSharedPointer->getGlobalScale());
        rect.h = (int)((float)sprite->sourceRect.h * tempSharedPointer->getGlobalScale());
        SDL_RenderCopy(sprite->renderer,sprite->texture,&sprite->sourceRect,&rect);
    }

    SpriteRenderer::SpriteRenderer(const std::string& spriteName,const std::shared_ptr<RenderSystem>& renderSystem) {
        sprite = renderSystem->loadedSprites.at(spriteName);
    }

    SpriteRenderer::~SpriteRenderer() {
        std::cout << "Sprite Renderer destroyed" << std::endl;
    }
}