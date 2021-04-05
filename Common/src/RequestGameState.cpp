#include <GameEntity.h>
#include "RequestGameState.h"
#include <iostream>

RequestGameState::RequestGameState() {

}


RequestGameState::RequestGameState(std::vector<GameEntity> gameEntities)
{
    for (int i = 0; i < gameEntities.size(); i++)
    {
        GameEntity entity = gameEntities[i];

        this->gameItems[i] = {.entity = entity.type, entity.x, entity.y};
    }
}

