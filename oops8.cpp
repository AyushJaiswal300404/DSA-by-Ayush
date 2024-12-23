#include <iostream>
#include <string>
using namespace std;
//Abstraction

// Abstract class
class Payment {
protected:
    double amount;
public:
    Payment(double amt) : amount(amt) {}
    virtual void processPayment() = 0;    // Pure virtual function
};

// Concrete class - Credit Card
class CreditCard : public Payment {
public:
    CreditCard(double amt) : Payment(amt) {}
    
    void processPayment() override {
        cout << "Processing $" << amount << " via Credit Card" << endl;
        // Hidden implementation details
    }
};

// Concrete class - PayPal
class PayPal : public Payment {
public:
    PayPal(double amt) : Payment(amt) {}
    
    void processPayment() override {
        cout << "Processing $" << amount << " via PayPal" << endl;
        // Hidden implementation details
    }
};

int main() {
    Payment* payment1 = new CreditCard(100.50);
    Payment* payment2 = new PayPal(75.25);

    payment1->processPayment();
    payment2->processPayment();

    delete payment1;
    delete payment2;
    return 0;
}