#include<iostream>
#include<cmath>
using namespace std;

class circle{
    private:
    int rad;

    public:
    void setRad(int r){
        rad=r;
    }

    float perimeter(){
        return 2*3.14*rad;
    }

    float area(){
        return 3.14*rad*rad;
    }
};
class rectangle{
    private:
    int len;
    int bre;

    public:
    void setLB(int l, int b){
        len=l;
        bre=b;
    }

    float perimeter(){
        return 2*(len+bre);
    }
    float area(){
        return len*bre;
    }

};
class triangle{
    private: 
    int s1,s2;
    int s3;

    public:
    void setSide(int a, int b , int c){
        s1=a;
        s2=b;
        s3=c;
    }
    float perimeter(){
        return s1+s2+s3;
    }
    float area(){
        float semi=(s1+s2+s3)/2;
        float in=semi*(semi-s1)*(semi-s2)*(semi-s3);
        return sqrt(in);
    }
};

int main(){
    int rad, len , bre, s1,s2,s3;
    cout<<"Enter the radius of circle: ";
    cin>>rad;
    cout<<"Enter the length and breath of rectangle: ";
    cin>>len>>bre;
    cout<<"Enter 3 sides of triangle: ";
    cin>>s1>>s2>>s3;
    circle c1;
    rectangle r1;
    triangle t1;
    c1.setRad(rad);
    r1.setLB(len,bre);
    t1.setSide(s1,s2,s3);
    cout<<"Perimeter of Circle: "<<c1.perimeter()<<"\n"<<"Area of Circle: "<<c1.area()<<endl;
    cout<<"Perimeter of Rectangle: "<<r1.perimeter()<<"\n"<<"Area of Rectangle: "<<r1.area()<<endl;
    cout<<"Perimeter of Triangle: "<<t1.perimeter()<<"\n"<<"Area of Triangle: "<<t1.area()<<endl;
    return  0;
}