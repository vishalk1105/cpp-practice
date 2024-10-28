#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter = 0;
std::mutex mtx;

void increaseThecounterFor10000Time()
{
    for (int i = 0; i < 100000; i++)
    {
        if (mtx.try_lock())
        {
            ++counter;
            mtx.unlock();
        }
    }
}
int main()
{
    std::thread t1(increaseThecounterFor10000Time);
    std::thread t2(increaseThecounterFor10000Time);
    t1.join();
    t2.join();

    cout << "The counter could increase upto " << counter << endl;
}