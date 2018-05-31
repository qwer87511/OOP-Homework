/*#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Schedule
{
    public:
        static const int PERIOD  = 9;
        static const int DAY = 5;
        static const int WIDTH = 5;
        Schedule();
        void Show();
        void put(int, int, string);
    private:

        string schedule[PERIOD][DAY];
};
Schedule::Schedule()
{
    for (int i = 0; i < PERIOD; ++i)
        for (int j = 0; j < DAY; ++j)
            schedule[i][j] = "none";
}
void Schedule::put(int x, int y, string name)
{
    schedule[x][y] = name;
}
void Schedule::Show()
{
    cout << setw(WIDTH) << "";

    for (int i = 0; i < DAY; ++i)
    {
        cout << setw(WIDTH) << i + 1;
    }

    cout << endl;

    for (int i = 0; i < PERIOD; ++i)
    {
        cout << setw(WIDTH) << i + 1;

        for (int j = 0; j < DAY; ++j)
        {
            cout << setw(WIDTH) << schedule[i][j];
        }

        cout << endl;
    }
}
const string CH_NUM = "零一二三四五";
int main()
{
    Schedule schedule;
    string input; // 二(1,5)
    int in;

    while (1)
    {
        cout << ">> ";
        getline(cin, input);

        if (input == "")
            schedule.Show();
        else
        {
            cout << (int)input[0];
            int day = CH_NUM.find(input[0]);

            for (int index = 3; input[index] != ')'; index += 2)
            {
                schedule.put(input[index] - '1', day - 1, "O");
            }
        }
    }

    system("pause");
}
/*
// 以下是 0.00390625 二進位表示(IEEE 754)
char* str = "0011111101110000000000000000000000000000000000000000000000000000";
double b = 0;
uint64_t* ptr = (uint64_t*)&b;
int i;

for (i = 0; i <= 63; ++i) {
    *ptr |= ((uint64_t)1 << (63 - i)) * (str[i] - '0');
}

printf("%.*f\n", DBL_DIG, b);*/