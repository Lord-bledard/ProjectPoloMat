//client

#include <iostream>
#include <boost/asio.hpp>
#include <Request.h>
#include <Menu.h>
#include <Client.h>
#include <Mainframe.h>
#include <ClientActionEnum.h>
#include <RequestClientAction.h>
#include <RequestGameState.h>
#include "ResponseListGames.h"

using boost::asio::ip::udp;


Client::Client()
{

}


void Client::run()
{
    Mainframe mainframe = Mainframe(this);
    mainframe.run();
}

void Client::init()
{

    try
    {

        /* init socket */
        this->io_service = new boost::asio::io_service();
        this->socket = new udp::socket(*io_service, udp::endpoint(udp::v4(), 0));

        /* connect to server */


    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}


RequestGameState Client::send_action(ClientActionEnum action)
{
    std::cout << "test" << std::endl;
    /*
    size_t s = sizeof(RequestClientAction);
    RequestClientAction request(action);
    socket->send_to(boost::asio::buffer(&request, s), *endpoint);
     */
    try
    {
        RequestClientAction truc = {.action = ClientActionEnum::RIGHT};
        size_t s = sizeof(RequestClientAction);
        std::cout << s << std::endl;

        udp::resolver resolver(*io_service);
        udp::resolver::query query(udp::v4(), "127.0.0.1", "9999");
        udp::endpoint server_endpoint = *resolver.resolve(query);

        this->socket->send_to(boost::asio::buffer((char *) &truc, s), server_endpoint);

        RequestGameState state;
        this->socket->receive_from(boost::asio::buffer((char *) &state, sizeof(RequestGameState)), server_endpoint);

        std::cout << state.nbItems << std::endl;

    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    /*
    RequestClientAction truc = {.action = ClientActionEnum::RIGHT};
    size_t s = sizeof(RequestClientAction);
    this->socket->send_to(boost::asio::buffer((char *) &truc, s), *endpoint);
    */
}
