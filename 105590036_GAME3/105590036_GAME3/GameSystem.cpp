#include "GameSystem.h"

GameSystem::GameSystem()
{   // initialize monster and job data
    this->_monstersList =
    {
        Character("�����L", 1, 6, 1, NULL),
        Character("�v�ܩi", 1, 1, 6, NULL),
        Character("�~�H", 6, 1, 1, NULL),
        Character("�j�C��", 3, 2, 3, NULL)
    };
    this->_jobList =
    {
        new Job("�s��", 2, 0, 0),
        new Job("�y�H", 0, 2, 0),
        new Job("�Ԥh", 0, 0, 2)
    };
}
GameSystem::~GameSystem()
{   // delete job memory
    int jobSize = this->_jobList.size();

    for (int i = 0; i < jobSize; ++i)
    {
        delete this->_jobList[i];
    }
}
void GameSystem::Start()
{   // run
    srand((unsigned)time(0));

    while (1)
    {
        PrintMenu();
        int input = GetNum(1, 7); // input number 1 to 7

        if (input == 7) return;

        Control(input);
    }
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
void GameSystem::Control(int input)
{   // work
    switch (input)
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

        case 6: // �R��¾�~
            DeleteJob();
            break;

        default:
            cout << "��J���~�A�п�J��� 1 ~ 7 �C" << endl << endl;
    }
}
int GameSystem::StringToInt(string input, int min, int max)
{   // string �� int�Aint���d�򶷫��w�A���b�d�򤺩ο�J���~�^��-1
    for (int i = min; i <= max; ++i)
    {
        if (input == to_string(i))
            return i;
    }

    return -1; // ��J���~
}
int GameSystem::GetNum(int min, int max)
{   // ���o����ƿ�J�A�̤p��(min)�A�̤j��(max)�ݫ��w //�^��-1��ܿ�J���~
    string input;
    getline(cin, input);
    return StringToInt(input, min, max);
}
int GameSystem::GetNumUntilCorrect(int min, int max)
{   // ���o����ƿ�J�A�̤p��(min)�A�̤j��(max)�ݫ��w //�ݿ�J�쥿�T�Ȭ���
    string input;

    while (1)
    {
        getline(cin, input);
        int num = StringToInt(input, min, max);

        if (num != -1) return num;

        cout << "��J���~�A�п�J��� " << min << " ~ " << max << "�C�Э��s��J : ";
    }
}
bool GameSystem::LegalName(string name, string illegalCharacters)
{
    if (name[0] == '\0' || name[0] == ' ') // ���i���ťն}�Y
        cout << "�Ĥ@�Ӧr�����i���ť�";
    else if (name.size() > 32) // �̤j����32�줸
        cout << "�W�r�L���A�̦h32��";
    else if (name.find_first_of(illegalCharacters) != string::npos) // ���i�t���D�k�r��
        cout << "�W�r�����i�a���D�k�r��";
    else
        return true;

    return false;
}
string GameSystem::GetName(string illegalCharacters)
{   // ��J�W�r���ˬd�O�_�]�t�D�k�r��
    string name;

    while (1)
    {
        getline(cin, name);

        if (LegalName(name, "\\/:*?\"<>|"))
            return name;

        cout << "�A�Э��s��J : ";
    }
}
bool GameSystem::NoCharacter()
{   // check whether character is empty
    if (this->_charactersList.empty())
    {
        cout << "�A�S�����󨤦�A�Х��Ыب���C" << endl << endl;
        return true;
    }
    else
        return false;
}
void GameSystem::CreateCharacter()
{   // create character
    if (this->_charactersList.size() == CHARACTER_MAX)
    {   // full
        cout << "����ƶq�w�F�W���C" << endl << endl;
        return;
    }

    // ���w�W�r
    cout << endl << "�п�J����W�� : ";
    string name = GetName("\\/:*?\"<>|"); // name
    // ���w�ݩ�
    int str(1), dex(1), con(1);
    DistributeAttributePoints(5, str, dex, con, 0, 0, 0);
    // ���w¾�~
    ShowAllJobName();
    cout << "�п��¾�~ : ";
    Job* job = this->_jobList[GetNumUntilCorrect(1, this->_jobList.size()) - 1];
    // �غc�å[����|
    this->_charactersList.push_back(Character(name, str, dex, con, job));
    cout << "�Ыئ��\!" << endl << endl << endl;
    cout << this->_charactersList.back().GetInformation() << endl; // output character's info
}
void GameSystem::DistributeAttributePoints(int point, int& str, int& dex, int& con, int extraStr, int extraDex, int extraCon)
{
    // ¾�~�ҼW�[����O�A�j��s��X "+value"�A�_�h���Ŧr��(����X)�C
    const string extraStrString = extraStr > 0 ? "+" + to_string(extraStr) : "";
    const string extraDexString = extraDex > 0 ? "+" + to_string(extraDex) : "";
    const string extraConString = extraCon > 0 ? "+" + to_string(extraCon) : "";

    while (point)
    {   // UI
        cout << endl << "1. �ثeSTR : " << str << extraStrString << endl;
        cout << "2. �ثeDEX : " << dex << extraDexString << endl;
        cout << "3. �ثeCON : " << con << extraConString << endl;
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
    return GetNumUntilCorrect(0, this->_charactersList.size()) - 1;
}
bool GameSystem::IsEnoughExp(const Character& character)
{   // check whether reached full exp
    const int fullExp[LEVEL_MAX - 1] = { 100, 300, 600, 1000 }; // AIM_EXP[0] is aim exp of level 1
    return character.GetExp() == fullExp[character.GetLevel() - 1];
}
void GameSystem::CharacterLevelUp(Character& character)
{   // level up and distribute attribute points
    cout << "����ɯŤF ~ ��o�s�� 3 �I�I�� �i�H�����e�ݩʤW : " << endl;
    int str(character.GetStr()), dex(character.GetDex()), con(character.GetCon());
    DistributeAttributePoints(3, str, dex, con, character.GetExtraStr(), character.GetExtraDex(), character.GetExtraCon());
    character.SetAttributes(str, dex, con);
    character.LevelUp();
    cout << "�t�I���� ! " << character.GetName() << "�ثe�����ŹF��" << character.GetLevel() << "�C" << endl << endl;
    cout << character.GetInformation() << endl;
}
Character GameSystem::CreateRandomMonster(int level)
{   // create random monster with random job
    Character monster = this->_monstersList[rand() % MONSTERS_NUM];
    monster.SetAttributes(monster.GetStr() + level - 1, monster.GetDex() + level - 1, monster.GetCon() + level - 1);
    monster.SetJob(this->_jobList[rand() % this->_jobList.size()]);
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

    Character& player = this->_charactersList[characterId];
    string fightInfo("");
    bool fightResult = player.Fight(CreateRandomMonster(player.GetLevel()), fightInfo);
    cout << endl << fightInfo << endl;

    if (fightResult) // win
    {
        if (player.GetExp() < EXP_MAX)
        {
            player.AddExp(100); // exp increases 100

            if (IsEnoughExp(player))
                CharacterLevelUp(player); // level up
        }
    }
    else // lose
        player.AddFailFightTimes(); // add fail fight times
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
{   // show all job name
    int num = this->_jobList.size();
    cout << endl;

    for (int i = 0; i < num; i++)
    {
        cout << i + 1 << ". " << this->_jobList[i]->GetName() << endl;
    }
}
void GameSystem::DeleteCharacter()
{   // delete character
    if (NoCharacter()) return;

    int id = GetCharacterId(); // show and choose

    if (id == -1)
    {   // return
        cout << endl << "���R������A��^���C" << endl << endl;
        return;
    }

    cout << "�w�R������ : " << this->_charactersList[id].GetName() << "�C" << endl << endl;
    this->_charactersList.erase(this->_charactersList.begin() + id);
}
bool GameSystem::JobNameIsNotReaped(string name)
{   // check whether job name is repeated
    int num = this->_jobList.size();

    for (int i = 0; i < num; ++i)
    {
        if (_jobList[i]->GetName() == name)
        {
            cout << "�W�٭���";
            return false;
        }
    }

    return true;
}
string GameSystem::GetJobName()
{   // get job name and check job name syntax
    string name;

    while (1)
    {
        getline(cin, name);

        if (LegalName(name, "\\/:*?\"<>| ") && JobNameIsNotReaped(name))
            return name;

        cout << "�A�Э��s��J : ";
    }
}
void GameSystem::AssignExtraAttributes(int& extraStr, int& extraDex, int& extraCon)
{   // assign job's extra attribute
    while (1)
    {
        cout << "�г]�wSTR�B�~�[�� : ";
        extraStr = GetNumUntilCorrect(0, 3);
        cout << "�г]�wDEX�B�~�[�� : ";
        extraDex = GetNumUntilCorrect(0, 3);
        cout << "�г]�wCON�B�~�[�� : ";
        extraCon = GetNumUntilCorrect(0, 3);

        if (extraStr + extraDex + extraCon <= 3) return;

        cout << "�B�~�[���ƭ��`�M�W�L 3 �A�Э��s��J�C" << endl;
    }
}
void GameSystem::AppendJob()
{   // add new job
    if (this->_jobList.size() == JOB_MAX)
    {   // full (20)
        cout << "¾�~�ƶq�w�F�W��" << endl;
        return;
    }

    cout << endl << "�п�J¾�~�W�� : ";
    string name = GetJobName(); // job name
    int extraStr(0), extraDex(0), extraCon(0); // job attribute
    AssignExtraAttributes(extraStr, extraDex, extraCon);
    this->_jobList.push_back(new Job(name, extraStr, extraDex, extraCon));
    cout << "�s�W¾�~ " << this->_jobList.back()->GetName() << " ���\!" << endl << endl;
}
bool GameSystem::JobIsNotUsed(Job* job)
{   // check whether job is in used
    int num = this->_charactersList.size();

    for (int i = 0; i < num; ++i)
    {
        if (this->_charactersList[i].GetJob() == job)
            return false;
    }

    return true;
}
int GameSystem::GetDeleteJobId()
{   // show all job and input job that user wants to delete and check the job is not in used
    ShowAllJobName();
    cout << "0. ��^���" << endl;
    cout << "�п��¾�~ : ";

    while (1)
    {
        int jobId = GetNumUntilCorrect(0, this->_jobList.size()) - 1;

        if (jobId == -1) return -1;

        if(JobIsNotUsed(this->_jobList[jobId])) return jobId;

        cout << "�o��¾�~�|������A�L�k�R���C�Э��s��J : ";
    }
}
void GameSystem::DeleteJob()
{   // delete job
    int jobId = GetDeleteJobId();

    if (jobId == -1)
    {   // return
        cout << endl << "���R��¾�~�A��^���C" << endl << endl;
        return;
    }

    if (this->_jobList.size() == 1)
    {   // the last job
        cout << "�ѤU�@��¾�~�A�L�k�R���C" << endl << endl;
        return;
    }

    cout << "�w�R��¾�~ : " << this->_jobList[jobId]->GetName() << "�C" << endl << endl;
    delete this->_jobList[jobId];
    this->_jobList.erase(this->_jobList.begin() + jobId);
}