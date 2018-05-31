#include "pizza.h"
void pizza::SetPizza(int type, int size, string toppings)
{
    pizza::type = type;
    pizza::size = size;
    pizza::toppings = toppings;
}
int pizza::ComputePrice()
{
    int price;

    if (size == 0) price = 10;
    else if (size == 1) price = 14;
    else price = 17;

    return price + 2 * strlen(toppings.c_str());
}
void pizza::OutputDescription()
{
    cout << endl << "Your order :" << endl;
    cout << "Type : " << typeName[type] << endl;
    cout << "Size : " << sizeName[size] << endl;
    cout << "Toppings : ";

    if (toppings == "\0") cout << "None";
    else
    {
        cout << toppingsName[toppings[0] - '1'];

        for (int i = 1; pizza::toppings[i]; i++)
        {
            cout << " & " << toppingsName[toppings[i] - '1'];
        }
    }

    cout << endl << endl << "Your pizza's price : " << ComputePrice() << endl;
    cout << "Thank you for your coming!" << endl << endl << endl;
}