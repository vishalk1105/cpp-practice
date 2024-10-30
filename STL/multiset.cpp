#include <iostream>
#include <set>
#include <string>
#include <functional>

using namespace std;
/*
int main()
{

    std::multiset<int, std::greater<>> multiSet = {5, 2, 4, 3, 2, 5};

    for (const auto &e : multiSet)
    {
        cout << e << endl;
    }

    return 0;
}
*/

class Person
{
public:
    string name;
    int age;

    bool operator<(const Person &rhs) const
    {
        return age < rhs.age;
    }

    bool operator>(const Person &rhs) const
    {
        return age > rhs.age;
    }
};

int main()
{
    std::multiset<Person, std::less<Person>> multiSet = {{"Vishal", 20}, {"Yash", 21}, {"Rahul", 21}};
    for (const auto &p : multiSet)
    {
        cout << p.name << " " << p.age << endl;
    }

    return 0;
}
