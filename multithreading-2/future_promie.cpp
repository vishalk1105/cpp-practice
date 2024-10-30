#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <algorithm>
#include <future>

using namespace std;
using namespace std::chrono;

typedef long int ull;

void findOdd(std::promise<ull> &&OddSumPromise, ull start, ull end)
{
    ull OddSum = 0;
    for (ull i = start; i <= end; i++)
    {
        if (i & 1)
        {
            OddSum += 1;
        }
    }
    OddSumPromise.set_value(OddSum);
}

int main()
{
    ull start = 0, end = 1900000000;
    std::promise<ull> OddSum;
    std::future<ull> OddFuture = OddSum.get_future();

    cout << "Thread Created!!" << endl;
    std::thread t1(findOdd, std::move(OddSum), start, end);

    cout << "Waiting for result!!\n";

    cout << "OddSum : " << OddFuture.get() << endl;

    cout << "Completed!! " << endl;
    return 0;
}