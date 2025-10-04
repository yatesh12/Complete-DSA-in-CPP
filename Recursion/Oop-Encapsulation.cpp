#include <iostream>
using namespace std;

class BankAccount {
private:
    // Private data members (encapsulated)
    string accountHolder;
    double balance;

public:
    // Constructor
    BankAccount(string name, double initialBalance) {
        accountHolder = name;
        balance = initialBalance;
    }

    // Public method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Public method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        } else {
            cout << "Invalid or insufficient funds!" << endl;
        }
    }

    // Public method to check balance
    double getBalance() const {
        return balance;
    }

    // Public method to get account holder's name
    string getAccountHolder() const {
        return accountHolder;
    }
};

int main() {
    BankAccount myAccount("Rahul", 5000.0);

    myAccount.deposit(1500.0);
    myAccount.withdraw(2000.0);

    cout << "Account Holder: " << myAccount.getAccountHolder() << endl;
    cout << "Current Balance: " << myAccount.getBalance() << endl;

    return 0;
}