//
// Created by jorge on 29/10/2022.
//

#ifndef HEXAGON_RENDERSYSTEM_H
#define HEXAGON_RENDERSYSTEM_H
#include <map>
#include <unordered_map>
#include <string>
#include <memory>
#include <SDL2/SDL_render.h>
#include <set>
#include "../../Utils/Sprite.h"
#include "../../Utils/Color.h"
#include "../Components/SpriteRenderer.h"


namespace Core{
    class RenderSystem {
    private:
        inline static SDL_Renderer * renderer;

    public:
        inline static std::unordered_map<std::string,std::shared_ptr<Sprite>> loadedSprites;
        inline static std::vector<std::shared_ptr<SpriteRenderer>> activeRenderers;


        explicit RenderSystem();
        static void InitSDL();
        void CreateWindowAndRender();
        static void HandleEvents(bool &isRunning);
        static void Render();
        void Release() const;
        static std::shared_ptr<Sprite> createAndLoadSprite(const std::string& path,const std::string& name);

        const int SCREEN_WIDTH = 960;
        const int SCREEN_HEIGHT = 540;
        const std::shared_ptr<Color> DARK_BACKGROUND = std::make_shared<Color>(32, 33, 36, 1);

        SDL_Window* window;



    };
}


#endif //HEXAGON_RENDERSYSTEM_H
