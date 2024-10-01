#include <iostream>
#include <string>
#include <cstring>
using namespace std;
void increamnet(int *a)
{
    *a = *a + 1;
    // a = a + 1;
    printf("Address of variable %d \n", a);
}

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int c;
    int (*p)(int, int);
    p = &add;
    c = (p)(2, 3);
    cout << c << endl;
    return 0;
}