// 資工二 105590036 張哲源 HW7
// RPG 遊戲
#include "Character.h"
bool IsCorrectName(string name)
{
    if (name == "\0" || name[0] == ' ') cout << "不可為空白" << endl;
    else if (name.find_first_of("\\/:*?\"<>|") != string::npos) cout << "含有不合法符號" << endl;
    else return true;

    return false;
}
string GetName()
{
    cout << "請輸入角色名稱 : ";
    string name;

    while (1)
    {
        getline(cin, name);

        if (IsCorrectName(name))return name;
        else cout << "請重新輸入 : ";
    }
}

int InputNumber(int max)
{
    string input;
    getline(cin, input);

    if (input[0] - '0' >= 0 && input[0] - '0' <= max && input[1] == '\0')
        return input[0] - '0';

    return -1;
}

void Assign(int& str, int& dex, int& con)
{
    for (int point = 5; point;)
    {
        cout << endl << "1. 目前STR : " << str << endl;
        cout << "2. 目前DEX : " << dex << endl;
        cout << "3. 目前CON : " << con << endl;
        cout << "目前剩餘點數 : " << point << endl;
        cout << "請選擇欲增加之屬性 : ";
        int choose = InputNumber(3);

        if (choose == 1)
        {
            ++str;
            --point;
        }
        else if (choose == 2)
        {
            ++str;
            --point;
        }
        else if (choose == 3)
        {
            ++str;
            --point;
        }
        else
            cout << "輸入錯誤，請輸入 1 ~ 3" << endl;
    }
}

int GetAction()
{
    while (1)
    {
        cout << "1. 創建角色" << endl;
        cout << "2. 角色作戰" << endl;
        cout << "3. 列出所有角色" << endl;
        cout << "4. 離開" << endl;
        int ins = InputNumber(4);

        if (ins != -1) return ins;

        cout << "輸入錯誤，請輸入1~4" << endl << endl;
    }
}

void Create(vector<Character>& characters)
{
    string name = GetName();
    int str(1), dex(1), con(1);
    Assign(str, dex, con);
    Character newCharacter(name, str, dex, con);
    characters.push_back(newCharacter);
    cout << newCharacter.GetInformation();
    cout << "創建成功!" << endl << endl;
}

void ShowAllCharactersName(vector<Character> characters)
{
    const int size = characters.size();

    for (int i = 0; i < size; i++)
    {
        cout << endl << i + 1 << ". " << characters[i].GetName();
    }
}

void LetFight(vector<Character>& characters, Character monsters[])
{
    int cap = characters.size();

    if (cap == 0)
    {
        cout << "請先創建角色" << endl << endl;
        return;
    }

    ShowAllCharactersName(characters);
    int who;
    int MonsterId = rand() % 4;
    cout << endl << "請選擇角色進行作戰 : ";

    while ((who = InputNumber(cap) - 1) == -2) cout << "輸入錯誤" << who << endl;

    if (characters[who].Fight(monsters[MonsterId]))
    {
        cout << monsters[MonsterId].GetName() << "倒下了 ! 獲勝的是 : " << characters[who].GetName() << endl << endl;
        characters[who].AddExp(100);
    }
    else
    {
        cout << characters[who].GetName() << "倒下了 ! 獲勝的是 : " << monsters[MonsterId].GetName() << endl << endl;
        characters[who].AddFailFightTimes();
    }
}

int main()
{
    vector<Character> characters;
    Character monsters[4] =
    {
        { "哥布林", 1, 6, 1 },
        { "史萊姆", 1, 1, 6 },
        { "獸人", 6, 1, 1 },
        { "大青蛙", 3, 2, 3 }
    };
    srand((unsigned int)time(0));

    while (1)
    {
        int ins = GetAction();

        if (ins == 1)
        {
            if (characters.size() == 5)
                cout << "角色數量已達上限" << endl << endl;
            else
                Create(characters);
        }
        else if (ins == 2)
            LetFight(characters, monsters);
        else if (ins == 3)
        {
            cout << endl;
            int amount = characters.size();

            if (amount == 0)
                cout << "你沒有創建角色" << endl;
            else
            {
                for (int i = 0; i < amount; i++)
                {
                    cout << characters[i].GetInformation();
                }
            }
        }
        else if (ins == 4)
            break;
    }

    system("PAUSE");
    return 0;
}