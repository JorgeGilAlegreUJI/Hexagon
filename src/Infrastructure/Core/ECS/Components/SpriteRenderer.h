//
// Created by jorge on 29/10/2022.
//

#ifndef HEXAGON_SPRITERENDERER_H
#define HEXAGON_SPRITERENDERER_H


#include <memory>
#include "../../Utils/Sprite.h"

namespace Core{
    class SpriteRenderer : public BaseComponent {
    private:
        SDL_Rect rect{};
        std::shared_ptr<Sprite> sprite;
    public:
        explicit SpriteRenderer(std::shared_ptr<Sprite> spr);
        void Draw();
        int layer;
    };


}

#endif //HEXAGON_SPRITERENDERER_H
