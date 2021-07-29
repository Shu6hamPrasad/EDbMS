#include <bits/stdc++.h>
#include "admin.cpp"
#include "common.cpp"

using namespace std;
void timeWriter(string UsrName)
{
    ofstream tFile;
    tFile.open("timeStamp.x", fstream::app);
    time_t tt;
    struct tm *ti;
    time(&tt);
    ti = localtime(&tt);
    tFile << asctime(ti) << "\tUSER : " << UsrName << endl
          << endl;
    tFile.close();
}
void timeStamp(string name)
{
    ofstream tFile;
    tFile.open("timeStamp.x", fstream::app);
    if (tFile.is_open())
            timeWriter(name);
    else
    {
        ofstream tFile("timeStamp.x");
        timeWriter(name);
    }
    tFile.close();
}
void user(string name)
{
    timeStamp(name);
    string privileges;
    if (name == "Shubham")
        admin(name);
    else
        common(name);
}