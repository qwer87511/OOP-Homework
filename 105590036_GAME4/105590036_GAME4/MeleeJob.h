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
        Job::JobType GetJobType();
        bool IsCounter(Job*);
};