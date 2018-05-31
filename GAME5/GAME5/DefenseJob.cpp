#include "DefenseJob.h"
#include "MeleeJob.h"
#include "Character.h"

DefenseJob::DefenseJob(string name, int extraStr, int extraDex, int extraCon) : Job(name,extraStr, extraDex,extraCon)
{
    Job::jobType = DEFENSE;
}
// 回傳職業型態名稱
string DefenseJob::GetJobTypeName()
{
    return "防禦系";
}
// 是否克制敵人職業
bool DefenseJob::IsCounter(Job* enemyJob)
{
    return dynamic_cast<MeleeJob*>(enemyJob) != nullptr;
}
// 回傳職業對敵人的傷害加成
int DefenseJob::GetDamage(Character* enemy)
{
    if (IsCounter(enemy->GetJob()))
        return this->GetExtraStr() + 2;
    else
        return this->GetExtraStr();
}