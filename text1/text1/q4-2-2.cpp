/*#include <iostream>
#include <string>
using namespace std;

class Animal
{
    public:
        Animal(string name) {
            this->name = name;
            legs = 4;
        }
        int getLegs() {
            return legs;
        }
        void setLegs(int l) {
            legs = l;
        }
        string getName() {
            return name;
        }
        virtual string sound() {
            return "no sound";
        }
        string getAnimal() {
            return name + ": " + to_string(legs) + " legs / " + sound();
        }
    protected:
        string name;
    private:
        int legs;
};
class Dog : public Animal
{
    public:
        Dog(string color) : Animal("Dog") {
            this->color = color;
        }
        string sound() {
            return "bark";
        }
        //int getTotalLegs(Animal &a) { return a.legs + legs; }
        string getColor() {
            return color;
        }
    private:
        string color;
};
class Chicken : public Animal
{
    public:
        Chicken() : Animal("Chicken"), wings(2) {
            setLegs(2);
        }
        string sound() {
            return "bok";
        }
        int getWings() {
            return wings;
        }
        string getTotalName(Animal& a) {
            return name + " " + a.getName();
        }
        bool isAfraidOf(Animal a) {
            return a.getName() == "Dog";
        }
        string getAnimal() {
            return Animal::getAnimal() + " / " + to_string(wings) + " wings";
        }
    private:
        int wings;
};
void main()
{
    //Animal a1("animal"); cout << a1.getLegs() << endl; //_________ 4
    Dog d2("yellow");
    cout << d2.getAnimal() << endl; //_________ Dog: 4 legs / bark
    //Animal a3 = d2; cout << a3.getColor() << endl; //_________ error
    //Animal *a4 = &d2; cout << a4->sound() << endl; //_________ bark
    //Dog d5("brown"); cout << d5.getTotalLegs(d2) << endl; //_________ error
    //Chicken c6; cout << c6.getWings() << endl; //_________ 2
    //Chicken c7; cout << c7.getTotalName(d2) << endl; //_________ Chicken dog
    //Chicken c8; cout << c8.getColor() << endl; //_________ error
    //Chicken c9; cout << c9.getAnimal() << endl; //_________ name Chicken 2 legs / bok / 2 wings
    //Chicken c10;
    //cout << c10.isAfraidOf(c9) << " " << c10.isAfraidOf(d2) << endl; //_________ 0 1
    //Chicken c11 = d2; cout << c11.sound << endl; //_________ error
    //Animal* a12 = new Chicken(); cout << a12->getAnimal() << endl; //_________ Chicken: 2 legs / bok
    //Animal *a13 = new Chicken(); cout << a13->getWings() << endl; //_________ error
    //Animal *a14 = new Chicken();
    //Chicken *c14 = (Chicken*)a14; cout << c14->getWings() << endl; //_________ 2
    //Dog *d15 = (Dog *)a14; cout << d15->getColor() << endl; //_________ error
    //Dog d16("white"); Animal a16 = d16; cout << a16.sound() << endl; //_________ no sound
}*/