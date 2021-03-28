#ifndef R_TYPE_CLIENT_H
# define R_TYPE_CLIENT_H

#include "RequestManager.h"

class Client {
private:
    RequestManager requestManager;
public:
	Client();

    void init();
	void run();


};

#endif                 /* !R_TYPE_CLIENT_H */