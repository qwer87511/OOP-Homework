#include "Header.h"

/*// Peroblem 1. �о\Ū�U�C�{���A�åB��g�ťճ������{���A�C�Ӫťեu��g1��{���C
// �H�U�{���}�Ҥ@�Ӥ�r�ɡA���ɮ�Ū�J�@�s���ơA�p��䥭��M�A�A�}�ڸ����X��console
void main()
{
    int xi;
    vector<int> x;
    fstream inputStream;
    inputStream.open("data.txt",ios::in); // Q1: �}���ɮסA�ɦW�� data.txt

    while (inputStream >> xi) // Q2: �j�����Ū�J��Ʀ�xi�A����EOF����C
        x.push_back(xi); // Q3: �NŪ�i�Ӫ��Ʀr(xi)�s��vector x��

    int sum = 0;

    for (vector<int>::iterator it = x.begin(); it != x.end(); ++it) // Q4: �j���vector x���C�Ӥ����U���@��
        sum += *it * *it; // Q5: �֭p�C�Ӥ���������M

    cout << sqrt(sum) << endl;
    inputStream.close(); // Q6: �����ɮ�
}*/

/*// Peroblem2.�о\Ū�U�C�{���A�åB��g�ťճ������{���A�C�Ӫťեu��g1��{���C
// Ū�J 1 �ӥ���ơA�̧ǱN 0,1,2,...,n-1 �s�b 1 �� list�A�A�Q�� list �p��C�Ӥ���������M�A�A�}�ڸ�
void main()
{
    int n;
    list<int> x;
    cin >> n; // Ū�J�@�ӥ���� n

    for (int i = 0; i < n; i++)
        x.push_back(i); // Q1: Ū i �s�� list x ��

    int sum = 0;

    for (list<int>::iterator it = x.begin(); it != x.end(); ++it) // Q2: �j��� list x ���C�Ӥ����U���@��
        sum += *it * *it; // Q3: �֭p�C�Ӥ���������M

    cout << sqrt(sum) << endl;
}*/

/*// Problem 3. �о\Ū�U�C�{���A�åB�g�Xcout�ҦL�X����(�B�I�Ƽg�ܤp���I�H�U2��Y�i)�C�Ъ`�N�{������������k���~�A
// �ɭP�L�k����cout�A�o�ǳ����мХܡuerror�v�A�é������~�C[�@��4�ӿ��~�A���׳̦h�u��g4��error�A�W�L�̥��D0��]
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
	//static void fight3() { fightCount++; score += 10; } // e : static �禡�L���ѦүS�w����A�� score �ݰѦүS�w����C
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

/*//Peroblem 4. �о\Ū�U�C�{���A�åB��g�ťճ������{���A�C�Ӫťեu��g1��{���C
class Book {
        friend ostream& operator<<(ostream& out, Book& drink);
    public:
        Book(string name, unsigned price) :
            _name(name), _price(price) {}
        unsigned int operator+(Book& rhs) // Q1: �ŧi operator+
        {
            return this->_price + rhs._price; // Q2: �^�ǻ��檺�M
        }
        void addAuthor(string authorName)
        {
            authors.push_back(authorName); // Q3: �W�[ 1 �ӧ@�̦� authors
        }
        string getAuthors()
        {
            string authorString("�@�̡G");

            for (vector<string>::iterator it = authors.begin(); it != authors.end(); ++it) // Q4: �j���C��@�̦U���@��
                authorString += *it + " "; // Q5: �N�@�̦s�b authorString

            return authorString;
        }
    private:
        string _name; // �ѦW
        unsigned int _price; // ����
        vector<string> authors; // �@�̸s
};
ostream& operator<<(ostream& out, Book& drink)
{
    cout << "�ѦW�G"<<drink._name + " ����G" << drink._price; // Q6: ��X�ѦW�λ���
    cout << " " << drink.getAuthors();// Q7: ��X�Ѫ��@�̸s
    return out;
}
// Operator overload
void main()
{
    Book b1("��q C++", 800);
    b1.addAuthor("�i�T"); // b1 �W�[ 1 �ӧ@��
    b1.addAuthor("���|"); // b1 �W�[ 1 �ӧ@��
    cout << b1.getAuthors() << endl;// ��X�Ѫ��@�̸s�A�Y �@�̡G�i�T ���|
    cout << b1 << endl; // ��X�Ѫ���T�A�Y �ѦW�G��q C++ ����G800 �@�̡G�i�T ���|
    Book b2("Absolute C++", 1000);
    cout << b1 + b2 << endl; // ��X�Ѫ����檺�M�A�Y 1800
}*/

