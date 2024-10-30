#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <algorithm>
#include <future>

using namespace std;
using namespace std::chrono;
typedef long long ull;

ull findOdd(ull start, ull end)
{
    ull OddSum = 0;
    for (ull i = start; i <= end; i++)
    {
        if (i & 1)
        {
            OddSum += i;
        }
    }
    return OddSum;
}

int main()
{
    ull start = 0, end = 19000000;
    cout << "Thread created if policy is std::launch::async!!" << endl;
    std::future<ull> OddSum = std::async(std::launch::async, findOdd, start, end);
    cout << "Waiting for Ressult !!" << endl;
    cout << "OddSum : " << OddSum.get() << endl;

    cout << "Completed!!" << endl;
    return 0;
}