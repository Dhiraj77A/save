#include<iostream>
using  namespace std;
class time{
    private:
    int hours;
    int minute;
    int seconds;

    public:
    time(int h=0, int m=0, int s=0){
        hours=h;
        minute=m;
        seconds=s;
    }

    time addTime(time time2){
        time result;
        result.hours=time2.hours+hours;
        result.minute=time2.minute+minute;
        result.seconds=time2.seconds+seconds;
        if(result.seconds>=60){
            result.seconds-=60;
            result.minute+=1;
        }
        if(result.minute>=60){
            result.minute-=60;
            result.hours+=1;
        }
        if(result.hours>=24){
            result.hours-=24;
        }
        return result;
    }

    void format12(){
        if(hours<=12){
            cout<<"12 hour format: "<<hours<<":"<<minute<<":"<<seconds<<" am"<<endl;
        }else{
            cout<<"12 hour format: "<<hours-12<<":"<<minute<<":"<<seconds<<" pm"<<endl;
        }
    }

    void format24(){
cout << "24 hour format: " << hours << ":" << minute << ":" << seconds
     << ((hours >= 12) ? " pm" : " am") << endl;
    }
};

int main(){
    int h, m, s;
    cout<<"Enter the time(t1)(h/m/s)(24hr): ";
    cin>>h>>m>>s;
    time t1(h, m, s);
    cout<<"Enter the time(t2)(h/m/s)(24hr): ";
    cin>>h>>m>>s;
    time t2(h, m, s);

    time t3=t2.addTime(t1);
    t3.format12();
    t3.format24();
    return 0;
}