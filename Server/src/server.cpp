//server

#include <iostream>
#include <boost/asio.hpp>
#include <cstdlib>

using boost::asio::ip::udp;
/*
using namespace boost::asio;
using namespace boost::asio::ip;

// Driver program for receiving data from buffer
std::string getData(tcp::socket& socket)
{
    streambuf buf;
    read_until(socket, buf, "\n");
    std::string data = buffer_cast<const char*>(buf.data());
    return data;
}

// Driver program to send data
void sendData(tcp::socket& socket, const std::string& message)
{
    write(socket,
          buffer(message + "\n"));
}

int main(int argc, char* argv[])
{

    io_service io_service;


    // Listening for any new incomming connection
    // at port 9999 with IPv4 protocol
    tcp::acceptor acceptor_server(io_service,tcp::endpoint(tcp::v4(), 9999));

    // Creating socket object
    tcp::socket server_socket(io_service);

    std::cout << "waiting for connection ..." << std::endl;
    // waiting for connection
    acceptor_server.accept(server_socket);

    std::cout << "connection accepted" << std::endl;

    // Reading username
    std::string u_name = getData(server_socket);
    // Removing "\n" from the username
    u_name.pop_back();

    // Replying with default mesage to initiate chat
    std::string response, reply;
    reply = "you said " + u_name + " !";
    std::cout << "Server: " << reply << std::endl;

    std::string thanks = "thanks";
    sendData(server_socket, thanks);

    return 0;
}
*/



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