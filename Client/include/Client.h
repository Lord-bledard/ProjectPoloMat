#ifndef R_TYPE_CLIENT_H
# define R_TYPE_CLIENT_H

#include "RequestManager.h"

class Client {
private:
    RequestManager requestManager;

    void create_game_menu();
    void join_game_menu();

public:
	Client();

    void init();
	void run();


};

#endif                 /* !R_TYPE_CLIENT_H */