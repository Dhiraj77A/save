#include<iostream>
#include<iomanip>
using namespace std;
class Celsius{
    private:
    float celTemp;

    public:
    void setData(float cel){
        celTemp=cel;
    }

    float toFahrenheit(){
        return ((9*celTemp)/5)+32.0;
    }
};
class Fahrenheit{
    private:
    float fahTemp;

    public:
    void setData(float fah){
        fahTemp=fah;
    }

    float toCelsius(){
        return (fahTemp-32)*(5.0/9.0);
    }

};
int main(){
    float cel, fah;
    Celsius t1;
    Fahrenheit t2;
    cout<<"Enter the Celsius Temperature: ";
    cin>>cel;
    t1.setData(cel);
    cout<<"Temperature in Fahrenheit: "<<fixed<<setprecision(2)<<t1.toFahrenheit()<<endl;

    cout<<"Enter the Fahrenheit Temperature: ";
    cin>>fah;
    t2.setData(fah);
    cout<<"Temperature in Celsius: "<<fixed<<setprecision(2)<<t2.toCelsius()<<endl;
    return 0;
}