#include "Server.h"
#include "Game.h"
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::udp;


int main(int argc, char* argv[])
{


    Server server = Server();
    server.init(9999);
    server.run();


    return 0;
}