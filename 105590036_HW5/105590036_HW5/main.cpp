//105590036_HW5 ��u�G ���T��
//�Q��vector�Ψ�禡���}�C�s�� �����w�ɬ��u�C����X�ߤ@���٪�
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool IsNum(string in)
{   //�ˬd�O�_���Ʀr
    if (!isdigit(in[0])) //�Ĥ@�Ӧr�����w�n���Ʀr
        return false;
    else if (in.find_first_not_of("0123456789") != string::npos)
        return false;
    else
        return true;
}
int GetNum()
{   //�H�r��Ū����J
    string in("\0");
    cout << "How many suitors are there?" << endl;

    while (1)
    {
        getline(cin, in);

        if (IsNum(in)) return stoi(in); //�T�w���Ʀr�ରint�^��
        else cout << "Wrong input. Please input again:" << endl;
    }
}
int LuckyNumber(int num)
{
    vector<int> suitors(num); //�إߤj�p��n���}�C

    for (int i = 0; i < num; i++) //�̧ǩ�J1~n���Ʀr
        suitors[i] = i + 1;

    int pos = 0; //��l��m��0
    int len; //����

    while ((len = suitors.size()) >= 2)
    {
        pos = (pos + 2) % len; //�C�������m���|�ܦ��U��Ӧ�m erase�|push�}�C�᪺��� �ҥHpos����m�|�۰ʸ��b�U�@�ӤH���W
        suitors.erase(suitors.begin() + pos);//�M���Ӧ�m�ñN�᭱���epush
    }

    return suitors[0];
}
int main()
{
    while (1)
    {
        int num = GetNum();

        if (num == 0) return 0; //0�����{��

        cout << endl << "The lucky winner is.... Number "
             << LuckyNumber(num) << " !" << endl << endl;
    }
}