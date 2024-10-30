#include <iostream>
#include <set>
#include <string>
#include <functional>

using namespace std;

class Person
{
public:
    float age;
    string name;
    bool operator<(const Person &rhs) const { return age < rhs.age; }

    bool operator>(const Person &rhs) const { return age > rhs.age; }
};

int main()
{
    // set<int> Set = {
    //     1,
    //     2,
    //     3,
    //     4,
    //     2,
    //     36,
    //     5,
    //     4,
    //     2,
    // };
    // for (const auto &e : Set)
    // {
    //     cout << e << endl;
    // }

    set<Person, std::greater<Person>> Set = {{30, "Vishal"},
                                             {29, "Yash"},
                                             {22, "John"}};

    for (const auto &e : Set)
    {
        cout << e.age << " " << e.name << endl;
    }
}