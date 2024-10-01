#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

class Bank
{
    char name[100], add[100], type;
    float balance;

public:
    void openAccount();
    void depositeMoney();
    void withdrawMoney();
    void displayAccount();
};

void Bank::openAccount()
{
    cout << "Enter Your Full name  :: ";
    cin.ignore(); // to clear buffer
    cin.getline(name, 100);
    cout << "Enter your Address :: ";
    cin.ignore();
    cin.getline(add, 100);
    cout << "What type of account you want to open saving (s) or Current (c)?? ::";
    cin >> type;
    cout << "Enter Amount fot Deposite :: ";
    cin >> balance;
    cout << "Your account is created  \n";
};

void Bank ::depositeMoney()
{
    float a;
    cout << "Enter how mush you deposite:: ";
    cin >> a;
    balance += a;
    cout << "Total Amount you deposite :: " << balance << endl;
};

void Bank ::displayAccount()
{
    cout << "Account Holder name : \t" << name << endl;
    cout << "Account Holder address : \t" << add << endl;
    cout << "Account Type : \t" << type << endl;
    cout << "Account Balance : \t" << balance << endl;
};

void Bank ::withdrawMoney()
{
    float a;
    cout << "Enter how mush you withdraw:: ";
    cin >> a;

    if (a > balance)
    {
        cout << "Withdraw amount can not be greater than balance amount" << endl;
    }
    else
    {
        balance -= a;
        cout << "Total balance:: " << balance << endl;
    }
};

int main()
{
    int menu, x;
    Bank bank;
    do
    {
        cout << "1) Open Account \n";
        cout << "2) Deposite Money \n";
        cout << "3) Withdraw Money \n";
        cout << "4) Display Account \n";
        cout << "5) Exit \n";
        cout << "Select the option from above \n";
        cin >> menu;
        switch (menu)
        {
        case 1:
            cout << "1) Open Account \n";
            bank.openAccount();
            break;
        case 2:
            cout << "2) Deposite Money \n";
            bank.depositeMoney();
            break;
        case 3:
            cout << "3) Withdraw Money  \n";
            bank.withdrawMoney();
            break;
        case 4:
            cout << "4) Display Account \n";
            bank.displayAccount();
            break;
        case 5:
            if (menu == 5)
            {
                exit(1);
            }
            break;
        default:
            cout << "try Again\n";
            break;
        }
        cout << "\n Do you want to select next option then press :: Y \n";
        cout << "if you want to exit then press  :: N \n";
        x = getch();
        if (x == 'n' || x == 'N')
        {
            exit(0);
        }
    } while (x == 'y' || x == 'Y');
    getch();
    return 0;
}