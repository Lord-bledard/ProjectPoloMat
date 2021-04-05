#ifndef R_TYPE_SHIP_H
# define R_TYPE_SHIP_H

#include <boost/asio.hpp>
#include <ResponseListGames.h>
#include "Request.h"

using boost::asio::ip::udp;

class Ship {
private:

public:
	Ship();
	int _id;
    
};

#endif                 /* !R_TYPE_SHIP_H */