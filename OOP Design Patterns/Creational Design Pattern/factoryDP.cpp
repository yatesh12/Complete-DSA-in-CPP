#include <iostream>
#include <string>
using namespace std;

// Abstract Product
class burger {
public:
    virtual void prepare() = 0;
    virtual ~burger() {}
};

// Concrete Products
class basicBurger : public burger {
public:
    void prepare() override {
        cout << "Preparing basic Burger" << endl;
    }
};

class standardBurger : public burger {
public:
    void prepare() override {
        cout << "Preparing standard Burger" << endl;
    }
};

class premiumBurger : public burger {
public:
    void prepare() override {
        cout << "Preparing premium Burger" << endl;
    }
};

// Factory Class
class burgerFactory {
public:
    burger* createBurger(const string& type) {
        if (type == "basic") {
            return new basicBurger();
        } else if (type == "standard") {
            return new standardBurger();
        } else if (type == "premium") {
            return new premiumBurger();
        } else {
            cout << "Invalid burger type!" << endl;
            return nullptr;
        }
    }
};

// Client Code
int main() {
    string type = "standard";

    burgerFactory* myBurgerFactory = new burgerFactory();
    burger* myBurger = myBurgerFactory->createBurger(type);

    if (myBurger)
        myBurger->prepare();

    delete myBurger;
    delete myBurgerFactory;

    return 0;
}