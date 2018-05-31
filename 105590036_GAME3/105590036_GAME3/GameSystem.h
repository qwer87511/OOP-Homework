#pragma once
#include "Character.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#define CHARACTER_MAX 5
#define MONSTERS_NUM 4
#define EXP_MAX 1000
#define LEVEL_MAX 5
#define JOB_MAX 20

class GameSystem
{
    public:
        // constructor
        GameSystem();
        // destructor
        ~GameSystem();
        // run
        void Start();
        // control
        void Control(int);
        // filter
        bool NoCharacter();
        // get input
        string GetName(string);
        bool LegalName(string, string);
        int StringToInt(string, int, int);
        int GetNum(int, int);
        int GetNumUntilCorrect(int, int);
        int GetCharacterId();
        // UI
        void ShowAllCharacters();
        void ShowAllCharactersName();
        void ShowAllJobName();
        void PrintMenu();
        // create character
        void CreateCharacter();
        // fight
        void CharacterFight();
        // about level up
        bool IsEnoughExp(const Character&);
        void CharacterLevelUp(Character&);
        // create random monster
        Character CreateRandomMonster(int);
        // delete character
        void DeleteCharacter();
        // distribute attribute points
        void DistributeAttributePoints(int, int&, int&, int&, int, int, int);
        // append job
        void AppendJob();
        string GetJobName();
        bool JobNameIsNotReaped(string);
        void AssignExtraAttributes(int&, int&, int&);
        // about delete job
        void DeleteJob();
        int GetDeleteJobId();
        bool JobIsNotUsed(Job*);
    private:
        // properties
        vector<Character> _charactersList;
        vector<Character> _monstersList;
        vector<Job*> _jobList;
};