#include <iostream>
#include <memory>

// Strategy Interface
class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() {}
};

// Concrete Strategy 1
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paid ₹" << amount << " using Credit Card.\n";
    }
};

// Concrete Strategy 2
class PayPalPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paid ₹" << amount << " using PayPal.\n";
    }
};

// Context (Client)
class PaymentProcessor {
private:
    std::unique_ptr<PaymentStrategy> strategy;
public:
    void setStrategy(std::unique_ptr<PaymentStrategy> s) {
        strategy = std::move(s);
    }

    void processPayment(int amount) {
        if (strategy)
            strategy->pay(amount);
        else
            std::cout << "No payment strategy set.\n";
    }
};

int main() {
    PaymentProcessor processor;

    // Use Credit Card
    processor.setStrategy(std::make_unique<CreditCardPayment>());
    processor.processPayment(500);

    // Use PayPal
    processor.setStrategy(std::make_unique<PayPalPayment>());
    processor.processPayment(800);

    return 0;
}
