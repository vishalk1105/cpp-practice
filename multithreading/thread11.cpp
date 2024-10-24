#include <iostream>
#include <thread>
#include <chrono>
#include <future>

bool bufferFiledLoader()
{
    size_t bytesLoaded = 0;
    while (bytesLoaded < 20000)
    {
        std::cout << "Thread: loading file..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        bytesLoaded += 1000;
    }
    return true;
}
int main()
{

    std::future<bool> backgroundThread = std::async(std::launch::async, bufferFiledLoader);
    std::future_status status;
    // our main program loop

    while (true)
    {
        std::cout << "Main thread is running\n";
        // artificial sleep for our program
        std::this_thread::sleep_for(std::chrono::microseconds(50));
        status = backgroundThread.wait_for(std::chrono::microseconds(1));
        // if our data is ready, that is , our background thread has completed
        if (status == std::future_status::ready)
        {
            std::cout << "Our data is ready...\n";
            break;
        }
    }

    std::cout << "Program is complete...\n";
    return 0;
}