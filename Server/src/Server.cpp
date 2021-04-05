//server

#include <iostream>
#include "Server.h"
#include <boost/bind.hpp>
#include "RequestClientAction.h"
#include "RequestGameState.h"
#include "ResponseListGames.h"

using boost::asio::ip::udp;


Server::Server()
{
    std::cout << "create server" << std::endl;
}

void Server::run()
{

    while (true)
    {
        this->receive_client_action();
        this->send_game_state();
    }
}


void Server::init(int port)
{

    this->io_service = new boost::asio::io_context();
    this->socket = new udp::socket (*io_service, udp::endpoint(udp::v4(), 9999));

    this->endpoint = new udp::endpoint();

}

void Server::receive_client_action()
{
    RequestClientAction request;
    this->socket->receive_from(boost::asio::buffer(&request, sizeof(RequestClientAction)), *endpoint);

    switch (request.action)
    {
        case ClientActionEnum::IDLE:
            std::cout << "IDLE" << std::endl;
            break;
        case ClientActionEnum::UP:
            std::cout << "UP" << std::endl;
            break;
        case ClientActionEnum::DOWN:
            std::cout << "DOWN" << std::endl;
            break;
        case ClientActionEnum::LEFT:
            std::cout << "LEFT" << std::endl;
            break;
        case ClientActionEnum::RIGHT:
            std::cout << "RIGHT" << std::endl;
            break;
    }
}

void Server::send_game_state()
{

    RequestGameState request;
    request.nbItems = 10;
    this-socket->send_to(boost::asio::buffer(&request, sizeof(RequestGameState)), *endpoint);
}

