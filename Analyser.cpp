#include "Analyser.h"
#include "DataLoader.h"
#include <iostream>
#include <Util.h>
#include <Message.h>


const int FIRSTELEMENT = 0;

//string Analyser::getSubscribeInfo(int subParam)
//{
//    string scribeInfoTmp;
//    string scribeInfo;
//    vector<Message> vMsg;
//
//    vMsg = publishMsgInfo();
//    for(int i=0;i < vMsg.size();i++)
//    {
//        scribeInfoTmp = vMsg[i].getPropertyValue(subParam);
//        if(scribeInfo.find(scribeInfoTmp+"\n") == string::npos)
//        {
//        scribeInfo += scribeInfoTmp;
//        scribeInfo += "\n";
//        }
//    }
//    cout<<"\nsubscribe info:"<<endl;
//    cout<<scribeInfo;
//    return scribeInfo;
//}
//
//string Analyser::getFakeProcess()
//{
//    vector<Message> vMsg;
//    string fakeProcess;
//
//    vMsg = publishMsgInfo();
//    cout << "\nfake process info:" << endl;
//    fakeProcess += getActivityModel(vMsg);
//    fakeProcess+= getProcess(vMsg);
//    return fakeProcess;
//}
//
//string Analyser::getProcess(vector<Message> vMsg)
//{
//    string strProcessInfo;
//
//    for(int i = 0;i < vMsg.size();i++)
//    {
//        strProcessInfo += to_string(i+1)+")     ";
//        getOperate(vMsg[i] ,strProcessInfo);
//        getProcessContent(vMsg[i], strProcessInfo);
//    }
//    cout <<strProcessInfo<<endl;
//    return strProcessInfo;
//
//}
//
//void Analyser::getOperate(Message &msg, string &strProcessInfo)
//{
//    string operate;
//
//    string leftModelValue = msg.getPropertyValue(leftModel);
//    string rightModelValue = msg.getPropertyValue(rightModel);
//    string arrowValue = msg.getPropertyValue(arrow);
//
//    if (((leftModelValue.find(FAKE) != string::npos) && (arrowValue.find(RIGHTARROW) != string::npos)) ||
//        ((rightModelValue.find(FAKE) != string::npos) && (arrowValue.find(LEFTARROW) != string::npos)))
//    {
//        operate = "Send";
//    }else
//    {
//        operate = "Wait";
//    }
//    strProcessInfo += operate +" " + msg.getPropertyValue(msgName)+"(";
//}
//
//void Analyser::getProcessContent(Message &msg, string &strProcessInfo)
//{
//    const int MSGPARAMCOUNT = MSGHEADPARAMCOUNT+MSGBODYPARAMCOUNT;
//
//    for(int j= MSGHEADPARAMCOUNT+1; j<MSGPARAMCOUNT-1; j++)
//    {
//        strProcessInfo += msg.getPropertyValue(j);
//        strProcessInfo += "-";
//    }
//    strProcessInfo += msg.getPropertyValue(MSGPARAMCOUNT-1) + ")\n";
//}
//
//
//string Analyser::getActivityModel(vector<Message> vMsg)
//{
//    string leftModelValue = vMsg[FIRSTELEMENT].getPropertyValue(leftModel);
//    string rightModelValue = vMsg[FIRSTELEMENT].getPropertyValue(rightModel);
//
//    if(leftModelValue.find(FAKE) != string::npos)
//    {
//        cout<<"主动模式(active)："<<endl;
//        return "主动模式(active)：\n";
//    }
//    else if (rightModelValue.find(FAKE) != string::npos)
//    {
//        cout<<"被动模式(passivity)："<<endl;
//        return "被动模式(passivity)：\n";
//    }
//    else
//    {
//        cout<<"print activity model error!!";
//        exit(1);
//    }
//}




Message Analyser::pushMsgPropertyValue(string &strMsg)
{
    Message msg;
    int indexBefore = 0;
    int indexAfter = strMsg.find('\n');
    string strMsgHead = strMsg.substr(indexBefore, indexAfter);
    string strMsgBody = strMsg.substr(indexAfter, strMsg.length()-1);
    vector<string> vMsgStruct = Util::getMatchStringVector(strMsgHead, MSGHEADPATTERN,MSGHEADPARAMCOUNT);
    vector<string> vMsgBody = Util::getMatchStringVector(strMsgBody, MSGBODYPARTTERN,MSGBODYPARAMCOUNT);
    vMsgStruct.insert(vMsgStruct.end(),vMsgBody.begin(),vMsgBody.end());
    for (unsigned int i =0;i<vMsgStruct.size();i++)
    {
        msg.setPropertyValue(vMsgStruct[i]);
    }
    return msg;
}

vector<Message> Analyser::publishMsgInfo(string &contractFilePath)
{
    FileLoader fileLoader;
    DataLoader *dataLoder = &fileLoader;
    vector<string> vStrMsg = dataLoder->loadData(contractFilePath);
    for (unsigned int i =0;i<vStrMsg.size();i++)
    {
        string strMsg = vStrMsg[i];
        vMsg.push_back(pushMsgPropertyValue(strMsg));
    }
    return vMsg;
}

vector<Message> getMsgProcess(string &contractFilePath, bool fake)
{
    publishMsgInfo(contractFilePath);
    for(int i=0 ;i<vMsg.size();i++)
    {

    }


}
