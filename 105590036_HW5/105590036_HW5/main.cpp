//105590036_HW5 資工二 黃俊維
//利用vector及其函式做陣列存取 類似定時炸彈遊戲找出唯一生還者
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool IsNum(string in)
{   //檢查是否為數字
    if (!isdigit(in[0])) //第一個字元必定要為數字
        return false;
    else if (in.find_first_not_of("0123456789") != string::npos)
        return false;
    else
        return true;
}
int GetNum()
{   //以字串讀取輸入
    string in("\0");
    cout << "How many suitors are there?" << endl;

    while (1)
    {
        getline(cin, in);

        if (IsNum(in)) return stoi(in); //確定為數字轉為int回傳
        else cout << "Wrong input. Please input again:" << endl;
    }
}
int LuckyNumber(int num)
{
    vector<int> suitors(num); //建立大小為n的陣列

    for (int i = 0; i < num; i++) //依序放入1~n的數字
        suitors[i] = i + 1;

    int pos = 0; //初始位置為0
    int len; //長度

    while ((len = suitors.size()) >= 2)
    {
        pos = (pos + 2) % len; //每次執行位置都會變成下兩個位置 erase會push陣列後的資料 所以pos的位置會自動落在下一個人身上
        suitors.erase(suitors.begin() + pos);//清除該位置並將後面往前push
    }

    return suitors[0];
}
int main()
{
    while (1)
    {
        int num = GetNum();

        if (num == 0) return 0; //0結束程式

        cout << endl << "The lucky winner is.... Number "
             << LuckyNumber(num) << " !" << endl << endl;
    }
}