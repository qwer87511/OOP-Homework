#include "Matrix.h"
#include "Fraction.h"
#include <string>
#include <vector>
int main()
{
    Fraction a(20), l(1), d(10);
    Fraction result((string)(((l + a) / Fraction(32)) * (l * a / Fraction(32)) + a) * a / Fraction(16) * (Fraction(1) - d / Fraction(512)));
    cout << (double)result;
    /*Matrix<Fraction> m1(3, 3), m2(3, 3), m3(3, 3);
    cin >> m1 >> m2;
    m3 = m1 * m2;
    cout << m3;
    Fraction f;

    while (1)
    {
        cin >> f;
        cout << '\r' << f << endl;
    }*/

    system("pause");
    return 0;
}
/*
3/4 1/2 1/4
1/2 1 1/2
1/4 1/2 3/4
2 0 0
0 2 -1
0 0 1
*/