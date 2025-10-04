#include <iostream>
#include <string>
using namespace std;

// Product class
class Computer {
private:
    string CPU;
    string RAM;
    string Storage;
    string GPU;

public:
    void setCPU(const string& cpu) { CPU = cpu; }
    void setRAM(const string& ram) { RAM = ram; }
    void setStorage(const string& storage) { Storage = storage; }
    void setGPU(const string& gpu) { GPU = gpu; }

    void showSpecs() const {
        cout << "Computer Specs:\n";
        cout << "CPU: " << CPU << "\n";
        cout << "RAM: " << RAM << "\n";
        cout << "Storage: " << Storage << "\n";
        cout << "GPU: " << GPU << "\n";
    }
};

// Abstract Builder
class ComputerBuilder {
public:
    virtual void buildCPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildStorage() = 0;
    virtual void buildGPU() = 0;
    virtual Computer* getComputer() = 0;
    virtual ~ComputerBuilder() {}
};

// Concrete Builder
class GamingComputerBuilder : public ComputerBuilder {
private:
    Computer* computer;

public:
    GamingComputerBuilder() { computer = new Computer(); }

    void buildCPU() override { computer->setCPU("Intel Core i9"); }
    void buildRAM() override { computer->setRAM("32GB DDR5"); }
    void buildStorage() override { computer->setStorage("1TB SSD"); }
    void buildGPU() override { computer->setGPU("NVIDIA RTX 4090"); }

    Computer* getComputer() override { return computer; }
};

// Director
class Director {
public:
    void construct(ComputerBuilder* builder) {
        builder->buildCPU();
        builder->buildRAM();
        builder->buildStorage();
        builder->buildGPU();
    }
};

// Client Code
int main() {
    Director director;
    GamingComputerBuilder gamingBuilder;

    director.construct(&gamingBuilder);
    Computer* gamingPC = gamingBuilder.getComputer();

    gamingPC->showSpecs();

    delete gamingPC; // Clean up
    return 0;
}