//
// Created by jorge on 27/10/2022.
//

#ifndef HEXAGON_CORELOOP_H
#define HEXAGON_CORELOOP_H


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
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;
};


#endif //HEXAGON_CORELOOP_H
