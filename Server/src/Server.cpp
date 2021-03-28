//server

#include <iostream>
#include <boost/asio.hpp>
#include <cstdlib>
#include <list>

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

    Request req;

    while (req.type != RequestType::STOP)
    {
        req = this->requestManager.receive_request_blocking();

        std::cout << "received message : " << req.data << std::endl;

        switch (req.type) {
            case RequestType::INIT_GAME:
                std::cout << "new game request" << std::endl;
                this->gameManager.start_new_game();
                break;
            default:
                break;
        }
    }

    std::cout << "bye bye" << std::endl;
}

void Server::init(int port)
{
    this->requestManager.init(port);
}



