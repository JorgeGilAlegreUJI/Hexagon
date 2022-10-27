//
// Created by jorge on 27/10/2022.
//

#ifndef HEXAGON_CORELOOP_H
#define HEXAGON_CORELOOP_H
#include "../Utils/Color.h"

namespace Core {
    class CoreLoop {
    public:
        void Init();
        void HandleEvents();
        void Update();
        void Render();
        void Release();
        bool IsRunning();
    private:
        void InitSDL();
        void CreateWindowAndRender();
    private:
        const int SCREEN_WIDTH = 960;
        const int SCREEN_HEIGHT = 540;
        const Core::Color* DARK_BACKGROUND = new Color(32, 33, 36, 1);
        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;
        
    };
}


#endif //HEXAGON_CORELOOP_H
