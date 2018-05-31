#include "Character.h"

// constructor
Character::Character(string name, int str, int dex, int con, Job* job)
    : _name(name)
    , _str(str)
    , _dex(dex)
    , _con(con)
    , _level(1)
    , _exp(0)
    , _totalFightTimes(0)
    , _failFightTimes(0)
    , _job(job)
{
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
Job* Character::GetJob() const
{
    return this->_job;
}
// include job attribute
int Character::GetExtraStr() const
{
    if (this->_job)
    {
        return this->_job->GetExtraStr();
    }

    return 0;
}
int Character::GetExtraDex() const
{
    if (this->_job)
    {
        return this->_job->GetExtraDex();
    }

    return 0;
}
int Character::GetExtraCon() const
{
    if (this->_job)
    {
        return this->_job->GetExtraCon();
    }

    return 0;
}
int Character::GetTotalStr() const
{
    return this->_str + this->_job->GetExtraStr();
}
int Character::GetTotalDex() const
{
    return this->_dex + this->_job->GetExtraDex();
}
int Character::GetTotalCon() const
{
    return this->_con + this->_job->GetExtraCon();
}
string Character::GetInformation() const
{
    string info;
    info = "角色名稱 : " + this->_name;
    info += "\n目前等級 : " + to_string(this->_level);
    info += " / 職業 : " + this->_job->GetName();
    info += "\n目前經驗值 : " + to_string(this->_exp);
    info +=  "\nSTR : " + to_string(this->_str);

    if (int jobStr = this->GetExtraStr()) info += "+" + to_string(jobStr);

    info += "\nDEX : " + to_string(this->_dex);

    if (int jobDex = this->GetExtraDex()) info += "+" + to_string(jobDex);

    info += "\nCON : " + to_string(this->_con);

    if (int jobCon = this->GetExtraCon()) info += "+" + to_string(jobCon);

    info += "\n總戰鬥場數 : " + to_string(this->_totalFightTimes);
    info += "\n戰鬥失敗場數 : " + to_string(this->_failFightTimes) + "\n";
    return info;
}
// setter
void Character::SetStr(int str)
{
    this->_str = str;
}
void Character::SetDex(int dex)
{
    this->_dex = dex;
}
void Character::SetCon(int con)
{
    this->_con = con;
}
void Character::SetJob(Job* job)
{
    this->_job = job;
}
void Character::AddExp(int value)
{
    this->_exp += value;
}
void Character::AddFailFightTimes()
{
    ++this->_failFightTimes;
}
void Character::SetAttritube(int str, int dex, int con)
{
    this->_str = str;
    this->_dex = dex;
    this->_con = con;
}
void Character::LevelUp()
{
    ++this->_level;
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
bool Character::Fight(Character monster, string& fightInfo)
{
    this->_totalFightTimes++;
    fightInfo = "系統選擇了「" + monster._name + "」作為敵人。\n";
    fightInfo += "系統選擇了「" + monster._job->GetName() + "」作為" + monster._name + "的職業。\n";
    int playerStr = this->GetTotalStr();
    int monsterStr = monster.GetTotalStr();
    int playerHP(this->GetTotalCon() * 3);
    int monsterHP(monster.GetTotalCon() * 3);

    for (int i = ChooseFirstAttack(this->_name, this->GetTotalDex(), monster._name, monster.GetTotalDex(), fightInfo); true; ++i)
    {   // i的初值以ChooseFirst決定，當i為偶數時，玩家攻擊；當i為奇數時，怪物攻擊。每次攻擊後，i就加1
        if (!(i % 2))
        {   // i為偶數
            Attack(this->_name, playerStr, monster._name, monsterHP, fightInfo); // 玩家放攻擊位置，怪物為防守位置。

            if (!monsterHP)
            {   // 怪物血量歸零，玩家勝
                fightInfo += monster._name + "倒下了 ! 獲勝的是 : " + this->_name + "\n";
                return true;
            }
        }
        else
        {   // i為奇數
            Attack(monster._name, monsterStr, this->_name, playerHP, fightInfo); // 怪物放攻擊位置，玩家為防守位置。

            if (!playerHP)
            {   // 玩家血量歸零，玩家敗
                fightInfo += this->_name + "倒下了 ! 獲勝的是 : " + monster._name + "\n";
                return false;
            }
        }
    }
}