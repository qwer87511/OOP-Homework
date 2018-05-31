/*#include "Header.h"
using namespace std;
struct alignas(16) Bar
{
    int i;       // 4 bytes
    int n;      // 4 bytes
    alignas(4) char arr[3];
    short s;          // 2 bytes
};

class C1
{
    public:
        virtual int f1() const {
            return 1;
        }
};
class C2 : public C1
{
    public:

        C2() {}
        explicit C2(const C1& c2) {
        }
        int f1() const {
            a = 0;
            return 1;
        }
    private:
        mutable int a;
};
#include <array>
int aa = 30;
int foo1() throw(C1);
int foo1() throw (C1)
{
    if(1) throw C1();
    else return 1;
}
int foo2() noexcept
{
    return 2;
}
class emptyC {
    public:
        static const int si = 9;
};
static volatile int foo; // 防止編譯器對(foo != 255) 優化為 (true)
void bar(void) {
    foo = 0;

    while (foo != 255)
        ;
}
int main()
{
    try {
        foo1();
    }
    catch (C1) {
    }

    extern int aa;
    cout << alignof(Bar) << endl; // output: 16
    int a = 9;
    __asm mov a, 3
    int u;
    decltype(u) i;
    C1 c1;
    C2 c2;
    //C2 C = c1; error
    C1& nc2 = c2;
    //C2& rc2 = c1; orror
    cout << nc2.f1();
    array<int, 4> iarr;
    cout<<iarr._Elems;

    for (register int i = 0; i < 10000000; ++i);

    signed int p = 5;
    char* pc = new char('e');
    int* pi = reinterpret_cast<int*>(pc);
    static_assert(emptyC::si, "need a > 0 si"); // error if si = 0
    wchar_t wc = L'\\';
    wcout << wc;
    wchar_t* w = L"\\oo";
    wcout <<endl<< w;
    system("pause");
    return 1;
}*/ // unknow: export thread_local(與static extren) 可以定義其儲存規範