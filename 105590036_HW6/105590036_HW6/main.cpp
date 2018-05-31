//105590036_HW6 ��u�G ���T��
//��@ operator overloading ���V�q dot product �B��
#include "Vector2D.h"
bool IsNum(string in, int len)
{   //�ˬd�O�_���Ʀr
    if (!isdigit(in[0]) && in[0] != '-' || in[0] == '-' && !isdigit(in[1])) //�Ĥ@�Ӧr�������Ʀr�έt���A�Y���t���A�ĤG�Ӧr�������Ʀr
        return false;

    for (int i = 1; i < len; ++i)
    {
        if (!isdigit(in[i])) //�D�Ʀr�^�� false
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
    int len = in.size(); //����
    int cut = in.find(','); //�r����m(�����I)

    if (in[0] != '(' || in[len - 1] != ')') //�L�e��A�� //���~
    {
        cout << "�V�q�e��ݦ�'('�M')'" << endl;
        return false;
    }
    else if (cut == -1) //�L�r�� //���~
    {
        cout << "X,Y�����S��','" << endl;
        return false; //(1,2)
    }

    x.assign(in, 1, cut - 1); //���w�r���e����Ƶ�X
    y.assign(in, cut + 1, len - cut - 2); //���w�r���᪺��Ƶ�Y

    if (!IsNum(x, cut - 1) || !IsNum(y, len - cut - 2)) //�D�Ʀr //���~
    {
        cout << "X,Y�п�J�Ʀr" << endl;
        return false;
    }
    else if (!IsInt(x) || !IsInt(y)) //���bint���x�s�d�� //���~
    {
        cout << "X,Y���ȵL�ġA���b " << INT_MAX << " ~ " << INT_MIN << " ����" << endl;
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

        if (isVector(in, x, y)) break; //�P�_�O�_���V�q�A�ñN����ର��զr��(x,y)

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