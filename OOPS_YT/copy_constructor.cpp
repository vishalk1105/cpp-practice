#include <iostream>
#include <string>
using namespace std;

class A
{
private:
    int age;
    string name;

public:
    A(int age = 28, string name = "null") : name{name}, age{age} // overloaded constructor
    {
        cout << "Parameterized/ overloaded constructor" << '\n';
    }

    A(const A &obj) : name{obj.name}, age{obj.age}
    {
        cout << "Copy constructor" << '\n';
    }

    void setName(string name)
    {
        this->name = name;
    }
    void getData()
    {
        cout << "The age is " << age << " Name is " << name << '\n';
    }
};

int main()
{

    A c;
    // c.getData();
    A a(10, "Vishal");
    // a.getData();

    A b = a;
    b.getData();
    //  b.setName("gurunath");
    a.getData();
    return 0;
}