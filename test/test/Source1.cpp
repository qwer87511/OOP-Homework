/*#include <iostream>
using namespace std;

class Quiz
{
        friend ostream& operator<<(ostream&, Quiz);
        friend double operator*(Quiz, Quiz);
    public:
        Quiz(int nx1 = 1, int nx2 = 2) : x1(nx1), x2(nx2) {}
        const Quiz operator-() {
            return Quiz(-x1, x2);
        }

        Quiz operator+(Quiz rhs) {
            return Quiz(x1 * rhs.x2 + x2 * rhs.x1, x2 * rhs.x2);
        }

        Quiz operator--() {
            return Quiz(x1 - x2, x2);
        }
        int  operator--() {
            return 1;
        }
        void setX1(int nx1) {
            x1 = nx1;
        }
    private:
        int x1, x2;
};

ostream& operator<<(ostream& out, Quiz rhs)
{
    out << rhs.x1 << '/' << rhs.x2;
    return out;
}

double operator*(Quiz lhs, Quiz rhs)
{
    return (lhs.x1 * rhs.x1) / (lhs.x2 * rhs.x2);
}
int foo(Quiz a, Quiz b) // foo(1,2) is pass
{
    return 263;
}
int main()
{
    Quiz q5(5, 6);
    //cout << q5 + 1; // 1 = Quiz(1)
    //cout << 1 + q5; // error
    Quiz q8(2, 1);
    //cout << 1 * q8; // Quiz(1) * q8
    Quiz q10(10, 11);
    //cout << --q10; // q-- != --q
    Quiz q12(12, 13);
    //(-q12).setX1(12); // -q12 is const only can use cnnst function
    //cout << q12;
    Quiz q15(15, 16);
    q15 = 17; // 17 = Quiz(17)
    system("pause");
    return 0;
}

class a
{   public:
        int operator++(int)
        {
            return 22;
        }
};

int foo()
{
    a tt;
    ++tt;
    tt++;
}*/