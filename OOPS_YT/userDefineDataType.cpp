#include <iostream>

using namespace std;

class Student
{ // Student is new Data type
public:
    float CGPA;
    string name;
    int rollNumber;

    Student()
    {
    }
};

int main()
{
    Student s;
    s.name = "Vishal Kamble";
    s.CGPA = 6.07;
    s.rollNumber = 76;

    Student s1;
    cout << s1.name << " " << s1.CGPA << " " << s1.rollNumber << endl;

    return 0;
}