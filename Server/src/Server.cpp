//server

#include <iostream>
#include <boost/asio.hpp>
#include <cstdlib>
#include <list>

#include "Message.h"
#include "Server.h"
#include "Game.h"
#include "GameManager.h"

using boost::asio::ip::udp;


Server::Server()
{
    this->gameManager = GameManager();
    std::cout << "create server" << std::endl;
}

Message Server::receive_msg_blocking()
{
    udp::endpoint sender_endpoint;
    struct Message msg;

    socket->receive_from(boost::asio::buffer((char *) &msg, sizeof(struct Message)), sender_endpoint);

    return msg;
}

void Server::run()
{
    std::cout << "run" <<std::endl;

    std::cout << "waiting for connection..." << std::endl;

    Message msg;

    while (msg.type != MsgType::STOP)
    {
        msg = receive_msg_blocking();

        std::cout << "received message : " << msg.data << std::endl;

        switch (msg.type) {
            case MsgType::INIT_GAME:
                std::cout << "new game request" << std::endl;
                this->gameManager.start_new_game();
                break;
            default:
                break;
        }
    }

    std::cout << "bye bye" << std::endl;
}

void Server::init(int port) {

    boost::asio::io_service io_service;
    this->socket = new udp::socket (io_service, udp::endpoint(udp::v4(), port));
}



