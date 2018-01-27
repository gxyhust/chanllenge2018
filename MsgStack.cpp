#include "MsgStack.h"

MsgStack::MsgStack()
{
    //ctor
}

MsgStack::~MsgStack()
{
    //dtor
}
bool MsgStack::sendMsg(string strMsg)
{
    cout<< "msgstack send msg";
    return true;
}

string MsgStack::recieveMsg()
{
    cout<< "msgstack recieve msg";
    return "1";
}


bool TcpStack::sendMsg(string strMsg)
{
    cout<< "tcpstack send msg";
    return true;
}

string TcpStack::recieveMsg()
{
    cout<< "tcpstack recieve msg";
    return "1";
}
