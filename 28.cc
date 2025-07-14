#include<iostream>
using namespace std;

class shape{
    public: 
    virtual void getdata()=0;
    virtual void area()=0;

    virtual ~shape(){
        cout<<"shape class(base class) destructor called"<<endl;
    }

};
class circle: public shape{
    private:
    int rad;

    public:
    void getdata(){
        cout<<"Enter the radius: ";
        cin>>rad;
    }

    void area(){
        cout<<"The area of the circle: "<<3.14*rad*rad<<endl;
    }

    ~circle(){
        cout<<"circle class destructor called"<<endl;
    }


};
class rectangle: public shape{
    private:
    int len;
    int bre;

    public:

    void getdata(){
        cout<<"Enter the length and breadth: ";
        cin>>len>>bre;
    }

    void area(){
        cout<<"The area of the rectangle: "<<len * bre<<endl;
    }

    ~rectangle(){
        cout<<"rectangle class destructor called"<<endl;
    }

};
class trapezium: public shape{
    private:
    int a;
    int b;
    int h;

    public:

    void getdata(){
        cout<<"Enter a, b and height: ";
        cin>>a>>b>>h;
    }

    void area(){
        cout<<"The area of the trapezium: "<<0.50*h*(a+b)<<endl;
    }

    ~trapezium(){
        cout<<"trapezium class destructor called"<<endl;
    }

};

int main(){

    shape *s;
    circle c1;
    rectangle r1;
    trapezium t1;

    s=&c1;
    s->getdata();
    s->area();
    delete s;

    s=&r1;
    s->getdata();
    s->area();
    delete s;


    s=&t1;
    s->getdata();
    s->area();
    delete s;

    return 0;
}