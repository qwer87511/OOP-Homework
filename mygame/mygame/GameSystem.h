#pragma once
#include "Character.h"
#include "MeleeJob.h"
#include "RemoteJob.h"
#include "DefenseJob.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class GameSystem
{
    public:
        // constructor
        GameSystem();
        // destructor
        ~GameSystem();
        // run
        void Start();
    private:
        /* properties */
        vector<Character> _charactersList;
        vector<Character> _monstersList;
        vector<Job*> _jobList;

        /* constants */
        static const int CHARACTER_MAX = 5; // 角色數量上限
        static const int MONSTERS_NUM = 4; // 怪物數量
        static const int JOB_MAX = 20; // 職業數量上限

        /* methods */
        // control
        void Control(int);
        // get input
        string GetName();
        int StringToInt(string, int, int);
        int GetNum(int, int);
        int GetNumUntilCorrect(int, int);
        // UI
        void ShowAllCharacters();
        void ShowAllCharactersName();
        void ShowAllJobName();
        void PrintMenu();
        void ShowAllJobTypeName();
        void ShowJobName(const vector<Job*>&);
        // create character
        void CreateCharacter();
        void PushSpecificJobList(vector<Job*>&, Job::JobType);
        // fight
        void CharacterFight();
        // level up
        void CharacterGetExpAndLevel(Character&);
        // create random monster
        Character CreateRandomMonster(int);
        // delete character
        void DeleteCharacter();
        // distribute attribute points
        void DistributeAttributePoints(int, int&, int&, int&, int, int, int);
        // append job
        void AppendJob();
        string GetJobName();
        bool JobNameIsReaped(string);
        void AssignExtraAttributes(int&, int&, int&);
        Job* CreateSpecificJob(string, int, int, int, Job::JobType);
        // about delete job
        void DeleteJob();
        int GetDeleteJobIndex();
        bool JobIsInUse(Job*);
        bool IsTheLastJobOfTheJobType(Job*);
};