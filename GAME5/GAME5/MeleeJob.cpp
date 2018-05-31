#include "MeleeJob.h"
#include "RemoteJob.h"
#include "Character.h"

MeleeJob::MeleeJob(string name, int extraStr, int extraDex, int extraCon) : Job(name, extraStr, extraDex, extraCon)
{
    JobType jobType = MELEE;
}
// �^��¾�~���A�W��
string MeleeJob::GetJobTypeName()
{
    return "��Z�������t";
}
// �O�_�J��ĤH¾�~
bool MeleeJob::IsCounter(Job* enemyJob)
{
    return dynamic_cast<RemoteJob*>(enemyJob) != nullptr;
}
// �^��¾�~��ĤH���ˮ`�[��
int MeleeJob::GetDamage(Character* enemy)
{
    if (IsCounter(enemy->GetJob()))
        return this->GetExtraStr() + 2;
    else
        return this->GetExtraStr();
}