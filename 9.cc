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

    float showCharge(){
        return parkedTime*chargeHour;
    }

    void showData(){
    cout<<" car id: "<<carId<<endl;
    cout<<" Charge: "<<showCharge()<<endl;
    cout<<" Parked Hour: "<<parkedTime<<endl;
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

    car1.showData();
    
    return 0;
}