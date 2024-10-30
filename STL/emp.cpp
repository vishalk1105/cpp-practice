#include <iostream>
#include <set>

using namespace std;

class A
{
public:
    int x;
    A(int x = 0) : x{x} { cout << "Constructor" << endl; };
    A(const A &rhs)
    {
        x = rhs.x;
        cout << "Copy" << endl;
    }
};

bool operator<(const A &lhs, const A &rhs) { return lhs.x < rhs.x; }

int main()
{
    set<A> Set;
    Set.insert(A(1));
    Set.emplace(2);
    return 0;
}