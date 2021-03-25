//server

#include <iostream>
#include <boost/asio.hpp>
#include <cstdlib>

using boost::asio::ip::udp;

int main(int argc, char* argv[])
{
    try
    {

        boost::asio::io_service io_service;
        udp::socket sock(io_service, udp::endpoint(udp::v4(), 9999));

        udp::endpoint sender_endpoint;
        char data[1024];
        std::cout << "waiting for connection..." << std::endl;
        size_t length = sock.receive_from(boost::asio::buffer(data, 1024), sender_endpoint);

        std::cout << data << std::endl;

        sock.send_to(boost::asio::buffer(data, length), sender_endpoint);

    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}