#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES 1
#include <stdio.h>
#include <iostream>
#include <string>
#include <bitset>
using namespace std;
#define LOGIC_SIZE 8

void CLA(bitset<LOGIC_SIZE> b1, bitset<LOGIC_SIZE> b2, bitset<LOGIC_SIZE> res)
{
    //bitset<RESULT_SIZE> g = b1 & b2;
}
int main()
{
    int a;
    scanf("%d", &a);
    string in;
    getline(cin, in);
    bitset<LOGIC_SIZE> b1(in);
    getline(cin, in);
    bitset<LOGIC_SIZE> b2(in);
    bitset<LOGIC_SIZE> res;
    CLA(b1, b2, res);
    cout << res;
    system("pause");
}