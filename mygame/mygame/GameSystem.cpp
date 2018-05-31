#include "GameSystem.h"

// constructor
GameSystem::GameSystem()
{
    // 建立預設怪物
    this->_monstersList =
    {
        Character("哥布林", 1, 6, 1, NULL),
        Character("史萊姆", 1, 1, 6, NULL),
        Character("獸人", 6, 1, 1, NULL),
        Character("大青蛙", 3, 2, 3, NULL)
    };
    // 建立預設職業
    this->_jobList =
    {
        new MeleeJob("盜賊", 2, 0, 0),
        new MeleeJob("刺客", 3, 0, 0),
        new RemoteJob("獵人", 0, 2, 0),
        new RemoteJob("神射手", 0, 3, 0),
        new DefenseJob("戰士", 0, 0, 2),
        new DefenseJob("狂戰士", 0, 0, 3)
    };
}
// destructor
GameSystem::~GameSystem()
{
    // 清空 Job
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
        int input = GetNum(1, 7); // 輸入數字 1 ~ 7

        if (input == 7) return; // 離開遊戲

        Control(input);
    }
}
// 顯示選單
void GameSystem::PrintMenu()
{
    cout << "1. 創建角色" << endl;
    cout << "2. 角色作戰" << endl;
    cout << "3. 列出所有角色" << endl;
    cout << "4. 刪除角色" << endl;
    cout << "5. 新增職業" << endl;
    cout << "6. 刪除職業" << endl;
    cout << "7. 離開" << endl;
}
// 選擇功能
void GameSystem::Control(int input)
{
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
// string 轉 int，int的範圍須指定，不在範圍內或輸入錯誤回傳 -1
int GameSystem::StringToInt(string input, int min, int max)
{
    for (int i = min; i <= max; ++i)
    {
        if (input == to_string(i))
            return i;
    }

    return -1; // 輸入錯誤
}
// 取得正整數輸入，最小值(min)，最大值(max)需指定 //回傳 -1 表示輸入錯誤
int GameSystem::GetNum(int min, int max)
{
    string input;
    getline(cin, input);
    return StringToInt(input, min, max);
}
// 取得正整數輸入，最小值(min)，最大值(max)需指定 //需輸入到正確值為止
int GameSystem::GetNumUntilCorrect(int min, int max)
{
    string input;

    while (1)
    {
        getline(cin, input);
        int num = StringToInt(input, min, max);

        if (num != -1) return num;

        cout << "輸入錯誤，請輸入整數 " << min << " ~ " << max << "。請重新輸入 : ";
    }
}
// 輸入名字並檢查是否包含非法字元
string GameSystem::GetName()
{
    string name;

    while (1)
    {
        getline(cin, name);

        if (name[0] == '\0' || name[0] == ' ') // 不可為空白開頭
            cout << "第一個字元不可為空白";
        else if (name.size() > 32) // 最大長度32位元
            cout << "名字過長，最多32位";
        else if (name.find_first_of("\\/:*?\"<>|") != string::npos) // 檢查是否含有非法字元
            cout << "名字中不可帶有非法字元";
        else
            return name;

        cout << "，請重新輸入 : ";
    }
}
// 從現有職業列表中，把符合選定的職業種類以 pointer 方式放進一個新的 vector 供玩家選擇。
void GameSystem::PushSpecificJobList(vector<Job*>& specificJobList, Job::JobType jobType)
{
    size_t size = this->_jobList.size();

    for (unsigned int i = 0; i < size; ++i)
    {
        if (this->_jobList[i]->GetJobType() == jobType)
            specificJobList.push_back(this->_jobList[i]);
    }
}
// 顯示容器中之職業名
void GameSystem::ShowJobName(const vector<Job*>& jobList)
{
    size_t size = jobList.size();

    for (unsigned int i = 0; i < size; ++i)
    {
        cout << i + 1 << ". " << jobList[i]->GetName() << endl;
    }
}
// 顯示所有可選的職業種類
void GameSystem::ShowAllJobTypeName()
{
    cout << "1. 近距離攻擊系" << endl;
    cout << "2. 遠距離攻擊系" << endl;
    cout << "3. 防禦系" << endl;
}
// 創建角色
void GameSystem::CreateCharacter()
{
    if (this->_charactersList.size() == CHARACTER_MAX)
    {   // 角色數量達上限 (5)
        cout << "角色數量已達上限。" << endl << endl;
        return;
    }

    // 指定名字
    cout << endl << "請輸入角色名稱 : ";
    string name = GetName(); // name
    // 指定屬性
    int str(1), dex(1), con(1);
    DistributeAttributePoints(5, str, dex, con, 0, 0, 0);
    // 指定職業種類
    cout << endl << "請選擇職業種類 :" << endl << endl;
    ShowAllJobTypeName();
    Job::JobType jobType = (Job::JobType)(GetNumUntilCorrect(1, 3) - 1);
    // 產生選定之職業列表
    vector<Job*> specificJob;
    PushSpecificJobList(specificJob, jobType);
    // 指定職業
    cout << "請選擇職業 : " << endl;
    ShowJobName(specificJob);
    Job* job = specificJob[GetNumUntilCorrect(1, specificJob.size()) - 1];
    // 建構並加入堆疊
    this->_charactersList.push_back(Character(name, str, dex, con, job));
    cout << "創建成功!" << endl << endl << endl;
    // 輸出角色資料
    cout << this->_charactersList.back().GetInformation() << endl;
}
// 分配屬性點數
void GameSystem::DistributeAttributePoints(int point, int& str, int& dex, int& con, int extraStr, int extraDex, int extraCon)
{
    // 職業所增加的能力，大於零輸出 "+value"，否則為空字串(不輸出)。
    const string extraStrString = extraStr > 0 ? "+" + to_string(extraStr) : "";
    const string extraDexString = extraDex > 0 ? "+" + to_string(extraDex) : "";
    const string extraConString = extraCon > 0 ? "+" + to_string(extraCon) : "";

    while (point)
    {
        // 顯示選單
        cout << endl << "1. 目前STR : " << str << extraStrString << endl;
        cout << "2. 目前DEX : " << dex << extraDexString << endl;
        cout << "3. 目前CON : " << con << extraConString << endl;
        cout << "目前剩餘點數 : " << point << endl;
        cout << "請選擇欲增加之屬性 : ";

        // 選擇屬性
        switch (GetNum(1, 3)) // 輸入1 ~ 3
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
// 從怪物列表選擇隨機怪物並從職業列表隨機選擇作為怪物之職業
Character GameSystem::CreateRandomMonster(int level)
{
    Character monster = this->_monstersList[rand() % MONSTERS_NUM];
    monster.SetAttributes(monster.GetStr() + level - 1, monster.GetDex() + level - 1, monster.GetCon() + level - 1);
    monster.SetJob(this->_jobList[rand() % this->_jobList.size()]);
    return monster;
}
// 打贏怪物後增加經驗和等級
void GameSystem::CharacterGetExpAndLevel(Character& character)
{
    if (character.IsFullLevel()) return;

    character.AddExp(100);

    if (character.IsFullExp())
    {   // 角色升級，分配屬性
        cout << "角色升級了 ~ 獲得新的 3 點點數 可以分到當前屬性上 : " << endl;
        int str(character.GetStr()), dex(character.GetDex()), con(character.GetCon());
        DistributeAttributePoints(3, str, dex, con, character.GetExtraStr(), character.GetExtraDex(), character.GetExtraCon());
        character.SetAttributes(str, dex, con);
        character.LevelUp();
        cout << "配點完成 ! " << character.GetName() << "目前的等級達到" << character.GetLevel() << "。" << endl << endl;
        cout << character.GetInformation() << endl;
    }
}
// 角色作戰
void GameSystem::CharacterFight()
{
    if (this->_charactersList.empty())
    {
        cout << "你沒有任何角色，請先創建角色。" << endl << endl;
        return;
    }

    // 選擇角色
    ShowAllCharactersName();
    cout << "0. 返回選單" << endl;
    cout << "請選擇角色進行作戰 : ";
    int characterId = GetNumUntilCorrect(0, this->_charactersList.size()) - 1;

    if (characterId == -1)
    {   // 返回選單
        cout << endl << "不進行戰鬥，返回選單。" << endl << endl;
        return;
    }

    Character& player = this->_charactersList[characterId];
    string fightInfo(""); // 儲存戰鬥資訊
    // 開始戰鬥
    bool fightResult = player.Fight(CreateRandomMonster(player.GetLevel()), fightInfo);
    cout << endl << fightInfo << endl;

    if (fightResult) // 贏
        CharacterGetExpAndLevel(player); // 增加經驗和等級
    else // 輸
        player.AddFailFightTimes(); //增加戰鬥失敗次數
}
// 顯示所有角色名
void GameSystem::ShowAllCharactersName()
{
    size_t num = _charactersList.size();
    cout << endl;

    for (unsigned int i = 0; i < num; ++i)
    {
        cout << i + 1 << ". " << _charactersList[i].GetName() << endl;
    }
}
// 顯示所有角色資料
void GameSystem::ShowAllCharacters()
{
    if (this->_charactersList.empty())
    {
        cout << "你沒有任何角色，請先創建角色。" << endl << endl;
        return;
    }

    size_t num = this->_charactersList.size();

    for (unsigned int i = 0; i < num; ++i)
    {
        cout << "------------------------------" << endl;
        cout << this->_charactersList[i].GetInformation() << endl;
    }
}
// 顯示所有職業名稱
void GameSystem::ShowAllJobName()
{
    size_t num = this->_jobList.size();
    cout << endl;

    for (unsigned int i = 0; i < num; i++)
    {
        cout << i + 1 << ". " << this->_jobList[i]->GetName() << endl;
    }
}
// 刪除角色
void GameSystem::DeleteCharacter()
{
    if (this->_charactersList.empty())
    {   // 返回選單
        cout << "你沒有任何角色，請先創建角色。" << endl << endl;
        return;
    }

    // 選擇角色
    ShowAllCharactersName();
    cout << "0. 返回選單" << endl;
    cout << "請選擇角色 : ";
    int id = GetNumUntilCorrect(0, this->_charactersList.size()) - 1;

    if (id == -1)
    {   // 不刪除，返回選單，
        cout << endl << "不刪除角色，返回選單。" << endl << endl;
        return;
    }

    // 刪除
    cout << "已刪除角色 : " << this->_charactersList[id].GetName() << "。" << endl << endl;
    this->_charactersList.erase(this->_charactersList.begin() + id);
}
// 檢查職業名稱是否重複
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
// 取得職業名稱並檢查錯誤
string GameSystem::GetJobName()
{
    string name;

    while (1)
    {
        getline(cin, name);

        if (name[0] == '\0' || name[0] == ' ') // 不可為空白開頭
            cout << "第一個字元不可為空白";
        else if (name.size() > 32) // 最大長度32位元
            cout << "名字過長，最多32位";
        else if (name.find_first_of("\\/:*?\"<>| ") != string::npos) // 不可含有非法字元
            cout << "名字中不可帶有非法字元";
        else if (JobNameIsReaped(name))
            cout << "名稱重複"; // 名稱不可重複
        else
            return name;

        cout << "，請重新輸入 : ";
    }
}
// 設定職業之屬性加成
void GameSystem::AssignExtraAttributes(int& extraStr, int& extraDex, int& extraCon)
{
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
// 創建指定的職業類別
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
// 新增職業
void GameSystem::AppendJob()
{
    if (this->_jobList.size() == JOB_MAX)
    {   // full (20)
        cout << "職業數量已達上限" << endl;
        return;
    }

    // 指定職業種類
    cout << endl << "請選擇職業種類" << endl << endl;
    ShowAllJobTypeName();
    Job::JobType jobType = (Job::JobType)(GetNumUntilCorrect(1, 3) - 1);
    // 指定職業名
    cout << endl << "請輸入職業名稱 : ";
    string name = GetJobName(); // job name
    // 指定屬性加成
    int extraStr(0), extraDex(0), extraCon(0); // job attribute
    AssignExtraAttributes(extraStr, extraDex, extraCon);
    // 建構並加到列表
    this->_jobList.push_back(CreateSpecificJob(name, extraStr, extraDex, extraCon, jobType));
    cout << "新增職業 " << this->_jobList.back()->GetName() << " 成功!" << endl << endl;
}
// 檢查職業是否有角色正在使用
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
// 檢查是否為該職業類別的最後一個
bool GameSystem::IsTheLastJobOfTheJobType(Job* job)
{
    size_t size = this->_jobList.size();
    Job::JobType jobType = job->GetJobType();

    for (unsigned int i = 0; i < size; ++i)
    {   // 職業類別相同但記憶體位置不同回傳 false
        if (this->_jobList[i]->GetJobType() == jobType && this->_jobList[i] != job)
            return false;
    }

    return true;
}
// 取得要刪除的職業之 index
int GameSystem::GetDeleteJobIndex()
{
    while (1)
    {
        int jobId = GetNumUntilCorrect(0, this->_jobList.size()) - 1;

        if (jobId == -1)
            return -1; // 回傳 -1 使用者不刪除職業返回選單
        else if (this->_jobList.size() == Job::JOB_TYPE_NUM)
            return -2; // 回傳 -2 職業剩存 3 個不可再刪除
        else if (JobIsInUse(this->_jobList[jobId]))
            cout << "這個職業尚有角色，不可刪除。請重新輸入 : "; // 職業被角色使用不可刪除
        else if (IsTheLastJobOfTheJobType(this->_jobList[jobId]))
            cout << "該系職業剩下一個職業，不可刪除。請重新輸入 : "; // 該系最後職業無法刪除
        else
            return jobId;
    }
}
// 刪除職業
void GameSystem::DeleteJob()
{
    // 選擇職業
    ShowAllJobName();
    cout << "0. 返回選單" << endl;
    cout << "請選擇職業 : ";
    int jobId = GetDeleteJobIndex();

    if (jobId == -1)
    {   // 返回選單
        cout << endl << "不刪除職業，返回選單。" << endl << endl;
        return;
    }
    else if (jobId == -2)
    {   // 各系僅存一職業無法刪除
        cout << "各系皆只剩下一個職業，無法再刪除。" << endl << endl;
        return;
    }

    //刪除職業
    cout << "已刪除職業 : " << this->_jobList[jobId]->GetName() << "。" << endl << endl;
    delete this->_jobList[jobId];
    this->_jobList.erase(this->_jobList.begin() + jobId);
}