//資工二 105590036 黃俊維 第1次作業
//此程式以身高計算理想體重
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool IsAlpha(char buffer[])
{
    if (!buffer[0]) return false; //沒有取得資料

    for (int i = 0; buffer[i]; i++)
    {
        if (!isalpha(buffer[i]) && buffer[i] != ' ')
            return false; //名字必須由英文或空格組成
    }

    return true;
}

bool IsNum(char buffer[])
{
    if (!buffer[0]) return false; //沒有取得資料

    for (int i = 0; buffer[i]; i++)
    {
        if (!isdigit(buffer[i]))
            return false; //必須為數字
    }

    return true;
}

bool ReadFile(fstream& file, string& name, int& feet, int& inch) {
    char buffer[100];
    file.getline(buffer, sizeof(buffer));

    if (!IsAlpha(buffer))
    {   //名字由英文或空白組成
        cout << "名字由英文或空白組成" << endl;
        return false;
    }

    name.assign(buffer);
    file.getline(buffer, sizeof(buffer));

    if (!IsNum(buffer))
    {   //由數字組成
        cout << "feet請輸入正整數" << endl;
        return false;
    }

    feet = stoi(buffer);
    file.getline(buffer, sizeof(buffer));

    if (!IsNum(buffer))
    {   //由數字組成
        cout << "inch請輸入正整數" << endl;
        return false;
    }

    inch = stoi(buffer);

    if (inch >= 12) return false;

    return true;
}
int IdealWeight(int feet, int inch)
{
    int idealWeight = 110;

    if (feet * 12 + inch > 60) idealWeight += (feet - 5) * 60 + inch * 5;

    return idealWeight;
}
int main()
{
    fstream file;
    file.open("weight.txt", ios::in);

    if (!file)
    {   //讀檔失敗
        cout << "read file fail" << endl;
        system("PAUSE");
        return -1;
    }

    while (!file.eof())
    {   //執行到資料尾
        string name("NAME");
        int feet, inch;

        if (!ReadFile(file, name, feet, inch))
        {   //資料格式有誤
            cout << "Input error." << endl << endl;
            break;
        }

        cout << name << endl;
        cout << "Hight: " << feet << " feet";

        if (inch) cout << " and " << inch << " inches";

        cout << endl << "Ideal Weight: " << IdealWeight(feet, inch) << " pounds" << endl << endl;
    }

    file.close();
    system("PAUSE");
    return 0;
}