#pragma once
#include "Job.h"

class Character
{
    public:
        // constructor
        Character(string, int, int, int, Job*);
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
        Job* GetJob() const;
        int GetExtraStr() const;
        int GetExtraDex() const;
        int GetExtraCon() const;
        int GetTotalStr() const;
        int GetTotalDex() const;
        int GetTotalCon() const;
        // setter
        void SetStr(int);
        void SetDex(int);
        void SetCon(int);
        void SetJob(Job*);
        void AddExp(int);
        void AddFailFightTimes();
        void SetAttributes(int, int, int);
        void LevelUp();
        // about fight
        bool Fight(Character, string&);
        int ChooseFirstAttack(string, int, string, int, string&);
        void Attack(string, int, string, int&, string&);
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
        Job* _job;
};