#include <iostream>
using namespace std;

class BankAccount
{
    char name[20];
    int account_number;
    float balance;

public:
    void get(int index);
    void deposit();
    void withdraw();
    void display();
    void check_balance();
};

void BankAccount::get(int index)
{
    account_number = index;
    cout << "Account number assinged is:" << account_number << endl;
    cout << "Enter the name of the account holder: ";
    cin >> name;
    cout << "Enter the balance: ";
    cin >> balance;
}

void BankAccount::deposit()
{
    float amount;
    cout << "Enter the amount to be deposited: ";
    cin >> amount;
    balance += amount;
}

void BankAccount::withdraw()
{
    float amount;
    cout << "Enter the amount to be withdrawn: ";
    cin >> amount;
    if (amount > balance)
    {
        cout << "Insufficient balance" << endl;
    }
    else
    {
        balance -= amount;
    }
}

void BankAccount::display()
{
    cout << "Name: " << name << endl;
    cout << "Account number: " << account_number << endl;
    cout << "Balance: " << balance << endl;
}

void BankAccount::check_balance()
{
    cout << "Balance: " << balance << endl;
}

int main()
{
    int size = 1;
    BankAccount *accounts = new BankAccount[size];

    int count = 0;

    while (1)
    {
        cout << "1. Enter the details of the account holder" << endl;
        cout << "2. Deposit money" << endl;
        cout << "3. Withdraw money" << endl;
        cout << "4. Display details" << endl;
        cout << "5. Display balance" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (count < size)
            {
                accounts[count].get(count);
                count++;
            }
            else
            {
                cout << "User note found creating new account" << endl;
                size *= 2;
                BankAccount *temp = new BankAccount[size];
                for (int i = 0; i < count; ++i)
                {
                    temp[i] = accounts[i];
                }
                delete[] accounts;
                accounts = temp;

                accounts[count].get(count);
                count++;
            }
            break;
        case 2:

            if (count > 0)
            {
                int accountIndex;
                cout << "Enter the account number: ";
                cin >> accountIndex;
                if (accountIndex >= 0 && accountIndex < count)
                {
                    accounts[accountIndex].deposit();
                }
                else
                {
                    cout << "Invalid account index" << endl;
                }
            }
            else
            {
                cout << "No accounts exist. Please create an account first." << endl;
            }
            break;
        case 3:
            if (count > 0)
            {
                int accountIndex;
                cout << "Enter the account number: ";
                cin >> accountIndex;
                if (accountIndex >= 0 && accountIndex < count)
                {
                    accounts[accountIndex].withdraw();
                }
                else
                {
                    cout << "Invalid account index" << endl;
                }
            }
            else
            {
                cout << "No accounts exist. Please create an account first." << endl;
            }
            break;
        case 4:
            if (count > 0)
            {
                int accountIndex;
                cout << "Enter the account number: ";
                cin >> accountIndex;
                if (accountIndex >= 0 && accountIndex < count)
                {
                    accounts[accountIndex].display();
                }
                else
                {
                    cout << "Invalid account index" << endl;
                }
            }
            else
            {
                cout << "No accounts exist. Please create an account first." << endl;
            }
            break;
        case 5:
            if (count > 0)
            {
                int accountIndex;
                cout << "Enter the account number: ";
                cin >> accountIndex;
                if (accountIndex >= 0 && accountIndex < count)
                {
                    accounts[accountIndex].check_balance();
                }
                else
                {
                    cout << "Invalid account index" << endl;
                }
            }
            else
            {
                cout << "No accounts exist. Please create an account first." << endl;
            }
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }
}
