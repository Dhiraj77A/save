#include<iostream>
using namespace std;

class  employee{
    private:
    int employeeId;
    int bonus;
    int overtime;

     

    public:
    void setpara(int id, int b, int ot){
        employeeId=id;
        bonus=b;
        overtime=ot;
    }
    void displayReport(){
        cout<<"An employee with emp id"<<employeeId<<" has received Rs."<<bonus<<" as bonus and had worked "<<overtime<<
        " hours as overtime in the year."<<endl;
    }
};

int main(){
    int id, bonus, ot;
    int n;
    employee emp[50];
    cout<<"Enter the number of employee: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Emp "<<i+1<<endl;
        cout<<"Enter the employee id: ";
        cin>>id;
        cout<<"Enter the total bonus: ";
        cin>>bonus;
        cout<<"Enter the total overtime: ";
        cin>>ot;
        emp[i].setpara(id,bonus,ot);
    }
    for(int i=0;i<n;i++){
        emp[i].displayReport();
    }
    return 0;
}