#include "MeleeJob.h"
#include "RemoteJob.h"
#include "Character.h"

MeleeJob::MeleeJob(string name, int extraStr, int extraDex, int extraCon) : Job(name, extraStr, extraDex, extraCon)
{
}
// 回傳職業型態名稱
string MeleeJob::GetJobTypeName()
{
    return "近距離攻擊系";
}
// 回傳職業型態
Job::JobType MeleeJob::GetJobType()
{
    return MELEE;
}
// 是否克制敵人職業
bool MeleeJob::IsCounter(Job* enemyJob)
{
    return dynamic_cast<RemoteJob*>(enemyJob) != nullptr;
}
// 回傳職業對敵人的傷害加成
int MeleeJob::GetDamage(Character* enemy)
{
    if (IsCounter(enemy->GetJob()))
        return this->GetExtraStr() + 2;
    else
        return this->GetExtraStr();
}