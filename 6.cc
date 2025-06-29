#include<iostream>
using namespace std;
int newSalary(int salary, int increment=9){
    return salary+salary*(increment/100.0);
}
int main(){
    cout<<"Chief Executive Officer: "<<newSalary(35000)<<endl;
    cout<<"Information Officer: "<<newSalary(25000,10)<<endl;
    cout<<"System Analyst: "<<newSalary(24000,12)<<endl;
    cout<<"Programmer: "<<newSalary(18000,12)<<endl;
    return 0;
}