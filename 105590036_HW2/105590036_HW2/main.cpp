//��u�G 105590036 ���T�� HW2
//½�P�O�йC��
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void Swap(int& a, int& b)
{   //�洫���
    int temp = a;
    a = b;
    b = temp;
}

void Shuffles(int(&cards)[4][4])
{   //�~�P : �H�����洫
    srand((unsigned int)time(0));

    for (int i = 0; i < 20; i++)
    {
        Swap(cards[rand() % 4][rand() % 4], cards[rand() % 4][rand() % 4]);
    }
}

bool IsGameOver(bool(&display)[4][4])
{   //�����O�_����½�}
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
{   //�ˬd��J�榡���T���ഫ���y��
    if (!(in[0] == '(' && in[1] >= '1' && in[1] <= '4' && in[2] == ',' && in[3] >= '1' && in[3] <= '4' && in[4] == ')' && in[5] == '\0'))
        return false;

    coordinate[0] = in[1] - '1';
    coordinate[1] = in[3] - '1';
    return true;
}

bool Input(int(&coordinate)[2][2])
{   //��J
    string in("INPUT");

    for (int i = 0; i < 2; i++)
    {
        cout << "Please enter the coordinate" << i + 1 << " : ";
        getline(cin, in);

        if (!Conversion(in, coordinate[i]))
        {
            cout << "�п�J���T�榡�C�p: (1,2)�C1<=x<=4�A1<=y<=4�C" << endl;
            return false;
        }
    }

    return true;
}

bool IsMatch(int(&cards)[4][4], int(&coordinate)[2][2])
{   //�O�_match
    if (cards[coordinate[0][0]][coordinate[0][1]] == cards[coordinate[1][0]][coordinate[1][1]])
        return true;

    return false;
}

void Output(int(&cards)[4][4], bool(&display)[4][4], int(&coordinate)[2][2], bool match)
{   //��X�O�_match
    if (match)
        cout << endl << "(" << coordinate[0][0] + 1 << "," << coordinate[0][1] + 1 << ") (" << coordinate[1][0] + 1 << "," << coordinate[1][1] + 1 << ")"
             << " is Match!" << endl << endl;
    else
        cout << endl << "(" << coordinate[0][0] + 1 << "," << coordinate[0][1] + 1 << ") (" << coordinate[1][0] + 1 << "," << coordinate[1][1] + 1 << ")"
             << " is not Match!" << endl << endl;

    //��X4*4���C���e��
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
    Shuffles(cards); //�~�P

    while (!IsGameOver(display)) //�O�_����½�}
    {
        while (!Input(coordinate)); //��J����o�ⵧ���Įy�Ь���

        match = IsMatch(cards, coordinate); //�x�s����match�����G

        if (!last_match) //�Y�W�@��match���� ��X50��ť�
        {
            for (int i = 0; i < 50; i++)
            {
                cout << endl;
            }
        }

        Output(cards, display, coordinate, match); //��Xmatch���G�ιC���e��

        if (match) //�Ymatch���\ �ä[½�}��i�P
            display[coordinate[0][0]][coordinate[0][1]] = display[coordinate[1][0]][coordinate[1][1]] = true;

        last_match = match; //�x�s����match���G
    }

    cout << "Game over." << endl << "You win!" << endl; //�C������
    system("pause");
    return 0;
}