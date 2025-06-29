#include<iostream>
using namespace std;
class carpark{
    private:
    int carId;
    int chargeHour;
    float parkedTime;

    public:
    void getCarId(int id){
        carId=id;
    }
    void getChargeHour(int ch){
        chargeHour=ch;
    }
    void getParkedTime(float time){
        parkedTime=time;
    }

    int showCarId(){
        return carId;
    }

    float showCharge(){
        return parkedTime*chargeHour;
    }

    int showParkedHour(){
        return parkedTime;
    }
};

int main(){
    int id, ch;
    float time;
    cout<<"Enter the car id: ";
    cin>>id;
    cout<<"Enter the charge per hour: ";
    cin>>ch;
    cout<<"Enter the parked time: ";
    cin>>time;
    carpark car1;
    car1.getCarId(id);
    car1.getChargeHour(ch);
    car1.getParkedTime(time);

    cout<<" car id: "<<car1.showCarId()<<endl;
    cout<<" Charge: "<<car1.showCharge()<<endl;
    cout<<" Parked Hour: "<<car1.showParkedHour()<<endl;
    return 0;
}