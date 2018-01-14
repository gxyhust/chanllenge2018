#include "Analyser.h"
#include "DataLoader.h"
#include <iostream>

DataLoader* dataLoder;
Analyser* analyser;
void Analyser::GetSubscribeInfoList(string subParamList,string subModelNameList="")
{
    dataLoder->LoadData();
    cout << "get subscribe info list" << endl;
}

void Analyser::GetFakeProcess(string type,string subModelNameList="")
{
    dataLoder->LoadData();
    cout << "print fake process" << endl;
}



int main()
{
    cout << "Hello world!" << endl;
    analyser->GetSubscribeInfoList("","");
    return 0;
}
