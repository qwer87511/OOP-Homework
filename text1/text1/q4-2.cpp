/*#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void main(int argc, char** argv)
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    //int q1 = v[1]; cout << q1 << endl; //_________ 3
    //vector<int>::iterator i2 = v.begin(); cout << *i2 << endl; //_________ 1
    //vector<int>::iterator i3 = v.end(); cout << *i3 << endl; //_________ error
    //cout << i2[1] + i2[2] << endl; //_________ 8
    //vector<int>::iterator i5 = i2 + 2; cout << (*i5 != v[2]) << endl; //_________ 0
    //vector<int>::iterator i6 = i5 - i2; cout << *i6 << endl; //_________ error
    //cout << *v.rbegin() << endl; //_________ 5
    //int q8 = 0;
    //for (vector<int>::iterator i8 = v.begin(); i8 != v.end(); i8++)
    //	q8 += *i8 * *i8;
    //cout << q8 << endl; //_________ 35
    list<int> l;

    for (int i9 = v.size() - 1; i9 >= 0; i9--)
        l.push_back(v[i9]);

    //cout << l[2] << endl; //_________ error
    //list<int>::iterator i11 = l.begin();
    //i11++;
    //cout << *i11 << endl; //_________ 3
    //list<int>::iterator i12 = i11 + 2;cout << *i12 << endl; //_________ error
    //cout << *find(l.begin(), l.end(), 5) << endl; //_________ 5
    //cout << *find(l.begin(), l.end(), 4) << endl; //_________ error
    //cout << (find(l.begin(), l.end(), 2) == l.end()) << endl; //_________ 1
    remove(l.begin(), l.end(), 5); //3 include<alogorithm>
    cout << *l.begin() << endl; //_________
}*/