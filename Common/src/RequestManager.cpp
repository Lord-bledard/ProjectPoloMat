#include "RequestManager.h"

using boost::asio::ip::udp;

RequestManager::RequestManager()
{
    this->io_service = new boost::asio::io_service();
}

void RequestManager::init(int port)
{
    this->socket = new udp::socket (*io_service, udp::endpoint(udp::v4(), port));
}

void RequestManager::connect_to_server()
{
    udp::resolver resolver(*io_service);
    udp::resolver::query query(udp::v4(), "127.0.0.1", "9999");
    udp::endpoint endpoint = *resolver.resolve(query);
}

Request RequestManager::create_request(RequestType type)
{
    return Request(UNKNOWN);
}

void RequestManager::send_request(Request request)
{
    socket->send_to(boost::asio::buffer((char *) &request, sizeof(struct Request)), *endpoint, request.type);
}

Request RequestManager::receive_request_blocking()
{
    struct Request request;

    socket->receive_from(boost::asio::buffer((char *) &request, sizeof(struct Request)), *endpoint, request.type);

    return request;
}
