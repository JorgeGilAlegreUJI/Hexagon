//
// Created by jorge on 27/10/2022.
//

#include <SDL2/SDL.h>
#include <iostream>
#include "CoreLoop.h"
#include "../../Exceptions/SDL_Exception.h"
#include "../Utils/Sprite.h"

Core::Sprite *spr;

namespace Core {
    void CoreLoop::Init() {
        InitSDL();
        CreateWindowAndRender();
        SDL_SetRenderDrawColor(renderer, DARK_BACKGROUND->r, DARK_BACKGROUND->g, DARK_BACKGROUND->b, DARK_BACKGROUND->a);
        spr = new Sprite(Sprite::TILES_GRASS_PATH,"grass_01.png",renderer,0,0);
        isRunning = true;
    }

    void CoreLoop::InitSDL() {
        //Initialize SDL
        bool isInitialized = SDL_Init( SDL_INIT_VIDEO ) >= 0;
        if(!isInitialized ) throw SDL_Exception(SDL_GetError());
    }

    void CoreLoop::CreateWindowAndRender() {
        SDL_CreateWindowAndRenderer(SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN,&window,&renderer);
        if(window == nullptr || renderer == nullptr){
            throw SDL_Exception(SDL_GetError());
        }
    }

    void CoreLoop::HandleEvents() {
        SDL_Event event;
        if (SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT) {
                isRunning = false;
            }
        }

    }

    void CoreLoop::Update() {

    }

    void CoreLoop::Render() {
        SDL_RenderClear(renderer);
        spr->Draw();
        SDL_RenderPresent(renderer);
    }

    void CoreLoop::Release() {
        //Destroy windows & renderer
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        //Quit SDL subsystems
        SDL_Quit();
    }

    bool CoreLoop::IsRunning() {
        return isRunning;
    }

}

