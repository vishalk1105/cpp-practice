#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

std::mutex gLock;
std::condition_variable gConditionVariable;

int main()
{
    int result = 0;
    bool notified = false;

    // Reposting Thread
    // Must wait on work, done by working thread
    std::thread reporter([&]
                         { std::unique_lock<std::mutex> lock(gLock); 
                         if(!notified){
                             gConditionVariable.wait(lock);
                         }
                         std::cout << "Reporter, result is: " << result << std::endl; });
    // Working Thread
    std::thread worker([&]
                       {
                           std::unique_lock<std::mutex> lock(gLock);
                           result = 42 + 1 + 7;
                           notified = true;
                           std::this_thread::sleep_for(std::chrono::seconds(5));
                           std::cout<<"Work Complete\n";
                           // Wake up a thread, that is waiting for some condition to be true
                           gConditionVariable.notify_one(); });
    reporter.join();
    worker.join();
    std::cout << "Programm Complete\n";
    return 0;
}