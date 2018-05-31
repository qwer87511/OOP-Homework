#pragma once
#include <string>
using namespace std;

class Character;
class Job
{
    public:
        // �l¾�~���O
        enum JobType { MELEE, REMOTE, DEFENSE };
        static const int JOB_TYPE_NUM = 3; // �l¾�~�ƶq
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