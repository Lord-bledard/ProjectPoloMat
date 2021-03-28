

#include <GameManager.h>
#include <thread>
#include <iostream>

GameManager::GameManager()
{

}


void GameManager::start_new_game()
{
    auto new_game = []() {
        Game game = Game();
        game.start();
    };

    threads.push_back(std::thread(&new_game));
}
