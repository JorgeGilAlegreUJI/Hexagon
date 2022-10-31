//
// Created by jorge on 30/10/2022.
//

#include "TileManager.h"
#include "../Core/ECS/Systems/RenderSystem.h"
#include "Tile.h"

namespace Game {
    TileManager::TileManager(std::shared_ptr<Core::SpriteRendererFactory> &spriteRendererFactory,
                             std::shared_ptr<Core::EntityFactory> &entityFactory) : spriteRendererFactory(spriteRendererFactory), entityFactory(entityFactory){

    }

    void TileManager::getNeis(std::vector<std::shared_ptr<Tile>> &neighbours,int x,int y,int mapSize,std::vector<std::shared_ptr<Tile>> &hexagonCells){

        // Left (G)
        if( x > 0 ){
            neighbours.push_back(hexagonCells[x - 1 + y * mapSize]);
        }

        // Right (D)
        if( x < mapSize-1 ){
            neighbours.push_back(hexagonCells[x + 1 + y * mapSize]);
        }

        if(y % 2 == 0)
        {
            // Top Left (B)
            if( y > 0 ){
                neighbours.push_back(hexagonCells[(x - 1) + (y - 1) * mapSize]);
            }

            // Top Right (C)
            if( y > 0 ) {
                neighbours.push_back(hexagonCells[x + (y - 1) * mapSize]);
            }

            // Bottom Left (F)
            if( y < mapSize && x>0 ) {
                neighbours.push_back(hexagonCells[(x - 1) + (y + 1) * mapSize]);
            }

            // Bottom Right (E)
            if( y < mapSize ){
                neighbours.push_back(hexagonCells[x + (y + 1) * mapSize]);
            }
        }
        else
        {
            // Top Left (B)
            if( y > 0 ) {
                neighbours.push_back(hexagonCells[x + (y - 1) * mapSize]);
            }

            // Top Right (C)
            if( y > 0 ) {
                neighbours.push_back(hexagonCells[(x + 1) + (y - 1) * mapSize]);
            }

            // Bottom Left (F)
            if( y < mapSize ) {
                neighbours.push_back(hexagonCells[x + (y + 1) * mapSize]);

            }

            // Bottom Right (E)
            if( y < mapSize ){
                neighbours.push_back(hexagonCells[(x - 1) + (y + 1) * mapSize]);
            }
        }
    }

    void TileManager::calculateSprite(std::vector<std::shared_ptr<Tile>> &neis,int i){
        std::string spriteNames[5] = { "tile0", "tile1", "tile2", "tile3","tile4" };
        std::string spriteName;

        if(i==0){
            int random = rand() % 5;
            spriteName = spriteNames[random];
            tiles[i]->id = random;

        }
        else
        {
           int increments[5] = {+2,+1,0,-1,-2};
            int nValids=0;
            int total =0;
            for (auto & nei : neis) {
                if(nei->id == -1) continue;
                nValids++;
                total+=nei->id;
            }
            int randomIncrement = increments[rand() % 5];
            int avg = total / nValids;
            int final = avg + randomIncrement;
            final = std::clamp(final,0,4);
            spriteName = spriteNames[final];
            tiles[i]->id = final;
        }
        std::shared_ptr<Core::SpriteRenderer> spriteRenderer = std::make_shared<Core::SpriteRenderer>(spriteName,spriteRendererFactory->renderSystem);
        tiles[i]->addComponent<Core::SpriteRenderer>(spriteRenderer);
    }


    void TileManager::CreateAllTiles() {
        tileParent = entityFactory->createAndRegisterEntity("tileParent");
        float size = ((float)Core::RenderSystem::SCREEN_WIDTH / (float)TOTAL_CENTRAL_TILES) / (float)TILE_WIDTH;
        float tilesWidth = (float)TILE_WIDTH * (float)TOTAL_CENTRAL_TILES * size;
        tileParent->setLocalPosition((int)(tilesWidth/4), TILE_HEIGHT/2);
        int horizontalTotal = 5;
        for (int i = 0; i < TOTAL_CENTRAL_TILES; ++i) {
            int horizontalOffset = TOTAL_CENTRAL_TILES - horizontalTotal;
            for (int j = 0; j < 5; ++j) {
                std::shared_ptr<Tile> tile = std::make_shared<Tile>("Tile"+ std::to_string(i*5+j));
                entityFactory->registerEntity(tile);
                tile->parent = tileParent;
                tiles.push_back(tile);
                tile->setLocalPosition(j*TILE_WIDTH + (horizontalOffset*TILE_WIDTH)/2,i*TILE_HEIGHT - TILE_HEIGHT/4*i);
            }
           if(i%2==0)horizontalTotal = 4;
           else horizontalTotal = 5;
        }

        for (int i = 0; i < TOTAL_CENTRAL_TILES; i++) {
            for (int j = 0; j < 5; j++) {
                std::vector<std::shared_ptr<Tile>> neis;
                getNeis(neis,j,i,5,tiles);
                calculateSprite(neis,i*5+j);
            }
        }
    }

} // Game