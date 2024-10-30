#include <iostream>
#include <forward_list>

using namespace std;

int main()
{

    forward_list<int> list1 = {5, 4, 2, 6, 2};
    forward_list<int> list2 = {7, 6, 1, 9};
    // list1.insert_after(list1.begin(), 8);
    // list1.reverse();

    //  list1.merge(list2);

    //  list1.splice_after(list1.begin(), list2);

    // list1.unique();   removes only adjacent duplicate

    // list1.remove(2);

    /* list1.remove_if([](int n)
                     { return n > 4; });
    */

    list1.resize(2);

    for (auto &el : list1)
    {
        cout << el << endl;
    }
    return 0;
}