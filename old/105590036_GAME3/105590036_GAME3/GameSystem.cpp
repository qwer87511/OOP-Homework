#include "GameSystem.h"

GameSystem::GameSystem()
{   // create monster data and job data
    this->_monstersList =
    {
        { "�����L", 1, 6, 1, NULL },
        { "�v�ܩi", 1, 1, 6, NULL },
        { "�~�H", 6, 1, 1, NULL },
        { "�j�C��", 3, 2, 3, NULL }
    };
    this->_jobList =
    {
        { "�s��", 2, 0, 0 },
        { "�y�H", 0, 2, 0 },
        { "�Ԥh", 0, 0, 2 }
    };
}
void GameSystem::Start()
{   // run
    srand((unsigned)time(0));

    while (1)
    {
        PrintMenu();

        switch (GetNum(1, 7)) // input number 1 to 5
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

            case 5: // �s�W¾�~
                AppendJob();
                break;

            case 6:
                DeleteJob();
                break;

            case 7: // ���}
                return;

            default:
                cout << "��J���~�A�п�J��� 1 ~ 7 �C" << endl << endl;
        }
    }
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
void GameSystem::PrintMenu()
{   // UI
    cout << "1. �Ыب���" << endl;
    cout << "2. ����@��" << endl;
    cout << "3. �C�X�Ҧ�����" << endl;
    cout << "4. �R������" << endl;
    cout << "5. �s�W¾�~" << endl;
    cout << "6. �R��¾�~" << endl;
    cout << "7. ���}" << endl;
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
int GameSystem::GetNumWithWhile(int min, int max)
{   // ��function�Ω���o��ƿ�J�A�̤p��(min)�A�̤j��(max)�ݦۦ�]�w //�ݿ�J�쥿�T�Ȭ���
    while (1)
    {
        int num = GetNum(min, max);

        if (num != -1) return num;

        cout << "��J���~�A�п�J��� " << min << " ~ " << max << "�C�Э��s��J : ";
    }
}
string GameSystem::GetName(string illegalCharacters)
{   // ��J�W�r���ˬd�O�_�]�t�D�k�r��
    string name;

    while (1)
    {
        getline(cin, name);

        if (name[0] == '\0' || name[0] == ' ') // ���i���ťն}�Y
            cout << "�Ĥ@�Ӧr�����i���ťաA";
        else if (name.size() > 32)
            cout << "���׳̦h32�줸�A";
        else if (name.find_first_of(illegalCharacters) != string::npos) // ���i�t���D�k�r��
            cout << "�W�r�����i�a���D�k�r���A";
        else
            return name;

        cout << "�Э��s��J : ";
    }
}
void GameSystem::CreateCharacter()
{   // create character
    if (FullCharacter()) return; // full

    // ���w�W�r
    cout << endl << "�п�J����W�� : ";
    string name = GetName("\\/:*?\"<>|"); // name
    Character newCharacter(name, 1, 1, 1, NULL);
    // ���w�ݩ�
    int str(1), dex(1), con(1);
    DistributeAttributes(newCharacter, 5, str, dex, con);
    newCharacter.SetAttritube(str, dex, con);
    // ���w¾�~
    ShowAllJobName();
    cout << "�п��¾�~ : ";
    newCharacter.SetJob(&this->_jobList[GetNumWithWhile(1, this->_jobList.size()) - 1]);
    // �غc�å[����|
    this->_charactersList.push_back(newCharacter);
    cout << "�Ыئ��\!" << endl << endl << endl;
    cout << this->_charactersList.back().GetInformation() << endl; // output character's info
}
void GameSystem::DistributeAttributes(Character character, int point, int& str, int& dex, int& con)
{
    int extra;
    string extraStr = ((extra = character.GetExtraStr()) > 0) ? "+" + to_string(extra) : "";
    string extraDex = ((extra = character.GetExtraDex()) > 0) ? "+" + to_string(extra) : "";
    string extraCon = ((extra = character.GetExtraCon()) > 0) ? "+" + to_string(extra) : "";

    while (point)
    {   // UI
        cout << endl << "1. �ثeSTR : " << str << extraStr;
        cout << endl << "2. �ثeDEX : " << dex << extraDex;
        cout << endl << "3. �ثeCON : " << con << extraCon;
        cout << endl << "�ثe�Ѿl�I�� : " << point << endl;
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

            default:
                cout << "��J���~�A�п�J��� 1 ~ 3 �A�Э��s��J�C" << endl;
        }
    }
}
int GameSystem::GetCharacterId()
{   // print all character name, check input format and return character id, return -1 means back to the menu.
    ShowAllCharactersName();
    cout << "0. ��^���" << endl;
    cout << "�п�ܨ��� : ";
    return GetNumWithWhile(0, this->_charactersList.size()) - 1;
}
bool GameSystem::IsEnoughExp(Character character)
{   // check whether reached full exp
    const int fullExp[LEVEL_MAX - 1] = { 100, 300, 600, 1000 }; // AIM_EXP[0] is aim exp of level 1
    return character.GetExp() == fullExp[character.GetLevel() - 1];
}
void GameSystem::CharacterLevelUp(Character& character)
{   // level up and distribute attribute points
    cout << "����ɯŤF ~ ��o�s�� 3 �I�I�� �i�H�����e�ݩʤW : " << endl;
    int str(character.GetStr()), dex(character.GetDex()), con(character.GetCon());
    DistributeAttributes(character, 3, str, dex, con);
    character.SetAttritube(str, dex, con);
    character.LevelUp();
    cout << "�t�I���� ! " << character.GetName() << "�ثe�����ŹF��" << character.GetLevel() << "�C" << endl << endl;
    cout << character.GetInformation() << endl;
}
Character GameSystem::CreateRandomMonster(int level)
{
    Character monster = this->_monstersList[rand() % MONSTERS_NUM];
    monster.SetAttritube(monster.GetStr() + level - 1, monster.GetDex() + level - 1, monster.GetCon() + level - 1);
    monster.SetJob(&this->_jobList[rand() % this->_jobList.size()]);
    return monster;
}
void GameSystem::CharacterFight()
{   // choose a character and fight random monater
    if (NoCharacter()) return;

    int characterId = GetCharacterId();

    if (characterId == -1)
    {
        cout << endl << "���i��԰��A��^���C" << endl << endl;
        return;
    }

    Character& character = this->_charactersList[characterId];
    Character monster = CreateRandomMonster(character.GetLevel());
    string fightInfo;
    bool win = character.Fight(monster, fightInfo);
    cout << endl << fightInfo << endl;

    if (win) // win
    {
        if (character.GetExp() < 1000)
        {
            character.AddExp(100); // exp increased by 100

            if (IsEnoughExp(character))
                CharacterLevelUp(character);
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

    int num = this->_charactersList.size();

    for (int i = 0; i < num; ++i)
    {
        cout << "------------------------------" << endl;
        cout << this->_charactersList[i].GetInformation() << endl;
    }
}
void GameSystem::ShowAllJobName()
{
    int num = this->_jobList.size();
    cout << endl;

    for (int i = 0; i < num; i++)
    {
        cout << i + 1 << ". " << this->_jobList[i].GetName() << endl;
    }
}
void GameSystem::DeleteCharacter()
{   // delete character
    if (NoCharacter()) return;

    int id = GetCharacterId(); // show and choose

    if (id == -1)
    {
        cout << endl << "���R������A��^���C" << endl << endl;
        return;
    }

    cout << "�w�R������ : " << this->_charactersList[id].GetName() << "�C" << endl << endl;
    this->_charactersList.erase(this->_charactersList.begin() + id);
}
bool GameSystem::RepeatedJobName(string name)
{
    int num = this->_jobList.size();

    for (int i = 0; i < num; ++i)
    {
        if (_jobList[i].GetName() == name) return true;
    }

    return false;
}
string GameSystem::GetJobName()
{
    while (1)
    {
        string name = GetName("\\/:*?\"<>| ");

        if (!RepeatedJobName(name)) return name;

        cout << "�W�٭��ơA�Э��s��J�C" << endl;
    }
}
void GameSystem::DistributeExtraAttributes(int& extraStr, int& extraDex, int& extraCon)
{
    while (1)
    {
        cout << "�г]�wSTR�B�~�[�� : ";
        extraStr = GetNumWithWhile(0, 3);
        cout << "�г]�wDEX�B�~�[�� : ";
        extraDex = GetNumWithWhile(0, 3);
        cout << "�г]�wCON�B�~�[�� : ";
        extraCon = GetNumWithWhile(0, 3);

        if (extraStr + extraDex + extraCon <= 3) return;

        cout << "�B�~�[���ƭ��`�M�W�L 3 �A�Э��s��J�C" << endl;
    }
}
void GameSystem::AppendJob()
{
    cout << endl << "�п�J¾�~�W�� : ";
    string name = GetJobName();
    int extraStr(0), extraDex(0), extraCon(0);
    DistributeExtraAttributes(extraStr, extraDex, extraCon);
    this->_jobList.push_back(Job(name, extraStr, extraDex, extraCon));
    cout << "�s�W¾�~ " << this->_jobList.back().GetName() << " ���\!" << endl << endl;
}
bool GameSystem::JobIsInUse(Job& job)
{
    int num = this->_charactersList.size();

    for (int i = 0; i < num; ++i)
    {
        if (this->_charactersList[i].GetJob() == &job)
            return true;
    }

    return false;
}
int GameSystem::GetDeleteJobId()
{
    ShowAllJobName();
    cout << "0. ��^���" << endl;
    cout << "�п��¾�~ : ";

    while (1)
    {
        int jobId = GetNumWithWhile(0, this->_jobList.size()) - 1;

        if (jobId == -1) return -1;

        if(!JobIsInUse(this->_jobList[jobId])) return jobId;

        cout << "�o��¾�~�|������A�L�k�R���C�Э��s��J : ";
    }
}
void GameSystem::DeleteJob()
{
    int jobId = GetDeleteJobId();

    if (jobId == -1)
    {
        cout << endl << "���R��¾�~�A��^���C" << endl << endl;
        return;
    }

    if (this->_jobList.size() == 1)
    {
        cout << "�ѤU�@��¾�~�A�L�k�R���C" << endl << endl;
        return;
    }

    cout << "�w�R��¾�~ : " << this->_jobList[jobId].GetName() << "�C" << endl << endl;
    this->_jobList.erase(this->_jobList.begin() + jobId);
}