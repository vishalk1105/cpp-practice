#include <iostream>
#include <array>

using namespace std;

int main()
{
    std::array<int, 5> arr{1, 2, 3, 4, 5};
    // cout << arr[5] << endl;
    // cout << arr.at(5) << endl;
    cout << arr.front() << endl;
    cout << arr.back() << endl;
    cout << arr.data() << endl; // return pointer / address of that array
    arr.fill(10);
    return 0;
}