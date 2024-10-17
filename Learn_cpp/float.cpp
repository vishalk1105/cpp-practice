#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

int add(int x, int y)
{
    return x + y;
}

int main()
{
    /* std::cout << std::numeric_limits<float>::is_iec559 << '\n';
      std::cout << std::numeric_limits<double>::is_iec559 << '\n';
      std::cout << std::numeric_limits<long double>::is_iec559 << '\n';


    cout << 5.0 << '\n';
    cout << 6.7f << '\n';
    cout << 9875421.32 << '\n';
*/
    // std::cout << std::setprecision(17);
    // show 17 digits of precision
    // std::cout << 3.33333333333333333333333333333333333333f << '\n'; // f suffix means float

    // std::cout << 3.33333333333333333333333333333333333333 << '\n'; // no suffix means double

    /* double zero{0.0};
      double posinf{5.0 / zero}; // positive infinity
      std::cout << posinf << '\n';

      double neginf{-5.0 / zero}; // negative infinity
      std::cout << neginf << '\n';

      double nan{zero / zero}; // not a number (mathematically invalid)
      std::cout << nan << '\n';

    bool bFalse{0}; // okay: initialized to false
    bool bTrue{1};  // okay: initialized to true

    std::cout << bFalse << bTrue << '\n';



    std::cout << "Input a keyboard character: "; // assume the user enters "abcd" (without quotes)

    char ch{};
    std::cin >> ch; // ch = 'a', "bcd" is left queued.
    std::cout << "You entered: " << ch << '\n';

    // Note: The following cin doesn't ask the user for input, it grabs queued input!
    std::cin >> ch; // ch = 'b', "cd" is left queued.
    std::cout << "You entered: " << ch << '\n';

       */

    std::cout << add(1, 2) << '\n';
    return 0;
}