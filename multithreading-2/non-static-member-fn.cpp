#include <iostream>
#include <thread>
using namespace std;

class Base
{
public:
    void run(int x)
    {
        while (x-- > 0)
        {
            cout << x << endl;
        }
    }

    static void show(int x)
    {
        while (x-- > 0)
        {
            cout << x << endl;
        }
    }
};

int main()
{
    Base b;
    // std::thread t(&Base::run, &b, 10);

    std::thread t1(&Base::show, 20);
    t1.join();

    return 0;
}