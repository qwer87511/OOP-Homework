#include "Matrix.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    Matrix m1,m2;
    m1.GetMatrix();
    m2.GetMatrix();
    //m.GaussianElimination();
    //m.ReverseGaussianElimination();
    (m1 + m2).Show();
    system("pause");
}
/*
2 4 -2 2
4 9 -3 8
-2 -3 7 10
2 4 -2
4 9 -3
-2 -3 7
*/