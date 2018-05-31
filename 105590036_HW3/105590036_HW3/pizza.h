#pragma once
#include <iostream>
#include <string>
using namespace std;
const char typeName[3][20] = { "Deep dish", "Hand tossed", "Pan" };
const char sizeName[3][20] = { "Small", "Medium", "Large" };
const char toppingsName[9][20] = { "Pepperoni", "Pepperoni(NY Style)", "Asiago", "Bocconcini", "Cheddar", "Feta", "Goat Cheese", "Mozzarella", "Parmesan" };
class pizza
{
    public:
        void SetPizza(int, int, string);
        void OutputDescription();
        int ComputePrice();
    private:
        int type;
        int size;
        string toppings;
};