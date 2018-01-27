#ifndef MSGSTACK_H
#define MSGSTACK_H

#include <iostream>
#include <string>

using namespace std;
class MsgStack
{
    public:
        MsgStack();
        virtual ~MsgStack();
        virtual bool sendMsg(string strMsg);
        virtual string recieveMsg();

    protected:

    private:
};

class TcpStack:public MsgStack
{
    public:
        bool sendMsg(string strMsg);
        string recieveMsg();
};

#endif // MSGSTACK_H
