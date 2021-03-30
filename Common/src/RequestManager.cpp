#include "RequestManager.h"
#include "RequestNewGame.h"
#include <iostream>
#include <boost/bind.hpp>

using boost::asio::ip::udp;

RequestManager::RequestManager()
{
    this->io_service = new boost::asio::io_service();
}

void RequestManager::run()
{
    this->io_service->run();
}

void RequestManager::init_as_server(int port)
{
    endpoint = new udp::endpoint(udp::v4(), port);

    this->socket = new udp::socket (*io_service, *endpoint);
}

void RequestManager::init_as_client(int port)
{
    udp::resolver resolver(*io_service);
    udp::resolver::query query(udp::v4(), "127.0.0.1", "9999");
    udp::endpoint endpoint_ = *resolver.resolve(query);
    endpoint = &endpoint_;

    this->socket = new udp::socket (*io_service, udp::endpoint(udp::v4(), 0));

    Request req = Request(RequestType::STOP);
    std::cout << "request type : " << req.type << std::endl;
    this->socket->send_to(boost::asio::buffer(&req, sizeof(Request)), *endpoint);
}


Request RequestManager::prepare_request(RequestType type)
{
    return Request(UNKNOWN);
}

void RequestManager::send_request(Request* request)
{
    size_t s;

    switch (request->type) {
        case RequestType::INIT_GAME: {
                s = sizeof(RequestNewGame);
                std::cout << "send init game " << std::endl;
                RequestNewGame *terr = (RequestNewGame *) request;
                std::cout << "Gamename :" << terr->gameName << std::endl;
                std::cout << "size :" << s << std::endl;
                break;
        }
        default: {
            break;
        }
    }


    socket->send_to(boost::asio::buffer((char *) request, s), *endpoint, request->type);
}


void RequestManager::handle_receive(const boost::system::error_code& error, size_t bytes_transferred)
{
    std::cout << "ulala" << std::endl;

    if (error == boost::asio::error::operation_aborted)
    {
        return;
    }

    // Prepare buffer
    unsigned int available = this->socket->available();

    std::cout << "available : " << available << std::endl;

    unsigned char* buffer = new unsigned char[available];

    // Fill it

    boost::system::error_code ec;
    unsigned int packetSize = this->socket->receive_from(boost::asio::buffer(buffer, available), *endpoint, 0, ec);

    if (ec)
    {
        std::cout << "error : " << ec << std::endl;
    }

    std::cout << "packetsize : " << packetSize << std::endl;

    Request *req = (Request*) buffer;
    std::cout << "request type : " << req->type << std::endl;


    this->receive();
}



void RequestManager::receive()
{
    socket->async_receive(boost::asio::null_buffers(),
                          boost::bind(&RequestManager::handle_receive,this,
                                      boost::asio::placeholders::error,boost::asio::placeholders::bytes_transferred));
}

Request RequestManager::prepare_request_new_game(std::string gameName, int nbPlayers)
{
    return Request(INIT_GAME);
}
