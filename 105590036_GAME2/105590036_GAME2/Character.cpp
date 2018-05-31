#include "Character.h"

// constructor
Character::Character(string name, int str, int dex, int con)
{
    this->_name = name;
    this->_str = str;
    this->_dex = dex;
    this->_con = con;
    this->_level = 1;
    this->_exp = 0;
    this->_totalFightTimes = 0;
    this->_failFightTimes = 0;
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
string Character::GetInformation() const
{
    return "����W�� : " + this->_name
           + "\n�ثe���� : " + to_string(this->_level)
           + "\n�ثe�g��� : " + to_string(this->_exp)
           + "\nSTR : " + to_string(this->_str)
           + "\nDEX : " + to_string(this->_dex)
           + "\nCON : " + to_string(this->_con)
           + "\n�`�԰����� : " + to_string(this->_totalFightTimes)
           + "\n�԰����ѳ��� : " + to_string(this->_failFightTimes) + "\n";
}
// setter
void Character::AddExp(int value)
{
    this->_exp += value;
}
void Character::AddFailFightTimes()
{
    this->_failFightTimes++;
}
int Character::LevelUp(int increaseStr, int increaseDex, int increaseCon)
{
    this->_str = increaseStr;
    this->_dex = increaseDex;
    this->_con = increaseCon;
    return ++this->_level;
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
void Character::AdjustLevel(int level)
{   // �̷Ӫ��a���żW�[�Ǫ���O
    this->_str += level - 1;
    this->_dex += level - 1;
    this->_con += level - 1;
}
bool Character::Fight(Character monster, string& fightInfo)
{
    this->_totalFightTimes++;
    fightInfo = "�t�ο�ܤF�u" + monster._name + "�v�@���ĤH�C\n";
    monster.AdjustLevel(this->_level);
    int playerHP(this->_con * 3);
    int monsterHP(monster._con * 3);

    for (int i = ChooseFirstAttack(this->_name, this->_dex, monster._name, monster._dex, fightInfo); true; ++i)
    {   // i����ȥHChooseFirst�M�w�A��i�����ƮɡA���a�����F��i���_�ƮɡA�Ǫ������C�C��������Ai�N�[1
        if (!(i % 2))
        {   // i������
            Attack(this->_name, this->_str, monster._name, monsterHP, fightInfo); // ���a�������m�A�Ǫ������u��m�C

            if (!monsterHP)
            {   // �Ǫ���q�k�s�A���a��
                fightInfo += monster._name + "�ˤU�F ! ��Ӫ��O : " + this->_name + "\n";
                return true;
            }
        }
        else
        {   // i���_��
            Attack(monster._name, monster._str, this->_name, playerHP, fightInfo); // �Ǫ��������m�A���a�����u��m�C

            if (!playerHP)
            {   // ���a��q�k�s�A���a��
                fightInfo += this->_name + "�ˤU�F ! ��Ӫ��O : " + monster._name + "\n";
                return false;
            }
        }
    }
}
