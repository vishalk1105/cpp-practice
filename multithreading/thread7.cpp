#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex gLock;
static int shared_value = 0;
void shared_value_increament()
{
    std::lock_guard<std::mutex> lockGaurd(gLock);

    try
    {
        shared_value = shared_value + 1;
        throw "dangerous...abort\n";
    }
    catch (...)
    {
        std::cout << "Handled Exception\n";
        return;
    }
}

int main()
{

    std::vector<std::thread> threads;

    for (int i = 0; i < 10; i++)
    {
        threads.push_back(std::thread(shared_value_increament));
    }

    for (int i = 0; i < 10; i++)
    {
        threads[i].join();
    }

    std::cout << "Shared Values is " << shared_value << std::endl;

    return 0;
}