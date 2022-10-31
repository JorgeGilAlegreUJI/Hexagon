//
// Created by jorge on 29/10/2022.
//

#ifndef HEXAGON_SPRITERENDERER_H
#define HEXAGON_SPRITERENDERER_H


#include <memory>
#include "../../Utils/Sprite.h"
#include "BaseComponent.h"

namespace Core{
    class RenderSystem; //Forward Declaration
    class SpriteRenderer : public BaseComponent {
    private:
        SDL_Rect rect{};
    public:
        explicit SpriteRenderer(const std::string& spriteName,const std::shared_ptr<RenderSystem>& renderSystem);
        std::shared_ptr<Sprite> sprite;
        void Draw();
        //TODO: int layer;
        ~SpriteRenderer() override;
    };


}

#endif //HEXAGON_SPRITERENDERER_H
