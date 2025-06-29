#include<iostream>
using namespace std;
int &largerTemp(int &t1, int &t2){
    return t1>t2? t1:t2;
}
int main(){
    int t1, t2;
    cout<<"Enter the two temperature: ";
    cin>>t1>>t2;
    int n;
     int &res=largerTemp(t1,t2);
    cout<<"largest: "<<res<<endl;
    cout<<"Enter the num: ";
    cin>>n;
    res=n;
    cout<<"After change largest: "<<res<<endl;
    return 0;
}