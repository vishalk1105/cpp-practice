#include <iostream>
using namespace std;

class Fraction
{
public:
    int num;
    int den;

    Fraction(int num, int den)
    {
        this->num = num;
        this->den = den;
    }

    Fraction operator+(Fraction f)
    {
        int newNum = ((this->den * f.num) + (this->num * f.den));
        int newDen = this->den * f.den;
        Fraction ans(newNum, newDen);
        return ans;
    };
    void display()
    {
        cout << num << " / " << den << endl;
    }
};

int main()
{
    Fraction f1(1, 2);
    Fraction f2(1, 4);
    Fraction f3 = f1 + f2;
    f3.display();
}