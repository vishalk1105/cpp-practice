#include <iostream>
#include <mutex>

using namespace std;
std::recursive_mutex m1;
int main()
{
    for (int i = 0; i < 5; i++)
    {
        m1.lock();
        std::cout << "Locked " << i << std::endl;
    }

    for (int i = 0; i < 5; i++)
    {
        m1.unlock();
        std::cout << "Un-Locked " << i << std::endl;
    }
}