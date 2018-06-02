#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<int> v = { 5, 8, 66, 9, 4, 8, 58 };
    vector<int>::iterator it = v.begin() + 6;
    v.erase(find(v.begin(), v.end(), 4));
    //it = find(v.begin(), v.end(), *it);

    cout << v.size() << endl;

    for (size_t i = 0; i < v.size(); ++i)
        cout << v[i] << endl;

    //cout << *it << endl;
    find(v.begin(), v.end(), *it);
    //cout << (v.end() == find(v.begin(), v.end(), *it)) << endl;

    system("pause");
}