#include <iostream>
using namespace std;

class Teacher{
    private:
    double salary;
    public:
    // Properties / attributes
    string name;
    string dept;
    string subject;

    // methods / member functions
    void changeDept(string newDept){
        dept = newDept;
    }

    void setSalary(double s){
        salary = s;
    }

    double getSalary(){
        return salary;
    }
};

int main() {
    Teacher t1;

    t1.name = "Sam";
    t1.dept = "AI&DS";
    t1.subject = "DBMS";

    cout << t1.name << endl;
    t1.setSalary(33000);
    cout << t1.getSalary() << endl;

    return 0;
}