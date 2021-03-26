#ifndef R_TYPE_SERVER_H
#define R_TYPE_SERVER_H

#include "Game.h"
#include <list>
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

class Server {

private:
    int port;
    std::list<Game> games;
    udp::socket *socket;


public:
    Server();
    void init(int port);
    void run();
};

#endif //R_TYPE_SERVER_H