#include "Header.h"

/*//Peroblem 1. 請閱讀下列程式，並且填寫空白部份的程式，每個空白只能寫1行程式(1個statement)。
class Drink { // 飲料
    public:
        Drink(string n, int p) : _name(n), _price(p) {} // Q1 初始化_name 與_price
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
class Order { // 飲料訂單
        friend ostream& operator<<(ostream& out, Order& order);
    public:
        Order() {}
        ~Order() {  } // Q2 避免 memory leak // ?
        void addDrink(Drink* d) {
            this->_drinks.push_back(d);    // Q3 訂單中增加 1 杯飲料
        }
        int getCount() {
            return this->_drinks.size();    // Q4 回傳共訂 n 杯飲料
        }
        int getTotalPrice() { // 回傳訂單中所有飲料的總價
            int total = 0;

            for (int i = 0; i < _drinks.size(); i++) total += this->_drinks[i]->getPrice(); // Q5

            return total;
        }
    private:
        vector<Drink*> _drinks;  // 訂單中所包含的所有飲料
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
        out << order._drinks[i]->getName() << " " << order._drinks[i]->getPrice() << endl; // Q8 輸出飲料的名稱與價格

    return out;
}
void main()
{
    Order order;
    order.addDrink(new Drink("奶茶", 30));
    order.addDrink(new Drink("珍奶", 35));
    cout << "您購買了以下" << order.getCount() << "杯飲料" << endl;
    cout << order;
    cout << "總價 " << order.getTotalPrice() << endl << endl;
    Drink d1("奶茶", 30), d2("珍奶", 35);

    if (d1 < d2) // 比較 d1 的價格是否小於 d2 的價格
        cout << "奶茶比珍奶便宜" << (d2 - d1) << "元";
    else
        cout << "奶茶比珍奶貴" << (d1 - d2) << "元";
}*/

/*//Problem 2. 請閱讀下列程式，並且寫出 cout 所印出的值。請注意程式中有部分文法錯誤，導致無法執行 cout，這些部分
//請標示「error」，並忽略錯誤。[答案共有 5 個錯誤，寫超過者倒扣分數]
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