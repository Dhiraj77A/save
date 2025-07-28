#include<iostream>
#include<cstring>
using namespace std;

class student{
    protected:
    char name[50];
    int age;

    public:
    student(const char* n="stud", int a=0){
        strcpy(name,n);
        age=a;
    }

    virtual void getdata()=0;
    virtual void showdata()=0;
    
};
class engineering: public student{

};
class medicine: public student{

};
class science: public student{

};