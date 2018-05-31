#include "Matrix.h"

Matrix<int> GetM()
{
    Matrix<int> m(2,2);
    cin >> m;
    return m;
}

void TestCopy()
{
    Matrix<int> m2=GetM();
    cout << m2 << endl;
    Matrix<int> m3;
    m3 = m2;
    m3 += m2;
    cout << m3;
}
void TestOperatorMult()
{
    Matrix<int> m1 = GetM();
    Matrix<int> m2 = GetM();
    //m1 *= m2;
    //cout << m1;
    Matrix<int> m3(m1 * m2);
    m3 = m1 * m2;
    cout << m3;
}

/*int main()
{
    //TestCopy();
    TestOperatorMult();
    system("pause");
    return 0;
}*/
/*
2 4
0 1
0 2
4 9
*/
