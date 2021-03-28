//client

#include <iostream>
#include <boost/asio.hpp>
#include <Message.h>
#include <Menu.h>

using boost::asio::ip::udp;

#define RETURN 0

void create_game_menu()
{

    Menu numPlayersMenu = Menu("How many players ?",
                               {"return", "1 player", "2 players", "3 players", "4 players"});

    int numPlayers = numPlayersMenu.getSelectedOption();

    if (numPlayers == 0)
    {
        std::cout << "return" << std::endl;
        return;
    }

    std::string gameName;

    std::cout << "Choose a name for your game : ";
    std::cin >> gameName;

    //TODO send game creation request

    std::cout << "Game created : " << gameName << std::endl << std::endl;

}

void join_game_menu()
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

int main(int argc, char* argv[])
{
    try
    {

        /* init socket */
        boost::asio::io_service io_service;
        udp::socket s(io_service, udp::endpoint(udp::v4(), 0));

        /* connect to server */
        udp::resolver resolver(io_service);
        udp::resolver::query query(udp::v4(), "127.0.0.1", "9999");
        udp::endpoint endpoint = *resolver.resolve(query);


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



    /*
        while (msg.type != MsgType::STOP)
        {
            std::cout << "Enter Message: ";
            std::cin.getline(msg.data, 20);

            if (strcmp(msg.data, "stop") == 0)
                msg.type = MsgType::STOP;

            s.send_to(boost::asio::buffer((char *) &msg, sizeof(Message)), endpoint);
            std::cout << "message sended : " << msg.data << std::endl;
        }
    */

    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}