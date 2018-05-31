#include "myVec.h"

int main()
{
    myVector<int> myVec(10);
    cout << myVec.size();
    myVec.push_back(10);
    cout << myVec.size();
    myVec.push_back(34);
    cout << myVec.size();
    myVec.push_back(23);
    myVec.push_back(55);
    myVec.push_back(13);
    cout << myVec.size();
    cout << myVec.pop_back() << endl;
    cout << myVec.size();
    vector<int> a;
    system("pause");
    return 0;
}


int foo(int(&Q)[2]) {
    return 0;
}

void ao() {
    int a[2];
    foo(a);
}



