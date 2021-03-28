#ifndef R_TYPE_SERVER_H
#define R_TYPE_SERVER_H

#include "Game.h"
#include <list>
#include <iostream>
#include <boost/asio.hpp>
#include <RequestManager.h>
#include "Request.h"
#include "GameManager.h"

using boost::asio::ip::udp;

class Server {

private:

    GameManager gameManager;
    RequestManager requestManager;


public:
    Server();
    void init(int port);
    void run();


};

#endif //R_TYPE_SERVER_H