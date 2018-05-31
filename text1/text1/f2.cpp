#include "Header.h"

/*//Peroblem 1. �о\Ū�U�C�{���A�åB��g�ťճ������{���A�C�Ӫťեu��g1��{��(1��statement)�C
class Drink { // ����
    public:
        Drink(string n, int p) : _name(n), _price(p) {} // Q1 ��l��_name �P_price
        string getName() {
            return _name;
        }
        int getPrice() {
            return _price;
        }
    private:
        string _name;
        int _price;
};
class Order { // ���ƭq��
        friend ostream& operator<<(ostream& out, Order& order);
    public:
        Order() {}
        ~Order() {  } // Q2 �קK memory leak // ?
        void addDrink(Drink* d) {
            this->_drinks.push_back(d);    // Q3 �q�椤�W�[ 1 �M����
        }
        int getCount() {
            return this->_drinks.size();    // Q4 �^�Ǧ@�q n �M����
        }
        int getTotalPrice() { // �^�ǭq�椤�Ҧ����ƪ��`��
            int total = 0;

            for (int i = 0; i < _drinks.size(); i++) total += this->_drinks[i]->getPrice(); // Q5

            return total;
        }
    private:
        vector<Drink*> _drinks;  // �q�椤�ҥ]�t���Ҧ�����
};
bool operator<(Drink& lhs, Drink& rhs) {
    return lhs.getPrice() < rhs.getPrice();    // Q6
}
int operator-(Drink& lhs, Drink& rhs) {
    return lhs.getPrice() - rhs.getPrice();    // Q7
}
ostream& operator<<(ostream& out, Order& order)
{
    for (int i = 0; i < order._drinks.size(); i++)
        out << order._drinks[i]->getName() << " " << order._drinks[i]->getPrice() << endl; // Q8 ��X���ƪ��W�ٻP����

    return out;
}
void main()
{
    Order order;
    order.addDrink(new Drink("����", 30));
    order.addDrink(new Drink("�å�", 35));
    cout << "�z�ʶR�F�H�U" << order.getCount() << "�M����" << endl;
    cout << order;
    cout << "�`�� " << order.getTotalPrice() << endl << endl;
    Drink d1("����", 30), d2("�å�", 35);

    if (d1 < d2) // ��� d1 ������O�_�p�� d2 ������
        cout << "������å��K�y" << (d2 - d1) << "��";
    else
        cout << "������å��Q" << (d1 - d2) << "��";
}*/

