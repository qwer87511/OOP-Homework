#pragma once
#include "Character.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#define CHARACTER_MAX 5
#define MONSTERS_NUM 4
#define LEVEL_MAX 5
using namespace std;

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
        string GetName();
        int GetNum(int, int);
        int ChooseCharacter();
        // UI
        void ShowAllCharacters();
        void ShowAllCharactersName();
        void PrintMenu();
        // create character
        void CreateCharacter();
        // fight
        void CharacterFight();
        // delete character
        void DeleteCharacter();
        // distribute attribute points
        void DistributeAttributes(int, int&, int&, int&);
        // about level up
        bool IsEnoughExp(Character);
        void LevelUp(Character&);
    private:
        // properties
        vector<Character> _charactersList;
        vector<Character> _monstersList;
};