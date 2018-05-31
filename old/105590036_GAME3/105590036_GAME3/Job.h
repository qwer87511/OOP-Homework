#pragma once
#include <string>
using namespace std;

class Job
{
    public:
        // constructor
        Job(string, int, int, int);
        // getter
        string GetName();
        int GetExtraStr();
        int GetExtraDex();
        int GetExtraCon();
    private:
        // properties
        string _name;
        int _extraStr;
        int _extraDex;
        int _extraCon;
};