#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::mutex m1;
int buffer = 0;

void task(const char *threadNumber, int loopFor)
{

    // std::unique_lock<mutex> lock(m1);
    // Automatically calls lock on mutex m1

    std::unique_lock<mutex> lock(m1, defer_lock); // do not acquire ownership of the mutex
    lock.lock();
    for (int i = 0; i < loopFor; i++)
    {
        buffer++;
        cout << threadNumber << " " << buffer << endl;
    }
}

int main()
{
    std::thread t1(task, "T1", 10);
    std::thread t2(task, "T2", 10);
    t1.join();
    t2.join();

    cout << buffer << "<<<<Buffer\n";
    return 0;
}