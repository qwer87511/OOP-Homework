#include <iostream>
#include <string>

using namespace std;

class Phone
{
public:
	Phone(string name) : name(name) {}
	string getName() { return name; }
	void setName(string name) { this->name = name; }
	void call(string number) {
		cout << name << " call " << number << endl;
	}
	void play(string game) {
		cout << name << " play " << game << endl;
	}
private:
	string name;
};

// Composition
class Student
{
public:
	Student(string name, string phoneName) : name(name), phone(phoneName) {}
	string getName() { return name; }
	void call(string number) { phone.call(number); }
	void play(string name) { phone.play(name); }
private:
	Phone phone;
	string name;
};

// Inheritance
// 這是錯誤示範，Student1繼承Phone是不對的
class Student1 : public Phone
{
public:
	Student1(string name, string phoneName) : name(name), Phone(phoneName) {}
	string getName() { return name; }
private:
	string name;
};

// Association
class Student2
{
public:
	Student2(string name, Phone *phone) : name(name), phone(phone) {}
	string getName() { return name; }
	void setPhone(Phone *phone) { this->phone = phone; }
	void call(string number) { phone->call(number); }
	void play(string name) { phone->play(name); }
private:
	Phone *phone;
	string name;
};

// Dependency #1: parameter
class Student3
{
public:
	Student3(string name) : name(name) {}
	string getName() { return name; }
	void call(string number, Phone *phone) { phone->call(number); }
	void play(string name, Phone *phone) { phone->play(name); }
private:
	string name;
};

// Dependency #2: local variable
class Student4
{
public:
	Student4(string name) : name(name) {}
	string getName() { return name; }
	void call(string number, string phoneName) {
		Phone phone(phoneName);
		phone.call(number);
	}
	void play(string name, string phoneName) {
		Phone phone(phoneName);
		phone.play(name);
	}
private:
	string name;
};

void main()
{
	// Composition
	Student dan("Dan", "iPhone X");
	cout << dan.getName() << " : " << endl;
	dan.call("02-27712171");
	dan.play("Flappy bird");

	// Inheritance
	Student1 mark("Mark", "HTC U11");
	cout << mark.getName() << " : " << endl;
	mark.call("02-27712171");
	mark.play("Flappy bird");

	// Association
	Phone pixel("Pixel");
	Student2 mary("mary", &pixel);
	cout << mary.getName() << " : " << endl;
	mary.call("02-27712171");
	mary.play("Flappy bird");
	Student2 jone("jone", &pixel);
	cout << jone.getName() << " : " << endl;
	jone.call("02-27712171");
	jone.play("Flappy bird");

	pixel.setName("New pixel");
	cout << mary.getName() << " : " << endl;
	mary.call("02-27712171");
	mary.play("Flappy bird");
	cout << jone.getName() << " : " << endl;
	jone.call("02-27712171");
	jone.play("Flappy bird");

	Phone sony("SONY Xperia");
	mary.setPhone(&sony);
	jone.setPhone(&sony);
	cout << mary.getName() << " : " << endl;
	mary.call("02-27712171");
	mary.play("Flappy bird");
	cout << jone.getName() << " : " << endl;
	jone.call("02-27712171");
	jone.play("Flappy bird");

	// Dependency #1
	Student3 john("John");
	cout << john.getName() << " : " << endl;
	john.call("02-27712171", &pixel);
	john.play("Flappy bird", &pixel);

	// Dependency #2
	Student4 arron("aaron");
	cout << arron.getName() << " : " << endl;
	arron.call("02-27712171", "Pixel 2");
	arron.play("Flappy bird", "Pixel 2");
}