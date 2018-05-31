#include "GameSystem.h"

// constructor
GameSystem::GameSystem()
{
    // �إ߹w�]�Ǫ�
    this->_monstersList =
    {
        Character("�����L", 1, 6, 1, NULL),
        Character("�v�ܩi", 1, 1, 6, NULL),
        Character("�~�H", 6, 1, 1, NULL),
        Character("�j�C��", 3, 2, 3, NULL)
    };
    // �إ߹w�]¾�~
    this->_jobList =
    {
        new MeleeJob("�s��", 2, 0, 0),
        new MeleeJob("���", 3, 0, 0),
        new RemoteJob("�y�H", 0, 2, 0),
        new RemoteJob("���g��", 0, 3, 0),
        new DefenseJob("�Ԥh", 0, 0, 2),
        new DefenseJob("�g�Ԥh", 0, 0, 3)
    };
}
// destructor
GameSystem::~GameSystem()
{
    // �M�� Job
    size_t jobSize = this->_jobList.size();

    for (unsigned int i = 0; i < jobSize; ++i)
    {
        delete this->_jobList[i];
    }
}
// run
void GameSystem::Start()
{
    srand((unsigned)time(0));

    while (1)
    {
        PrintMenu();
        int input = GetNum(1, 7); // ��J�Ʀr 1 ~ 7

        if (input == 7) return; // ���}�C��

        Control(input);
    }
}
// ��ܿ��
void GameSystem::PrintMenu()
{
    cout << "1. �Ыب���" << endl;
    cout << "2. ����@��" << endl;
    cout << "3. �C�X�Ҧ�����" << endl;
    cout << "4. �R������" << endl;
    cout << "5. �s�W¾�~" << endl;
    cout << "6. �R��¾�~" << endl;
    cout << "7. ���}" << endl;
}
// ��ܥ\��
void GameSystem::Control(int input)
{
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
// string �� int�Aint���d�򶷫��w�A���b�d�򤺩ο�J���~�^�� -1
int GameSystem::StringToInt(string input, int min, int max)
{
    for (int i = min; i <= max; ++i)
    {
        if (input == to_string(i))
            return i;
    }

    return -1; // ��J���~
}
// ���o����ƿ�J�A�̤p��(min)�A�̤j��(max)�ݫ��w //�^�� -1 ��ܿ�J���~
int GameSystem::GetNum(int min, int max)
{
    string input;
    getline(cin, input);
    return StringToInt(input, min, max);
}
// ���o����ƿ�J�A�̤p��(min)�A�̤j��(max)�ݫ��w //�ݿ�J�쥿�T�Ȭ���
int GameSystem::GetNumUntilCorrect(int min, int max)
{
    string input;

    while (1)
    {
        getline(cin, input);
        int num = StringToInt(input, min, max);

        if (num != -1) return num;

        cout << "��J���~�A�п�J��� " << min << " ~ " << max << "�C�Э��s��J : ";
    }
}
// ��J�W�r���ˬd�O�_�]�t�D�k�r��
string GameSystem::GetName()
{
    string name;

    while (1)
    {
        getline(cin, name);

        if (name[0] == '\0' || name[0] == ' ') // ���i���ťն}�Y
            cout << "�Ĥ@�Ӧr�����i���ť�";
        else if (name.size() > 32) // �̤j����32�줸
            cout << "�W�r�L���A�̦h32��";
        else if (name.find_first_of("\\/:*?\"<>|") != string::npos) // �ˬd�O�_�t���D�k�r��
            cout << "�W�r�����i�a���D�k�r��";
        else
            return name;

        cout << "�A�Э��s��J : ";
    }
}
// �q�{��¾�~�C���A��ŦX��w��¾�~�����H pointer �覡��i�@�ӷs�� vector �Ѫ��a��ܡC
void GameSystem::PushSpecificJobList(vector<Job*>& specificJobList, Job::JobType jobType)
{
    size_t size = this->_jobList.size();

    for (unsigned int i = 0; i < size; ++i)
    {
        if (this->_jobList[i]->GetJobType() == jobType)
            specificJobList.push_back(this->_jobList[i]);
    }
}
// ��ܮe������¾�~�W
void GameSystem::ShowJobName(const vector<Job*>& jobList)
{
    size_t size = jobList.size();

    for (unsigned int i = 0; i < size; ++i)
    {
        cout << i + 1 << ". " << jobList[i]->GetName() << endl;
    }
}
// ��ܩҦ��i�諸¾�~����
void GameSystem::ShowAllJobTypeName()
{
    cout << "1. ��Z�������t" << endl;
    cout << "2. ���Z�������t" << endl;
    cout << "3. ���m�t" << endl;
}
// �Ыب���
void GameSystem::CreateCharacter()
{
    if (this->_charactersList.size() == CHARACTER_MAX)
    {   // ����ƶq�F�W�� (5)
        cout << "����ƶq�w�F�W���C" << endl << endl;
        return;
    }

    // ���w�W�r
    cout << endl << "�п�J����W�� : ";
    string name = GetName(); // name
    // ���w�ݩ�
    int str(1), dex(1), con(1);
    DistributeAttributePoints(5, str, dex, con, 0, 0, 0);
    // ���w¾�~����
    cout << endl << "�п��¾�~���� :" << endl << endl;
    ShowAllJobTypeName();
    Job::JobType jobType = (Job::JobType)(GetNumUntilCorrect(1, 3) - 1);
    // ���Ϳ�w��¾�~�C��
    vector<Job*> specificJob;
    PushSpecificJobList(specificJob, jobType);
    // ���w¾�~
    cout << "�п��¾�~ : " << endl;
    ShowJobName(specificJob);
    Job* job = specificJob[GetNumUntilCorrect(1, specificJob.size()) - 1];
    // �غc�å[�J���|
    this->_charactersList.push_back(Character(name, str, dex, con, job));
    cout << "�Ыئ��\!" << endl << endl << endl;
    // ��X������
    cout << this->_charactersList.back().GetInformation() << endl;
}
// ���t�ݩ��I��
void GameSystem::DistributeAttributePoints(int point, int& str, int& dex, int& con, int extraStr, int extraDex, int extraCon)
{
    // ¾�~�ҼW�[����O�A�j��s��X "+value"�A�_�h���Ŧr��(����X)�C
    const string extraStrString = extraStr > 0 ? "+" + to_string(extraStr) : "";
    const string extraDexString = extraDex > 0 ? "+" + to_string(extraDex) : "";
    const string extraConString = extraCon > 0 ? "+" + to_string(extraCon) : "";

    while (point)
    {
        // ��ܿ��
        cout << endl << "1. �ثeSTR : " << str << extraStrString << endl;
        cout << "2. �ثeDEX : " << dex << extraDexString << endl;
        cout << "3. �ثeCON : " << con << extraConString << endl;
        cout << "�ثe�Ѿl�I�� : " << point << endl;
        cout << "�п�ܱ��W�[���ݩ� : ";

        // ����ݩ�
        switch (GetNum(1, 3)) // ��J1 ~ 3
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
// �q�Ǫ��C�����H���Ǫ��ñq¾�~�C���H����ܧ@���Ǫ���¾�~
Character GameSystem::CreateRandomMonster(int level)
{
    Character monster = this->_monstersList[rand() % MONSTERS_NUM];
    monster.SetAttributes(monster.GetStr() + level - 1, monster.GetDex() + level - 1, monster.GetCon() + level - 1);
    monster.SetJob(this->_jobList[rand() % this->_jobList.size()]);
    return monster;
}
// ��Ĺ�Ǫ���W�[�g��M����
void GameSystem::CharacterGetExpAndLevel(Character& character)
{
    if (character.IsFullLevel()) return;

    character.AddExp(100);

    if (character.IsFullExp())
    {   // ����ɯšA���t�ݩ�
        cout << "����ɯŤF ~ ��o�s�� 3 �I�I�� �i�H�����e�ݩʤW : " << endl;
        int str(character.GetStr()), dex(character.GetDex()), con(character.GetCon());
        DistributeAttributePoints(3, str, dex, con, character.GetExtraStr(), character.GetExtraDex(), character.GetExtraCon());
        character.SetAttributes(str, dex, con);
        character.LevelUp();
        cout << "�t�I���� ! " << character.GetName() << "�ثe�����ŹF��" << character.GetLevel() << "�C" << endl << endl;
        cout << character.GetInformation() << endl;
    }
}
// ����@��
void GameSystem::CharacterFight()
{
    if (this->_charactersList.empty())
    {
        cout << "�A�S�����󨤦�A�Х��Ыب���C" << endl << endl;
        return;
    }

    // ��ܨ���
    ShowAllCharactersName();
    cout << "0. ��^���" << endl;
    cout << "�п�ܨ���i��@�� : ";
    int characterId = GetNumUntilCorrect(0, this->_charactersList.size()) - 1;

    if (characterId == -1)
    {   // ��^���
        cout << endl << "���i��԰��A��^���C" << endl << endl;
        return;
    }

    Character& player = this->_charactersList[characterId];
    string fightInfo(""); // �x�s�԰���T
    // �}�l�԰�
    bool fightResult = player.Fight(CreateRandomMonster(player.GetLevel()), fightInfo);
    cout << endl << fightInfo << endl;

    if (fightResult) // Ĺ
        CharacterGetExpAndLevel(player); // �W�[�g��M����
    else // ��
        player.AddFailFightTimes(); //�W�[�԰����Ѧ���
}
// ��ܩҦ�����W
void GameSystem::ShowAllCharactersName()
{
    size_t num = _charactersList.size();
    cout << endl;

    for (unsigned int i = 0; i < num; ++i)
    {
        cout << i + 1 << ". " << _charactersList[i].GetName() << endl;
    }
}
// ��ܩҦ�������
void GameSystem::ShowAllCharacters()
{
    if (this->_charactersList.empty())
    {
        cout << "�A�S�����󨤦�A�Х��Ыب���C" << endl << endl;
        return;
    }

    size_t num = this->_charactersList.size();

    for (unsigned int i = 0; i < num; ++i)
    {
        cout << "------------------------------" << endl;
        cout << this->_charactersList[i].GetInformation() << endl;
    }
}
// ��ܩҦ�¾�~�W��
void GameSystem::ShowAllJobName()
{
    size_t num = this->_jobList.size();
    cout << endl;

    for (unsigned int i = 0; i < num; i++)
    {
        cout << i + 1 << ". " << this->_jobList[i]->GetName() << endl;
    }
}
// �R������
void GameSystem::DeleteCharacter()
{
    if (this->_charactersList.empty())
    {   // ��^���
        cout << "�A�S�����󨤦�A�Х��Ыب���C" << endl << endl;
        return;
    }

    // ��ܨ���
    ShowAllCharactersName();
    cout << "0. ��^���" << endl;
    cout << "�п�ܨ��� : ";
    int id = GetNumUntilCorrect(0, this->_charactersList.size()) - 1;

    if (id == -1)
    {   // ���R���A��^���A
        cout << endl << "���R������A��^���C" << endl << endl;
        return;
    }

    // �R��
    cout << "�w�R������ : " << this->_charactersList[id].GetName() << "�C" << endl << endl;
    this->_charactersList.erase(this->_charactersList.begin() + id);
}
// �ˬd¾�~�W�٬O�_����
bool GameSystem::JobNameIsReaped(string name)
{
    size_t num = this->_jobList.size();

    for (unsigned int i = 0; i < num; ++i)
    {
        if (_jobList[i]->GetName() == name)
            return true;
    }

    return false;
}
// ���o¾�~�W�٨��ˬd���~
string GameSystem::GetJobName()
{
    string name;

    while (1)
    {
        getline(cin, name);

        if (name[0] == '\0' || name[0] == ' ') // ���i���ťն}�Y
            cout << "�Ĥ@�Ӧr�����i���ť�";
        else if (name.size() > 32) // �̤j����32�줸
            cout << "�W�r�L���A�̦h32��";
        else if (name.find_first_of("\\/:*?\"<>| ") != string::npos) // ���i�t���D�k�r��
            cout << "�W�r�����i�a���D�k�r��";
        else if (JobNameIsReaped(name))
            cout << "�W�٭���"; // �W�٤��i����
        else
            return name;

        cout << "�A�Э��s��J : ";
    }
}
// �]�w¾�~���ݩʥ[��
void GameSystem::AssignExtraAttributes(int& extraStr, int& extraDex, int& extraCon)
{
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
// �Ыث��w��¾�~���O
Job* GameSystem::CreateSpecificJob(string name, int extraStr, int extraDex, int extraCon, Job::JobType jobType)
{
    switch (jobType)
    {
        case Job::MELEE:
            return new MeleeJob(name, extraStr, extraDex, extraCon);

        case Job::REMOTE:
            return new RemoteJob(name, extraStr, extraDex, extraCon);

        default:
            return new DefenseJob(name, extraStr, extraDex, extraCon);
    }
}
// �s�W¾�~
void GameSystem::AppendJob()
{
    if (this->_jobList.size() == JOB_MAX)
    {   // full (20)
        cout << "¾�~�ƶq�w�F�W��" << endl;
        return;
    }

    // ���w¾�~����
    cout << endl << "�п��¾�~����" << endl << endl;
    ShowAllJobTypeName();
    Job::JobType jobType = (Job::JobType)(GetNumUntilCorrect(1, 3) - 1);
    // ���w¾�~�W
    cout << endl << "�п�J¾�~�W�� : ";
    string name = GetJobName(); // job name
    // ���w�ݩʥ[��
    int extraStr(0), extraDex(0), extraCon(0); // job attribute
    AssignExtraAttributes(extraStr, extraDex, extraCon);
    // �غc�å[��C��
    this->_jobList.push_back(CreateSpecificJob(name, extraStr, extraDex, extraCon, jobType));
    cout << "�s�W¾�~ " << this->_jobList.back()->GetName() << " ���\!" << endl << endl;
}
// �ˬd¾�~�O�_�����⥿�b�ϥ�
bool GameSystem::JobIsInUse(Job* job)
{
    size_t num = this->_charactersList.size();

    for (unsigned int i = 0; i < num; ++i)
    {
        if (this->_charactersList[i].GetJob() == job)
            return true;
    }

    return false;
}
// �ˬd�O�_����¾�~���O���̫�@��
bool GameSystem::IsTheLastJobOfTheJobType(Job* job)
{
    size_t size = this->_jobList.size();
    Job::JobType jobType = job->GetJobType();

    for (unsigned int i = 0; i < size; ++i)
    {   // ¾�~���O�ۦP���O�����m���P�^�� false
        if (this->_jobList[i]->GetJobType() == jobType && this->_jobList[i] != job)
            return false;
    }

    return true;
}
// ���o�n�R����¾�~�� index
int GameSystem::GetDeleteJobIndex()
{
    while (1)
    {
        int jobId = GetNumUntilCorrect(0, this->_jobList.size()) - 1;

        if (jobId == -1)
            return -1; // �^�� -1 �ϥΪ̤��R��¾�~��^���
        else if (this->_jobList.size() == Job::JOB_TYPE_NUM)
            return -2; // �^�� -2 ¾�~�Ѧs 3 �Ӥ��i�A�R��
        else if (JobIsInUse(this->_jobList[jobId]))
            cout << "�o��¾�~�|������A���i�R���C�Э��s��J : "; // ¾�~�Q����ϥΤ��i�R��
        else if (IsTheLastJobOfTheJobType(this->_jobList[jobId]))
            cout << "�Өt¾�~�ѤU�@��¾�~�A���i�R���C�Э��s��J : "; // �Өt�̫�¾�~�L�k�R��
        else
            return jobId;
    }
}
// �R��¾�~
void GameSystem::DeleteJob()
{
    // ���¾�~
    ShowAllJobName();
    cout << "0. ��^���" << endl;
    cout << "�п��¾�~ : ";
    int jobId = GetDeleteJobIndex();

    if (jobId == -1)
    {   // ��^���
        cout << endl << "���R��¾�~�A��^���C" << endl << endl;
        return;
    }
    else if (jobId == -2)
    {   // �U�t�Ȧs�@¾�~�L�k�R��
        cout << "�U�t�ҥu�ѤU�@��¾�~�A�L�k�A�R���C" << endl << endl;
        return;
    }

    //�R��¾�~
    cout << "�w�R��¾�~ : " << this->_jobList[jobId]->GetName() << "�C" << endl << endl;
    delete this->_jobList[jobId];
    this->_jobList.erase(this->_jobList.begin() + jobId);
}