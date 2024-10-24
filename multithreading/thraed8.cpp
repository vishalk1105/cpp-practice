#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>

static std::atomic<int> shared_value = 0;
void shared_value_increament()
{
    shared_value++;
}

int main()
{
    std::vector<std::thread> threads;

    for (int i = 0; i < 1000; i++)
    {
        threads.push_back(std::thread(shared_value_increament));
    }

    for (int i = 0; i < 1000; i++)
    {
        threads[i].join();
    }

    std::cout << "Shared Values is " << shared_value << std::endl;

    return 0;
}