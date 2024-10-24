#include <iostream>
using namespace std;

class Base // Abstract class
{
public:
    virtual void give() = 0; // Pure virtual function
};

class Boy : public Base
{
public:
    void give()
    {
        cout << "Brown Bun\n";
    }
};

class Girl : public Base
{
public:
    void give()
    {
        cout << "Pink Bun\n";
    }
};

int main()
{
    Boy b;
    Girl g;

    Base *ptr = new Boy();
    ptr->give();

    ptr = &g;
    ptr->give();
}