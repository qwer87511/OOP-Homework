#include "RemoteJob.h"
#include "DefenseJob.h"
#include "Character.h"

RemoteJob::RemoteJob(string name, int extraStr, int extraDex, int extraCon) : Job(name, extraStr, extraDex, extraCon)
{
}
// �^��¾�~���A�W��
string RemoteJob::GetJobTypeName()
{
    return "���Z�������t";
}
// �^��¾�~���A
Job::JobType RemoteJob::GetJobType()
{
    return REMOTE;
}
// �O�_�J��ĤH¾�~
bool RemoteJob::IsCounter(Job* enemyJob)
{
    return dynamic_cast<DefenseJob*>(enemyJob) != nullptr;
}
// �^��¾�~��ĤH���ˮ`�[��
int RemoteJob::GetDamage(Character* enemy)
{
    if (IsCounter(enemy->GetJob()))
        return this->GetExtraStr() + 2;
    else
        return this->GetExtraStr();
}