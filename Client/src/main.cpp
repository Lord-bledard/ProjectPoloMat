#include <iostream>
#include <Client.h>

int	main(int argc, char *argv[])
{
    Client client = Client();
    client.init();
    client.run();
}