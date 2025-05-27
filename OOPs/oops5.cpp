#include <iostream>
#include <string>
using namespace std;
//Encapsulation
class BankAccount {
private:
    // Private data members for data hiding
    string accountHolder;
    double balance;
    string accountNumber;
    int pin;

public:
    // Constructor
    BankAccount(string name, string accNum, int securityPin) {
        accountHolder = name;
        accountNumber = accNum;
        balance = 0.0;
        pin = securityPin;
    }

    // Getter methods for controlled access
    string getAccountHolder() {
        return accountHolder;
    }

    string getAccountNumber() {
        // Show only last 4 digits for security
        string masked = "XXXX-XXXX-" + accountNumber.substr(accountNumber.length()-4);
        return masked;
    }

    double getBalance(int inputPin) {
        // Validate PIN before showing balance
        if (inputPin == pin) {
            return balance;
        }
        cout << "Invalid PIN!" << endl;
        return -1;
    }

    // Setter methods with validation
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited $" << amount << endl;
        } else {
            cout << "Invalid deposit amount" << endl;
        }
    }

    bool withdraw(double amount, int inputPin) {
        // Validate PIN and amount before withdrawal
        if (inputPin != pin) {
            cout << "Invalid PIN!" << endl;
            return false;
        }
        
        if (amount <= 0) {
            cout << "Invalid withdrawal amount" << endl;
            return false;
        }

        if (amount > balance) {
            cout << "Insufficient funds" << endl;
            return false;
        }

        balance -= amount;
        cout << "Successfully withdrawn $" << amount << endl;
        return true;
    }
};

int main() {
    // Creating a bank account
    BankAccount account("John Doe", "1234567890", 1234);

    // Testing encapsulation
    cout << "Account Holder: " << account.getAccountHolder() << endl;
    cout << "Account Number: " << account.getAccountNumber() << endl;

    // Deposit money
    account.deposit(1000);
    
    // Check balance with correct PIN
    cout << "Balance: $" << account.getBalance(1234) << endl;

    // Attempt withdrawal with wrong PIN
    account.withdraw(500, 5678);

    // Withdraw with correct PIN
    account.withdraw(500, 1234);

    // Check final balance
    cout << "Final Balance: $" << account.getBalance(1234) << endl;

    return 0;
}