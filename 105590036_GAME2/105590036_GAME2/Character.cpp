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
           + "\n戰鬥失敗場數 : " + to_string(this->_failFightTimes) + "\n";
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
int Character::LevelUp(int increaseStr, int increaseDex, int increaseCon)
{
    this->_str = increaseStr;
    this->_dex = increaseDex;
    this->_con = increaseCon;
    return ++this->_level;
}
// fight
int Character::ChooseFirstAttack(string playerName, int playerDex, string monsterName, int monsterDex, string& fightInfo)
{   // 依DEX選擇先攻方
    fightInfo += playerName + "的DEX為" + to_string(playerDex) + "，";
    fightInfo += monsterName + "的DEX為" + to_string(monsterDex) + "，由";

    if (playerDex >= monsterDex)
    {
        fightInfo += playerName + "先進行攻擊。\n\n";
        return 0; // 玩家先攻回傳偶數
    }
    else
    {
        fightInfo += monsterName + "先進行攻擊。\n\n";
        return 1; // 怪物先攻回傳奇數
    }
}
void Character::Attack(string attackerName, int attackerStr, string defenderName, int& defenderHP, string& fightInfo)
{   // attack once
    fightInfo += attackerName + "發動攻擊 ! 對" + defenderName + "造成" + to_string(attackerStr) + "點傷害。\n";
    fightInfo += defenderName + "的HP從" + to_string(defenderHP) + "變為";
    defenderHP -= attackerStr; // 扣血

    if (defenderHP < 0) defenderHP = 0; // min=0

    fightInfo += to_string(defenderHP) + "\n\n";
}
void Character::AdjustLevel(int level)
{   // 依照玩家等級增加怪物能力
    this->_str += level - 1;
    this->_dex += level - 1;
    this->_con += level - 1;
}
bool Character::Fight(Character monster, string& fightInfo)
{
    this->_totalFightTimes++;
    fightInfo = "系統選擇了「" + monster._name + "」作為敵人。\n";
    monster.AdjustLevel(this->_level);
    int playerHP(this->_con * 3);
    int monsterHP(monster._con * 3);

    for (int i = ChooseFirstAttack(this->_name, this->_dex, monster._name, monster._dex, fightInfo); true; ++i)
    {   // i的初值以ChooseFirst決定，當i為偶數時，玩家攻擊；當i為奇數時，怪物攻擊。每次攻擊後，i就加1
        if (!(i % 2))
        {   // i為偶數
            Attack(this->_name, this->_str, monster._name, monsterHP, fightInfo); // 玩家放攻擊位置，怪物為防守位置。

            if (!monsterHP)
            {   // 怪物血量歸零，玩家勝
                fightInfo += monster._name + "倒下了 ! 獲勝的是 : " + this->_name + "\n";
                return true;
            }
        }
        else
        {   // i為奇數
            Attack(monster._name, monster._str, this->_name, playerHP, fightInfo); // 怪物放攻擊位置，玩家為防守位置。

            if (!playerHP)
            {   // 玩家血量歸零，玩家敗
                fightInfo += this->_name + "倒下了 ! 獲勝的是 : " + monster._name + "\n";
                return false;
            }
        }
    }
}
