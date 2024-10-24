#include <iostream>

using namespace std;

int main()
{

    int num;
    int den;
    int output = 0;
    cout << "Enter the value of numerator\n";
    cin >> num;
    cout << "Enter the value of denominator\n";
    cin >> den;
    try
    {
        if (den == 0)
        {
            throw den;
        }
        else
        {
            output = num / den;
        }
    }
    catch (int den)
    {
        cout << "Can not enter denominator value 0 while doing division operation \n";
        cout << "Your enter denomiator is: " << den << '\n';
    }

    cout << "The out put of the division is " << output << '\n';

    return 0;
}