#include "GameSystem.h"

GameSystem::GameSystem()
{   // create monster data
    this->_monstersList =
    {
        { "�����L", 1, 6, 1 },
        { "�v�ܩi", 1, 1, 6 },
        { "�~�H", 6, 1, 1 },
        { "�j�C��", 3, 2, 3 }
    };
}
bool GameSystem::FullCharacter()
{   // check whether character is full
    if (this->_charactersList.size() == CHARACTER_MAX)
    {
        cout << "����ƶq�w�F�W��" << endl << endl;
        return true;
    }
    else
        return false;
}
bool GameSystem::NoCharacter()
{   // check whether character is empty
    if (this->_charactersList.empty())
    {
        cout << "�A�S�����󨤦�" << endl << endl;
        return true;
    }
    else
        return false;
}
void GameSystem::Start()
{   // run
    srand((unsigned)time(0));

    while (1)
    {
        PrintMenu();

        switch (GetNum(1, 5)) // input number 1 to 5
        {
            case 1: // �إߨ���
                CreateCharacter();
                break;

            case 2: // ����@��
                CharacterFight();
                break;

            case 3: // ��ܩҦ�����
                ShowAllCharacters();
                break;

            case 4: // �R������
                DeleteCharacter();
                break;

            case 5: // ���}
                return;

            default:
                cout << "��J���~�A�п�J��� 1 ~ 5 �C" << endl << endl;
        }
    }
}
void GameSystem::PrintMenu()
{   // UI
    cout << "1. �Ыب���" << endl;
    cout << "2. ����@��" << endl;
    cout << "3. �C�X�Ҧ�����" << endl;
    cout << "4. �R������" << endl;
    cout << "5. ���}" << endl;
}
int GameSystem::GetNum(int min, int max)
{   // ��function�Ω���o��ƿ�J�A�̤p��(min)�A�̤j��(max)�ݦۦ�]�w //�^��-1��ܿ�J���~
    string input;
    getline(cin, input);

    for (int i = min; i <= max; ++i)
    {
        if (input == to_string(i)) return i;
    }

    return -1; // ��J���~�A�п�J���1~max
}
string GameSystem::GetName()
{   // ��J�W�r���ˬd
    cout << "�п�J����W�� : ";
    string name;

    while (1)
    {
        getline(cin, name);

        if (name == "\0" || name[0] == ' ') // �Ĥ@�Ӧr�����i���ť�
            cout << "�Ĥ@�Ӧr�����i���ťաA" << endl;
        else if (name.find_first_of("\\/:*?\"<>|") != string::npos) // �W�r�����i�a���H�U�r�� \/:*?\"<>|
            cout << "�W�r�����i�a���H�U�r�� \\/:*?\"<>|" << endl;
        else
            return name;

        cout << "�Э��s��J : ";
    }
}
void GameSystem::CreateCharacter()
{   // create character
    if (FullCharacter()) return; // full

    string name = GetName(); // name
    int str(1), dex(1), con(1);
    DistributeAttributes(5, str, dex, con); // ���w�ݩ�
    this->_charactersList.push_back(Character(name, str, dex, con)); // �غc�å[����|
    cout << "�Ыئ��\!" << endl << endl << endl;
    cout << this->_charactersList.back().GetInformation() << endl; // output character's info
}
void GameSystem::DistributeAttributes(int point, int& str, int& dex, int& con)
{
    while (point)
    {   // UI
        cout << endl << "1. �ثeSTR : " << str << endl;
        cout << "2. �ثeDEX : " << dex << endl;
        cout << "3. �ثeCON : " << con << endl;
        cout << "�ثe�Ѿl�I�� : " << point << endl;
        cout << "�п�ܱ��W�[���ݩ� : ";

        switch (GetNum(1, 3)) // input number 1 to 3
        {
            case 1: // str + 1
                ++str, --point;
                break;

            case 2: // dex + 1
                ++dex, --point;
                break;

            case 3: // con + 1
                ++con, --point;
                break;

            default: // error input
                cout << "��J���~�A�п�J��� 1 ~ 3" << endl;
        }
    }
}
int GameSystem::ChooseCharacter()
{   // print all character name, check input format and return character id, return -1 means back to the menu.
    int num = this->_charactersList.size();
    int characterId;
    ShowAllCharactersName();
    cout << "0. ��^���" << endl;
    cout << "�п�ܨ��� : ";

    while ((characterId = GetNum(0, num)) == -1) // ��ܨ���
    {
        cout << "��J���~�A�п�J���0~" << num << endl;
    }

    return characterId - 1;
}
bool GameSystem::IsEnoughExp(Character character)
{   // check whether reached full exp
    const int fullExp[LEVEL_MAX - 1] = { 100, 300, 600, 1000 }; // AIM_EXP[0] is aim exp of level 1
    return character.GetExp() == fullExp[character.GetLevel() - 1];
}
void GameSystem::LevelUp(Character& character)
{   // level up and distribute attribute points
    cout << "����ɯŤF ~ ��o�s�� 3 �I�I�� �i�H�����e�ݩʤW : " << endl;
    int str = character.GetStr();
    int dex = character.GetDex();
    int con = character.GetCon();
    DistributeAttributes(3, str, dex, con);
    cout << "�t�I���� ! " << character.GetName() << "�ثe�����ŹF��" << character.LevelUp(str, dex, con) << "�C" << endl << endl;
    cout << character.GetInformation() << endl;
}
void GameSystem::CharacterFight()
{   // choose a character and fight random monater
    if (NoCharacter()) return;

    int characterId = ChooseCharacter();

    if (characterId == -1)
    {
        cout << endl << "���i��԰��A��^���C" << endl << endl;
        return;
    }

    Character& character = this->_charactersList[characterId];
    string fightInfo;
    bool win = character.Fight(this->_monstersList[rand() % MONSTERS_NUM], fightInfo);
    cout << endl << fightInfo << endl;

    if (win) // win
    {
        if (character.GetExp() < 1000)
        {
            character.AddExp(100); // exp increased by 100

            if (IsEnoughExp(character))
                LevelUp(character);
        }
    }
    else // lose
        character.AddFailFightTimes(); // add fail fight times
}
void GameSystem::ShowAllCharactersName()
{   // show all character name
    int num = _charactersList.size();
    cout << endl;

    for (int i = 0; i < num; ++i)
    {
        cout << i + 1 << ". " << _charactersList[i].GetName() << endl;
    }
}
void GameSystem::ShowAllCharacters()
{   // show all character info
    if (NoCharacter()) return;

    int num = _charactersList.size();

    for (int i = 0; i < num; ++i)
    {
        cout << "------------------------------" << endl;
        cout << this->_charactersList[i].GetInformation() << endl;
    }
}
void GameSystem::DeleteCharacter()
{   // delete character
    if (NoCharacter()) return;

    int id = ChooseCharacter(); // choose

    if (id == -1)
    {
        cout << endl << "���R������A��^���C" << endl << endl;
        return;
    }

    cout << "�w�R������ : " << this->_charactersList[id].GetName() << "�C" << endl << endl;
    this->_charactersList.erase(this->_charactersList.begin() + id);
}