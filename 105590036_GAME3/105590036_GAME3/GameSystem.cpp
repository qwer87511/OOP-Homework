#include "GameSystem.h"

GameSystem::GameSystem()
{   // initialize monster and job data
    this->_monstersList =
    {
        Character("哥布林", 1, 6, 1, NULL),
        Character("史萊姆", 1, 1, 6, NULL),
        Character("獸人", 6, 1, 1, NULL),
        Character("大青蛙", 3, 2, 3, NULL)
    };
    this->_jobList =
    {
        new Job("盜賊", 2, 0, 0),
        new Job("獵人", 0, 2, 0),
        new Job("戰士", 0, 0, 2)
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
    cout << "1. 創建角色" << endl;
    cout << "2. 角色作戰" << endl;
    cout << "3. 列出所有角色" << endl;
    cout << "4. 刪除角色" << endl;
    cout << "5. 新增職業" << endl;
    cout << "6. 刪除職業" << endl;
    cout << "7. 離開" << endl;
}
void GameSystem::Control(int input)
{   // work
    switch (input)
    {
        case 1: // 建立角色
            CreateCharacter();
            break;

        case 2: // 角色作戰
            CharacterFight();
            break;

        case 3: // 顯示所有角色
            ShowAllCharacters();
            break;

        case 4: // 刪除角色
            DeleteCharacter();
            break;

        case 5: // 新增職業
            AppendJob();
            break;

        case 6: // 刪除職業
            DeleteJob();
            break;

        default:
            cout << "輸入錯誤，請輸入整數 1 ~ 7 。" << endl << endl;
    }
}
int GameSystem::StringToInt(string input, int min, int max)
{   // string 轉 int，int的範圍須指定，不在範圍內或輸入錯誤回傳-1
    for (int i = min; i <= max; ++i)
    {
        if (input == to_string(i))
            return i;
    }

    return -1; // 輸入錯誤
}
int GameSystem::GetNum(int min, int max)
{   // 取得正整數輸入，最小值(min)，最大值(max)需指定 //回傳-1表示輸入錯誤
    string input;
    getline(cin, input);
    return StringToInt(input, min, max);
}
int GameSystem::GetNumUntilCorrect(int min, int max)
{   // 取得正整數輸入，最小值(min)，最大值(max)需指定 //需輸入到正確值為止
    string input;

    while (1)
    {
        getline(cin, input);
        int num = StringToInt(input, min, max);

        if (num != -1) return num;

        cout << "輸入錯誤，請輸入整數 " << min << " ~ " << max << "。請重新輸入 : ";
    }
}
bool GameSystem::LegalName(string name, string illegalCharacters)
{
    if (name[0] == '\0' || name[0] == ' ') // 不可為空白開頭
        cout << "第一個字元不可為空白";
    else if (name.size() > 32) // 最大長度32位元
        cout << "名字過長，最多32位";
    else if (name.find_first_of(illegalCharacters) != string::npos) // 不可含有非法字元
        cout << "名字中不可帶有非法字元";
    else
        return true;

    return false;
}
string GameSystem::GetName(string illegalCharacters)
{   // 輸入名字並檢查是否包含非法字元
    string name;

    while (1)
    {
        getline(cin, name);

        if (LegalName(name, "\\/:*?\"<>|"))
            return name;

        cout << "，請重新輸入 : ";
    }
}
bool GameSystem::NoCharacter()
{   // check whether character is empty
    if (this->_charactersList.empty())
    {
        cout << "你沒有任何角色，請先創建角色。" << endl << endl;
        return true;
    }
    else
        return false;
}
void GameSystem::CreateCharacter()
{   // create character
    if (this->_charactersList.size() == CHARACTER_MAX)
    {   // full
        cout << "角色數量已達上限。" << endl << endl;
        return;
    }

    // 指定名字
    cout << endl << "請輸入角色名稱 : ";
    string name = GetName("\\/:*?\"<>|"); // name
    // 指定屬性
    int str(1), dex(1), con(1);
    DistributeAttributePoints(5, str, dex, con, 0, 0, 0);
    // 指定職業
    ShowAllJobName();
    cout << "請選擇職業 : ";
    Job* job = this->_jobList[GetNumUntilCorrect(1, this->_jobList.size()) - 1];
    // 建構並加到堆疊
    this->_charactersList.push_back(Character(name, str, dex, con, job));
    cout << "創建成功!" << endl << endl << endl;
    cout << this->_charactersList.back().GetInformation() << endl; // output character's info
}
void GameSystem::DistributeAttributePoints(int point, int& str, int& dex, int& con, int extraStr, int extraDex, int extraCon)
{
    // 職業所增加的能力，大於零輸出 "+value"，否則為空字串(不輸出)。
    const string extraStrString = extraStr > 0 ? "+" + to_string(extraStr) : "";
    const string extraDexString = extraDex > 0 ? "+" + to_string(extraDex) : "";
    const string extraConString = extraCon > 0 ? "+" + to_string(extraCon) : "";

    while (point)
    {   // UI
        cout << endl << "1. 目前STR : " << str << extraStrString << endl;
        cout << "2. 目前DEX : " << dex << extraDexString << endl;
        cout << "3. 目前CON : " << con << extraConString << endl;
        cout << "目前剩餘點數 : " << point << endl;
        cout << "請選擇欲增加之屬性 : ";

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
                cout << "輸入錯誤，請輸入整數 1 ~ 3 ，請重新輸入。" << endl;
        }
    }
}
int GameSystem::GetCharacterId()
{   // print all character name, check input format and return character id, return -1 means back to the menu.
    ShowAllCharactersName();
    cout << "0. 返回選單" << endl;
    cout << "請選擇角色 : ";
    return GetNumUntilCorrect(0, this->_charactersList.size()) - 1;
}
bool GameSystem::IsEnoughExp(const Character& character)
{   // check whether reached full exp
    const int fullExp[LEVEL_MAX - 1] = { 100, 300, 600, 1000 }; // AIM_EXP[0] is aim exp of level 1
    return character.GetExp() == fullExp[character.GetLevel() - 1];
}
void GameSystem::CharacterLevelUp(Character& character)
{   // level up and distribute attribute points
    cout << "角色升級了 ~ 獲得新的 3 點點數 可以分到當前屬性上 : " << endl;
    int str(character.GetStr()), dex(character.GetDex()), con(character.GetCon());
    DistributeAttributePoints(3, str, dex, con, character.GetExtraStr(), character.GetExtraDex(), character.GetExtraCon());
    character.SetAttributes(str, dex, con);
    character.LevelUp();
    cout << "配點完成 ! " << character.GetName() << "目前的等級達到" << character.GetLevel() << "。" << endl << endl;
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
        cout << endl << "不進行戰鬥，返回選單。" << endl << endl;
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
        cout << endl << "不刪除角色，返回選單。" << endl << endl;
        return;
    }

    cout << "已刪除角色 : " << this->_charactersList[id].GetName() << "。" << endl << endl;
    this->_charactersList.erase(this->_charactersList.begin() + id);
}
bool GameSystem::JobNameIsNotReaped(string name)
{   // check whether job name is repeated
    int num = this->_jobList.size();

    for (int i = 0; i < num; ++i)
    {
        if (_jobList[i]->GetName() == name)
        {
            cout << "名稱重複";
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

        cout << "，請重新輸入 : ";
    }
}
void GameSystem::AssignExtraAttributes(int& extraStr, int& extraDex, int& extraCon)
{   // assign job's extra attribute
    while (1)
    {
        cout << "請設定STR額外加成 : ";
        extraStr = GetNumUntilCorrect(0, 3);
        cout << "請設定DEX額外加成 : ";
        extraDex = GetNumUntilCorrect(0, 3);
        cout << "請設定CON額外加成 : ";
        extraCon = GetNumUntilCorrect(0, 3);

        if (extraStr + extraDex + extraCon <= 3) return;

        cout << "額外加成數值總和超過 3 ，請重新輸入。" << endl;
    }
}
void GameSystem::AppendJob()
{   // add new job
    if (this->_jobList.size() == JOB_MAX)
    {   // full (20)
        cout << "職業數量已達上限" << endl;
        return;
    }

    cout << endl << "請輸入職業名稱 : ";
    string name = GetJobName(); // job name
    int extraStr(0), extraDex(0), extraCon(0); // job attribute
    AssignExtraAttributes(extraStr, extraDex, extraCon);
    this->_jobList.push_back(new Job(name, extraStr, extraDex, extraCon));
    cout << "新增職業 " << this->_jobList.back()->GetName() << " 成功!" << endl << endl;
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
    cout << "0. 返回選單" << endl;
    cout << "請選擇職業 : ";

    while (1)
    {
        int jobId = GetNumUntilCorrect(0, this->_jobList.size()) - 1;

        if (jobId == -1) return -1;

        if(JobIsNotUsed(this->_jobList[jobId])) return jobId;

        cout << "這個職業尚有角色，無法刪除。請重新輸入 : ";
    }
}
void GameSystem::DeleteJob()
{   // delete job
    int jobId = GetDeleteJobId();

    if (jobId == -1)
    {   // return
        cout << endl << "不刪除職業，返回選單。" << endl << endl;
        return;
    }

    if (this->_jobList.size() == 1)
    {   // the last job
        cout << "剩下一個職業，無法刪除。" << endl << endl;
        return;
    }

    cout << "已刪除職業 : " << this->_jobList[jobId]->GetName() << "。" << endl << endl;
    delete this->_jobList[jobId];
    this->_jobList.erase(this->_jobList.begin() + jobId);
}