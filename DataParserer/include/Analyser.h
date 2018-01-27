#ifndef ANALYSER_H
#define ANALYSER_H
#include <string>
#include <iostream>
#include <vector>
#include "Message.h"
using namespace std;
class Analyser
{
    public:
//        string getSubscribeInfo(int subParam);
//        string getFakeProcess();
//        void getOperate(Message &msg, string &strProcessInfo);
//        string getActivityModel(vector<Message> vMsg);
//        void getProcessContent(Message &msg, string &strProcessInfo);
//        string getProcess(vector<Message> vMsg);

        vector<Message> getMsgProcess(const string &contractFilePath,const bool fake);

    private:
        vector<Message> vMsg;
        Message pushMsgPropertyValue(const string &strMsg);
        vector<Message> publishMsgInfo(const string &contractFilePath);

};

#endif // ANALYSER_H
