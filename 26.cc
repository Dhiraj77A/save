#include<iostream>
using namespace std;

class person {
private:
    char name[50];
    int age;

public:
    void getdata() {
        cout << "Enter the name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter the age: ";
        cin >> age;
    }

    void address() {
        cout << "Address of base obj: " << this << endl;
    }
};

class student : public person {
private:
    int roll;

public:
    void getdataS() {
        getdata();
        cout << "Enter roll no: ";
        cin.ignore();
        cin >> roll;
    }

    void address() {
        cout << "Address of student obj: " << this << endl;
    }
};

class employee : public person {
private:
    int empid;

public:
    void getdataE() {
        getdata();
        cout << "Enter emp id: ";
        cin.ignore();
        cin >> empid;
    }

    void address() {
        cout << "Address of employee obj: " << this << endl;
    }
};

int main() {
    person p1, p2;
    p1.getdata();
    p2.getdata();
    p1.address();
    p2.address();

    student s1, s2;
    s1.getdataS();
    s2.getdataS();
    s1.address();
    s2.address();

    employee e1, e2;
    e1.getdataE();
    e2.getdataE();
    e1.address();
    e2.address();

    return 0;
}
