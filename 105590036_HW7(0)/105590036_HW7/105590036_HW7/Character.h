#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
#define MONSTERS_NUM 4

class Character
{
    public:
        // constructor
        Character(string, int, int, int);
        // getter
        string GetName() const;
        int GetLevel() const;
        int GetStr() const;
        int GetDex() const;
        int GetCon() const;
        int GetExp() const;
        int GetTotalFightTimes() const;
        int GetFailFightTimes() const;
        string GetInformation() const;
        // setter
        void AddExp(int);
        void AddFailFightTimes();
        // fight
        bool Fight(Character);
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