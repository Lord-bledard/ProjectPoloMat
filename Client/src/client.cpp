//client

#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::udp;


int main(int argc, char* argv[])
{
    try
    {

        boost::asio::io_service io_service;

        udp::socket s(io_service, udp::endpoint(udp::v4(), 0));

        udp::resolver resolver(io_service);
        udp::resolver::query query(udp::v4(), "127.0.0.1", "9999");

        udp::endpoint endpoint = *resolver.resolve(query);

        std::cout << "Enter message: ";
        char request[1024];
        std::cin.getline(request, 1024);
        size_t request_length = std::strlen(request);
        std::cout << "request : "<< request << std::endl;
        s.send_to(boost::asio::buffer(request, request_length), endpoint);

        char reply[1024];
        udp::endpoint sender_endpoint;
        size_t reply_length = s.receive_from(
                boost::asio::buffer(reply, 1024), sender_endpoint);
        std::cout << "Reply is: ";
        std::cout.write(reply, reply_length);
        std::cout << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}