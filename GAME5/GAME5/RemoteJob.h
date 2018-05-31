#pragma once
#include "Job.h"

class RemoteJob : public Job
{
    public:
        // constructor
        RemoteJob(string, int, int, int);

        /* methods */
        int GetDamage(Character*);
        string GetJobTypeName();
        bool IsCounter(Job*);
};