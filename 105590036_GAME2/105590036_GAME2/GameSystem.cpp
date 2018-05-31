#include "GameSystem.h"

GameSystem::GameSystem()
{   // create monster data
    this->_monstersList =
    {
        { "哥布林", 1, 6, 1 },
        { "史萊姆", 1, 1, 6 },
        { "獸人", 6, 1, 1 },
        { "大青蛙", 3, 2, 3 }
    };
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
void GameSystem::Start()
{   // run
    srand((unsigned)time(0));

    while (1)
    {
        PrintMenu();

        switch (GetNum(1, 5)) // input number 1 to 5
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

            case 5: // 離開
                return;

            default:
                cout << "輸入錯誤，請輸入整數 1 ~ 5 。" << endl << endl;
        }
    }
}
void GameSystem::PrintMenu()
{   // UI
    cout << "1. 創建角色" << endl;
    cout << "2. 角色作戰" << endl;
    cout << "3. 列出所有角色" << endl;
    cout << "4. 刪除角色" << endl;
    cout << "5. 離開" << endl;
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
string GameSystem::GetName()
{   // 輸入名字並檢查
    cout << "請輸入角色名稱 : ";
    string name;

    while (1)
    {
        getline(cin, name);

        if (name == "\0" || name[0] == ' ') // 第一個字元不可為空白
            cout << "第一個字元不可為空白，" << endl;
        else if (name.find_first_of("\\/:*?\"<>|") != string::npos) // 名字中不可帶有以下字元 \/:*?\"<>|
            cout << "名字中不可帶有以下字元 \\/:*?\"<>|" << endl;
        else
            return name;

        cout << "請重新輸入 : ";
    }
}
void GameSystem::CreateCharacter()
{   // create character
    if (FullCharacter()) return; // full

    string name = GetName(); // name
    int str(1), dex(1), con(1);
    DistributeAttributes(5, str, dex, con); // 指定屬性
    this->_charactersList.push_back(Character(name, str, dex, con)); // 建構並加到堆疊
    cout << "創建成功!" << endl << endl << endl;
    cout << this->_charactersList.back().GetInformation() << endl; // output character's info
}
void GameSystem::DistributeAttributes(int point, int& str, int& dex, int& con)
{
    while (point)
    {   // UI
        cout << endl << "1. 目前STR : " << str << endl;
        cout << "2. 目前DEX : " << dex << endl;
        cout << "3. 目前CON : " << con << endl;
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

            default: // error input
                cout << "輸入錯誤，請輸入整數 1 ~ 3" << endl;
        }
    }
}
int GameSystem::ChooseCharacter()
{   // print all character name, check input format and return character id, return -1 means back to the menu.
    int num = this->_charactersList.size();
    int characterId;
    ShowAllCharactersName();
    cout << "0. 返回選單" << endl;
    cout << "請選擇角色 : ";

    while ((characterId = GetNum(0, num)) == -1) // 選擇角色
    {
        cout << "輸入錯誤，請輸入整數0~" << num << endl;
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
    cout << "角色升級了 ~ 獲得新的 3 點點數 可以分到當前屬性上 : " << endl;
    int str = character.GetStr();
    int dex = character.GetDex();
    int con = character.GetCon();
    DistributeAttributes(3, str, dex, con);
    cout << "配點完成 ! " << character.GetName() << "目前的等級達到" << character.LevelUp(str, dex, con) << "。" << endl << endl;
    cout << character.GetInformation() << endl;
}
void GameSystem::CharacterFight()
{   // choose a character and fight random monater
    if (NoCharacter()) return;

    int characterId = ChooseCharacter();

    if (characterId == -1)
    {
        cout << endl << "不進行戰鬥，返回選單。" << endl << endl;
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
        cout << endl << "不刪除角色，返回選單。" << endl << endl;
        return;
    }

    cout << "已刪除角色 : " << this->_charactersList[id].GetName() << "。" << endl << endl;
    this->_charactersList.erase(this->_charactersList.begin() + id);
}