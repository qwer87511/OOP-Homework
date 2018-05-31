//105590036_HW6 資工二 黃俊維
//實作 operator overloading 做向量 dot product 運算
#include "Vector2D.h"
bool IsNum(string in, int len)
{   //檢查是否為數字
    if (!isdigit(in[0]) && in[0] != '-' || in[0] == '-' && !isdigit(in[1])) //第一個字元必為數字或負號，若為負號，第二個字元必為數字
        return false;

    for (int i = 1; i < len; ++i)
    {
        if (!isdigit(in[i])) //非數字回傳 false
            return false;
    }

    return true;
}
bool IsInt(string in)
{
    string int_max(to_string(INT_MAX));
    string int_min(to_string(INT_MIN));

    if (in[0] != '-')
    {
        if (in.size() < int_max.size() || in.size() == int_max.size() && in <= int_max)
            return true;
    }
    else
    {
        if (in.size() < int_min.size() || in.size() == int_min.size() && in <= int_min)
            return true;
    }

    return false;
}
bool isVector(string in, string& x, string& y)
{
    int len = in.size(); //長度
    int cut = in.find(','); //逗號位置(切割點)

    if (in[0] != '(' || in[len - 1] != ')') //無前後括號 //錯誤
    {
        cout << "向量前後需有'('和')'" << endl;
        return false;
    }
    else if (cut == -1) //無逗號 //錯誤
    {
        cout << "X,Y之間沒有','" << endl;
        return false; //(1,2)
    }

    x.assign(in, 1, cut - 1); //指定逗號前的資料給X
    y.assign(in, cut + 1, len - cut - 2); //指定逗號後的資料給Y

    if (!IsNum(x, cut - 1) || !IsNum(y, len - cut - 2)) //非數字 //錯誤
    {
        cout << "X,Y請輸入數字" << endl;
        return false;
    }
    else if (!IsInt(x) || !IsInt(y)) //不在int的儲存範圍 //錯誤
    {
        cout << "X,Y的值無效，須在 " << INT_MAX << " ~ " << INT_MIN << " 之間" << endl;
        return false;
    }

    return true;
}
void GetVectorData(int& vectorX,int& vectorY)
{
    string in, x, y;

    while (1)
    {
        getline(cin, in);

        if (in == "Exit") //EXIT
        {
            system("pause");
            exit(0);
        }

        if (isVector(in, x, y)) break; //判斷是否為向量，並將資料轉為兩組字串(x,y)

        cout << "Please input again :";
    }

    vectorX = stoi(x);
    vectorY = stoi(y);
}
int main()
{
    int vectorX, vectorY;

    while (1)
    {
        cout << "Please input vectorA: ";
        GetVectorData(vectorX, vectorY); //get vectorA
        Vector2D vectorA(vectorX, vectorY); //construct
        cout << "Please input vectorB: ";
        GetVectorData(vectorX, vectorY); //get vectorB
        Vector2D vectorB(vectorX, vectorY);
        // output
        cout << endl << "vectorA = (" << vectorA.GetX() << "," << vectorA.GetY() << ") ";
        cout << "vectorB = (" << vectorB.GetX() << "," << vectorB.GetY() << ")" << endl;
        cout << "vectorA * vectorB = " << vectorA* vectorB << endl << endl << endl;
    }

    system("pause");
    return 0;
}