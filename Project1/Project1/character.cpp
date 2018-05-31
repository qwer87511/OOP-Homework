#include "Character.h"

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
string Character::GetName()
{
    return this->_name;
}
int Character::GetLevel()
{
    return this->_level;
}
int Character::GetStr()
{
    return this->_str;
}
int Character::GetDex()
{
    return this->_dex;
}
int Character::GetCon()
{
    return this->_con;
}
int Character::GetExp()
{
    return this->_exp;
}
int Character::GetTotalFightTimes()
{
    return this->_totalFightTimes;
}
int Character::GetFailFightTimes()
{
    return this->_failFightTimes;
}
string Character::GetInformation()
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
void Character::AddExp(int value)
{
    this->_exp += value;
}
void Character::AddFailFightTimes()
{
    this->_failFightTimes++;
}
void Attack(string attackerName, int attackerStr, string defenderName, int& defenderHP)
{
    cout << attackerName << "發動攻擊 ! 對" << defenderName << "造成" << attackerStr << "點傷害。" << endl;
    cout << defenderName << "的HP從" << defenderHP << "變為";
    defenderHP -= attackerStr; // 造成傷害

    if (defenderHP < 0) defenderHP = 0; // 血量最小為0

    cout << defenderHP << endl << endl;
}
bool Character::Fight(Character& monster)
{
    this->_totalFightTimes++;
    int playerHP(this->_con * 3);
    int monsterHP(monster._con * 3);
    cout << "系統選擇了「" << monster._name << "」作為敵人。" << endl;
    cout << this->_name << "的DEX為" << this->_dex << "，";
    cout << monster._name << "的DEX為" << monster._dex;

    if (monster._dex > this->_dex)
    {
        cout << "，由" << monster._name << "先進行攻擊。" << endl << endl;
        Attack(monster._name, monster._str, this->_name, playerHP);
    }
    else
        cout << "，由" << this->_name << "先進行攻擊。" << endl << endl;

    while (1)
    {
        if (!playerHP) return false; // 玩家血量歸零，玩家敗

        Attack(this->_name, this->_str, monster._name, monsterHP); //玩家放攻擊位置，怪物為防守位置。

        if (!monsterHP) return true;// 怪物血量歸零，玩家勝

        Attack(monster._name, monster._str, this->_name, playerHP); // 怪物放攻擊位置，玩家為防守位置。
    }
}