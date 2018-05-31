// q4#1
/*#include <iostream>
#include <string>
using namespace std;

class Shape
{
    public:
        Shape(string name) {
            this->name = name;
            color = "white";
        }
        string getShape() {
            return name + " " + color;
        }
        string getName() {
            return name;
        }
        int area() {
            return 0;
        }
    protected:
        string color;
    private:
        string name;
};
class Rectangle : public Shape
{
    public:
        Rectangle(int h, int w) : height(h), width(w), Shape("R") {}
        //Rectangle(int h, int w, string c) : height(h), width(w) { color = c; }
        int area() {
            return height * width;
        }
        string getShape() {
            return Shape::getShape() + " " + to_string(area()) + " "
                   + to_string(height) + " x " + to_string(width);
        }
        void setColor(string color) {
            this->color = color;
        }
        //void setName(string name) { this->name = name; }
        int calculate(Shape* s) {
            return s->area() + area();
        }
    private:
        int height, width;
};
void main()
{
    //Shape s1("S"); cout << s1.getShape() << endl; //______ S white
    //Rectangle r2(2, 3); cout << r2.getName() << endl; //______ R
    //Rectangle r3(3, 4); cout << r3.getShape() << endl; //______ R white 12 3 x 4
    //Rectangle r4(4, 5); cout << r4.Shape::area() << " " << r4.area() << endl; //______ 0 20
    //Rectangle r5(5, 6); r5.setColor("blue"); cout << r5.getShape() << endl; //______ R blue 30 5 x 6
    //Rectangle r6(6, 7); r6.setName("Rectangle"); cout << r6.getShape() << endl; //______ error
    //Rectangle r7(7, 8, "red"); cout << r7.getShape() << endl; //______ error
    //Shape s8 = r2; cout << s8.getShape() << " " << s8.area() << endl; //______ R white 0
    //Rectangle r9 = s1; cout << r9.getShape << endl; //______ error
    //Shape* s10 = &r2; r2.setColor("yellow"); cout << s10->getShape() << endl; //______ R yellow
    //Rectangle *r11 = new Shape("X"); cout << r11->getShape() << endl; //______ error 子無法指向父
    //Rectangle r12(12, 13); cout << r12.calculate(&r3) << endl; //______ 156
    system("pause");
}*/