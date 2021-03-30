//client

#include <iostream>
#include <boost/asio.hpp>
#include <Request.h>
#include <Menu.h>
#include <Client.h>
#include "RequestNewGame.h"
#include "RequestManager.h"

using boost::asio::ip::udp;

#define RETURN 0

Client::Client()
{

}

void Client::create_game_menu()
{

    Menu numPlayersMenu = Menu("How many players ?",
                               {"return", "1 player", "2 players", "3 players", "4 players"});

    int selection = numPlayersMenu.getSelectedOption();

    if (selection == RETURN)
    {
        std::cout << "return" << std::endl;
        return;
    }

    int nbPlayers = selection;

    std::string gameName;

    std::cout << "Choose a name for your game : ";
    std::cin >> gameName;

    Request req = RequestNewGame(nbPlayers, gameName);
    this->requestManager.send_request(&req);

    std::cout << "Game created : " << gameName << std::endl << std::endl;

}

void Client::join_game_menu()
{
    //TODO ask server for games names

    std::vector<std::string> options = {"return", "a", "b", "c"};

    Menu joinGameMenu = Menu("What game do you want to join ?", options);

    int selection = joinGameMenu.getSelectedOption();

    if (selection == RETURN)
        return;

    std::string gameName = options[selection];

    //TODO send request
    std::cout << "join game " << gameName << std::endl;
}

void Client::run()
{

    Menu mainMenu = Menu("What do you want to do ?",
                         {"Start new game", "Join existing game", "Exit"});

    enum options {NEW_GAME, JOIN_GAME, EXIT};

    int exit = 0;

    while(!exit)
    {
        switch(mainMenu.getSelectedOption())
        {
            case NEW_GAME:
                create_game_menu();
                break;
            case JOIN_GAME:
                join_game_menu();
                break;
            case EXIT:
                exit = 1;
                break;
        }
    }
}

void Client::init()
{
    this->requestManager.init_as_client(0);
}
