//資工二 105590036 黃俊維 HW2
//翻牌記憶遊戲
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void Swap(int& a, int& b)
{   //交換兩值
    int temp = a;
    a = b;
    b = temp;
}

void Shuffles(int(&cards)[4][4])
{   //洗牌 : 隨機兩兩交換
    srand((unsigned int)time(0));

    for (int i = 0; i < 20; i++)
    {
        Swap(cards[rand() % 4][rand() % 4], cards[rand() % 4][rand() % 4]);
    }
}

bool IsGameOver(bool(&display)[4][4])
{   //偵測是否全部翻開
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (!display[i][j])
                return false;
        }
    }

    return true;
}

bool Conversion(string in, int(&coordinate)[2])
{   //檢查輸入格式正確並轉換為座標
    if (!(in[0] == '(' && in[1] >= '1' && in[1] <= '4' && in[2] == ',' && in[3] >= '1' && in[3] <= '4' && in[4] == ')' && in[5] == '\0'))
        return false;

    coordinate[0] = in[1] - '1';
    coordinate[1] = in[3] - '1';
    return true;
}

bool Input(int(&coordinate)[2][2])
{   //輸入
    string in("INPUT");

    for (int i = 0; i < 2; i++)
    {
        cout << "Please enter the coordinate" << i + 1 << " : ";
        getline(cin, in);

        if (!Conversion(in, coordinate[i]))
        {
            cout << "請輸入正確格式。如: (1,2)。1<=x<=4，1<=y<=4。" << endl;
            return false;
        }
    }

    return true;
}

bool IsMatch(int(&cards)[4][4], int(&coordinate)[2][2])
{   //是否match
    if (cards[coordinate[0][0]][coordinate[0][1]] == cards[coordinate[1][0]][coordinate[1][1]])
        return true;

    return false;
}

void Output(int(&cards)[4][4], bool(&display)[4][4], int(&coordinate)[2][2], bool match)
{   //輸出是否match
    if (match)
        cout << endl << "(" << coordinate[0][0] + 1 << "," << coordinate[0][1] + 1 << ") (" << coordinate[1][0] + 1 << "," << coordinate[1][1] + 1 << ")"
             << " is Match!" << endl << endl;
    else
        cout << endl << "(" << coordinate[0][0] + 1 << "," << coordinate[0][1] + 1 << ") (" << coordinate[1][0] + 1 << "," << coordinate[1][1] + 1 << ")"
             << " is not Match!" << endl << endl;

    //輸出4*4之遊戲畫面
    cout << "           [1]    [2]    [3]    [4]" << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << "[" << i + 1 << "]        ";

        for (int j = 0; j < 4; j++)
        {
            if (display[i][j] || i == coordinate[0][0] && j == coordinate[0][1] || i == coordinate[1][0] && j == coordinate[1][1])
                cout << " " << cards[i][j] << "     ";
            else
                cout << " *     ";
        }

        cout << endl;
    }
}

int main()
{
    int cards[4][4] = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8 };
    bool display[4][4] = { false }, match, last_match = true;
    int coordinate[2][2];
    Shuffles(cards); //洗牌

    while (!IsGameOver(display)) //是否全部翻開
    {
        while (!Input(coordinate)); //輸入到取得兩筆有效座標為止

        match = IsMatch(cards, coordinate); //儲存本局match之結果

        if (!last_match) //若上一局match失敗 輸出50行空白
        {
            for (int i = 0; i < 50; i++)
            {
                cout << endl;
            }
        }

        Output(cards, display, coordinate, match); //輸出match結果及遊戲畫面

        if (match) //若match成功 永久翻開兩張牌
            display[coordinate[0][0]][coordinate[0][1]] = display[coordinate[1][0]][coordinate[1][1]] = true;

        last_match = match; //儲存此次match結果
    }

    cout << "Game over." << endl << "You win!" << endl; //遊戲結束
    system("pause");
    return 0;
}