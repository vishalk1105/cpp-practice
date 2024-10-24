#include <iostream>
#include <thread>

int main()
{

    auto lambda = [](int x)
    {
        std::cout << "Hello from thread!! \n";
        std::cout << "Argument passed in: " << x << std::endl;
    };

    std::thread myThread(lambda, 100);
    myThread.join();
    std::cout << "Hello from my main thread \n";

    return 0;
}