#ifndef R_TYPE_REQUESTMANAGER_H
#define R_TYPE_REQUESTMANAGER_H

#include <boost/asio.hpp>
#include "Request.h"
#include "RequestNewGame.h"

using boost::asio::ip::udp;

class RequestManager {
private:
    boost::asio::io_service *io_service;

    udp::socket *socket;
    udp::endpoint *endpoint;

public:
    RequestManager();
    Request prepare_request(RequestType type);
    Request prepare_request_new_game(std::string gameName, int nbPlayers);
    void init_as_server(int port);
    void init_as_client(int port);
    void run();
    void send_request(Request* request);
    void receive();
    void handle_receive(const boost::system::error_code& error, size_t bytes_transferred);

    void connect_to_server();
};

#endif //R_TYPE_REQUESTMANAGER_H
