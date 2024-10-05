#include <iostream>
#include <fstream> //file handling
#include <sstream> //to convert other data type into string
#include <Windows.h>
using namespace std;

class Bill
{
private:
    string item;
    float rate;
    int qty;

public:
    Bill() : item(""), rate(0), qty(0) {};

    void setItem(string item)
    {
        this->item = item;
    }
    void setrate(float rate)
    {
        this->rate = rate;
    }
    void setQty(int qty)
    {
        this->qty = qty;
    }

    string getItem()
    {
        return item;
    }
    float getRate()
    {
        return rate;
    }
    int getQty()
    {
        return qty;
    }
};

void addItem(Bill b)
{
    bool close = false;
    while (!close)
    {
        int choice;
        std::cout << "\t1. Add" << endl;
        std::cout << "\t2. Close" << endl;
        std::cout << "\t\tEnter Choice: " << endl;
        cin >> choice;

        if (choice == 1)
        {
            system("cls");
            string item;
            int qty;
            float rate;
            std::cout << "\t Enter Item Name: ";
            cin >> item;
            b.setItem(item);
            std::cout << "\t Enter Quantity: ";
            cin >> qty;
            b.setQty(qty);
            std::cout << "\t Enter Rate: ";
            cin >> rate;
            b.setrate(rate);

            ofstream out("D:\\VISHAL\\Practice\\cpp-practice\\superMarket\\bill.txt", ios::app);

            if (!out)
            {
                std::cout << "\t Error: File cant open" << endl;
            }
            else
            {
                out << "\t" << b.getItem() << " " << b.getQty() << " " << b.getRate() << endl
                    << endl;
                ;
            }
            out.close();
            std::cout << "Item Added Siccesssfully !!" << endl;
            Sleep(3000);
        }
        else if (choice == 2)
        {
            system("cls");
            close = true;
            std::cout << "\tBack To Main Menu" << endl;
            Sleep(3000);
        }
        else
        {
            std::cout << "Wrong Input" << endl;
        }
    }
}

void printBill()
{
    system("cls");
    int count = 0;
    bool close{false};
    while (!close)
    {
        system("cls");
        int choice;
        std::cout << "\t1. Add Bill" << endl;
        std::cout << "\t2. Close Session" << endl;
        std::cout << "\t\tEnter Choice: " << endl;
        cin >> choice;
        if (choice == 1)
        {
            string item;
            int qty;
            float rate;
            std::cout << "\t Enter Item Name: ";
            cin >> item;
            //  b.setItem(item);
            std::cout << "\t Enter Quantity: ";
            cin >> qty;
            //  b.setQty(qty);
            std::cout << "\t Enter Rate: ";
            cin >> rate;
            // b.setrate(rate);
            ifstream in("D:\\VISHAL\\Practice\\cpp-practice\\superMarket\\bill.txt");
            ofstream out("D:\\VISHAL\\Practice\\cpp-practice\\superMarket\\bill_Temp.txt");

            string line;
            bool found{false};
            while (getline(in, line))
            {
                stringstream ss;
                ss << line;
                string itemName;
                float itemRate;
                int itemQty;
                char delimiter;
                ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQty;

                if (item == itemName)
                {
                    found = true;
                    if (qty <= itemQty)
                    {

                        int amount = itemRate * qty;
                        std::cout << "\t Item | Rate | Quantity | Amount" << endl;
                        std::cout << "\t" << itemName << "\t" << itemRate << "\t" << itemQty << "\t" << amount << endl;
                        int newQty = itemQty - qty;
                        itemQty = newQty;
                        count += amount;
                        out << "\t" << itemName << " : " << itemRate << " : " << itemQty << endl;
                    }
                    else
                    {
                        std::cout << "\tSorry, " << item << " Ended!" << endl;
                    }
                }
                else
                {
                    out << line << endl;
                }
            }
            if (!found)
            {
                std::cout << "\tItem Not Available!" << endl;
            }
            out.close();
            in.close();
            remove("D:\\VISHAL\\Practice\\cpp-practice\\superMarket\\bill.txt");
            rename("D:\\VISHAL\\Practice\\cpp-practice\\superMarket\\bill_Temp.txt", "D:\\VISHAL\\Practice\\cpp-practice\\superMarket\\bill.txt");
        }
        else if (choice == 2)
        {
            close = true;
            std::cout << "\t Counting Total Bill" << endl;
        }
        Sleep(3000);
    }
    system("cls");
    std::cout << endl
              << endl;
    std::cout << "\t Total Bil------------------ : " << count << endl
              << endl;
    std::cout << "\tThanks for Shopping !!" << endl;
    Sleep(5000);
}

int main()
{

    Bill b;

    bool exit{false};
    while (!exit)
    {
        system("cls");
        int val;
        std::cout << "\tWelcome to Super market Billing System" << endl;
        std::cout << "\t******************************************" << endl;
        std::cout << "\t\t1. Add Item" << endl;
        std::cout << "\t\t2. Print Bill" << endl;
        std::cout << "\t\t3. Exit" << endl;
        std::cout << "\t\t Enter Choice" << endl;
        cin >> val;

        if (val == 1)
        {
            system("cls");
            addItem(b);
            Sleep(3000);
        }
        else if (val == 2)
        {
            printBill();
        }
        else if (val == 3)
        {
            system("cls");
            exit = true;
            std::cout << "\tGood Luck!" << endl;
            Sleep(3000);
        }
    }
}
