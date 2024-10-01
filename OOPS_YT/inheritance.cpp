#include <iostream>
using namespace std;

class Scooty // Parent class
{
public:
    int topSpeed;
    float milage;

private:
    int bootSpace;
};

class Bike : public Scooty // child class
{
public:
    int gears;
};

int main()
{
    Bike b1;
    b1.topSpeed = 180;
    b1.milage = 12.5;
    b1.gears = 6;
}