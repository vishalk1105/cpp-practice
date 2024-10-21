#include <iostream>
using namespace std;

class base
{
public:
    void Msg()
    {
        cout << "It is a Base class\n";
    }
};

class dervied : public base
{

public:
    void Msg()
    {
        cout << "It is a Derived class\n";
        base::Msg();
    }
};

int main()
{
    dervied d;
    d.Msg();
    return 0;
}