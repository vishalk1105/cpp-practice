#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> Vec;
    Vec.reserve(20); // make vector of capacity 50
    for (int i = 0; i < 32; i++)
    {
        Vec.push_back(i);
        cout << Vec.size() << " " << Vec.capacity() << endl;
    }
    return 0;
}