#include <iostream>
//#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "CoreLoop.h"

int main(int argc, char* args[] ){
    auto coreLoop = Core::CoreLoop();
    try {
        coreLoop.Init();
        while (coreLoop.IsRunning()){
            coreLoop.HandleEvents();
            coreLoop.Update();
            coreLoop.Render();
        }
        coreLoop.Release();
    }
    catch(std::exception &exception) {
        fprintf(stderr,"%s", exception.what());
        SDL_Quit();
        return -1;
    }
    return 0;
}


