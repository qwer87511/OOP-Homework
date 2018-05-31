#include "RemoteJob.h"
#include "DefenseJob.h"
#include "Character.h"

RemoteJob::RemoteJob(string name, int extraStr, int extraDex, int extraCon) : Job(name, extraStr, extraDex, extraCon)
{
    JobType jobType = REMOTE;
}
// 回傳職業型態名稱
string RemoteJob::GetJobTypeName()
{
    return "遠距離攻擊系";
}
// 是否克制敵人職業
bool RemoteJob::IsCounter(Job* enemyJob)
{
    return dynamic_cast<DefenseJob*>(enemyJob) != nullptr;
}
// 回傳職業對敵人的傷害加成
int RemoteJob::GetDamage(Character* enemy)
{
    if (IsCounter(enemy->GetJob()))
        return this->GetExtraStr() + 2;
    else
        return this->GetExtraStr();
}