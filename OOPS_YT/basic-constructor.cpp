#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person()
    {
        name = "Null";
        age = 0;
    }

    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void getData()
    {
        cout << "Name is " << name << " and age is " << age << '\n';
    }
};
int main()
{
    Person p3, p("Gurunath Kamble", 30);
    p.getData();
    p3.getData();
    Person p1 = Person("Vishal", 30);
    p1.getData();
    Person *p2 = new Person("pointer name", 30);
    p2->getData();
}