#include "Character.h"

// constructor
Character::Character(string name, int str, int dex, int con)
{
    this->_name = name;
    this->_str = str;
    this->_dex = dex;
    this->_con = con;
    this->_level = 1;
    this->_exp = 0;
    this->_totalFightTimes = 0;
    this->_failFightTimes = 0;
}
// getter
string Character::GetName() const
{
    return this->_name;
}
int Character::GetLevel() const
{
    return this->_level;
}
int Character::GetStr() const
{
    return this->_str;
}
int Character::GetDex() const
{
    return this->_dex;
}
int Character::GetCon() const
{
    return this->_con;
}
int Character::GetExp() const
{
    return this->_exp;
}
int Character::GetTotalFightTimes() const
{
    return this->_totalFightTimes;
}
int Character::GetFailFightTimes() const
{
    return this->_failFightTimes;
}
string Character::GetInformation() const
{
    return "角色名稱 : " + this->_name
           + "\n目前等級 : " + to_string(this->_level)
           + "\n目前經驗值 : " + to_string(this->_exp)
           + "\nSTR : " + to_string(this->_str)
           + "\nDEX : " + to_string(this->_dex)
           + "\nCON : " + to_string(this->_con)
           + "\n總戰鬥場數 : " + to_string(this->_totalFightTimes)
           + "\n戰鬥失敗場數 : " + to_string(this->_failFightTimes) + "\n\n";
}
// setter
void Character::AddExp(int value)
{
    this->_exp += value;
}
void Character::AddFailFightTimes()
{
    this->_failFightTimes++;
}
// fight
int ChooseFirstAttack(string playerName, int playerDex, string monsterName, int monsterDex)
{   // 依DEX選擇先攻方
    cout << playerName << "的DEX為" << playerDex << "，";
    cout << monsterName << "的DEX為" << monsterDex;

    if (playerDex >= monsterDex)
    {
        cout << "，由" << playerName << "先進行攻擊。" << endl << endl;
        return 0; // 玩家先攻回傳偶數
    }
    else
    {
        cout << "，由" << monsterName << "先進行攻擊。" << endl << endl;
        return 1; // 怪物先攻回傳奇數
    }
}
void Attack(string attackerName, int attackerStr, string defenderName, int& defenderHP)
{
    cout << attackerName << "發動攻擊 ! 對" << defenderName << "造成" << attackerStr << "點傷害。" << endl;
    cout << defenderName << "的HP從" << defenderHP << "變為";
    defenderHP -= attackerStr; // 扣血

    if (defenderHP < 0) defenderHP = 0; // min=0

    cout << defenderHP << endl << endl;
}
bool Character::Fight(Character monster)
{
    cout << "系統選擇了「" << monster._name << "」作為敵人。" << endl;
    int playerHP(this->_con * 3);
    int monsterHP(monster._con * 3);
    this->_totalFightTimes++;

    for (int i = ChooseFirstAttack(this->_name, this->_dex, monster._name, monster._dex); true; ++i)
    {   // i的初值以ChooseFirst決定，當i為偶數時，玩家攻擊；當i為奇數時，怪物攻擊。每次攻擊後，i就加1
        if (!(i % 2))
        {   // i為偶數
            Attack(this->_name, this->_str, monster._name, monsterHP); // 玩家放攻擊位置，怪物為防守位置。

            if (!monsterHP) return true; // 怪物血量歸零，玩家勝
        }
        else
        {   // i為奇數
            Attack(monster._name, monster._str, this->_name, playerHP); // 怪物放攻擊位置，玩家為防守位置。

            if (!playerHP) return false; // 玩家血量歸零，玩家敗
        }
    }
}