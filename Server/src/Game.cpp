#include <iostream>
#include <Ship.h>
#include <Wall.h>

#include "Game.h"

Game::Game()
{
    std::cout << "init game " << std::endl;

    Ship ship = Ship();
    ship.setPosition(40, 60);

    Wall wall1 = Wall();
    Wall wall2 = Wall();
    Wall wall3 = Wall();
    Wall wall4 = Wall();

    wall1.setPosition(0 + 0 * wall1.width, 0);
    wall2.setPosition(0 + 1 * wall1.width, 0);
    wall3.setPosition(0 + 2 * wall1.width, 0);
    wall4.setPosition(0 + 3 * wall1.width, 0);

    this->entities.push_back(ship);
    this->entities.push_back(wall1);
    this->entities.push_back(wall2);
    this->entities.push_back(wall3);
    this->entities.push_back(wall4);
}
