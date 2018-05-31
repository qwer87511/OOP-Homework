#include <iostream>
#include <string>
using namespace std;
class Quiz
{
        friend Quiz foo(Quiz);
    public:
        Quiz(int nx, int ny) : x(nx) {
            y_ptr = new int(ny);
        }
        Quiz(Quiz& q) {
            cout << "V";
            x = q.x + 1;
            y_ptr = new int(*q.y_ptr + 1);
        }
        int getXY() {
            return x + *y_ptr;
        }
        void setX(int x) {
            this->x = x;
        }
        void setY(int y) {
            *y_ptr = y;
        }
        void addY(int& y) {
            y_ptr += y;
        }
        void newY(int n) {
            delete y_ptr;
            y_ptr = new int[n];

            for (int i = 0; i < n; i++)
                y_ptr[i] = i * 2;
        }
        int getX() {
            return x;
        }
        int getY(int i) {
            return y_ptr[i];
        }
        void calculate() {
            y_ptr = &x;
        }
        void calculate1(Quiz* q) {
            q = new Quiz(100, 101);
        }
        //void calculate2(Quiz &q) { q->x = 102; *(q->y_ptr) = 103; }
        void calculate3(Quiz& q) {
            q = Quiz(104, 105);
        }
        Quiz calculate4() {
            Quiz q = Quiz(104, 105);
            return q;
        }
        Quiz calculate5(Quiz q) {
            return q;
        }
        //void deleteY() { delete y_ptr[]; }
    private:
        int x;
        int* y_ptr;
};
Quiz foo(Quiz a) {
    cout << a.x;
    return a;
}
int main()
{
    //Quiz q1(1, 2); cout << q1.getXY() << endl; //______
    //Quiz q2(2, 3); q2.setY(4); cout << q2.getXY() << endl; //______
    //Quiz q3(3, 4); q3.addY(5); cout << q3.getXY() << endl; //______
    //Quiz q4(4, 5); q4.newY(6); cout << q4.getXY() << endl; //______
    //Quiz q5(5, 6); q5.newY(7); cout << q5.getY(5) << endl; //______
    //Quiz q6(6, 7); q6.calculate(); cout << q6.getXY() << endl; //______
    //Quiz q7(7, 8); q7.calculate1(&q1); cout << q1.getXY() << endl; //______
    //Quiz q8(8, 9); q8.calculate2(q1); cout << q1.getXY() << endl; //______
    //Quiz q9(9, 10); q9.calculate3(q1); cout << q1.getXY() << endl; //______
    //Quiz q10(10, 11); q10.deleteY(); cout << q10.getX() << endl; //______
    //Quiz q11(11, 12); q11 = q2; cout << q11.getXY() << endl; //______
    //q11.setY(13); cout << q2.getXY() << endl; //______
    //Quiz q13(13, 14), t(q13); q13.setX(15); cout << t.getXY() << endl;//______
    //Quiz q14(14, 15);
    //cout << q14.calculate4().getXY() << endl; //______
    //Quiz q15(15, 16);
    //Quiz& a=foo(q15);
    //q15.calculate5(q15);
    //cout << q15.getX();
    string a, b;
    cin >> a >> b;
    return int(a == b);
    system("pause");
}