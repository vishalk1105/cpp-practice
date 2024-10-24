#include <iostream>
#include <thread>

void test(int x)
{
    std::cout << "Hello from thread!! \n";
    std::cout << "Argument passed in: " << x << std::endl;
}

int main()
{
    std::thread myThread(&test, 100);
    myThread.join();
    std::cout << "Hello from my main thread \n";

    return 0;
}