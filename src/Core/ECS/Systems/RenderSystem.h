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
#include "HierarchySystem.h"


namespace Core{
    class SpriteRenderer;
    class RenderSystem {
    private:
        SDL_Renderer * renderer;
        std::shared_ptr<HierarchySystem> hierarchySystem;

    public:
        std::unordered_map<std::string,std::shared_ptr<Sprite>> loadedSprites;
        explicit RenderSystem(std::shared_ptr<HierarchySystem> hierarchySystem);
        void InitSDL();
        void CreateWindowAndRender();
        void HandleEvents(bool &isRunning);
        void Render();
        void Release() const;
        std::shared_ptr<Sprite> createAndLoadSprite(const std::string& path,const std::string& name);

        const Color DARK_BACKGROUND = Color(32, 33, 36, 1);
        static const int SCREEN_WIDTH = 1728;
        static const int SCREEN_HEIGHT = 972;
        SDL_Window* window;
    };
}


#endif //HEXAGON_RENDERSYSTEM_H
