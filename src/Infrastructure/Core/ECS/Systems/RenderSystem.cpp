//
// Created by jorge on 29/10/2022.
//

#include "RenderSystem.h"
#include <string>
#include "../../../Exceptions/SDL_Exception.h"
#include <SDL2/SDL.h>

//"Resources/Textures/Tiles/Terrain/Grass/"
//"grass_01.png"
namespace Core{

    std::shared_ptr<Sprite> Core::RenderSystem::createAndLoadSprite(const std::string& path, const std::string& name) {
        std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>(path, name, renderer);
        std::pair<std::string,std::shared_ptr<Sprite>> pair = std::pair<std::string,std::shared_ptr<Sprite>>(name,sprite);
        loadedSprites.insert(pair);
        return sprite;
    }

    RenderSystem::RenderSystem() {
        InitSDL();
        CreateWindowAndRender();
        SDL_SetRenderDrawColor(renderer, DARK_BACKGROUND->r, DARK_BACKGROUND->g, DARK_BACKGROUND->b, DARK_BACKGROUND->a);
    }

    void RenderSystem::InitSDL() {
        //Initialize SDL
        bool isInitialized = SDL_Init( SDL_INIT_VIDEO ) >= 0;
        if(!isInitialized ) throw SDL_Exception(SDL_GetError());
    }

    void RenderSystem::CreateWindowAndRender() {
        SDL_CreateWindowAndRenderer(SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN,&window,&renderer);
        if(window == nullptr || renderer == nullptr){
            throw SDL_Exception(SDL_GetError());
        }
    }

    void RenderSystem::HandleEvents(bool &isRunning) {
        SDL_Event event;
        if (SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT) {
                isRunning = false;
            }
        }
    }

    void RenderSystem::Render()
    {
        SDL_RenderClear(renderer);
        for (const std::shared_ptr<SpriteRenderer>& sr : activeRenderers)
            sr->Draw();
        SDL_RenderPresent(renderer);
    }

    void RenderSystem::Release() const {
        //Destroy windows & renderer
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        //Quit SDL subsystems
        SDL_Quit();
    }


}