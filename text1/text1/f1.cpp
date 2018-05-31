#include "Header.h"

/*// Peroblem 1. 請閱讀下列程式，並且填寫空白部份的程式，每個空白只能寫1行程式。
// 以下程式開啟一個文字檔，自檔案讀入一連串整數，計算其平方和，再開根號後輸出至console
void main()
{
    int xi;
    vector<int> x;
    fstream inputStream;
    inputStream.open("data.txt",ios::in); // Q1: 開啟檔案，檔名為 data.txt

    while (inputStream >> xi) // Q2: 迴圈反覆讀入整數至xi，直至EOF為止。
        x.push_back(xi); // Q3: 將讀進來的數字(xi)存至vector x中

    int sum = 0;

    for (vector<int>::iterator it = x.begin(); it != x.end(); ++it) // Q4: 迴圈對vector x的每個元素各做一次
        sum += *it * *it; // Q5: 累計每個元素的平方和

    cout << sqrt(sum) << endl;
    inputStream.close(); // Q6: 關閉檔案
}*/

/*// Peroblem2.請閱讀下列程式，並且填寫空白部份的程式，每個空白只能寫1行程式。
// 讀入 1 個正整數，依序將 0,1,2,...,n-1 存在 1 個 list，再利用 list 計算每個元素的平方和，再開根號
void main()
{
    int n;
    list<int> x;
    cin >> n; // 讀入一個正整數 n

    for (int i = 0; i < n; i++)
        x.push_back(i); // Q1: 讀 i 存至 list x 中

    int sum = 0;

    for (list<int>::iterator it = x.begin(); it != x.end(); ++it) // Q2: 迴圈對 list x 的每個元素各做一次
        sum += *it * *it; // Q3: 累計每個元素的平方和

    cout << sqrt(sum) << endl;
}*/

