//
// Created by jorge on 27/10/2022.
//

#ifndef HEXAGON_CORELOOP_H
#define HEXAGON_CORELOOP_H
#include "../Utils/Color.h"
#include "../ECS/Systems/RenderSystem.h"

namespace Core {
    class CoreLoop {
    public:
        explicit CoreLoop();
        void Init();
        void HandleEvents();
        void Update();
        void Render();
        void Release();
        bool isRunning;
    private:
        std::unique_ptr<RenderSystem> renderSystem;
    };
}


#endif //HEXAGON_CORELOOP_H
