#include <iostream>
#include <string>
using namespace std;
class System
{
    public:
        static void Pause() {
            system("pause");
        }
};
class Shape
{
    public:
        Shape(string name, int nx, int ny) : x(nx), y(ny) {
            this->name = name;
        }
        virtual string getShape() {
            return name + " (" + to_string(x) + "," + to_string(y) +
                   ")";
        }
        string getName() {
            return name;
        }
        virtual double perimeter() = 0;
        //int area() = 0;
        int getXY() {
            return x + y;
        }
    protected:
        int x, y;
        string name;
};
class Circle : public Shape
{
    public:
        Circle(int x, int y, int r) : radius(r), Shape("C", x, y) {}
        string getShape() {
            return Shape::getShape() + " " + to_string(radius) + " "
                   + to_string(perimeter());
        }
        double perimeter() {
            return 2 * 3.14 * radius;
        }
        double area() {
            return 3.14 * radius * radius;
        }
        int getXY() {
            return x * y;
        }
    private:
        double radius;
};
int calculate1(Shape* s) {
    return s->getXY();
}
string calculate2(Shape* s) {
    return s->getShape();
}
string calculate3(Shape& s) {
    return s.getShape();
}
string calculate4(Shape* s) {
    return s->Shape::getShape();
}
/*void main()
{   // 5 errors
    //Circle c1(1, 2, 1); cout << c1.getShape() << endl; //___________ C (1,2) 1 6.28
    Circle c2(2, 3, 2);
    //cout << c2.getShape() << endl; //___________
    //Circle c3; cout << c3.area() << endl; //___________ e1
    Circle c4(4, 5, 1);
    //cout << c4.area() << endl; //___________ 3.14
    //Shape s5(5, 6, 2); cout << s5.getShape() << endl; //___________ e2 abstract class
    Shape* s6 = new Circle(6, 7, 8);
    //cout << s6->getXY() << endl; //___________ 13
    Circle* c7 = new Circle(7, 8, 9);
    //cout << c7->getXY() << endl; //___________ 56
    Shape* s8 = new Circle(8, 9, 10);
    //cout << s8->perimeter() << endl; //___________
    Circle* c9 = new Circle(9, 10, 10);
    //cout << c9->perimeter() << endl; //___________
    //Shape *s10 = new Circle(10, 11, 10); cout << s10->area() << endl; //___________ e3
    //cout << calculate1(new Circle(11, 12, 10)) << endl; //___________
    //cout << calculate2(new Circle(12, 13, 10)) << endl; //___________
    //cout << calculate1(new Shape("S", 13, 14)) << endl; //___________ e4
    //cout << calculate3(new Circle(14, 15, 10)) << endl; //___________ e5
    //cout << calculate4(new Circle(15, 16, 10)) << endl; //___________
    cout << calculate3(Circle(10, 20, 30));
    System::Pause();
}*/