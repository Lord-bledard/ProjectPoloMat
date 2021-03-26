#ifndef R_TYPE_MESSAGE_H
#define R_TYPE_MESSAGE_H

#include <string>

enum MsgType {
    INIT_GAME,
    END_GAME,
    UNKNOWN
};

struct Message {
    MsgType type;
    char data[1024];
};

/*
void initMessage(struct Message msg, MsgType type, std::string data)
{

    msg.type = type;
    strcpy(msg.data, data.c_str());
}

struct Message initMessagelocal(MsgType type, std::string data)
{
    struct Message msg;
    msg.type = type;
    strcpy(msg.data, data.c_str());
    return msg;
}
*/

#endif //R_TYPE_MESSAGE_H
