#include <iostream>
#include <string>

class BankAccount {
private:
    // 1. Attributes (Properties)
    std::string accountHolder;
    std::string accountNumber;
    double balance;

public:
    // 2. Parameterized Constructor (using initialization list)
    BankAccount(std::string holderName, std::string number) 
        : accountHolder(holderName), accountNumber(number), balance(0.0) {}

    // 3. Methods (Behaviors)
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrew: $" << amount << std::endl;
        } else {
            std::cout << "Error: Insufficient funds or invalid amount." << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    // Real-World Object Creation
    BankAccount alexAccount("Alex Smith", "ACC12345");

    // Using the object's methods
    alexAccount.deposit(500.00);   // Balance is now $500.00
    alexAccount.withdraw(150.00);  // Balance is now $350.00
    
    std::cout << "Final Balance: $" << alexAccount.getBalance() << std::endl;

    return 0;
}