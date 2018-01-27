#include "Util.h"

using namespace std;
vector<string> Util::split(string& src, string separate_character)
{
    vector<string> strs;
    int separate_characterLen = separate_character.size();
    int lastPosition = 0, index = -1;
    while (-1 != (index = src.find(separate_character, lastPosition)))
    {
        strs.push_back(src.substr(lastPosition, index - lastPosition));
        lastPosition = index + separate_characterLen;
    }
    string lastString = src.substr(lastPosition);
    if (!lastString.empty())
    {
        strs.push_back(lastString);
    }
    return strs;
}

string& Util::trim(string &s)
{
    int index = 0;
    if( !s.empty())
    {
       while( (index = s.find(' ',index)) != string::npos)
       {
           s.erase(index,1);
       }
    }
}

string& Util::removeString(string &strInput, string &strWantToRemove)
{
    string::size_type  pos = 0;
    if( !strInput.empty())
    {
        while ((pos = strInput.find_first_of(strWantToRemove, pos)) != string::npos)
        {
           strInput.erase(pos, 1);;
        }
    }
    return strInput;
}

vector<string> Util::getMatchStringVector(string str_src, const string str_pattern, int int_matchCount)
{
    vector<string> v_matchResult;
    regex p(str_pattern);
    sregex_iterator pos(str_src.begin(),str_src.end(),p);
    sregex_iterator end;
    for (int i=1;i<=int_matchCount;i++)
    {
       v_matchResult.push_back(pos->str(i));
    }
    return v_matchResult;
}

bool Util::checkFileExist(string inputFileName)
{
    if(inputFileName=="")
    {
        cout<<"NO INPUT FILE"<<endl;
        return false;
    }
    if((_access(inputFileName.c_str(),F_OK)) == -1)
    {
        cout<<"INPUT FILE NOT EXIST"<<endl;
        return false;
    }
    return true;
}

string Util::getProgramDir()
{
    char exeFullPath[MAX_PATH];
    string strPath = "";
    string path;
    char *p;

    GetModuleFileName(NULL,exeFullPath,MAX_PATH);
    strPath=(string)exeFullPath;
    int pos = strPath.find_last_of('\\', strPath.length());
    return strPath.substr(0, pos);
}
