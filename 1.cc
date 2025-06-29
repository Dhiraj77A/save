#include<iostream>
#include<iomanip>
using namespace std;
struct date{
    int month;
    int day;
    int year;
};
void printDate(date inputDate){
    cout<<setfill('0')<<setw(2)<<inputDate.month<<"/"<<setfill('0')<<setw(2)<<inputDate.day<<"/"<<setw(4)<<inputDate.year<<endl;
}
int main(){
    date d1;
    cout<<"Enter the month, day and year: ";
    cin>>d1.month>>d1.day>>d1.year;
    printDate(d1);
    return 0;
}