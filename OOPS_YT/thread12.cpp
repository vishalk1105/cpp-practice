#include <iostream>
#include <thread>
#include <mutex>

std::mutex g_lock;

void job1()
{
    if (g_lock.try_lock())
    {
        std::cout << "Job 1 is executed\n";
        g_lock.unlock();
    }
}
void job2()
{
    if (g_lock.try_lock())
    {
        std::cout << "Job 2 is executed\n";
        g_lock.unlock();
    }
}

int main()
{
    std::thread thread1(job1);
    std::thread thread2(job2);

    thread1.join();
    thread2.join();
    return 0;
}