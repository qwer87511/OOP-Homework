//��u�G 105590036 ���T�� ��1���@�~
//���{���H�����p��z�Q�魫
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool IsAlpha(char buffer[])
{
    if (!buffer[0]) return false; //�S�����o���

    for (int i = 0; buffer[i]; i++)
    {
        if (!isalpha(buffer[i]) && buffer[i] != ' ')
            return false; //�W�r�����ѭ^��ΪŮ�զ�
    }

    return true;
}

bool IsNum(char buffer[])
{
    if (!buffer[0]) return false; //�S�����o���

    for (int i = 0; buffer[i]; i++)
    {
        if (!isdigit(buffer[i]))
            return false; //�������Ʀr
    }

    return true;
}

bool ReadFile(fstream& file, string& name, int& feet, int& inch) {
    char buffer[100];
    file.getline(buffer, sizeof(buffer));

    if (!IsAlpha(buffer))
    {   //�W�r�ѭ^��Ϊťղզ�
        cout << "�W�r�ѭ^��Ϊťղզ�" << endl;
        return false;
    }

    name.assign(buffer);
    file.getline(buffer, sizeof(buffer));

    if (!IsNum(buffer))
    {   //�ѼƦr�զ�
        cout << "feet�п�J�����" << endl;
        return false;
    }

    feet = stoi(buffer);
    file.getline(buffer, sizeof(buffer));

    if (!IsNum(buffer))
    {   //�ѼƦr�զ�
        cout << "inch�п�J�����" << endl;
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
    {   //Ū�ɥ���
        cout << "read file fail" << endl;
        system("PAUSE");
        return -1;
    }

    while (!file.eof())
    {   //������Ƨ�
        string name("NAME");
        int feet, inch;

        if (!ReadFile(file, name, feet, inch))
        {   //��Ʈ榡���~
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