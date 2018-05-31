// ��u�G 105590036 �i���� HW7
// RPG �C��
#include "Character.h"
bool IsCorrectName(string name)
{
    if (name == "\0" || name[0] == ' ') cout << "���i���ť�" << endl;
    else if (name.find_first_of("\\/:*?\"<>|") != string::npos) cout << "�t�����X�k�Ÿ�" << endl;
    else return true;

    return false;
}
string GetName()
{
    cout << "�п�J����W�� : ";
    string name;

    while (1)
    {
        getline(cin, name);

        if (IsCorrectName(name))return name;
        else cout << "�Э��s��J : ";
    }
}

int InputNumber(int max)
{
    string input;
    getline(cin, input);

    if (input[0] - '0' >= 0 && input[0] - '0' <= max && input[1] == '\0')
        return input[0] - '0';

    return -1;
}

void Assign(int& str, int& dex, int& con)
{
    for (int point = 5; point;)
    {
        cout << endl << "1. �ثeSTR : " << str << endl;
        cout << "2. �ثeDEX : " << dex << endl;
        cout << "3. �ثeCON : " << con << endl;
        cout << "�ثe�Ѿl�I�� : " << point << endl;
        cout << "�п�ܱ��W�[���ݩ� : ";
        int choose = InputNumber(3);

        if (choose == 1)
        {
            ++str;
            --point;
        }
        else if (choose == 2)
        {
            ++str;
            --point;
        }
        else if (choose == 3)
        {
            ++str;
            --point;
        }
        else
            cout << "��J���~�A�п�J 1 ~ 3" << endl;
    }
}

int GetAction()
{
    while (1)
    {
        cout << "1. �Ыب���" << endl;
        cout << "2. ����@��" << endl;
        cout << "3. �C�X�Ҧ�����" << endl;
        cout << "4. ���}" << endl;
        int ins = InputNumber(4);

        if (ins != -1) return ins;

        cout << "��J���~�A�п�J1~4" << endl << endl;
    }
}

void Create(vector<Character>& characters)
{
    string name = GetName();
    int str(1), dex(1), con(1);
    Assign(str, dex, con);
    Character newCharacter(name, str, dex, con);
    characters.push_back(newCharacter);
    cout << newCharacter.GetInformation();
    cout << "�Ыئ��\!" << endl << endl;
}

void ShowAllCharactersName(vector<Character> characters)
{
    const int size = characters.size();

    for (int i = 0; i < size; i++)
    {
        cout << endl << i + 1 << ". " << characters[i].GetName();
    }
}

void LetFight(vector<Character>& characters, Character monsters[])
{
    int cap = characters.size();

    if (cap == 0)
    {
        cout << "�Х��Ыب���" << endl << endl;
        return;
    }

    ShowAllCharactersName(characters);
    int who;
    int MonsterId = rand() % 4;
    cout << endl << "�п�ܨ���i��@�� : ";

    while ((who = InputNumber(cap) - 1) == -2) cout << "��J���~" << who << endl;

    if (characters[who].Fight(monsters[MonsterId]))
    {
        cout << monsters[MonsterId].GetName() << "�ˤU�F ! ��Ӫ��O : " << characters[who].GetName() << endl << endl;
        characters[who].AddExp(100);
    }
    else
    {
        cout << characters[who].GetName() << "�ˤU�F ! ��Ӫ��O : " << monsters[MonsterId].GetName() << endl << endl;
        characters[who].AddFailFightTimes();
    }
}

int main()
{
    vector<Character> characters;
    Character monsters[4] =
    {
        { "�����L", 1, 6, 1 },
        { "�v�ܩi", 1, 1, 6 },
        { "�~�H", 6, 1, 1 },
        { "�j�C��", 3, 2, 3 }
    };
    srand((unsigned int)time(0));

    while (1)
    {
        int ins = GetAction();

        if (ins == 1)
        {
            if (characters.size() == 5)
                cout << "����ƶq�w�F�W��" << endl << endl;
            else
                Create(characters);
        }
        else if (ins == 2)
            LetFight(characters, monsters);
        else if (ins == 3)
        {
            cout << endl;
            int amount = characters.size();

            if (amount == 0)
                cout << "�A�S���Ыب���" << endl;
            else
            {
                for (int i = 0; i < amount; i++)
                {
                    cout << characters[i].GetInformation();
                }
            }
        }
        else if (ins == 4)
            break;
    }

    system("PAUSE");
    return 0;
}