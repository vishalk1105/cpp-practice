#include <iostream>
using namespace std;

class Scooty // Parent class
{
public:
    int topSpeed;
    float milage;

    Scooty()
    {
        cout << "Parent class default constructor" << '\n';
    }
    Scooty(int topSpeed, float milage) : topSpeed{topSpeed}, milage{milage}
    {
        cout << "Parent class Parameterized constructor" << '\n';
    }

private:
    int bootSpace;
};

class Bike : public Scooty // child class
{
public:
    int gears;

    Bike() : Scooty()
    {
        cout << "Child class default constructor" << '\n';
    }
    Bike(int gears, int topSpeed, float milage) : Scooty(topSpeed, milage), gears{gears}
    {
        cout << "Child class Parameterized constructor" << '\n';
    }
};

int main()
{
    Bike b1(1, 100, 24.5f);
    Bike b2;
}