#pragma once
#include <string>
using namespace std;

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
        int LevelUp(int, int, int);
        // about fight
        bool Fight(Character, string&);
        int ChooseFirstAttack(string, int, string, int, string&);
        void Attack(string, int, string, int&, string&);
        // for monster
        void AdjustLevel(int);
    private:
        // properties
        string _name;
        int _level;
        int _str;
        int _dex;
        int _con;
        int _exp;
        int _totalFightTimes;
        int _failFightTimes;
};