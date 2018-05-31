#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    Point(int x, int y)
        : x(x), y(y)
    {}
    int x;
    int y;
};

class C1
{
    public:
        C1(Point (&np)[3])
            : vp(np, np + sizeof(np) / sizeof(Point))
        {
            cout << "1" << endl;
        }
        /*C1(Point* p)
        {
            cout << "2" << endl;
            vp = p;
        }*/
        //private:
        vector<Point> vp;
};

class C2
{
    public:

    private:
};

int main()
{
    Point p[3] = { Point(2, 5), Point(5, 8), Point(8, 9) };
    C1 c1(p);
    cout << c1.vp.at(1).x;
    system("pause");
}