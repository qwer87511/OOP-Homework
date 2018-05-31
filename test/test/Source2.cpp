/*#include "midstream.h"

class Quiz
{
    public:
        Quiz(int q1, int q2) {
            this->q1 = q1;
            this->q2 = new int(q2);
        }
        Quiz(Quiz& q) {
            q1 = q.q1 + 1;
            q2 = q.q2;
        }
        ~Quiz() {
            delete q2;
        }
        string getQ1Q2() {
            return to_string(q1) + ' ' + to_string(*q2);
        }
        void setQ1(int q1) {
            this->q1 = q1;
        }
        void setQ2(int q2) {
            *(this->q2) = q2;
        }
        void setQ2(int* q2) {
            this->q2 = q2;
        }
        void do1() {
            *q2 += q1;
        }
        void do2() {
            q2 += q1;
        }
        //void do3() { q2 = q1; }
        void do4(Quiz* q) {
            q->q1 = 4;
            q->setQ2(5);
        }
        void do5(Quiz& q) {
            q1 += q.q1;
        }
        void do6(Quiz q) {
            q1 += q.q1;
        }
        Quiz do7() {
            Quiz* q = new Quiz(q1, *q2);
            return *q;
        }
        Quiz do8() {
            Quiz q(8, 9);
            return q;
        }
        void operator=(Quiz const& rhs) {
            q1 = rhs.q1;
            *q2 = *(rhs.q2);
            // *this;
        }
    private:
        int q1;
        int* q2;
};

int main()

{
    // 4errors
    //Quiz q1(1, 2);cout << q1.getQ1Q2() << endl; //_________ 1 2
    //Quiz q2(2, 3); q2.setQ1(4); cout << q2.getQ1Q2() << endl; //_________ 4 3
    //Quiz q3(3, 4); q3.do1(); cout << q3.getQ1Q2() << endl; //_________ 3 7
    //Quiz q4(4, 5);q4.do2();cout << q4.getQ1Q2() << endl; //_________ error
    //Quiz q5(5, 6); q5.setQ2(new int(7)); cout << q5.getQ1Q2() << endl; //_________ 5 7
    //Quiz q6(6, 7); q6.do3(); cout << q6.getQ1Q2() << endl; //_________ error
    //Quiz q7(7, 8); q7.do4(&q1); cout << q1.getQ1Q2() << endl; //_________ 4 5
    //Quiz q8(8, 9); q8.do5(q2); cout << q8.getQ1Q2() << endl; //_________ 12 9 // no copy
    //Quiz q9(9, 10);q1 = q9;cout << q1.getQ1Q2() << endl; //_________ // 9 10 // no copy
    //Quiz q10(10, 11);q1 = q9 = q10;cout << q1.getQ1Q2() << endl; //_________ // error
    //Quiz q11(q9); cout << q11.getQ1Q2() << endl; //_________ 10 10
    //q9.setQ2(12); cout << q11.getQ1Q2() << endl; //_________ 10 12
    Quiz q13(13, 14), t(1, 2);
    q13.do6(t);
    cout << q13.getQ1Q2() << endl;//_________ 15 14
    //Quiz q14(14, 15); cout << q14.do7().getQ1Q2() << endl; //_________ 15 15 // COPY
    Quiz q15(15, 16);
    //cout << q15.do8().getQ1Q2() << endl; //_________ error
    system("pause");
}
//2. 執行上題的main()時，其中有兩行會有memory leak的現象，是哪兩行(10 % ) ? 請寫出qXX ________ ________ q14 q5*/