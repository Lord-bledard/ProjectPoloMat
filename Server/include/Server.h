#ifndef R_TYPE_SERVER_H
#define R_TYPE_SERVER_H

#include "Game.h"
#include <list>
#include <iostream>
#include <boost/asio.hpp>
#include "Message.h"
#include "GameManager.h"

using boost::asio::ip::udp;

class Server {

private:
    int port;

    udp::socket *socket;
    GameManager gameManager;

    Message receive_msg_blocking();

public:
    Server();
    void init(int port);
    void run();


};

#endif //R_TYPE_SERVER_H