#include<iostream>
#include<iomanip>
using namespace std;
class date{
    private:
    int year;
    int month;
    int day;

    int findDay(int m, int y){
        switch (m)
        {
            case 2: return (y%100!=0&&y%4==0||y%400==0)? 29 : 28;
            case 1: case 3: case 5: case 7: case 9: case 11: return 31;
        default: return 30;
        }
    }

    void increaseDate(){
        day++;
        if(day>findDay(month,year)){
            day=1;
            month++;
            if(month>12){
                year++;
                month=1;
            }
        }
    }

    public:
    date(int y=2025,int m=1,int d=1){
        year=y;
        month=m;
        day=d;
    }

    date& operator ++(){
        increaseDate();
        return *this;
    }

    date operator ++(int){
        date cpy=*this;
        ++(*this);
        return cpy;
    }

    void display(){
    cout << year << "/"
         << setw(2) << setfill('0') << month << "/"
         << setw(2) << setfill('0') << day << endl;
}


};
int main(){

    int y, m, d;
    cout<<"Enter the date(y/m/d): ";
    cin>>y>>m>>d;
    date date1(y,m,d);
    ++date1;
    cout<<"after prefix increment: ";
    date1.display();
    date date2=date1++;
    cout<<"before postfix increment: ";
    date2.display();
    cout<<"after postfix increment: ";
    date1.display();
    return 0;
}