#pragma once
#include "Job.h"

class DefenseJob : public Job
{
    public:
        // constructor
        DefenseJob(string, int, int, int);

        /* methods */
        int GetDamage(Character*);
        string GetJobTypeName();
        bool IsCounter(Job*);
};