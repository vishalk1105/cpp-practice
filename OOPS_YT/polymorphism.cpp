#include <iostream>
using namespace std;

class Base
{

public:
    virtual void show()
    {
        cout << "Base\n";
    }
};

class Derv1 : public Base
{
public:
    void show()
    {
        cout << "Derived 1\n";
    }
};

class Derv2 : public Base
{
public:
    void show()
    {
        cout << "Derived 2\n";
    }
};

int main()
{

    Derv1 dv1;
    Derv2 dv2;
    Base *ptr;
    ptr = &dv1;
    ptr->show();

    ptr = &dv2;
    ptr->show();
    return 0;
}