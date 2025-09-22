#include <iostream>
using namespace std;

// Base class
class Person {
public:
    string name;
    int age;

    // Constructor
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    // Destructor
    ~Person() {
        cout << "Person destructor called\n";
    }
};

// Derived class
class Student : public Person {
public:
    int rollno;

    // Constructor using initializer list and base class constructor
    Student(string name, int age, int rollno) : Person(name, age) {
        this->rollno = rollno;
    }

    // Method to display student info
    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << rollno << endl;
    }

    // Destructor
    ~Student() {
        cout << "Student destructor called\n";
    }
};

// Main function
int main() {
    // Creating a Student object
    Student s1("Aman", 19, 21);

    // Displaying student info
    s1.getInfo();

    return 0;
}