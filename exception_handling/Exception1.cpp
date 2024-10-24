#include <iostream>

using namespace std;

int main()
{

    int age = 20;
    try
    {
        if (age >= 24)
        {
            cout << "you have the access to drink the alcohol\n";
        }
        else
        {
            throw(age);
        }
    }
    catch (int age)
    {
        cout << "You don't have the access to drink the alcohol , bcz your age is less than 24 \n";
        cout << "Your Age is : " << age << '\n';
    }
    return 0;
}