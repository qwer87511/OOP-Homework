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
           + "\n�԰����ѳ��� : " + to_string(this->_failFightTimes) + "\n\n";
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
// fight
int ChooseFirstAttack(string playerName, int playerDex, string monsterName, int monsterDex)
{   // ��DEX��ܥ����
    cout << playerName << "��DEX��" << playerDex << "�A";
    cout << monsterName << "��DEX��" << monsterDex;

    if (playerDex >= monsterDex)
    {
        cout << "�A��" << playerName << "���i������C" << endl << endl;
        return 0; // ���a����^�ǰ���
    }
    else
    {
        cout << "�A��" << monsterName << "���i������C" << endl << endl;
        return 1; // �Ǫ�����^�ǩ_��
    }
}
void Attack(string attackerName, int attackerStr, string defenderName, int& defenderHP)
{
    cout << attackerName << "�o�ʧ��� ! ��" << defenderName << "�y��" << attackerStr << "�I�ˮ`�C" << endl;
    cout << defenderName << "��HP�q" << defenderHP << "�ܬ�";
    defenderHP -= attackerStr; // ����

    if (defenderHP < 0) defenderHP = 0; // min=0

    cout << defenderHP << endl << endl;
}
bool Character::Fight(Character monster)
{
    cout << "�t�ο�ܤF�u" << monster._name << "�v�@���ĤH�C" << endl;
    int playerHP(this->_con * 3);
    int monsterHP(monster._con * 3);
    this->_totalFightTimes++;

    for (int i = ChooseFirstAttack(this->_name, this->_dex, monster._name, monster._dex); true; ++i)
    {   // i����ȥHChooseFirst�M�w�A��i�����ƮɡA���a�����F��i���_�ƮɡA�Ǫ������C�C��������Ai�N�[1
        if (!(i % 2))
        {   // i������
            Attack(this->_name, this->_str, monster._name, monsterHP); // ���a�������m�A�Ǫ������u��m�C

            if (!monsterHP) return true; // �Ǫ���q�k�s�A���a��
        }
        else
        {   // i���_��
            Attack(monster._name, monster._str, this->_name, playerHP); // �Ǫ��������m�A���a�����u��m�C

            if (!playerHP) return false; // ���a��q�k�s�A���a��
        }
    }
}