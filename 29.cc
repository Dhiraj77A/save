#include<iostream>
#include<string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person() : name(""), age(0) {
        cout << "Person constructor" << endl;
    }

    void showInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    virtual void input() = 0;
    virtual ~Person() {
        cout << "Person destructor" << endl;
    }
};

class Employee : virtual public Person {
protected:
    int empId;
    double salary;

public:
    Employee() : empId(0), salary(0.0) {
        cout << "Employee constructor" << endl;
    }

    void showEmpInfo() const {
        cout << "Emp Id: " << empId << ", Salary: $" << salary << endl;
    }

    void input() override {
        cout << "Enter emo id: ";
        cin >> empId;
        cout << "Enter salary: ";
        cin >> salary;
    }

    virtual ~Employee() {
        cout << "Employee destructor" << endl;
    }
};

class Student : virtual public Person {
protected:
    int studId;
    string major;

public:
    Student() : studId(0), major("") {
        cout << "Student constructor" << endl;
    }

    virtual ~Student() {
        cout << "Student destructor" << endl;
    }

    void showStudInfo() const {
        cout << " Student Id: " << studId << ", Major: " << major << endl;
    }

    void input() override {
        cout << "Enter student Id: ";
        cin >> studId;
        cout << "Enter major: ";
        cin.ignore();
        getline(cin, major);
    }
};

class Manager : public Employee, public Student {
private:
    string dept;

public:
    Manager() : dept("Unknown") {
        cout << "Manager constructor" << endl;
    }

    virtual ~Manager() {
        cout << "Manager destructor" << endl;
    }

    void showInfo() const {
        Person::showInfo();    // Corrected function to show the person info
        showEmpInfo();
        showStudInfo();
        cout << "Department: " << dept << endl;
    }

    void input() override {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        Employee::input();
        Student::input();
        cout << "Enter department: ";
        cin.ignore();
        getline(cin, dept);
    }
};

int main() {
    Manager m;
    m.input();
    m.showInfo();
    return 0;
}
