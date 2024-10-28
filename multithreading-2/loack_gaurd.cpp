#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::mutex m1;
int buffer = 0;

void task(const char *threadNumber, int loopFor)
{
    // m1.lock();

    std::lock_guard<mutex> lock(m1);
    for (int i = 0; i < loopFor; i++)
    {
        buffer++;
        cout << threadNumber << " " << buffer << endl;
    }
    // m1.unlock();
}

int main()
{
    std::thread t1(task, "T0", 10);
    std::thread t2(task, "T1", 10);
    t1.join();
    t2.join();

    cout << buffer << "<<<<Buffer\n";
    return 0;
}