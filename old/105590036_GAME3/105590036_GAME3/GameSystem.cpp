#include "GameSystem.h"

GameSystem::GameSystem()
{   // create monster data and job data
    this->_monstersList =
    {
        { "哥布林", 1, 6, 1, NULL },
        { "史萊姆", 1, 1, 6, NULL },
        { "獸人", 6, 1, 1, NULL },
        { "大青蛙", 3, 2, 3, NULL }
    };
    this->_jobList =
    {
        { "盜賊", 2, 0, 0 },
        { "獵人", 0, 2, 0 },
        { "戰士", 0, 0, 2 }
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

            case 6:
                DeleteJob();
                break;

            case 7: // 離開
                return;

            default:
                cout << "輸入錯誤，請輸入整數 1 ~ 7 。" << endl << endl;
        }
    }
}
bool GameSystem::FullCharacter()
{   // check whether character is full
    if (this->_charactersList.size() == CHARACTER_MAX)
    {
        cout << "角色數量已達上限" << endl << endl;
        return true;
    }
    else
        return false;
}
bool GameSystem::NoCharacter()
{   // check whether character is empty
    if (this->_charactersList.empty())
    {
        cout << "你沒有任何角色" << endl << endl;
        return true;
    }
    else
        return false;
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
int GameSystem::GetNum(int min, int max)
{   // 此function用於取得整數輸入，最小值(min)，最大值(max)需自行設定 //回傳-1表示輸入錯誤
    string input;
    getline(cin, input);

    for (int i = min; i <= max; ++i)
    {
        if (input == to_string(i)) return i;
    }

    return -1; // 輸入錯誤，請輸入整數1~max
}
int GameSystem::GetNumWithWhile(int min, int max)
{   // 此function用於取得整數輸入，最小值(min)，最大值(max)需自行設定 //需輸入到正確值為止
    while (1)
    {
        int num = GetNum(min, max);

        if (num != -1) return num;

        cout << "輸入錯誤，請輸入整數 " << min << " ~ " << max << "。請重新輸入 : ";
    }
}
string GameSystem::GetName(string illegalCharacters)
{   // 輸入名字並檢查是否包含非法字元
    string name;

    while (1)
    {
        getline(cin, name);

        if (name[0] == '\0' || name[0] == ' ') // 不可為空白開頭
            cout << "第一個字元不可為空白，";
        else if (name.size() > 32)
            cout << "長度最多32位元，";
        else if (name.find_first_of(illegalCharacters) != string::npos) // 不可含有非法字元
            cout << "名字中不可帶有非法字元，";
        else
            return name;

        cout << "請重新輸入 : ";
    }
}
void GameSystem::CreateCharacter()
{   // create character
    if (FullCharacter()) return; // full

    // 指定名字
    cout << endl << "請輸入角色名稱 : ";
    string name = GetName("\\/:*?\"<>|"); // name
    Character newCharacter(name, 1, 1, 1, NULL);
    // 指定屬性
    int str(1), dex(1), con(1);
    DistributeAttributes(newCharacter, 5, str, dex, con);
    newCharacter.SetAttritube(str, dex, con);
    // 指定職業
    ShowAllJobName();
    cout << "請選擇職業 : ";
    newCharacter.SetJob(&this->_jobList[GetNumWithWhile(1, this->_jobList.size()) - 1]);
    // 建構並加到堆疊
    this->_charactersList.push_back(newCharacter);
    cout << "創建成功!" << endl << endl << endl;
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
        cout << endl << "1. 目前STR : " << str << extraStr;
        cout << endl << "2. 目前DEX : " << dex << extraDex;
        cout << endl << "3. 目前CON : " << con << extraCon;
        cout << endl << "目前剩餘點數 : " << point << endl;
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
    return GetNumWithWhile(0, this->_charactersList.size()) - 1;
}
bool GameSystem::IsEnoughExp(Character character)
{   // check whether reached full exp
    const int fullExp[LEVEL_MAX - 1] = { 100, 300, 600, 1000 }; // AIM_EXP[0] is aim exp of level 1
    return character.GetExp() == fullExp[character.GetLevel() - 1];
}
void GameSystem::CharacterLevelUp(Character& character)
{   // level up and distribute attribute points
    cout << "角色升級了 ~ 獲得新的 3 點點數 可以分到當前屬性上 : " << endl;
    int str(character.GetStr()), dex(character.GetDex()), con(character.GetCon());
    DistributeAttributes(character, 3, str, dex, con);
    character.SetAttritube(str, dex, con);
    character.LevelUp();
    cout << "配點完成 ! " << character.GetName() << "目前的等級達到" << character.GetLevel() << "。" << endl << endl;
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
        cout << endl << "不進行戰鬥，返回選單。" << endl << endl;
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
        cout << endl << "不刪除角色，返回選單。" << endl << endl;
        return;
    }

    cout << "已刪除角色 : " << this->_charactersList[id].GetName() << "。" << endl << endl;
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

        cout << "名稱重複，請重新輸入。" << endl;
    }
}
void GameSystem::DistributeExtraAttributes(int& extraStr, int& extraDex, int& extraCon)
{
    while (1)
    {
        cout << "請設定STR額外加成 : ";
        extraStr = GetNumWithWhile(0, 3);
        cout << "請設定DEX額外加成 : ";
        extraDex = GetNumWithWhile(0, 3);
        cout << "請設定CON額外加成 : ";
        extraCon = GetNumWithWhile(0, 3);

        if (extraStr + extraDex + extraCon <= 3) return;

        cout << "額外加成數值總和超過 3 ，請重新輸入。" << endl;
    }
}
void GameSystem::AppendJob()
{
    cout << endl << "請輸入職業名稱 : ";
    string name = GetJobName();
    int extraStr(0), extraDex(0), extraCon(0);
    DistributeExtraAttributes(extraStr, extraDex, extraCon);
    this->_jobList.push_back(Job(name, extraStr, extraDex, extraCon));
    cout << "新增職業 " << this->_jobList.back().GetName() << " 成功!" << endl << endl;
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
    cout << "0. 返回選單" << endl;
    cout << "請選擇職業 : ";

    while (1)
    {
        int jobId = GetNumWithWhile(0, this->_jobList.size()) - 1;

        if (jobId == -1) return -1;

        if(!JobIsInUse(this->_jobList[jobId])) return jobId;

        cout << "這個職業尚有角色，無法刪除。請重新輸入 : ";
    }
}
void GameSystem::DeleteJob()
{
    int jobId = GetDeleteJobId();

    if (jobId == -1)
    {
        cout << endl << "不刪除職業，返回選單。" << endl << endl;
        return;
    }

    if (this->_jobList.size() == 1)
    {
        cout << "剩下一個職業，無法刪除。" << endl << endl;
        return;
    }

    cout << "已刪除職業 : " << this->_jobList[jobId].GetName() << "。" << endl << endl;
    this->_jobList.erase(this->_jobList.begin() + jobId);
}