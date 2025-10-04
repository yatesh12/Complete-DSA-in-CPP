#include <iostream>
using namespace std;

// Prototype Interface
class clonable {
public:
    virtual clonable* clone() const = 0;
    virtual ~clonable() {}
};

// Concrete Prototype
class NPC : public clonable {
public:
    string name;
    int health;
    int power;

    NPC(string name, int health, int power)
        : name(name), health(health), power(power) {
        cout << "Creating NPC " << name << '\n';
    }

    // Copy Constructor
    NPC(const NPC& n)
        : name(n.name), health(n.health), power(n.power) {
        cout << "Cloning NPC " << name << '\n';
    }

    clonable* clone() const override {
        return new NPC(*this);
    }

    void print() const {
        cout << "NPC " << name << " | Health: " << health << " | Power: " << power << endl;
    }

    void setName(const string& newName){
        name = newName;
    }

    ~NPC() {
        cout << "Destroying NPC " << name << '\n';
    }
};

int main() {
    NPC* alien = new NPC("Alice", 50, 30);
    alien->print(); // Show original

    NPC* alienClone = dynamic_cast<NPC*>(alien->clone());
    alienClone->setName("Sam");
    alienClone->print(); // Modified clone

    delete alien;
    delete alienClone;

    return 0;
}