#ifndef R_TYPE_REQUESTMANAGER_H
#define R_TYPE_REQUESTMANAGER_H

#include <boost/asio.hpp>
#include "Request.h"

using boost::asio::ip::udp;

class RequestManager {
private:
    boost::asio::io_service *io_service;
    udp::socket *socket;
    udp::endpoint *endpoint;

public:
    RequestManager();
    Request create_request(RequestType type);
    void init(int port);
    void send_request(Request request);
    Request receive_request_blocking();
    void connect_to_server();
};

#endif //R_TYPE_REQUESTMANAGER_H
