#include <iostream>
#include <thread>

using namespace std;

void run(int count)
{
    while (count-- > 0)
    {
        cout << "Vishal " << count << endl;
    }
    std::this_thread::sleep_for(chrono::seconds(5));
    cout << "Thread finish " << endl;
}

int main()
{
    std::thread t(run, 10);
    cout << "Main()" << endl;
    t.detach();
    // if (t.joinable())
    // {
    //     t.join();
    // }

    cout << "Main() after" << endl;
    std::this_thread::sleep_for(chrono::seconds(5));
    return 0;
}