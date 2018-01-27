#define BUFFER 256

#include "DataLoader.h"
#include "Util.h"

char buffer[BUFFER];
const string defaultFile = "\\..\\..\\..\\output\\output.wsd";

vector<string> DataLoader::loadData(string &input)
{
}

vector<string> FileLoader::loadData(string &contractFilePath)
{
    string strMsg;
    vector<string> vStrMsg;
    ifstream fin;
    Util* u;

    bool flag = false;
    if (contractFilePath=="")
        contractFilePath = defaultFile;
    string fileAbsolutePath = Util::getProgramDir() + contractFilePath;
    checkContract();
    cout << "fileAbsolutePath="<<fileAbsolutePath<< endl;
    if(!Util::checkFileExist(fileAbsolutePath))
    {
        cout << "tranfered file not exist" << endl;
        exit(1);
    }
    fin.open(fileAbsolutePath);
    if(!fin.is_open())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }

    while(!fin.eof())
    {
        fin.getline(buffer, BUFFER);
        string strLine = buffer;
        if ((strLine.find(FAKE) != string::npos) || (strLine.find(STARTENDFLAG) != string::npos))
        {
            flag = true;
            if (strMsg.find(FAKE) != string::npos)
            {
                u->trim(strMsg);
                vStrMsg.push_back(strMsg);
            }
            strMsg = strLine;
        }
        else if (flag && (strLine.find(STARTENDFLAG) == string::npos))
        {
            strMsg = strMsg + "\n" + strLine;
        }
    }
    return vStrMsg;
}



void DataLoader::checkContract()
{
    //ctor;
}
