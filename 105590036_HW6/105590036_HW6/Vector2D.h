#pragma once
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Vector2D
{
    public:
        Vector2D(int sx, int sy);
        void SetX(int x);
        void SetY(int y);
        int GetX();
        int GetY();
        int operator*(Vector2D);
    private:
        int _x, _y;
};