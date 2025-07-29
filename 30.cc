#include<iostream>
using namespace std;

class student{
    protected:
    char name[50];
    int age;

    public:

    virtual void getdata()=0;
    virtual void showdata()=0;

};
class engineering: public student{
    protected:
    char branch[50];

    public:

    void getdata(){
        cout<<"Engineering"<<endl;
        cout<<"Enter your name: ";
        cin.ignore();
        cin.getline(name,50);
        cout<<"Enter your age: ";
        cin>>age;
        cout<<"Enter your branch: ";
        cin.ignore();
        cin.getline(branch,50);
    }

    void showdata(){
        cout<<"Engineering"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Branch: "<<branch<<endl;
    }

};
class medicine: public student{
    protected:
    char hospital[50];

    public:

    void getdata(){
        cout<<"Medicine"<<endl;
        cout<<"Enter you name: ";
        cin.ignore();
        cin.getline(name,50);
        cout<<"Enter you age: ";
        cin>>age;
        cout<<"Enter hospital: ";
        cin.ignore();
        cin.getline(hospital,50);
    }

    void showdata(){
        cout<<"Medicine"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Hospital: "<<hospital<<endl;
    }

};
class science: public student{
    protected:
    char department[50];

    public:

    void getdata(){
        cout<<"Science"<<endl;
        cout<<"Enter you name: ";
        cin.ignore();
        cin.getline(name,50);
        cout<<"Enter you age: ";
        cin>>age;
        cout<<"Enter department: ";
        cin.ignore();
        cin.getline(department,50);
    }

    void showdata(){
        cout<<"Science"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Department: "<<department<<endl;
    }

};

int main(){
    engineering eng;
    medicine med;
    science sci;

    student *stud[3]={&eng,&med, &sci};

    for(int i=0;i<3;i++){
        stud[i]->getdata();
        cout<<endl;
    }
    for(int i=0;i<3;i++){
        stud[i]->showdata();
        cout<<endl;
    }

    return 0;
}