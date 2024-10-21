#include <iostream>

using namespace std;

class House
{
private:
    int lenght = 0, breadth = 0;

public:
    void setData(int, int);

    void area();
};

void House::setData(int x, int y)
{
    lenght = x;
    breadth = y;
}
void House::area()
{
    cout << "Area of house is " << lenght * breadth << '\n';
}

int main()
{
    House h1;

    h1.setData(50, 60);
    h1.area();
}