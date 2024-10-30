#include <iostream>
#include <map>
#include <functional>
#include <vector>

using namespace std;

int main()
{
    std::map<string, int, std::less<string>> Map;
    Map["Chotu"] = 90909009;
    Map["Amit"] = 98451236;
    Map.insert(std::make_pair("Bot", 784512369));

    for (auto &el1 : Map)
    {
        cout << el1.first << " " << el1.second << endl;
    }

    cout << Map["Chotu"] << endl;
    return 0;
}