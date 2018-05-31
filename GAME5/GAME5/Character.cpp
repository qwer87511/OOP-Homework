#include "Character.h"

// constructor
Character::Character(string name, int str, int dex, int con, Job* job)
    : _name(name), _str(str), _dex(dex), _con(con), _level(1), _exp(0), _totalFightTimes(0), _failFightTimes(0), _job(job)
{
    ResetFullExp(); // �]�w�ɯŸg���
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
    ResetFullExp(); // �]�w�ɯŸg���
}
// �]�w�ɯŸg���
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
// �O�_�F�ɯŸg��
bool Character::IsFullExp() const
{
    return this->_exp == this->_fullExp;
}
// �O�_����
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
    info = "����W�� : " + this->_name;
    info += "\n�ثe���� : " + to_string(this->_level);
    info += " / ¾�~ : " + this->_job->GetName();
    info += " (���� : " + this->GetJob()->GetJobTypeName() + ")";
    info += "\n�ثe�g��� : " + to_string(this->_exp);
    info +=  "\nSTR : " + to_string(this->_str);

    if (int jobStr = this->GetExtraStr()) info += "+" + to_string(jobStr); // ¾�~�[��

    info += "\nDEX : " + to_string(this->_dex);

    if (int jobDex = this->GetExtraDex()) info += "+" + to_string(jobDex);

    info += "\nCON : " + to_string(this->_con);

    if (int jobCon = this->GetExtraCon()) info += "+" + to_string(jobCon);

    info += "\n�`�԰����� : " + to_string(this->_totalFightTimes);
    info += "\n�԰����ѳ��� : " + to_string(this->_failFightTimes) + "\n";
    return info;
}
// fight
int Character::ChooseFirstAttack(string playerName, int playerDex, string monsterName, int monsterDex, string& fightInfo)
{   // ��DEX��ܥ����
    fightInfo += playerName + "��DEX��" + to_string(playerDex) + "�A";
    fightInfo += monsterName + "��DEX��" + to_string(monsterDex) + "�A��";

    if (playerDex >= monsterDex)
    {
        fightInfo += playerName + "���i������C\n\n";
        return 0; // ���a����^�ǰ���
    }
    else
    {
        fightInfo += monsterName + "���i������C\n\n";
        return 1; // �Ǫ�����^�ǩ_��
    }
}
void Character::Attack(string attackerName, int attackerStr, string defenderName, int& defenderHP, bool counter, string& fightInfo)
{   // �����@��
    fightInfo += attackerName + "�o�ʧ��� ! ��" + defenderName + "�y��" + to_string(attackerStr) + "�I�ˮ`�C";

    if (counter) fightInfo += "  *�ݩʬ۫g !";

    fightInfo += "\n" + defenderName + "��HP�q" + to_string(defenderHP) + "�ܬ�";
    defenderHP -= attackerStr; // ����

    if (defenderHP < 0) defenderHP = 0; // min=0

    fightInfo += to_string(defenderHP) + "\n\n";
}
bool Character::Fight(Character monster, string& fightInfo)
{
    this->_totalFightTimes++;
    fightInfo = "�t�ο�ܤF�u" + monster._name + "�v�@���ĤH�C\n";
    fightInfo += "�t�ο�ܤF�u" + monster._job->GetName() + "�v�@��" + monster._name + "��¾�~�C\n";
    // setup
    int playerDamage = this->GetDamage(&monster);
    int monsterDamage = monster.GetDamage(this);
    int playerHP(this->GetTotalCon() * 3);
    int monsterHP(monster.GetTotalCon() * 3);
    bool playerCounterMonster = this->_job->IsCounter(monster._job);
    bool monsterCounterPlayer = monster._job->IsCounter(this->_job);

    // fight
    for (int i = ChooseFirstAttack(this->_name, this->GetTotalDex(), monster._name, monster.GetTotalDex(), fightInfo); true; ++i)
    {   // i����ȥHChooseFirst�M�w�A��i�����ƮɡA���a�����F��i���_�ƮɡA�Ǫ������C�C�������� i + 1 �C
        if (!(i % 2))
        {   // i �����ơA���a�������m�A�Ǫ������u��m�C
            Attack(this->_name, playerDamage, monster._name, monsterHP, playerCounterMonster, fightInfo);

            if (!monsterHP)
            {   // �Ǫ���q�k�s�A���a��
                fightInfo += monster._name + "�ˤU�F ! ��Ӫ��O : " + this->_name + "\n";
                return true;
            }
        }
        else
        {   // i ���_�ơA�Ǫ��������m�A���a�����u��m�C
            Attack(monster._name, monsterDamage, this->_name, playerHP, monsterCounterPlayer, fightInfo);

            if (!playerHP)
            {   // ���a��q�k�s�A���a��
                fightInfo += this->_name + "�ˤU�F ! ��Ӫ��O : " + monster._name + "\n";
                return false;
            }
        }
    }
}