#include <iostream>
#include <string>
using namespace std;

class bankAccount {  // here we define the class and the methods
    private:
        string accountHolderName;
        int accountNumber;
        string accountType;
        double balance;
        double interestRate;
        static int numAccounts;

    public:
        bankAccount(string name, string type, double balance, double rate) {
            accountHolderName = name;
            accountType = type;
            this->balance = balance;
            interestRate = rate;
            accountNumber = ++numAccounts;
        }

        void deposit(double amount);
        void withdraw(double amount);
        double getInterest();
        void updateBalance();
        void print();
        int getAccountNumber();
        string getAccountHolderName();
        string getAccountType();
        double getBalance();
        double getInterestRate();
};
void bankAccount::print() {  // This is the output stack
    cout << "Account Holder Name: " << accountHolderName << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Type: " << accountType << endl;
    cout << "Balance: " << balance << endl;
    cout << "Interest Rate: " << interestRate << endl;
}

int bankAccount::numAccounts = 0;

int main() {
    const int MAX_ACCOUNTS = 10;
    bankAccount* accounts[MAX_ACCOUNTS];
    int numAccounts = 0;

    while (numAccounts < MAX_ACCOUNTS) { // lets get all the info from the user
        cout << "Enter account holder name: ";
        string name;
        getline(cin, name);

        cout << "Enter account type (Checking or Savings): ";
        string type;
        getline(cin, type);

        cout << "Enter initial balance: ";
        double balance;
        cin >> balance;

        cout << "Enter interest rate (as a decimal): ";
        double rate;
        cin >> rate;
        cin.ignore(); // it kept going crazy so I had to ignore the newline character

        cout << "***" << endl; // added a separator so it wasnt a jumble on the screen

        accounts[numAccounts] = new bankAccount(name, type, balance, rate);
        numAccounts++;

        if (numAccounts == MAX_ACCOUNTS) {
            cout << "The account system is full." << endl;
        }

    }

    cout << "***" << endl; // make it pretty

    for (int i = 0; i < numAccounts; i++) {
        accounts[i]->print();
        cout << "***" << endl; // little separation goes a long way
    }

    for (int i = 0; i < numAccounts; i++) {
        delete accounts[i];
    }

    return 0;
}
