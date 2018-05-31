#include "Character.h"

// constructor
Character::Character(string name, int str, int dex, int con, Job* job)
    : _name(name)
    , _str(str)
    , _dex(dex)
    , _con(con)
    , _level(1)
    , _exp(0)
    , _totalFightTimes(0)
    , _failFightTimes(0)
    , _job(job)
{
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
// include job attribute
int Character::GetExtraStr() const
{
    if (this->_job)
    {
        return this->_job->GetExtraStr();
    }

    return 0;
}
int Character::GetExtraDex() const
{
    if (this->_job)
    {
        return this->_job->GetExtraDex();
    }

    return 0;
}
int Character::GetExtraCon() const
{
    if (this->_job)
    {
        return this->_job->GetExtraCon();
    }

    return 0;
}
int Character::GetTotalStr() const
{
    return this->_str + this->_job->GetExtraStr();
}
int Character::GetTotalDex() const
{
    return this->_dex + this->_job->GetExtraDex();
}
int Character::GetTotalCon() const
{
    return this->_con + this->_job->GetExtraCon();
}
string Character::GetInformation() const
{
    string info;
    info = "����W�� : " + this->_name;
    info += "\n�ثe���� : " + to_string(this->_level);
    info += " / ¾�~ : " + this->_job->GetName();
    info += "\n�ثe�g��� : " + to_string(this->_exp);
    info +=  "\nSTR : " + to_string(this->_str);

    if (int jobStr = this->GetExtraStr()) info += "+" + to_string(jobStr);

    info += "\nDEX : " + to_string(this->_dex);

    if (int jobDex = this->GetExtraDex()) info += "+" + to_string(jobDex);

    info += "\nCON : " + to_string(this->_con);

    if (int jobCon = this->GetExtraCon()) info += "+" + to_string(jobCon);

    info += "\n�`�԰����� : " + to_string(this->_totalFightTimes);
    info += "\n�԰����ѳ��� : " + to_string(this->_failFightTimes) + "\n";
    return info;
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
void Character::AddExp(int value)
{
    this->_exp += value;
}
void Character::AddFailFightTimes()
{
    ++this->_failFightTimes;
}
void Character::SetAttritube(int str, int dex, int con)
{
    this->_str = str;
    this->_dex = dex;
    this->_con = con;
}
void Character::LevelUp()
{
    ++this->_level;
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
void Character::Attack(string attackerName, int attackerStr, string defenderName, int& defenderHP, string& fightInfo)
{   // attack once
    fightInfo += attackerName + "�o�ʧ��� ! ��" + defenderName + "�y��" + to_string(attackerStr) + "�I�ˮ`�C\n";
    fightInfo += defenderName + "��HP�q" + to_string(defenderHP) + "�ܬ�";
    defenderHP -= attackerStr; // ����

    if (defenderHP < 0) defenderHP = 0; // min=0

    fightInfo += to_string(defenderHP) + "\n\n";
}
bool Character::Fight(Character monster, string& fightInfo)
{
    this->_totalFightTimes++;
    fightInfo = "�t�ο�ܤF�u" + monster._name + "�v�@���ĤH�C\n";
    fightInfo += "�t�ο�ܤF�u" + monster._job->GetName() + "�v�@��" + monster._name + "��¾�~�C\n";
    int playerStr = this->GetTotalStr();
    int monsterStr = monster.GetTotalStr();
    int playerHP(this->GetTotalCon() * 3);
    int monsterHP(monster.GetTotalCon() * 3);

    for (int i = ChooseFirstAttack(this->_name, this->GetTotalDex(), monster._name, monster.GetTotalDex(), fightInfo); true; ++i)
    {   // i����ȥHChooseFirst�M�w�A��i�����ƮɡA���a�����F��i���_�ƮɡA�Ǫ������C�C��������Ai�N�[1
        if (!(i % 2))
        {   // i������
            Attack(this->_name, playerStr, monster._name, monsterHP, fightInfo); // ���a�������m�A�Ǫ������u��m�C

            if (!monsterHP)
            {   // �Ǫ���q�k�s�A���a��
                fightInfo += monster._name + "�ˤU�F ! ��Ӫ��O : " + this->_name + "\n";
                return true;
            }
        }
        else
        {   // i���_��
            Attack(monster._name, monsterStr, this->_name, playerHP, fightInfo); // �Ǫ��������m�A���a�����u��m�C

            if (!playerHP)
            {   // ���a��q�k�s�A���a��
                fightInfo += this->_name + "�ˤU�F ! ��Ӫ��O : " + monster._name + "\n";
                return false;
            }
        }
    }
}