#include<iostream>
#include<iomanip>
using namespace std;
inline void salary(int pay){
    cout<<"Net Salary: "<<fixed<<setprecision(2)<<pay-pay*0.1;
}
int main(){
    int sal;
    cout<<"Enter the salary: ";
    cin>>sal;
    salary(sal);
    return 0;
}