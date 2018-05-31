#pragma once
#include "Character.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#define CHARACTER_MAX 5
#define MONSTERS_NUM 4
#define LEVEL_MAX 5

class GameSystem
{
    public:
        // constructor
        GameSystem();
        // run
        void Start();
        // filter
        bool NoCharacter();
        bool FullCharacter();
        // get input
        string GetName(string);
        int GetNum(int, int);
        int GetNumWithWhile(int, int);
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
        // create random monster
        Character CreateRandomMonster(int);
        // delete character
        void DeleteCharacter();
        // distribute attribute points
        void DistributeAttributes(Character, int, int&, int&, int&);
        // about level up
        bool IsEnoughExp(Character);
        void CharacterLevelUp(Character&);
        // append job
        void AppendJob();
        string GetJobName();
        bool RepeatedJobName(string);
        void DistributeExtraAttributes(int&, int&, int&);
        // about delete job
        void DeleteJob();
        int GetDeleteJobId();
        bool JobIsInUse(Job&);
    private:
        // properties
        vector<Character> _charactersList;
        vector<Character> _monstersList;
        vector<Job> _jobList;
};