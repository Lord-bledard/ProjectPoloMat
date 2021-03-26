//server

#include <iostream>
#include <boost/asio.hpp>
#include <cstdlib>
#include <list>

#include "Message.h"
#include "Server.h"
#include "Game.h"


using boost::asio::ip::udp;


Server::Server()
{
    std::cout << "create server" << std::endl;
}


void Server::run()
{
    std::cout << "run" <<std::endl;
    /* wait for receive */
    udp::endpoint sender_endpoint;
    char data[1024];
    std::cout << "waiting for connection..." << std::endl;

    //struct Message msg = initMessagelocal(INIT_GAME, "salut");

    struct Message msg;

    socket->receive_from(boost::asio::buffer((char *) &msg, sizeof(struct Message)), sender_endpoint);

    std::cout << msg.data << std::endl;

}

void Server::init(int port) {

    boost::asio::io_service io_service;
    this->socket = new udp::socket (io_service, udp::endpoint(udp::v4(), port));
}



