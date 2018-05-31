#include "Character.h"

// constructor
Character::Character(string name, int str, int dex, int con, Job* job)
    : _name(name), _str(str), _dex(dex), _con(con), _level(1), _exp(0), _totalFightTimes(0), _failFightTimes(0), _job(job)
{
    ResetFullExp(); // 設定升級經驗值
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
void Character::AddExp(int increaseExp)
{
    this->_exp += increaseExp;
}
void Character::SetFullExp(int fullExp)
{
    this->_fullExp = fullExp;
}
void Character::AddFailFightTimes()
{
    ++this->_failFightTimes;
}
void Character::SetAttributes(int str, int dex, int con)
{
    this->_str = str;
    this->_dex = dex;
    this->_con = con;
}
void Character::LevelUp()
{
    ++this->_level;
    ResetFullExp(); // 設定升級經驗值
}
// 設定升級經驗值
void Character::ResetFullExp()
{
    const int FULL_EXP_OF_LEVEL[LEVEL_MAX] = { 100, 300, 600, 1000, 1000 };
    this->_fullExp = FULL_EXP_OF_LEVEL[this->_level - 1];
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
// 是否達升級經驗
bool Character::IsFullExp() const
{
    return this->_exp == this->_fullExp;
}
// 是否滿級
bool Character::IsFullLevel() const
{
    return this->_level == LEVEL_MAX;
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
int Character::GetExtraStr() const
{
    return this->_job->GetExtraStr();
}
int Character::GetExtraDex() const
{
    return this->_job->GetExtraDex();
}
int Character::GetExtraCon() const
{
    return this->_job->GetExtraCon();
}
int Character::GetDamage(Character* character) const
{
    return this->_str + this->_job->GetDamage(character);
}
int Character::GetTotalDex() const
{
    return this->_dex + this->GetExtraDex();
}
int Character::GetTotalCon() const
{
    return this->_con + this->GetExtraCon();
}
string Character::GetInformation() const
{
    string info;
    info = "角色名稱 : " + this->_name;
    info += "\n目前等級 : " + to_string(this->_level);
    info += " / 職業 : " + this->_job->GetName();
    info += " (所屬 : " + this->GetJob()->GetJobTypeName() + ")";
    info += "\n目前經驗值 : " + to_string(this->_exp);
    info +=  "\nSTR : " + to_string(this->_str);

    if (int jobStr = this->GetExtraStr()) info += "+" + to_string(jobStr); // 職業加成

    info += "\nDEX : " + to_string(this->_dex);

    if (int jobDex = this->GetExtraDex()) info += "+" + to_string(jobDex);

    info += "\nCON : " + to_string(this->_con);

    if (int jobCon = this->GetExtraCon()) info += "+" + to_string(jobCon);

    info += "\n總戰鬥場數 : " + to_string(this->_totalFightTimes);
    info += "\n戰鬥失敗場數 : " + to_string(this->_failFightTimes) + "\n";
    return info;
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
void Character::Attack(string attackerName, int attackerStr, string defenderName, int& defenderHP, bool counter, string& fightInfo)
{   // 攻擊一次
    fightInfo += attackerName + "發動攻擊 ! 對" + defenderName + "造成" + to_string(attackerStr) + "點傷害。";

    if (counter) fightInfo += "  *屬性相剋 !";

    fightInfo += "\n" + defenderName + "的HP從" + to_string(defenderHP) + "變為";
    defenderHP -= attackerStr; // 扣血

    if (defenderHP < 0) defenderHP = 0; // min=0

    fightInfo += to_string(defenderHP) + "\n\n";
}
bool Character::Fight(Character monster, string& fightInfo)
{
    this->_totalFightTimes++;
    fightInfo = "系統選擇了「" + monster._name + "」作為敵人。\n";
    fightInfo += "系統選擇了「" + monster._job->GetName() + "」作為" + monster._name + "的職業。\n";
    // setup
    int playerDamage = this->GetDamage(&monster);
    int monsterDamage = monster.GetDamage(this);
    int playerHP(this->GetTotalCon() * 3);
    int monsterHP(monster.GetTotalCon() * 3);
    bool playerCounterMonster = this->_job->IsCounter(monster._job);
    bool monsterCounterPlayer = monster._job->IsCounter(this->_job);

    // fight
    for (int i = ChooseFirstAttack(this->_name, this->GetTotalDex(), monster._name, monster.GetTotalDex(), fightInfo); true; ++i)
    {   // i的初值以ChooseFirst決定，當i為偶數時，玩家攻擊；當i為奇數時，怪物攻擊。每次攻擊後 i + 1 。
        if (!(i % 2))
        {   // i 為偶數，玩家放攻擊位置，怪物為防守位置。
            Attack(this->_name, playerDamage, monster._name, monsterHP, playerCounterMonster, fightInfo);

            if (!monsterHP)
            {   // 怪物血量歸零，玩家勝
                fightInfo += monster._name + "倒下了 ! 獲勝的是 : " + this->_name + "\n";
                return true;
            }
        }
        else
        {   // i 為奇數，怪物放攻擊位置，玩家為防守位置。
            Attack(monster._name, monsterDamage, this->_name, playerHP, monsterCounterPlayer, fightInfo);

            if (!playerHP)
            {   // 玩家血量歸零，玩家敗
                fightInfo += this->_name + "倒下了 ! 獲勝的是 : " + monster._name + "\n";
                return false;
            }
        }
    }
}