/*// Problem 3. 請閱讀下列程式，並且寫出cout所印出的值(浮點數寫至小數點以下2位即可)。請注意程式中有部分文法錯誤，
// 導致無法執行cout，這些部分請標示「error」，並忽略錯誤。[共有4個錯誤，答案最多只能寫4個error，超過者本題0分]
class Animal
{
public:
	Animal(string n) : x(0), y(0), name(n) {}
	virtual string getSound() = 0;
	virtual bool canSwim() { return false; }
	virtual void Move(int dx, int dy) { x += dx; y += dy; }
	string getName() { return name; }
	string getAnimal() {
		return name + " " + getXY() + " sound=" + getSound() + " swim=" +
			to_string(canSwim());
	}
	string getXY() { return "(" + to_string(x) + "," + to_string(y) + ")"; }
	int getX() { return x; }
	bool operator>(Animal &rhs) { return name.length() > rhs.name.length(); }
protected:
	string name;
	int x, y;
};
class Dog : public Animal
{
public:
	// Dog() : legs(4) {} e : Animal does not have default constructor
	Dog(string name) : Animal(name), legs(4) {}
	string getSound() { return "Woof!"; }
	string getAnimal() { return Animal::getAnimal() + "legs=" + to_string(legs); }
	bool canSwim() { return true; }
private:
	int legs;
};
class Cat : public Animal
{
public:
	Cat() : Animal("cat"), legs(4) {}
	string getSound() { return "Meow!"; }
	void Move(int dx, int dy) { x += dx / 2; y += dy / 2; }
private:
	int legs;
};

class FightGame
{
public:
	FightGame(Animal *a1, Animal *a2) : animal1(a1), animal2(a2) {}
	string getFighters() { return animal1->getName() + " " + animal2->getName(); }
	void fight1() {
		fightCount++;
		if (*animal1 > *animal2)
			score++;
	}
	void fight2() { fightCount++; score += animal1->getX() + animal2->getX(); }
	//static void fight3() { fightCount++; score += 10; } // e : static 函式無須參考特定物件，但 score 需參考特定物件。
	int getScore() { return score; }
	void set1(Animal *a) { a = new Dog("snoopy"); }
	void set2(Animal *a) { a->Move(2, 3); }
	//void set3(Animal a) { animal1 = &a; } // e : Animal is an abstract class
	static int fightCount;
private:
	Animal *animal1, *animal2;
	int score;
};
int FightGame::fightCount = 0;
void main()
{	// 4 errors
	//Animal a1("animal"); cout << a1.getAnimal() << endl; // Q1 // e1 : Animal is an abstract class
	Dog d2("pluto2"); cout << d2.getName() << endl; // Q2 // pluto2
	Dog d3("pluto3"); cout << d3.getAnimal() << endl; // Q3 // pluto3 (0,0) sound=Woof! swim=1 legs=4
	Dog d4("pluto4"); d4.Move(4, 5); cout << d4.getXY() << endl; // Q4 (4,5)
	//Dog d5; cout << d5.getAnimal() << endl; // Q5 // e2 : Dog has not default constructor
	Cat c6; cout << c6.getAnimal() << endl; // Q6 cat (0,0) sound=Meow! swim=0
	//Cat c7; c7.Move(7, 8); cout << c7.getXY() << endl; // Q7 // (3,4)
	//Animal *a8; a8 = &d2; cout << a8->getAnimal() << endl; // Q8 pluto2 (0,0) sound=Woof! swim=1
	//Animal *a9; a9 = &c6; a9->Move(10, 10); cout << a9->getXY() << endl; // Q9 // (5,5)
	//Dog d10("pluto10"); Cat c10; cout << (d10 > c10 ? ">" : "<=") << endl; // Q10 // >
	//FightGame f11(&d2, &d3); cout << f11.getFighters() << endl; // Q11 // pluto2 pluto3
	//FightGame f12(&d2, &d4); cout << FightGame::fightCount << endl; // Q12 // 0
	//FightGame f13(&d2, &d3); f13.fight1(); cout << f13.getScore() << endl; // Q13 // 0
	//FightGame f14(&d2, &c6); f14.fight1(); cout << f14.getScore() << endl; // Q14 // 1
	//FightGame f15(&d2, &d4); f15.fight2(); cout << f15.getScore() << endl; // Q15 // 4
	//FightGame f16(&d2, &d4); cout << f16.fightCount << endl; // Q16 // 3
	//FightGame f17(&d2, &d4); f15.fight3(); cout << f15.getScore() << endl; // Q17 // e3 : fight3() has error
	//FightGame f18(&d2, &d4); f18.set1(&d3); cout << d3.getName() << endl; // Q18 // pluto3
	//Dog d19("pluto19"); FightGame f19(&d2, &d4); f19.set2(&d19);
	//cout << d19.getXY() << endl; // Q19 // (2,3)
	//FightGame f20(&d2, &d4); f20.set3(d19); cout << d19.getXY() << endl; // Q20 // e4 : set3() has error
}*/

/*//Peroblem 4. 請閱讀下列程式，並且填寫空白部份的程式，每個空白只能寫1行程式。
class Book {
        friend ostream& operator<<(ostream& out, Book& drink);
    public:
        Book(string name, unsigned price) :
            _name(name), _price(price) {}
        unsigned int operator+(Book& rhs) // Q1: 宣告 operator+
        {
            return this->_price + rhs._price; // Q2: 回傳價格的和
        }
        void addAuthor(string authorName)
        {
            authors.push_back(authorName); // Q3: 增加 1 個作者至 authors
        }
        string getAuthors()
        {
            string authorString("作者：");

            for (vector<string>::iterator it = authors.begin(); it != authors.end(); ++it) // Q4: 迴圈對每位作者各做一次
                authorString += *it + " "; // Q5: 將作者存在 authorString

            return authorString;
        }
    private:
        string _name; // 書名
        unsigned int _price; // 價格
        vector<string> authors; // 作者群
};
ostream& operator<<(ostream& out, Book& drink)
{
    cout << "書名："<<drink._name + " 價格：" << drink._price; // Q6: 輸出書名及價格
    cout << " " << drink.getAuthors();// Q7: 輸出書的作者群
    return out;
}
// Operator overload
void main()
{
    Book b1("精通 C++", 800);
    b1.addAuthor("張三"); // b1 增加 1 個作者
    b1.addAuthor("李四"); // b1 增加 1 個作者
    cout << b1.getAuthors() << endl;// 輸出書的作者群，即 作者：張三 李四
    cout << b1 << endl; // 輸出書的資訊，即 書名：精通 C++ 價格：800 作者：張三 李四
    Book b2("Absolute C++", 1000);
    cout << b1 + b2 << endl; // 輸出書的價格的和，即 1800
}*/

