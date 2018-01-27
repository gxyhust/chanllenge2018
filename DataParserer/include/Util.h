#ifndef UTIL_H
#define UTIL_H
#include<regex>
#include<iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <io.h>
using namespace std;
class Util
{
    public:
        static vector<string> split(string& src, string separate_character);
        static string& trim(string &str_input);
        static string& removeString(string &strInput, string &strWantToRemove);
        static vector<string> getMatchStringVector(string str_src, const string str_pattern, const int int_matchCount);
        static bool checkFileExist(string inputFileName);
        static string getProgramDir();
    protected:

    private:
};

#endif // UTIL_H
