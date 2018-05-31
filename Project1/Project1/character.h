#pragma once
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
class Character
{
    public:
        Character(string, int, int, int);
        string GetName();
        int GetLevel();
        int GetStr();
        int GetDex();
        int GetCon();
        int GetExp();
        int GetTotalFightTimes();
        int GetFailFightTimes();
        string GetInformation();
        void AddExp(int);
        void AddFailFightTimes();
        bool Fight(Character&);
    private:
        string _name;
        int _level;
        int _str;
        int _dex;
        int _con;
        int _exp;
        int _totalFightTimes;
        int _failFightTimes;
};