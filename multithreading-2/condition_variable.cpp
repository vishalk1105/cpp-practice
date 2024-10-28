#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

std::condition_variable cv;
std::mutex m;
long balance = 0;

void addMoney(int money)
{
    std::lock_guard<mutex> lg(m);
    balance += money;
    cout << "Amount added Current balance is :" << balance << '\n';
    cv.notify_one();
}

void withdrawMoney(int money)
{
    std::unique_lock<mutex> ul(m);
    cv.wait(ul, []
            { return (balance != 0) ? true : false; });
    if (balance >= money)
    {
        balance -= money;
        cout << "Amount deducted:" << money << '\n';
    }
    else
    {
        cout << "Amount Can't be Deducted, Current Balance is less than " << money << '\n';
    }
    cout << "Current Balance is: " << balance << '\n';
}

int main()
{
    std::thread t1(withdrawMoney, 500);
    std::thread t2(addMoney, 500);
    t1.join();
    t2.join();
    return 0;
}