/*//Problem 2. �о\Ū�U�C�{���A�åB�g�X cout �ҦL�X���ȡC�Ъ`�N�{������������k���~�A�ɭP�L�k���� cout�A�o�ǳ���
//�мХܡuerror�v�A�é������~�C[���צ@�� 5 �ӿ��~�A�g�W�L�̭˦�����]
class Student
{
        friend ostream& operator<<(ostream& out, Student& c);
    public:
        Student(string n, string co, int cr) : name(n), course(co), credit(cr) {
            count++;
        }
        virtual bool isGoodStudent() = 0;
        virtual bool isBetterThan(Student& s) {
            return true;
        };
        virtual int getDonation() {
            return 0;
        }
        int getCredit() {
            return credit;
        }
        int getTuition() {
            return credit * 100;
        }
        static int getCount() {
            return count;
        }
    protected:
        string name, course;
        int credit;
        static int count;
};
int Student::count = 0;
class NormalStudent : public Student
{
    public:
        NormalStudent(string n, string co, int cr) : Student(n, co, cr), grade(0) {}
        NormalStudent(string n, string co, int cr, int g) : Student(n, co, cr), grade(g) {}
        virtual bool isGoodStudent() {
            return grade >= 80;
        }
        //virtual bool isBetterThan(Student &s) { grade > s.grade; } // e : Student has no member"grade"
        int getDiff(int g) {
            return abs(grade - g);
        }
        int getDiff(NormalStudent& s) {
            return abs(credit - s.credit);
        }
        void setGrade(int g) {
            grade = g;
        }
    private:
        int grade;
};
class RichStudent : public Student
{
    public:
        friend ostream& operator<<(ostream& out, RichStudent& s);
        RichStudent(string n, string co, int cr, int m)
            : Student(n, co, cr), money(m), donation(0) {}
        RichStudent(string n, string co, int cr, int m, int d)
            : Student(n, co, cr), money(m), donation(0) {
            giveDonation(d);
        }
        virtual bool isGoodStudent() {
            return donation >= 3000;
        }
        void giveDonation(int d = 0) {
            int amount = credit * 1000 + d;
            donation += amount;
            money -= amount;
        }
        int getDonation() {
            return donation;
        }
    protected:
        int money, donation;
};
ostream& operator<<(ostream& out, Student& s)
{
    out << s.name << " " << s.course << " " << s.credit << " " << s.getTuition();
    return out;
}
ostream& operator<<(ostream& out, RichStudent& s)
{
    out << (Student&)s << " " << s.donation << " " << s.money;
    return out;
}
void main()
{
    //Student s1("John", "DB", 3); cout << s1 << endl; // Q1 // e1 : Student is an abstract class
    //NormalStudent n2("Mary", "DB", 3); cout << n2 << endl; // Q2 // Mary DB 3 300
    //NormalStudent n3("June", "OS", 2); cout << Student::getCount() << endl; // Q3 // 2
    //n3.setGrade(95); cout << n3.isGoodStudent() << endl; // Q4 // 1
    //cout << n3.isBetterThan(n2) << endl; // Q5 // e2 : isBetterThan() has error, but program can still work
    //cout << n3.getDiff(55) << endl; // Q6 // 40
    //NormalStudent n7("Pete", "OO", 4); cout << n7.getTuition() << endl; // Q7 // 400
    //cout << n7.getDiff(n3) << endl; // Q8 // 2
    //Student *s9 = new NormalStudent("Robb", "DS", 5);
    //cout << s9->isGoodStudent() << endl; // Q9 // 0
    //RichStudent r10("Jone", "AI", 5, 10000); cout << r10 << endl; // Q10 // Jone AI 5 500 0 10000
    //Student *s11 = &r10; cout << s11->isGoodStudent() << endl; // Q11 // 0
    //r10.giveDonation(); cout << s11->isGoodStudent() << endl; // Q12 // 1
    //cout << r10 << endl; // Q13 // Jone AI 5 500 5000 5000
    //s11->addMoney(10000); cout << s11->getMoney() << endl; // Q14 // e3 : does not have that function
    //Student *s15 = new NormalStudent("Snow", "WP", 4); cout << *s15 << endl; // Q15 // Snow WP 4 400
    //RichStudent *r16 = (RichStudent*)s15; cout << *r16 << endl; // Q16 // e4 : cast is unreasonable
    //list<Student*> l17;
    //l17.push_back(new RichStudent("Gabe", "JS", 4, 20000, 10000));
    //l17.push_back(new NormalStudent("Ayra", "MM", 3));
    //l17.push_back(new NormalStudent("Gael", "DM", 5, 85));
    //cout << (*l17.begin())->getDonation() << endl; // Q17 // 14000
    //cout << (*l17.rbegin())->getDonation() << endl; // Q18 // 0
    //int total = 0;
    //for (list<Student *>::iterator i = l17.begin(); i != l17.end(); i++)
    //	total += (*i)->isGoodStudent();
    //cout << total << endl; // Q19 // 2(1 + 0 + 1)
    //RichStudent r20("Vale", "IP", 4, 20000), r20a("Naak", "CC", 3, 20000, 10);
    //cout << (r20 > r20a ? "Vale is richer" : "Naak is richer") << endl; // Q20 // e5 : operator > was not defined
}*/