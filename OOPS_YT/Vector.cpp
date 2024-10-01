#include <iostream>
using namespace std;

class Vector
{
public:
    int size;
    int capacity;
    int *arr;

    Vector()
    {
        size = 0;
        capacity = 1;
        arr = new int[1];
    }

    void add(int ele)
    {
        if (size == capacity)
        {
            capacity *= 2;
            int *arr2 = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                arr2[i] = arr[i];
            }
            arr = arr2;
        }
        arr[size++] = ele;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int get(int inx)
    {
        if (size == 0)
        {
            cout << "Array is Empty" << endl;
            return -1;
        }
        if (inx >= size || inx < 0)
        {
            cout << "Invalid Index" << endl;
            return -1;
        }
        return arr[inx];
    }

    void remove()
    {
        if (size == 0)
        {
            cout << "Array is Empty" << endl;
        }
        size--;
    }
};

int main()
{
    Vector v1;
    v1.add(10);
    v1.add(20);
    v1.add(30);
    v1.print();
    //  v1.get(10);
    v1.remove();
    v1.print();
}