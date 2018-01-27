#include <iostream>
#include <MsgStack.h>
#include <Analyser.h>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
//    TcpStack tcpStack;
//    MsgStack *msgStack = &tcpStack;
//    msgStack->sendMsg("123");
//    msgStack->recieveMsg();
    Analyser analyser;
    string contractFilePath = "\\..\\..\\..\\..\\output\\output.wsd";
    analyser.publishMsgInfo(contractFilePath);
    return 0;
}
