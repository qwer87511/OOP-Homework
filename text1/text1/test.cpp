#include "Header.h"

class C
{
    public:
        operator CC()
        {
            return CC();
        }
};
class CC
{};

int main()
{
    C c;
    CC cc = CC(c);
}