#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

int myAmount = 0;
std::timed_mutex m;

void increament(int i)
{
    if (m.try_lock_for(std::chrono::seconds(1))) // 2   will entered both thread
    {
        ++myAmount;
        std::this_thread::sleep_for(std::chrono::seconds(2)); // 1
        cout << "Thread " << i << " Entered " << endl;
        m.unlock();
    }
    else
    {
        cout << "Thread " << i << " Couldn't Enter" << endl;
    }
}

int main()
{
    std::thread t1(increament, 1);
    std::thread t2(increament, 2);
    t1.join();
    t2.join();

    cout << myAmount << '\n';
    return 0;
}