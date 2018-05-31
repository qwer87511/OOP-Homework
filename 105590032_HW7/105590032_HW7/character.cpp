#include "Character.h"

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
string Character::GetName()
{
    return this->_name;
}
int Character::GetLevel()
{
    return this->_level;
}
int Character::GetStr()
{
    return this->_str;
}
int Character::GetDex()
{
    return this->_dex;
}
int Character::GetCon()
{
    return this->_con;
}
int Character::GetExp()
{
    return this->_exp;
}
int Character::GetTotalFightTimes()
{
    return this->_totalFightTimes;
}
int Character::GetFailFightTimes()
{
    return this->_failFightTimes;
}
string Character::GetInformation()
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
void Character::AddExp(int value)
{
    this->_exp += value;
}
void Character::AddFailFightTimes()
{
    this->_failFightTimes++;
}
void Attack(string attackerName, int attackerStr, string defenderName, int& defenderHP)
{
    cout << attackerName << "�o�ʧ��� ! ��" << defenderName << "�y��" << attackerStr << "�I�ˮ`�C" << endl;
    cout << defenderName << "��HP�q" << defenderHP << "�ܬ�";
    defenderHP -= attackerStr; // �y���ˮ`

    if (defenderHP < 0) defenderHP = 0; // ��q�̤p��0

    cout << defenderHP << endl << endl;
}
bool Character::Fight(Character& monster)
{
    this->_totalFightTimes++;
    int playerHP(this->_con * 3);
    int monsterHP(monster._con * 3);
    cout << "�t�ο�ܤF�u" << monster._name << "�v�@���ĤH�C" << endl;
    cout << this->_name << "��DEX��" << this->_dex << "�A";
    cout << monster._name << "��DEX��" << monster._dex;

    if (monster._dex > this->_dex)
    {
        cout << "�A��" << monster._name << "���i������C" << endl << endl;
        Attack(monster._name, monster._str, this->_name, playerHP);
    }
    else
        cout << "�A��" << this->_name << "���i������C" << endl << endl;

    while (1)
    {
        if (!playerHP) return false; // ���a��q�k�s�A���a��

        Attack(this->_name, this->_str, monster._name, monsterHP); //���a�������m�A�Ǫ������u��m�C

        if (!monsterHP) return true;// �Ǫ���q�k�s�A���a��

        Attack(monster._name, monster._str, this->_name, playerHP); // �Ǫ��������m�A���a�����u��m�C
    }
}