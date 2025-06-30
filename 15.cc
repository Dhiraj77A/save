#include<iostream>
using namespace std;

class vehicle {
private:
    int num_vehicle, hour, rate;

public:
    vehicle(int n=0, int h=0 ,int r=0){
        num_vehicle = n;
        hour = h;
        rate = r;
    }

    vehicle(const vehicle& copyobj){
        num_vehicle = copyobj.num_vehicle;
        hour = copyobj.hour;
        rate = copyobj.rate;
        cout<<"copy constructor called"<<endl;
    }

    void display(){
        float total = num_vehicle * hour * rate;
        if (num_vehicle > 10)
            total *= 0.9;  // 10% discount
        cout << "total charge: " << total << endl;
    }
};

int main(){
    int v, h, r;
    cout << "Enter the vehicle number, hour and rate: ";
    cin >> v >> h >> r;

    vehicle v1(v, h, r);
    vehicle v2(v1);  // copy constructor

    cout << "Charges for first vehicle object: ";
    v1.display();

    cout << "Charges for second vehicle object (copied): ";
    v2.display();

    return 0;
}
