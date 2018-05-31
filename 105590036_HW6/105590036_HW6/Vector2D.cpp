#include "Vector2D.h"
Vector2D::Vector2D(int sx, int sy)
{
    SetX(sx);
    SetY(sy);
}
void Vector2D::SetX(int sx)
{
    _x = sx;
}
void Vector2D::SetY(int sy)
{
    _y = sy;
}
int Vector2D::GetX()
{
    return _x;
}
int Vector2D::GetY()
{
    return _y;
}
int Vector2D::operator*(Vector2D vector)
{
    return _x*vector._x + _y*vector._y;
}