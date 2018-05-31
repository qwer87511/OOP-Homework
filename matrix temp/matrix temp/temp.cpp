#include <iostream>
using namespace std;

template<class T>
class C
{
    public:
        int foo1();
        friend int foo2(C);
        friend int operator +(int, C);
        template<class T> friend ostream& operator <<(ostream&, C); // ¥ý template ¦A friend
        template<class T2> int add(T2);
    private:
        int data = 1;
};

template<class T> // class template
template<class T2> // function template
int C<T>::add(T2 rhs)
{
    return 50;
}

template<class T>
int C<T>::foo1()
{
    return 1;
}

template<class T>
int foo2(C<T> c)
{
    return data;
}

template<class T>
int operator +(int a, C<T>)
{
    return data;
}

template<class T>
ostream& operator <<(ostream& out, C<T>)
{
    return out;
}