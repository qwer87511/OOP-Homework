#pragma once
#include "Job.h"

class Character
{
    public:
        // constructor
        Character(string, int, int, int, Job*);

        /* constants */
        static const int EXP_MAX = 1000; // 經驗上限
        static const int LEVEL_MAX = 5; // 等級上限

        /* setter */
        void SetStr(int);
        void SetDex(int);
        void SetCon(int);
        void SetJob(Job*);
        void AddExp(int);
        void SetFullExp(int);
        void AddFailFightTimes();
        void SetAttributes(int, int, int);
        // level up
        void LevelUp();

        /* getter */
        string GetName() const;
        int GetLevel() const;
        int GetStr() const;
        int GetDex() const;
        int GetCon() const;
        int GetExp() const;
        bool IsFullExp() const;
        int GetTotalFightTimes() const;
        int GetFailFightTimes() const;
        string GetInformation() const;
        Job* GetJob() const;
        int GetExtraStr() const;
        int GetExtraDex() const;
        int GetExtraCon() const;
        int GetDamage(Character*) const;
        int GetTotalDex() const;
        int GetTotalCon() const;
        bool IsFullLevel() const;

        // about fight
        bool Fight(Character, string&);
    private:
        /* properties */
        string _name;
        int _level;
        int _str;
        int _dex;
        int _con;
        int _exp;
        int _fullExp;
        int _totalFightTimes;
        int _failFightTimes;
        Job* _job;

        /* methods */
        // fight 方法，由 fight() 呼叫。
        int ChooseFirstAttack(string, int, string, int, string&);
        void Attack(string, int, string, int&, bool, string&);
        // 設定升級經驗值，由 constructor 和 LevelUp() 呼叫
        void ResetFullExp();
};