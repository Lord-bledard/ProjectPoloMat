#ifndef R_TYPE_CLIENT_H
# define R_TYPE_CLIENT_H

#include <boost/asio.hpp>
#include <ResponseListGames.h>
#include "Request.h"
#include <ClientActionEnum.h>
#include "RequestGameState.h"

using boost::asio::ip::udp;

class Client {
private:

    boost::asio::io_service *io_service;
    udp::socket *socket;
    udp::endpoint *endpoint;

    void join_game_menu();
    void send_request(Request* request);

public:
	Client();

    void init();
	void run();
	RequestGameState send_action(ClientActionEnum action);
	void receive_game_state();


};

#endif                 /* !R_TYPE_CLIENT_H */