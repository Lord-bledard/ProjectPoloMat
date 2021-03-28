#include <iostream>

#include "Game.h"

Game::Game()
{
    std::cout << "init game" << std::endl;
}


void Game::start()
{
    std::cout << "start game in new thread" << std::endl;
}