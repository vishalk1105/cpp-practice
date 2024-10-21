#include <iostream>

using namespace std;

class A
{
private:
    int weight;

public:
    A(int x = 0)
    {
        weight = x;
    }

    // A addWeight(A w)
    // {
    //     A temp;
    //     temp.weight = weight + w.weight;
    //     return temp;
    // }

    A operator+(A w) // operator overloading
    {
        A temp;
        temp.weight = weight + w.weight;
        return temp;
    }

    void operator++()
    {
        ++weight;
    }
    void operator++(int)
    {
        weight++;
    }
    void getWeight()
    {
        cout << weight << '\n';
    }
};

int main()
{
    A person1(63);
    A person2(89);
    ++person2;
    person2++;
    person2.getWeight();
    A total;
    //  total = person1.addWeight(person2);
    // total = person1 + person2;
    // total.getWeight();
}