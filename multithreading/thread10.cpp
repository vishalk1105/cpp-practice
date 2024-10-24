#include <iostream>
#include <future>

int square(int x)
{
    return x * x;
}
int main()
{

    std::future<int> asyncFunction = std::async(&square, 12);
    int result = asyncFunction.get();
    std::cout << "Result is :" << result << std::endl;
    return 0;
}