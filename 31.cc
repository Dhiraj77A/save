#include<iostream>
using namespace std;

class Vehicle{
    public:
    virtual void showsize(){
        cout<<"vehicle have different size"<<endl;
    }
};
 class bus: public Vehicle{
    public:
    void showsize(){
        cout<<"Bus is large size vehicle"<<endl;
    }
};
 class car: public Vehicle{
    public:
    void showsize(){
        cout<<"Car is medium size vehicle"<<endl;
    }
};
 class bike: public Vehicle{
    public:
    void showsize(){
        cout<<"Bike is small size vehicle"<<endl;
    }
};

int main(){
    Vehicle *v1=new bus();
    Vehicle *v2=new car();
    Vehicle *v3=new bike();

    bus *b1=dynamic_cast<bus*>(v1);
    car *c1=dynamic_cast<car*>(v2);
    bike *bi1=dynamic_cast<bike*>(v3);

    if(b1){
        cout<<"Bus Pointer: "<<endl;
        b1->showsize();
    }
    if(c1){
        cout<<"Car Pointer: "<<endl;
        c1->showsize();
    }
    if(bi1){
        cout<<"Bike Pointer: "<<endl;
        bi1->showsize();
    }

    cout<<"type of v1 is  "<<typeid(*v1).name()<<endl;
    cout<<"type of v2 is  "<<typeid(*v2).name()<<endl;
    cout<<"type of v3 is  "<<typeid(*v3).name()<<endl;
    return 0;
}