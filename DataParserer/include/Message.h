#ifndef MSGLOADER_H
#define MSGLOADER_H

#include <string>
#include <vector>

using namespace std;

enum msgStruct {leftModel, arrow, rightModel, msgName, notePosition, session, event, key};
const string MSGHEADPATTERN = "([a-zA-Z_]+)([-<>]+)([a-zA-Z_]+):([a-zA-Z]+)";
const string MSGBODYPARTTERN = "note(.*):\"(.*)\",(.*),\"(.*)\"";
const int MSGHEADPARAMCOUNT = 4;
const int MSGBODYPARAMCOUNT = 4;
class Message
{

    public:
        string getPropertyValue(int property)
        {
            return msg[property];
        }

        void setPropertyValue(string propertyValue)
        {
            msg.push_back(propertyValue);
        }

    private:
        vector<string> msg;
};

#endif // MSGLOADER_H
