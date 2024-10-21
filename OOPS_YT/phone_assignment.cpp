#include <iostream>
#include <string>
using namespace std;

class Phone
{
private:
    string name;
    int ram;
    string processor;
    string batter;

public:
    Phone(string name = "null", int ram = 0, string processor = "null", string batter = "null") : name{name}, ram{ram}, batter{batter}, processor{processor}
    {
        cout << "overloaded constructor " << '\n';
    }

    Phone(const Phone &obj) : name{obj.name}, ram{obj.ram}, processor{obj.processor}, batter{obj.batter}
    {
        cout << "Copy constructor" << '\n';
    }
    void setName(string name);
    void setRam(int ram);
    void setProcessor(string processor);
    void setBatter(string batter);

    void getData();
};

void Phone::setName(string name)
{
    this->name = name;
}

void Phone::setRam(int ram)
{
    this->ram = ram;
}

void Phone::setProcessor(string processor)
{
    this->processor = processor;
}

void Phone::setBatter(string batter)
{
    this->batter = batter;
}

void Phone::getData()
{
    cout << "Phone has " << this->name << " " << this->processor << " " << this->ram << " " << this->batter << '\n';
}

int main()
{
    Phone p;
    p.setName("Samsung");
    p.setProcessor("octa core");
    p.setRam(8);
    p.setBatter("samsung batter");
    p.getData();

    Phone p1;
    p1.setName("Apple");
    p1.setProcessor("beta core");
    p1.setRam(16);
    p1.setBatter("Apple batter");
    //  p1.getData();

    Phone p3 = p1;
    p3.setName("Oppo");
    p3.getData();
}