#include <iostream>
using namespace std;

class Hero {
public:
    char level = 'A';

    int getHealth() const {
        return health;
    }

    void setHealth(int h) {
        health = h;
    }

private:
    int health = 20;
};

int main() {
    Hero sam;                 // Stack allocation
    Hero* b = new Hero();     // Heap allocation (corrected the pointer usage)

    // Accessing and modifying health for sam
    cout << "sam's health: " << sam.getHealth() << endl;
    sam.setHealth(70);
    cout << "sam's health after update: " << sam.getHealth() << endl;

    // Accessing and modifying health for b
    cout << "b's health: " << b->getHealth() << endl;
    b->setHealth(90);
    cout << "b's health after update: " << b->getHealth() << endl;

    delete b;  // Free the memory allocated on the heap

    return 0;
}