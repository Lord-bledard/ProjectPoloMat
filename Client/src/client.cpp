//client

#include <iostream>
#include <boost/asio.hpp>
#include <Message.h>

using boost::asio::ip::udp;


int main(int argc, char* argv[])
{
    try
    {

        /* init socket */
        boost::asio::io_service io_service;
        udp::socket s(io_service, udp::endpoint(udp::v4(), 0));

        /* connect to server */
        udp::resolver resolver(io_service);
        udp::resolver::query query(udp::v4(), "127.0.0.1", "9999");
        udp::endpoint endpoint = *resolver.resolve(query);

        /* enter Message */

        Message msg;

        while (msg.type != MsgType::STOP)
        {
            std::cout << "Enter Message: ";
            std::cin.getline(msg.data, 20);

            if (strcmp(msg.data, "stop") == 0)
                msg.type = MsgType::STOP;

            s.send_to(boost::asio::buffer((char *) &msg, sizeof(Message)), endpoint);
            std::cout << "message sended : " << msg.data << std::endl;
        }

    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}