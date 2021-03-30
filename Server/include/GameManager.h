#ifndef R_TYPE_GAMEMANAGER_H
#define R_TYPE_GAMEMANAGER_H

#include "Game.h"
//#include <thread>
#include <list>

class GameManager
{
private:
  //  std::list<std::thread> threads;
    std::list<Game> games;
public:

    GameManager();

    void start_new_game(int nbPlayers, std::string gameName);


};
#endif //R_TYPE_GAMEMANAGER_H
