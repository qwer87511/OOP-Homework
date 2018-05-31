// ��u�G 105590036 ���T�� HW7
// class �ŧi�H���A��@ RPG �C��
#include "Character.h"

int GetNum(int max) // ��function�Ω���o����ƿ�J�A�̤p��1�A�̤j��(max)�i�ۦ�]�w //�^��-1��ܿ�J���~
{
    string input;
    getline(cin, input);

    for (int i = 1; i <= max; ++i)
    {
        if (input == to_string(i)) return i;
    }

    return -1; // ��J���~�A�п�J���1~max
}
int GetIns()
{
    while (1)
    {   // UI
        cout << "1. �Ыب���" << endl;
        cout << "2. ����@��" << endl;
        cout << "3. �C�X�Ҧ�����" << endl;
        cout << "4. ���}" << endl;
        int ins = GetNum(4); // ��J1~4

        if (ins != -1) return ins; // �S�����~�~�^��

        cout << "��J���~�A�п�J��� 1 ~ 4" << endl << endl;
    }
}
string GetName()
{
    cout << "�п�J����W�� : ";
    string name;

    while (true)
    {
        getline(cin, name);

        if (name == "\0" || name[0] == ' ') // �Ĥ@�Ӧr�����i���ť�
            cout << "�Ĥ@�Ӧr�����i���ťաA" << endl << "�Э��s��J : ";
        else if (name.find_first_of("\\/:*?\"<>|") != string::npos) // �W�r�����i�a���H�U�r�� \/:*?\"<>|
            cout << "�W�r�����i�a���H�U�r�� \\/:*?\"<>|" << endl << "�Э��s��J : ";
        else
            return name;
    }
}
void AssignAttributes(int& str, int& dex, int& con)
{
    for (int point = 5; point;)
    {   // UI
        cout << endl << "1. �ثeSTR : " << str << endl;
        cout << "2. �ثeDEX : " << dex << endl;
        cout << "3. �ثeCON : " << con << endl;
        cout << "�ثe�Ѿl�I�� : " << point << endl;
        cout << "�п�ܱ��W�[���ݩ� : ";

        switch (GetNum(3)) // ��J�Ʀr1~3
        {
            case 1:
                ++str, --point; // �O�q+1
                break;

            case 2:
                ++dex, --point; // �ӱ�+1
                break;

            case 3:
                ++con, --point; // ���+1
                break;

            default:
                cout << "��J���~�A�п�J��� 1 ~ 3" << endl;
        }
    }
}
void CreateCharacter(vector<Character>& characters)
{
    if (characters.size() == 5) // �W�L�W�� : 5
    {
        cout << "����ƶq�w�F�W��(5)" << endl << endl;
        return;
    }

    string name = GetName(); // �W�r
    int str(1), dex(1), con(1);
    AssignAttributes(str, dex, con); // ���w�ݩ�
    characters.push_back(Character(name, str, dex, con)); // �غc�å[����|
    cout << "�Ыئ��\!" << endl << endl << endl;
    cout << characters.back().GetInformation(); // ��X���
}
void ShowAllCharactersName(vector<Character>& characters)
{   // ��X����W�r
    int num = characters.size();

    for (int i = 0; i < num; ++i)
    {
        cout << endl << i + 1 << ". " << characters[i].GetName();
    }
}
void LetFight(vector<Character>& characters, const Character monsters[])
{
    int num = characters.size();

    if (!num) // �S������
    {
        cout << "�Х��Ыب���" << endl << endl;
        return;
    }

    int characterId;
    int MonsterId = rand() % MONSTERS_NUM; // ��rand()�I�s�ü� �è����HMONSTER_NUM(4)���l��
    ShowAllCharactersName(characters);
    cout << endl << "�п�ܨ���i��@�� : ";

    while ((characterId = GetNum(num)) == -1) // ��ܨ���
    {
        cout << "��J���~�A�п�J���1~" << num << endl;
    }

    if (characters[--characterId].Fight(monsters[MonsterId])) // ��ܤ�����I�sfight�A��J�Ǫ����Ѽ�
    {   // win
        cout << monsters[MonsterId].GetName() << "�ˤU�F ! ��Ӫ��O : " << characters[characterId].GetName() << endl << endl;
        characters[characterId].AddExp(100); // �g��W�[100
    }
    else
    {   // lose
        cout << characters[characterId].GetName() << "�ˤU�F ! ��Ӫ��O : " << monsters[MonsterId].GetName() << endl << endl;
        characters[characterId].AddFailFightTimes(); // ���Ѧ��ƼW�[1
    }
}
void ShowAllCharacters(const vector<Character> characters)
{
    int num = characters.size();

    if (!num)
    {   // �S�����󨤦�
        cout << "�A�S�����󨤦�" << endl << endl;
        return;
    }

    for (int i = 0; i < num; ++i)
    {   // ��ܩҦ�������
        cout << "------------------------------" << endl;
        cout << characters[i].GetInformation();
    }
}

int main()
{
    srand((unsigned int)time(0)); // ���s�ü�
    vector<Character> characters; // �Ҧ������Ƥ��}�C
    const Character MONSTERS[MONSTERS_NUM] = // �Ǫ����
    {
        { "�����L", 1, 6, 1 },
        { "�v�ܩi", 1, 1, 6 },
        { "�~�H", 6, 1, 1 },
        { "�j�C��", 3, 2, 3 }
    };

    while (1)
    {
        switch (GetIns()) // UI
        {
            case 1: // �إߨ���
                CreateCharacter(characters);
                break;

            case 2: // ����@��
                LetFight(characters,MONSTERS);
                break;

            case 3: // ��ܩҦ�����
                ShowAllCharacters(characters);
                break;

            case 4: // EXIT
                system("pause");
                return 0;
        }
    }
}