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
// �^��¾�~���A�W��
string Job::GetJobTypeName()
{
    return "�L";
}
// �^��¾�~���A
Job::JobType Job::GetJobType()
{
    return MELEE;
}
// �O�_�J��ĤH¾�~
bool Job::IsCounter(Job* enemyJob)
{
    return false;
}
// �^��¾�~��ĤH���ˮ`�[��
int Job::GetDamage(Character* enemy)
{
    return this->_extraStr;
}