#pragma once
#include <string>
using namespace std;

class Character;
class Job
{
    public:
        // 子職業類別
        enum JobType { MELEE, REMOTE, DEFENSE };
        static const int JOB_TYPE_NUM = 3; // 子職業數量
        static JobType jobType;

        // constructor
        Job(string, int, int, int);

        /* getter */
        string GetName();
        int GetExtraStr();
        int GetExtraDex();
        int GetExtraCon();

        /* methods */
        JobType GetJobType();
        virtual int GetDamage(Character*);
        virtual string GetJobTypeName();
        virtual bool IsCounter(Job*);
    private:
        /* properties */
        string _name;
        int _extraStr;
        int _extraDex;
        int _extraCon;
};