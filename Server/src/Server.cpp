//server

#include <iostream>
#include <boost/asio.hpp>
#include <cstdlib>
#include <list>
#include <RequestNewGame.h>

#include "Request.h"
#include "Server.h"
#include "GameManager.h"

using boost::asio::ip::udp;


Server::Server()
{
    this->gameManager = GameManager();
    std::cout << "create server" << std::endl;
}

void Server::run()
{
    std::cout << "run" <<std::endl;

    std::cout << "waiting for connection..." << std::endl;

    this->requestManager.receive();
    this->requestManager.run();

    /*
    while (req->type != RequestType::STOP)
    {


       // std::cout << "received message : " << req.data << std::endl;

        switch (req->type) {
            case RequestType::INIT_GAME: {
                std::cout << "new game request" << std::endl;
                this->gameManager.start_new_game();
                break;
            }
            case RequestType::END_GAME: {
                std::cout << "test" << std::endl;
            }
            default: {
                break;
            }
        }
    }
     */

    std::cout << "bye bye" << std::endl;
}

void Server::init(int port)
{
    this->requestManager.init_as_server(port);
}



