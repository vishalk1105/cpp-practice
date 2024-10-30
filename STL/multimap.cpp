#include <iostream>
#include <map>
#include <functional>
#include <vector>

using namespace std;

int main()
{
    std::multimap<char, int, std::less<>> MultiMap;

    MultiMap.insert(pair<char, int>('a', 1));
    MultiMap.insert(make_pair('a', 2));
    MultiMap.insert(make_pair('a', 3));
    MultiMap.insert(make_pair('b', 4));
    MultiMap.insert(make_pair('b', 6));
    MultiMap.insert(make_pair('c', 5));
    for (auto &el1 : MultiMap)
    {
        cout << el1.first << " " << el1.second << endl;
    }
    cout << "---------------------------------------\n";
    auto range = MultiMap.equal_range('a');
    for (auto it = range.first; it != range.second; ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}