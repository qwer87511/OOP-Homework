#pragma once
#include "Job.h"

class MeleeJob : public Job
{
    public:
        // constructor
        MeleeJob(string, int, int, int);

        /* methods */
        int GetDamage(Character*);
        string GetJobTypeName();
        bool IsCounter(Job*);
};