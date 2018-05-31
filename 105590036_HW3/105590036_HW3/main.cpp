#include "pizza.h"
void Display(const char name[][20], int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << i + 1 << ". " << name[i] << endl;
    }
}
int Get()
{
    string in = "\0";
    getline(cin, in);

    while (in[0]<'1' || in[0]>'3' || in[1] != '\0')
    {
        cout << "Invalid input. Please input again" << endl;
        getline(cin, in);
    }

    return in[0] - '1';
}
void GetToppings(string& toppings)
{
    string in = "\0";

    while (in != "-1")
    {
        getline(cin, in);

        if (in[0] >= '1' && in[0] <= '9' && in[1] == '\0')
        {
            if (strstr(toppings.c_str(), in.c_str()))
                cout << "Yot are already choose this topping. Please choose again." << endl;
            else
                toppings += in;
        }
        else
            cout << "Invalid input. Please input again" << endl;
    }
}
int main()
{
    pizza piz;
    cout << "Choose pizza's type :" << endl;
    Display(typeName, 3);
    int type = Get();
    cout << endl << "Choose pizza's size :" << endl;
    Display(sizeName, 3);
    int size = Get();
    cout << endl << "Choose pizza's toppings :" << endl;
    Display(toppingsName, 9);
    string toppings = "\0";
    GetToppings(toppings);
    piz.SetPizza(type, size, toppings);
    piz.OutputDescription();
    system("pause");
}