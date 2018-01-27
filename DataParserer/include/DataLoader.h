#ifndef DATALOADER_H
#define DATALOADER_H
#include <fstream>
#include <iostream>
#include <vector>
#include "Message.h"
#include <string>

#define FAKE "FAKE"
#define RIGHTARROW ">"
#define LEFTARROW "<"
#define STARTENDFLAG "@"
using namespace std;
class DataLoader
{
    public:
        virtual vector<string> loadData(string &input);
        void checkContract();
        string inputFile;

    protected:

    private:

};

class FileLoader:public DataLoader
{
    public:
        vector<string> loadData(string &contractFilePath);
};

#endif // DATALOADER_H
