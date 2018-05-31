#include "DefenseJob.h"
#include "MeleeJob.h"
#include "Character.h"

DefenseJob::DefenseJob(string name, int extraStr, int extraDex, int extraCon) : Job(name,extraStr, extraDex,extraCon)
{
    Job::jobType = DEFENSE;
}
// �^��¾�~���A�W��
string DefenseJob::GetJobTypeName()
{
    return "���m�t";
}
// �O�_�J��ĤH¾�~
bool DefenseJob::IsCounter(Job* enemyJob)
{
    return dynamic_cast<MeleeJob*>(enemyJob) != nullptr;
}
// �^��¾�~��ĤH���ˮ`�[��
int DefenseJob::GetDamage(Character* enemy)
{
    if (IsCounter(enemy->GetJob()))
        return this->GetExtraStr() + 2;
    else
        return this->GetExtraStr();
}