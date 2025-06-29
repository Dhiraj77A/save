#include<iostream>
#include<iomanip>
using namespace std;
void convertFtToIn(){
    float ft;
    cout<<"Enter the feet1: ";
    cin>>ft;
    cout<<"inches: "<<fixed<<setprecision(2)<<ft*12<<endl;
}
void convertFtToIn(float ft){
    cout<<"inches: "<<fixed<<setprecision(2)<<ft*12<<endl;
}
void convertFtToIn(float ft, float &in){
    in=ft*12;
}
int main(){
    float ft2,in=0,ft3;
    convertFtToIn();
    cout<<"Enter the feet2: ";
    cin>>ft2;
    convertFtToIn(ft2);
    cout<<"Enter the feet3: ";
    cin>>ft3;
    convertFtToIn(ft3,in);
    cout<<"inches: "<<fixed<<setprecision(2)<<in<<endl;
    return 0;
}