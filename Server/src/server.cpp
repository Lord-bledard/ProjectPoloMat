//server

#include <iostream>
#include <boost/asio.hpp>

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
    std::cout << "ok" << std::endl;

    io_service io_service;

    // Listening for any new incomming connection
    // at port 9999 with IPv4 protocol
    tcp::acceptor acceptor_server(io_service,tcp::endpoint(tcp::v4(), 9999));

    // Creating socket object
    tcp::socket server_socket(io_service);

    // waiting for connection
    acceptor_server.accept(server_socket);

    // Reading username
    std::string u_name = getData(server_socket);
    // Removing "\n" from the username
    u_name.pop_back();

    // Replying with default mesage to initiate chat
    std::string response, reply;
    reply = "Hello " + u_name + "!";
    std::cout << "Server: " << reply << std::endl;
    sendData(server_socket, reply);

    while (true) {

        // Fetching response
        response = getData(server_socket);

        // Popping last character "\n"
        response.pop_back();

        // Validating if the connection has to be closed
        if (response == "exit") {
            std::cout << u_name << " left!" << std::endl;
            break;
        }
        std::cout << u_name << ": " << response << std::endl;

        // Reading new message from input stream
        std::cout << "Server"
             << ": ";
        getline(std::cin, reply);
        sendData(server_socket, reply);

        if (reply == "exit")
            break;
    }
    return 0;
}