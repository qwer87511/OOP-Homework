#include "Job.h"

Job::Job(string name, int extraStr, int extraDex, int extraCon)
    : _name(name), _extraStr(extraStr), _extraDex(extraDex), _extraCon(extraCon)
{
}
string Job::GetName()
{
    return this->_name;
}
int Job::GetExtraStr()
{
    return this->_extraStr;
}
int Job::GetExtraDex()
{
    return this->_extraDex;
}
int Job::GetExtraCon()
{
    return this->_extraCon;
}
// 回傳職業型態名稱
string Job::GetJobTypeName()
{
    return "無";
}
// 回傳職業型態
Job::JobType Job::GetJobType()
{
    return MELEE;
}
// 是否克制敵人職業
bool Job::IsCounter(Job* enemyJob)
{
    return false;
}
// 回傳職業對敵人的傷害加成
int Job::GetDamage(Character* enemy)
{
    return this->_extraStr;
}