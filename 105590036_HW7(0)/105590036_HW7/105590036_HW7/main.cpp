// 資工二 105590036 黃俊維 HW7
// class 宣告人物，實作 RPG 遊戲
#include "Character.h"

int GetNum(int max) // 此function用於取得正整數輸入，最小為1，最大值(max)可自行設定 //回傳-1表示輸入錯誤
{
    string input;
    getline(cin, input);

    for (int i = 1; i <= max; ++i)
    {
        if (input == to_string(i)) return i;
    }

    return -1; // 輸入錯誤，請輸入整數1~max
}
int GetIns()
{
    while (1)
    {   // UI
        cout << "1. 創建角色" << endl;
        cout << "2. 角色作戰" << endl;
        cout << "3. 列出所有角色" << endl;
        cout << "4. 離開" << endl;
        int ins = GetNum(4); // 輸入1~4

        if (ins != -1) return ins; // 沒有錯誤才回傳

        cout << "輸入錯誤，請輸入整數 1 ~ 4" << endl << endl;
    }
}
string GetName()
{
    cout << "請輸入角色名稱 : ";
    string name;

    while (true)
    {
        getline(cin, name);

        if (name == "\0" || name[0] == ' ') // 第一個字元不可為空白
            cout << "第一個字元不可為空白，" << endl << "請重新輸入 : ";
        else if (name.find_first_of("\\/:*?\"<>|") != string::npos) // 名字中不可帶有以下字元 \/:*?\"<>|
            cout << "名字中不可帶有以下字元 \\/:*?\"<>|" << endl << "請重新輸入 : ";
        else
            return name;
    }
}
void AssignAttributes(int& str, int& dex, int& con)
{
    for (int point = 5; point;)
    {   // UI
        cout << endl << "1. 目前STR : " << str << endl;
        cout << "2. 目前DEX : " << dex << endl;
        cout << "3. 目前CON : " << con << endl;
        cout << "目前剩餘點數 : " << point << endl;
        cout << "請選擇欲增加之屬性 : ";

        switch (GetNum(3)) // 輸入數字1~3
        {
            case 1:
                ++str, --point; // 力量+1
                break;

            case 2:
                ++dex, --point; // 敏捷+1
                break;

            case 3:
                ++con, --point; // 體質+1
                break;

            default:
                cout << "輸入錯誤，請輸入整數 1 ~ 3" << endl;
        }
    }
}
void CreateCharacter(vector<Character>& characters)
{
    if (characters.size() == 5) // 超過上限 : 5
    {
        cout << "角色數量已達上限(5)" << endl << endl;
        return;
    }

    string name = GetName(); // 名字
    int str(1), dex(1), con(1);
    AssignAttributes(str, dex, con); // 指定屬性
    characters.push_back(Character(name, str, dex, con)); // 建構並加到堆疊
    cout << "創建成功!" << endl << endl << endl;
    cout << characters.back().GetInformation(); // 輸出資料
}
void ShowAllCharactersName(vector<Character>& characters)
{   // 輸出角色名字
    int num = characters.size();

    for (int i = 0; i < num; ++i)
    {
        cout << endl << i + 1 << ". " << characters[i].GetName();
    }
}
void LetFight(vector<Character>& characters, const Character monsters[])
{
    int num = characters.size();

    if (!num) // 沒有角色
    {
        cout << "請先創建角色" << endl << endl;
        return;
    }

    int characterId;
    int MonsterId = rand() % MONSTERS_NUM; // 用rand()呼叫亂數 並取除以MONSTER_NUM(4)的餘數
    ShowAllCharactersName(characters);
    cout << endl << "請選擇角色進行作戰 : ";

    while ((characterId = GetNum(num)) == -1) // 選擇角色
    {
        cout << "輸入錯誤，請輸入整數1~" << num << endl;
    }

    if (characters[--characterId].Fight(monsters[MonsterId])) // 選擇之角色呼叫fight，放入怪物的參數
    {   // win
        cout << monsters[MonsterId].GetName() << "倒下了 ! 獲勝的是 : " << characters[characterId].GetName() << endl << endl;
        characters[characterId].AddExp(100); // 經驗增加100
    }
    else
    {   // lose
        cout << characters[characterId].GetName() << "倒下了 ! 獲勝的是 : " << monsters[MonsterId].GetName() << endl << endl;
        characters[characterId].AddFailFightTimes(); // 失敗次數增加1
    }
}
void ShowAllCharacters(const vector<Character> characters)
{
    int num = characters.size();

    if (!num)
    {   // 沒有任何角色
        cout << "你沒有任何角色" << endl << endl;
        return;
    }

    for (int i = 0; i < num; ++i)
    {   // 顯示所有角色資料
        cout << "------------------------------" << endl;
        cout << characters[i].GetInformation();
    }
}

int main()
{
    srand((unsigned int)time(0)); // 重製亂數
    vector<Character> characters; // 所有角色資料之陣列
    const Character MONSTERS[MONSTERS_NUM] = // 怪物資料
    {
        { "哥布林", 1, 6, 1 },
        { "史萊姆", 1, 1, 6 },
        { "獸人", 6, 1, 1 },
        { "大青蛙", 3, 2, 3 }
    };

    while (1)
    {
        switch (GetIns()) // UI
        {
            case 1: // 建立角色
                CreateCharacter(characters);
                break;

            case 2: // 角色作戰
                LetFight(characters,MONSTERS);
                break;

            case 3: // 顯示所有角色
                ShowAllCharacters(characters);
                break;

            case 4: // EXIT
                system("pause");
                return 0;
        }
    }
}