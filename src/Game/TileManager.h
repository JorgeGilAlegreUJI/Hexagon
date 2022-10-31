//
// Created by jorge on 30/10/2022.
//

#ifndef HEXAGON_TILEMANAGER_H
#define HEXAGON_TILEMANAGER_H

#include "../Core/ECS/Systems/Factories/SpriteRendererFactory.h"
#include "Tile.h"

namespace Game {

    class TileManager {
    private:
        void getNeis(std::vector<std::shared_ptr<Tile>> &neighbours, int x, int y, int mapSize,
                     std::vector<std::shared_ptr<Tile>> &hexagonCells);

        void calculateSprite(std::vector<std::shared_ptr<Tile>> &neis, int i);

        const int TOTAL_CENTRAL_TILES = 7;
        const int TILE_WIDTH = 120;
        const int TILE_HEIGHT = 140;
        std::shared_ptr<Core::Entity> tileParent;
        std::vector<std::shared_ptr<Tile>> tiles;

        std::shared_ptr<Core::SpriteRendererFactory> spriteRendererFactory;
        std::shared_ptr<Core::EntityFactory> entityFactory;
    public:
        explicit TileManager(std::shared_ptr<Core::SpriteRendererFactory> &spriteRendererFactory,
        std::shared_ptr<Core::EntityFactory> &entityFactory);
        void CreateAllTiles();
    };

} // Game

#endif //HEXAGON_TILEMANAGER_H
